/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 14:27:42 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 14:46:21 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		len(long long n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_utoa(long long n)
{
	int		i;
	char	*str;

	if (n < 0)
		n = 4294967296 - n;
	i = len(n);
	if (!(str = malloc((sizeof(char) * i))))
		return (0);
	while (i--)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
