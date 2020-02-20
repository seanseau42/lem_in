/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 13:51:25 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 13:51:28 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

t_link			*insert_link(char *val, int i)
{
	t_link	*elem;

	if (!(elem = malloc(sizeof(t_link))))
		return (NULL);
	if (!(elem->link = ft_strdup(val)))
		return (NULL);
	elem->index = i;
	elem->next = NULL;
	return (elem);
}

t_name			*insert_name(char **val, int i)
{
	t_name	*elem;

	if (!(elem = malloc(sizeof(t_name))))
		return (NULL);
	if (!(elem->name = ft_strdup(val[0])))
		return (NULL);
	elem->co_x = ft_atoi(val[1]);
	elem->co_y = ft_atoi(val[2]);
	elem->index = i;
	elem->next = NULL;
	return (elem);
}

t_file_display	*insert_line(char *line)
{
	t_file_display	*elem;

	if (!(elem = malloc(sizeof(t_file_display))))
		return (NULL);
	if (!(elem->line = ft_strdup(line)))
		return (NULL);
	elem->next = NULL;
	return (elem);
}

int				list_len(t_name *name, t_link *link, int chose)
{
	t_name	*tmp_name;
	t_link	*tmp_link;
	int		n;

	n = 0;
	tmp_name = name;
	tmp_link = link;
	if (chose == 1)
		n = 0;
	if (chose == 0 || chose == 2)
		while (tmp_name)
		{
			tmp_name = tmp_name->next;
			n++;
		}
	if (chose == 1 || chose == 2)
		while (tmp_link)
		{
			tmp_link = tmp_link->next;
			n++;
		}
	return (n);
}

void			print_list(t_name *name, t_link *link)
{
	t_name	*tmp_name;
	t_link	*tmp_link;

	tmp_name = name;
	tmp_link = link;
	while (tmp_name)
	{
		ft_printf("%d : [%s]\n", tmp_name->index, tmp_name->name);
		tmp_name = tmp_name->next;
	}
	while (tmp_link)
	{
		ft_printf("%d : [%s]\n", tmp_link->index, tmp_link->link);
		tmp_link = tmp_link->next;
	}
}
