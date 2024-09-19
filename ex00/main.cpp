/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:33:21 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/19 12:21:18 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <set>

int main()
{
    std::set<int> s;
    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(55);
    v.push_back(99);
    v.push_back(1);

    try
    {
        easyfind(v, 1);
        easyfind(v, 100);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        

    for (int i = 0; i < 10; i++)
    {
        s.insert(i + 1);
    }

    try
    {
        easyfind(s, 5);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
