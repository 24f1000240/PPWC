#include <stdio.h>
#include <string.h>

struct planet_t {
    char name[80];
    double diameter;
    int moons;
    double orbit_time;
    double rotation_time;
};

void print_planet(struct planet_t *p1) {
    printf("\n--- Planet Data Entered ---\n");
    printf("Name: %s", p1->name);
    printf("Diameter: %.2f km\n", p1->diameter);
    printf("Moons: %d\n", p1->moons);
    printf("Time to complete 1 orbit: %.2f years\n", p1->orbit_time);
    printf("Time to complete 1 rotation: %.3f hours\n", p1->rotation_time);
}

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

    print_planet(&current_planet);

    return 0;
}

