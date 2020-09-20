#include "std_lib_facilities.h"
/*

Below are 25 code fragments. Each is meant to be inserted into this “scaffolding”:
#include "std_lib_facilities.h"
int main()
try {
<<your code here>>
keep_window_open();
return 0;
}
catch (exception& e) {
cerr << "error: " << e.what() << '\n';
keep_window_open();
return 1;
}
catch (...) {
cerr << "Oops: unknown exception!\n";
keep_window_open();
return 2;
}
Each has zero or more errors. Your task is to find and remove all errors in each program. When you
have removed those bugs, the resulting program will compile, run, and write “Success!” Even if you
think you have spotted an error, you still need to enter the (original, unimproved) program fragment
and test it; you may have guessed wrong about what the error is, or there may be more errors in a
fragment than you spotted. Also, one purpose of this drill is to give you a feel for how your compiler
reacts to different kinds of errors. Do not enter the scaffolding 25 times — that’s a job for cut and
paste or some similar “mechanical” technique. Do not fix problems by simply deleting a statement;
repair them by changing, adding, or deleting a few characters.
1. Cout << "Success!\n";
2. cout << "Success!\n;
3. cout << "Success" << !\n"
4. cout << success << '\n';
5. string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
6. vector<int> v(10); v(5) = 7; if (v(5)!=7) cout << "Success!\n";
7. if (cond) cout << "Success!\n"; else cout << "Fail!\n";
8. bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
9. string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n";
10. string s = "ape"; if (s=="fool") cout << "Success!\n";
11. string s = "ape"; if (s=="fool") cout < "Success!\n";
12. string s = "ape"; if (s+"fool") cout < "Success!\n";
13. vector<char> v(5); for (int i=0; 0<v.size(); ++i) ; cout << "Success!\n";
14. vector<char> v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
15. string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s[i];
16. if (true) then cout << "Success!\n"; else cout << "Fail!\n";
17. int x = 2000; char c = x; if (c==2000) cout << "Success!\n";
18. string s = "Success!\n"; for (int i=0; i<10; ++i) cout << s[i];
19. vector v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
20. int i=0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n";
21. int x = 2; double d = 5/(x–2); if (d==2*x+0.5) cout << "Success!\n";
22. string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i];
23. int i=0; while (i<10) ++j; if (j<i) cout << "Success!\n";
24. int x = 4; double d = 5/(x–2); if (d=2*x+0.5) cout << "Success!\n";
25. cin << "Success!\n";

*/

/*
	/Corercted code

	cout << "Success!\n";
	cout << "Success!\n";
	cout << "Success" << "!\n";
	cout << "Success!" << '\n';
	int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
	vector<int> v(10); v[5] = 7; if (v[5] == 7) cout << "Success!\n";
	if (true) cout << "Success!\n"; else cout << "Fail!\n";
	bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";
	string s = "ape"; bool c = "fool" > s; if (c) cout << "Success!\n";
	string s = "ape"; if (s == "ape") cout << "Success!\n";
	string s = "ape"; if (s == "ape") cout << "Success!\n";
	string s = "ape"; if (s < "fool") cout << "Success!\n";
	vector<char> v(5); for (int i=0; i<v.size(); ++i) ; cout << "Success!\n";
	vector<char> v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n";
	string s = "Success!\n"; for (int i = 0; i < 9; ++i) cout << s[i];
	if (true) cout << "Success!\n"; else cout << "Fail!\n";
	int x = 2000; int c = x; if (c == 2000) cout << "Success!\n";
	string s = "Success!\n"; for (int i = 0; i < 9; ++i) cout << s[i];
	vector<int> v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n";
	int i = 0; int j = 9; while (i < 10) ++i; if (j < i) cout << "Success!\n";
	int x = 2; double d = 5 - 0.5; if (d == 2 * x + 0.5) cout << "Success!\n";
	string s = "Success!\n"; for (int i = 0; i < 9; ++i) cout << s[i];
	int j = 9; int i = 0; while (i < 10) ++i; if (j < i) cout << "Success!\n";
	int x = 4; double d = 17 / (x-2); if (d = 2 * x + 0.5) cout << "Success!\n";
	

*/
int main()
try {
	//Insert line from above here
		keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}/*1. Name four major types of errors and briefly define each one.
	-Compile time error
		-Errors caught by the compiler, syntax errors and type erros
	-Linking error
		-Errors happening during the linking. Misssing function declarations is an example
	-Runtime error
		-Errors happening at runtime by out of range error, illegal types
	-Logic error
		-Errors made by a programmer, the program works fine it just doesn't do what we hoped it would
2. What kinds of errors can we ignore in student programs?
	-Misbehaving hardware
	-Misbehaving system software
	-Can't terminate when error happens
3. What guarantees should every completed project offer?
	-For correct inputs it sould produce correct output
	-For incorrect inputs it gives an error.
4. List three approaches we can take to eliminate errors in programs and produce acceptable
software.
	-Organise software to minimize errors
	-Eliminate error through debugging and testing
	-Make sure that the remaining errors are not serious
5. Why do we hate debugging?
	It takes a long time, and we have no guarantee to find all the bugs, it can be pretty hard to find an error.
6. What is a syntax error? Give five examples.
	Using a syntax incorrectly.
		int a == 2;
		cout >> "alma";
		in b = 3;
		int b = 2
		vector<> v(4;

7. What is a type error? Give five examples.
	A type error is a mismatch between a variable, function etc declared type and the value supplied to it
		int k = "alma"
		int f(int){;}; f('z');
		int k = 2.9999 (narrowing)

8. What is a linker error? Give three examples.
	Error happening when the linker tries to link the translation units together
		-call to a funciton f(int,int); Which has no definition. Or has 2 definitions.
9. What is a logic error? Give three examples.
	The program prdudces incorrect output
	int area(int widht, int length){
		return width+length;
	}
	The function above works fine it just doesn't calculate an area.
10. List four potential sources of program errors discussed in the text.
	-Poor sepcification
	-Incomplete program
	-Unexpected arguments
	-Unexpected inputs
	-Unexpected state
	-Logical errors
11. How do you know if a result is plausible? What techniques do you have to answer such
questions?
	-Guesstimations. Trying to guess or estimate a plausible result.
	-Research. Using the internet or other source of data to compare my result to.
12. Compare and contrast having the caller of a function handle a run-time error vs. the called
function’s handling the run-time error.
	-When the caller handles the error the code becomes messy quckly. Needs code duplication
	-When the callee handles the error the function can become longer, creates runtime overhead, the body of a funciton must be knowm and occasionally modified in order to handle errors.
	As a solution the calle tipically throws and a caller handles the thrown object in a try block.

13. Why is using exceptions a better idea than returning an “error value”?
	-Sometimes a return value can become a source of confushion.
	-Sometimes the set of plausible return values includes every possible values so we can't tell whether we are returning an erorr or a legit value

14. How do you test if an input operation succeeded?
	if(cin)
	This test if the cin object is good. 
15. Describe the process of how exceptions are thrown and caught.
	When we get an unexpected result, we throw and exception either and object we defined or an exception object defined by the standard
	We put the function into a try block. 
	The closest catch block will handle the error we thrown form the function that has that type of parameter we are throwing

16. Why, with a vector called v, is v[v.size()] a range error? What would be the result of calling
this?

	because the elements are indexed from 0; For 6 elements the biggest legal index is 5. An exception will be raised, and either we handle the exception in a try catch block or the program exits with the error thrown.

17. Define pre-condition and post-condition; give an example (that is not the area() function from
this chapter), preferably a computation that requires a loop.
	Pre conditions are our expectations to the input variables of a function

	bool heigth(vector<int> v){
		//pre-condition all the values are positive numbers. Heigth can't be negative

		int sum = 0;
		for(int it : v)
		{
			sum += it;
		}
		return sum/v.size();

		/post condition the returned value is greater than the min of vector values and smaller than the max.
	}

18. When would you not test a pre-condition?
	When testing the precondition is really complex or expensive ie. is the input data structure ordered correctly
19. When would you not test a post-condition?
	? Probably only if it's too hard to test / would always test it
20. What are the steps in debugging a program?
	Solve the compile time problems
	Solve the link time errors
	Solve runtime and logic errors
21. Why does commenting help when debugging?
	In comments we can tell what the code is supposed to do. If there are unfinished cases, unhandled inputs, can tell what complicated and long functions do.
22. How does testing differ from debugging?	In testing we compare the output of our program from a set of systematically selected inputs to what we expect.	In debugging we find an error and correct it.	*/