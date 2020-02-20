/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 08:46:05 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 15:21:10 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

size_t			ft_strlen(const char *s);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
int				ft_atoi(char const *str);
char			*ft_itoa(int n);
void			*ft_memalloc(size_t size);
char			**ft_strsplit(char const *s, char c);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strchr(const char *str, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strrchr(const char *s, int c);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_strcat(char *s1, const char *s2);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
char			*ft_strndup(const char *s1, size_t len);
void			ft_swap(int *a, int *b);
char			*ft_lltoa(long long n);
char			*ft_ulltoa(unsigned long long n);
char			*ft_utoa(long long n);
char			*ft_uhtoa(long long n);
char			*ft_uhhtoa(long long n);
char			*ft_htoa(short n);
char			*ft_hhtoa(char n);
char			*ft_strjoinfree(char *s1, char *s2, char i);
char			*ft_strsubfree(char *s1, size_t start, size_t len);
char			*ft_ftoa(long double d, int p);
int				*ft_intcpy(int *dst, const int *src, int size);

int				get_next_line(const int fd, char **line);

# define BUFF_SIZE 2
# define FDMAX 126

typedef struct	s_gnl
{
	char	*str;
	int		fd;
}				t_gnl;

#endif
