/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ftoa2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/06 16:38:08 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/06 16:38:33 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		putint(intmax_t num, char *str, int count)
{
	if (num == 0)
		str[count] = '0';
	while (num)
	{
		str[--count] = num % 10 + '0';
		num /= 10;
	}
}

static double	ft_power(double num, int p)
{
	if (p == 0)
		return (1);
	if (p == 1)
		return (num);
	return (num * ft_power(num, p - 1));
}

static int		ft_ilen(intmax_t num)
{
	int		count;

	if (num < 0)
		num = -num;
	count = 0;
	while (num > 0 && ++count && (num /= 10))
		;
	return (count);
}

static void		putdec(long double d, int *i, int p, char *str)
{
	int		n;

	n = d;
	str[*i] = (p) ? '.' : '\0';
	while (p--)
	{
		d = (d - n) * 10.0;
		n = d;
		str[++*i] = n + '0';
	}
}

char			*ft_ftoa(long double d, int p)
{
	int			num;
	char		*str;
	int			i;
	short int	isneg;

	isneg = 0;
	if (p <= 0)
		p = 6;
	if (d < 0 || d == -0.0)
		isneg = 1;
	if (isneg)
		d = -d;
	d += (p >= 0) ? 5.000001 / ft_power(10, p + 1) : 0;
	num = d;
	i = ft_ilen(num) + isneg;
	if (!(str = malloc(sizeof(char) * (i + p + (p > 0 ? 1 : 0) + 1))))
		return (NULL);
	str[0] = (isneg) ? '-' : '\0';
	putint(num, str, i);
	i += (num == 0 ? 1 : 0);
	putdec(d, &i, p, str);
	str[i + 1] = '\0';
	return (str);
}
