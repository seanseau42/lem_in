/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rev_intcpy.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/29 02:56:00 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 15:20:46 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		*ft_rev_intcpy(int *dst, const int *src, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < size)
	{
		dst[j] = src[i];
		i++;
		j--;
	}
	return (dst);
}
