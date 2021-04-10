/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:01:03 by sreijola          #+#    #+#             */
/*   Updated: 2021/04/10 22:13:53 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

void		translate_to_bytecode(char *line, t_list **node)
{
	(*node)->next = ft_lstnew(line, ft_strlen(line));
}


void		get_champion(char *name, t_list **champ)
{
	int		fd;
	char	*line;
	t_list	*node;

	fd = open(name, O_RDONLY);
	if (fd < 0 || get_next_line(fd, &line, 0) < 1)
		ft_exit("Failed to open or read from file"); //	(ft_printf("%s\n", strerror(errno)
	*champ = ft_lstnew(line, ft_strlen(line));
	node = *champ;
	while (get_next_line(fd, &line, 0))
	{
		translate_to_bytecode(line, &node);
		node = node->next;
	}
	close(fd);
}
