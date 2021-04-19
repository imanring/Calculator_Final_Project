#ifndef MODULUS_COMMAND_H_EXISTS
#define MODULUS_COMMAND_H_EXISTS

#include "Binary_Command.h"

class Modulus_Command : public Binary_Command { 
public:
	Modulus_Command(Stack <int> & stack);

	int evaluate(int, int);

	int precedence();

	void printName();
};

#endif
