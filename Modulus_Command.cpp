#include "Modulus_Command.h"

Modulus_Command::Modulus_Command (Stack <int> & stack)
: Binary_Command(stack) { }

int Modulus_Command::evaluate(int lhs, int rhs) {
	return lhs%rhs;
}

int Modulus_Command::precedence() {
	return 1;
}

void Modulus_Command::printName() {
	std::cout<<"Modulus Command"<<std::endl;
}
