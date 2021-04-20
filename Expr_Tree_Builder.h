#ifndef Expr_Tree_Builder_Exists
#define Expr_Tree_Builder_Exists

#include "Expr_Builder.h"
#include "Expr_Node.h"

class Expr_Tree_Builder : public Expr_Builder {
public:
	Expr_Tree_Builder ();
	~Expr_Builder ();
	void build_number (int num);
	void build_add_operator ();
	/*void build_subtract_operator ();
	void build_multiply_operator ();
	void build_divide_operator ();
	void build_modulus_operator ();
	void build_open_parenthesis ();
	void build_close_parenthesis ();*/
	Expr_Node * get_expression ();
private:
	Expr_Node * head_;
};

#endif
