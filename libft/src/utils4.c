/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils4.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 17:20:45 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 17:22:53 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_octa_else(unsigned long dec, t_flags flags, t_check_octa *c_octa)
{
	if (flags.hashtag && ((c_octa->surplus != 1 && dec != 0) || flags.point))
		put_init("0", c_octa);
	c_octa->nb = 0;
	if ((dec != 0) || (dec == 0 && !flags.point))
		ft_putstro(c_octa->str, flags);
	if (dec != 0)
		c_octa->nb = ft_strlen(c_octa->str) + c_octa->surplus;
	if (dec == 0 && !flags.point)
		c_octa->nb = ft_strlen(c_octa->str) - flags.hashtag;
	return (c_octa->nb);
}
