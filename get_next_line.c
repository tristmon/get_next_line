/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:07:36 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/20 10:39:23 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

static t_list	*get_fd(t_list **fd_list, int fd)
{
	t_list	*temp;

	temp = *fd_list;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	if(!(temp = ft_lstnew("\0", fd)))
		return (NULL);
	ft_lstadd(fd_list, temp);
	return (temp);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*fd_list;
	t_list 			*current_fd;
	int				nb;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0 ||
			!(*line = ft_strnew(1)))
		return (-1);
	if(!(current_fd = get_fd(&fd_list, fd)))
	{
		free(*line);
		return (-1);
	}
	while((nb = read(fd, buff, BUFF_SIZE)))
	{
		buff[nb] = 0;
		//on veut join avec notre buff dans la liste
		tmp = current_fd->content;
		if(!(current_fd->content = ft_strjoin(tmp, buff)))
		{
			free(*line);
			free(tmp);
			// peut etre liberer content
			return (-1);
		}
		free(tmp);
	}
	if(!ft_strstr(current_fd->content, "\n"))
	{
		tmp = *line;
		if(!(*line = ft_strdup(current_fd->content)))
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
		if (ft_strlen(*line))
		{
			free(current_fd->content);
			free(current_fd);
		}
	}
	else
	{
		tmp = *line;
		if(!(*line = ft_strndup(current_fd->content, ft_strstr(current_fd->content, "\n") - (char*)(current_fd->content))))
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
		tmp = current_fd->content;
		if(!(current_fd->content = ft_strdup(ft_strstr(current_fd->content, "\n") + 1)))
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
	}
	return (ft_strlen(*line) ? 1 : 0);
}
