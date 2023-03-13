/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:50:12 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/02/13 13:11:21 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

int		main(int argc, char **argv, char **envp);

//          FIND PATH

char	*ft_find_path(char **envp, char *cmd);
char	*ft_no_path(char **envp, char *cmd);
int		ft_execute(char *path, char *cmd, char **envp);

//			PROCESSES

int		ft_proc_hijo(int *fd, char **envp, char **argv);
int		ft_proc_padre(int *fd, char **envp, char **argv);

//          UTILS

void	ft_free_matrix(char **mtx);
int		ft_error(int flag);

#endif