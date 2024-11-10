/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C00_Learning.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:05:29 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/08 15:07:29 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
//#include <vector>

//int	main ()
//{
//	std::vector<int> numbers = {1, 2, 3, 4, 5};
//	std::vector<int>::iterator it;

//	for (it = numbers.begin(); it != numbers.end(); ++it)
//		std::cout << *it << " ";
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>

class Account
{
	public:
		Account(int balance) : _balance(balance) {}

		void displayStatus() const
		{
			std::cout << "Balance: " << _balance << std::endl;
		}

		void makeDeposit(int amount)
		{
			_balance += amount;
		}

		void makeWithdrawal(int amount)
		{
			_balance -= amount;
		}
	private:
		int _balance;
};

int	main()
{
	std::vector<Account> accounts = {Account(100), Account(200), Account(300)};
	
	std::cout << "Initial account statues:" << std::endl;
	std::for_each(accounts.begin(), accounts.end(), [](Account& acc) {acc.displayStatus();});
	
	std:for_each(accounts.begin(), accounts.end(), [](Account& acc) {acc.makeDeposit(50); });
	
	std::cout << "\nAccount statues after deposit:" << std::endl;
	std::for_each(accounts.begin(), accounts.end(), [] (Account& acc) {acc.displayStatus(); });
	//Lambda function

	return 0;


}
