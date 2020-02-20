/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 08:24:10 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 03:02:02 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct		s_flags
{
	int					hashtag;
	int					zero;
	unsigned int		minus;
	unsigned int		plus;
	unsigned int		point;
	unsigned int		space;
	char				flag;
	unsigned int		width;
	unsigned int		precision;
	unsigned int		percent;
	unsigned int		large;
	unsigned int		l;
	unsigned int		h;
	unsigned int		ll;
	unsigned int		nb_caract;
	int					tmp;
}					t_flags;

typedef struct		s_compt
{
	int					i;
	int					j;
	int					m;
	int					nb;
	char				*num;
	char				*num2;
}					t_compt;

typedef struct		s_args
{
	char				*s;
	int					d;
	long long			ld;
	char				c;
	unsigned int		u;
	unsigned long long	lu;
	long long			x;
	unsigned long		o;
	void				*p;
	double				f;
}					t_args;

typedef struct		s_check_str
{
	unsigned int		precision;
	unsigned int		width;
	unsigned int		minus;
	unsigned int		zero;
	int					size;
	char				*str;
}					t_check_str;

typedef struct		s_check_digit
{
	char				*num;
	char				*negnum;
	char				*str;
	int					len;
	int					yn;
	int					neg;
	int					unplus;
	int					space;
	long long			negdig;
	int					ret;
	int					diff;
}					t_check_digit;

typedef struct		s_check_octa
{
	int					size;
	char				*str;
	int					surplus;
	int					tmp;
	int					nb;
}					t_check_octa;

typedef struct		s_check_hexa
{
	int					size;
	char				*str;
	int					exc;
	int					tmp;
}					t_check_hexa;

typedef struct		s_check_float
{
	int					size;
	char				*str;
	char				*nbstr;
	char				*nbstr2;
	char				*decstr;
	int					declen;
	int					nblen;
	int					hashtag;
	int					ret;
	int					strlen;
	int					yes;
}					t_check_float;

int					chose_flag(t_flags flags, va_list va, int nb);
int					parse(char *str, va_list va);
t_flags				compt_flags(t_flags flags, t_compt compt, char *str);
int					give_info(t_compt *compt, t_flags flags,
		va_list va, char *str);
int					chose_for_digit(t_flags flags, va_list va,
		int nb, t_args args);
int					chose_other_digit(t_flags flags, va_list va,
		int nb, t_args args);

t_check_str			init_str(t_flags flags, int size, char *str);
void				init(t_flags *flags);
void				init_digit(t_check_digit *c_dig, long long digit);
void				init_octa(t_check_octa *c_octa, t_flags flags);
void				init_float(t_flags flags, t_check_float *c_float);

int					ft_isflags(char c);
int					ft_atoi_2(char const *str);
char				*ft_strrev(char *str);
void				ft_putnstr(char const *s, int size);
void				ft_putncaract(char c, int size);
char				*ft_strcapitalize(char *str);
int					put_ret(char *str, int len);
void				put_init(char *str, t_check_octa *c_octa);
char				*cut_str_long(char *seg, t_flags flags);
void				free_digit(long long digit, t_check_digit *c_dig);
int					ft_is_in_string(char c);

char				*dectoocta(unsigned long n, t_flags flags);
void				ft_putstro(char *str, t_flags flags);
char				*dectohexa(unsigned long long n, t_flags flags, int i);
void				ft_putstrx(char *str, t_flags flags);
void				ft_puthash(t_flags flags);
int					ret_int(unsigned long long n, int base);
char				*octa_zero(char *seg);

int					precision_width_str(t_check_str c_str);
int					is_precision_str(t_check_str c_str);
int					is_width_str(t_check_str c_str);
int					is_width_no_precision_other_str(t_check_str c_str,
		int chose);
int					check_p_w_str(char *str, t_flags flags);

int					check_p_w_digit(long long digit, t_flags flags);
char				*make_str(long long digit, t_flags flags, char *str,
		t_check_digit *c_dig);
void				is_space(long long digit, t_flags *flags,
		t_check_digit *c_dig);
void				digit_upper_0(long long digit, t_check_digit *c_dig,
		int chose);
void				digit_lower_0(long long digit, t_check_digit *c_dig,
		t_flags flags, int n);
int					digit_plus_prec(long long digit, t_flags flags,
		t_check_digit c_dig);
int					digit_plus_width(long long digit, t_flags flags,
		t_check_digit c_dig);
int					digit_plus_width2(long long digit, t_flags flags,
		t_check_digit c_dig);
int					is_digit_plus(long long digit, t_flags flags,
		t_check_digit c_dig);
int					is_digit_minus(long long digit, t_flags flags,
		t_check_digit c_dig);
int					prec_digit_no_op(long long digit, t_flags flags,
		t_check_digit c_dig);
int					width_digit_no_op(long long digit, t_flags flags,
		t_check_digit c_dig);
void				is_flag_u(long long digit, t_flags *flags,
		t_check_digit *c_dig);
void				put_free(long long digit, t_flags flags,
		t_check_digit *c_dig);
int					ret_digit_no_op(long long digit, t_flags flags,
		t_check_digit c_dig);

int					check_p_w_caract(int c, t_flags flags);

int					is_octa_hash(unsigned long dec, t_flags flags,
		t_check_octa *c_octa);
int					is_octa_width_no_op(unsigned long dec, t_flags flags,
		t_check_octa *c_octa);
void				octa_print_space_0(unsigned long dec, t_flags flags,
		t_check_octa *c_octa, int chose);
int					is_octa_width_lower_no_op(unsigned long dec,
		t_flags flags, t_check_octa *c_octa);
int					is_octa_width_lower(unsigned long dec, t_flags flags,
		t_check_octa *c_octa);
int					is_octa_width(unsigned long dec, t_flags flags,
		t_check_octa *c_octa);
int					is_octa_width_up_prec(unsigned long dec, t_flags flags,
		t_check_octa *c_octa);
int					is_octa_width_prec(unsigned long dec, t_flags flags,
		t_check_octa *c_octa);
int					is_octa_no_width_prec(unsigned long dec, t_flags flags,
		t_check_octa *c_octa);
int					check_p_w_octa(unsigned long dec, t_flags flags);
int					is_octa_else(unsigned long dec, t_flags flags,
		t_check_octa *c_octa);

int					check_p_w_hexa(unsigned long long dec, t_flags flags);
void				puthash_init(t_flags flags, t_check_hexa *c_hexa);
int					is_hexa_width(unsigned long long dec, t_flags flags,
		t_check_hexa *c_hexa);
int					is_hexa_width_0_minus(unsigned long long dec, t_flags flags,
		t_check_hexa *c_hexa);
void				is_hexa_width_small_no_op(unsigned long long dec,
		t_flags flags, t_check_hexa *c_hexa);
int					is_hexa_width_small(unsigned long long dec, t_flags flags,
		t_check_hexa c_hexa);
int					is_hexa_width_no_prec_no_op(unsigned long long dec,
		t_flags flags, t_check_hexa c_hexa);
int					is_hexa_width_no_prec(unsigned long long dec, t_flags flags,
		t_check_hexa c_hexa);
int					is_hexa_width_upper_prec_minus(unsigned long long dec,
		t_flags flags, t_check_hexa *c_hexa);
int					is_hexa_width_upper_prec(unsigned long long dec,
		t_flags flags, t_check_hexa *c_hexa);
int					is_hexa_width_prec(unsigned long long dec, t_flags flags,
		t_check_hexa *c_hexa);
int					is_hexa_no_width_prec(unsigned long long dec, t_flags flags,
		t_check_hexa c_hexa);
int					is_hexa_no_op(unsigned long long dec, t_flags flags,
		t_check_hexa c_hexa);

int					check_p_w_ptr(void *ptr, t_flags flags);
int					check_p_w_percent(t_flags flags);

int					check_p_w_float(long double dec, t_flags flags);
void				free_float(t_check_float *c_float);
char				*ft_decpart(long double f, t_flags flags, int zer);
void				dec_arround(t_check_float *c_float, long double dec,
		t_flags flags);
int					float_nowidth_prec(long double dec, t_check_float c_float,
		t_flags flags);
int					float_nowidth_prec_sup_inf(long double dec,
		t_check_float c_float, t_flags flags);
int					width_noprec_nopoint(long double dec, t_flags flags,
		t_check_float c_float);
int					width_noprec_nopoint_null (t_flags flags);
int					width_noprec_point(long double dec, t_flags flags,
		t_check_float c_float);
int					str_find(char *str, char c);
int					width_noprec_point_nul(t_flags flags);
void				print_width_noprec_point_nul(t_flags flags);
void				print_width_noprec_nopoint(t_flags flags, int pre);
void				get_parts(t_check_float *c_float, t_flags flags,
		long double dec);

int					ft_printf(const char *format,
			...) __attribute__((format(printf,1,2)));

int					*ft_rev_intcpy(int *dst, const int *src, int size);

#endif
