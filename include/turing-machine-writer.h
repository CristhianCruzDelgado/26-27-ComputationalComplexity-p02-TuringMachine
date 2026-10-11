/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#ifndef TURING_MACHINE_WRITER_H_
#define TURING_MACHINE_WRITER_H_

#include "turing-machine.h"

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class TuringMachineWriter {
 public:
  TuringMachineWriter() = default;
  void writeTuringMachine(const TuringMachine&) const;
 private:
  void writeStates(const std::vector<std::string>&) const;
  void writeTransitions(const Transitions&) const;
  void writeSymbols(const std::vector<Symbol>&) const;
  void writeMovements(const std::vector<Movement>&) const;
};

#endif
