/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 10:07:23 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 18:23:05 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int			i;
	const unsigned char		*s3;
	const unsigned char		*s4;

	i = -1;
	s3 = s1;
	s4 = s2;
	while (++i < n)
		if (s3[i] < s4[i] || s3[i] > s4[i])
			return (s3[i] - s4[i]);
	return (0);
}
