#include "Binary_Command.h"

Binary_Command::Binary_Command (Stack <int> & stack)
: Command(stack) { }

void Binary_Command::execute() {
	int rhs = stack_.top();
	stack_.pop();
	int lhs = stack_.top();
	stack_.pop();
	stack_.push(this->evaluate(lhs, rhs));
}
