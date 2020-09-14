#include "flood.h"

void	ft_error(const char *str)
{
	printf("Error: %s\n", str);
	exit(1);
}

void flood_fill(t_vectors *v, char **map, int x, int y) 
{
	if (x < 0 || x > v->map_width - 1 || y < 0 || y > v->map_height - 1)
		return ; 
    if (ft_strchr("ZY", map[y][x]))
	{ 
		if (map[y][x] == 'Y')
			map[y][x] = '2';
		else
			map[y][x] = '0';
		flood_fill(v, map, x + 1, y); 
		flood_fill(v, map, x - 1, y); 
		flood_fill(v, map, x, y + 1); 
		flood_fill(v, map, x, y - 1); 
    }
}
 
void flood(t_vectors *v, char **map, int x, int y) 
{
	if (x < 0 || x > v->map_width - 1 || y < 0 || y > v->map_height - 1)
		return ; 
    if (ft_strchr("02NSWE", map[y][x]))
	{ 
		if (!x || !y || x >= v->map_width -1 || y >= v->map_height - 1)
			ft_error("Map leak!");
        if (map[y][x] == '2')
			map[y][x] = 'Y';
		else
			map[y][x] = 'Z';
		flood(v, map, x + 1, y); 
		flood(v, map, x - 1, y); 
		flood(v, map, x, y + 1); 
		flood(v, map, x, y - 1); 
    }
	if (map[y][x] == 'X')
		ft_error("Map leak!");
} 

int main(void)
{
	char **map;
	t_vectors *v;

	if (!(v = malloc(sizeof(t_vectors))))
		ft_error("malloc");
	if (!(map = malloc(sizeof(char *))))
		ft_error("malloc");
	v->map = map;
	ft_process_cub_file(v);
	flood(v, v->map, 1, 1);
	printf("\n\n");
	ft_print_map(v, v->map);
	printf("\n\n");
	flood_fill(v, v->map, 1, 1);
	ft_print_map(v, v->map);

    return(0);
}