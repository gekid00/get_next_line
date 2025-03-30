/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:53:46 by rbourkai          #+#    #+#             */
/*   Updated: 2024/12/09 19:16:03 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*alloc_stash(char *stash, char *buffer)
{
	char	*new_stash;

	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
	new_stash = ft_strjoin(stash, buffer);
	if (!new_stash)
		return (free(stash), NULL);
	free(stash);
	return (new_stash);
}

static char	*extract_line(char **stash)
{
	char	*line;
	char	*temp;
	char	*newline_pos;
	size_t	line_len;

	if (!*stash || !**stash)
		return (NULL);
	newline_pos = ft_strchr(*stash, '\n');
	if (!newline_pos)
		return (line = ft_strdup(*stash), free(*stash), *stash = NULL, line);
	line_len = newline_pos - *stash + 1;
	line = malloc(line_len + 1);
	if (!line)
		return (free(*stash), *stash = NULL, NULL);
	ft_memmove(line, *stash, line_len);
	line[line_len] = '\0';
	temp = ft_strdup(newline_pos + 1);
	if (!temp)
		return (free(line), free(*stash), *stash = NULL, NULL);
	return (free(*stash), *stash = temp, line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(stash), stash = NULL, NULL);
		buffer[bytes_read] = '\0';
		if (bytes_read == 0 && (!stash || *stash == '\0'))
			return (free(buffer), free(stash), stash = NULL, NULL);
		stash = alloc_stash(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (free(buffer), extract_line(&stash));
}
