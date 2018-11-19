/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:13:19 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/19 16:11:57 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <libc.h>

int	main()
{
	int	fd;
	char **str;
	int i;

	i = 0;
	str = malloc(sizeof(*str) * 100);
	fd = open("test.txt", O_RDONLY);
	ft_putnbr(get_next_line(fd, &str[0]));
	ft_putchar(10);
	ft_putendl(str[0]);
	ft_putnbr(get_next_line(fd, &str[1]));
	ft_putchar(10);
	ft_putendl(str[1]);
	ft_putnbr(get_next_line(fd, &str[2]));
	ft_putchar(10);
	ft_putendl(str[2]);
	ft_putnbr(get_next_line(fd, &str[3]));
	ft_putchar(10);
	ft_putendl(str[3]);
	ft_putnbr(get_next_line(fd, &str[4]));
	ft_putchar(10);
	ft_putendl(str[4]);
	ft_putnbr(get_next_line(fd, &str[5]));
	ft_putchar(10);
	ft_putendl(str[5]);
	return (0);
}

