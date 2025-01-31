/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:06:27 by mtangalv          #+#    #+#             */
/*   Updated: 2025/01/18 20:26:21 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!src || !dst)
		return (0);
	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && *src != '\0')
	{
		*dst++ = *src++;
		i++;
	}
	if (i < size)
		*dst = '\0';
	while (*src++ != '\0')
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ptr;

	if (!src)
		return (NULL);
	ptr = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, src, ft_strlen(src) + 1);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	final = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!final)
		return (NULL);
	while (s1[i] != '\0')
	{
		final[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		final[i] = s2[j];
		i++;
		j++;
	}
	final[i] = '\0';
	return (final);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	if ((char) c == '\0')
		return ((char *)s);
	return (0);
}
