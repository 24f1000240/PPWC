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
    printf("Name: %s\n", p1->name);
    printf("Diameter: %lf km\n", p1->diameter);
    printf("Moons: %d\n", p1->moons);
    printf("Time to complete 1 orbit: %.2f years\n", p1->orbit_time);
    printf("Time to complete 1 rotation: %.3f hours\n", p1->rotation_time);
}

void scan_planet(struct planet_t *p2) {
    printf("Enter planet name: ");
    scanf("%s", p2->name); 
    printf("Enter diameter (km): ");
    scanf("%lf", &p2->diameter);
    printf("Enter number of moons: ");
    scanf("%d", &p2->moons);
    printf("Enter orbit time (years): ");
    scanf("%lf", &p2->orbit_time);
    printf("Enter rotation time (hours): ");
    scanf("%lf", &p2->rotation_time);
}

int main() {
    struct planet_t current_planet;

    scan_planet(&current_planet);
    print_planet(&current_planet);

    return 0;
}

