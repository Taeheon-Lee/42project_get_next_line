/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 02:36:59 by tlee              #+#    #+#             */
/*   Updated: 2020/03/09 16:38:59 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

int		warehouse(int fd, char **wh)
{
	int		cnt;
	char	buff[BUFF_SIZE + 1];
	char	*temp;

	if (read(fd, buff, 0) < 0)
		return (-1);
	while ((cnt = read(fd, buff, BUFF_SIZE)))
	{
		buff[cnt] = '\0';
		if (!(*wh))
			*wh = ft_strdup(buff);
		else
		{
			temp = *wh;
			*wh = ft_strjoin(*wh, buff);
			free(temp);
		}
		if (ft_strchr(*wh, '\n'))
			break ;
	}
	return (cnt);
}

int		get_next_line(const int fd, char **line)
{
	static char	**wh = NULL;
	int			i;
	int			cnt;

	i = 0;
	if (!wh)
		wh = (char **)malloc(sizeof(char *) * 4096);
	if (fd < 0 || !line || (cnt = warehouse(fd, &(wh[fd - 3]))) < 0)
		return (-1);
	while (wh[fd - 3][i] != '\0' && wh[fd - 3][i] != '\n')
		i++;
	*line = ft_strnew(i);
	*line = ft_strncpy(*line, wh[fd - 3], i);
	if (*(wh[fd - 3]) || (**line && *line))
	{
		wh[fd - 3] = ft_strcut(wh[fd - 3], '\n');
		return (1);
	}
	return (cnt);
}
