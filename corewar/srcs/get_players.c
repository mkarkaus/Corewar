/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:05:57 by mkarkaus          #+#    #+#             */
/*   Updated: 2021/04/10 11:50:15 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	get_player_code(char *file, t_player *players)
{
	int		ret;
	int		fd;

	ret = 1;
	fd = open(file, O_RDONLY);
	if (fd != -1)
	{
		players = (t_player *)malloc(sizeof(t_player));
		read(fd, &(players->header.magic), sizeof(unsigned int));
		read(fd, players->header.prog_name, PROG_NAME_LENGTH);
		lseek(fd, 4, SEEK_CUR);
		read(fd, &(players->header.prog_size), sizeof(unsigned int));
		read(fd, players->header.comment, COMMENT_LENGTH);
		lseek(fd, 4, SEEK_CUR);
		read(fd, &(players->code), CHAMP_MAX_SIZE);
		

		ft_pr_hex((void *)&players->header.magic, sizeof(int), 1);
		ft_printf("\n");
		ft_pr_hex(players->header.prog_name, PROG_NAME_LENGTH, 1);
		ft_printf("\n");
		ft_pr_hex((void *)&players->header.prog_size, sizeof(int), 1);
		ft_printf("%u\n", players->header.prog_size);
		ft_printf("\n");
		ft_pr_hex(players->header.comment, COMMENT_LENGTH, 1);
		ft_printf("\n");
		ft_pr_hex(players->code, CHAMP_MAX_SIZE, 1);
		exit(1);
		
		// validate_champ(content);
	}
	else
		ft_printf("{red}Error while opening file: %s{r}\n", strerror(errno));
	close(fd);
}

