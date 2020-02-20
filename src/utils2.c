/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 13:52:44 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 13:52:45 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

int		check_valid_co(int **tab, int len)
{
	int		i;
	int		found;
	int		a;

	a = -1;
	while (++a < len)
	{
		found = 0;
		i = a - 1;
		while (++i < len)
		{
			if (tab[i][0] == tab[a][0] && tab[i][1] == tab[a][1])
				found++;
		}
		if (found > 1)
			return (-1);
	}
	return (1);
}

int		print_and_return(int i)
{
	if (i == 0)
	{
		ft_putstr("ERROR CODE\n");
		return (0);
	}
	if (i == -1)
	{
		ft_putstr("ERROR\n");
		return (-1);
	}
	return (1);
}

int		free_and_return(char ***split, int i)
{
	int		j;

	j = 0;
	if (i == 1)
		return (-1);
	if (i == 2)
	{
		free(*split[0]);
		free(*split[1]);
		free(*split);
		*split = NULL;
		return (-1);
	}
	return (1);
}
