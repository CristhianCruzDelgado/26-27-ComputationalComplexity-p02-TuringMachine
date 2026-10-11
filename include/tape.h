/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#ifndef TAPE_H_
#define TAPE_H_

#include <algorithm>
#include <iostream>
#include <unordered_map>

#include "symbol.h"

class Tape {
 public:
  Tape() = default;
  explicit Tape(const Symbol& blank_symbol) 
    : head_(0), blank_symbol_(blank_symbol) {}
  void clear();
  const Symbol& read() const;
  void write(const Symbol&);
  void left();
  void right();
  friend std::ostream& operator<<(std::ostream&, const Tape&);

 private:
  std::unordered_map<int, Symbol> tape_;
  int head_;
  Symbol blank_symbol_;
};

#endif
