/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:02:57 by maalexan          #+#    #+#             */
/*   Updated: 2024/04/10 21:08:32 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/*
Test
*/


t_vec3f get_object_base_color(t_object *object) {
    if (!object) return (t_vec3f){0, 0, 0};  // Return black or some default color if there's no object

    switch (object->type) {
        case SPHERE:
            return object->data.sphere->rgb;
        case PLANE:
            return object->data.plane->rgb;
        case CYLINDER:
            return object->data.cylinder->rgb;
        default:
            return (t_vec3f){0, 0, 0};  // Return black or some default color for unknown types
    }
}


void render_scene_from_framebuffer(const t_scene *scene, mlx_image_t *image) {
    // Convert the ambient color to an integer value
    int ambient_color = float_to_int_rgb(scene->ambient->rgb);

    for (int y = 0; y < WIN_HEIGHT; ++y) {
        for (int x = 0; x < WIN_WIDTH; ++x) {
            t_intersect *intersect = scene->fb.intersections[y * WIN_WIDTH + x];

            if (intersect) {
                // Assuming you have a function to get the base color of the object
                t_vec3f base_color = get_object_base_color(intersect->object);

                // Convert the color to int and set the pixel color
                int color = float_to_int_rgb(base_color);
                mlx_put_pixel(image, x, y, color);
            } else {
                // Use the ambient light color as the background color
                mlx_put_pixel(image, x, y, ambient_color);
            }
        }
    }
}

void test_framebuffer(const t_scene *scene) {
    for (int y = 0; y < WIN_HEIGHT; ++y) {
        for (int x = 0; x < WIN_WIDTH; ++x) {
            t_intersect *intersect = scene->fb.intersections[y * WIN_WIDTH + x];
            printf("Pixel [%d, %d]: ", x, y);
            if (intersect) {
                printf("Hit Object - Distance: %f, ", intersect->distance);
                printf("Point: (%f, %f, %f), ", intersect->point.x, intersect->point.y, intersect->point.z);
                printf("Normal: (%f, %f, %f)\n", intersect->normal.x, intersect->normal.y, intersect->normal.z);
            } else {
                printf("No intersection\n");
            }
        }
    }
}


/*
EndTest
*/


t_scene	*get_scene(void)
{
	static t_scene	scene;

	return (&scene);
}
/*
int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_scene		*scene;

	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "miniRT", false);
	if (!mlx)
		return (1);
	apply_validations(argc, argv);
	scene = get_scene();
	print_scene(scene);
	render_scene_from_framebuffer(scene, image);
	mlx_key_hook(mlx, key_hook, mlx);
	mlx_close_hook(mlx, close_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
*/

int main(int argc, char **argv) {
    mlx_t *mlx;
    mlx_image_t *image;
    t_scene *scene;

    mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "miniRT", false);
    if (!mlx)
        return (1);

    apply_validations(argc, argv);
    scene = get_scene();
    print_scene(scene);

    // Create a new image
    image = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
    if (!image) {
        mlx_terminate(mlx);
        return (1); // Handle the error appropriately
    }

	test_framebuffer(scene);
    // Render the scene into the image
    render_scene_from_framebuffer(scene, image);

    // Put the image to the window, assuming you have a window created
    mlx_image_to_window(mlx, image, 0, 0);

    // Set up hooks
    mlx_key_hook(mlx, key_hook, mlx);
    mlx_close_hook(mlx, close_hook, mlx);

    // Enter the event loop
    mlx_loop(mlx);

    // Cleanup
    mlx_delete_image(mlx, image);  // Clean up the image when done
    mlx_terminate(mlx);
    return (0);
}
