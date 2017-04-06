/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnebie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 04:09:09 by gnebie            #+#    #+#             */
/*   Updated: 2017/03/07 04:09:11 by gnebie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			ft_int_error(const char *line)
{
	char	c;

	c = '\n';
	write(2, line, ft_strlen(line));
	write(2, &c, 1);
	return (-1);
}
