/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:02:24 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/24 12:40:30 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

#include <iostream>

Brain::Brain()
{
  std::cout << "Brain's constructor called" << std::endl;
  ideas[0] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	ideas[1] = "Etiam venenatis lacus in ex condimentum, et suscipit nisl maximus.";
	ideas[2] = "Vestibulum faucibus tortor ultricies neque ullamcorper, sed malesuada diam euismod.";
	ideas[3] = "Vestibulum fermentum enim posuere magna mollis, nec convallis tellus dignissim.";
	ideas[4] = "Suspendisse ut mauris semper, tincidunt enim a, condimentum odio.";
	ideas[5] = "Vestibulum non lectus et arcu posuere auctor.";
	ideas[6] = "Aliquam ac orci ac turpis egestas maximus.";
	ideas[7] = "Vestibulum at nisl a erat iaculis aliquam non nec nisi.";
	ideas[8] = "Quisque ac purus in metus mattis iaculis.";
	ideas[9] = "Proin vestibulum est molestie eros semper suscipit.";
	ideas[10] = "Cras iaculis nunc id sem blandit porttitor.";
	ideas[11] = "Nam iaculis est ac bibendum tempus.";
	ideas[12] = "Integer varius ipsum vel ullamcorper luctus.";
	ideas[13] = "Sed molestie sem non lobortis vestibulum.";
	ideas[14] = "Phasellus eget dui dictum, hendrerit tellus et, pellentesque urna.";
	ideas[15] = "Nulla hendrerit lorem non lacus scelerisque viverra.";
	ideas[16] = "Proin iaculis dui non erat venenatis efficitur.";
	ideas[17] = "Proin sollicitudin metus non diam viverra ullamcorper.";
	ideas[18] = "Pellentesque consequat leo a odio facilisis vestibulum.";
	ideas[19] = "Sed efficitur ex ac massa molestie, eu fringilla elit fringilla.";
	ideas[20] = "Donec suscipit arcu non erat ullamcorper porta.";
	ideas[21] = "Quisque eu eros at tellus ullamcorper congue.";
	ideas[22] = "Nulla at tellus ac mauris aliquam varius.";
	ideas[23] = "Donec at felis imperdiet, lobortis risus eu, ultrices est.";
	ideas[24] = "Nam nec lorem in mi pulvinar porttitor.";
	ideas[25] = "Morbi at odio auctor, iaculis nibh at, imperdiet dolor.";
	ideas[26] = "Donec ut tortor molestie, auctor lorem et, faucibus dolor.";
	ideas[27] = "Morbi id justo sodales, blandit sem a, tincidunt mauris.";
	ideas[28] = "Proin egestas tellus quis arcu mollis, vitae porttitor metus elementum.";
	ideas[29] = "Cras eu magna eget sapien finibus efficitur in ac lacus.";
	ideas[30] = "Vestibulum sed metus tempus, fermentum lacus fringilla, facilisis arcu.";
	ideas[31] = "Quisque cursus lacus ut odio interdum, id placerat lacus pellentesque.";
	ideas[32] = "Maecenas a sapien facilisis, mattis nibh ac, accumsan erat.";
	ideas[33] = "Nunc vulputate enim et nisi ullamcorper, et hendrerit lorem luctus.";
	ideas[34] = "Nulla et augue id leo finibus ornare quis in diam.";
	ideas[35] = "Sed consequat elit volutpat magna dignissim, vel auctor nulla semper.";
	ideas[36] = "Nulla id erat laoreet, accumsan tortor sit amet, venenatis ante.";
	ideas[37] = "In tempus orci et nibh scelerisque, et bibendum orci suscipit.";
	ideas[38] = "Morbi quis nisl vel nibh gravida maximus nec nec sem.";
	ideas[39] = "Ut finibus orci sed ante tempus, ac efficitur massa tincidunt.";
	ideas[40] = "In mattis sapien at viverra tempus.";
	ideas[41] = "Donec sit amet arcu aliquam, sodales turpis id, dictum mauris.";
	ideas[42] = "Nulla aliquam orci in aliquet bibendum.";
	ideas[43] = "Etiam consectetur leo in nunc fermentum interdum.";
	ideas[44] = "Donec vel neque porttitor diam viverra venenatis eu a purus.";
	ideas[45] = "Curabitur sollicitudin ex euismod, fringilla libero vehicula, convallis nisi.";
	ideas[46] = "Cras at justo finibus, elementum sapien a, ultricies enim.";
	ideas[47] = "Integer varius velit eu dolor malesuada tempus.";
	ideas[48] = "Quisque dictum dolor id turpis volutpat posuere.";
	ideas[49] = "Integer blandit turpis sit amet turpis ultrices placerat.";
	ideas[50] = "Nullam et dolor eu risus sollicitudin mollis non cursus risus.";
	ideas[51] = "Pellentesque et lorem condimentum, maximus tortor sed, volutpat lectus.";
	ideas[52] = "Praesent luctus odio at dui euismod, et accumsan sapien ullamcorper.";
	ideas[53] = "Morbi sit amet metus id enim ultricies congue.";
	ideas[54] = "Quisque at diam porttitor, varius orci eu, aliquam nisi.";
	ideas[55] = "In at nulla id velit semper blandit.";
	ideas[56] = "Quisque dignissim lacus ut massa porta iaculis.";
	ideas[57] = "Nulla tempor arcu ut leo imperdiet tincidunt.";
	ideas[58] = "Nunc eget tellus id tellus finibus eleifend a sit amet tortor.";
	ideas[59] = "Curabitur fringilla ipsum sed lacus vehicula, at pharetra neque maximus.";
	ideas[60] = "Nulla facilisis sem nec leo porttitor sodales.";
	ideas[61] = "Cras consequat diam et urna convallis gravida id vel sem.";
	ideas[62] = "Mauris in nulla sed sem blandit egestas sit amet eget quam.";
	ideas[63] = "Quisque pharetra mauris non nibh mattis ornare.";
	ideas[64] = "Donec placerat erat at fringilla egestas.";
	ideas[65] = "Quisque facilisis erat vel tempus feugiat.";
	ideas[66] = "Mauris imperdiet sem quis posuere commodo.";
	ideas[67] = "Nunc dignissim purus maximus sem vehicula commodo.";
	ideas[68] = "Curabitur varius magna id ornare venenatis.";
	ideas[69] = "Donec eget sapien ac ligula pretium mattis.";
	ideas[70] = "Nunc sagittis elit finibus nisl hendrerit, ornare ullamcorper sapien imperdiet.";
	ideas[71] = "Vivamus in orci a est volutpat tempus.";
	ideas[72] = "Nam lacinia lectus ut aliquet rhoncus.";
	ideas[73] = "Nullam fringilla nisl sed risus iaculis, eu vulputate urna porttitor.";
	ideas[74] = "Donec eu tellus rhoncus, pellentesque augue non, pulvinar enim.";
	ideas[75] = "Proin eget ipsum sed odio gravida molestie vel eget massa.";
	ideas[76] = "Ut vel eros quis mi sagittis faucibus.";
	ideas[77] = "Morbi posuere risus sed felis ornare, a tincidunt ligula cursus.";
	ideas[78] = "Aenean in magna finibus lacus lacinia commodo.";
	ideas[79] = "Donec non diam vitae neque tristique scelerisque.";
	ideas[80] = "Morbi sit amet elit vitae est pretium tempus at ut metus.";
	ideas[81] = "Nulla venenatis arcu at eros hendrerit, et malesuada diam laoreet.";
	ideas[82] = "Proin luctus ante vel massa facilisis scelerisque.";
	ideas[83] = "Fusce semper lorem et auctor accumsan.";
	ideas[84] = "Nunc ut sapien id leo elementum mollis.";
	ideas[85] = "Pellentesque laoreet quam non auctor tincidunt.";
	ideas[86] = "Morbi sollicitudin justo vitae ligula scelerisque commodo.";
	ideas[87] = "Integer fermentum mauris nec eros viverra, vitae bibendum libero suscipit.";
	ideas[88] = "Morbi nec mi euismod, cursus ipsum nec, blandit ante.";
	ideas[89] = "In bibendum ante at diam interdum interdum.";
	ideas[90] = "Praesent tempor dui eget magna malesuada molestie.";
	ideas[91] = "Integer in mi at mauris bibendum mollis non vitae nisl.";
	ideas[92] = "Vivamus elementum dolor eu nisi tempor vehicula.";
	ideas[93] = "Nulla tincidunt magna quis porttitor mollis.";
	ideas[94] = "Donec pretium turpis sed erat luctus vulputate.";
	ideas[95] = "Vivamus vehicula elit a velit pulvinar porttitor.";
	ideas[96] = "Duis quis elit ac velit tempor maximus ac ultricies mi.";
	ideas[97] = "Vivamus non nunc ultrices, lobortis felis mollis, luctus magna.";
	ideas[98] = "Praesent in est non tellus vestibulum tempor.";
	ideas[99] = "Duis eget ipsum luctus, tempor diam in, aliquam orci.";
} 
 
Brain &Brain::operator=(const Brain &other)
{ 
  std::cout << "Brain's Copy assignment operator called" << std::endl;
  for (int i = 0; i < 100; i++) {
    this->ideas[i] = other.ideas[i];
  }
  return (*this);
} 
 
Brain::Brain(const Brain &other)
{ 
  std::cout << "Brain's copy constructor operator called" << std::endl;
 
  *this = other;
}

Brain::~Brain() { std::cout << "Brain's default destructor called" << std::endl; }

void Brain::setIdea(int index, const std::string& idea)
{
  if (index >= 0 && index < 100)
    ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
  if (index >= 0 && index < 100)
    return ideas[index];
  return "";
}
