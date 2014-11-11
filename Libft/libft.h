/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:23:02 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/11 13:23:38 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_strcat(char *dest, const char *src);//ok
char	*ft_strncat(char *dest, const char *src, size_t n);//ok
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);// ok
int		ft_strncmp(const char *s1, const char *s2, size_t n);// ok
int		ft_atoi(const char *str);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *str, const char *tofind, size_t n);//ok
size_t	ft_strlcat(char *dst, char *src, size_t size);//ok
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	ft_bzero(void *str, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_memset(void *str, int c, size_t n);//ok
void	*ft_memmove(void *dest, const void *src, size_t n);//ok
void	*ft_memcpy(void *dest, const void *src, size_t n);//ok
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);//ok
void	*ft_memalloc(size_t size);//ok
void	ft_putnbr(int n);//ok
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar(char c);//ok
void	ft_putstr(char const *str);//ok
int		ft_strequ(char const *s1, char const *s2);//ok
int		ft_strnequ(char const *s1, char const *s2, size_t n);
void	ft_strclr(char *s);
char	*ft_strnew(size_t size);
char	*ft_strmap(char const *s, char (*f)(char));// ok
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));//ok
char	*ft_strsub(char const *s, unsigned int start, size_t len);//ok
char	*ft_strjoin(char const *s1, char const *s2);//ok
char	*ft_strtrim(char const *s);//ok
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
char	*ft_itoa(int n);
void	ft_memdel(void **ap);
void	ft_strdel(char **as);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_isspace(char c);
#endif
