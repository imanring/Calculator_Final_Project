#include "Add_Command.h"

Add_Command::Add_Command(Stack <int> & stack)
: Binary_Command(stack) { }

int Add_Command::evaluate (int lhs, int rhs){
	return lhs+rhs;
}

int Add_Command::precedence() {
	return 0;
}

void Add_Command::printName() {
	std::cout<<"Add Command"<<std::endl;
}
