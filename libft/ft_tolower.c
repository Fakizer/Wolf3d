/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:05:34 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/23 17:05:35 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int ch)
{
	if (ch >= 65 && ch <= 90)
		return (ch + 32);
	if (ch >= 97 && ch <= 122)
		return (ch);
	else
		return (ch);
}
