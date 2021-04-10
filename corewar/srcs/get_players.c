/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:05:57 by mkarkaus          #+#    #+#             */
/*   Updated: 2021/04/10 17:38:05 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Reads from file descriptor all the properties of the champion straight 
**	to the struct 't_player' in order and skips 4 bytes of zeroes with lseek
**	which are padding the name and comment. This function also reverses the
**	order of bytes of integers so that they show the right decimal value.
*/

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
		ft_byterev((uint8_t *)&(players->header.magic), sizeof(int));
		ft_byterev((uint8_t *)&(players->header.prog_size), sizeof(int));
		players->next = NULL;

		ft_pr_hex((void *)&players->header.magic, sizeof(int), 1);
		ft_printf("%u\n", players->header.magic);
		ft_printf("\n");
		ft_pr_hex(players->header.prog_name, PROG_NAME_LENGTH, 1);
		ft_printf("\n");
		ft_pr_hex((void *)&players->header.prog_size, sizeof(int), 1);
		ft_printf("%u\n", players->header.prog_size);
		ft_printf("\n");
		ft_pr_hex(players->header.comment, COMMENT_LENGTH, 1);
		ft_printf("\n");
		ft_pr_hex(players->code, 1000, 1);
		exit(1);

		// validate_champ(content);
	}
	else
		ft_exit("Error while opening file.\n");
	close(fd);
}
