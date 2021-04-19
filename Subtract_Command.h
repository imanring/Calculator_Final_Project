#ifndef SUBTRACT_COMMAND_H_EXISTS
#define SUBTRACT_COMMAND_H_EXISTS

#include "Binary_Command.h"

class Subtract_Command : public Binary_Command {
public:
	Subtract_Command(Stack <int> & stack);

	int evaluate(int, int);

	int precedence();

	void printName();
};

#endif
