/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:25:06 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/19 12:21:53 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

#include <algorithm>
#include <iostream>
#include <iterator>

template <typename T>
void easyfind(T container, int to_find)
{
    typename T::iterator it = container.begin();

    it = std::find(container.begin(), container.end(), to_find);

    if (it == container.end())
        throw (std::out_of_range("This number has not been found in the given container!"));

    std::cout << "The first occurence of the number " << to_find << " in the given container is at position : " << std::distance(container.begin(), it) + 1 << std::endl;

}

#endif