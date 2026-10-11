/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#include "turing-machine-reader.h"

TuringMachine TuringMachineReader::readTuringMachine(
    const char* config_path) const {
  std::ifstream file(config_path);
  if (!file.is_open()) {
    throw std::runtime_error("Cannot open configuration file");
  }
  readLineComments(file);
  std::vector<std::string> states;
  readStates(states, file);
  Alphabet input_alphabet;
  readInputAlphabet(input_alphabet, file);
  Alphabet tape_alphabet;
  readTapeAlphabet(tape_alphabet, file);
  std::string initial_state;
  readInitialState(states, initial_state, file);
  Symbol blank_symbol;
  readBlankSymbol(input_alphabet, tape_alphabet, blank_symbol, file);
  std::vector<std::string> final_states;
  readFinalStates(states, final_states, file);
  std::size_t number_of_tapes;
  readNumberOfTapes(number_of_tapes, file);
  Transitions transition_function;
  readTransitionFunction(
    states, tape_alphabet, number_of_tapes, transition_function, file);
  return TuringMachine(
    states, input_alphabet, tape_alphabet, initial_state, blank_symbol, 
    final_states, number_of_tapes, transition_function);
}

void TuringMachineReader::readLineComments(std::ifstream& is) const {
  while (is.peek() == '#' || is.peek() == '\n' || is.peek() == '\r') {
    std::string dummy;
    std::getline(is, dummy);
  }
}

void TuringMachineReader::readStates(
    std::vector<std::string>& states, 
    std::ifstream& file) const {
  std::string line;
  if (!std::getline(file, line)) {
    throw std::invalid_argument("Invalid input: stream read failure");
  }
  std::istringstream line_stream(line);
  std::string state;
  while (line_stream >> state) {
    states.push_back(state);
  }
  if (states.empty()) {
    throw std::runtime_error("Q = ∅");
  }
}

void TuringMachineReader::readInputAlphabet(
    Alphabet& input_alphabet,
    std::ifstream& file) const {
  file >> input_alphabet;
}

void TuringMachineReader::readTapeAlphabet(
    Alphabet& tape_alphabet,
    std::ifstream& file) const {
  file >> tape_alphabet;
}

void TuringMachineReader::readInitialState(
    const std::vector<std::string>& states, 
    std::string& initial_state, 
    std::ifstream& file) const {
  if (!std::getline(file, initial_state)) {
    throw std::invalid_argument("Invalid input: stream read failure");
  }
  if (std::find(states.begin(), states.end(), initial_state) == states.end()) {
    throw std::runtime_error("q0 ∉ Q");
  }
}

void TuringMachineReader::readBlankSymbol(
    const Alphabet& input_alphabet,
    const Alphabet& tape_alphabet, 
    Symbol& blank_symbol, 
    std::ifstream& file) const {
  std::string line;
  if (!std::getline(file, line)) {
    throw std::invalid_argument("Invalid input: stream read failure");
  }
  std::istringstream line_stream(line);
  if (!(line_stream >> blank_symbol)) {
    throw std::invalid_argument("Invalid input: stream read failure");
  }
  if (input_alphabet.includes(blank_symbol)) {
    throw std::runtime_error("□ ∈ Σ");
  }
  if (!tape_alphabet.includes(blank_symbol)) {
    throw std::runtime_error("□ ∉ Γ");
  }
}

void TuringMachineReader::readFinalStates(
    const std::vector<std::string>& states,
    std::vector<std::string>& final_states, 
    std::ifstream& file) const {
  std::string line;
  if (!std::getline(file, line)) {
    throw std::invalid_argument("Invalid input: stream read failure");
  }
  std::istringstream line_stream(line);
  std::string final_state;
  while (line_stream >> final_state) {
    if (std::find(states.begin(), states.end(), final_state) == states.end()) {
      throw std::runtime_error("F ⊈ Q");
    }
    final_states.push_back(final_state);
  }
}

void TuringMachineReader::readNumberOfTapes(
    std::size_t& number_of_tapes, 
    std::ifstream& file) const {
  std::string line;
  if (!std::getline(file, line)) {
    throw std::invalid_argument("Invalid input: stream read failure");
  }
  number_of_tapes = std::stoull(line);
}

void TuringMachineReader::readTransitionFunction(
    const std::vector<std::string>& states, 
    const Alphabet& tape_alphabet, 
    std::size_t number_of_tapes, 
    Transitions& transition_function, 
    std::ifstream& file) const {
  std::string line;
  while (std::getline(file, line)) {
    std::istringstream line_stream(line);
    std::string state;
    std::vector<Symbol> tapes_symbol;
    std::string next_state;
    std::vector<Symbol> next_tapes_symbol;
    std::vector<Movement> movements;

    if (!(line_stream >> state)) {
      throw std::invalid_argument("Invalid input: stream read failure");
    }
    if (std::find(states.begin(), states.end(), state) == states.end()) {
      throw std::runtime_error(state + " ∉ Q");
    }

    tapes_symbol.reserve(number_of_tapes);
    for (std::size_t i = 0; i < number_of_tapes; ++i) {
      Symbol tape_symbol;
      if (!(line_stream >> tape_symbol)) {
        throw std::invalid_argument("Invalid input: stream read failure");
      }
      if (!tape_alphabet.includes(tape_symbol)) {
        throw std::runtime_error(
          std::string(1, tape_symbol.getSymbol()) + " ∉ Γ");
      }
      tapes_symbol.push_back(tape_symbol);
    }

    if (!(line_stream >> next_state)) {
      throw std::invalid_argument("Invalid input: stream read failure");
    }
    if (std::find(states.begin(), states.end(), next_state) == states.end()) {
      throw std::runtime_error(next_state + " ∉ Q");
    }

    next_tapes_symbol.reserve(number_of_tapes);
    for (std::size_t i = 0; i < number_of_tapes; ++i) {
      Symbol next_tape_symbol;
      if (!(line_stream >> next_tape_symbol)) {
        throw std::invalid_argument("Invalid input: stream read failure");
      }
      if (!tape_alphabet.includes(next_tape_symbol)) {
        throw std::runtime_error(
          std::string(1, next_tape_symbol.getSymbol()) + " ∉ Γ");
      }
      next_tapes_symbol.push_back(next_tape_symbol);
    }

    movements.reserve(number_of_tapes);
    for (std::size_t i = 0; i < number_of_tapes; ++i) {
      char character;
      if (!(line_stream >> character)) {
        throw std::invalid_argument("Invalid input: stream read failure");
      }
      Movement move = MovementParser::MovementFromChar(character);
      movements.push_back(move);
    }

    transition_function.insert({
      {state, tapes_symbol}, 
      {next_state, next_tapes_symbol, movements}});
  }
}
