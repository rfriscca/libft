/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:41:30 by rfriscca          #+#    #+#             */
/*   Updated: 2015/12/09 15:00:57 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_taballoc_line(char **tab, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			j++;
			i++;
		}
		if (j != 0)
			tab[k] = ft_strnew(j);
		j = 0;
		k++;
	}
	return (tab);
}

static char	**ft_taballoc(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			j++;
		i++;
	}
	if ((tab = (char**)malloc(j * sizeof(tab))) == NULL)
		return (NULL);
	tab = ft_taballoc_line(tab, s, c);
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	k = 0;
	tab = ft_taballoc(s, c);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			tab[k][j] = ((char*)s)[i];
			i++;
			j++;
		}
		j = 0;
		k++;
	}
	return (tab);
}
