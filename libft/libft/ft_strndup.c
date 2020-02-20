/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/14 18:35:22 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/14 18:37:12 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*dup;

	if (!(dup = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	else
		dup = ft_strncpy(dup, s1, len);
	return (dup);
}
