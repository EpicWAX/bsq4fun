#ifndef BSQ_H
# define BSQ_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>

/*
**  sy means symbol (sy[0] is empty case s[1] block case and sy[2] square representation)
**  yx[0] and yx[1] is axy y and x
**  fp means final position (fp[0] and fp[1] is y and x position, fp[2] is the size of the square)
*/

typedef struct          s_env
{
    char    sy[3];
    int     yx[2];
    int     fp[3];
    int     **map;
}                       t_env;

#endif