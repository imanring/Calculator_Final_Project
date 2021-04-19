#include "Number_Command.h"

Number_Command::Number_Command (Stack <int> & stack, int val)
: val_ (val),
Command(stack) 
{ }

void Number_Command::execute() {
	stack_.push(this->val_);
}

int Number_Command::precedence() {
	return -1;
}

void Number_Command::printName() {
	std::cout<<"Number: "<<val_<<std::endl;
}
