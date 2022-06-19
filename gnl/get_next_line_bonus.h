/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Louisa <Louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:15:10 by lhafsi            #+#    #+#             */
/*   Updated: 2022/01/31 15:42:41 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# ifndef FD_SETSIZE
#  define FD_SETSIZE 1024
# endif

size_t	ft_strlen(char const *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_free(char *str);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
int		ft_endofline(char *txt);
char	*get_next_line(int fd);
char	*ft_line(char *txt);
char	*ft_save(char *txt);

#endif
