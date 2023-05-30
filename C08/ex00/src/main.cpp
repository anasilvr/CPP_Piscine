#include "../include/easyfind.hpp"

#include <iostream>
#include <vector>


int main(void)
{
	
    std::vector<int> v1;
	std::cout << "v1 initial stats" << std::endl;
	std::cout << "\tv1 size: " << v1.size() << std::endl;
	std::cout << "\tv1 content: ";
	for (unsigned long i = 0; i < v1.size(); i++)
        std::cout << v1.at(i) << " ";

	std::cout << "\n\nAdding 5 numbers with v1.push_back()" << std::endl;

    for (int i = 0; i < 5; i++)
        v1.push_back(i);

	std::cout << "\tv1 size: " << v1.size() << std::endl;
	std::cout << "\tv1 content: ";
	for (unsigned long i = 0; i < v1.size(); i++)
        std::cout << v1.at(i) << " ";

	std::cout << "\n\nTrying to find elements:" << std::endl;

	try { //valid element to be found [TEST 1]
		std::vector<int>::iterator it = easyfind(v1, 1);
		std::cout << "\t[TEST 1] Found it! [" << *it << "]" << std::endl;
	}
    catch (std::exception &e) {
        std::cerr << "\t" << e.what() << std::endl;
    }

	try { //invalid element to be found [TEST 2]
		std::vector<int>::iterator it = easyfind(v1, 10);
		std::cout << "\t[TEST 2]Found it! [" << *it << "]" << std::endl;
	}
    catch (std::exception &e) {
        std::cerr << "\t" << e.what() << std::endl;
    }

	v1.push_back(10);

	try { //valid element to be found after insertion [TEST 3]
		std::vector<int>::iterator it = easyfind(v1, 10);
		std::cout << "\t[TEST 3] Found it [" << *it << "]" << std::endl;
	}
    catch (std::exception &e) {
        std::cerr << "\t" << e.what() << std::endl;
    }

	std::cout << "\nv1 final stats";
	std::cout << "\n\tv1 size: " << v1.size() << std::endl;
	std::cout << "\tv1 content: ";
	for (unsigned long i = 0; i < v1.size(); i++)
        std::cout << v1.at(i) << " ";
	std::cout << std::endl;

}