/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:13:19 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/20 11:55:43 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <libc.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int	fd;
	char *str;
	int i;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	while(get_next_line(fd, &str) > 0)
		ft_putendl(str);
	return (0);
}

