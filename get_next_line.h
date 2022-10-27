#ifndef GET_NEXT_LINE_H

# ifndef BUFF_SIZE
#  define BUFF_SIZE 42
# endif

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>



typedef struct node
{
    unsigned char value;
    struct node *next;
}   node;

typedef struct
{
    node    *head;
    node    *tail;
    size_t  size;
} queue;

char 	*get_next_line(int	fd);
char    *get_line(queue *q);
int 	enqueue(queue *q, unsigned char value);
int     newline_exists(char *s);

unsigned char		dequeue(queue *q);

#endif