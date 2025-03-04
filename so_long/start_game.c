/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:19:03 by wemubis_          #+#    #+#             */
/*   Updated: 2023/03/13 22:26:33 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_img(t_start *s)
{
	s->height = 64;
	s->width = 64;
	s->p_exit = "sprites/exit.xpm";
	s->floor = "sprites/floor.xpm";
	s->wall = "sprites/wall.xpm";
	s->item = "sprites/item.xpm";
	s->p_player = "sprites/player.xpm";
	s->img_exit = mlx_xpm_file_to_image(s->ptr, s->p_exit, &(s->width),
			&(s->height));
	s->img_floor = mlx_xpm_file_to_image(s->ptr, s->floor, &(s->width),
			&(s->height));
	s->img_wall = mlx_xpm_file_to_image(s->ptr, s->wall, &(s->width),
			&(s->height));
	s->img_item = mlx_xpm_file_to_image(s->ptr, s->item, &(s->width),
			&(s->height));
	s->img_player = mlx_xpm_file_to_image(s->ptr, s->p_player, &(s->width),
			&(s->height));
}

static void	init_window(t_start *sl)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(sl->map[0]);
	while (sl->map[i])
		i++;
	sl->win = mlx_new_window(sl->ptr, (len * sl->width), (i * sl->height),
			"So_long");
	if (!sl->win)
		end(sl);
	if (len > 3840 / sl->width || i > 2160 / sl->height)
	{
		ft_printf("Too big for 4K screen");
		end(sl);
	}
}

void	start_game(t_start *sl)
{
	sl->ptr = mlx_init();
	if (!sl->ptr)
		ft_free_error("mlx_init() failed", sl->map);
	open_img(sl);
	init_window(sl);
	mlx_loop_hook(sl->ptr, draw_map_on_win, sl);
	mlx_hook(sl->win, KeyPress, KeyPressMask, key_press, sl);
	mlx_hook(sl->win, DestroyNotify, ButtonPressMask, end, sl);
	mlx_loop(sl->ptr);
}
