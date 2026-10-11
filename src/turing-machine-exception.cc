/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#include "turing-machine-exception.h"

constexpr std::string_view kHelpError =
  "Help: This program simulates a Turing Machine (TM)\n"
  "Try: ./turing-machine -config <../data/[designed|example]TM-[1|2].txt>\n";
constexpr std::string_view kParserError = "Use -help for help\n";

TuringMachineException::TuringMachineException(std::string_view message)
    : std::runtime_error(std::string(message)) {}

HelpError::HelpError() : TuringMachineException(kHelpError) {}

ParserError::ParserError() : TuringMachineException(kParserError) {}
