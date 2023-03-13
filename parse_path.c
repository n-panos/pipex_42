/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:57:46 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/02/14 12:12:34 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_find_path(char **envp, char *cmd)
{
	char	*path;
	char	**cmd_flags;

	if (!cmd)
		return (NULL);
	cmd_flags = ft_split(cmd, ' ');
	path = cmd_flags[0];
	cmd_flags[0] = ft_strrchr(path, '/');
	if (ft_strrchr(path, '/') == NULL)
		path = ft_no_path(envp, cmd);
	return (path);
}

static void	ft_write_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		write(1, mat[i], ft_strlen(mat[i]));
		write(1, "\n", 1);
		i++;
	}
}

char	*ft_no_path(char **envp, char *cmd)
{
	int		i;
	char	**pos_paths;
	char	*path;
	char	**cmd_flags;

	if (envp == NULL)
		return (NULL);
	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH", 5))
		i++;
	cmd_flags = ft_split(cmd, ' ');
	//ft_write_mat(envp);
	write(1, "AB\n", 3);
	pos_paths = ft_split(envp[i] + 5, ':');
	ft_write_mat(pos_paths);
	i = 0;
	while (pos_paths)
	{
		path = ft_strjoin(pos_paths[i], cmd_flags[0]);
		if (ft_execute(path, cmd, envp) == 0)
			break ;
		free (path);
		i++;
	}
	ft_free_matrix(cmd_flags);
	ft_free_matrix(pos_paths);
	return (path);
}

int	ft_execute(char *path, char *cmd, char **envp)
{
	if (execve(path, &cmd, envp) == -1)
		return (1);
	return (0);
}
