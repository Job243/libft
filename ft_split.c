/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:02:11 by jmafueni          #+#    #+#             */
/*   Updated: 2023/12/05 18:44:22 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			count++;
		i++;
	}
	return (count);
}

static	char	*ft_strndup(const char *s, int n)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_free_split(char **tab, int j)
{
	if (!tab[j])
	{
		while (j > 0)
			free(tab[j--]);
		free(tab);
		return (NULL);
	}
	return (tab);
}

static char	**ft_extractwords(char **tab, const char *s, char c)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
		{
			tab[j] = ft_strndup(s + start, i - start);
			ft_free_split(tab, j);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!tab)
		return (NULL);
	ft_extractwords(tab, s, c);
	return (tab);
}

/*int	main(void)
{
	char	str[] = " bonjour le monde ";
	char	c;
	int		i;
	char	**tab;

	c = ' ';
	i = 0;
	tab = ft_split(str, c);
	while (i < ft_countwords(str, c))
	{
		printf("tab[%d] -> %s\n", i, tab[i]);
		i++;
	}
	return (0);
}*/
