/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_str.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:55:34 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 18:28:19 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		precision_width_str(t_check_str c_str)
{
	if (c_str.minus && !c_str.width)
	{
		ft_putnstr(c_str.str, c_str.precision);
		ft_putncaract(' ', c_str.size);
		return (c_str.size + c_str.precision);
	}
	else if (c_str.minus && c_str.width)
	{
		ft_putnstr(c_str.str, c_str.precision);
		ft_putncaract(' ', c_str.width - c_str.precision);
		return ((c_str.width - c_str.precision) + c_str.precision);
	}
	else if (c_str.precision < c_str.width)
	{
		ft_putncaract(' ', (c_str.width - c_str.precision));
		ft_putnstr(c_str.str, c_str.precision);
		return ((c_str.width - c_str.precision) + c_str.precision);
	}
	else
	{
		ft_putncaract(' ', c_str.size);
		ft_putnstr(c_str.str, c_str.precision);
		return (c_str.size + c_str.precision);
	}
}

int		is_precision_str(t_check_str c_str)
{
	if (c_str.precision < ft_strlen(c_str.str))
	{
		if (c_str.width)
			return (precision_width_str(c_str));
		else
			ft_putnstr(c_str.str, c_str.precision);
		return (c_str.precision);
	}
	else
	{
		if (c_str.minus)
		{
			ft_putstr(c_str.str);
			ft_putncaract(' ', c_str.size);
			return (c_str.size + ft_strlen(c_str.str));
		}
		else
		{
			ft_putncaract(' ', c_str.size);
			ft_putstr(c_str.str);
			return (c_str.size + ft_strlen(c_str.str));
		}
	}
	return (0);
}

int		is_width_str(t_check_str c_str)
{
	if (c_str.minus)
	{
		ft_putstr(c_str.str);
		ft_putncaract(' ', c_str.size);
		return (c_str.size + ft_strlen(c_str.str));
	}
	else if (c_str.zero)
	{
		ft_putncaract('0', c_str.size);
		ft_putstr(c_str.str);
		return (c_str.size + ft_strlen(c_str.str));
	}
	else
	{
		ft_putncaract(' ', c_str.size);
		ft_putstr(c_str.str);
		return (c_str.size + ft_strlen(c_str.str));
	}
}

int		is_width_no_precision_other_str(t_check_str c_str, int chose)
{
	if (chose == 1)
	{
		if (c_str.zero && !c_str.minus)
			ft_putncaract('0', c_str.width);
		else
			ft_putncaract(' ', c_str.width);
		return (c_str.width);
	}
	if (chose == 2)
	{
		ft_putstr(c_str.str);
		ft_putncaract(' ', c_str.size + 1);
		return (c_str.size + ft_strlen(c_str.str));
	}
	return (0);
}

int		check_p_w_str(char *str, t_flags flags)
{
	int		size;

	if (!str)
	{
		ft_strdel(&str);
		str = ft_strnew(7);
		str = ft_strcpy(str, "(null)");
	}
	size = flags.width - ft_strlen(str);
	if (size < 0)
		size = 0;
	if (flags.point && (!flags.precision && !flags.width))
		return (0);
	else if (flags.precision)
		return (is_precision_str(init_str(flags, size, str)));
	else if (flags.point && !flags.precision)
		return (is_width_no_precision_other_str(init_str(flags, size, str), 1));
	else if (flags.width)
		return (is_width_str(init_str(flags, size, str)));
	else if (flags.plus && flags.minus && (size + 1))
		return (is_width_no_precision_other_str(init_str(flags, size, str), 2));
	ft_putstr(str);
	return (ft_strlen(str));
}
