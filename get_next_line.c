/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:07:36 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/20 13:07:12 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include "stdio.h"

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
		ft_putstr("buffer est (entree) : ");
		printf("%s\n", current_fd->content); //debug
	while(!ft_strstr(current_fd->content, "\n") && (nb = read(fd, buff, BUFF_SIZE)))
	{
		ft_putstr("on lit\n");
		buff[nb] = 0;
		//on veut join avec notre buff dans la liste
		tmp = current_fd->content;
		if(!(current_fd->content = ft_strjoin(tmp, buff)))
		{
			free(*line);
			free(tmp);
			return (-1);
		}
		free(tmp);
	}
	printf("taille du buff est %zu\n", ft_strlen(current_fd->content));
	if(ft_strlen(current_fd->content) && !ft_strstr(current_fd->content, "\n"))
	{
		ft_putstr("on rentre dans le sans n\n");
		tmp = *line;
		if(!(*line = ft_strdup(current_fd->content)))
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
		ft_strclr(current_fd->content);
		//free(current_fd->content);
		//current_fd->content = NULL;
		//free(current_fd);
		//current_fd = NULL;
		//ft_putstr("buffer est (sortie 2)");
		//ft_putendl(current_fd->content); //debug
		return (1);
	}
	else if (*((char*)(current_fd->content)) != 0)
	{

		ft_putstr("on rentre dans le  n\n");
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
		//ft_putstr("buffer est (sortie 1)");
		//ft_putendl(current_fd->content); //debug
		return (1);
	}
		//ft_putstr("buffer est (sortie 3)");
		//ft_putendl(current_fd->content); //debug
	return (0);
}
