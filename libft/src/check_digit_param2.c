/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_digit_param2.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/18 10:29:01 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 17:00:03 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_digit_plus(long long digit, t_flags flags, t_check_digit c_dig)
{
	if (flags.precision)
		return (digit_plus_prec(digit, flags, c_dig));
	else if (flags.width)
	{
		if (!flags.point && flags.zero && (flags.width > ft_strlen(c_dig.num)))
			return (digit_plus_width(digit, flags, c_dig));
		else
			return (digit_plus_width2(digit, flags, c_dig));
	}
	else
	{
		if (digit >= 0)
		{
			ft_putchar('+');
			if ((!flags.point && digit == 0) || digit != 0)
				c_dig.yn++;
		}
		if ((!flags.point && digit == 0) || digit != 0)
			ft_putstr(c_dig.num);
		return (ft_strlen(c_dig.num) + c_dig.yn + flags.space);
	}
}

int		is_digit_minus(long long digit, t_flags flags, t_check_digit c_dig)
{
	if ((flags.width > flags.precision && flags.precision >=
				ft_strlen(c_dig.num)) || flags.precision > ft_strlen(c_dig.num))
	{
		digit_lower_0(digit, &c_dig, flags, 1);
		ft_putstr(c_dig.negnum);
		if (flags.width > flags.precision)
			ft_putncaract(' ', (flags.width - flags.precision - c_dig.yn));
		free_digit(digit, &c_dig);
		if (flags.width > flags.precision)
			return (flags.space + flags.width);
		return (flags.space + flags.precision + c_dig.yn);
	}
	if (flags.precision < ft_strlen(c_dig.num))
	{
		ft_putstr(c_dig.num);
		if (flags.width > flags.precision)
		{
			ft_putncaract(' ', (flags.width - ft_strlen(c_dig.num) + c_dig.yn));
			if ((flags.width < ft_strlen(c_dig.num)))
				return (ft_strlen(c_dig.num) + flags.space);
			return (flags.space + flags.width);
		}
		return (ft_strlen(c_dig.num) + flags.space);
	}
	return (0);
}

int		prec_digit_no_op(long long digit, t_flags flags, t_check_digit c_dig)
{
	if (flags.width > flags.precision &&
			flags.precision >= ft_strlen(c_dig.num))
	{
		if (flags.width > flags.precision && c_dig.diff != 0)
			ft_putncaract(' ', (flags.width - flags.precision
						- flags.space - c_dig.neg));
		if (flags.width > flags.precision)
			c_dig.yn++;
		put_free(digit, flags, &c_dig);
		if (flags.width > flags.precision)
			return (flags.width);
		if (!(flags.width > flags.precision))
			return (flags.precision + flags.space + c_dig.yn);
		return (flags.width + flags.space - c_dig.len + c_dig.yn);
	}
	if ((flags.precision > 1) && (flags.precision < ft_strlen(c_dig.num)))
		ft_putncaract(' ', (flags.width - ft_strlen(c_dig.num)));
	if ((flags.precision > 1) && (flags.precision < ft_strlen(c_dig.num)))
		c_dig.yn++;
	put_free(digit, flags, &c_dig);
	return (ret_digit_no_op(digit, flags, c_dig));
}

int		width_digit_no_op(long long digit, t_flags flags, t_check_digit c_dig)
{
	if (!flags.point && flags.zero && (flags.width > ft_strlen(c_dig.num)))
	{
		digit_lower_0(digit, &c_dig, flags, 0);
		ft_putncaract('0', (flags.width - ft_strlen(c_dig.negnum)
					- c_dig.yn - flags.space));
		return (put_ret(c_dig.negnum, flags.width));
	}
	else if ((!flags.point && (flags.width > ft_strlen(c_dig.num)))
			|| ((flags.point && (flags.width >= ft_strlen(c_dig.num)))))
	{
		ft_putncaract(' ', (flags.width - ft_strlen(c_dig.num)));
		if (digit != 0)
		{
			if (c_dig.space == 1 && flags.width == 1
					&& ft_strlen(c_dig.num) < 2)
				ft_putchar(' ');
			return (put_ret(c_dig.num, flags.width +
						flags.space + c_dig.space));
		}
		else
			return (put_ret(" ", flags.width + flags.space));
	}
	else
		return (put_ret(c_dig.num, ft_strlen(c_dig.num) + flags.space));
}
