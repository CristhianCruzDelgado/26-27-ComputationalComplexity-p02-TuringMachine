/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#include "args-parser.h"

ArgsParser::ArgsParser(int argc, char* argv[]) {
  if (argc < 2) {
    throw ParserError();
  }
  arguments_.reserve(argc);
  for (int i = 0; i < argc; ++i) {
    arguments_.emplace_back(argv[i]);
  }
  if (argc == 2 && std::string_view(arguments_[1]) == "-help") {
    throw HelpError();
  } 
  if (argc == 3 && std::string_view(arguments_[1]) == "-config") {
    return;
  }
  throw ParserError();
}

const char* ArgsParser::getConfigPath() const {
  return arguments_[2];
}
