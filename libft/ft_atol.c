/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:10:02 by maroy             #+#    #+#             */
/*   Updated: 2023/06/26 16:28:14 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long	i;
	long	s;
	long	res;
	char	*cstr;

	if (!str)
		return (0);
	cstr = (char *)str;
	i = 0;
	s = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (cstr[i] == '-' || cstr[i] == '+')
	{
		if (cstr[i] == '-')
			s = -s;
		i++;
	}
	while (ft_isdigit(cstr[i]))
	{
		res = res * 10 + cstr[i] - '0';
		i++;
	}
	return (s * res);
}
