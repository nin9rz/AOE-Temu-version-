/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:30:02 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/05 17:39:45 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

int	main(int argc, char **argv)
{
	int x = std::atoi(argv[1]);
	int y = std::atoi(argv[2]);
	int	min = std::atoi(argv[3]);
	int	max = std::atoi(argv[4]);

	std::ofstream ost;
	std::srand(std::time(NULL));
	ost.open(argv[5], std::ofstream::out | std::ofstream::trunc);
	if (ost.fail() || min > max)
		return (1);
	for (int i = 0; i < y; ++i)
	{
		for (int ii = 0; ii < x; ++ii)
			ost << ((std::rand() % (max - min + 1)) + min);
		ost << std::endl;
	}
	ost.close();
}