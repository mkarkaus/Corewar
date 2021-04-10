/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytecode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:06:25 by sreijola          #+#    #+#             */
/*   Updated: 2021/04/10 23:53:18 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

void	write_bytecode(char *name, t_list *champ, int flag)
{
	int		fd;
	char	*tmp;
	mode_t	mode;
	
	fd = 1;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	tmp = ft_strsub(name, 0, ft_strlen(name) - 2);
	tmp = ft_strjoin(tmp, ".cor", 1);
	if (flag == 0)
		fd = open(tmp, O_WRONLY | O_CREAT | O_TRUNC, mode); //S_IRWXO); //if error in translation no .cor file can exist HUOM! ei toimi jos on ollut ja poistettu(symbolic link)
	if (fd < 0)//onhan riittävä ehto
		ft_exit("Failed to open .cor\n");
	while (champ)
	{
		write(fd, champ->content, champ->content_size);
		write(fd, "\n", 1); //muista muuttaa vastaamaan fd:tä jos tarpeen
		champ = champ->next;
	}
	close(fd);
}
