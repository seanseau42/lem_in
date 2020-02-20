/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_pointer.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:45:23 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/05 19:03:14 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_p_w_ptr(void *ptr, t_flags flags)
{
	flags.hashtag = 1;
	flags.l = 1;
	return (check_p_w_hexa((long long)ptr, flags));
}
