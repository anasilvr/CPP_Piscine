#include "../include/Harl.hpp"
// https://isocpp.org/wiki/faq/pointers-to-members

static int id_complaint(std::string arg)
{
	std::transform(arg.begin(), arg.end(), arg.begin(), ::toupper);
	if (arg.compare("DEBUG") == 0)
		return (1);
	else if (arg.compare("INFO") == 0)
		return (2);
	if (arg.compare("WARNING") == 0)
		return (3);
	if (arg.compare("ERROR") == 0)
		return (4);
	else
		return (0);
}

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
	
	switch(id_complaint(argv[1]))
	{
		case 1:
			kharlen.complain("DEBUG");
		case 2:
			kharlen.complain("INFO");
		case 3:
			kharlen.complain("WARNING");
		case 4:
			kharlen.complain("ERROR");
			break;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}