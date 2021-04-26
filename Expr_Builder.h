#ifndef EXPR_BUILDER_H_EXISTS
#define EXPR_BUILDER_H_EXISTS

#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Number_Node.h"

class Expr_Builder {
public:
	virtual ~Expr_Builder () = 0;
	virtual void build_number (int num) = 0;
	virtual void build_add_operator () = 0;
	virtual void build_subtract_operator () = 0;
	virtual void build_multiply_operator () = 0;
	virtual void build_divide_operator () = 0;
	virtual void build_modulus_operator () = 0;
	virtual void build_open_parenthesis () = 0;
	virtual void build_close_parenthesis () = 0;
	virtual Expr_Node * get_expression () = 0;
private:
};

#endif
