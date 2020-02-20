/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_float.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 14:32:22 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/06 16:34:28 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	free_float(t_check_float *c_float)
{
	if (c_float->yes == 0)
	{
		ft_strdel(&c_float->str);
		ft_strdel(&c_float->nbstr);
		ft_strdel(&c_float->decstr);
	}
}

void	get_parts(t_check_float *c_float, t_flags flags, long double dec)
{
	c_float->nblen = 0;
	while (c_float->str[c_float->nblen] != '.' && c_float->str[c_float->nblen])
		c_float->nblen++;
	if (flags.hashtag)
		c_float->nblen++;
	if (dec != 0.0)
	{
		c_float->nbstr = ft_strsub(c_float->str, 0, c_float->nblen);
		c_float->decstr = ft_strsub(c_float->str, c_float->nblen,
				ft_strlen(c_float->str) - (c_float->nblen));
		c_float->declen = ft_strlen(c_float->decstr);
		c_float->size = flags.width - ft_strlen(c_float->str);
		c_float->yes = 0;
	}
	else
		init_float(flags, c_float);
	if (c_float->size < 0)
		c_float->size = 0;
	c_float->ret = 0;
	c_float->strlen = ft_strlen(c_float->str);
}

int		check_p_w_float(long double dec, t_flags flags)
{
	t_check_float	c_float;

	c_float.str = ft_ftoa(dec, flags.precision);
	get_parts(&c_float, flags, dec);
	if (flags.width && !flags.precision)
	{
		if (flags.point)
			c_float.ret = width_noprec_point(dec, flags, c_float);
		if (!flags.point)
			c_float.ret = width_noprec_nopoint(dec, flags, c_float);
	}
	if (flags.precision && !flags.width)
		c_float.ret = float_nowidth_prec(dec, c_float, flags);
	if ((flags.precision && flags.width) && (flags.width >= flags.precision))
		ft_putncaract(' ', flags.width - c_float.strlen - flags.plus);
	if (!c_float.ret)
	{
		if (dec > 0)
			ft_putncaract('+', flags.plus);
		ft_putstr(c_float.str);
		ft_putncaract('0', flags.precision - c_float.declen - flags.plus);
		c_float.ret = (c_float.nblen + c_float.declen + flags.plus + 1);
	}
	free_float(&c_float);
	return (c_float.ret);
}
