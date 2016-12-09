/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasiala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:05:40 by fmasiala          #+#    #+#             */
/*   Updated: 2016/12/07 14:43:16 by mprevot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_istetriminos(char *str)
{
	int		i;
	int		count;
	int		flag;

	i = 0;
	count = 0;
	flag = 0;
	while (i < 21)
	{
		if (str[i] == '#')
		{
			count++;
			if ((str[i + 1] == '#') || (str[i - 1] == '#') ||
				(str[i + 5] == '#') || (str[i - 5] == '#'))
			{
				flag++;
			}
		}
		i++;
	}
	if (flag == count)
		return (0);
	else
		return (-1);
}

int		count_cara(char *str)
{
	int		i;
	int		dot;
	int		diese;

	i = 0;
	dot = 0;
	diese = 0;
	if (str[i] == '\0')
		return (1);
	while (i < 21)
	{
		if (str[i] == '.')
			dot++;
		if (str[i] == '#')
			diese++;
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n' && str[i] != '\0')
			return (-1);
		i++;
	}
	if (dot == 12 && diese == 4 && (ft_istetriminos(str) == 0))
		return (0);
	else
		return (-1);
}

int		ft_open(char *path)
{
	int		fd;

	if ((fd = open(path, O_RDONLY)) == -1)
	{
		printf("%s : %s \n", strerror(errno), path);
		ft_putstr_fd("Open Error\n", 0);
		exit(2);
	}
	return (fd);
}

t_tetri	**reader(int argc, char *path, int *len)
{
	int		fd;
	int		check;
	int		nbr;
	char	*str;
	t_tetri **tetris;

	if (error(argc) == -1)
		exit(0);
	nbr = 0;
	*len = 0;
	check = 0;
	str = ft_strnew(21);
	fd = ft_open(path);
	while ((check = read(fd, str, 21)))
	{
		if (tetri_checker(check, str) != 0)
			exit(0);
		str[20] = '\0';
		nbr++;
	}
	tetris = creat_tetriminos(path, nbr);
	*len = nbr;
	close(fd);
	return (tetris);
}