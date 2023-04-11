#include "../include/Harl.hpp"
// https://isocpp.org/wiki/faq/pointers-to-members

int main ( void )
{
	std::string input;
	Harl kharlen;

	std::cout << "Options: [ DEBUG | INFO | WARNING | ERROR ] \
	[ Ctrl+D or exit to quit ]" << std::endl;

	std::cin >> input;
	std::transform(input.begin(), input.end(), input.begin(), ::toupper);
	while (input.compare("exit"))
	{
		if (std::cin.eof())
            break;
		kharlen.complain(input);
		input.clear();
		std::cin >> input;
	}
}