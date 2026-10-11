/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#include "tape.h"

void Tape::clear() {
  tape_.clear();
}

const Symbol& Tape::read() const {
  auto it = tape_.find(head_);
  if (it == tape_.end()) {
    return blank_symbol_;
  }
  return it->second;
}

void Tape::write(const Symbol& symbol) {
  tape_[head_] = symbol;
}

void Tape::left() {
  --head_;
}

void Tape::right() {
  ++head_;
}

std::ostream& operator<<(std::ostream& os, const Tape& tape) {
  if (tape.tape_.empty()) {
    return os << "[" << tape.blank_symbol_ << "]\n";
  }
  int minPos = tape.head_;
  int maxPos = tape.head_;
  for (const auto& [pos, symbol] : tape.tape_) {
    minPos = std::min(minPos, pos);
    maxPos = std::max(maxPos, pos);
  }
  --minPos;
  ++maxPos;
  for (int i = minPos; i <= maxPos; ++i) {
    auto it = tape.tape_.find(i);
    Symbol symbol = (it != tape.tape_.end()) ? it->second : tape.blank_symbol_;
    if (i == tape.head_) {
      os << "[" << symbol << "]";
    } else {
      os << symbol;
    }
  }
  os << "\n";
  return os;
}
