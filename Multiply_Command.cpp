#include "Multiply_Command.h"

Multiply_Command::Multiply_Command (Stack <int> & stack)
: Binary_Command(stack) { }

int Multiply_Command::evaluate(int lhs, int rhs) {
	return lhs * rhs;
}

int Multiply_Command::precedence() {
	return 1;
}

void Multiply_Command::printName() {
	std::cout<<"Multiply Command"<<std::endl;
}
