/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprevot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:11:33 by mprevot           #+#    #+#             */
/*   Updated: 2016/11/29 13:26:27 by mprevot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>

int		main(void)
{
	int     out;
	int     p[2];
	char    sortie[100];
	char	str[] = "vive les gateaux extra-terrestres";
	char    str2[] = "vive les gateaux extra-terrestres\n";

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	ft_putendl(str);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, str2))
	{
		dup2(out, 1);
		return (10);
	}

	dup2(out, 1);
	return (0);
}
