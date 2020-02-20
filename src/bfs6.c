/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bfs6.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 05:10:42 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 13:50:16 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

static void	path_occurence(t_res *res, t_sort *sort, t_dispa *dis, int step)
{
	if (dis->error == 1)
	{
		sort->first_path[sort->nb_path_first] = res->paths[dis->i + step];
		sort->new_size_first[sort->nb_path_first] =
			res->size_paths[dis->i + step];
		sort->nb_path_first++;
	}
	else if ((res->size_paths[dis->occurrence + step] >
				res->size_paths[dis->i + step]))
	{
		ft_bzero(&sort->first_path[dis->occurrence],
				res->size_paths[dis->occurrence + step]);
		sort->first_path[dis->occurrence] = res->paths[dis->i + step];
		sort->new_size_first[dis->occurrence] = res->size_paths[dis->i + step];
	}
	else if (sort->new_size_first[dis->occurrence] >
			res->size_paths[dis->i + step])
	{
		ft_bzero(&sort->first_path[dis->occurrence],
				res->size_paths[dis->occurrence + step]);
		sort->first_path[dis->occurrence] = res->paths[dis->i + step];
		sort->new_size_first[dis->occurrence] = res->size_paths[dis->i + step];
	}
}

static void	search_occurence(t_res *res, t_sort *sort, t_dispa *dis, int step)
{
	dis->count = -1;
	dis->error = 1;
	while (++dis->count < sort->nb_path_first)
	{
		dis->j = 0;
		while (++dis->j < res->size_paths[dis->i + step] - 1)
		{
			dis->k = -1;
			while (++dis->k < sort->new_size_first[dis->count] - 1)
			{
				if (res->paths[dis->i + step][dis->j] ==
						sort->first_path[dis->count][dis->k])
				{
					dis->occurrence = dis->count;
					dis->error++;
				}
			}
		}
	}
}

static void	clear_path1(t_res *res, t_sort *sort, int step)
{
	t_dispa		dis;

	dis.i = 0;
	dis.occurrence = 0;
	sort->nb_path_first = 1;
	sort->first_path[0] = res->paths[step];
	sort->new_size_first[0] = res->size_paths[step];
	while (++dis.i < res->used_paths - step)
	{
		search_occurence(res, sort, &dis, step);
		path_occurence(res, sort, &dis, step);
	}
}

int			ft_tri_paths(t_res *res, t_sort *sort, int nb_line, int total_ants)
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
	while (++step < res->used_paths && step < TRI)
	{
		clear_path1(res, sort, step);
		if ((cur_nb = ft_nb_line(total_ants, sort, 0, 0)) <= nb_line)
			return (SUCCESS);
		if (cur_nb < better_nb)
		{
			better_step = step;
			better_nb = cur_nb;
		}
	}
	clear_path1(res, sort, better_step);
	return (1);
}
