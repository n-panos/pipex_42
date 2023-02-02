/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:20:02 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/02/02 12:22:20 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(const char *s1)
{
	int		i;
	char	*copy;
	int		j;

	i = ft_strlen_gnl(s1) + 1;
	j = 0;
	copy = malloc(sizeof(char) * i);
	if (!copy)
		return (NULL);
	while (s1[j] != '\0')
	{
		copy[j] = s1[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	n;
	size_t	tam;

	if (s == '\0')
		return (NULL);
	tam = len + 1;
	if (ft_strlen_gnl(s) < len)
		tam = ft_strlen_gnl(s) - start + 1;
	str = malloc(sizeof(char) * tam);
	if (!str)
		return (NULL);
	if (start >= ft_strlen_gnl(s))
		return (ft_strdup_gnl(""));
	n = 0;
	while (s[start] != '\0' && len)
	{
		str[n] = s[start];
		start++;
		n++;
		len--;
	}
	str[n] = '\0';
	return (str);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr_gnl(char *str, int c)
{
	char	*s;

	s = (char *)str;
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*cat;
	int		i;
	int		j;

	if (s1 == '\0' || s2 == '\0')
		return (NULL);
	i = 0;
	j = 0;
	cat = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!cat)
		return (NULL);
	while (s1[i] != '\0')
	{
		cat[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		cat[i] = s2[j];
		i++;
		j++;
	}
	cat[i] = '\0';
	return (cat);
}
