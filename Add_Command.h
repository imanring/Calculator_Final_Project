#ifndef ADD_COMMAND_H_EXISTS
#define ADD_COMMAND_H_EXISTS

#include "Binary_Command.h"

class Add_Command : public Binary_Command {
public:
	Add_Command (Stack <int> & stack);

	int evaluate(int, int);
	int precedence();
	void printName();
};
#endif
