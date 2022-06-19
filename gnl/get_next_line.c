/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Louisa <Louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:13:47 by lhafsi            #+#    #+#             */
/*   Updated: 2022/01/31 15:19:21 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *txt)
{
	char	*line;
	int		i;

	i = 0;
	if (txt[i] == 0)
		return (NULL);
	while (txt[i] && txt[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (txt[i] && txt[i] != '\n')
	{
		line[i] = txt[i];
		i++;
	}
	if (txt[i] == '\n')
	{
		line[i] = txt[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save(char *txt)
{
	char	*str;
	int		i;
	int		j;

	i = ft_endofline(txt) + 1;
	if (txt[i - 1] == '\0')
	{
		free(txt);
		return (NULL);
	}
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(txt) - i + 2));
	if (!str)
		return (NULL);
	while (txt[i])
	{
		str[j] = txt[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(txt);
	return (str);
}

char	*ft_read(int fd, char *txt)
{
	char	*buffer;
	int		ret;

	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	ret = 1;
	while (ret != 0 && !ft_strchr(txt, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[ret] = '\0';
		txt = ft_strjoin(txt, buffer);
	}
	free(buffer);
	return (txt);
}

char	*get_next_line(int fd)
{
	static char	*txt = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	txt = ft_read(fd, txt);
	if (!txt)
		return (NULL);
	line = ft_line(txt);
	txt = ft_save(txt);
	return (line);
}
