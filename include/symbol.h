/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <iostream>
#include <stdexcept>

class Symbol {
 public:
  static constexpr char kEmptySymbol = '.';
  Symbol() = default;
  explicit Symbol(char symbol) : symbol_(symbol) {}
  char getSymbol() const;
  friend bool operator==(const Symbol&, const Symbol&);
  friend bool operator<(const Symbol&, const Symbol&);
  friend std::istream& operator>>(std::istream&, Symbol&);
  friend std::ostream& operator<<(std::ostream&, const Symbol&);
 private:
  char symbol_;
};

#endif
