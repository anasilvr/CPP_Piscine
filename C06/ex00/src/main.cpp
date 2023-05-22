/*
TODO:
[] takes as parameter a string representation of a C++ literal in its most
common form:
        [] char (ex.: ’c’, ’a’, ...)
        [] int (ex.: 0, -42, 42...)
        [] float (ex.:0.0f, -4.2f, 4.2f... and -inff, +inff, nanf)
        [] double (ex.: 0.0, -4.2, 4.2... and -inf, +inf and nan) (decimal
notation)

[] detect the type of the literal passed as parameter
[] convert it from string to its actual type
[] convert it explicitly to the three other data types
[] display the results as shown below

---[] EXCEPTIONS ?
        [x] non displayable characters shouldn’t be used as inputs (char: Non
displayable)
        [x] does not make any sense or overflows ([type]: impossible)

PDF:
        ./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

        ./convert nan
char: impossible
int: impossible
float: nanf
double: nan

        ./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
7

*/

#include "../include/Converter.hpp"

int main(int ac, char **av) {
    if (ac == 2) {
		try {
	        Converter arg(av[1]);
			cout << arg;
		}
	    catch (std::exception &e) {
			ERR_MSG;
		}
		return (0);
    }
	else {
		cout << RED;
		cout << "Error: Invalid number of arguments.\nUsage: ./convert [argument]";
		cout << NC << endl;
		return (-1);
	}
}