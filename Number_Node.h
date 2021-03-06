#ifndef NUMBER_NODE_H_EXISTS
#define NUMBER_NODE_H_EXISTS

#include "Expr_Node.h"

class Number_Node : public Expr_Node { 
public:
	Number_Node(int val);
	
	//~Number_Node();

	int eval();

	int precedence();

	void printName();
	
	int getVal();

	void accept (Expr_Node_Visitor * visitor);
private:
	int val_;
};

#endif
