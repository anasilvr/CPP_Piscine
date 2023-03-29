#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

static int errMsg (std::string msg, std::string data)
{
	std::cout << msg;
	if (!data.empty())
		std::cout << data;
	std::cout << std::endl;
	return (-1);
}

// static void word_replace (std::string *target, size_t len, std::string word)
// {
// 	(void)word;
// 	std::cout << "len: "<< len << std::endl;
// 	std::cout << *target << std::endl;
		
// }

int main( int argc, char **argv )
{
	if (argc != 4)
		return (errMsg("error: invalid number of arguments.\n", "usage: ./sed [filename] [word_to_search] [replacing_word]"));

	std::ifstream	ifile (argv[1]);
	std::string		name(argv[1]);
	std::string		wtarget(argv[2]);
	std::string		wreplace(argv[3]);

	name += ".replace";

	if (!ifile.good())
		return (errMsg("error: could not open file ", argv[1]));
	else
	{
		std::ofstream ofile(name);
		std::string line;
		while (std::getline(ifile, line))
		{
			std::size_t pos = 0;
			while (pos < line.length())
			{
				pos = line.find(wtarget, pos);
				if (pos == std::string::npos)
					break ;
				line.erase(pos, line.length());
				line.insert(pos, wreplace);
			}
			ofile << line << std::endl;
		}
	}
}


