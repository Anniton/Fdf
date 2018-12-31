/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:19:14 by cmoulini          #+#    #+#             */
/*   Updated: 2018/12/26 14:42:31 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct			s_listgnl
{
	int					fd;
	char				*str;
	struct s_listgnl	*next;
}						t_listgnl;

int						get_next_line(const int fd, char **line);

#endif
