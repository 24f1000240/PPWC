#include <stdio.h>
#include <string.h>

struct planet_t {
    char name[80];
    double diameter;
    int moons;
    double orbit_time;
    double rotation_time;
};

int main() {
    struct planet_t current_planet;

    printf("Enter planet name: ");
    fgets(current_planet.name, sizeof(current_planet.name), stdin);

    printf("Enter diameter (km): ");
    scanf("%lf", &current_planet.diameter);

    printf("Enter number of moons: ");
    scanf("%d", &current_planet.moons);

    printf("Enter orbit time (years): ");
    scanf("%lf", &current_planet.orbit_time);

    printf("Enter rotation time (hours): ");
    scanf("%lf", &current_planet.rotation_time);

    printf("\n--- Planet Data Entered ---\n");
    printf("Name: %s", current_planet.name);
    printf("Diameter: %.2f km\n", current_planet.diameter);
    printf("Moons: %d\n", current_planet.moons);
    printf("Orbit Time: %.2f years\n", current_planet.orbit_time);
    printf("Rotation Time: %.3f hours\n", current_planet.rotation_time);

    return 0;
}

