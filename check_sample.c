/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sample.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:13:20 by aquan             #+#    #+#             */
/*   Updated: 2019/02/11 14:46:05 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		validity(t_struct *env, t_check *sample)
{
	if (sample->tab)
		sample->tmp = sample->tab;
	if (!(sample->tab = (int**)ft_memalloc(sizeof(int*)
					* (sample->len + 1))))
		return (-1);
	if (!(ft_check_x(sample->line)))
		return (-1);
	sample->s_split = ft_strsplit(sample->line, ' ');
	free(sample->line);
	if (env->firstline == 0)
	{
		env->nb_x = ft_arrlen(sample->s_split);
		env->firstline = 1;
	}
	sample->len_of_a_line = ft_arrlen(sample->s_split);
	if (sample->len_of_a_line < env->nb_x)
		return (-1);
	if (sample->len > 0)
		ft_arrcpy(sample->tmp, sample->tab,
				sample->len, sample->len_of_a_line);
	sample->tab[sample->len] = ft_convert(sample->s_split);
	return (0);
}

int				check_sample_validity(int fd, t_struct *env)
{
	t_check		*sample;

	if (!(sample = (t_check*)ft_memalloc(sizeof(t_check))))
		return (0);
	sample->len = 0;
	sample->tmp = NULL;
	sample->tab = NULL;
	env->firstline = 0;
	while (get_next_line(fd, &sample->line) > 0)
	{
		if (validity(env, sample) == -1)
			return (-1);
		sample->len++;
	}
	env->nb_y = sample->len;
	env->final = sample->tab;
	free(sample);
	return (1);
}
