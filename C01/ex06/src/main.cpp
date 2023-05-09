#include "../include/Harl.hpp"
// https://isocpp.org/wiki/faq/pointers-to-members

int main ( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cout << "YOU HAVE TO COMPLAIN ABOUT SOMETHING!\n\
		\n\tEx.: ./HarlFilter [OPTION]\
		\nOptions: [ DEBUG | INFO | WARNING | ERROR ]" << std::endl;
		return (-1);
	}

	Harl kharlen;
	std::string options[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	
	std::string complaint;
	std::string input = argv[1];

	std::transform(input.begin(), input.end(), input.begin(), ::toupper);

	int i = 0;
	while (i < 4 && options[i] != input)
		i++;
	switch(i)
	{
		case 0:
			kharlen.complain("DEBUG");
		case 1:
			kharlen.complain("INFO");
		case 2:
			kharlen.complain("WARNING");
		case 3:
			kharlen.complain("ERROR");
			break;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}