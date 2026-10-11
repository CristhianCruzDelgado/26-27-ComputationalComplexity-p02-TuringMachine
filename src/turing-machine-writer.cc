/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#include "turing-machine-writer.h"

constexpr std::string_view kHorizontalLine = "------------------"
  "--------------------------------------------------------------\n";

void TuringMachineWriter::writeTuringMachine( 
    const TuringMachine& turing_machine) const {
  std::cout << "Turing Machine (TM)\n" 
            << kHorizontalLine
            << "Q:  ";
  writeStates(turing_machine.getStates());
  std::cout << "\nΣ:  " << turing_machine.getInputAlphabet()
            << "\nΓ:  " << turing_machine.getTapeAlphabet()
            << "\nq0: " << turing_machine.getInitialState()
            << "\nb:  " << turing_machine.getBlankSymbol()
            << "\nF:  "; 
  writeStates(turing_machine.getFinalStates());
  std::cout << "\nδ:\n";
  writeTransitions(turing_machine.getTransitions());
  std::cout << kHorizontalLine;
}

void TuringMachineWriter::writeStates(
    const std::vector<std::string>& states) const {
  bool is_first = true;
  for (const std::string& state : states) {
    if (!is_first) {
      std::cout << ' ';
    }
    std::cout << state;
    is_first = false;
  }
}

void TuringMachineWriter::writeTransitions(
    const Transitions& transition_function) const {
  for (const auto& [key, value] : transition_function) {
    std::cout << "(" << key.state_ << ", ";
    writeSymbols(key.tapes_symbol_);
    std::cout <<") --> (" << value.next_state_ << ", ";
    writeSymbols(value.tapes_symbol_);
    std::cout << ", ";
    writeMovements(value.movements_);
    std::cout << ")\n";
  }
}

void TuringMachineWriter::writeSymbols(
    const std::vector<Symbol>& symbols) const {
  std::cout << '|';
  for (const Symbol& symbol : symbols) {
    std::cout << symbol << '|';
  }
}

void TuringMachineWriter::writeMovements(
    const std::vector<Movement>& movements) const {
  std::cout << '|';
  for (const Movement& move : movements) {
    std::cout << MovementParser::MovementToChar(move) << '|';
  }
}
