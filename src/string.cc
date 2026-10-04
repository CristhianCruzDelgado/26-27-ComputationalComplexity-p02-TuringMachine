/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#include "../include/string.h"

String::String(const std::string& symbols) {
  if (symbols.size() == 1 && symbols[0] == Symbol::kEmptySymbol) {
    return;
  }
  symbols_.reserve(symbols.size());
  for (char character : symbols) {
    if (character == Symbol::kEmptySymbol) {
      throw std::invalid_argument("String cannot contain the empty symbol");
    }
    if (character == ' ') {
      continue;
    }
    Symbol symbol(character);
    symbols_.emplace_back(symbol);
  }
}

const Symbol& String::operator[](std::size_t index) const { 
  return symbols_[index]; 
}

const std::vector<Symbol>& String::getString() const { 
  return symbols_; 
}

std::size_t String::size() const { 
  return symbols_.size(); 
}

bool String::empty() const {
  return symbols_.empty();
}

bool operator==(const String& lhs, const String& rhs) {
  return lhs.symbols_ == rhs.symbols_;
}

bool operator<(const String& lhs, const String& rhs) {
  if (lhs.size() != rhs.size()) {
    return lhs.size() < rhs.size();
  }
  return lhs.symbols_ < rhs.symbols_;
}

std::istream& operator>>(std::istream& is, String& string) {
  std::string line;
  if (std::getline(is, line)) {
    string = String(line);
  } else {
    throw std::invalid_argument("Invalid input: string undefined");
  }
  return is;
}

std::ostream& operator<<(std::ostream& os, const String& string) {
  if (string.empty()) {
    return os << Symbol::kEmptySymbol;
  } 
  for (const Symbol& symbol : string.symbols_) {
    os << symbol;
  }
  return os;
}
