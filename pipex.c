/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:47:31 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/03/13 11:33:18 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		*fd;
	pid_t	pidc;
	int		error;

	error = 0;
	if (argc != 5)
		return (ft_error(5));
	fd = ft_calloc(2, sizeof(int));
	if (!fd || (pipe(fd) == -1))
		return (ft_error(1));
	pidc = fork();
	if (pidc == -1)
		return (ft_error(2));
	if (pidc == 0)
		error = ft_proc_hijo(fd, envp, argv);
	else if (error == 0)
		error = ft_proc_padre(fd, envp, argv);
	return (ft_error(error));
}

int	ft_proc_hijo(int *fd, char **envp, char **argv)
{
	char	*path;
	char	*cmd;
	int		infile_id;
	int		error_flag;

	printf("Proceso hijo:");
	error_flag = 0;
	cmd = argv[2];
	close(fd[0]);
	path = ft_find_path(envp, cmd);
	infile_id = open(argv[1], O_RDONLY);
	if (infile_id == -1)
		error_flag = 3;
	else
	{
		dup2(infile_id, 0);
		dup2(fd[1], 1);
		if (execve(path, &cmd, envp) == -1)
			error_flag = 6;
	}
	free(path);
	return (0);
}

int	ft_proc_padre(int *fd, char **envp, char **argv)
{
	char	*path;
	char	*cmd;
	int		outfile_id;
	int		error_flag;

	printf("Proceso padre:");
	error_flag = 0;
	cmd = argv[3];
	close(fd[1]);
	path = ft_find_path(envp, cmd);
	outfile_id = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile_id == -1)
		error_flag = 4;
	else
	{
		dup2(fd[0], 0);
		dup2(outfile_id, 1);
		if (execve(path, &cmd, envp) == -1)
			error_flag = 6;
	}
	free(path);
	return (0);
}
