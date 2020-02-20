/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 13:52:01 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 15:17:17 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

int		insert_line_lst(t_map *m, char **line, t_file_display **dis, int *c)
{
	if (*c == 0)
	{
		if (!(*dis = insert_line(*line)))
			return (-1);
		m->tmp_f_dis = *dis;
		*c = 1;
	}
	else if (*c == 1)
	{
		if (!(m->tmp_f_dis->next = insert_line(*line)))
			return (-1);
		m->tmp_f_dis = m->tmp_f_dis->next;
	}
	return (1);
}

int		ft_get_map_size(t_map *m, t_name **name, t_link **l)
{
	if (m->inf.start == -1 || m->inf.end == -1 || !m->tmp_link || !m->tmp_name)
		return (-1);
	m->inf.size_name = list_len(*name, *l, 0);
	m->inf.size_link = list_len(*name, *l, 1);
	return (1);
}

int		check_name_line(t_name **name, t_map *map, char *line, char **split)
{
	if (map->cpt.j == 0 && line[0] != '#' && line[0] != 'L' &&
			(count_word(line, ' ') >= 1 && !(ft_strchr(line, '-'))))
	{
		split = ft_strsplit(line, ' ');
		if (!split[1] || !split[2] || count_word(line, ' ') > 3 ||
				!check_str_number(split[1]) || !check_str_number(split[2]))
			return (ft_free_split(&split, count_word(line, ' ')));
		if (check_start_name(map, name, split) != 1)
			return (ft_free_split(&split, count_word(line, ' ')));
		free(split[0]);
		free(split[1]);
		free(split[2]);
		free(split);
		map->cpt.i++;
	}
	else if (line[0] == 'L')
		return (-1);
	if (map->cpt.j != 0 && line[0] != '#' && line[0] != 'L' &&
		(count_word(line, '-') == 1 && !(ft_strchr(line, '-'))))
		return (-1);
	return (1);
}

int		check_start_end(t_map *map, char **l, t_file_display **f_dis)
{
	int		chose;

	chose = 1;
	if ((ft_strstr(*l, "##start") || ft_strstr(*l, "##end")) && map->cpt.j == 0)
	{
		if (ft_strstr(*l, "##start"))
			if (check_start(map) != 1)
				return (-1);
		if (ft_strstr(*l, "##end"))
			if (check_end(map) != 1)
				return (-1);
		ft_strdel(&(*l));
		get_next_line(0, &(*l));
		if (!insert_line_lst(map, l, f_dis, &chose))
			return (-1);
		if (!(map->cpt.j == 0 && *l[0] != '#' && *l[0] != 'L' &&
					(count_word(*l, '-') == 1 && !(ft_strchr(*l, '-')))))
			map->cpt.error = 1;
	}
	return (1);
}

int		parser(t_name **name, t_link **l, t_map *m, t_file_display **f_dis)
{
	char	*line;
	char	**split;
	int		chose;

	split = NULL;
	line = NULL;
	chose = 1;
	if ((check_ant_line(m, &line, f_dis) != 1))
		return (-1);
	while (get_next_line(0, &line))
	{
		if (!insert_line_lst(m, &line, f_dis, &chose))
			return (-1);
		if (line[0] == '\0' || count_word(line, '-') > 2)
			m->cpt.error = 1;
		if ((check_start_end(m, &line, f_dis) != 1)
			|| (check_name_line(name, m, line, split) != 1)
			|| (check_link_line(l, m, line) != 1))
			return (free_line(&line));
		get_line_expected(m, line);
		ft_strdel(&line);
		if (m->cpt.error == 1)
			return (-1);
	}
	return (ft_get_map_size(m, name, l)) == 1 ? 1 : -1;
}
