#ifndef MODULUS_NODE_H_EXISTS
#define MODULUS_NODE_H_EXISTS

#include "Binary_Node.h"

class Modulus_Node : public Binary_Node { 
public:
	Modulus_Node();

	int eval();

	int precedence();

	void printName();
};

#endif
