/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#ifndef TURING_MACHINE_H_
#define TURING_MACHINE_H_

#include "alphabet.h"
#include "movement.h"
#include "movement-parser.h"
#include "string.h"
#include "symbol.h"
#include "transition-key.h"
#include "transition-value.h"

#include <map>
#include <string>
#include <vector>

using Transitions = std::map<TransitionKey, TransitionValue>;

class TuringMachine {
 public:
  TuringMachine() = default;
  TuringMachine(const std::vector<std::string>& states, 
                const Alphabet& input_alphabet, 
                const Alphabet& tape_alphabet, 
                const std::string& initial_state, 
                const Symbol& blank_symbol,
                const std::vector<std::string>& final_states, 
                std::size_t number_of_tapes, 
                const Transitions& transition_function) 
      : states_(states), 
        input_alphabet_(input_alphabet), 
        tape_alphabet_(tape_alphabet), 
        initial_state_(initial_state), 
        blank_symbol_(blank_symbol), 
        final_states_(final_states),
        number_of_tapes_(number_of_tapes), 
        transition_function_(transition_function) {}
  const std::vector<std::string>& getStates() const;
  const Alphabet& getInputAlphabet() const;
  const Alphabet& getTapeAlphabet() const;
  const std::string& getInitialState() const;
  const Symbol& getBlankSymbol() const;
  const std::vector<std::string>& getFinalStates() const;
  std::size_t getNumberOfTapes() const;
  const Transitions& getTransitions() const;
  TransitionValue getTransitionValueOf(const TransitionKey&) const;
  
 private:
  std::vector<std::string> states_;
  Alphabet input_alphabet_; 
  Alphabet tape_alphabet_;
  std::string initial_state_;
  Symbol blank_symbol_;
  std::vector<std::string> final_states_;
  std::size_t number_of_tapes_;
  Transitions transition_function_;
};

#endif
