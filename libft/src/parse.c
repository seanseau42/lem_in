/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:45:53 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 16:49:14 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int			is_no_flag(t_compt *compt, t_flags *flags, char *str)
{
	if (!ft_is_in_string(str[compt->j]))
	{
		if (ft_strchr("lhL", str[compt->j - 1]))
			compt->i = compt->j;
		else
			compt->i = compt->j - 1;
		return (1);
	}
	*flags = compt_flags(*flags, *compt, str);
	return (0);
}

int			give_info(t_compt *compt, t_flags flags, va_list va, char *str)
{
	compt->j = compt->i + 1;
	flags.tmp = 0;
	init(&flags);
	while (!(ft_isflags(str[compt->j++])))
		if ((is_no_flag(compt, &flags, str) == 1))
			return (1);
	flags.flag = str[compt->j - 1];
	if (!(compt->num = ft_strsub(str, compt->i, (compt->j - compt->i))))
		return (0);
	compt->num2 = NULL;
	if (flags.point)
		if (!(compt->num2 = ft_strsub(str, flags.tmp + 1,
						(compt->j - flags.tmp - 1))))
			return (0);
	if (compt->num2 == NULL)
		flags.precision = 0;
	else
		flags.precision = ft_atoi_2(compt->num2);
	flags.width = ft_atoi_2(compt->num);
	compt->i = compt->j - 1;
	compt->nb = chose_flag(flags, va, compt->nb);
	ft_strdel(&compt->num);
	ft_strdel(&compt->num2);
	return (1);
}

int			if_is_true(char *str, t_flags flags, t_compt cpt)
{
	if (str[cpt.j - 1] == '.' && ((ft_isdigit(str[cpt.j - 2]) ||
		ft_isdigit(str[cpt.j])) || str[cpt.j - 2] == ' '
		|| str[cpt.j - 2] == '+' || str[cpt.j - 2] == '#'
		|| (str[cpt.j - 2] == '%'
		&& ft_isflags(str[cpt.j]))))
		return (1);
	else
		return (0);
}

t_flags		compt_flags(t_flags flags, t_compt cpt, char *str)
{
	if (str[cpt.j - 1] == '#' && flags.hashtag < 1)
		flags.hashtag++;
	if (str[cpt.j - 1] == '+' && flags.plus < 1)
		flags.plus++;
	if (str[cpt.j - 1] == '-' && flags.minus < 1)
		flags.minus++;
	if (str[cpt.j - 1] == '0' && flags.zero < 1 &&
			!ft_isflags(str[cpt.j]) && !ft_isdigit(str[cpt.j - 2]))
		flags.zero++;
	if (if_is_true(str, flags, cpt))
	{
		flags.point++;
		flags.tmp = cpt.j - 1;
	}
	if (str[cpt.j - 1] == ' ' && flags.space < 1)
		flags.space++;
	if (str[cpt.j - 1] == 'l' && flags.l < 2)
		flags.l++;
	if (str[cpt.j - 1] == 'h' && flags.h < 2)
		flags.h++;
	if (str[cpt.j - 1] == 'L' && flags.ll < 1)
		flags.ll++;
	return (flags);
}

int			parse(char *str, va_list va)
{
	t_flags		flags;
	t_compt		compt;

	compt.nb = 0;
	compt.i = -1;
	while (str[++compt.i])
	{
		if (str[compt.i] != '%')
		{
			ft_putchar(str[compt.i]);
			compt.nb++;
		}
		if (str[compt.i] == '%' && str[compt.i + 1] != '\0')
			if (!(give_info(&compt, flags, va, str)))
				return (0);
	}
	va_end(va);
	return (compt.nb);
}
