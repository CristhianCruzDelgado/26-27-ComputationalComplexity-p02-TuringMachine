/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#ifndef TRANSITION_KEY_H_
#define TRANSITION_KEY_H_

#include "symbol.h"

#include <string>
#include <tuple>
#include <vector>

struct TransitionKey {
  std::string state_;
  std::vector<Symbol> tapes_symbol_;  
  friend bool operator==(const TransitionKey& lhs, const TransitionKey& rhs) {
    return lhs.state_ == rhs.state_ && lhs.tapes_symbol_ == rhs.tapes_symbol_;
  }
  friend bool operator<(const TransitionKey& lhs, const TransitionKey& rhs) {
    return std::tie(lhs.state_, lhs.tapes_symbol_) < 
      std::tie(rhs.state_, rhs.tapes_symbol_);
  }
};

#endif
