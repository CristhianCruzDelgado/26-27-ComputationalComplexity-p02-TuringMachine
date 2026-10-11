/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#ifndef TURING_MACHINE_READER_H_
#define TURING_MACHINE_READER_H_

#include "turing-machine.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class TuringMachineReader {
 public:
  TuringMachineReader() = default;
  TuringMachine readTuringMachine(const char*) const;
  
 private:
  void readLineComments(std::ifstream&) const;
  void readStates(std::vector<std::string>&, std::ifstream&) const;
  void readInputAlphabet(Alphabet&, std::ifstream&) const;
  void readTapeAlphabet(Alphabet&, std::ifstream&) const;
  void readInitialState(const std::vector<std::string>&, 
                        std::string&, 
                        std::ifstream&) const;
  void readBlankSymbol(const Alphabet&, 
                       const Alphabet&, 
                       Symbol&, 
                       std::ifstream&) const;
  void readFinalStates(const std::vector<std::string>&, 
                       std::vector<std::string>&, 
                       std::ifstream&) const;
  void readNumberOfTapes(std::size_t&, std::ifstream&) const;
  void readTransitionFunction(const std::vector<std::string>&, 
                              const Alphabet&, 
                              std::size_t, 
                              Transitions&, 
                              std::ifstream&) const;
};

#endif
