/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:13:19 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/19 18:48:22 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <libc.h>

int	main()
{
	int	fd;
	char *str;
	int i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (get_next_line(fd, &str))
		ft_putendl(str);
	return (0);
}

