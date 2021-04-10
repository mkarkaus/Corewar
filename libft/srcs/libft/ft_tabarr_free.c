/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabarr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 04:24:18 by sreijola          #+#    #+#             */
/*   Updated: 2021/03/05 12:49:26 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_tabarr_free(int **tab, int max_rows)
{
	if (!tab)
		return ;
	while (--max_rows >= 0)
		free(tab[max_rows]);
	free(tab);
}
