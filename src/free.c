/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 13:51:18 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 13:51:19 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

void		free_simple(t_bfs *bfs, t_map *map, t_res *res)
{
	free(res->paths);
	free(res->size_paths);
	free(bfs->mtx_diago);
	free(bfs->mtx_state);
	free(map->matrix);
	free(map->map_co);
	free(map->map_link);
	free(map->map_name);
	free(bfs->queue);
	bfs->mtx_diago = NULL;
	bfs->mtx_state = NULL;
	bfs->queue = NULL;
	map->matrix = NULL;
	res->paths = NULL;
}

void		free_all(t_bfs *bfs, t_map *map, t_res *res)
{
	int i;

	i = -1;
	while (++i < bfs->nb_paths)
		free(bfs->queue[i]);
	i = -1;
	while (++i < map->inf.size_link)
		free(map->map_link[i]);
	i = -1;
	while (++i < res->used_paths)
		free(res->paths[i]);
	i = -1;
	while (++i < map->inf.size_name)
	{
		free(bfs->mtx_diago[i]);
		free(bfs->mtx_state[i]);
		free(map->matrix[i]);
		free(map->map_name[i]);
		free(map->map_co[i]);
	}
	free_simple(bfs, map, res);
}

void		clear_display(t_file_display **f_dis)
{
	t_file_display *f_dis_temp;

	f_dis_temp = *f_dis;
	while (*f_dis)
	{
		f_dis_temp = (*f_dis)->next;
		free((*f_dis)->line);
		free(*f_dis);
		*f_dis = f_dis_temp;
	}
}

void		clear(t_name **name, t_link **link, t_file_display **f_dis)
{
	t_name *name_temp;
	t_link *link_temp;

	name_temp = *name;
	link_temp = *link;
	while (name_temp)
	{
		name_temp = (*name)->next;
		free((*name)->name);
		free(*name);
		*name = name_temp;
	}
	while (*link)
	{
		link_temp = (*link)->next;
		free((*link)->link);
		free(*link);
		*link = link_temp;
	}
	clear_display(f_dis);
}

void		free_tri(t_tripaths *tri, t_bfs *bfs)
{
	int		i;
	int		j;

	i = -1;
	while (++i < bfs->nb_paths)
	{
		j = -1;
		while (++j < tri->nb_subs[i])
		{
			free(tri->paths[i][j].path);
		}
		free(tri->paths[i]);
	}
	free(tri->nb_subs);
	free(tri->paths);
}
