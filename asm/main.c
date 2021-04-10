/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:09:06 by sreijola          #+#    #+#             */
/*   Updated: 2021/04/10 23:54:32 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

/*
**
**
**
*/

void	print_usage()
{
	ft_printf("{cyan}%s", "Usage: ./asm [-a] < path/champion.s >\n");
	ft_printf("%s{r}", "-a : outputs a stripped and annotated version of the code to the standard output (instead of creating a .cor file)\n");
	exit(-1);
}

int		validate_champion(char *file)
{
	int		len;

	len = ft_strlen(file);
	if (file[len - 2] == '.' && file[len - 1] == 's')
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_list	*champ;
	int		flag;
	int		champ_found;
	int		i;
	
	i = 1;
	flag = 0;
	champ_found = 0;
	while (i < ac)
	{
		ft_printf("%d\n", i);
		if (ac > 1 && ft_strlen(av[i]) == 2 && av[i][1] == 'a')
		{
			flag = 1;
			ft_printf("set flag: %d\n", flag);
		}
		else if (ac > 1 && ft_strlen(av[i]) > 2 && validate_champion(av[i])) //
		{
			get_champion(av[i], &champ);
			// ft_lstprint(champ);
			write_bytecode(av[i], champ, flag);
			champ_found = 1;
		}
		else if (champ_found == 0)
			print_usage();
		i++;
	}
	return (0);
}
