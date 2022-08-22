#ifndef FDF_H
# define FDF_H

# define BUFFER_SIZE 30

typedef struct s_map
{
	int	line;
	int	size;
	int **coordn;
}	t_map;

char	*get_next_line(int fd);
int		ft_strlen(char *str, int target);
char	*temp_split(char *ret);
char	*ft_strchr(const char *str, int c);
char	*ft_free(char *ret, char *temp);

char	**ft_split(char const *s, char c);
void	*ft_calloc(int count, int size);
char	**ft_split(char const *s, char c, int *size);

int		ft_getnbr(char *str);

void	error(void);

#endif
