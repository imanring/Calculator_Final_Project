#ifndef EXPR_COMMAND_FACTORY_H_EXISTS
#define EXPR_COMMAND_FACTORY_H_EXISTS

#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"
#include "Number_Command.h"

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
	virtual Math_Expr * get_expression (void) = 0;
private:
};

#endif
