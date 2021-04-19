#ifndef COMMAND_H_EXISTS
#define COMMAND_H_EXISTS

#include "Stack.h"
#include <iostream>

class Command {
public:
	Command(Stack <int> & stack);
	virtual void execute() = 0;
	virtual int precedence() = 0;
	// for testing purposes
	virtual void printName() = 0;
protected:
	Stack <int> & stack_;
};

#endif
