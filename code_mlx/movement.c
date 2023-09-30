#include "../so_long.h" 

int	ft_move(int keysym, t_jeu *jeu)
{
	if (keysym == 65307)
	{
		free_all(jeu);
		disconnect(jeu);
		exit(EXIT_SUCCESS);
	}
	if (keysym == 65363 || keysym == 100)
    {
		go_right(jeu);
        // ft_printf("number of steps : %d\n", jeu->steps);
    }
	if (keysym == 65361 || keysym == 97)
    {
		go_left(jeu);
        // ft_printf("number of steps : %d\n", jeu->steps);
    }
	if (keysym == 65362 || keysym == 119)
    {
		go_up(jeu);
        // ft_printf("number of steps : %d\n", jeu->steps);
    }
	if (keysym == 65364 || keysym == 115)
    {
		go_down(jeu);
        // ft_printf("number of steps : %d\n", jeu->steps);
    }
    // if (keysym == 46)
	// {
	//     mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->end, 0, 0);
    //     if (keysym == 46)
    //     {
    //         mlx_destroy_image(jeu->mlx_ptr, jeu->end);
	//         mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->end_two, 0, 0);
	//         printf("salut");
    //     }
	// }
    // if (jeu->map_p[jeu->x][jeu->y] == 'E' )
    // end_frame(XK_space, jeu);
	return (0);
}

// void moveEnemies(t_jeu *jeu) 
// {
//     // Initialisez un pointeur vers le premier ennemi dans la liste
//     t_enemy *ennemi = jeu->nmi;

//     // Parcourez la liste des ennemis
//     while (ennemi != NULL) 
//     {
//         // Mettez à jour la position de l'ennemi en fonction de sa direction
//         // Par exemple, pour faire avancer l'ennemi vers la droite
//         ennemi->x += 1;
//         if (jeu->map_p[jeu->x][jeu->y + 1] == '1' || jeu->map_p[jeu->x][jeu->y + 1] == 'E' || jeu->map_p[jeu->x][jeu->y + 1] == 'D')
// 		return ;

//         // Rafraîchissez l'affichage de l'ennemi à sa nouvelle position
//         mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, ennemi->img, ennemi->x * 64, ennemi->y * 64);

//         // Passez à l'ennemi suivant dans la liste
//         ennemi = ennemi->next;
//     }
// }

void	go_right(t_jeu *jeu)
{
	if ((jeu->map_p[jeu->x][jeu->y + 1] == 'E' && jeu->coin == 0) || jeu->map_p[jeu->x][jeu->y + 1] == 'D')
	{
		if(jeu->map_p[jeu->x][jeu->y + 1] == 'D')
			ft_printf("Don Paolo ruined your tea party :(\n");
        if(jeu->map_p[jeu->x][jeu->y + 1] == 'E' && jeu->coin == 0)
			ft_printf("Yayyy congratulations!! Now it's time to make the dishes :)\n");
		free_all(jeu);
		disconnect(jeu);
		exit(EXIT_SUCCESS);
	}
	if (jeu->map_p[jeu->x][jeu->y + 1] == '1' || jeu->map_p[jeu->x][jeu->y + 1] == 'E')
		return ;
	if (jeu->map_p[jeu->x][jeu->y + 1] == 'C')
	{
		jeu->coin--;
		jeu->map_p[jeu->x][jeu->y + 1] = '0';
	}
    print_moves(jeu);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_floor, jeu->y * 64, jeu->x * 64);
	jeu->y = jeu->y + 1;
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_right, jeu->y * 64, jeu->x * 64);
}

void	go_left(t_jeu *jeu)
{
	if ((jeu->map_p[jeu->x][jeu->y - 1] == 'E' && jeu->coin == 0) || jeu->map_p[jeu->x][jeu->y - 1] == 'D')
	{
		if(jeu->map_p[jeu->x][jeu->y - 1] == 'D')
			ft_printf("Don Paolo ruined your tea party :(\n");
        if(jeu->map_p[jeu->x][jeu->y - 1] == 'E' && jeu->coin == 0)
			ft_printf("Yayyy congratulations!! Now it's time to make the dishes :)\n");
		free_all(jeu);
		disconnect(jeu);
		exit(EXIT_SUCCESS);
	}
	if (jeu->map_p[jeu->x][jeu->y - 1] == '1' || jeu->map_p[jeu->x][jeu->y - 1] == 'E')
		return ;
	if (jeu->map_p[jeu->x][jeu->y - 1] == 'C')
	{
		jeu->coin--;
		jeu->map_p[jeu->x][jeu->y - 1] = '0';
	}
    print_moves(jeu);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_floor, jeu->y * 64, jeu->x * 64);
	jeu->y = jeu->y - 1;
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_left, jeu->y * 64, jeu->x * 64);
}

void	go_up(t_jeu *jeu)
{
	if ((jeu->map_p[jeu->x - 1][jeu->y] == 'E' && jeu->coin == 0) || jeu->map_p[jeu->x - 1][jeu->y] == 'D')
	{
		if(jeu->map_p[jeu->x - 1][jeu->y] == 'D')
			ft_printf("Don Paolo ruined your tea party :(\n");
        if(jeu->map_p[jeu->x - 1][jeu->y] == 'E' && jeu->coin == 0)
			ft_printf("Yayyy congratulations!! Now it's time to make the dishes :)\n");
		free_all(jeu);
		disconnect(jeu);
		exit(EXIT_SUCCESS);
	}
	if (jeu->map_p[jeu->x - 1][jeu->y] == '1' || jeu->map_p[jeu->x - 1][jeu->y] == 'E')
		return ;
	if (jeu->map_p[jeu->x - 1][jeu->y] == 'C')
	{
		jeu->coin--;
		jeu->map_p[jeu->x - 1][jeu->y] = '0';
	}
    print_moves(jeu);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_floor, jeu->y * 64, jeu->x * 64);
	jeu->x = jeu->x - 1;
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_perso, jeu->y * 64, jeu->x * 64);
}

void	go_down(t_jeu *jeu)
{
	if ((jeu->map_p[jeu->x + 1][jeu->y] == 'E' && jeu->coin == 0) || jeu->map_p[jeu->x + 1][jeu->y] == 'D')
	{
		if(jeu->map_p[jeu->x + 1][jeu->y] == 'D')
			ft_printf("Don Paolo ruined your tea party :(\n");
        if(jeu->map_p[jeu->x + 1][jeu->y] == 'E' && jeu->coin == 0)
			ft_printf("Yayyy congratulations!! Now it's time to make the dishes :)\n");
		free_all(jeu);
		disconnect(jeu);
		exit(EXIT_SUCCESS);
	}
	if (jeu->map_p[jeu->x + 1][jeu->y] == '1' || jeu->map_p[jeu->x + 1][jeu->y] == 'E')
		return ;
	if (jeu->map_p[jeu->x + 1][jeu->y] == 'C')
	{
		jeu->coin--;
		jeu->map_p[jeu->x + 1][jeu->y] = '0';
	}
    print_moves(jeu);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_floor, jeu->y * 64, jeu->x * 64);
	jeu->x = jeu->x + 1;
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_perso, jeu->y * 64, jeu->x * 64);
}
