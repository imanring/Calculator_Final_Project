#ifndef DIVIDE_COMMAND_H_EXISTS
#define DIVIDE_COMMAND_H_EXISTS

#include "Binary_Command.h"

class Divide_Command : public Binary_Command { 
public:
	Divide_Command(Stack <int> & stack);

	int evaluate(int, int);

	int precedence();

	void printName();
};


#endif
