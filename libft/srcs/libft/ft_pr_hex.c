/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:31:34 by mkarkaus          #+#    #+#             */
/*   Updated: 2021/04/09 16:25:36 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	print_hex_line(unsigned char *mem, int len, int fd)
{
	char	hex[17] = "0123456789abcdef";
	int		i;

	i = 0;
	while (i < 16)
	{
		if (i < len)
		{
			write(fd, ((*mem / 16) + hex), 1);
			write(fd, ((*mem % 16) + hex), 1);
			mem++;
		}
		else
			write(fd, "  ", 2);
		write(fd, " ", 1);
		i++;
	}
}

void	print_ascii_line(unsigned char *mem, int len, int fd)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (i < len)
		{
			if (*mem >= 32 && *mem <= 126)
				write(fd, mem, 1);
			else
				write(fd, ".", 1);
			mem++;
		}
		else
			write(fd, " ", 1);
		i++;
	}
}

void	ft_pr_hex(unsigned char *mem, int len, int fd)
{
	while (len > 0)
	{
		print_hex_line(mem, len, fd);
		write(fd, "   ", 3);
		print_ascii_line(mem, len, fd);
		write(fd, "\n", 1);
		mem += 16;
		len -= 16;
	}
}
