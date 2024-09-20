/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:28:56 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/19 15:00:54 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void )
{
    std::cout << "A new array has been created with a maximum capacity of : 0."<< std::endl;
}

Span::Span( const Span& ref )
{
    this->array = ref.array;

    std::cout << "A new array has been created with a maximum capacity of : " << array.capacity() << std::endl;
}

Span::Span( unsigned int size )
{
    array.reserve(size);
    
    std::cout << "A new array has been created with a maximum capacity of : " << size << "."<< std::endl;
}

Span::~Span()
{
    
}

Span& Span::operator=( const Span& rhs )
{
    this->array = rhs.array;
    this->array.shrink_to_fit(); // only assigning a vector to an other saves the same capacity as before, thus we have to shrink it to fit the current size, then, reserve same capacity as right side vector.
    this->array.reserve(rhs.array.capacity());
}

void    Span::addNumber( int num )
{
    if (this->array.capacity() - this->array.size())
        array.push_back(num);
    
    throw std::length_error("No enough space in the array to add a new element!");
}

void    Span::addNumber( std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    unsigned int    available_size = array.capacity() - array.size();
    unsigned int    elements_count = std::distance(start, end);

    if (elements_count > available_size)
        throw std::length_error("Not enough space in the array to add a new elements!");

    while (start != end)
    {
        array.push_back(*start);
        start++;
    }
}

unsigned int    Span::shortestSpan( void )
{
    std::vector<int>::iterator smallest = std::min_element(array.begin(), array.end());

    if (smallest == array.end())
        throw std::range_error("No Span can be found in this array!");

    std::vector<int>::iterator second_smallest = std::min_element(smallest + 1, array.end());

    if ((second_smallest != array.end()) && (*smallest != *second_smallest))
    {
        return (std::distance(smallest, second_smallest));
    }

    throw std::range_error("No Span can be found in this array!");
}

unsigned int    Span::longestSpan( void )
{
    std::vector<int>::iterator smallest = std::min_element(array.begin(), array.end());
    std::vector<int>::iterator bigest = std::max_element(array.begin(), array.end());

    if ((smallest != bigest) && (*smallest != *bigest)) // we first have to check if the iterators are different to avoid dereferencing in case they hold the address of the element past the last one.
    {
        return (std::distance(smallest, bigest));
    }

    throw std::range_error("No Span can be found in this array!");
}