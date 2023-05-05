/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:25:52 by melsahha          #+#    #+#             */
/*   Updated: 2023/01/14 15:17:25 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	got_line(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while (s && s[count])
		count ++;
	return (count);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;
	int		i;
	int		j;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ret = malloc(count * size);
	if (!ret)
		return (0);
	i = 0;
	j = count * size;
	while (i < j)
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}

char	*get_line(char *s)
{
	char	*line;
	int		nl;
	int		i;

	nl = 0;
	if (!s[0])
		return (0);
	while (s[nl] && s[nl] != '\n')
		nl++;
	line = (char *)ft_calloc(nl + 2, 1);
	if (!line)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] && s[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size1;
	size_t	size2;
	size_t	i;
	char	*ret;

	i = 0;
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	ret = (char *)malloc(size1 + size2 + 1);
	if (!ret)
		return (0);
	while (i < size1)
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < size1 + size2)
	{
		ret[i] = s2[i - size1];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
