/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_digit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:42:56 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 16:28:58 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*make_str(long long digit, t_flags flags, char *str,
		t_check_digit *c_dig)
{
	if (flags.flag == 'u')
	{
		if (flags.l)
			str = ft_ulltoa(digit);
		else if (flags.h == 1)
			str = ft_uhtoa(digit);
		else if (flags.h == 2)
			str = ft_uhhtoa(digit);
		else
			str = ft_utoa(digit);
	}
	if (flags.flag == 'i' || flags.flag == 'd')
	{
		if (flags.l)
			str = ft_lltoa(digit);
		else if (flags.h == 1)
			str = ft_htoa(digit);
		else if (flags.h == 2)
			str = ft_hhtoa(digit);
		else
			str = ft_itoa(digit);
		c_dig->str = ft_itoa(-digit);
	}
	c_dig->len = ft_strlen(str);
	return (str);
}

void	is_space(long long digit, t_flags *flags, t_check_digit *c_dig)
{
	if (((flags->space && (digit >= 0) && !flags->plus)) &&
			(((digit == 0 && flags->space) || 1 < ft_strlen(c_dig->num))
			|| flags->precision > ft_strlen(c_dig->num)) && flags->flag != 'u')
		ft_putchar(' ');
	else if (flags->space)
	{
		flags->space = 0;
		c_dig->space = 1;
	}
	if (digit < 0)
	{
		c_dig->diff = ((int)ft_strlen(c_dig->num) - flags->precision - 1);
		c_dig->neg = 1;
	}
	else
	{
		c_dig->diff = ((int)ft_strlen(c_dig->num) - flags->precision);
		c_dig->neg = 0;
	}
}

void	is_flag_u(long long digit, t_flags *flags, t_check_digit *c_dig)
{
	if (flags->flag == 'u')
		flags->plus = 0;
	if (digit < 0 && flags->flag != 'u')
		c_dig->negdig = -digit;
}

int		check_p_w_digit(long long digit, t_flags flags)
{
	t_check_digit		c_dig;

	init_digit(&c_dig, digit);
	is_flag_u(digit, &flags, &c_dig);
	if (!(c_dig.num = make_str(digit, flags, c_dig.num, &c_dig)))
		return (0);
	is_space(digit, &flags, &c_dig);
	if (flags.minus)
		c_dig.ret = is_digit_minus(digit, flags, c_dig);
	else if (flags.plus)
		c_dig.ret = is_digit_plus(digit, flags, c_dig);
	else
	{
		if (flags.precision)
			c_dig.ret = prec_digit_no_op(digit, flags, c_dig);
		else if (flags.width)
			c_dig.ret = width_digit_no_op(digit, flags, c_dig);
		else if ((digit == 0 && !flags.point) || digit != 0)
			c_dig.ret = put_ret(c_dig.num, ft_strlen(c_dig.num) + flags.space);
	}
	ft_strdel(&c_dig.num);
	ft_strdel(&c_dig.str);
	if (c_dig.ret != 0)
		return (c_dig.ret);
	return (flags.space + 0);
}
