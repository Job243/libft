/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 22:40:20 by jmafueni          #+#    #+#             */
/*   Updated: 2023/11/21 16:53:48 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	value;

	i = 0;
	value = 0;
	sign = 1;
	while (is_space((const char)nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		value = value * 10 + nptr[i] - '0';
		i++;
	}
	return (value * sign);
}

/*int	main(void)
{
	const char	*str = "--12345";
	int			value = ft_atoi(str);

	printf("La valeur entière convertie de la chaîne est : %d\n", value);
	return (0);
}*/
