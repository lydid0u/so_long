/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:54:17 by adzinabi          #+#    #+#             */
/*   Updated: 2023/07/13 23:08:54 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *str1, char *str2)
{
	int		len;
	int		i;
	int		j;
	char	*str;

	len = ft_strclen(str1, '\0') + ft_strclen(str2, '\0');
	str = malloc(sizeof(char) * (len + 1));
	*str = '\0';
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strclen(str1, '\0'))
	{
		str[i] = str1[i];
		i++;
	}
	while (j < ft_strclen(str2, '\0'))
		str[i++] = str2[j++];
	str[i] = '\0';
	return (free(str1), str);
}

int	ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (str)
	{	
		while (str[i])
		{
			if (str[i] == (unsigned char)c)
				return (1);
			i++;
		}
	}
	return (0);
}

char	*addnextline(char *str)
{
	char	*stash;
	int		i;

	i = 0;
	if (!str || !str[0])
		return (NULL);
	stash = malloc(sizeof(char) * ft_strclen(str, '\n') + 2);
	if (!stash)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		stash[i] = str[i];
		i++;
	}
	if (str[i] != '\0')
	{
		stash[i] = '\n';
		i++;
	}
	stash[i] = '\0';
	return (stash);
}

char	*add_left_to_stash(char *stash)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*left;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	left = malloc((ft_strclen(stash, '\0') - i) * sizeof(char));
	if (!left)
		return (free(stash), NULL);
	j = i + 1;
	k = 0;
	while (stash[j])
		left[k++] = stash[j++];
	left[k] = '\0';
	return (free(stash), left);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buff;
	int			char_lu;

	char_lu = 1;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	*buff = '\0';
	while (char_lu > 0 && !ft_strchr(stash, '\n'))
	{
		char_lu = read(fd, buff, BUFFER_SIZE);
		if (char_lu == -1)
			return (free(buff), NULL);
		buff[char_lu] = '\0';
		stash = ft_strjoin(stash, buff);
		if (!stash)
			return (free(buff), NULL);
	}
	line = addnextline(stash);
	stash = add_left_to_stash(stash);
	return (free(buff), line);
}
/*
 #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd;
	fd = open("test.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
   int	main(int argc, char **argv)
   {
   char	*str;
   int		fd;

   if (argc != 2)
   return (1);
   fd = open(argv[1], O_RDONLY);
   str = get_next_line(fd);
   while (str)
   {
  	 printf("%s", str);
  	 free(str);
  	 str = get_next_line(fd);
   }
   free(str);
   return (0);
   }
*/