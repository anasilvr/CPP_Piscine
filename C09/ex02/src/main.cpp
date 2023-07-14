/*
TODO:

You must create a program with these constraints:
	[x] The name of the program is PmergeMe.
	[ ] Your program must be able to use a positive integer sequence as argument.
	[ ] Your program must use a merge-insert sort algorithm to sort the positive integer
sequence.
	[ ] If an error occurs during program execution, an error message should be displayed
on the standard output.
	[ ] You must use at least two different containers in your code to
validate this exercise.
	[ ] Your program must be able to handle at least 3000 different integers.

It is strongly advised to implement your algorithm for each container
and thus to avoid using a generic function.

Output Guideline:

	[ ] On the first line you must display an explicit text followed by the unsorted positive
integer sequence.
	[ ] On the second line you must display an explicit text followed by the sorted positive
integer sequence.
	[ ] On the third line you must display an explicit text indicating the time used by
your algorithm by specifying the first container used to sort the positive integer
sequence.
	[ ] On the last line you must display an explicit text indicating the time used by
your algorithm by specifying the second container used to sort the positive integer
sequence.

Ex.:

$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us

$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us

$> ./PmergeMe "-1" "2"
Error

*/

#include "../include/PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac == 1)
		cout << "caca" << endl;
	else
		cout << av[0] << endl;
}