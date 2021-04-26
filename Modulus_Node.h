#ifndef MODULUS_NODE_H_EXISTS
#define MODULUS_NODE_H_EXISTS

#include "Binary_Expr_Node.h"

class Modulus_Node : public Binary_Expr_Node { 
public:
	Modulus_Node();

	int eval();

	int precedence();

	void printName();

	//void accept(Expr_Node_Visitor * visitor);
};

#endif
