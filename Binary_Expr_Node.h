#ifndef BINARY_EXPR_NODE_H_EXISTS
#define BINARY_EXPR_NODE_H_EXISTS

#include "Expr_Node.h"

class Binary_Expr_Node : public Expr_Node {
public:
	Binary_Expr_Node ();
	Binary_Expr_Node (Expr_Node * left, Expr_Node * right);
	~Binary_Expr_Node ();
	virtual int eval () = 0;
	void setLeft (Expr_Node * left);
	void setRight (Expr_Node * right);
	virtual int precedence() = 0;
	virtual void printName() = 0;
protected:
	Expr_Node * left_;
	Expr_Node * right_;
};
#endif
