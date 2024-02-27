/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamraoui <bamraoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:15:44 by bamraoui          #+#    #+#             */
/*   Updated: 2024/02/27 12:36:44 by bamraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <time.h>

void	child1_p(char **av, int *pipe_fd, char **env);
void	child2_p(char **av, int *pipe_fd, char **env);
void	close_wait(int pipe_fd, int pid);
void	exec_cmd(char *cmd, char **env);
void	print_error(char *s);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *str, const char *s, size_t len);
char	*ft_path(char **env);
void	free_all(char **arr);
char	*full_path(char *cmd, char **env);
size_t	slen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

#endif