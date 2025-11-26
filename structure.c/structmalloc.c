#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct planet_t {
    char name[80];
    double diameter;
    int moons;
    double orbit_time;
    double rotation_time;
};

int main() {
    struct planet_t planet;
    struct planet_t *ptr = &planet;  // pointer to structure
    
    ptr = (struct planet *)malloc(sizeof(struct planet_t));
    
    printf("Enter planet name: ");
    fgets((*ptr).name, sizeof((*ptr).name), stdin);

    printf("Enter diameter (km): ");
    scanf("%lf", &((*ptr).diameter));

    printf("Enter number of moons: ");
    scanf("%d", &((*ptr).moons));

    printf("Enter orbit time (years): ");
    scanf("%lf", &((*ptr).orbit_time));

    printf("Enter rotation time (hours): ");
    scanf("%lf", &((*ptr).rotation_time));

    printf("\n--- Planet Data Entered ---\n");
    printf("Name: %s", (*ptr).name);
    printf("Diameter: %.2f km\n", (*ptr).diameter);
    printf("Moons: %d\n", (*ptr).moons);
    printf("Orbit Time: %.2f years\n", (*ptr).orbit_time);
    printf("Rotation Time: %.3f hours\n", (*ptr).rotation_time);

    return 0;
}

