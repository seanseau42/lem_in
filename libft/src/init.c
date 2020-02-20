/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:04:59 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/06 16:36:35 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			init(t_flags *flags)
{
	flags->hashtag = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->point = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->space = 0;
	flags->l = 0;
	flags->h = 0;
	flags->ll = 0;
}

t_check_str		init_str(t_flags flags, int size, char *str)
{
	t_check_str		c_str;

	c_str.precision = flags.precision;
	c_str.width = flags.width;
	c_str.minus = flags.minus;
	c_str.zero = flags.zero;
	c_str.size = size;
	c_str.str = str;
	return (c_str);
}

void			init_digit(t_check_digit *c_dig, long long digit)
{
	c_dig->num = NULL;
	c_dig->str = NULL;
	c_dig->negnum = NULL;
	c_dig->yn = 0;
	c_dig->space = 0;
	c_dig->unplus = 1;
	c_dig->negdig = digit;
	c_dig->ret = 0;
}

void			init_octa(t_check_octa *c_octa, t_flags flags)
{
	c_octa->surplus = 0;
	c_octa->size = flags.width - ft_strlen(c_octa->str);
	if (c_octa->size < 0)
		c_octa->size = 0;
}

void			init_float(t_flags flags, t_check_float *c_float)
{
	ft_strdel(&c_float->str);
	c_float->str = "0.0";
	c_float->size = flags.width - ft_strlen(c_float->str);
	c_float->nbstr = "0";
	c_float->decstr = ".0";
	c_float->declen = 1;
	c_float->nblen = 2;
	c_float->yes = 1;
}
