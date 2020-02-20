/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bfs2.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 15:51:35 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 13:50:08 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

void	remove_room_queue(t_bfs *bfs)
{
	int x;
	int path;

	path = 0;
	while (path < bfs->nb_paths)
	{
		x = 0;
		while (x < bfs->nb_paths)
		{
			bfs->queue[path][x] = bfs->queue[path][x + 1];
			x++;
		}
		path++;
	}
}

void	ft_del_rooms(t_bfs *bfs, t_temp_bfs temp)
{
	int		i;
	int		y;

	i = temp.size_queue;
	y = -1;
	while (bfs->queue[temp.actual_path][i] != -1)
		i++;
	if (i < 2 * temp.size_queue - 1)
	{
		while (++y < temp.size_queue)
		{
			bfs->queue[temp.actual_path][y] =
				bfs->queue[temp.actual_path][temp.size_queue + y];
			bfs->queue[temp.actual_path][temp.size_queue + y] = -1;
		}
	}
	else
	{
		while (++y < temp.size_queue)
		{
			bfs->queue[temp.actual_path][y] =
				bfs->queue[temp.actual_path][i + y - temp.size_queue];
			bfs->queue[temp.actual_path][i + y - temp.size_queue] = -1;
		}
	}
}

void	ft_delactual_room(t_bfs *bfs, int path, t_temp_bfs temp)
{
	int		i;
	int		save_room;

	i = 0;
	while (bfs->queue[temp.actual_path][i + 1] != -1)
		i = i + 1;
	save_room = bfs->queue[temp.actual_path][i];
	bfs->queue[path][i] = -1;
	bfs->queue[temp.actual_path][temp.i_queue] = save_room;
}

void	ft_pre_roomto_queue(t_bfs *bfs, t_temp_bfs temp, int room, int path)
{
	while (bfs->queue[path][temp.i_queue] != -1)
		temp.i_queue++;
	bfs->queue[path][temp.i_queue] = room;
}

void	ft_freequeue(t_bfs *bfs)
{
	int		i;

	i = -1;
	while (++i < bfs->nb_paths)
		free((bfs->queue[i]));
	free((bfs->queue));
	bfs->queue = NULL;
}
