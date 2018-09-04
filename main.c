#include "includes/bsq.h"

void	struct_init(t_env *e, char *line)
{
    char *ptr;

    ptr = line;
    ptr = ft_strrev(ptr);
    e->sy[2] = ptr[0];
    e->sy[1] = ptr[1];
    e->sy[0] = ptr[2];
    ptr = &ptr[3];
    e->yx[0] = ft_atoi(ft_strrev(ptr));
    e->fp[0] = -1;
    e->fp[1] = -1;
    e->fp[2] = -1;
}

void		new_sq_init(int *fp, int y, int x, int size)
{
	fp[0] = y;
	fp[1] = x;
	fp[2] = size;
}

int         ret_min(int a, int b, int c)
{
    if (a < b)
        return ((a < c) ? a : c);
    return ((b < a) ? b : a);
}

void		print_solution(int ac, t_env *e)
{
	int y;
	int x;

	y = e->fp[0] + 1;
	while (--y != (e->fp[0] - e->fp[2]) && (x = e->fp[1] + 1))
		while (--x != (e->fp[1] - e->fp[2]))
			e->map[y][x] = -1;
    y = -1;
    while (++y < e->yx[0])
    {
		x = -1;
        while (++x < e->yx[1])
        {
			if (e->map[y][x] == -1)
				ft_putchar(e->sy[2]);
			else if (e->map[y][x] == 0)
				ft_putchar(e->sy[1]);
			else
				ft_putchar(e->sy[0]);
        }
        ft_putchar('\n');
    }
	if (ac != 1)
		ft_putchar('\n');
}

/*void		error_free_and_exit(t_env *e, char *line)
{
	if (line)
		ft_strdel(&line);
	if (e->map)
	{
		while (e->map[e->yx[0]--])
		{
			printf("free e->map[%d]\n", e->yx[0]);
			free(e->map[e->yx[0]]);
			printf("try to print map 0 0 [%d]\n", e->map[e->yx[0]][0]);
		}
		free(e->map);
		e->map = NULL;
	}
	return (ft_putendl("map error"));
}*/

void        bsq(int ac, int fd)
{
    t_env   e;
    char    *line;
    int     y;
    int     x;
    int     i;

    if (fd < 0)
        return (ft_putendl("map bidon"));
    get_next_line(fd, &line);
    struct_init(&e, line);
    i = 0;
    y = e.yx[0];
	e.map = (int**)malloc(sizeof(int*) * y);
    while (y--)
    {
        get_next_line(fd, &line);
        if (i == 0)
            e.yx[1] = ft_strlen(line);
        if (e.yx[1] != (int)ft_strlen(line))
            return (ft_putendl("bad len"));
        e.map[i] = (int*)malloc(sizeof(int) * e.yx[1]);
        x = -1;
        while (++x < e.yx[1])
        {
			if (line[x] != e.sy[0] && line[x] != e.sy[1])
                return (ft_putendl("invalid char"));
            if (i == 0 || x == 0)
                e.map[i][x] = (line[x] == e.sy[0]) ? 1 : 0;
            else if (i > 0 && x > 0)
                e.map[i][x] = (line[x] == e.sy[1]) ? 0 : ret_min(e.map[i][x - 1], e.map[i - 1][x - 1], e.map[i - 1][x]) + 1;
            if (e.map[i][x] > e.fp[2] && line[x] != e.sy[1])
				new_sq_init(e.fp, i, x, e.map[i][x]);
        }
        i++;
    }
    close(fd);
	print_solution(ac, &e);
	//printf("%s\n", line);
	//error_free_and_exit(&e, line);
	//printf("%s\n", line);
}

int     main(int ac, char **av)
{
    if (ac > 1 && *av++)
        while (ac-- > 1)
           bsq(ac, open(*av++, O_RDONLY));
	else
		bsq(ac, 0);
    return (0);
}
