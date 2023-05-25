#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <unistd.h>

int main () {
	Base *test1 = generate();
	Base &ref1 = *test1;

//	std::cout << "\ntest at: " << test1 << std::endl;
//	std::cout << "ref at: " << &ref1 << std::endl;
	
	identify(test1);
	identify(ref1);

	delete test1;
}