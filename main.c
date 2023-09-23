#include "so_long.h"

int main(int argc, char **argv)
{
	static t_jeu jeu = {0}; // remettre tout ce quil y a dans jeu a 0 et etre sur quil reste aucune valeur dedans
	int i;
	if (argc == 2)
	{
		if (!(check_valid_name(argv[1])))
			return (0);
		i = 0;

		if (!(creation_carte(argv[1], &jeu)))
			return (0);
		// if(!(check_empty(&jeu)))
		// 	return(0);
		jeu.map_parser = copy_map(jeu.map);
		if (!(check_map(&jeu)))
			return (0);
		jeu.map_flood = copy_map(jeu.map);

		flood_fill(jeu.x, jeu.y, &jeu);
		if (!(check_flood(&jeu)))
			return (0);
		i = 0;
		while (jeu.map_flood[i])
		{
			ft_printf("%s\n", jeu.map_flood[i]);
			i++;
		}
		libere_carte(jeu.map);
		libere_carte(jeu.map_parser);
		libere_carte(jeu.map_flood);
	}

	return (0);
}