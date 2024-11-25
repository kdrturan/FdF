/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abturan <abturan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:02:37 by abturan           #+#    #+#             */
/*   Updated: 2024/11/25 17:17:41 by abturan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	index_hex(char ch)
{
	char	*hex;
	char	*hex_up;
	int		i;

	i = -1;
	hex = "0123456789abcdef";
	hex_up = "0123456789ABCDEF";
	while (++i < 16)
		if (ch == hex[i] || ch == hex_up[i])
			return (i);
	return (-1);
}

int	ft_puthex(char *str, t_file *data)
{
	int	hex_val;
	int	result;
	int	i;
	int	len;

	len = 0;
	i = 0;
	result = 0;
	if (!str)
		return (YELLOW);
	if (str[1] != '0' && (str[2] != 'x' || str[2] != 'X'))
		return (-1);
	str += 3;
	while (str[len])
		len++;
	while (str[i])
	{
		hex_val = index_hex(str[i]);
		if (hex_val == -1)
			return (-1);
		result += hex_val * (int)pow(16, (len - i - 1));
		i++;
	}
	return (result);
}
