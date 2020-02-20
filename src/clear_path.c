/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clear_path.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 13:50:46 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 16:16:38 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

static void			ft_occur2(t_dispa dis, t_sort *s, t_res *res)
{
	if (s->new_size_first[dis.occurrence] > res->size_paths[dis.i])
	{
		s->second_path[s->nb_path_second] = s->first_path[dis.occurrence];
		s->new_size_second[s->nb_path_second] = res->size_paths[dis.occurrence];
		ft_bzero(&s->first_path[dis.occurrence],
				res->size_paths[dis.occurrence]);
		s->first_path[dis.occurrence] = res->paths[dis.i];
		s->new_size_first[dis.occurrence] = res->size_paths[dis.i];
		s->nb_path_second++;
	}
	else
	{
		s->second_path[s->nb_path_second] = res->paths[dis.i];
		s->new_size_second[s->nb_path_second] = res->size_paths[dis.i];
		s->nb_path_second++;
	}
}

static void			ft_occur(t_dispa dis, t_sort *s, t_res *res)
{
	if (dis.error == 1)
	{
		s->first_path[s->nb_path_first] = res->paths[dis.i];
		s->new_size_first[s->nb_path_first] = res->size_paths[dis.i];
		s->nb_path_first++;
	}
	else if (res->size_paths[dis.occurrence] > res->size_paths[dis.i])
	{
		s->second_path[s->nb_path_second] = s->first_path[dis.occurrence];
		s->new_size_second[s->nb_path_second] = res->size_paths[dis.occurrence];
		ft_bzero(&s->first_path[dis.occurrence],
				res->size_paths[dis.occurrence]);
		s->first_path[dis.occurrence] = res->paths[dis.i];
		s->new_size_first[dis.occurrence] = res->size_paths[dis.i];
		s->nb_path_second++;
	}
	else
		ft_occur2(dis, s, res);
}

static void			get_occurence(t_dispa dis, t_sort *sort, t_res *res)
{
	while (dis.i < res->used_paths)
	{
		dis.count = -1;
		dis.error = 1;
		while (++dis.count < sort->nb_path_first)
		{
			dis.j = 0;
			while (++dis.j < res->size_paths[dis.i] - 1)
			{
				dis.k = -1;
				while (++dis.k < sort->new_size_first[dis.count] - 1)
				{
					if (res->paths[dis.i][dis.j] ==
							sort->first_path[dis.count][dis.k])
					{
						dis.occurrence = dis.count;
						dis.error++;
					}
				}
			}
		}
		ft_occur(dis, sort, res);
		dis.i++;
	}
}

int					clear_path2(t_res *res, t_sort *sort)
{
	t_dispa		dis;

	dis.i = 1;
	dis.occurrence = 0;
	if (init_sort(sort, res) != 1)
		return (-1);
	get_occurence(dis, sort, res);
	return (1);
}
