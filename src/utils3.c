/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils3.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 13:52:52 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 13:52:53 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lemin.h"

int			name_cmp(char *s1, char *s2)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			j++;
		i++;
	}
	if (j == len)
		return (1);
	return (0);
}

int			ft_chose_free2(char *s2, char **split)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	if (ft_strlen(s2) != ft_strlen(split[1]))
		return (0);
	while (split[1][i] || s2[i])
	{
		if (s2[i] == split[1][i])
			j++;
		i++;
	}
	if (j == i)
	{
		free(split[0]);
		free(split[1]);
		free(split);
		return (1);
	}
	return (0);
}

int			ft_chose_free(char *s2, char **split)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	if (ft_strlen(s2) != ft_strlen(split[0]))
		return (0);
	while (s2[i] || split[0][i])
	{
		if (s2[i] == split[0][i])
			j++;
		i++;
	}
	if (j == i)
	{
		free(split[0]);
		free(split[1]);
		free(split);
		return (1);
	}
	return (0);
}

int			ft_strcheck(char *s1, char *s2, int chose)
{
	char	**split;

	split = ft_strsplit(s1, '-');
	if (chose == 1)
		if (ft_chose_free(s2, split) == 1)
			return (1);
	if (chose == 2)
		if (ft_chose_free2(s2, split) == 1)
			return (1);
	free(split[0]);
	free(split[1]);
	free(split);
	return (0);
}

int			ft_atoi_3(char const *str)
{
	int			i;
	int			nbr;

	i = 0;
	nbr = 0;
	while (str[i] == ' ' || ft_isalpha(str[i]) ||
			str[i] == '#' || str[i] == ':')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr);
}
