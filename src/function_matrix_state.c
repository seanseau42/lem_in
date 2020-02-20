/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   function_matrix_state.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 13:51:32 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 14:46:58 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

int		ft_init_queue(t_bfs *bfs, int i)
{
	int		j;

	if (!(bfs->queue = (int **)malloc(sizeof(int *) * bfs->nb_paths)))
		return (FAILURE);
	while (++i < bfs->nb_paths)
	{
		j = -1;
		if (bfs->size_diago < 20)
		{
			if (!(bfs->queue[i] = (int *)malloc(sizeof(int) * 20)))
				return (FAILURE);
			while (++j < 20)
				bfs->queue[i][j] = -1;
		}
		else
		{
			if (!(bfs->queue[i] = (int *)malloc(sizeof(int) * bfs->size_diago)))
				return (FAILURE);
			while (++j < bfs->size_diago)
				bfs->queue[i][j] = -1;
		}
		bfs->queue[i][0] = bfs->start;
	}
	return (SUCCESS);
}

int		ft_foundroom(t_bfs *bfs, t_temp_bfs temp, int room)
{
	while (++room < bfs->size_diago)
	{
		if (bfs->mtx_diago[room][bfs->queue[temp.actual_path][temp.i_queue]]
			== 1)
		{
			if (bfs->mtx_state[room][temp.actual_path] == -1)
				return (room);
		}
	}
	return (-1);
}

int		ft_size_queue(t_bfs bfs, int path)
{
	int		nb;

	nb = 0;
	while (bfs.queue[path][nb] != -1)
		nb++;
	return (nb);
}

void	ft_roomto_queue(t_bfs *bfs, t_temp_bfs temp, int room)
{
	while (bfs->queue[temp.actual_path][temp.size_queue] != -1)
		temp.size_queue++;
	bfs->queue[temp.actual_path][temp.size_queue] = room;
}

void	ft_setqueue(t_bfs *bfs, t_temp_bfs temp, int step)
{
	int		next_room;

	next_room = -1;
	while ((next_room = ft_foundroom(bfs, temp, next_room)) != -1)
	{
		if (next_room == bfs->end)
		{
			bfs->found_paths++;
		}
		else
		{
			bfs->mtx_state[next_room][temp.actual_path] = step;
			ft_roomto_queue(bfs, temp, next_room);
		}
	}
}
