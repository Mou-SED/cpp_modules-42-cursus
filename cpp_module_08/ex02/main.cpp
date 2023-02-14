/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:58:35 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/14 15:38:10 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main( void )
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl << "------------------------" << std::endl << std::endl;

	std::list< int > mlist;

	mlist.push_back(5);
	mlist.push_back(17);

	std::cout << mlist.back() << std::endl;

	mlist.pop_back();

	std::cout << mlist.size() << std::endl;

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);

	std::list<int>::iterator itL = mlist.begin();
	std::list<int>::iterator iteL = mlist.end();

	++itL;
	--itL;
	while (itL != iteL)
	{
		std::cout << *itL << std::endl;
		++itL;
	}
	std::list<int> l(mlist);

	return 0;
}