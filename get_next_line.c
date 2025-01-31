/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:06:33 by mtangalv          #+#    #+#             */
/*   Updated: 2025/01/23 12:22:10 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

static char	*get_string(int fd, char *stash, char *backup, int *error)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line)
	{
		read_line = read(fd, stash, BUFFER_SIZE);
		if (read_line == -1)
		{
			*error = -1;
			return (0);
		}
		if (read_line == 0)
			break ;
		stash[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		char_temp = backup;
		backup = ft_strjoin(char_temp, stash);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract_line(char *string)
{
	size_t		count;
	char		*aftermath;

	count = 0;
	while (string[count] != '\n' && string[count] != '\0')
		count++;
	if (string[count] == '\0' || string[1] == '\0')
		return (0);
	aftermath = ft_substr(string, count + 1, ft_strlen(string) - count);
	if (*aftermath == '\0')
	{
		free (aftermath);
		aftermath = NULL;
	}
	string[count + 1] = '\0';
	return (aftermath);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*buffer;
	int			error;

	error = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = get_string(fd, buffer, backup, &error);
	if (error == -1)
	{
		free(backup);
		backup = NULL;
	}
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	backup = extract_line(line);
	return (line);
}
