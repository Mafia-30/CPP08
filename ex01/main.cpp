/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:01:43 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/20 10:04:23 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


    /* This main has nothing to do with the exercice! */

int main()
{
    std::vector<int> v;

    v.reserve(10);

    for (int i = 0; i < 5; i++)
        v.push_back(i);

    for (std::vector<int>::iterator i= v.begin(); i < v.end(); i++)
        std::cout << *i << " " ;

    std::cout << std::endl;
    std::cout << v.capacity() << std::endl;

    std::vector<int> a;

    a.reserve(50);
    
    for (int i = 0; i < 50; i++)
        a.push_back(i + 50);


    std::cout << a.capacity() << std::endl;
    // a.clear();
    a = v;
    a.shrink_to_fit();
    a.reserve(v.capacity());
    a.push_back(88);

    for (auto it : a)
        std::cout << it << std::endl;
    std::cout << a.capacity() << std::endl;
    std::cout << a.size() << std::endl;

}