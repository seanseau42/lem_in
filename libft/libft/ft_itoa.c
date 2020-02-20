/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 06:27:31 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 14:24:52 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		len(int n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

static int		one(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_itoa(int n)
{
	int		i;
	int		tmp2;
	char	*str;

	if (n == -2147483648)
	{
		str = ft_memalloc(12);
		str = ft_strcpy(str, "-2147483648");
		return (str);
	}
	tmp2 = one(n);
	if (n < 0)
		n = -n;
	i = len(n);
	if (!(str = ft_memalloc(i + tmp2)))
		return (0);
	tmp2 == 1 ? str[0] = '-' : 0;
	while (i--)
	{
		str[i + tmp2] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
