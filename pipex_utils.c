/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamraoui <bamraoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:20:12 by bamraoui          #+#    #+#             */
/*   Updated: 2024/02/27 18:40:23 by bamraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strnstr(const char *str, const char *s, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lens;

	i = 0;
	j = 0;
	lens = ft_strlen(s);
	if (*s == '\0')
		return ((char *)str);
	if (len == 0)
		return (NULL);
	while (str[i] != '\0' && lens <= len)
	{
		j = 0;
		while (str[i + j] == s[j] && (i + j) < len)
		{
			j++;
			if (s[j] == '\0')
				return ((char *)(str + i));
		}
		i++;
	}
	return (NULL);
}

char	*ft_path(char **env)
{
	char	*path;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", 4))
		{
			path = env[i] + 5;
			return (path);
		}
		i++;
	}
	return (NULL);
}

void	free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	*full_path(char *cmd, char **env)
{
	int		i;
	char	**split;
	char	*str_path;
	char	*add_slash;
	char	*add_cmd;

	i = 0;
	str_path = ft_path(env);
	split = ft_split(str_path, ':');
	while (split[i])
	{
		add_slash = ft_strjoin(split[i], "/");
		add_cmd = ft_strjoin(add_slash, cmd);
		free(add_slash);
		if (access(add_cmd, F_OK) == 0)
		{
			free_all(split);
			return (add_cmd);
		}
		free(add_cmd);
		i++;
	}
	free_all(split);
	return (cmd);
}
