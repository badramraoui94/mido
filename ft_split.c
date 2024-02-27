/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamraoui <bamraoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:04:36 by bamraoui          #+#    #+#             */
/*   Updated: 2024/02/27 11:04:40 by bamraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_words(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (count);
}

static char	*ft_alloc(char **s, char c)
{
	int		i;
	char	*p;

	i = 0;
	while ((*s)[i] != '\0' && (*s)[i] != c)
		i++;
	p = malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (**s && **s != c)
	{
		p[i] = **s;
		i++;
		*s += 1;
	}
	p[i] = '\0';
	return (p);
}

static char	**ft_freed(char **arr, int j)
{
	while (j >= 0)
	{
		free(arr[j]);
		j--;
	}
	free (arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	i = count_words((char *)s, c);
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			tab[i] = ft_alloc((char **)&s, c);
			if (!tab[i])
				return (ft_freed(tab, i--));
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
