#ifndef NUMBER_NODE_H_EXISTS
#define NUMBER_NODE_H_EXISTS

#include "Expr_Node.h"

class Number_Node : public Expr_Node { 
public:
	Number_Command(int val);

	int eval();

	int precedence();

	void printName();
private:
	int val_;
};

#endif
