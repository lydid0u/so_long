/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.h									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: adzinabi <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/07/13 23:03:19 by adzinabi		  #+#	#+#			 */
/*   Updated: 2023/07/13 23:11:02 by adzinabi		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		ft_strclen(char *str, char c);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strchr(const char *str, int c);
char	*addnextline(char *str);
char	*removeandstash(char *str);
char	*get_next_line(int fd);
char	*add_left_to_stash(char *stash);

#endif
