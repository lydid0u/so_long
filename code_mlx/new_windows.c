// #include "../so_long.h"

// int on_destroy(t_mlx *mlx)
// {
// 	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
// 	mlx_destroy_display(mlx->mlx_ptr);
// 	free(mlx->mlx_ptr);
// 	exit(0);
// 	return (0);
// }
 
// int on_keypress(int keysym, t_mlx *mlx) // keysym = nom de touche
// {
// 	(void)mlx;
// 	ft_printf("Pressed key: %d\n", keysym);
// 	return (0);
// }




// int main(void)
// {
// 	t_mlx mlx;
// 	//t_jeu jeu;

// 	mlx.mlx_ptr = mlx_init();
// 	if (!mlx.mlx_ptr)
// 		return (1);
// 	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "windows :)");
// 	if (!mlx.win_ptr)
// 		return (free(mlx.mlx_ptr), 1);

// 	mlx.largeur = 50;
// 	mlx.hauteur = 50;

// 	mlx.collectible = mlx_xpm_file_to_image(mlx.mlx_ptr, "viande.xpm", &mlx.largeur, &mlx.hauteur);
		

// 	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.collectible, 500, 100);


// 	// // enregistrer donnee de la touche qu'on relache
// 	// mlx_hook(mlx.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &mlx);
 
// 	// // enregistrer la destruction de la fenetre
// 	// mlx_hook(mlx.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &mlx);
 
// 	mlx_loop(mlx.mlx_ptr);
// 	return (0);
// }