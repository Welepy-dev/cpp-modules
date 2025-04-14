/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:01:08 by welepy            #+#    #+#             */
/*   Updated: 2025/04/14 16:28:22 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Account.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() {}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_displayTimestamp();
	std::cout	
				<< "index:"		<< _accountIndex 
				<< ";amount:"	<< _amount
				<< ";created"	<<
	std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (withdrawal < _amount)
	{
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout
					<< "index:"				<< _accountIndex
					<< ";p_amount:"			<< _amount + withdrawal
					<< ";withdrawal:"		<< withdrawal
					<< ";amount:"			<< _amount
					<< ";nb_withdrawals:"	<< _nbWithdrawals <<
		std::endl;
		return (true);
	}
	else
	{
		std::cout
					<< "index:"			<< _accountIndex
					<< ";p_amount:"		<< _amount
					<< ";withdrawal:"	<< "refused" <<
					
		std::endl;
		return (false);
	}
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
				<< "index:"			<< _accountIndex
				<< ";amount:"		<< _amount
				<< ";deposits:"		<< _nbDeposits
				<< ";withdrawals:"	<< _nbWithdrawals <<
	std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_totalAmount += deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout
				<< "index:"			<< _accountIndex
				<< ";p_amount:"		<< _amount - deposit
				<< ";deposit:"		<< deposit
				<< ";amount:"		<< _amount
				<< ";nb_deposits:"	<< _nbDeposits <<
	std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t t = std::time(NULL);
	std::tm* now = std::localtime(&t);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", now);

	std::cout << buffer;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
				<< "accounts:"		<< getNbAccounts()
				<< ";total:"		<< getTotalAmount()
				<< ";deposits:"		<< getNbDeposits()
				<< ";withdrawals:"	<< getNbWithdrawals() <<
	std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout
				<< "index:" 		<< _accountIndex
				<< ";amount:"		<< _amount
				<< ";closed" <<
	std::endl;
}
