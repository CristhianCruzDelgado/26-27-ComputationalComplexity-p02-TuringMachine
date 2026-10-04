/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#include "turing-machine-app.h"

TuringMachineApp::TuringMachineApp(const char* config_path) {
  turing_machine_ = turing_machine_reader_.readTuringMachine(config_path);
  turing_machine_writer_.writeTuringMachine(turing_machine_);
}

void TuringMachineApp::runApp() {
  std::string input_string;
  const std::string exit_string("exit");
  readInputString(input_string);
  while (!(input_string == exit_string)) {
    turing_machine_simulator_.test(turing_machine_, input_string);
    readInputString(input_string);
  }
}

void TuringMachineApp::readInputString(std::string& input_string) {
  std::cout << "Enter the input string to see if it is accepted or rejected by "
    "the automaton\n(press enter for empty string, write 'exit' to quit)\n> ";
  if (!(std::cin >> input_string)) {
    throw std::invalid_argument("Invalid input: stream read failure");
  }
  std::cout << "\n";
}
