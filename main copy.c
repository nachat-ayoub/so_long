#include "so_long.h"




int render_frame(t_game *game)
{
    // This code will run every frame
    printf("Rendering frame...\n");

	draw_map(game->mlx_ptr, game->mlx_win, game);

    // You can use the `param` argument to access any custom data
    // Example: Cast `param` to your data structure if needed
    // struct my_data *data = (struct my_data *)param;

    // Return 0 or 1 (returning non-zero may stop the loop in some implementations)
    return 0;
}

int main()
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_game	*game;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	mlx_win = mlx_new_window(mlx_ptr, get_map_width()*BLOCK_SIZE, get_map_height()*BLOCK_SIZE, "My 2d Game");

	printf("\nMap w: %d", get_map_width());
	printf("\nMap h: %d\n", get_map_height());

	game->player_x = 0;
	game->player_y = 0;
	draw_map(mlx_ptr, mlx_win, game);
	mlx_loop_hook(mlx_ptr, render_frame, game);

	// game loop
	mlx_loop(mlx_ptr);
	// clear things
	mlx_destroy_window(mlx_ptr, mlx_win);
	free(mlx_ptr);
}