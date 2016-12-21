/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprevot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:38:32 by mprevot           #+#    #+#             */
/*   Updated: 2016/12/20 19:52:56 by mprevot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_buff		*ft_get_buff(fd)
{
	static t_buff	*lstbuff;
	t_buff			*buff;
	t_buff			*new;
	t_buff			*last;

	buff = lstbuff;
	while (buff)
	{
		if (buff->fd == fd)
			return (buff);
		last = buff;
		buff = buff->next;
	}
	new = (t_buff *)malloc(sizeof(t_buff));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->n = 0;
	new->buff = ft_strnew(0);
	new->buff_start = new->buff;
	new->next = NULL;
	if (new->buff == NULL)
		return (NULL);
	if (!lstbuff)
		lstbuff = new;
	else
		last->next = new;
	return (new);
}

char	*ft_find_line(t_buff *buff)
{
	char	*rest;
	char	*tmp;
	int		l;

	rest = ft_strchr(buff->buff, '\n');
	if(rest == NULL)
	{
		tmp = ft_strnew(BUFF_SIZE);
		l = read(buff->fd, tmp, BUFF_SIZE);
		if (l > 0)
		{
			buff->buff = ft_strjoin(buff->buff, tmp);
			free(buff->buff_start);
			buff->buff_start = buff->buff;
			free(tmp);
			return (ft_find_line(buff));
		}
		else if (l == 0)
		{
			buff->n = 1;
			return (buff->buff);
		}
		return (NULL);
	}
	else
	{
		*rest = '\0';
		tmp = buff->buff;
		buff->buff = ++rest;
		return (ft_strdup(tmp));
	}
}

int		get_next_line(const int fd, char **line)
{
	t_buff	*buff;

	if (fd < 0 || line == NULL)
		return (-1);
	buff = ft_get_buff(fd);
	if (!buff)
	{
		return (-1);
	}
	if (buff->n)
		return (0);
	*line = ft_find_line(buff);
	if (*line == NULL)
		return (-1);
	if (buff->n && **line == '\0')
		return (0);
	return (1);	
}