/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_algo.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 21:22:47 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 13:51:09 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

int		nb_ant_int_path(t_map map, t_sort *sort, int ant, int index)
{
	int i;

	i = 0;
	while (i < sort->nb_path_first)
	{
		if (index >= sort->new_size_first[i])
		{
			sort->dispache[i]++;
			ant++;
		}
		if (ant == map.inf.nb_fourmi)
			return (index);
		i++;
	}
	return (nb_ant_int_path(map, sort, ant, index + 1));
}

int		dispache_ant(t_map map, t_sort *sort, int nb_ligne)
{
	t_dispa		dis;

	if (init_dis(&dis, map, sort) != 1)
		return (-1);
	while (dis.l < nb_ligne)
	{
		if ((dis.tmp * sort->nb_path_first) <= map.inf.nb_fourmi)
			dis.ant_cross_max = dis.tmp * sort->nb_path_first;
		if (dis.ant_cross + dis.ant_finish == map.inf.nb_fourmi - dis.reste + 1)
			dis.ant_cross_max += dis.reste;
		display_print(&dis, sort, map);
		dis.p = -1;
		while (++dis.p < sort->nb_path_first)
			dis.start_path[dis.p] = 0;
		if (dis.l + 1 != nb_ligne)
			ft_printf("\n");
		dis.space = 1;
		dis.l++;
	}
	free(dis.status_ant);
	free(dis.status_path);
	free(dis.start_path);
	free(dis.status_partion);
	free(sort->new_size_first);
	return (0);
}

int		select_tri_path(t_map map, t_res *res, t_sort *sort)
{
	if (map.line_expected > 0 && map.inf.size_name > 300)
	{
		if (!ft_tri_big(res, sort, map.line_expected, map.inf.nb_fourmi))
			return (0);
	}
	else if (map.line_expected > 0)
	{
		if (!ft_tri_paths(res, sort, map.line_expected, map.inf.nb_fourmi))
			return (0);
	}
	else
	{
		clear_path2(res, sort);
		free(sort->second_path);
		free(sort->new_size_second);
	}
	return (1);
}

int		display_algo(t_map map, t_res *res)
{
	t_sort	sort;
	int		i;
	int		nb_line;

	if ((select_tri_path(map, res, &sort)) == 0)
		return (0);
	if (!(sort.dispache = malloc(sizeof(int) * sort.nb_path_first)))
		return (0);
	i = -1;
	while (++i < sort.nb_path_first)
		sort.dispache[i] = 0;
	nb_line = nb_ant_int_path(map, &sort, 0, 0);
	dispache_ant(map, &sort, nb_line);
	free(sort.dispache);
	free(sort.first_path);
	if (map.line_expected > 0)
		ft_printf("Number of lines required: %d | Number of lines done: %d\n",
				map.line_expected, nb_line);
	return (0);
}
