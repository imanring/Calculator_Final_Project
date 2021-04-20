#ifndef EXPR_COMMAND_FACTORY_H_EXISTS
#define EXPR_COMMAND_FACTORY_H_EXISTS

#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Number_Node.h"

class Expr_Builder {
public:
	virtual ~Expr_Builder (void) = 0;
	virtual void build_number (int num) = 0;
	virtual void build_add_command () = 0;
	virtual void create_subtract_command () = 0;
	virtual void create_multiply_command () = 0;
	virtual void create_divide_command () = 0;
	virtual void create_modulus_command () = 0;
	virtual void build_open_parenthesis (void) = 0;
	virtual void build_close_parenthesis (void) = 0;
	virtual Expr_Node * get_expression (void) = 0;
private:
};

#endif