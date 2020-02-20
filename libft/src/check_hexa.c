/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_hexa.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:43:42 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 16:16:56 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	puthash_init(t_flags flags, t_check_hexa *c_hexa)
{
	ft_puthash(flags);
	c_hexa->exc = 2;
}

int		is_hexa_no_width_prec(unsigned long long dec, t_flags flags,
		t_check_hexa c_hexa)
{
	if (flags.hashtag)
		if (dec != 0 || flags.flag == 'p')
		{
			ft_puthash(flags);
			c_hexa.exc = 2;
		}
	if (flags.precision > ft_strlen(c_hexa.str))
	{
		if (ft_strlen(c_hexa.str) < 9)
			ft_putncaract('0', flags.precision - ft_strlen(c_hexa.str));
		if (ft_strlen(c_hexa.str) > 8 && !flags.l && !flags.h)
			ft_putncaract('0', flags.precision - 8);
		if (ft_strlen(c_hexa.str) > 8 && !flags.l && flags.h == 1)
			ft_putncaract('0', flags.precision - 4);
		if (ft_strlen(c_hexa.str) > 8 && !flags.l && flags.h == 2)
			ft_putncaract('0', flags.precision - 2);
		if (ft_strlen(c_hexa.str) > 8 && flags.l && !flags.h)
			ft_putncaract('0', flags.precision - ft_strlen(c_hexa.str));
		ft_putstrx(c_hexa.str, flags);
		return (flags.precision + c_hexa.exc);
	}
	else
		ft_putstrx(c_hexa.str, flags);
	return (ft_strlen(c_hexa.str) + c_hexa.exc);
}

int		is_hexa_no_op(unsigned long long dec, t_flags flags,
		t_check_hexa c_hexa)
{
	if (flags.hashtag)
		if (dec != 0 || flags.flag == 'p')
			puthash_init(flags, &c_hexa);
	if (flags.flag == 'x' || flags.flag == 'X')
	{
		if (!(dec == 0 && flags.point))
		{
			ft_putstrx(c_hexa.str, flags);
			return ((int)ft_strlen(c_hexa.str) + c_hexa.exc);
		}
	}
	else
	{
		if (dec != 0)
			ft_putstrx(c_hexa.str, flags);
		if (dec != 0)
			return (ft_strlen(c_hexa.str) + c_hexa.exc);
		else if (dec == 0 && !flags.point)
		{
			ft_putstrx(c_hexa.str, flags);
			return (ft_strlen(c_hexa.str) + c_hexa.exc);
		}
		return (c_hexa.exc);
	}
	return (0);
}

int		check_p_w_hexa(unsigned long long dec, t_flags flags)
{
	t_check_hexa	c_hexa;
	int				nb;

	c_hexa.exc = 0;
	c_hexa.str = dectohexa(dec, flags, 0);
	if (flags.flag == 'X')
		c_hexa.str = ft_strcapitalize(c_hexa.str);
	c_hexa.size = flags.width - ft_strlen(c_hexa.str);
	if (c_hexa.size < 0)
		c_hexa.size = 0;
	if (flags.width && !flags.precision)
		nb = is_hexa_width_no_prec(dec, flags, c_hexa);
	else if (flags.width && flags.precision)
		nb = is_hexa_width_prec(dec, flags, &c_hexa);
	else if (!flags.width && flags.precision)
		nb = is_hexa_no_width_prec(dec, flags, c_hexa);
	else
		nb = is_hexa_no_op(dec, flags, c_hexa);
	ft_strdel(&c_hexa.str);
	return (nb);
}
