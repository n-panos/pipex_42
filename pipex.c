/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:47:31 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/02/02 12:05:56 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		*fd;
	pid_t	pidc;
	int		infile_id;

	if (argc != 5)
		return (1);
	infile_id = open(argv[1], O_RDONLY);
	fd = ft_calloc(2, sizeof(int));
	if (!fd || (pipe(fd) == -1))
		return (1); //error management
	pidc = fork();
	if (pidc == 0)
		ft_proc_hijo(fd, argv[1], argv[2], infile_id);
	else if (pidc == -1)
		return (1); //error management
	else
		ft_proc_padre();
	return (0);
}

void	ft_proc_hijo(int *fd, char *filename, char *cmd, int infile_id)
{
	char	*str;

	close(fd[0]);

	write(fd[1]	);
}

void	ft_proc_padre(int *fd)
{
	close(fd[1]);
	read(fd[1]	);
}
