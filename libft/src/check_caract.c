/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_caract.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:44:14 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/05 19:05:28 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_p_w_caract(int c, t_flags flags)
{
	if (flags.width)
	{
		if (flags.minus)
		{
			ft_putchar(c);
			ft_putncaract(' ', (flags.width - 1));
			return (flags.width);
		}
		else
		{
			if (flags.zero)
				ft_putncaract('0', (flags.width - 1));
			else
				ft_putncaract(' ', (flags.width - 1));
			ft_putchar(c);
			return (flags.width);
		}
	}
	else
		ft_putchar(c);
	return (1);
}
