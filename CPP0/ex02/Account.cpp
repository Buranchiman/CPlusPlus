#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <cstdio>
#include <string>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account:: _displayTimestamp( void)
{
	char buffer[16];
	std::time_t t = std::time(NULL);
	std::tm *tm_info = std::localtime(&t);

	// Format: YYYYMMDD_HHMMSS
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", tm_info);
	std::cout << '[' << buffer << ']' << ' ';
	//std::cout << "[19920104_091532] ";
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "amount:" << _amount << ";created\n";
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "amount:" << _amount << ";closed\n";
}

int Account::getNbAccounts( void ) { return (_nbAccounts); }
int Account::getTotalAmount( void ) { return (_totalAmount); }
int Account::getNbDeposits( void ) { return (_totalNbDeposits); }
int Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }

void Account:: makeDeposit(int deposit)
{
	if (deposit < 0)
	{
		std::cout << "Cannot deposit a negative amount!\n";
		return ;
	}
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "p_amount:" << _amount << ';'
			  << "deposit:" << deposit << ';'
			  << "amount:" << _amount + deposit << ';'
			  << "nb_deposits:" << _nbDeposits << '\n';
	_amount += deposit;
	_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal < 0)
	{
		std::cout << "Cannot withdraw a negative amount!\n";
		return (false);
	}
	if (withdrawal <= _amount)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
	}
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "p_amount:" << _amount << ';'
			  << "withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused\n";
		return (false);
	}
	else
	{
		std::cout << withdrawal << ';'
				  << "amount:" << _amount - withdrawal << ';'
				  << "nb_withdrawals:" << _nbWithdrawals << '\n';
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
	}
		return (true);
}

int	Account::checkAmount(void) const { return (_amount); }

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "amount:" << _amount << ';'
			  << "deposits:" << _nbDeposits << ';'
			  << "withdrawals:" << _nbWithdrawals << '\n';
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ';'
			  << "total:" << _totalAmount << ';'
			  << "deposits:" << _totalNbDeposits << ';'
			  << "withdrawals:" << _totalNbWithdrawals << '\n';
}
