/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:34:09 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/02/02 12:23:25 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_valid_return(char **s, char **line, int fd, int byte_rd)
{
	char	*aux;
	int		len;

	if (byte_rd == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
	{
		*line = ft_strdup_gnl("");
		free(s[fd]);
		s[fd] = NULL;
		return (0);
	}
	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	*line = ft_substr_gnl(s[fd], 0, len);
	if (s[fd][len] == '\0')
	{
		free(s[fd]);
		s[fd] = NULL;
		return (0);
	}
	aux = ft_strdup_gnl(s[fd] + len + 1);
	free(s[fd]);
	s[fd] = aux;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*s[4096];
	char		*buf;
	int			byte_rd;
	char		*aux;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf || fd < 0 || line == NULL)
		return (-1);
	byte_rd = read(fd, buf, BUFFER_SIZE);
	while (byte_rd > 0)
	{
		buf[byte_rd] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup_gnl("");
		aux = ft_strjoin_gnl(s[fd], buf);
		free(s[fd]);
		s[fd] = aux;
		if (ft_strchr_gnl(s[fd], '\n'))
			break ;
		byte_rd = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (byte_rd < 0)
		return (-1);
	return (ft_valid_return(s, line, fd, byte_rd));
}
