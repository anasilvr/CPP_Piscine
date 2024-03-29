/*
TODO:

You must create a program with these constraints:
	[x] The program name is RPN.
	[x] Your program must take an RPN expression as an argument.
	[x] The numbers used in this operation and passed as arguments will always be less
		than 10. The calculation itself but also the result do not take into account this rule.
	[x] Your program must process this expression and output the correct result on the
		standard output.
	[x] If an error occurs during the execution of the program an error message should be
		displayed on the STDOUT.
	[x] Your program must be able to handle operations with these tokens: "+ - / *".


In reverse Polish notation, the operators follow their operands.

(3 × 4) + (5 × 6)
	becomes
3 4 × 5 6 × + 
*/

#include "../include/RPN.hpp"

int main(int ac, char **av) {
	if (ac == 2) {
		RPN input(av[1]);
		return (EXIT_SUCCESS);
	}
	cerr << RED "Invalid number of arguments.\nUsage: ./RPN \"1 1 +\"" NC << endl;
	return (EXIT_FAILURE);
}