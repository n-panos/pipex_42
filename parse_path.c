/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:57:46 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/02/02 09:53:19 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp, char *cmd)
{
	char	*path;
	char	**cmd_flags;

	if (!cmd)
		return (1);
	cmd_flags = ft_split(cmd, ' ');
	path = cmd_flags[0];
	cmd_flags[0] = ft_strrchr(path, '/');
	if (ft_strrchr(path, '/') == NULL)
		path = ft_no_path(envp, cmd);
	else
		cmd++;
	if (ft_execute(path, cmd, envp) == 1)
		return (NULL);
	return (path);
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
	while (envp[i] && ft_strnstr(envp[i], "PATH", 5))
		i++;
	cmd_flags = ft_split(cmd, ' ');
	pos_paths = ft_split(envp[i] + 5, ':');
	while (pos_paths)
	{
		path = ft_strjoin(pos_paths[0], cmd_flags[0]);
		if (ft_execute(path, cmd, envp) == 0)
			break ;
		free (path);
		pos_paths++;
	}
	ft_free_matrix(cmd_flags);
	ft_free_matrix(pos_paths);
	return (path);
}

int	ft_execute(char *path, char *cmd, char **envp)
{
	if (execve(path, cmd, envp) == NULL)
		return (1);
	return (0);
}
