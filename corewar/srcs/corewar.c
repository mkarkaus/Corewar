/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:40:48 by mkarkaus          #+#    #+#             */
/*   Updated: 2021/04/12 15:50:56 by mkarkaus         ###   ########.fr       */
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

int			main(int ac, char **av)
{
	t_corewar	cw;
	t_player	players;

	// cw = (t_corewar *)ft_memalloc(sizeof(t_corewar));
	if (ac > 1)
	{
		while (--ac > 0)
		{
			av++;
			ft_printf("1 %s\n", *av);
			if (is_filename(*av))
				get_player_code(*av, &players);
			else if (*av[0] == '-')
			{
				ac -= set_flag(&av, &players, &cw, (ac == 1));
				ft_printf("av:%d\n", cw.nflag);
			}
			else
				print_usage();
			ft_printf("2 %s\n", *av + 1);
		}
	}
	else
		print_usage();
	return (0);
}
