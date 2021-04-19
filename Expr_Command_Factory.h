#ifndef EXPR_COMMAND_FACTORY_H_EXISTS
#define EXPR_COMMAND_FACTORY_H_EXISTS

#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"
#include "Number_Command.h"

class Expr_Command_Factory {
public:
	virtual ~Expr_Command_Factory(void) = 0;
	virtual Number_Command * create_number_command (int num) = 0;
	virtual Add_Command * create_add_command () = 0;
	virtual Subtract_Command * create_subtract_command () = 0;
	virtual Multiply_Command * create_multiply_command () = 0;
	virtual Divide_Command * create_divide_command () = 0;
	virtual Modulus_Command * create_modulus_command () = 0;
private:
//	Expr_Command_Factory (const Expr_Command_Factory &);
//	const Expr_Command_Factory & operator = (const Expr_Command_Factory &);
};

#endif
