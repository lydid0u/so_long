#include "../so_long.h"

void nombredeligne(char *av1, t_jeu *jeu)
{
	int fd;
	char *line;

	jeu->nbr_ligne = 0;

	fd = open(av1, O_RDONLY);
	if (fd == -1)
		return;
	line = get_next_line(fd);
	while (line)
	{
		if (line == NULL)
			break;
		free(line);
		line = get_next_line(fd);

		jeu->nbr_ligne++;
	}
	free(line);
	close(fd);
}

int libere_carte(char **carte)
{
	int i;

	if (!carte)
		return (0);

	i = 0;
	while (carte[i])
	{
		free(carte[i]);
		i++;
	}
	free(carte);
	carte = NULL;
	return (1);
}

int creation_carte(char *av1, t_jeu *jeu)
{
	int fd;
	int i;

	char *line;

	i = 0;
	fd = open(av1, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nLe fichier n'existe pas\n"), 0);
	nombredeligne(av1, jeu);
	if (jeu->nbr_ligne <= 1)
		return (ft_printf("Error\n pas asser de ligne"), 0);
	jeu->map = malloc(sizeof(char *) * (jeu->nbr_ligne + 1));
	if (!jeu->map)
		return (free(jeu->map), 0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		jeu->map[i] = copy(line);
		free(line);
		i++;
	}
	jeu->map[i] = NULL;
	close(fd);
	return (1);
}

int mur_haut_bas(t_jeu *jeu)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (jeu->map_parser[0][i])
	{
		if (jeu->map_parser[0][i] != '1' && jeu->map_parser[0][i] != '\n')
		{
			ft_printf("Erreur, le mur du haut ne doit contenir que des 1 !");
			return (0);
		}
		i++;
	}
	while (jeu->map_parser[jeu->nbr_ligne - 1][j])
	{
		if (jeu->map_parser[jeu->nbr_ligne - 1][j] != '1' && jeu->map_parser[jeu->nbr_ligne - 1][j] != '\n')
		{
			ft_printf("Erreur, le mur du bas ne doit contenir que des 1 !");
			return (0);
		}
		j++;
	}
	return (1);
}

int contenu_ligne(t_jeu *jeu)
{
	int i = 1;
	int j;
	int longueur;
	int v;

	v = 0;
	j = 0;
	longueur = ft_strlen(jeu->map_parser[i]);
	while (i < jeu->nbr_ligne - 1)
	{
		while (jeu->map_parser[i][j] && j < longueur - 1)
		{
			if (jeu->map_parser[i][0] != '1' || jeu->map_parser[i][longueur - 1] != '1')
			{
				ft_printf("Erreur : les extrémités ne doivent contenir que des 1 !\n");
				return (0);
			}
			else if (jeu->map_parser[i][j] != '0' && jeu->map_parser[i][j] != '1' && jeu->map_parser[i][j] != 'C' && jeu->map_parser[i][j] != 'P' && jeu->map_parser[i][j] != 'E')
			{
				ft_printf("Erreur : caractère incompatible\n");
				return (0);
			}
			if (jeu->map_parser[i][j] == 'P')
			{
				jeu->x = i;
				jeu->y = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int check_letter(t_jeu *jeu)
{
	int i;
	int j;

	i = 0;
	while (jeu->map_parser[i])
	{
		j = 0;
		while (jeu->map_parser[i][j])
		{
			if (jeu->map_parser[i][j] == 'C')
				jeu->collectible = jeu->collectible + 1;
			else if (jeu->map_parser[i][j] == 'P')
			{
				jeu->perso = jeu->perso + 1;
				if (jeu->map_parser[i][j] == 'P')
				{

					jeu->x = i;
					jeu->y = j;
				}
			}
			else if (jeu->map_parser[i][j] == 'E')
				jeu->exit = jeu->exit + 1;
			j++;
		}
		i++;
	}
	if (!(error_letter(jeu)))
		return (0);
	return (1);
}