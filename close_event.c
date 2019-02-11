/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:07:41 by aquan             #+#    #+#             */
/*   Updated: 2019/02/08 16:59:30 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		cross_event(t_struct *env)
{
	destroy_all(env);
	exit(EXIT_SUCCESS);
}

int		esc_key(int key, t_struct *env)
{
	if (key == 53)
	{
		destroy_all(env);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
