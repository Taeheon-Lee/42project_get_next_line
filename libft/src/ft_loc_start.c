/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loc_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 01:47:20 by tlee              #+#    #+#             */
/*   Updated: 2020/02/28 17:07:45 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_loc_start(char const *s, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (s[i] != '\n' && s[i] != '\t' && s[i] != ' ')
			break ;
		i++;
	}
	return (i);
}
