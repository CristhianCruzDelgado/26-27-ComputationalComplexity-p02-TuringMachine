/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#include "alphabet.h"

Alphabet::Alphabet(const std::string& symbols) {
  for (char character : symbols) {
    if (character == Symbol::kEmptySymbol) {
      throw std::invalid_argument("Alphabet cannot include the empty symbol");
    }
    if (character == ' ') {
      continue;
    }
    Symbol symbol(character);
    symbols_.insert(symbol);
  }
  if (symbols_.empty()) {
    throw std::invalid_argument("Alphabet cannot be empty");
  } 
}

const std::set<Symbol>& Alphabet::getSymbols() const {
  return symbols_;
}

std::size_t Alphabet::size() const {
  return symbols_.size();
}

bool Alphabet::empty() const {
  return symbols_.empty();
}

bool Alphabet::includes(const Symbol& symbol) const {
  return symbols_.find(symbol) != symbols_.end();
}

std::istream& operator>>(std::istream& is, Alphabet& alphabet) {
  std::string line;
  if (std::getline(is, line)) {
    alphabet = Alphabet(line);
  } else {
    throw std::invalid_argument("Invalid input: alphabet undefined");
  }
  return is;
}

std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  os << "{";
  bool first = true;
  for (const Symbol& symbol : alphabet.symbols_) {
    if (!first) {
      os << ", ";
    }
    os << symbol;
    first = false;
  }
  os << "}";  
  return os;
}
