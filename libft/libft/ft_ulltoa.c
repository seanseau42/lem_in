/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lltoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 10:41:16 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 15:04:29 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

#include "libft.h"

static int		len(unsigned long long n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	if (len > 21)
		len = 21;
	return (len);
}

char			*ft_ulltoa(unsigned long long n)
{
	int		i;
	char	*str;

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
