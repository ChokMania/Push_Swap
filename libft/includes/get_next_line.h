/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:52:35 by judumay           #+#    #+#             */
/*   Updated: 2019/01/25 13:17:07 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE 1

int get_next_line(const int fd, char **line);

#endif
