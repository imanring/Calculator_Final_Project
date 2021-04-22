#ifndef CALCULATOR_H_EXISTS
#define CALCULATOR_H_EXISTS

#include "Binary_Expr_Node.h"
#include "Stack.h"

class Calculator {
public:
	Calculator ();
	~Calculator ();
	void addOp (Binary_Expr_Node * op);
	void addNode (Expr_Node * node);
	void print();
	Expr_Node * get_expression();
private:
	Stack<Expr_Node *> nodes_;
	Stack<Binary_Expr_Node *> ops_;
};

#endif
