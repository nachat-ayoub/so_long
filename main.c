#include "so_long.h"


int main()
{
	void	*mlx_ptr;
	void	*mlx_win;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	mlx_win = mlx_new_window(mlx_ptr, get_map_width()*BLOCK_SIZE, get_map_height()*BLOCK_SIZE,
	"My 2d Game");

	printf("\nMap w: %d", get_map_width());
	printf("\nMap h: %d\n", get_map_height());

	draw_map(mlx_ptr, mlx_win);

	// game loop
	mlx_loop(mlx_ptr);
	// clear things
	mlx_destroy_window(mlx_ptr, mlx_win);
	free(mlx_ptr);
}