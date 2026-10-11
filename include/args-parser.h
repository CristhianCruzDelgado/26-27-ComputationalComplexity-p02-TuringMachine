/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#ifndef ARGS_PARSER_H_
#define ARGS_PARSER_H_

#include "turing-machine-exception.h"

#include <string_view>
#include <vector>

class ArgsParser {
 public:
  ArgsParser() = default;
  explicit ArgsParser(int argc, char* argv[]);
  const char* getConfigPath() const;
  
 private:
  std::vector<char*> arguments_;
};

#endif
