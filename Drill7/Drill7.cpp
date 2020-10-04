// Drill7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

/*
This drill simply involves getting the sequence of versions of Date to work. For each version define
a Date called today initialized to June 25, 1978. Then, define a Date called tomorrow and give it
a value by copying today into it and increasing its day by one using add_day(). Finally, output
today and tomorrow using a << defined as in §9.8.
Your check for a valid date may be very simple. Feel free to ignore leap years. However, don’t
accept a month that is not in the [1,12] range or day of the month that is not in the [1,31] range. Test
each version with at least one invalid date (e.g., 2004, 13, –5).
1. The version from §9.4.1
2. The version from §9.4.2
3. The version from §9.4.3
4. The version from §9.7.1
5. The version from §9.7.4
*/

// simple Date
struct Date942 {
    int y, m, d; // year, month, day
    Date942(int y, int m, int d); // check for valid date and initialize
    void add_day(int n); // increase the Date by n days
};

bool is_valid(Date942& dd) {
    if (dd.d < 1 || dd.d > 31)
        return false;
    else if (dd.m < 1 || dd.m > 12)
        return false;
    else if (dd.y > 3000)
        return false;
    else
        return true;
}

class Date943 {
    int y, m, d; // year, month, day
public:
    Date943(int y, int m, int d); // check for valid date and initialize
    void add_day(int n); // increase the Date by n days
    int month() const { return m; }
    int day() const { return d; }
    int year() const { return y; }
};

bool is_valid(Date943& dd) {
    if (dd.day() < 1 || dd.day() > 31)
        return false;
    else if (dd.month() < 1 || dd.month() > 12)
        return false;
    else if (dd.year() > 3000)
        return false;
    else
        return true;
}

void Date943::add_day(int n) {
    this->d += n;
    if (!is_valid(*this))
        error("This date is not valid\n");
}

Date943::Date943(int yy, int mm, int dd) : d{ dd }, m{ mm }, y{ yy }{};

Date942::Date942(int yy, int mm, int dd) : y{ yy }, m{ mm }, d{ dd }{};

void Date942::add_day(int n) {
    d += n;
    if (!is_valid(*this))
        error("Date is not in a valid state\n");
};

// simple Date (too simple?)
struct Date941 {
    int y; // year
    int m; // month in year
    int d; // day of month
};

ostream& operator<<(ostream& os, const Date941& d)
{
    return os << '(' << d.y
        << ',' << d.m
        << ',' << d.d << ')';
}

ostream& operator<<(ostream& os, const Date942& d)
{
    return os << '(' << d.y
        << ',' << d.m
        << ',' << d.d << ')';
}

ostream& operator<<(ostream& os, const Date943& d)
{
    return os << '(' << d.year()
        << ',' << d.month()
        << ',' << d.day() << ')';
}

bool is_valid(Date941&);

void add_day(Date941& dd, int n)
{
    dd.d++;
    if (!is_valid(dd))
        error("Date is not in a valid state\n");
    // increase dd by n days
}

bool is_valid(Date941& dd) {
    if (dd.d < 1 || dd.d > 31)
        return false;
    else if (dd.m < 1 || dd.m > 12)
        return false;
    else if (dd.y > 3000) 
        return false;
    else
        return true;
}

class Year { // year in [min:max) range
    static const int min = 1800;
    static const int max = 2200;
public:
    class Invalid { };
    Year(int x) : y{ x } { if (x < min || max <= x) throw Invalid{}; }
    int year() const { return y; }
private:
    int y;
};

enum class Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

/*
ostream& operator<<(ostream& os, Month mm) {
    switch (mm) {
    case Month::jan :
        os << "January";
        break;
    case Month::feb :
        os << "February";
        break;
    case Month::mar:
        os << "March";
        break;
    case Month::apr:
        os << "April";
        break;
    case Month::may:
        os << "May";
        break;
    case Month::jun:
        os << "June";
        break;
    case Month::jul:
        os << "July";
        break;
    case Month::aug:
        os << "August";
        break;
    case Month::sep:
        os << "September";
        break;
    case Month::oct:
        os << "October";
        break;
    case Month::nov:
        os << "November";
        break;
    case Month::dec:
        os << "December";
        break;
    default:
        cerr << "Invalid month";
    }
    return os;
}
*/

ostream& operator<<(ostream& os, Month m) {
    os << int(m);
    return os;
}

class Date971 {
public:
    Date971(Year y, Month m, int d); // check for valid date and initialize
    // . . .
    void add_day(int n);
    Year year() const { return y; };
    Month month() const { return m; };
    int day() const { return d; };
private:
    Year y;
    Month m;
    int d; // day
};

Date971::Date971(Year yy, Month mm, int dd) : y{ yy }, m{ mm }, d{dd} {
}

bool is_valid(Date971& dd) {
    if (dd.day() < 1 || dd.day() > 31)
        return false;
    else if (dd.year().year() > 3000)
        return false;
    else
        return true;
}

void Date971::add_day(int n) {
    this->d += n;
    if (!is_valid(*this))
        error("not a valid date \n");
}

ostream& operator<<(ostream& os, const Date971& d)
{
    return os << '(' << d.year().year()
        << ',' << d.month()
        << ',' << d.day() << ')';
}

class Date974 {
public:
    class Invalid {};
    // . . .
    Date974(int, Month, int);
    int day() const { return d; }; // const member: can’t modify the object
    Month month() const { return m; }; // const member: can’t modify the object
    int year() const { return y; }; // const member: can’t modify the object
    void add_day(int n); // non-const member: can modify the object
    void add_month(int n); // non-const member: can modify the object
    void add_year(int n); // non-const member: can modify the object
    void is_valid();
private:
    int y; // year
    Month m;
    int d; // day of month
};

void Date974::is_valid() {
    if (this->d < 1 || this->d > 31)
        throw Invalid();
}

void Date974::add_day(int n) {
    this->d += n;
    is_valid();
};

void Date974::add_month(int n) {
    this->m = Month((int(this->m) + n) % 12);
    is_valid();
}

void Date974::add_year(int n) {
    this->y += n;
    is_valid();
}


Date974::Date974(int yy, Month mm, int dd) : y{ yy }, m{ mm }, d{ dd }{
    if (d < 1 || d > 31 || y < 1000 || y > 3000) throw Invalid();
};

ostream& operator<<(ostream& os, const Date974& d)
{
    return os << '(' << d.year()
        << ',' << d.month()
        << ',' << d.day() << ')';
}

int main()
{
    Date941 today1 = Date941{1978,6,25}; // a Date variable (a named object)
    Date941 tomorrow1 = Date941{ today1 };
    add_day(tomorrow1, 1);
    cout << today1 << tomorrow1 << '\n';

    Date942 today2 = Date942{ 1978,6,25 };
    Date942 tomorrow2 = Date942{ today2 };
    tomorrow2.add_day(1);
    cout << today2 << tomorrow2 << '\n';

    Date943 today3 = Date943{ 1978,6,25 };
    Date943 tomorrow3 = Date943{ today3 };
    tomorrow3.add_day(1);
    cout << today3 << tomorrow3 << '\n';

    Date971 today4 = Date971{ Year{1978},Month::jun,25 };
    Date971 tomorrow4 = Date971{ today4 };
    tomorrow4.add_day(1);
    cout << today4 << tomorrow4 << '\n';
    
    Date974 today5 = Date974{ 1978,Month::jun,25 };
    Date974 tomorrow5 = Date974{ today5 };
    tomorrow5.add_day(1);
    cout << today5 << tomorrow5 << '\n';
}


/*
Review
1. What are the two parts of a class, as described in the chapter?
    Interface and Implementation
2. What is the difference between the interface and the implementation in a class?
    The interface tells how to use a class, what methods it has, the signature of a funciton, the implementation 
    is how the class works internally.
3. What are the limitations and problems of the original Date struct that is created in the
chapter?
    Original date struct can easily be in an invalid state due to access to its data members directly.
    It is inconveninent to use it and always check for errors.
4. Why is a constructor used for the Date type instead of an init_day() function?
    Because the constructor is automatically called whenever a new object is created, thus prohibiting the creation without an initilaization
5. What is an invariant? Give examples.
    A rule that constitutes a valid value is an invariant. In the case of the date a day must be between 1-31. In the case of a for loop
    the looping variable must be smaller than the limiting value.
6. When should functions be put in the class definition, and when should they be defined outside
the class? Why?
    Functions should be placed inside of a class only if we want them to be inlined because of performace adventages in case of small funcitons
7. When should operator overloading be used in a program? Give a list of operators that you
might want to overload (each with a reason).
    When we want the built in operators to operate on our types.
    Havin defined a matrix type A+B, A*B should be matrix addition and multiplication.
8. Why should the public interface to a class be as small as possible?
    To make it easier to understand for your users
9. What does adding const to a member function do?
    A const funciton ensures that the function is not changing the object, thus it can be called on constatnts
10. Why are “helper functions” best placed outside the class definition?
    That way they don't "pollute" the interface, and the interface remains minimal for the ease of use.
*/

/*
Terms
built-in types
    types defined be the langue standard. Int, char, double. These are the tipes where the compiler knows how to place them in memory
class
    A collenction of data members and funciton operating on them. A basic facility that supports user defined types in C++
const
    A keyword when used with variables makes the compiler catch attempts of changing its value, when used with funcitons ensures that the funciotn doesn't
    change the value of the object it's used for.
constructor
    A special memberfunction of a class. It is used to initialize a calss.
destructor
    A special mebmer funciton of a class. It is used automatically when the object goes out of scope.
enum
    A keyword do define enumerations
enumeration
    A user defined type a collction of symbolic constatns
enumerator
    A symbolic constatnt in an enumerator
helper function
    A funciton that operates with a class, but not a part of the interface.
implementation
    The function definitions of a class is the implementation of a class.
in-class initializer
    A way to initialize variables of a a class when nothing else initializes them.
inlining
    A funtion defined in a class interface is az inline function. Inline funcitons are inserted to the place of use when used insted of being called.
interface
    A part of a class declaration the user accesses directly.
invariant
    A rule that constitues a valid state.
representation
    How the object is stored in memory
struct
    A class with public members by default. Used for plain old data.
structure
    The connections between the smaller units of a system is called the structure of a system.
user-defined types
    Not built in types
valid state
    Having a valid value is being in a valid state. 

*/

/*
Excercise 1
1. List sets of plausible operations for the examples of real-world objects in §9.1 (such as
toaster).

    Insert bread.
    Remove bread.
    Start toasting
    Stop toasting
    Plug it in
    Remove plug

Fridge
    
    Open door.
    Close door.
    Adjust temperature.
    Turn it off.
    Turn it on.
    Insert food.
    Remove food.
    Insert shelf.
    Remove shelf.
    Clean.
    Defrost.
*/