/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 07:21:23 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/03 13:53:41 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char*str;

	if (!(str = (malloc(sizeof(char) * (size + 1)))))
		return (0);
	ft_bzero(str, size + 1);
	return (str);
}
