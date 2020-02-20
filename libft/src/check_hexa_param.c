/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_hexa_param.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/19 12:41:50 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 11:09:25 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_hexa_width(unsigned long long dec, t_flags flags,
		t_check_hexa *c_hexa)
{
	if ((dec != 0 && !(flags.flag == 'p') && !(flags.width >
				ft_strlen(c_hexa->str))) || (flags.flag == 'p' && flags.minus))
	{
		ft_puthash(flags);
		c_hexa->exc = 2;
	}
	else if ((dec != 0 && flags.plus) || (flags.flag == 'p'))
	{
		if (dec != 0)
			ft_putncaract(' ', (flags.width - ft_strlen(c_hexa->str) - 2));
		else
			ft_putncaract(' ', (flags.width - 2));
		ft_puthash(flags);
		c_hexa->exc = 2;
		if (dec != 0)
			ft_putstrx(c_hexa->str, flags);
		if (flags.width > ft_strlen(c_hexa->str))
			return (flags.width);
		else if (dec == 0)
			return (c_hexa->exc);
		else
			return (ft_strlen(c_hexa->str) + c_hexa->exc);
	}
	return (-1);
}

void	is_hexa_width_small_no_op(unsigned long long dec, t_flags flags,
		t_check_hexa *c_hexa)
{
	if (flags.flag == 'p')
		ft_putncaract(' ', c_hexa->size - 2);
	if (flags.flag == 'p')
		ft_puthash(flags);
	else if ((flags.width >= (ft_strlen(c_hexa->str) + 2)) && flags.hashtag
			&& c_hexa->exc != 2)
	{
		c_hexa->exc = 2;
		ft_putncaract(' ', c_hexa->size - c_hexa->exc);
		c_hexa->exc = 0;
	}
	else
	{
		if (dec == 0)
			c_hexa->size++;
		ft_putncaract(' ', c_hexa->size - c_hexa->exc);
	}
	if (flags.hashtag && dec != 0 && c_hexa->exc != 2 && !(flags.flag == 'p'))
	{
		ft_puthash(flags);
		c_hexa->exc = 2;
	}
	if (dec != 0 || (flags.flag == 'p' && dec == 0))
		ft_putstrx(c_hexa->str, flags);
}

int		is_hexa_width_0_minus(unsigned long long dec, t_flags flags,
		t_check_hexa *c_hexa)
{
	if (((flags.flag == 'p' && c_hexa->exc != 2) || (flags.hashtag
					&& dec != 0 && c_hexa->exc != 2)) && flags.minus)
	{
		ft_puthash(flags);
		c_hexa->exc = 2;
	}
	if (dec != 0 && flags.minus)
		ft_putstrx(c_hexa->str, flags);
	if (dec != 0 && flags.minus)
	{
		ft_putncaract(' ', (flags.width - ft_strlen(c_hexa->str) -
					c_hexa->exc));
		return (1);
	}
	else if (flags.minus)
	{
		ft_putchar('0');
		ft_putncaract(' ', (flags.width - ft_strlen(c_hexa->str) -
					c_hexa->exc));
		return (1);
	}
	return (0);
}

int		is_hexa_width_small(unsigned long long dec, t_flags flags,
		t_check_hexa c_hexa)
{
	if (is_hexa_width_0_minus(dec, flags, &c_hexa) == 1)
		;
	else
	{
		if (flags.zero && !flags.point && !(flags.flag == 'p'))
		{
			if (flags.hashtag && dec != 0 && c_hexa.exc != 2
					&& !(flags.flag == 'p'))
			{
				ft_puthash(flags);
				c_hexa.exc = 2;
			}
			ft_putncaract('0', (c_hexa.size - c_hexa.exc));
			ft_putstrx(c_hexa.str, flags);
			return (flags.width);
		}
		is_hexa_width_small_no_op(dec, flags, &c_hexa);
	}
	if (flags.flag == 'p' && flags.minus && flags.width
			<= ft_strlen(c_hexa.str))
		return (flags.width);
	if (flags.flag == 'p' && flags.minus && flags.width
			== ft_strlen(c_hexa.str) + 1)
		return (ft_strlen(c_hexa.str) + c_hexa.exc);
	return (flags.width);
}

int		is_hexa_width_no_prec_no_op(unsigned long long dec,
		t_flags flags, t_check_hexa c_hexa)
{
	if (flags.hashtag && dec != 0 && c_hexa.exc != 2)
		ft_puthash(flags);
	if (flags.hashtag && dec != 0 && c_hexa.exc != 2)
		c_hexa.exc = 2;
	if (!flags.h && !flags.l && ft_strlen(c_hexa.str) > 8)
		ft_putncaract(' ', flags.width - 8);
	else if (flags.h == 1 && ft_strlen(c_hexa.str) > 4)
		ft_putncaract(' ', flags.width - 4);
	else if (flags.h == 2 && ft_strlen(c_hexa.str) > 2)
		ft_putncaract(' ', flags.width - 2);
	if (dec != 0 || (flags.h && dec == 0))
		ft_putstrx(c_hexa.str, flags);
	else
		ft_putncaract(' ', 1);
	return (ft_strlen(c_hexa.str) + c_hexa.exc);
}
