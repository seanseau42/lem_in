/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bfs4.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 08:26:29 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 13:50:11 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

int			get_nb_sub_path(t_bfs *bfs, t_temp_paths tp,
		t_tripaths *tri, int path)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (++i < bfs->end_links)
	{
		if (bfs->mtx_state[tp.sub_ends[i]][path] != -1)
			count++;
	}
	tri->nb_subs[path] = count;
	return (count);
}

static int	ft_init_tripaths(t_tripaths *tri, t_bfs *bfs, t_temp_paths tp)
{
	int		i;
	int		j;

	i = -1;
	if (!((tri)->nb_subs = (int *)malloc(sizeof(int) * bfs->nb_paths)))
		return (FAILURE);
	if (!((tri)->paths = (t_path **)malloc(sizeof(t_path *) * bfs->nb_paths)))
		return (FAILURE);
	while (++i < bfs->nb_paths)
	{
		j = -1;
		if (!((tri)->paths[i] =
				malloc(sizeof(t_path) * get_nb_sub_path(bfs, tp, tri, i))))
			return (FAILURE);
		while (++j < (tri)->nb_subs[i])
		{
			(tri)->paths[i][j].path = NULL;
			(tri)->paths[i][j].size = 0;
		}
	}
	(tri)->count_paths = 0;
	return (SUCCESS);
}

static int	ft_sub_ends(t_bfs *bfs, t_temp_paths *tp)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!(tp->sub_ends = (int *)malloc(sizeof(int) * bfs->end_links)))
		return (FAILURE);
	while (++i < bfs->size_diago)
	{
		if (bfs->mtx_diago[bfs->end][i])
			tp->sub_ends[++j] = i;
	}
	tp->act_path = 0;
	tp->sub_paths = 0;
	tp->i_stp = 0;
	return (SUCCESS);
}

static int	ft_states_to_paths(t_bfs *bfs, t_tripaths *tri, t_temp_paths *tp)
{
	int		i_state;

	if (bfs->mtx_state[tp->sub_ends[tp->sub_paths]][tp->act_path] == -1)
		return (SUCCESS);
	if ((init_states_to_paths(bfs, tri, tp)) == FAILURE)
		return (FAILURE);
	while (--tp->step)
	{
		i_state = -1;
		while (++i_state < bfs->size_diago)
			if (bfs->mtx_state[i_state][tp->act_path]
					== tp->step && bfs->mtx_diago[i_state][tp->prev])
			{
				tri->paths[tp->act_path][tp->i_stp].path[tp->step] = i_state;
				tp->prev = i_state;
				break ;
			}
	}
	tri->paths[tp->act_path][tp->i_stp].path[0] = bfs->start;
	tp->i_stp++;
	tri->count_paths++;
	return (SUCCESS);
}

int			ft_takepaths(t_bfs *bfs, t_res *res, t_tripaths *tri)
{
	t_temp_paths	tp;
	int				i;

	i = -1;
	res = NULL;
	if (!ft_sub_ends(bfs, &tp))
		return (0);
	if (!ft_init_tripaths(tri, bfs, tp))
		return (0);
	tp.act_path = -1;
	while (++tp.act_path < bfs->nb_paths)
	{
		tp.i_stp = 0;
		tp.sub_paths = -1;
		while (++tp.sub_paths < bfs->end_links)
			if (!ft_states_to_paths(bfs, tri, &tp))
				return (0);
	}
	free(tp.sub_ends);
	return (1);
}
