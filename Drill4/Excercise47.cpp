/*
7. Write a grammar for bitwise logical expressions. A bitwise logical expression is much like an
arithmetic expression except that the operators are ! (not), ~ (complement), & (and), | (or), and
^ (exclusive or). Each operator does its operation to each bit of its integer operands (see
§25.5). ! and ~ are prefix unary operators. A ^ binds tighter than a | (just as * binds tighter than
+) so that x|y^z means x|(y^z) rather than (x|y)^z. The & operator binds tighter than ^ so that
x^y&z means x^(y&z).

In this case the binding rules are:

Unary uperators always binds first. That is ! and ~ ;
These must be next to last rules. The last is reading a bit.

Then comes  &

Then ^

Then |

Other than that i assume the bitwise operations are left associative.

BitwiseExpr:
	Term
	BitwiseExpr Term
Term:
	term2
	Term | term2
Term2:
	Term3
	Term3 ^ Term2
Term3:
	Term4
	Term4 & Term3
Term4:
	Term5
	Term6 Term5
Term5:
	integer literal
Term6:
	~
	!
*/