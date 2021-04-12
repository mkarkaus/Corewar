/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:39:43 by mkarkaus          #+#    #+#             */
/*   Updated: 2021/04/12 15:50:58 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	'int not_last' indicates if the flag is the last argument in av.
*/

void	check_flag_arg(t_corewar *cw, char **av, int is_last)
{
	if (!is_last && (av + 1) && ft_onlydigits(*(av + 1)))
	{
		if (**av == 'n' && (ft_atoi(*(av + 1)) < 1 || ft_atoi(*(av + 1)) > 4))
			ft_exit("Error: Player number has to be between 1 and 4.\n");
		else if (ft_strequ(*av, "dump") && ft_atoi(*(av + 1)) < 0)
			ft_exit("Error: 'dump'-flags argument can't be negative.\n");
	}
	else
		ft_exit("Error: Flags argument should be a positive integer.\n");
}

int		set_flag(char ***av, t_player *player, t_corewar *cw, int is_last)
{
	(**av)++;
	if (ft_strequ(**av, "n") || ft_strequ(**av, "dump"))
	{
		check_flag_arg(cw, *av, is_last);
		if (ft_strequ(**av, "n"))
			cw->nflag = ft_atoi(*(*av + 1));
		else if (ft_strequ(**av, "dump"))
			cw->dflag = ft_atoi(*(*av + 1));
		(*av)++;
		return (1);
	}
	else if (ft_strequ(**av, "v"))
		cw->vflag = 1;
	else
		ft_exit("Error: Invalid flag.\n");
	return (0);
}
