/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#ifndef TURING_MACHINE_SIMULATOR_H_
#define TURING_MACHINE_SIMULATOR_H_

#include "tape.h"
#include "turing-machine.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

class TuringMachineSimulator {
 public:
  TuringMachineSimulator() = default;
  void test(const TuringMachine&, const std::string&) const;
  
 private:
  void printTapes(const std::vector<Tape>&) const;
};

#endif
