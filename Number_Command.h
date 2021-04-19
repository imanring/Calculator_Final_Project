#ifndef NUMBER_COMMAND_H_EXISTS
#define NUMBER_COMMAND_H_EXISTS

#include "Command.h"

class Number_Command : public Command { 
public:
	Number_Command(Stack <int> & stack, int val);

	void execute();

	int precedence();

	void printName();
private:
	int val_;
};

#endif
