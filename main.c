#include "includes/bsq.h"

int    print_bsq_struct(t_env *e)
{
    printf("/****struct****\\\n");
    printf("| sy 0 [%c]\n", e->sy[0]);
    printf("| sy 1 [%c]\n", e->sy[1]);
    printf("| sy 2 [%c]\n", e->sy[2]);
    printf("| nu y [%d]\n", e->yx[0]);
    printf("| nu x [%d]\n", e->yx[1]);
    printf("\\**************/\n\n");
    return (1);
}

int     struct_init(t_env *e, char *line)
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
    return (1);
}

int     not_legit(char empty, char block, char c)
{
    return ((c == empty || c == block) ? 1 : 0);
}

int         ret_min(int a, int b, int c)
{
    if (a < b)
        return ((a < c) ? a : c);
    return ((b < a) ? b : a);
}

void        bsq(int fd)
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
    e.map = ft_memalloc(y);
    while (y--)
    {
        get_next_line(fd, &line);
        if (i == 0)
            e.yx[1] = ft_strlen(line);
        if (e.yx[1] != (int)ft_strlen(line))
            return (ft_putendl("bad len"));
        e.map[i] = (int*)malloc(sizeof(int) * e.yx[1]);
        // e.map[i] = ft_memalloc(x);
        x = -1;
        while (++x < e.yx[1])
        {
            if (not_legit(e.sy[0], e.sy[1], line[x]) == 0)
                return (ft_putendl("invalid char"));
            if (i == 0 || x == 0)
                e.map[i][x] = (line[x] == e.sy[0]) ? 1 : 0;
            else if (i > 0 && x > 0)
                e.map[i][x] = (line[x] == e.sy[1]) ? 0 : ret_min(e.map[i][x - 1], e.map[i - 1][x - 1], e.map[i - 1][x]) + 1;
            printf("[%d] ", e.map[i][x]);
            if (line[x] != e.sy[1] && e.map[i][x] > e.fp[2])
            {
                e.fp[2] = e.map[i][x];
                e.fp[0] = i;
                e.fp[1] = x;
            }
        }
        printf("\n");
        i++;
    }
    printf("\nsuite test\nbsq y = %d, x = %d, size = %d\n\n", e.yx[0], e.yx[1], e.yx[2]);
    y = -1;
    while (++y < e.yx[0])
    {
        x = -1;
        while (++x < e.yx[1])
        {
            // if (y == e.fp[0] && x == e.yx[1])
                // e.map[y][x] = 123;
            printf("[%d] ", e.map[y][x]);
        }
        printf("\n");
    }
    close(fd);
}

int     main(int ac, char **av)
{
    if (ac > 1 && *av++)
        while (ac-- > 1)
           bsq(open(*av++, O_RDONLY));
    return (0);
}