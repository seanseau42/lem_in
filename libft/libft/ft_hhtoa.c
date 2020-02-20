/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hhtoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 16:01:59 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 16:04:59 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		len(char n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

static int		one(char n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_hhtoa(char n)
{
	int		i;
	int		tmp2;
	char	*str;

	if (n == -128)
	{
		str = ft_memalloc(5);
		str = ft_strcpy(str, "-128");
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
