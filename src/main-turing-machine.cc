/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#include "args-parser.h"
#include "turing-machine-app.h"
#include "turing-machine-exception.h"

#include <exception>
#include <iostream>

constexpr int kExitSuccess = 0;
constexpr int kExitFailure = 1;

int main(int argc, char* argv[]) {
  try {
    ArgsParser argsParser(argc, argv);
    TuringMachineApp turing_machine_app(argsParser.getConfigPath());
    turing_machine_app.runApp();
  } catch (const HelpError& e) {
    std::cout << e.what();
    return kExitSuccess;
  } catch (const TuringMachineException& e) {
    std::cerr << "Error: " << e.what();
    return kExitFailure;
  } catch (const std::exception& e) {
    std::cerr << "Unexpected error: " << e.what() << '\n';
    return kExitFailure;
  } catch (...) {
    std::cerr << "Error: unknown failure\n";
    return kExitFailure;
  }
  return kExitSuccess;
}
