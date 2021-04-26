#ifndef ADD_NODE_H_EXISTS
#define ADD_NODE_H_EXISTS

#include "Binary_Expr_Node.h"

class Add_Node : public Binary_Expr_Node {
public:
	Add_Node ();
	//~Add_Node ();
	int eval ();
	int precedence();
	void printName();
	//void accept(Expr_Node_Visitor * visitor);
};
#endif
