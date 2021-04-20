#ifndef Expr_Tree_Builder_Exists
#define Expr_Tree_Builder_Exists

#include "Expr_Builder.h"
#include "Expr_Tree.h"

class Expr_Tree_Builder : public Expr_Builder {
public:
	Expr_Tree_Builder ();
	~Expr_Builder ();
	void build_number (int num);
	void build_add_command ();
	void create_subtract_command ();
	void create_multiply_command ();
	void create_divide_command ();
	void create_modulus_command ();
	void build_open_parenthesis ();
	void build_close_parenthesis ();
	Math_Expr * get_expression ();
private:
	Expr_Tree * tree_;
};

#endif
