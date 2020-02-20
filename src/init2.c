/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init2.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 13:51:45 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 13:51:46 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

int		init_mtx_state(t_bfs *bfs, t_map map)
{
	int i;
	int j;

	j = -1;
	while (++j < map.inf.size_name)
	{
		if (!(bfs->mtx_state[j] = (int *)malloc(sizeof(int) * (bfs->nb_paths))))
			return (FAILURE);
		i = -1;
		while (++i < bfs->nb_paths)
			bfs->mtx_state[j][i] = -1;
	}
	return (SUCCESS);
}

int		init_states_to_paths(t_bfs *bfs, t_tripaths *tri, t_temp_paths *tp)
{
	tri->paths[tp->act_path][tp->i_stp].size =
		bfs->mtx_state[tp->sub_ends[tp->sub_paths]][tp->act_path] + 2;
	if (!(tri->paths[tp->act_path][tp->i_stp].path = (int *)malloc(sizeof(int) *
		tri->paths[tp->act_path][tp->i_stp].size)))
		return (FAILURE);
	tp->step = bfs->mtx_state[tp->sub_ends[tp->sub_paths]][tp->act_path];
	tri->paths[tp->act_path][tp->i_stp].path
		[tri->paths[tp->act_path][tp->i_stp].size - 1] = bfs->end;
	tri->paths[tp->act_path][tp->i_stp].path
		[tri->paths[tp->act_path][tp->i_stp].size - 2] =
		tp->sub_ends[tp->sub_paths];
	tp->prev = tp->sub_ends[tp->sub_paths];
	return (1);
}

int		init_tri_to_res(t_res *res, t_tripaths tri, t_bfs bfs, t_rank *rank)
{
	res->used_paths = ft_used_paths(tri.nb_subs, bfs.nb_paths, LIMIT_PATHS);
	if (!(rank->ranking[0] = (int *)malloc(sizeof(int) * res->used_paths)))
		return (0);
	if (!(rank->ranking[1] = (int *)malloc(sizeof(int) * res->used_paths)))
		return (0);
	if (!(rank->ranking[2] = (int *)malloc(sizeof(int) * res->used_paths)))
		return (0);
	ft_import_coord(tri, bfs, rank, LIMIT_PATHS);
	ft_tri_shell(rank, res->used_paths);
	if (!(res->paths = (int **)malloc(sizeof(int *) * res->used_paths)))
		return (0);
	if (!(res->size_paths = (int *)malloc(sizeof(int) * res->used_paths)))
		return (0);
	return (1);
}
