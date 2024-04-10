#include "minirt.h"

void print_vec3f(const char* name, t_vec3f vec) {
    printf("%s: (%f, %f, %f)\n", name, vec.x, vec.y, vec.z);
}

void print_scene(const t_scene* scene) {
    if (scene->ambient) {
        printf("Ambient:\n");
        printf(" Ratio: %f\n", scene->ambient->ratio);
        print_vec3f(" RGB", scene->ambient->rgb);
    }

    if (scene->camera) {
        printf("\nCamera:\n");
        print_vec3f(" Coords", scene->camera->coords);
        print_vec3f(" Norm Vector", scene->camera->norm_vector);
        printf(" FOV: %d\n", scene->camera->horiz_fov);
    }

    if (scene->light) {
        printf("\nLight:\n");
        print_vec3f(" Coords", scene->light->coords);
        printf(" Brightness Ratio: %f\n", scene->light->bright_ratio);
        print_vec3f(" RGB", scene->light->rgb);
    }

    printf("\nObjects:\n");
    t_object* obj = scene->objects;
    while (obj != NULL) {
        switch (obj->type) {
            case SPHERE:
                printf("Sphere:\n");
                print_vec3f(" Coords", obj->data.sphere->coords);
                printf(" Diameter: %f\n", obj->data.sphere->diameter);
                print_vec3f(" RGB", obj->data.sphere->rgb);
                break;
            case PLANE:
                printf("Plane:\n");
                print_vec3f(" Coords", obj->data.plane->coords);
                print_vec3f(" Norm Vector", obj->data.plane->norm_vector);
                print_vec3f(" RGB", obj->data.plane->rgb);
                break;
            case CYLINDER:
                printf("Cylinder:\n");
                print_vec3f(" Coords", obj->data.cylinder->coords);
                print_vec3f(" Norm Vector", obj->data.cylinder->norm_vector);
                printf(" Diameter: %f\n", obj->data.cylinder->diameter);
                printf(" Height: %f\n", obj->data.cylinder->height);
                print_vec3f(" RGB", obj->data.cylinder->rgb);
                break;
            default:
                printf("Unknown object type\n");
        }
        obj = obj->next;
        if (obj != NULL) printf("\n");
    }
}
