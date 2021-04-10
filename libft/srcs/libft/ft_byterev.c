/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_byterev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:47:07 by mkarkaus          #+#    #+#             */
/*   Updated: 2021/04/10 14:18:00 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_byterev(uint8_t *mem, unsigned int len)
{
	uint8_t		*temp;
	unsigned int	i;

	i = 0;
	temp = (uint8_t *)malloc(len * sizeof(uint8_t));
	ft_memcpy(temp, mem, len);
	while (i < len)
	{
		temp[i] = mem[len - i - 1];
		i++;
	}
	ft_memcpy(mem, temp, len);
}
