#ifndef Expr_Node_H_EXISTS
#define Expr_Node_H_EXISTS

#include <iostream>
class Expr_Node_Visitor;

class Expr_Node {
public:
	Expr_Node ();
	virtual ~Expr_Node();
	virtual int eval() = 0;
	virtual int precedence() = 0;
	// for testing purposes
	virtual void printName() = 0;
	virtual void accept(Expr_Node_Visitor * visitor) = 0;
};

#endif
