#include "../include/sed.hpp"


static int errMsg(int err, bool quit)
{
	switch (err)
		case 1:
		std::cout << "Error: Invalid number of arguments.\n Ex.: ./sed \"filetoreplace.txt\" \"stringtoreplace\" \"newstring\"" << std::endl;
	if (quit)
		std::exit(-1);
	return (0);
}

int main( int argc, char **argv )
{
	(void)argv;
	if ( argc != 4)
		return (errMsg(1, 1));
}