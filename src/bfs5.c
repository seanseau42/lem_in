/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bfs5.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/26 15:54:49 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 15:39:07 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

void	ft_tri_shell_proc(t_rank *rank)
{
	rank->val = rank->ranking[2][rank->l];
	rank->val1 = rank->ranking[1][rank->l];
	rank->val0 = rank->ranking[0][rank->l];
	rank->m = rank->l;
	while ((rank->m > (rank->step - 1)) &&
		rank->ranking[2][rank->m - rank->step] > rank->val)
	{
		rank->ranking[2][rank->m] = rank->ranking[2][rank->m - rank->step];
		rank->ranking[1][rank->m] = rank->ranking[1][rank->m - rank->step];
		rank->ranking[0][rank->m] = rank->ranking[0][rank->m - rank->step];
		rank->m = rank->m - rank->step;
	}
	rank->ranking[2][rank->m] = rank->val;
	rank->ranking[1][rank->m] = rank->val1;
	rank->ranking[0][rank->m] = rank->val0;
}

void	ft_tri_shell(t_rank *rank, int size)
{
	rank->step = 0;
	while (rank->step < size)
		rank->step = 3 * rank->step + 1;
	while (rank->step != 0)
	{
		rank->step = rank->step / 3;
		rank->l = rank->step - 1;
		while (++rank->l < size)
			ft_tri_shell_proc(rank);
	}
}

void	limit_paths_sup(t_tripaths tri, t_rank *rank, int limit)
{
	rank->k = -1;
	while (++rank->k < limit)
	{
		rank->j = -1;
		rank->size = 2147483645;
		while (++rank->j < tri.nb_subs[rank->i])
		{
			if (tri.paths[rank->i][rank->j].size < rank->size)
			{
				rank->size = tri.paths[rank->i][rank->j].size;
				rank->ranking[0][rank->i * limit + rank->k - rank->left] =
					rank->i;
				rank->ranking[1][rank->i * limit + rank->k - rank->left] =
					rank->j;
				rank->ranking[2][rank->i * limit + rank->k - rank->left] =
					tri.paths[rank->i][rank->j].size;
			}
		}
		tri.paths[rank->ranking[0][rank->i * limit + rank->k -
			rank->left]][rank->ranking[1][rank->i * limit + rank->k -
			rank->left]].size = rank->size = 2147483647;
	}
}

void	ft_import_coord(t_tripaths tri, t_bfs bfs, t_rank *rank, int limit)
{
	rank->i = -1;
	rank->left = 0;
	while (++rank->i < bfs.nb_paths)
	{
		if (tri.nb_subs[rank->i] <= limit)
		{
			rank->j = -1;
			while (++rank->j < tri.nb_subs[rank->i])
			{
				rank->ranking[0][rank->i * limit + rank->j - rank->left] =
					rank->i;
				rank->ranking[1][rank->i * limit + rank->j - rank->left] =
					rank->j;
				rank->ranking[2][rank->i * limit + rank->j - rank->left] =
					tri.paths[rank->i][rank->j].size;
			}
			rank->left += limit - tri.nb_subs[rank->i];
		}
		else
		{
			limit_paths_sup(tri, rank, limit);
		}
	}
}

int		ft_tri_to_res(t_res *res, t_tripaths tri, t_bfs bfs, t_map map)
{
	t_rank	rank;
	int		i;

	i = -1;
	if ((init_tri_to_res(res, tri, bfs, &rank)) == 0)
		return (0);
	while (++i < res->used_paths)
	{
		res->size_paths[i] = rank.ranking[2][i];
		if (!(res->paths[i] = (int *)malloc(sizeof(int) * res->size_paths[i])))
			return (0);
		if (bfs.start != map.inf.start)
			res->paths[i] = ft_rev_intcpy(res->paths[i],
					tri.paths[rank.ranking[0][i]][rank.ranking[1][i]].path,
					res->size_paths[i]);
		else
			res->paths[i] = ft_intcpy(res->paths[i],
					tri.paths[rank.ranking[0][i]][rank.ranking[1][i]].path,
					res->size_paths[i]);
	}
	free(rank.ranking[0]);
	free(rank.ranking[1]);
	free(rank.ranking[2]);
	return (1);
}
