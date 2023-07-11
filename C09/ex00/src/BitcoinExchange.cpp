
#include "../include/BitcoinExchange.hpp"

// Default constructor
//BitcoinExchange::BitcoinExchange() { return; }

BitcoinExchange::BitcoinExchange(const char *av) {
	try {
		std::fstream inputFile (av);
		std::fstream dataFile("data.csv");

		std::getline(inputFile, _inputBuffer, '\0');
		inputFile.close();

		std::getline(dataFile, _dataBuffer, '\0');
		dataFile.close();
	}
	catch (std::fstream::failure e) {
		cerr << "Error opening/reading/closing files\n";
	}
	parseInput();
	parseData();
	generateOutput();
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

void BitcoinExchange::parseInput() {
	string buff;
	string date;
	string value;

	size_t pos = 0;
	size_t offset = 0;
	size_t len = 0;

	while ((pos = _inputBuffer.find('\n', offset)) != std::string::npos) {
		len = pos - offset; // substring length
		buff = _inputBuffer.substr(offset, len);

		// Separate date and value
		size_t delimiterPos = buff.find(" | ");
		if (delimiterPos != string::npos) {
			date = buff.substr(0, delimiterPos);
			value = buff.substr(delimiterPos + 3);
		}
		else {
			date = buff;
			value = "";
		}
		_inputMap.insert(std::make_pair(date, value));
		pos++; // Move to the next character after '\n'
		offset = pos; // Update the offset
	}
}

void BitcoinExchange::parseData() {
	string buff;
	string date;
	string rate;

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
			rate = buff.substr(delimiterPos + 1);
		}
		else {
			date = buff;
			rate = "";
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
    return !iss.fail();
}

static bool isValueValid(const std::string& value) {

}

void BitcoinExchange::generateOutput() const {
	for (multimap<string, string>::const_iterator it= _inputMap.begin(); it != _inputMap.end(); ++it)
	{
		string output;
		if (isDateValid(it->first) && isValueValid(it->second))
		{
			multimap<string, string>::const_iterator itData = _dataMap.find(it->first);
			if (itData != _dataMap.end())
			{
				float result = stof(it->second) * stof(itData->second);
				string value = std::to_string(result);
				output = it->first + " => " + it->second + " = " + value;
				cout << output << endl;
			}
		}
		else
			output = "Error: bad input.\n"
    }
}
