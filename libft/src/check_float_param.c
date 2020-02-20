/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_float_param.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/06 16:27:39 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/06 16:35:46 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		width_noprec_point(long double dec, t_flags flags,
		t_check_float c_float)
{
	if (dec == 0.0)
		print_width_noprec_point_nul(flags);
	if (dec == 0.0)
		return (flags.width);
	dec_arround(&c_float, dec, flags);
	if (flags.minus)
	{
		ft_putncaract('+', flags.plus);
		ft_putstr(c_float.nbstr);
		ft_putncaract(' ', (flags.width - c_float.nblen - flags.plus));
	}
	else
	{
		ft_putncaract('+', flags.plus);
		if (flags.zero)
			ft_putncaract('0', flags.width - c_float.nblen -
					flags.plus - flags.hashtag);
		else
			ft_putncaract(' ', flags.width - c_float.nblen -
					flags.plus - flags.hashtag);
		ft_putstr(c_float.nbstr);
	}
	if (!(str_find(c_float.nbstr, '.') == 1))
		ft_putncaract('.', flags.hashtag);
	return (flags.width + flags.hashtag + flags.plus);
}

int		width_noprec_nopoint_null(t_flags flags)
{
	if (!flags.minus && !flags.hashtag && !flags.zero)
		print_width_noprec_nopoint(flags, 1);
	else if (flags.minus)
		print_width_noprec_nopoint(flags, 3);
	else if (flags.zero)
		print_width_noprec_nopoint(flags, 2);
	return (flags.width);
}

int		width_noprec_nopoint(long double dec, t_flags flags,
		t_check_float c_float)
{
	if (dec == 0.0 && flags.width > 8)
		return (width_noprec_nopoint_null(flags));
	else if (dec == 0.0 && !(flags.width > 8))
	{
		print_width_noprec_nopoint(flags, 0);
		return (8 + flags.plus);
	}
	if (!flags.zero)
	{
		ft_putncaract(' ', c_float.size - flags.plus);
		ft_putncaract('+', flags.plus);
	}
	else if (!flags.minus)
	{
		ft_putncaract('+', flags.plus);
		ft_putncaract('0', c_float.size - flags.plus);
	}
	ft_putstr(c_float.str);
	if (flags.minus)
		ft_putncaract(' ', c_float.size);
	return (flags.width);
}

int		float_nowidth_prec_sup_inf(long double dec, t_check_float c_float,
		t_flags flags)
{
	if (flags.precision >= ft_strlen(c_float.decstr))
	{
		if (dec == 0.0)
		{
			ft_putstr(c_float.nbstr);
			ft_putstr(c_float.decstr);
		}
		else
			ft_putstr(c_float.str);
		ft_putncaract('0', flags.precision - c_float.declen);
		return (flags.precision + c_float.nblen - 1 + flags.plus);
	}
	else
	{
		ft_putstr(c_float.str);
		return (c_float.nblen + 1 + flags.precision + flags.plus);
	}
	return (0);
}

int		float_nowidth_prec(long double dec,
		t_check_float c_float, t_flags flags)
{
	ft_putncaract('+', flags.plus);
	if (flags.plus == 0)
		ft_putncaract(' ', flags.space);
	return (float_nowidth_prec_sup_inf(dec, c_float, flags));
}
