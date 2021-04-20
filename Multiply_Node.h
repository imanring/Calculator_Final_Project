#ifndef MULTIPLY_NODE_H_EXISTS
#define MULTIPLY_NODE_H_EXISTS

#include "Binary_Node.h"

class Multiply_Node : public Binary_Node {
public:
	Multiply_Node ();

	int eval ();

	int precedence();

	void printName();
};

#endif
