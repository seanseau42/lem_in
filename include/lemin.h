/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lemin.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 13:30:44 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 14:48:25 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/includes/ft_printf.h"

# define TRUE				1
# define FALSE				0
# define SUCCESS			1
# define FAILURE			0
# define LIMIT_PATHS		20
# define TRI				15

typedef struct			s_file_display
{
	char					*line;
	struct s_file_display	*next;
}						t_file_display;

typedef struct			s_resize_matrice
{
	int						i;
	int						j;
	int						k;
	int						x;
	int						y;
	int						save_y;
	int						save_x;
	int						l;
	int						m;
	int						n;
	int						size_reduct;
}						t_resize_matrice;

typedef struct			s_name
{
	char					*name;
	int						index;
	int						co_y;
	int						co_x;
	struct s_name			*next;
}						t_name;

typedef struct			s_link
{
	char					*link;
	int						index;
	struct s_link			*next;
}						t_link;

typedef struct			s_info
{
	int						nb_fourmi;
	int						start;
	int						end;
	int						size_name;
	int						size_link;
	int						ret;
}						t_info;

typedef struct			s_matrix
{
	int						i;
	int						j;
	int						start_link_end;
	int						end_link_start;
	int						tmp_i;
	int						save_y;
	int						save_x;
	int						size;
	char					*name1;
	char					*name2;
	char					**split;
}						t_matrix;

typedef struct			s_cpt
{
	int						error;
	int						i;
	int						j;
	int						yes_start;
	int						yes_end;
	unsigned int			len;
	unsigned int			k;
	int						start_name;
	int						start_link;
	int						nb1;
	int						nb2;
}						t_cpt;

typedef struct			s_temp_bfs
{
	int						actual_path;
	int						i_queue;
	int						add_queue;
	int						size_queue;
}						t_temp_bfs;

typedef struct			s_bfs
{
	int						start;
	int						end;
	int						nb_paths;
	int						finish;
	int						end_links;
	int						size_diago;
	int						**mtx_diago;
	int						**mtx_state;
	int						found_paths;
	int						**queue;
	int						count_paths;
}						t_bfs;

typedef struct			s_map
{
	char					**map_name;
	char					**new_name;
	char					**map_link;
	int						**map_co;
	int						**matrix;
	int						**new_matrix;
	int						line_expected;
	int						ret;
	t_info					inf;
	t_cpt					cpt;
	t_matrix				mat;
	t_link					*tmp_link;
	t_name					*tmp_name;
	t_resize_matrice		n_mat;
	t_file_display			*tmp_f_dis;
}						t_map;

typedef struct			s_res
{
	int						**paths;
	int						*size_paths;
	int						used_paths;
}						t_res;

typedef	struct			s_path
{
	int						*path;
	int						size;
}						t_path;

typedef struct			s_tripaths
{
	struct s_path			**paths;
	int						*nb_subs;
	int						count_paths;
}						t_tripaths;

typedef struct			s_temp_paths
{
	int						act_path;
	int						sub_paths;
	int						*sub_ends;
	int						i_stp;
	int						step;
	int						prev;
}						t_temp_paths;

typedef struct			s_sort
{
	int						**new_path;
	int						**first_path;
	int						**second_path;
	int						*new_size_first;
	int						*new_size_second;
	int						nb_path_first;
	int						nb_path_second;
	int						*dispache;
}						t_sort;

typedef struct			s_dispa
{
	int						reste;
	int						*status_ant;
	int						ant_finish;
	int						i;
	int						j;
	int						k;
	int						l;
	int						m;
	int						n;
	int						p;
	int						q;
	int						space;
	int						ant_cross;
	int						tmp;
	int						ant_cross_max;
	int						*status_partion;
	int						*start_path;
	int						*status_path;
	int						count;
	int						error;
	int						occurrence;
	int						choose;
}						t_dispa;

typedef struct			s_rank
{
	int						i;
	int						j;
	int						k;
	int						size;
	int						left;
	int						*ranking[3];
	int						step;
	int						l;
	int						m;
	int						val;
	int						val1;
	int						val0;
}						t_rank;

/*
**	parser.c
*/
int						insert_line_lst(t_map *m, char **line,
	t_file_display **dis, int *c);
int						ft_get_map_size(t_map *m, t_name **name, t_link **l);
int						check_name_line(t_name **name, t_map *map,
	char *line, char **split);
int						check_start_end(t_map *map, char **l,
	t_file_display **f_dis);
int						parser(t_name **name, t_link **l, t_map *m,
	t_file_display **f_dis);

/*
**	parser_check.c
*/
int						check_start(t_map *map);
int						check_end(t_map *map);
int						check_start_name(t_map *map,
	t_name **name, char **split);
int						check_ant_line(t_map *map, char **l,
	t_file_display **f_dis);
int						check_link_line(t_link **link, t_map *map,
	char *line);

/*
**	set_all_tab.c
*/
int						set_tab_link(t_link *tmp_link, t_map *map);
int						set_tab_name_and_co(t_name *tmp_name, t_map *map);
int						set_map(t_name **name, t_link **link, t_map *map);
void					set_check_name_link(t_map *map, int i);
int						set_matrix(t_map *map);

/*
**	check_link_name.c
*/
int						check_all_link_and_name(t_map *map, int i);

/*
**	bfs1.c
*/
void					ft_setprematrix(t_bfs *bfs, t_temp_bfs temp);
void					ft_foundpaths(t_bfs *bfs, int step, t_map *map);
t_tripaths				ft_bfs(t_map map, t_bfs *bfs,
	t_tripaths *tri, t_res *res);

/*
**	setup_bfs.c
*/
void					ft_nb_paths(t_map map, t_bfs *bfs);
int						ft_nb_paths_start(t_map map);
int						ft_setprealgo(t_map map, t_bfs *bfs);

/*
**	bfs2.c
*/
void					remove_room_queue(t_bfs *bfs);
void					ft_del_rooms(t_bfs *bfs, t_temp_bfs temp);
void					ft_delactual_room(t_bfs *bfs, int path,
	t_temp_bfs temp);
void					ft_pre_roomto_queue(t_bfs *bfs,
		t_temp_bfs temp, int room, int path);
void					ft_freequeue(t_bfs *bfs);

/*
**	function_matrix_state.c
*/
int						ft_init_queue(t_bfs *bfs, int i);
int						ft_foundroom(t_bfs *bfs, t_temp_bfs temp, int room);
int						ft_size_queue(t_bfs bfs, int path);
void					ft_roomto_queue(t_bfs *bfs, t_temp_bfs temp, int room);
void					ft_setqueue(t_bfs *bfs, t_temp_bfs temp, int step);

/*
** bfs4.c
*/
int						get_nb_sub_path(t_bfs *bfs, t_temp_paths tp,
		t_tripaths *tri, int path);
int						ft_takepaths(t_bfs *bfs, t_res *res, t_tripaths *tri);

/*
** bfs5.c
*/
void					ft_tri_shell(t_rank *rank, int size);
void					ft_import_coord(t_tripaths tri, t_bfs bfs,
	t_rank *rank, int limit);
int						ft_tri_to_res(t_res *res, t_tripaths tri,
	t_bfs bfs, t_map map);
void					limit_paths_sup(t_tripaths tri,
	t_rank *rank, int limit);
void					ft_tri_shell_proc(t_rank *rank);

/*
** bfs6.c
*/
int						ft_tri_paths(t_res *res, t_sort *sort,
	int nb_line, int total_ants);

/*
** bfs7.c
*/
int						ft_tri_big(t_res *res, t_sort *sort,
	int nb_line, int total_ants);
int						ft_nb_line(int total_ants, t_sort *sort,
	int ant, int index);

int						is_path_possible(t_bfs *bfs);
/*
** display_algo.c
*/
int						display_algo(t_map map, t_res *res);

/*
** clear_path.c
*/
int						clear_path2(t_res *res, t_sort *sort);

/*
** dispatch_ant.c
*/
void					display_print(t_dispa *dis, t_sort *sort, t_map map);

/*
**	free.c
*/
void					free_all(t_bfs *bfs, t_map *map, t_res *res);
void					clear(t_name **name, t_link **link,
	t_file_display **f_dis);
void					free_tri(t_tripaths *tri, t_bfs *bfs);

/*
**	free_error.c
*/
void					free_no_solution(t_bfs *bfs, t_map *map);
int						free_print1(t_file_display **f_dis, t_name **name,
						t_link **link, t_map *map);
int						free_print2(t_file_display **f_dis, t_name **name,
						t_link **link, t_map *map);
int						ft_free_split(char ***split, int nb_words);
int						free_end_start(t_file_display **f_dis, t_name **name,
						t_link **link, t_map *map);

/*
**	utils.c
*/
unsigned int			count_word(const char *s, char c);
void					free_map(char **map);
int						check_str_number(char *str);
int						free_line(char **line);
/*
**	utils2.c
*/
int						check_valid_co(int **tab, int len);
int						print_and_return(int i);
int						free_and_return(char ***split, int i);

/*
**	utils3.c
*/
int						name_cmp(char *s1, char *s2);
int						ft_chose_free2(char *s2, char **split);
int						ft_chose_free(char *s2, char **split);
int						ft_strcheck(char *s1, char *s2, int chose);
int						ft_atoi_3(char const *str);

/*
**	utils4.c
*/
int						ft_used_paths(int *nb_subs, int nb_paths, int limit);
int						actu_disi2(int disi, int step, int temp);
int						actu_disi(int disi, int step);
void					get_line_expected(t_map *map, char *line);

/*
**	init.c
*/
void					init_value(t_map *map);
void					init_matrix(t_map *map);
int						init_sort(t_sort *sort, t_res *res);
void					dis_var(t_dispa *dis, t_map map, t_sort *sort);
int						init_dis(t_dispa *dis, t_map map, t_sort *sort);

/*
**	init2.c
*/
int						init_mtx_state(t_bfs *bfs, t_map map);
int						init_states_to_paths(t_bfs *bfs,
		t_tripaths *tri, t_temp_paths *tp);
int						init_tri_to_res(t_res *res,
		t_tripaths tri, t_bfs bfs, t_rank *rank);

/*
**	ft_list.c
*/
t_link					*insert_link(char *val, int i);
t_name					*insert_name(char **val, int i);
t_file_display			*insert_line(char *line);
int						list_len(t_name *name, t_link *link, int chose);
void					print_list(t_name *name, t_link *link);

/*
**	main.c
*/
void					print_file(t_file_display *f_dis);
int						start_link_to_end(t_map	*map, t_file_display *f_dis);

#endif
