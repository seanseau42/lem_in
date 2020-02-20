/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conversion.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:33:57 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/06 16:41:00 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		chose_for_digit(t_flags flags, va_list va, int nb, t_args args)
{
	if (flags.l && flags.flag == 'u')
	{
		args.lu = va_arg(va, unsigned long long);
		nb += check_p_w_digit(args.lu, flags);
	}
	else if (flags.flag == 'u')
	{
		args.u = va_arg(va, unsigned int);
		nb += check_p_w_digit(args.u, flags);
	}
	else if (flags.l && (flags.flag == 'd' || flags.flag == 'i'))
	{
		args.ld = va_arg(va, long long);
		nb += check_p_w_digit(args.ld, flags);
	}
	else
	{
		args.d = va_arg(va, int);
		nb += check_p_w_digit(args.d, flags);
	}
	return (nb);
}

int		chose_other_digit(t_flags flags, va_list va, int nb, t_args args)
{
	if (flags.flag == 'x' || flags.flag == 'X')
	{
		args.x = va_arg(va, unsigned long long);
		nb += check_p_w_hexa(args.x, flags);
	}
	if (flags.flag == 'p')
	{
		args.p = va_arg(va, void*);
		nb += check_p_w_ptr(args.p, flags);
	}
	if (flags.flag == 'o')
	{
		args.o = va_arg(va, unsigned long);
		nb += check_p_w_octa(args.o, flags);
	}
	return (nb);
}

int		chose_flag_f(t_flags flags, va_list va, int nb, t_args args)
{
	if (flags.flag == 'f')
	{
		if (flags.large == 1)
			args.f = va_arg(va, long double);
		else
			args.f = va_arg(va, double);
		nb += check_p_w_float(args.f, flags);
	}
	return (nb);
}

int		chose_flag(t_flags flags, va_list va, int nb)
{
	t_args		args;

	if (flags.flag == 's')
	{
		args.s = va_arg(va, char*);
		nb += check_p_w_str(args.s, flags);
	}
	if (flags.flag == 'd' || flags.flag == 'u' || flags.flag == 'i')
		nb = chose_for_digit(flags, va, nb, args);
	if (flags.flag == 'c')
	{
		args.c = va_arg(va, int);
		nb += check_p_w_caract(args.c, flags);
	}
	if (flags.flag == 'x' || flags.flag == 'X'
			|| flags.flag == 'o' || flags.flag == 'p')
		nb = chose_other_digit(flags, va, nb, args);
	if (flags.flag == 'f')
		nb = chose_flag_f(flags, va, nb, args);
	if (flags.flag == '%')
		nb += check_p_w_percent(flags);
	return (nb);
}
