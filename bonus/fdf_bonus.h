/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:56:39 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/02 12:58:30 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# define BUFFER_SIZE 		30
# define KEY_PRESS			2
# define DESTROY_NOTIFY		17

#define KEY_ESC		53
#define KEY_Q		12
#define KEY_W		13
#define KEY_E		14
#define KEY_A		0
#define KEY_S		1
#define KEY_D		2
#define KEY_UP		126
#define KEY_LEFT	123
#define KEY_RIGHT	124
#define KEY_DOWN	125
#define	KEY_PLUS	24
#define	KEY_MINUS	27

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	struct s_map	*map;
	struct s_coor	**coor;
	struct s_img	img;
}	t_mlx;

typedef struct s_coor
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_coor;

typedef struct s_map
{
	int				row;
	int				col;
	int				width;
	int				height;
	int				moving_x;
	int				moving_y;
	double			scale;
	double			angle;
	double			angle_x;
	double			angle_y;
	double			angle_z;
	struct s_coor 	**value;
	int				**color;
}	t_map;

int		hooks(int key, t_mlx *mlx);
void	moving_hook(int key, t_mlx *mlx);
void	change_angle(int key, t_mlx *mlx);
int		close_window(t_mlx *mlx);
void	change_scale(int key, t_mlx *mlx);
void	reinit_coor(t_mlx *mlx);

int		ft_strlen(char *str);
int 	count_line(int fd);
int		check_filename(char *name);
void	make_scale(t_map *map, t_coor **coor);

void	make_coordn(t_map *map);

t_map	init_map(t_map *map, int width, int height);
void	init_window(void **mlx, void **win);

void	drawing(t_mlx *mlx);
void	clear_image(t_mlx *mlx);
void	put_pixel(t_mlx	*mlx, int x, int y, int color);

t_coor	**init_coordn(t_map *map);
void	rotation(t_map *map, t_coor **coor);
void	axonometric(t_map *map, t_coor **coor);
void	moving_map(t_map *map, t_coor **coor);
void	adjust_scale(t_map *map, t_coor **coor);
void	adjust_center(t_map *map, t_coor **coor);

void	gredient_over(t_coor one, t_coor two, t_mlx *mlx);
void	gredient_under(t_coor one, t_coor two, t_mlx *mlx);

void	parsing_file(char *file_name, t_map *map);

char	*get_next_line(int fd);
int		ft_strlen_gnl(char *str, int target);
char	*temp_split(char *ret);
char	*ft_strchr(const char *str, int c);
char	*ft_free(char *ret, char *temp);

void	*ft_calloc(int count, int size);
char	**ft_split(char const *s, char c, int *size);
char	*ft_strnstr(char *haystack, char *needle, int len);
char	*ft_strcpy(char *src);
void	free_child(char **ret, int idx);

int		ft_atoi(char *str);

void	error(void);

#endif
