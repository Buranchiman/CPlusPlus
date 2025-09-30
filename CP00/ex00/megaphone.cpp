/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivallee <wivallee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:47:40 by wivallee          #+#    #+#             */
/*   Updated: 2025/09/19 12:49:58 by wivallee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	str_to_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - ('a' - 'A');
		i++;
	}
}

int	main(int argc, char **argv)
{

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for(int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		for (std::string::size_type j = 0; j < arg.length(); j++)
		{
			arg[j] = std::toupper(static_cast<unsigned char>(arg[j]));
		}
		std::cout << arg;
	}
	std::cout << '\n';
	return (0);
}
