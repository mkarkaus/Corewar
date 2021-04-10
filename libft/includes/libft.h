/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:57:46 by mkarkaus          #+#    #+#             */
/*   Updated: 2021/04/09 16:26:03 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_lstprint(t_list *alst);
void			ft_lstapp(t_list **alst, t_list *end);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstnew(void const *content, size_t content_size);
size_t			ft_strlcat(char *dest, const char *src, size_t len);
size_t			ft_strlen(const char *s);
void			ft_putchar(char c);
void			ft_putnbr(int n);
int				ft_putstr(char const *s);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strdup(const char *s);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *dest, const char *src, size_t len);
char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strstr(char const *s1, char const *s2);
char			*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strchr(char const *s, int c);
char			*ft_strrchr(char const *s, int c);
int				ft_strcmp(char const *s1, char const *s2);
int				ft_strncmp(char const *s1, char const *s2, size_t n);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2, int free_int);
char			*ft_strtrim(char const *s);
char			*ft_strrev(char *str, int free_str);
char			**ft_strsplit(char const *s, char c);
char			*ft_strcut(char *str, int vol, int dir, int free_str);
int				ft_atoi(const char *str);
unsigned int	ft_atoui(const char *str);
char			*ft_itoa(int n);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_swap(int *a, int *b);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_intlen(int n);
int				ft_longlen(long n);
char			*ft_itoa_llong(long long n);
int				ft_intlen_llong(long long n);
char			*ft_itoa_ptr(int *n);
int				ft_onlydigits(char *str);
void			ft_free_arrays(void **ptr, int rows);

void			ft_pr_intarr(int **arr, int maxr, int maxc, int fd);
void			ft_pr_chararr(char **arr, int maxr, int fd);
void			ft_pr_hex(unsigned char *mem, int len, int fd);

void			ft_strarr_free(char **arr);
char			**ft_strarr_malloc(int rows, int cols);
int				ft_strarrsize(char **arr);
void			ft_lstfree(t_list *lst);
int				ft_lstlen(t_list *lst);
void			ft_arr_free(void **tab, int max_rows);
void			**ft_arr_malloc(unsigned long ptrs, unsigned long bytes);
void			ft_tabarr_free(int **tab, int max_rows);
int				**ft_tabarr_malloc(int max_rows, int max_cols);
int				ft_tabint_find(int *tab, int to_find, int tab_len);
int				ft_tabnequ(int *t1, int *t2, int n);

int				ft_strarr_size(char **arr);
void			ft_strarr_free(char **arr);
void			ft_strarr_print(char **arr);

#endif
