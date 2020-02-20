/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   setup_bfs.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 13:52:21 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 14:49:12 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

void		ft_nb_paths(t_map map, t_bfs *bfs)
{
	int		i;

	i = -1;
	while (++i < map.inf.size_name)
	{
		if (map.matrix[map.inf.start][i] == 1)
			map.cpt.nb1++;
		if (map.matrix[map.inf.end][i] == 1)
			map.cpt.nb2++;
	}
	bfs->finish = map.cpt.nb1 * map.cpt.nb2;
	if (map.cpt.nb1 < map.cpt.nb2)
	{
		bfs->nb_paths = map.cpt.nb1;
		bfs->end_links = map.cpt.nb2;
		bfs->start = map.inf.start;
		bfs->end = map.inf.end;
	}
	else
	{
		bfs->nb_paths = map.cpt.nb2;
		bfs->end_links = map.cpt.nb1;
		bfs->start = map.inf.end;
		bfs->end = map.inf.start;
	}
}

int			ft_nb_paths_start(t_map map)
{
	int		i;
	int		nb;

	nb = 0;
	i = -1;
	while (++i < map.inf.size_name)
		if (map.matrix[map.inf.start][i] == 1)
			nb++;
	return (nb);
}

int			ft_setprealgo(t_map map, t_bfs *bfs)
{
	int		i;
	int		j;

	j = -1;
	i = -1;
	ft_nb_paths(map, bfs);
	if (!(bfs->mtx_diago = (int **)malloc(sizeof(int *) * map.inf.size_name)))
		return (FAILURE);
	while (++i < map.inf.size_name)
	{
		if (!(bfs->mtx_diago[i] = malloc(sizeof(int) * map.inf.size_name)))
			return (FAILURE);
		bfs->mtx_diago[i] = ft_intcpy(bfs->mtx_diago[i],
			map.matrix[i], map.inf.size_name);
	}
	if (!(bfs->mtx_state = malloc(sizeof(int *) * map.inf.size_name)))
		return (FAILURE);
	init_mtx_state(bfs, map);
	bfs->size_diago = map.inf.size_name;
	bfs->found_paths = 0;
	if (!(ft_init_queue(bfs, -1)))
		return (FAILURE);
	return (SUCCESS);
}
