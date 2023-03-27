#include "Account.hpp"
#include <iostream>

Account::Account( int initial_deposit )
	: _accountIndex (_nbAccounts), _amount (initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
		_nbAccounts++;
		_totalAmount += _amount;
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex;
		std::cout << ";amount:" << this->_amount;
		std::cout << ";created" << std::endl;
}


Account::~Account( void ){
		_displayTimestamp();

		std::cout << "index:" << this->_accountIndex;
		std::cout << ";amount:" << this->_amount;
		std::cout << ";closed" << std::endl;
}


int	Account::getNbAccounts( void ){ return (_nbAccounts); }
int	Account::getTotalAmount( void ){ return (_totalAmount); }
int	Account::getNbDeposits( void ){ return (_totalNbDeposits); }
int	Account::getNbWithdrawals( void ){ return (_totalNbWithdrawals); }

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;	
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:" << "refused" << std::endl;
		return false;
	}
	else
	{
		std::cout << ";withdrawal:" << withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		this->_amount -= withdrawal;
	}
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
	return true;
}
int		Account::checkAmount( void ) const{
	return 1;
}
void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

void	Account::_displayTimestamp( void ){
	std::time_t	ref;
	std::tm *time;
	char buffer[16] = {0};

	std::time(&ref);
	time = std::localtime(&ref);

	std::strftime(buffer, 16, "%Y%m%d_%H%M%S",time);
	std::cout << "[" << buffer << "] " << std::flush;
}

// void	Account::_displayTimestamp( void ){
// 	std::cout << "[19920104_091532] " << std::flush;
// }

/*
	The hard coded timestamp is to be used to help correction by allowing you to
	redirect the output of the program to a text file and do a diff against the
	log provided by 42.
	
		$> ./Account > output.txt
		$> diff 19920104_091532.log.txt output.txt

*/

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;