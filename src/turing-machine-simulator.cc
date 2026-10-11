/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#include "turing-machine-simulator.h"

const int kMaxIterations = 10000;
constexpr std::string_view kHorizontalLine = "------------------"
  "--------------------------------------------------------------\n";

void TuringMachineSimulator::test(
    const TuringMachine& turing_machine,
    const std::string& input_string) const {
  std::vector<Tape> tapes;
  size_t number_of_tapes = turing_machine.getNumberOfTapes();
  Symbol blank_symbol = turing_machine.getBlankSymbol();
  for (size_t i = 0; i < number_of_tapes; ++i) {
    tapes.push_back(Tape(blank_symbol));
  }

  Alphabet input_alphabet = turing_machine.getInputAlphabet();
  for (char character : input_string) {
    Symbol symbol = Symbol(character);
    if (!input_alphabet.includes(symbol)) {
      throw std::runtime_error(std::string(1, symbol.getSymbol()) + " ∉ Σ");
    }
    tapes[0].write(symbol);
    tapes[0].right();
  }
  size_t input_string_length = input_string.length();
  for (size_t i = 0; i < input_string_length; ++i) {
    tapes[0].left();
  }

  std::cout << "Tapes before ...\n";
  printTapes(tapes);

  bool is_accepted = false;
  int i = 0;
  std::string current_state = turing_machine.getInitialState();
  while (i < kMaxIterations) {
    std::vector<Symbol> tape_symbols;
    for (size_t j = 0; j < number_of_tapes; ++j) {
      tape_symbols.push_back(tapes[j].read());
    }

    TransitionKey transition_key = {current_state, tape_symbols};
    TransitionValue transition_value = 
      turing_machine.getTransitionValueOf(transition_key);
    
    if (transition_value == TransitionValue{}) {
      std::vector<std::string> final_states = turing_machine.getFinalStates();
      auto it = 
        std::find(final_states.begin(), final_states.end(), current_state);
      if (it != final_states.end()) {
        is_accepted = true;
      }
      break;
    }

    current_state = transition_value.next_state_;
    for (size_t j = 0; j < number_of_tapes; ++j) {
      tapes[j].write(transition_value.tapes_symbol_[j]);
      switch (transition_value.movements_[j]) {
        case Movement::LEFT:
          tapes[j].left();
          break;
        case Movement::RIGHT:
          tapes[j].right();
          break;
        default:
          break;
      }
    }

    // Trace ...
    // std::cout << i << ": ";
    // printTapes(tapes);
    ++i;
  }

  std::cout << "Tapes after ...\n";
  printTapes(tapes);

  if (is_accepted) {
    std::cout << String(input_string) << " ∈ L\n";
  } else {
    std::cout << String(input_string) << " ∉ L\n";
  }
  std::cout << kHorizontalLine;
}

void TuringMachineSimulator::printTapes(const std::vector<Tape>& tapes) const {
  for (const Tape& tape : tapes) {
    std::cout << tape;
  }
  std::cout << "\n";
}
