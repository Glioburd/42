/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 16:29:41 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/22 15:16:00 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE

# define BUFF_SIZE	5000

#include "./Libft/libft.h"

int	get_next_line(int const fd, char **line);

#endif
