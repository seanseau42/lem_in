/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 08:13:46 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 23:35:11 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *h;
	const char *n;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		h = haystack;
		n = needle;
		while (*h == *n && (*h && *n) != 0)
		{
			h++;
			n++;
		}
		if (!*n)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
