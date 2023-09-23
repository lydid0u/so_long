#include "../so_long.h"

int	error_letter(t_jeu *jeu)
{
	if (jeu->perso != 1)
        return(ft_printf("Error, il faut 1 personnage !\n"), 0);
    if (jeu->exit != 1)
    	return(ft_printf("Error, il faut 1 sortie !\n"), 0);
    if (jeu->collectible < 1)
    	return(ft_printf("Error, il faut au moins un collectible !\n"), 0);
    if (jeu->nbr_ligne >= jeu->len)
    	return(ft_printf("Error, la map doit etre rectangle !\n"), 0);
    return(1);
}

int check_valid_name(char *av1)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(av1) - 1;
    if(av1[len] == 'r')
        i++;
    if(av1[len - 1] == 'e')
        i++;
    if(av1[len - 2] == 'b')
        i++;
    if(av1[len - 3] == '.')
        i++;
    if(i == 4)
        return(1);
    else
        return(ft_printf("Error\n nom de fichier invalide"), 0);
}

int	line_size(t_jeu *jeu)
{
    int i;
    int len2;


    i = 0;
    jeu->len = ft_strlen(jeu->map_parser[i]);
    while (jeu->map_parser[i])
    {
        len2 = ft_strlen(jeu->map_parser[i]);
        if (jeu->len != len2)
        {
            ft_printf("Toutes les lignes ne font pas la meme taille ! \n");
            return (0);
        }
        i++;
    }
	return(1);
}


int	check_empty(t_jeu *jeu)
{
	int	i;
	int	len;
	int	len2;

	i = 2;
	len = ft_strlen(jeu->map[1]);
	if(len != 0)
		return(1);
	while(jeu->map[i])
	{

		len2 = ft_strlen(jeu->map[i]);
		if(len2 != len)
		{
			return(1);
		}
		i++;
	}
	ft_printf("Error\n map vide");
	libere_carte(jeu->map); 
	return(0);
}

int	check_map(t_jeu *jeu)
{
    if(!(line_size(jeu)))
	{
        libere_carte(jeu->map);
        libere_carte(jeu->map_parser);		
		return(0);
	}
	if(!(mur_haut_bas(jeu)))
	{
        libere_carte(jeu->map);
        libere_carte(jeu->map_parser);		
		return(0);
	}
    if(!(contenu_ligne(jeu)))
	{
        libere_carte(jeu->map);
        libere_carte(jeu->map_parser);		
		return(0);
	}
    if(!(check_letter(jeu)))
	{
        libere_carte(jeu->map);
        libere_carte(jeu->map_parser);		
		return(0);
	}  
    return (1);
}

