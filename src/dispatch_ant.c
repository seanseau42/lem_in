/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dispatch_ant.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 13:50:39 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 13:50:41 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

void		print_space(t_dispa *dis)
{
	if (dis->space == 1)
		dis->space = 0;
	else
		ft_printf(" ");
}

void		last_ant_finish(t_dispa *dis, t_sort *sort, t_map map)
{
	if (dis->k + 1 < sort->new_size_first[dis->j] &&
			sort->first_path[dis->j][dis->k + 1] == map.inf.end)
	{
		dis->ant_finish++;
		dis->ant_cross--;
	}
}

int			partition_eq_dispache(t_dispa *d, t_map map, t_sort *sort)
{
	if (d->i < map.inf.nb_fourmi && (!(d->status_ant[d->i] == map.inf.start)))
		d->j = d->status_path[d->i];
	else
	{
		d->q = 0;
		d->p = 0;
		while (d->q < sort->nb_path_first)
		{
			if (d->start_path[d->q] == 0 && d->j != d->q &&
					d->status_partion[d->q] != sort->dispache[d->q])
			{
				d->p = 1;
				d->j = d->q;
				break ;
			}
			d->q++;
		}
		if (d->p != 1)
		{
			d->m = 1;
			d->i++;
			return (-1);
		}
	}
	return (1);
}

void		display_print2(t_dispa *dis, t_sort *sort, t_map map)
{
	while (dis->k < sort->new_size_first[dis->j])
	{
		if ((dis->i < map.inf.nb_fourmi) && sort->first_path[dis->j][dis->k] ==
	dis->status_ant[dis->i] && sort->first_path[dis->j][dis->k] != map.inf.end)
		{
			print_space(dis);
			if (dis->status_ant[dis->i] == map.inf.start)
			{
				dis->start_path[dis->n] = 1;
				dis->ant_cross++;
				dis->n++;
			}
			if (dis->status_ant[dis->i] == map.inf.start)
				dis->status_partion[dis->j]++;
			dis->status_ant[dis->i] = sort->first_path[dis->j][dis->k + 1];
			dis->status_path[dis->i] = dis->j;
			last_ant_finish(dis, sort, map);
			ft_printf("L%d-%s", dis->i + 1,
					map.map_name[dis->status_ant[dis->i]]);
			break ;
		}
		dis->k++;
	}
}

void		display_print(t_dispa *dis, t_sort *sort, t_map map)
{
	dis->m = 0;
	dis->i = 0;
	while (dis->i < dis->ant_cross_max)
	{
		dis->j = 0;
		dis->n = 0;
		while (dis->j < sort->nb_path_first)
		{
			if (dis->status_partion[dis->j] == sort->dispache[dis->j])
				if (partition_eq_dispache(dis, map, sort) == -1)
					break ;
			dis->k = 0;
			display_print2(dis, sort, map);
			dis->i++;
			dis->j++;
		}
		if (dis->i % sort->nb_path_first == 0)
			if (dis->i == sort->nb_path_first * dis->tmp && dis->tmp <=
					map.inf.nb_fourmi)
				dis->tmp++;
		if (dis->m == 1)
			break ;
	}
}
