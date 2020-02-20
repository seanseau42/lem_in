/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 14:36:41 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/13 15:42:32 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*new;

	new = *alst;
	if (alst != NULL)
	{
		while (new != NULL)
		{
			next = new->next;
			del(new->content, new->content_size);
			free(new);
			new = next;
		}
		*alst = NULL;
	}
}
