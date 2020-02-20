/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:30:47 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/05 17:45:45 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 96 && str[i] < 123)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	rev;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		rev = str[i];
		str[i] = str[j];
		str[j] = rev;
		j--;
		i++;
	}
	return (str);
}

int		put_ret(char *str, int len)
{
	ft_putstr(str);
	return (len);
}

void	put_init(char *str, t_check_octa *c_octa)
{
	ft_putstr(str);
	c_octa->surplus = 1;
}

void	free_digit(long long digit, t_check_digit *c_dig)
{
	if (digit < 0)
		ft_strdel(&c_dig->negnum);
}
