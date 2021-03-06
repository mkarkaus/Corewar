/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:40:48 by mkarkaus          #+#    #+#             */
/*   Updated: 2021/04/10 14:05:54 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	print_usage()
{
	ft_printf("{cyan}Usage: ./corewar [filename].cor{r}\n");
}

int		main(int argc, char **argv)
{
	t_player	players;
	int			i;

	i = 0;
	
	if (argc > 1)
	{
		while (++i < argc)
			get_player_code(argv[i], &players);
	}
	else
		print_usage();
	return (0);
}
