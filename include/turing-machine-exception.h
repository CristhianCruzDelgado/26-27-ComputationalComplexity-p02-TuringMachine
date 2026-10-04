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

#include <exception>
#include <string>
#include <string_view>

class TuringMachineException : public std::exception {
 public:
  explicit TuringMachineException(std::string_view message)
      : message_(message) {}
  const char* what() const noexcept override { 
    return message_.c_str(); 
  }
 protected:
  std::string message_;
};

class HelpError : public TuringMachineException {
 public:
  HelpError() 
      : TuringMachineException(
          "Help: This program simulates a Turing Machine (TM)\n"
          "Try: ./turing-machine "
          "-config <../data/[designed|example]TM-[1|2].txt>\n") {}
};

class ParserError : public TuringMachineException {
 public:
  ParserError() 
      : TuringMachineException(
            "Use -help for help\n") {}
};

#endif
