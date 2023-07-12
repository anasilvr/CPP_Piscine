
#include "../include/BitcoinExchange.hpp"

// Default constructor
//BitcoinExchange::BitcoinExchange() { return; }

BitcoinExchange::BitcoinExchange(const char *av) {
	try {
		std::ifstream dataFile("data.csv");
		string header;
		std::getline(dataFile, header);
		std::getline(dataFile, _dataBuffer, '\0');
		dataFile.close();
	}
	catch (std::fstream::failure e) {
		cerr << "Error reading files\n";
	}
	parseData();
	generateOutput(av);
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  *this = other;
  return;
}

// Copy assignment overload
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
BitcoinExchange::~BitcoinExchange() { return; }



void BitcoinExchange::errMsg (string msg, string data)
{
        cerr << msg;
        if (!data.empty())
                cerr << data;
        cerr << endl;
}

// void BitcoinExchange::parseInput() {
// 	string buff;
// 	string date;
// 	string value;

// 	size_t pos = 0;
// 	size_t offset = 0;
// 	size_t len = 0;

// 	while ((pos = _inputBuffer.find('\n', offset)) != std::string::npos) {
// 		len = pos - offset; // substring length
// 		buff = _inputBuffer.substr(offset, len);

// 		// Separate date and value
// 		size_t delimiterPos = buff.find(" | ");
// 		if (delimiterPos != string::npos) {
// 			date = buff.substr(0, delimiterPos);
// 			value = buff.substr(delimiterPos + 3);
// 		}
// 		else {
// 			date = buff;
// 			value = "";
// 		}
// 		_inputMap.insert(std::make_pair(date, value));
// 		pos++; // Move to the next character after '\n'
// 		offset = pos; // Update the offset
// 	}
// }

void BitcoinExchange::parseData() {
	string buff;
	string date;
	string value;
	float rate;

	size_t pos = 0;
	size_t offset = 0;
	size_t len = 0;

	while ((pos = _dataBuffer.find('\n', pos)) != std::string::npos) {
		len = pos - offset; // substring length
		buff = _dataBuffer.substr(offset, len);

		// Separate date and rate
		size_t delimiterPos = buff.find(",");
		if (delimiterPos != string::npos) {
			date = buff.substr(0, delimiterPos);
			rate = stof(buff.substr(delimiterPos + 1));
		}
		else {
			date = buff;
			rate = -1;
		}
		_dataMap.insert(std::make_pair(date, rate));
		pos++; // Move to the next character after '\n'
		offset = pos; // Update the offset
	}
	// _dataMap.erase(prev(_dataMap.end()));
	// for(multimap<string, string>::iterator it = _dataMap.begin(); it != _dataMap.end(); ++it)
	// cout << it->first << " | " << it->second << endl;
}

static bool isDateValid(const std::string& date) {
    std::tm timeStruct = { .tm_year = 0, .tm_mon = 0, .tm_mday = 0, .tm_hour = 0, .tm_min = 0, .tm_sec = 0 };
    std::istringstream iss(date);
    iss >> std::get_time(&timeStruct, "%Y-%m-%d");
    return (!iss.fail());
}

void BitcoinExchange::generateOutput(const char *av) const {
	
	std::ifstream iFile(av);
	string line;
	std::getline(iFile, line);
	while (std::getline(iFile, line)) {// Separate date and value
		string date;
		string value;
		size_t delimiterPos = line.find(" | ");
		if (delimiterPos != string::npos) {
			date = line.substr(0, delimiterPos);
			value = line.substr(delimiterPos + 3);
			if (!isDateValid(date))
				cout << "Error: bad input => " << date << endl;
		}
		else {
			date = line;
			value = "";
		}
		try {
			if (value.size() == 0 || value.length() < 1)
				cout << "Error: bad input => " << date << endl;
			else if (std::stod(value) > 1000)
					cout << "Error: too large a number." << endl;
			else if (std::stod(value) < 0)
					cout << "Error: not a positive number." << endl;
			else {
				for (map<string, float>::const_iterator it = _dataMap.begin(); it != _dataMap.end(); ++it) {
					if (it->first.compare(date) == 0)
						cout << date << " => " << value << " = " << (stof(value) * it->second) << endl;
				}
			}
		}
		catch (const std::exception &e) {
			cout << "Error: Invalid input." << endl;
		}	
	}
}