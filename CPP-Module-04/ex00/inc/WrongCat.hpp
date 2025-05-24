/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:47:39 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/23 14:21:02 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class WrongCat : public Animal
{
  public:
    WrongCat();
    WrongCat(std::string type);
    WrongCat(const WrongCat &other);
    WrongCat &operator=(const WrongCat &other);
    virtual ~WrongCat();

    void makeSound(void) const;
  
  private:
    
};

#endif
