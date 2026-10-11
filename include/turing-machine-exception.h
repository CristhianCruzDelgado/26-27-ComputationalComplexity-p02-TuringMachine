/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#ifndef TURING_MACHINE_EXCEPTION_H_
#define TURING_MACHINE_EXCEPTION_H_

#include <stdexcept>
#include <string>
#include <string_view>

class TuringMachineException : public std::runtime_error {
 public:
  explicit TuringMachineException(std::string_view message);
};

class HelpError : public TuringMachineException {
 public:
  HelpError();
};

class ParserError : public TuringMachineException {
 public:
  ParserError();
};

#endif
