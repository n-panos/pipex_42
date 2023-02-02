/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:54:16 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/02/02 12:20:05 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1

int			get_next_line_gnl(int fd, char **line);
size_t		ft_strlen_gnl(const char *s);
char		*ft_strdup_gnl(const char *s1);
char		*ft_strchr_gnl(char *str, int c);
char		*ft_strjoin_gnl(char *s1, char *s2);
char		*ft_substr_gnl(char const *s, unsigned int start, size_t len);
#endif
