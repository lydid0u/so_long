/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   map_checker.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/09/24 14:45:46 by lboudjel		  #+#	#+#			 */
/*   Updated: 2023/10/06 12:07:06 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../so_long.h"

void	nbr_of_line(char *av1, t_jeu *jeu)
{
	int		fd;
	char	*line;

	jeu->nbr_ligne = 0;
	fd = open(av1, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		if (line == NULL)
			break ;
		free(line);
		line = get_next_line(fd);
		jeu->nbr_ligne++;
	}
	free(line);
	close(fd);
}

int	create_map(char *av1, t_jeu *jeu, int i)
{
	int		fd;
	char	*line;

	fd = open(av1, O_RDONLY);
	if (fd == -1 || read(fd, &line, 0) < 0)
		return (ft_printf("Error\nThere is an error with the file !\n"), 0);
	nbr_of_line(av1, jeu);
	if (jeu->nbr_ligne <= 1)
		return (ft_printf("Error\nNot enough lines !"), 0);
	if (jeu->nbr_ligne > 16)
		return (ft_printf("Error\nToo many lines !"), 0);
	jeu->map = malloc(sizeof(char *) * (jeu->nbr_ligne + 1));
	if (!jeu->map)
		return (free(jeu->map), 0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		jeu->map[i] = copy(line);
		free(line);
		i++;
	}
	jeu->map[i] = NULL;
	return (close(fd), 1);
}

int	check_letter(t_jeu *jeu)
{
	int	i;
	int	j;

	i = 0;
	while (jeu->map_p[i])
	{
		j = 0;
		while (jeu->map_p[i][j])
		{
			if (jeu->map_p[i][j] == 'C')
				jeu->coin++;
			else if (jeu->map_p[i][j] == 'P')
				jeu->perso++;
			else if (jeu->map_p[i][j] == 'D')
				jeu->nmi++;
			else if (jeu->map_p[i][j] == 'E')
				find_pos_exit(jeu, i, j);
			j++;
		}
		i++;
	}
	if (!(error_letter(jeu)))
		return (0);
	return (1);
}

int	check_valid_name(char *av1)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(av1) - 1;
	if (av1[len] == 'r')
		i++;
	if (av1[len - 1] == 'e')
		i++;
	if (av1[len - 2] == 'b')
		i++;
	if (av1[len - 3] == '.')
		i++;
	if (i == 4)
		return (1);
	else
		return (ft_printf("Error\nFile's name is not valid !"), 0);
}

int	check_map(t_jeu *jeu)
{
	if (!(line_size(jeu)))
	{
		free_map(jeu->map);
		free_map(jeu->map_p);
		return (0);
	}
	if (!(wall_up_down(jeu)))
	{
		free_map(jeu->map);
		free_map(jeu->map_p);
		return (0);
	}
	if (!(content_line(jeu, 1)))
	{
		free_map(jeu->map);
		free_map(jeu->map_p);
		return (0);
	}
	if (!(check_letter(jeu)))
	{
		free_map(jeu->map);
		free_map(jeu->map_p);
		return (0);
	}
	return (1);
}
