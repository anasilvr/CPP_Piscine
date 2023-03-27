#include <iostream>
#include <string>

int main ( void )
{
	std::string salut = "HI THIS IS BRAIN";
	std::string* stringPTR = &salut;
	std::string& stringREF = salut;

	std::cout << "[salut]     Address:\t" << &salut << std::endl;
	std::cout << "[stringPRT] Address:\t" << stringPTR << std::endl;
	std::cout << "[stringREF] Address:\t" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "[salut]     Value:\t" << salut << std::endl;
	std::cout << "[stringPRT] Value:\t" << *stringPTR << std::endl;
	std::cout << "[stringREF] Value:\t" << stringREF << std::endl;
}