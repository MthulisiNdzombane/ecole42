/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprevot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:11:37 by mprevot           #+#    #+#             */
/*   Updated: 2016/11/15 13:14:06 by mprevot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		main(void)
{
	char	str1[] = "coucou";

	if (ft_strchr(str1, 'u') != str1 + 2)
		return (10);
	if (ft_strchr(str1, 'z') != NULL)
		return (20);
	return (0);
}
