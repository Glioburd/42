/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 17:37:52 by gsauvair          #+#    #+#             */
/*   Updated: 2015/02/02 18:13:23 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#define OPTIONS "# +-0*vhlLn"
#define ON 1
#define OFF 2
#include <stdlib.h>
#include <stdarg.h>
#include "./libft/libft.h"

typedef struct	s_opt
{
	char		*get;
	int			width;
	int			len_prev;
}				t_opt;

typedef struct	s_flag
{
	int			space;
	int			num;
	char		sum;
	char		sub;
	char		sharp;
}				t_flag;

typedef struct	s_tab
{
	char		*flag;
	char		*(*func) (t_opt, va_list, int);
}				t_tab;

char	*print_details(char *str, t_opt opt);
char	*final_print(char *str, t_opt opt);
char	*nextprint(char *str, t_opt opt);
int		ft_find(const char *str);
int		ft_putpercent(const char *str);
int		ft_putstd(const char *str);
int		ft_printf(const char *str, ...);
void	continue_itoa(int n, char *str, int b, char *base);
char	*itoa(char *base, int n);
void	continue_litoa(long int n, char *str, long int b, char *base);
char	*litoa(char *base, long int n);
char	*ft_turn_off(void);
int		get_info(char **str, va_list ap);
int		ft_is_option(char c);
void	ft_check_option(char *get, char **str, t_opt *opt, va_list ap);
t_opt	ft_get_option(char **str, va_list ap);
char	*ft_base(int flag);
char	*ul(int flag, char *base, va_list ap);
char	*ft_print_number(t_opt opt, va_list ap, int flag);
int		ft_check_ap(va_list ap);
char	*fill(char c, int len);
char	*continue_print(char *str, t_opt opt);
char	*ft_print_str(t_opt opt, va_list ap, int check);
int		ft_flag(t_opt opt, char **str, va_list ap);
int		ft_display(va_list ap, char **str);
void	continue_uitoa(unsigned int n, char *str, unsigned int b, char *base);
char	*uitoa(char *base, unsigned int n);
void	cont_ult(unsigned long int n, char *s, unsigned long b, char *d);
char	*ultoa(char *base, unsigned long n);

#endif
