#ifndef DIVIDE_NODE_H_EXISTS
#define DIVIDE_NODE_H_EXISTS

#include "Binary_Node.h"

class Divide_Node : public Binary_Node { 
public:
	Divide_Node ();

	int eval ();

	int precedence();

	void printName();
};


#endif
