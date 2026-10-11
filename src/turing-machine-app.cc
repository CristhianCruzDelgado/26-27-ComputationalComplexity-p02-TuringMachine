/**
 * Universidad de La Laguna ULL
 * Degree: Computer Engineering
 * Signature: Computational Complexity
 * Practice 02: Turing Machine
 * Author: Cristhian Adoney Cruz Delgado
 * Email: alu0101648293@ull.edu.es
 */

#include "turing-machine-app.h"

constexpr std::string_view kExitCommand = "exit";

TuringMachineApp::TuringMachineApp(const char* config_path) :
    turing_machine_(TuringMachineReader().readTuringMachine(config_path)) {}

void TuringMachineApp::runApp() {
  TuringMachineWriter().writeTuringMachine(turing_machine_);
  std::string input_string;
  readInputString(input_string);
  while (!(input_string == kExitCommand)) {
    turing_machine_simulator_.test(turing_machine_, input_string);
    readInputString(input_string);
  }
}

void TuringMachineApp::readInputString(std::string& input_string) {
  printInstructions();
  if (!(std::getline(std::cin, input_string))) {
    throw std::invalid_argument("Invalid input: stream read failure");
  }
  std::cout << "\n";
}

void TuringMachineApp::printInstructions() {
  std::cout << "Enter the input string to see if it is accepted or rejected "
               "by the machine\n(press enter for the empty string, write '"
            << kExitCommand << "' to quit)\n> ";
}
