/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamraoui <bamraoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:15:07 by bamraoui          #+#    #+#             */
/*   Updated: 2024/02/27 18:45:22 by bamraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *cmd, char **env)
{
	char	**tab;
	char	*path;
	int		res;

	tab = ft_split(cmd, ' ');
	path = full_path(tab[0], env);
	res = execve(path, tab, env);
	if (res < 0)
	{
		free_all(tab);
		print_error("command not found\n");
	}
}

void	child1_p(char **av, int *pipe_fd, char **env)
{
	int	fd;

	close(pipe_fd[0]);
	fd = open(av[1], O_RDONLY, 0777);
	if (fd < 1)
		print_error("could not open the file");
	if (dup2(fd, 0) == -1)
		print_error("Error in dup2");
	if (dup2(pipe_fd[1], 1) == -1)
		print_error("Error in dup2");
	close(fd);
	close(pipe_fd[1]);
	exec_cmd(av[2], env);
}

void	child2_p(char **av, int *pipe_fd, char **env)
{
	int	fd;

	close(pipe_fd[1]);
	fd = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd < 1)
		print_error("Error in open");
	if (dup2(fd, 1) == -1)
		print_error("Error in dup2");
	if (dup2(pipe_fd[0], 0) == -1)
		print_error("Error in dup2");
	close(fd);
	close(pipe_fd[0]);
	exec_cmd(av[3], env);
}

void	close_wait(int pipe_fd, int pid)
{
	close(pipe_fd);
	waitpid(pid, NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (ac == 5)
	{
		if (pipe(pipe_fd) == -1)
			exit(1);
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0)
			child1_p(av, pipe_fd, env);
		pid2 = fork();
		if (pid2 == -1)
			exit(1);
		if (pid2 == 0)
			child2_p(av, pipe_fd, env);
		close_wait(pipe_fd[0], pid);
		close_wait(pipe_fd[1], pid2);
	}
	else
		print_error("Incorrect, please enter 5 arguments\n");
	return (0);
}
