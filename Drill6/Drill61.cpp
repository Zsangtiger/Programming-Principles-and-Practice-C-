/*
Write a program using a single file containing three namespaces X, Y, and Z so that the
following main() works correctly:
*/
#include "std_lib_facilities.h"

namespace X {
	int var = 0;
	void print() {
		cout << var<<" From X\n";
	}

}
namespace Y {
	int var = 0;
	void print() {
		cout << var<<" From Y\n";
	}
}

namespace Z{
	int var = 0;
	void print() {
		cout << var << " From Z\n";
	}
}
int main()
{
	X::var = 7;
	X::print(); // print X’s var
	using namespace Y;
	var = 9;
	print(); // print Y’s var
	{ using Z::var;
	using Z::print;
	var = 11;
	print(); // print Z’s var
	}
	print(); // print Y’s var
	X::print(); // print X’s var
}/*Review
1. What is the difference between a declaration and a definition ?
	A declaration tells the compiler that a name exist, a definition is a declaration that allocates memory.

2. How do we syntactically distinguish between a function declarationand a function definition ?
	A definition has the return_type name(param1, param2 ) { body }; syntax, A declaration doesn't have a body.
3. How do we syntactically distinguish between a variable declarationand a variable definition ?
	int a; int definition; extern int a; declaration
4. Why can’t you use the functions in the calculator program from Chapter 6 without declaring
them first ?
	Because they call each other in a circle, and a function can't be calle unless it is declared.


5. Is int a; a definition or just a declaration ?
	It is a definition. It sets aside memory for an int;
6. Why is it a good idea to initialize variables as they are declared ?
	Because if we don't initialize them we run into bugs, as they get assigned implementation defined values
7. What can a function declaration consist of ?
	return type, name, funciton braces (), parameter definitions, or just tipes of the formal parameters
8. What good does indentation do ?
	Makes the program easily readable, manageable. Especially signifies finding the beginning and end of a scope (Look at python)
9. What are header files used for ?
	They contain declarations of variables, fuctions, classes. They are included in files where these declarations are needed.
10. What is the scope of a declaration ?
	The scope of a declaration is the part of the code where it can be used. It starts with the declarations and ends with the scope the declaration is in.
11. What kinds of scope are there ? Give an example of each.
	Global scope int a; int main(){;};. Namespace scope namespace{int a;};, Class scope class foo{int a;};, Local scope int fo(){ {string local_scope;}}, statement scope. for(){string statement_scope;}
12. What is the difference between a class scopeand local scope ?
	 They handle declarations differently
13. Why should a programmer minimize the number of global variables ?
	Because global names can clash easily, and it is hard to tell which funciton modifies the values of globals.
14. What is the difference between pass - by - value and pass - by - reference ?
	Passing by value means we are initializing new variables with the values we pass, passing by reference gives another name to the same adress of memory
15. What is the difference between pass - by - reference and pass - by - const - reference ?
	Both use reference, const reference won't allow the function to change the values.
16. What is a swap() ?
	A funciton which swaps values of arguments
17. Would you ever define a function with a vector<double>-by - value parameter ?
	No because if the value of the vector is large the copy initialization becomes expensive and slow
18. Give an example of undefined order of evaluation.Why can undefined order of evaluation be a
problem ?
	int v[i] = ++i;
	Here we don't know wheather ++i or i will be evaluated first, as a result it gives us different results.
19. What do x&& yand x || y, respectively, mean ?
	x && y is false if either x is false or y is false true otherwise. x || y is true if either x is true or y is true false otherwise
20. Which of the following is standard - conforming C++ : functions within functions, functions
within classes, classes within classes, classes within functions ?
	Classes within classes, functions within classes, classes within funcitons.
21. What goes into an activation record ?
	An activation record of a function is a data structure the compiler sets aside for the variables of the function and to know where to return and with what.
22. What is a call stack and why do we need one ?
	A stack of funciton activation records. C++ uses it to keep track of the funciton calls during the run of a program.
23. What is the purpose of a namespace ?
	To keep names conflict free
24. How does a namespace differ from a class ?
	Drom namespaces we don't create objects.
25. What is a using declaration ?
	using namespace::entity
26. Why should you avoid using directives in a header ?
	They cause naming conflicts as headers are copied into cpp-s.
27. What is namespace std ?
	A namespace for the elements of the standard library
*/

/*
Terms
activation record
	a datastructure a function creates for its variables and return value, and adress to return to.
argument
	The values a function gets are called function variables
argument passing
	When formal parameters get values.
call stack
	A stack of activation records is a funtion call stack.
class scope
	The code inside of a class
const
	The variable can't change value
constexpr
	A value that is know at compile time
declaration
	Introducing a name to a scope
definition
	Allocating memory for a declaration
extern
	Keyword to tell a variable is just declared
forward declaration
	Declaring a function or class first and defining it later
function
	A computation. Collection of statements with a return type, name, and arguments
function definition
	The body fo a function.
global scope
	The scope that is not a namespace scope, class scope, local scope, statement scope
header file
	A file containing declarations
initializer
	The value we give a variable when defined.
local scope
	between {} of a block or in function argument list.
namespace
	A scope with a name.
namespace scope
	Code within a namespace
nested block
	A block within a block
parameter
	The argument of a funciton
pass-by-const-reference
	Giving a value by cont reference means we give just the adress, and we can't change the variable in the funciton
pass-by-reference
	Giving the adress of a variable to a function.
pass-by-value
	Initializing a new variable with from the argument of a function
recursion
	A funciton calling itself is a recursion
return
	Statement that return a value form a funciton
return value
	The value returned by the funciton
scope
	A scpoe is a region of program text
statement scope
	A scope in a statement
technicalities
	Details of something
undeclared identifier
	A name that isn't declared before it's used
using declaration
	A statement to tell the compiler an entity from a namespace is used without qualification
using directive	A statement to tell the compiler a namespace is used without qualification
*/