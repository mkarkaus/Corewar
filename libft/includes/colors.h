/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 19:29:59 by mkarkaus          #+#    #+#             */
/*   Updated: 2021/04/08 12:45:52 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLORS_H
# define FT_COLORS_H

/*
**In order:
**Normal text
**Bold text
**Faint text
**Italic text
**Underlined text
**Background color
*/

# ifdef __linux__
	#define CLR_CODE "\e["
# endif

# ifdef __APPLE__
	#define CLR_CODE "\x1b["
# endif

const char	*g_cname[] =
{
	"{r}",
	"{red}",
	"{green}",
	"{yellow}",
	"{blue}",
	"{magenta}",
	"{cyan}",
	"{white}",
	"{b_red}",
	"{b_green}",
	"{b_yellow}",
	"{b_blue}",
	"{b_magenta}",
	"{b_cyan}",
	"{b_white}",
	"{f_red}",
	"{f_green}",
	"{f_yellow}",
	"{f_blue}",
	"{f_magenta}",
	"{f_cyan}",
	"{f_white}",
	"{i_red}",
	"{i_green}",
	"{i_yellow}",
	"{i_blue}",
	"{i_magenta}",
	"{i_cyan}",
	"{i_white}",
	"{u_red}",
	"{u_green}",
	"{u_yellow}",
	"{u_blue}",
	"{u_magenta}",
	"{u_cyan}",
	"{u_white}",
	"{bck_black}",
	"{bck_red}",
	"{bck_green}",
	"{bck_yellow}",
	"{bck_blue}",
	"{bck_magenta}",
	"{bck_cyan}",
	"{bck_white}",
};

const char	*g_ccode[] = {
	"0;0m",
	"0;31m",
	"0;32m",
	"0;33m",
	"0;34m",
	"0;35m",
	"0;36m",
	"0;37m",
	"1;31m",
	"1;32m",
	"1;33m",
	"1;34m",
	"1;35m",
	"1;36m",
	"1;37m",
	"2;31m",
	"2;32m",
	"2;33m",
	"2;34m",
	"2;35m",
	"2;36m",
	"2;37m",
	"3;31m",
	"3;32m",
	"3;33m",
	"3;34m",
	"3;35m",
	"3;36m",
	"3;37m",
	"4;31m",
	"4;32m",
	"4;33m",
	"4;34m",
	"4;35m",
	"4;36m",
	"4;37m",
	"0;40m",
	"0;41m",
	"0;42m",
	"0;43m",
	"0;44m",
	"0;45m",
	"0;46m",
	"0;47m"
};

#endif
