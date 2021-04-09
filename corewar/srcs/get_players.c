/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:05:57 by mkarkaus          #+#    #+#             */
/*   Updated: 2021/04/09 17:21:36 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	get_player_code(char *file)
{
	void	*content;
	int		ret;
	int		fd;

	ret = 1;
	fd = open(file, O_RDONLY);
	// lseek(fd, 0, SEEK_END);
	if (fd != -1)
	{
		ft_printf("%s\n", file);
		while (ret > 0)
		{
			// content = malloc(4000);
			ret = read(fd, &content, 128);
			ft_pr_hex((char *)content, 148, 1);
			ft_printf("\n");
		}
		// ret = get_next_line(fd, &content, 0);
		validate_champ(content);
	}
	else
		ft_printf("{red}Error while opening file: %s{r}\n", strerror(errno));
	close(fd);
}

