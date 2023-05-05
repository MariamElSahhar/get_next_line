/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:25:49 by melsahha          #+#    #+#             */
/*   Updated: 2023/01/14 16:05:54 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*trim(char *s)
{
	char	*trimmed;
	int		nl;
	int		i;

	nl = 0;
	while (s[nl] && s[nl] != '\n')
		nl++;
	if (!s[nl])
	{
		free(s);
		return (0);
	}
	trimmed = (char *)ft_calloc(ft_strlen(s) - nl + 1, sizeof(char));
	if (!trimmed)
		return (0);
	nl++;
	i = 0;
	while (s[i + nl])
	{
		trimmed[i] = s[nl + i];
		i++;
	}
	free(s);
	return (trimmed);
}

char	*append_free(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}

char	*read_file(int fd, char *s)
{
	char	*buffer;
	int		i;

	if (!s)
		s = (char *)ft_calloc(1, sizeof(char));
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	i = 1;
	while (!got_line(s) && i > 0 && buffer)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == 0)
		{
			free(buffer);
			if (ft_strlen(s) == 0)
			{
				free(s);
				return (0);
			}
			return (s);
		}
		buffer[i] = '\0';
		s = append_free(s, buffer);
	}
	free(buffer);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s[1024];
	char		*line;

	if (fd < 0 || read(fd, s[fd], 0) < 0)
		return (0);
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (0);
	s[fd] = read_file(fd, s[fd]);
	if (!s[fd])
		return (0);
	line = get_line(s[fd]);
	s[fd] = trim(s[fd]);
	return (line);
}

/* int	main(void)
{
	int	fd;

	fd = open("gnlTester/files/multiple_line_no_nl", O_RDONLY);

	printf("output 1: %s", get_next_line(fd));
	printf("output 2: %s", get_next_line(fd));
	printf("output 3: %s", get_next_line(fd));
	printf("output 4: %s", get_next_line(fd));
	printf("output 5: %s", get_next_line(fd));
	printf("output 6: %s", get_next_line(fd));
	// printf("output 7: %s", get_next_line(fd));
	// printf("output 8: %s", get_next_line(fd));
	// printf("output 9: %s", get_next_line(fd));
	// printf("output 10: %s", get_next_line(fd));
	// printf("output: %s", get_next_line(fd));
	return (0);
}
 */
