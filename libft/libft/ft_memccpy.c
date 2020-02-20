/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 09:22:43 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/07 04:20:18 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst,
		const void *src, int c, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;
	unsigned char			i;

	d = dst;
	s = src;
	i = c;
	while (n--)
		if ((*d++ = *s++) == i)
			return (d);
	return (NULL);
}
