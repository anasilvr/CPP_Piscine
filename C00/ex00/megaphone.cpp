#include <iostream>

int	main(int argc, char **argv)
{
	std::string no_arg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::string outp;
	int len;

	if (argc == 1)
		std::cout << no_arg << std::endl;
	else 
	{
		for(int i = 1; argv[i]; i++)
		{
			outp = argv[i];
			len = outp.length();
	 		for(int j = 0; j < len; j++)
				std::cout << (char)toupper(outp[j]);
		}
		std::cout << std::endl;
	}
	return (0);
}
