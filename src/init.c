/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 13:51:39 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 12:59:13 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

void	init_value(t_map *map)
{
	map->cpt.error = -1;
	map->inf.nb_fourmi = -1;
	map->cpt.i = 0;
	map->cpt.j = 0;
	map->inf.start = -1;
	map->inf.end = -1;
	map->cpt.start_name = 1;
	map->cpt.start_link = 1;
	map->cpt.yes_start = 0;
	map->cpt.yes_end = 0;
	map->n_mat.size_reduct = 0;
	map->cpt.nb1 = 0;
	map->cpt.nb2 = 0;
	map->ret = 0;
	map->tmp_link = 0;
}

void	init_matrix(t_map *map)
{
	map->mat.i = -1;
	map->mat.tmp_i = 0;
	map->mat.j = 0;
	map->mat.save_x = -1;
	map->mat.save_y = -1;
	map->mat.name1 = NULL;
	map->mat.name2 = NULL;
	map->mat.split = NULL;
	map->mat.start_link_end = 0;
	map->mat.end_link_start = 0;
}

int		init_sort(t_sort *sort, t_res *res)
{
	if (!(sort->new_size_first = malloc(sizeof(int) * res->used_paths)))
		return (0);
	if (!(sort->new_size_second = malloc(sizeof(int) * res->used_paths)))
		return (0);
	if (!(sort->first_path = malloc(sizeof(int*) * res->used_paths)))
		return (0);
	if (!(sort->second_path = malloc(sizeof(int*) * res->used_paths)))
		return (0);
	sort->nb_path_first = 1;
	sort->nb_path_second = 0;
	sort->first_path[0] = res->paths[0];
	sort->new_size_first[0] = res->size_paths[0];
	return (1);
}

void	dis_var(t_dispa *dis, t_map map, t_sort *sort)
{
	dis->reste = map.inf.nb_fourmi % sort->nb_path_first;
	dis->ant_finish = 0;
	dis->ant_cross_max = sort->nb_path_first;
	dis->l = 0;
	dis->tmp = 1;
	dis->ant_cross = 1;
	dis->m = 0;
	dis->n = 0;
	dis->space = 1;
}

int		init_dis(t_dispa *dis, t_map map, t_sort *sort)
{
	if (!(dis->status_path = malloc(sizeof(int) * map.inf.nb_fourmi)))
		return (0);
	if (!(dis->status_ant = malloc(sizeof(int) * map.inf.nb_fourmi)))
		return (0);
	if (!(dis->start_path = malloc(sizeof(int) * sort->nb_path_first)))
		return (0);
	if (!(dis->status_partion = malloc(sizeof(int) * sort->nb_path_first)))
		return (0);
	dis->i = -1;
	while (++dis->i < map.inf.nb_fourmi)
	{
		dis->status_path[dis->i] = -1;
		dis->status_ant[dis->i] = map.inf.start;
	}
	dis->i = -1;
	while (++dis->i < sort->nb_path_first)
	{
		dis->start_path[dis->i] = 0;
		dis->status_partion[dis->i] = 0;
	}
	dis_var(dis, map, sort);
	return (1);
}
