/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#ifndef TRANSITION_VALUE_H_
#define TRANSITION_VALUE_H_

#include "movement.h"
#include "symbol.h"

#include <string>
#include <vector>

struct TransitionValue {
  std::string next_state_;
  std::vector<Symbol> tapes_symbol_;
  std::vector<Movement> movements_;
};

#endif
