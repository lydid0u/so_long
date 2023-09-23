#include "so_long.h"

char	*copy(const char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char    **copy_map(char **map)
{
    char    **dst;
    int        i;

    i = 0;
    while (map[i])
        i++;
    dst = (char **)malloc(sizeof(char *) * (i + 1));
    if (!dst)
    	return NULL;
    i = 0;
    while (map[i])
    {
        dst[i] = copy(map[i]);
        if (dst[i] == NULL)
        {
            while (i >= 0)
                free(dst[i--]);
            return (NULL);
        }
        i++;
    }
    dst[i] = NULL;
    return (dst);
}

int    flood_fill(int x, int y, t_jeu *jeu)
{	

	if (jeu->map_flood[x][y] == '1' || jeu->map_flood[x][y] == 'V')
        return (0);
    jeu->map_flood[x][y] = 'V';
    if (flood_fill(x - 1, y, jeu) || flood_fill(x + 1, y, jeu)
        || flood_fill(x, y - 1, jeu) || flood_fill(x, y + 1, jeu))
        return (1);
    return (0);
}

int	check_flood(t_jeu *jeu)
{
	int	i;
	int	j;
	int	longueur;

	j = 0;
	i = 0;
	longueur = ft_strlen(jeu->map_flood[i]);

	while(jeu->map_flood[i] && i < jeu->nbr_ligne)
	{
		while(jeu->map_flood[i][j] && j < longueur - 1)
		{
			if (jeu->map_flood[i][0] != '1' || jeu->map_flood[i][longueur - 1] != '1')
			{
			ft_printf("endroit inaccesible \n");
    		libere_carte(jeu->map);
    		libere_carte(jeu->map_parser);
			libere_carte(jeu->map_flood);
			return(0);
			}
			else if (jeu->map_flood[i][j] != 'V' && jeu->map_flood[i][j] != '1')
			{
				ft_printf("endroit inaccesible");
				libere_carte(jeu->map);
    			libere_carte(jeu->map_parser);
				libere_carte(jeu->map_flood);		
				return(0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return(1);
}

