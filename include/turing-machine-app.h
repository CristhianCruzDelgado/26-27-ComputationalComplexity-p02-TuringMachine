/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#ifndef TURING_MACHINE_APP_H_
#define TURING_MACHINE_APP_H_

#include <iostream>
#include <stdexcept>
#include <string_view>

#include "turing-machine.h"
#include "turing-machine-simulator.h"
#include "turing-machine-reader.h"
#include "turing-machine-writer.h"

class TuringMachineApp {
 public:
  TuringMachineApp() = default;
  explicit TuringMachineApp(const char*);
  void runApp();
 private:
  void readInputString(std::string&);
  void printInstructions();
  TuringMachine turing_machine_;
  TuringMachineSimulator turing_machine_simulator_;
};

#endif
