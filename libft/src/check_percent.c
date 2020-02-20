/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_percent.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/26 17:47:01 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/26 17:47:53 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_p_w_percent(t_flags flags)
{
	if (flags.width)
	{
		if (flags.minus)
		{
			ft_putchar('%');
			if (flags.zero)
				ft_putncaract('0', flags.width - 1);
			else
				ft_putncaract(' ', flags.width - 1);
			return (flags.width);
		}
		else
		{
			if (flags.zero)
				ft_putncaract('0', flags.width - 1);
			else
				ft_putncaract(' ', flags.width - 1);
			ft_putchar('%');
			return (flags.width);
		}
	}
	else
		ft_putchar('%');
	return (1);
}
