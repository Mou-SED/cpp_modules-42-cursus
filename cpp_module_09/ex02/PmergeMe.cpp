/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:34:02 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/30 13:31:20 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void )
{
	return ;
}

PmergeMe::PmergeMe( int ac, char **av, size_t size )
{
    this->_ac = ac;
    this->_av = av;
    this->_size = size;

    this->_timeUsedVector = 0.0;
    this->_timeUsedDqueue = 0.0;
    for (int i = 1; i < ac; i++)
    {
        this->_vec.push_back(atoi(av[i]));
        this->_deq.push_back(atoi(av[i]));
    }

    return ;
}

PmergeMe::PmergeMe( PmergeMe const & src )
{
	*this = src;
	return ;
}

PmergeMe::~PmergeMe( void )
{
    _vec.clear();
    _deq.clear();
	return ;
}

PmergeMe & PmergeMe::operator=( PmergeMe const & other )
{
	if (this != &other)
	{
        this->_ac = other._ac;
        this->_av = other._av;
        this->_size = other._size;
        this->_vec = other._vec;
        this->_deq = other._deq;
        this->_timeUsedVector = other._timeUsedVector;
        this->_timeUsedDqueue = other._timeUsedDqueue;
	}
	return *this;
}

void    PmergeMe::runVector( void )
{
    clock_t start, end;
    size_t sizeVec = this->_vec.size();

    start = clock();
    mergeInsertionSort(this->_vec, 0, sizeVec - 1);
    end = clock();
    this->setTimeUsedVector((double)(end - start));

    return ;
}

void    PmergeMe::runDeque( void )
{
    clock_t start, end;
    size_t sizeDeq = this->_deq.size();

    start = clock();
    mergeInsertionSort(this->_deq, 0, sizeDeq - 1);
    end = clock();
    this->setTimeUsedDqueue((double)(end - start));

    return ;
}

void    PmergeMe::printBefore( void ) const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < this->_vec.size(); i++)
        std::cout << this->_vec[i] << " ";
    std::cout << std::endl;

    return ;
}

void    PmergeMe::printAfter( void ) const
{
    std::cout << "After: ";
    for (size_t i = 0; i < this->_vec.size(); i++)
        std::cout << this->_vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _size << " elements with std::vector : "
        << std::fixed << std::setprecision(2) << this->getTimeUsedVector() << " us" << std::endl;
    std::cout << "Time to process a range of " << _size << " elements with std::Deque : "
        << std::fixed << std::setprecision(2) << this->getTimeUsedDqueue() << " us" << std::endl;

    return ;
}

double	PmergeMe::getTimeUsedVector( void ) const
{
	return this->_timeUsedVector;
}

double	PmergeMe::getTimeUsedDqueue( void ) const
{
	return this->_timeUsedDqueue;
}

void	PmergeMe::setTimeUsedVector( double time )
{
	this->_timeUsedVector = time;
}

void	PmergeMe::setTimeUsedDqueue( double time )
{
	this->_timeUsedDqueue = time;
}

// mergeInsertionSort for vector container

void insertionSort( std::vector<int> & arr, int left, int right )
{
    for (int i = left + 1; i <= right; i++)
	{
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
		{
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge( std::vector<int> & arr, int left, int mid, int right )
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
	{
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
	{
        R[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
	{
        if (L[i] <= R[j])
		{
            arr[k++] = L[i++];
        }
        else
		{
            arr[k++] = R[j++];
        }
    }
    while (i < n1)
	{
        arr[k++] = L[i++];
    }
    while (j < n2)
	{
        arr[k++] = R[j++];
    }
}

void mergeInsertionSort( std::vector<int>& arr, int left, int right )
{
    if (left < right)
	{
        int mid = left + (right - left) / 2;
        if (mid - left + 1 <= 16)
            insertionSort(arr, left, mid);
        else
            mergeInsertionSort(arr, left, mid);
        if (right - mid <= 16)
            insertionSort(arr, mid + 1, right);
        else
            mergeInsertionSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// mergeInsertionSort for Deque container

void insertionSort( std::deque<int> & arr, int left, int right )
{
    for (int i = left + 1; i <= right; i++)
	{
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
		{
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge( std::deque<int> & arr, int left, int mid, int right )
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
	{
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
	{
        R[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
	{
        if (L[i] <= R[j])
		{
            arr[k++] = L[i++];
        }
        else
		{
            arr[k++] = R[j++];
        }
    }
    while (i < n1)
	{
        arr[k++] = L[i++];
    }
    while (j < n2)
	{
        arr[k++] = R[j++];
    }
}

void mergeInsertionSort( std::deque<int> & arr, int left, int right )
{
    if (left < right)
	{
        int mid = left + (right - left) / 2;
        if (mid - left + 1 <= 16)
            insertionSort(arr, left, mid);
        else
            mergeInsertionSort(arr, left, mid);
        if (right - mid <= 16)
            insertionSort(arr, mid + 1, right);
        else
            mergeInsertionSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
