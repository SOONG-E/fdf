#ifndef FDF_H
# define FDF_H

# define BUFFER_SIZE 30

typedef struct s_map
{
	int		row;
	int		col;
	int 	**coordn;
	char	***color;
}	t_map;

void printmap(t_map *map); //삭제!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int 	count_line(int fd);

t_map	init_map(t_map *map);

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
int		ft_strlen(char *str);
void	free_child(char **ret, int idx);

int		ft_atoi(char *str);

void	error(void);

#endif
