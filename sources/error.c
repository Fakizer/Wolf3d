/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 19:09:52 by vvlasenk          #+#    #+#             */
/*   Updated: 2017/01/01 19:09:53 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_error(char *pref)
{
	ft_putstr_fd(PROG_NAME, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(pref, 2);
	ft_putstr_fd("\n", 2);
	exit(ERROR_EXIT);
}
