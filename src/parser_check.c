/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser_check.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 13:52:07 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 15:16:35 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

int		check_start(t_map *map)
{
	if (map->cpt.yes_start != 0)
		return (-1);
	map->inf.start = map->cpt.i;
	map->cpt.yes_start = 1;
	return (1);
}

int		check_end(t_map *map)
{
	if (map->cpt.yes_end != 0)
		return (-1);
	map->inf.end = map->cpt.i;
	map->cpt.yes_end = 1;
	return (1);
}

int		check_start_name(t_map *map, t_name **name, char **split)
{
	if (map->cpt.start_name)
	{
		if (!(*name = insert_name(split, 0)))
			return (-1);
		map->cpt.start_name = 0;
		map->tmp_name = *name;
	}
	else
	{
		if (!(map->tmp_name->next = insert_name(split, map->cpt.i)))
			return (-1);
		map->tmp_name = map->tmp_name->next;
	}
	return (1);
}

int		check_ant_line(t_map *map, char **l, t_file_display **f_dis)
{
	int		chose;

	chose = 0;
	while (get_next_line(0, &(*l)) && !(check_str_number(*l)) && *l[0] == '#')
	{
		if (!insert_line_lst(map, l, f_dis, &chose))
			return (-1);
		if (ft_strstr(*l, "##start") || ft_strstr(*l, "##end"))
		{
			ft_strdel(&(*l));
			return (-1);
		}
		ft_strdel(&(*l));
	}
	if (!*l || !insert_line_lst(map, l, f_dis, &chose))
		return (-1);
	if (l[0] == '\0' || !check_str_number(*l))
		map->cpt.error = 1;
	map->inf.nb_fourmi = ft_atoi(*l);
	ft_strdel(&(*l));
	if (map->inf.nb_fourmi <= 0)
		return (-1);
	return (1);
}

int		check_link_line(t_link **link, t_map *map, char *line)
{
	if (line[0] != '#' && line[0] != 'L' && count_word(line, ' ') == 1 &&
			count_word(line, '-') == 2 && ft_strchr(line, '-'))
	{
		if (map->cpt.start_link)
		{
			if (!(*link = insert_link(line, 0)))
				return (-1);
			map->cpt.start_link = 0;
			map->tmp_link = *link;
		}
		else
		{
			if (!(map->tmp_link->next = insert_link(line, map->cpt.j)))
				return (-1);
			map->tmp_link = map->tmp_link->next;
		}
		map->cpt.j++;
	}
	return (1);
}
