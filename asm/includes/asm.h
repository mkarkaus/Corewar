/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:02:39 by sreijola          #+#    #+#             */
/*   Updated: 2021/04/10 18:50:57 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ASM_H
# define	ASM_H

# include "../../libft/includes/libft.h"
# include "../../includes/op.h"

void		get_champion(char *name, t_list **champ);
void	write_bytecode(char *name, t_list *champ, int flag);

#endif
