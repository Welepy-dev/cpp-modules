/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureucrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:10:19 by marcsilv          #+#    #+#             */
/*   Updated: 2025/06/02 16:52:46 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

# include <string>
# include <iostream>
class Bureucrat 
{
  public:
    Bureucrat(void);
    Bureucrat(std::string name, int grade);
    Bureucrat(const Bureucrat &other);
    Bureucrat &operator=(const Bureucrat &other);
    ~Bureucrat(void);

    std::string getName(void) const;

    int         getGrade(void) const;
    void        setGrade(const int grade);
    
    void        incrementGrade(void);
    void        decrementGrade(void);
  
  private:
    std::string name;
    int               grade;
};

std::ostream& operator<<(std::ostream &out, const Bureucrat &bureucrat);

#endif
