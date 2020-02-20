/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_hexa_param2.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/19 12:42:09 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 17:00:28 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_hexa_width_no_prec(unsigned long long dec, t_flags flags,
		t_check_hexa c_hexa)
{
	if (flags.hashtag && flags.point)
		if (!(c_hexa.tmp = is_hexa_width(dec, flags, &c_hexa)))
			return (c_hexa.tmp);
	if (c_hexa.tmp == flags.width && flags.width > ft_strlen(c_hexa.str))
		return (flags.width);
	if (flags.hashtag && flags.point && dec == 0)
	{
		if (!(flags.flag == 'p'))
			ft_putncaract(' ', flags.width);
		if (!(flags.flag == 'p'))
			return (flags.width + c_hexa.exc);
		else if (flags.flag == 'p')
			ft_putncaract(' ', flags.width - c_hexa.exc);
		return (flags.width);
	}
	if (flags.width > ft_strlen(c_hexa.str))
		return (is_hexa_width_small(dec, flags, c_hexa));
	else
		return (is_hexa_width_no_prec_no_op(dec, flags, c_hexa));
}

int		is_hexa_width_upper_prec_minus(unsigned long long dec, t_flags flags,
		t_check_hexa *c_hexa)
{
	if (!flags.minus)
	{
		if (flags.hashtag && dec != 0 && c_hexa->exc != 2)
			puthash_init(flags, c_hexa);
		if (!(flags.flag == 'p'))
			ft_putncaract(' ', (flags.width - flags.precision - c_hexa->exc));
		ft_putncaract('0', (flags.width - ft_strlen(c_hexa->str) -
					(flags.width - flags.precision)));
		ft_putstrx(c_hexa->str, flags);
		if (flags.width > 2)
			return (flags.width);
		else
			return (flags.width + ft_strlen(c_hexa->str));
	}
	else
	{
		ft_putncaract('0', (flags.width - ft_strlen(c_hexa->str) -
					(flags.width - flags.precision)));
		ft_putstrx(c_hexa->str, flags);
		if (!(flags.flag == 'p'))
			ft_putncaract(' ', (flags.width - flags.precision));
		else
			ft_putncaract(' ', (flags.width - flags.precision - c_hexa->exc));
		return (flags.width);
	}
}

int		is_hexa_width_upper_prec(unsigned long long dec, t_flags flags,
		t_check_hexa *c_hexa)
{
	if (flags.precision < ft_strlen(c_hexa->str))
	{
		if (flags.hashtag || flags.flag == 'p')
		{
			ft_putncaract(' ', flags.width - ft_strlen(c_hexa->str) - 2);
			if (dec != 0 && c_hexa->exc != 2)
				ft_puthash(flags);
			if (dec != 0 && c_hexa->exc != 2)
				c_hexa->exc = 2;
		}
		else
			ft_putncaract(' ', flags.width - ft_strlen(c_hexa->str));
		ft_putstrx(c_hexa->str, flags);
		if (flags.width > ft_strlen(c_hexa->str))
			return (flags.width);
		else
			return (ft_strlen(c_hexa->str) + c_hexa->exc);
	}
	return (is_hexa_width_upper_prec_minus(dec, flags, c_hexa));
}

int		is_hexa_width_prec(unsigned long long dec, t_flags flags,
		t_check_hexa *c_hexa)
{
	if (flags.flag == 'p' && dec != 0 && flags.width < ft_strlen(c_hexa->str))
		ft_puthash(flags);
	if (flags.flag == 'p' && dec != 0 && flags.width < ft_strlen(c_hexa->str))
		c_hexa->exc = 2;
	if (flags.width > flags.precision)
		return (is_hexa_width_upper_prec(dec, flags, c_hexa));
	else if (flags.width < flags.precision || flags.width == flags.precision)
	{
		if (flags.hashtag && dec != 0 && c_hexa->exc != 2)
			ft_puthash(flags);
		if (flags.hashtag && dec != 0 && c_hexa->exc != 2)
			c_hexa->exc = 2;
		ft_putncaract('0', (flags.precision - ft_strlen(c_hexa->str)));
		ft_putstrx(c_hexa->str, flags);
		if (flags.precision > ft_strlen(c_hexa->str))
			return (flags.precision + c_hexa->exc);
		else
			return (ft_strlen(c_hexa->str) + c_hexa->exc);
	}
	return (-1);
}
