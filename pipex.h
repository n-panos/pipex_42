/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:50:12 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/02/02 12:44:27 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>

void	ft_parse_path(char **argv);

//          FIND PATH

char	*find_path(char **envp, char *cmd);
char	*ft_no_path(char **envp, char *cmd);
int		ft_execute(char *path, char *cmd, char **envp);

//          UTILS

void	ft_free_matrix(char **mtx);

#endif