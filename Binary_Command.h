#ifndef BINARY_COMMAND_H_EXISTS
#define BINARY_COMMAND_H_EXISTS
#include "Command.h"

class Binary_Command : public Command {
public:
	Binary_Command(Stack <int> & stack);
	void execute();
	virtual int evaluate(int, int) = 0;
	virtual int precedence() = 0;
	virtual void printName() = 0;
};
#endif
