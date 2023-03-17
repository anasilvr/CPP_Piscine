#include <iostream>
#include "Sample.class.hpp"

int	main(){
	Sample1 test (3.14f);

	std::cout << "Coucou from main! " << std::endl;
	test.sq = 10;
	test.print_att();
	std::cout << "Bye bye!" << std::endl;

	return (0);
}