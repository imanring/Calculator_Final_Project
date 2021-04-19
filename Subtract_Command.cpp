#include "Subtract_Command.h"

Subtract_Command::Subtract_Command (Stack <int> & stack)
: Binary_Command (stack) { }

int Subtract_Command::evaluate(int lhs, int rhs) {
	return lhs-rhs;
}

int Subtract_Command::precedence() {
	return 0;
}

void Subtract_Command::printName() {
	std::cout<<"Subtract Command"<<std::endl;
}
