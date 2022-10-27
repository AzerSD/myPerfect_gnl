/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 04:32:02 by azer              #+#    #+#             */
/*   Updated: 2022/10/27 06:34:31 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int				i;
	int				cnt;
	int				k = 1;
	char			*buff;
	char			*line;
	static queue	q;

	buff = malloc(BUFF_SIZE + 1);
	if (!buff)
		return (NULL);

	cnt = 1;
	while (cnt != 0 && k)
	{
		cnt = read(fd, buff, BUFF_SIZE);
		if (cnt == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[cnt] = '\0';
		
		i = 0;
		while (cnt > 0 && buff[i])
			enqueue(&q, buff[i++]);

		k = !newline_exists(buff);
		if (q.size == 0)
		{
			free(buff);
			return (NULL);
		}
	}
	line = get_line(&q);
	free(buff);
	return (line);
}
