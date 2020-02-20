/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lltoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 10:41:16 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 10:49:02 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdio.h>

static int		len(long long n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

static int		one(long long n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_lltoa(long long n)
{
	int		i;
	int		tmp2;
	char	*str;

	if (n == LLONG_MIN)
	{
		str = ft_memalloc(21);
		str = ft_strcpy(str, "-9223372036854775808");
		str[20] = '\0';
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
