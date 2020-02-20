/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils1.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:07:47 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 17:20:14 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_isflags(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
			|| c == 'u' || c == 'x' || c == 'X' || c == 'f'
			|| c == '%' || c == '\0')
		return (1);
	return (0);
}

int		ft_atoi_2(char const *str)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || ft_isalpha(str[i])
			|| str[i] == '%' || str[i] == '0' || str[i] == '+' || str[i] == '-'
			|| str[i] == '#' || str[i] == 'l' || str[i] == 'h' || str[i] == 'L')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + str[i++] - '0';
	return (nbr);
}

void	ft_putnstr(char const *s, int size)
{
	if (s != 0)
		write(1, s, size);
}

void	ft_putncaract(char c, int size)
{
	int		i;

	i = -1;
	if (size >= 0)
		while (++i != size)
			ft_putchar(c);
}

char	*cut_str_long(char *seg, t_flags flags)
{
	if (flags.flag == 'x' || flags.flag == 'X')
	{
		if (flags.l && ft_strlen(seg) > 16)
			seg[16] = '\0';
		if (ft_strlen(seg) > 8 && !flags.l)
			seg[8] = '\0';
		if (flags.h == 1)
			seg[4] = '\0';
		if (flags.h == 2)
			seg[2] = '\0';
	}
	else
	{
		if (flags.h == 1)
			seg[6] = '\0';
		if (flags.h == 2)
			seg[3] = '\0';
	}
	return (seg);
}
