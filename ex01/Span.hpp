/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:18:46 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/19 14:27:57 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>

class Span {

    public :
        Span( void );
        Span( const Span& ref );
        Span( unsigned int size );
        
        ~Span();
        
        Span& operator=( const Span& rhs );

        void            addNumber( int num );
        void            addNumber( std::vector<int>::iterator start, std::vector<int>::iterator end); // this interval must be left-closed, right-open interval : [ ... [
        unsigned int    shortestSpan( void );
        unsigned int    longestSpan( void );

    private :
        std::vector<int> array;
};



#endif