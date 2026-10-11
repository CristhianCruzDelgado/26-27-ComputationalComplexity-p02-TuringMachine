/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#ifndef MOVEMENT_PARSER_H_
#define MOVEMENT_PARSER_H_

#include "movement.h"

#include <stdexcept>

class MovementParser {
 public:
  MovementParser() = default;
  static Movement MovementFromChar(char);
  static char MovementToChar(const Movement&);
};

#endif
