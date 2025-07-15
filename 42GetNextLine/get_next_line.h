/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:05:14 by msariasl          #+#    #+#             */
/*   Updated: 2022/12/20 22:05:16 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		newline_counter(char *raw_str);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_strchr(char *str, int c);
int		count_after_nl(char *raw_str);
char	*get_next_line(int fd);

#endif