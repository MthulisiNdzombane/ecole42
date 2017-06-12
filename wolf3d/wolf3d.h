/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprevot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 14:17:48 by mprevot           #+#    #+#             */
/*   Updated: 2017/06/10 14:17:50 by mprevot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include "libft/libft.h"

# define WIN_X 1600
# define WIN_Y 900

# define MAP_SIZE 144
# define MAP_W 12
# define MAP_BLOCK	'#'
# define MAP_START	'*'
# define MAP_STOP	'S'
# define MAP_EMPTY	'.'

# define MINIMAP_X 50
# define MINIMAP_Y 550
# define MINIMAP_BLOCK_SIZE 20
# define MINIMAP_USER_SIZE  3
# define MINIMAP_COLOR 100

typedef struct			s_map
{
	void				*win;
	void				*mlx;
	void				*img;
	char				*imgstr;
	int					imgstrlen;
	char				mapstr[MAP_SIZE + 1];
	float				user_posx;
	float				user_posy;
	float				user_deg;
}						t_map;

#endif