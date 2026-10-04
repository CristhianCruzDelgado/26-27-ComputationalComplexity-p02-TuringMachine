/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#include "movement-parser.h"

Movement MovementParser::MovementFromChar(char c) {
  switch (c) {
    case 'L': return Movement::LEFT;
    case 'R': return Movement::RIGHT;
    case 'S': return Movement::STAY;
    default: throw std::invalid_argument("Invalid movement");
  }
}

char MovementParser::MovementToChar(const Movement& move) {
  switch (move) {
    case Movement::LEFT: return 'L';
    case Movement::RIGHT: return 'R';
    case Movement::STAY: return 'S';
    default: throw std::invalid_argument("Invalid movement");
  }
}
