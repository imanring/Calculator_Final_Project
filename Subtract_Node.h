#ifndef SUBTRACT_NODE_H_EXISTS
#define SUBTRACT_NODE_H_EXISTS

#include "Binary_Node.h"

class Subtract_Node : public Binary_Node {
public:
	Subtract_Node ();

	int eval ();

	int precedence();

	void printName();
};

#endif
