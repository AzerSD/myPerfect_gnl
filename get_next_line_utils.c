/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:26:59 by azer              #+#    #+#             */
/*   Updated: 2022/10/27 06:34:44 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int enqueue(queue *q, unsigned char value)
{
    node *new_node;
    new_node = malloc (sizeof(node));
    if (new_node == NULL)
        return (0);

    new_node->value = value;
    new_node->next = NULL;
    if (q->tail != NULL)
        q->tail->next = new_node;

    q->tail = new_node;
    if (q->head == NULL)
        q->head = new_node;
    q->size += 1;
    return (1);
}

unsigned char dequeue(queue *q)
{
    unsigned char    result;
    
    if (q->head == NULL)
        return (0);
    
    node *tmp = q->head;
    result = tmp->value;
    q->head = q->head->next;
    
    if (q->head == NULL)
        q->tail = NULL;

    q->size -= 1;
    free(tmp);
    tmp = NULL;

    return (result);
}

int	newline_exists(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char *get_line(queue *q)
{
    char    *line;
    int     i;
    int     len = q->size;
    unsigned char    c;

    line = malloc(sizeof(char) * (len));
    if (!line)
        return (NULL);
    i = 0;
    while (i < len)
    {
        c = dequeue(q);
        if (c != '\n')
        {
            line[i] = c;
            i++;
        }
        else
        {
            line[i] = c;
            i++;
            line[i] = '\0';
            return (line);
        }
    }
    line[i] = '\0';
    return (line);
}
