/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#include "turing-machine.h"

const std::vector<std::string>& TuringMachine::getStates() const { 
  return states_; 
}

const Alphabet& TuringMachine::getInputAlphabet() const { 
  return input_alphabet_; 
}

const Alphabet& TuringMachine::getTapeAlphabet() const { 
  return tape_alphabet_; 
}

const std::string& TuringMachine::getInitialState() const { 
  return initial_state_; 
}

const Symbol& TuringMachine::getBlankSymbol() const { 
  return blank_symbol_; 
}

const std::vector<std::string>& TuringMachine::getFinalStates() const {
  return final_states_;
}

std::size_t TuringMachine::getNumberOfTapes() const {
  return number_of_tapes_;
}

const Transitions& TuringMachine::getTransitions() const {
  return transition_function_;
}

TransitionValue TuringMachine::getTransitionValueOf(
    const TransitionKey& transition_key) const {
  auto it = transition_function_.find(transition_key);
  if (it == transition_function_.end()) {
    return {};
  }
  return it->second;
}
