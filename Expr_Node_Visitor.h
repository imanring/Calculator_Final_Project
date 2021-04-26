#ifndef EXPR_NODE_VISITOR_H_EXISTS
#define EXPR_NODE_VISITOR_H_EXISTS

#include "Binary_Expr_Node.h"
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Number_Node.h"

class Expr_Node_Visitor {
public:
	virtual ~Expr_Node_Visitor() {};
	virtual void visit_add_operator (const Add_Node * add) = 0;
	virtual void visit_subtract_operator (const Subtract_Node * subtract) = 0;
	virtual void visit_multiply_operator (const Multiply_Node * mult) = 0;
	virtual void visit_divide_operator (const Divide_Node * divide) = 0;
	virtual void visit_modulus_operator(const Modulus_Node * mod) = 0;
	virtual void void_number (const Number_Node * num) = 0;
};

#endif
