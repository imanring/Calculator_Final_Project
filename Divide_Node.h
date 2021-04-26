#ifndef DIVIDE_NODE_H_EXISTS
#define DIVIDE_NODE_H_EXISTS

#include "Binary_Expr_Node.h"

class Divide_Node : public Binary_Expr_Node { 
public:
	Divide_Node ();

	int eval ();

	int precedence();

	void printName();

	//void accept(Expr_Node_Visitor * visitor);
};


#endif
