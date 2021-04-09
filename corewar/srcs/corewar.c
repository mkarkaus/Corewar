/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:40:48 by mkarkaus          #+#    #+#             */
/*   Updated: 2021/04/09 13:03:25 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	print_usage()
{
	ft_printf("{cyan}Usage: ./corewar [filename].cor{r}\n");
}

int		main(int argc, char **argv)
{
	int		i;

	i = 0;
	
	if (argc > 1)
	{
		while (++i < argc)
			get_player_code(argv[i]);
	}
	else
		print_usage();
	return (0);
}
