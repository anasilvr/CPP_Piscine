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

int main( int argc, char **argv )
{
	if (argc != 4)
		return (errMsg("error: invalid number of arguments.\n", "usage: ./sed [filename] [word_to_search] [replacing_word]"));

	std::ifstream	ifile (argv[1]);

	if (!ifile.good())
		return (errMsg("error: could not open file ", argv[1]));
	else
	{
		std::string			name(argv[1]);
		std::string			wtarget(argv[2]);
		std::string			wreplace(argv[3]);
		std::string			line;
		std::stringstream	buffer;
		std::size_t			pos = 0;

		std::ofstream		ofile(name.append(".replace").data());

		while (ifile.good() && ofile.good())
		{
			std::getline(ifile, line);
			pos = line.find(wtarget, 0);
			while (pos != std::string::npos)
			{
				line.erase(pos, wtarget.length());
				line.insert(pos, wreplace);
				pos += wreplace.length();
				pos = line.find(wtarget, pos);
			}
			ofile << line;
			if (ifile.eof())
				break ;
			ofile << std::endl;
		}
		ifile.close();
		ofile.close();
	}
}


