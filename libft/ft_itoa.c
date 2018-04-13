/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:58:24 by vvlasenk          #+#    #+#             */
/*   Updated: 2017/10/24 19:22:32 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_pos(char *str, int n, int len)
{
	str[--len] = '0' + (n % 10);
	n /= 10;
	while (n)
	{
		str[--len] = '0' + (n % 10);
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_nbrlen(n);
	str = ft_strnew(len);
	if (str == NULL)
		return (0);
	if (n >= 0)
		ft_pos(str, n, len);
	else
	{
		str[0] = '-';
		while (n)
		{
			str[--len] = '0' - (n % 10);
			n /= 10;
		}
	}
	return (str);
}
