#include "Divide_Command.h"

Divide_Command::Divide_Command (Stack <int> & stack)
: Binary_Command(stack) { }

int Divide_Command::evaluate(int lhs, int rhs) {
	return lhs / rhs;
}

int Divide_Command::precedence() {
	return 1;
}

void Divide_Command::printName() {
	std::cout<<"Divide Command"<<std::endl;
}
