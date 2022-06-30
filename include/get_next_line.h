/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:15:10 by lhafsi            #+#    #+#             */
/*   Updated: 2022/06/30 14:57:13 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../lib/libft/libft.h"
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

char	*ft_strjoin(char *s1, char *s2);
char	*ft_free(char *str);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
int		ft_endofline(char *txt);
char	*get_next_line(int fd);
char	*ft_line(char *txt);
char	*ft_save(char *txt);

#endif
