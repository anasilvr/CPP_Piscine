#include "../include/iter.hpp"

int main (void) {
	int arr[5] = {1, 2, 3, 4, 5};
	std::string phrase[5] = {"hi", "this", "is", "a", "test"};
	float glub[10] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};

	std::cout << "Starting iter with int array being sent to print function:" << std::endl;
	iter(arr, 5, print);
	std::cout << "\nStarting iter with string array being sent to print function:" << std::endl;
	iter(phrase, 5, print);
	std::cout << "\nStarting iter with float array being sent to print function:" << std::endl;
	iter(glub, 10, print);
}