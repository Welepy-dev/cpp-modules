/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:47:39 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/24 12:01:45 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
  public:
    Cat();
    Cat(std::string type);
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    virtual ~Cat();

    virtual void makeSound(void) const;
    void setIdea(int index, const std::string& ideas);
    std::string getIdea(int index) const;
  
  private:
    Brain *brain;
};

#endif
