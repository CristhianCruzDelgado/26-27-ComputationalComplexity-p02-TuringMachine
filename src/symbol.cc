/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#include "symbol.h"

char Symbol::getSymbol() const { 
  return symbol_; 
}

bool Symbol::isEmptySymbol() const {
  return symbol_ == kEmptySymbol;
}

bool operator==(const Symbol& lhs, const Symbol& rhs) {
  return lhs.symbol_ == rhs.symbol_;
}

bool operator<(const Symbol& lhs, const Symbol& rhs) {
  return lhs.symbol_ < rhs.symbol_;
}

std::istream& operator>>(std::istream& is, Symbol& symbol) {
  char character;
  if (!(is >> character)) {
    throw std::invalid_argument("Invalid input: symbol undefined");
  }
  symbol.symbol_ = character;
  return is;
}

std::ostream& operator<<(std::ostream& os, const Symbol& symbol) {
  os << symbol.symbol_;
  return os;
}
