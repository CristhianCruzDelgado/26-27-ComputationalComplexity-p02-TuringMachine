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
    if (std::isspace(character)) {
      continue;
    }
    Symbol symbol(character);
    if (symbol.isEmptySymbol()) {
      throw std::runtime_error("Alphabet cannot include the empty symbol");
    }
    symbols_.insert(symbol);
  }
  if (symbols_.empty()) {
    throw std::runtime_error("Alphabet cannot be empty");
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
  if (!std::getline(is, line)) {
    throw std::invalid_argument("Invalid input: alphabet undefined");
  }
  alphabet = Alphabet(line);
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
