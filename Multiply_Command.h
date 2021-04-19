#ifndef MULTIPLY_COMMAND_H_EXISTS
#define MULTIPLY_COMMAND_H_EXISTS

#include "Binary_Command.h"

class Multiply_Command : public Binary_Command {
public:
	Multiply_Command(Stack <int> & stack);

	int evaluate(int, int);

	int precedence();

	void printName();
};

#endif
