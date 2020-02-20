/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bfs7.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 05:21:55 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 15:37:42 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

static void	search_occur_path(t_res *res, t_sort *sort, t_dispa *dis, int step)
{
	if (dis->i < 5)
		dis->i = actu_disi(dis->i, step);
	dis->count = -1;
	dis->error = 0;
	while (++dis->count < sort->nb_path_first)
	{
		dis->j = 0;
		while (++dis->j < res->size_paths[dis->i] - 1)
		{
			dis->k = -1;
			while (++dis->k < sort->new_size_first[dis->count] - 1 &&
					!dis->error)
				if (res->paths[dis->i][dis->j] ==
						sort->first_path[dis->count][dis->k])
					dis->error++;
		}
	}
	if (!dis->error)
	{
		sort->first_path[sort->nb_path_first] = res->paths[dis->i];
		sort->new_size_first[sort->nb_path_first] = res->size_paths[dis->i];
		sort->nb_path_first++;
	}
}

static void	clear_path(t_res *res, t_sort *sort, int step)
{
	t_dispa		dis;

	dis.i = actu_disi(0, step);
	sort->first_path[0] = res->paths[actu_disi(0, step)];
	sort->new_size_first[0] = res->size_paths[actu_disi(0, step)];
	sort->nb_path_first = 1;
	while (++dis.i < res->used_paths)
		search_occur_path(res, sort, &dis, step);
}

int			ft_nb_line(int total_ants, t_sort *sort, int ant, int index)
{
	int i;

	i = 0;
	while (i < sort->nb_path_first)
	{
		if (index >= sort->new_size_first[i])
			ant++;
		if (ant == total_ants)
			return (index);
		i++;
	}
	return (ft_nb_line(total_ants, sort, ant, index + 1));
}

int			ft_tri_big(t_res *res, t_sort *sort, int nb_line, int total_ants)
{
	int			better_step;
	int			better_nb;
	int			cur_nb;
	int			step;

	better_nb = 2147483645;
	step = -1;
	if (!(sort->new_size_first = malloc(sizeof(int) * res->used_paths)))
		return (0);
	if (!(sort->first_path = malloc(sizeof(int*) * res->used_paths)))
		return (0);
	while (++step < 32)
	{
		clear_path(res, sort, step);
		if ((cur_nb = ft_nb_line(total_ants, sort, 0, 0)) <= nb_line)
			return (SUCCESS);
		if (cur_nb < better_nb)
		{
			better_step = step;
			better_nb = cur_nb;
		}
	}
	if (better_step != step - 1)
		clear_path(res, sort, better_step);
	return (1);
}

int			is_path_possible(t_bfs *bfs)
{
	int i;
	int path;

	i = -1;
	path = -1;
	while (++i < bfs->size_diago)
	{
		if (bfs->mtx_diago[bfs->end][i])
		{
			path = -1;
			while (++path < bfs->nb_paths)
			{
				if (bfs->mtx_state[i][path] > 0)
					return (1);
			}
		}
	}
	return (0);
}
