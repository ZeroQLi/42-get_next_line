/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:06:25 by mtangalv          #+#    #+#             */
/*   Updated: 2025/01/23 15:01:42 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

char		*get_next_line(int fd);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(char *src);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
