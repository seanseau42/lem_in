/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 07:48:10 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/14 18:35:17 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dup;

	if (!(dup = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (0);
	else
		dup = ft_strcpy(dup, s1);
	return (dup);
}
