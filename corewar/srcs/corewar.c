/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:40:48 by mkarkaus          #+#    #+#             */
/*   Updated: 2021/04/10 17:47:35 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	print_usage()
{
	ft_printf("{cyan}Usage: ./corewar [-dump nbr_cycles] [[-n number] \
champion1.cor] ...{r}\n");
	exit(-1);
}

int		is_filename(char *arg)
{
	int		len;

	len = ft_strlen(arg);
	if (len > 4)
		return(ft_strnequ(arg + (len - 4), ".cor", ft_strlen(".cor")));
	return (0);
}

int		main(int argc, char **argv)
{
	t_player	players;
	int			i;

	i = 0;
	
	if (argc > 1)
	{
		while (++i < argc)
		{
			if (is_filename(argv[i]))
				get_player_code(argv[i], &players);
			// Here could be int that '-n'-flag sets as the int value and puts
			// it for the next champ it finds from argv
			else if (argv[i][0] == '-')
				set_flag(argv + i, &players);
			else
				print_usage();
		}
	}
	else
		print_usage();
	return (0);
}
