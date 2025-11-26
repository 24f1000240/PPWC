#include <stdio.h>
#include <string.h>

struct planet_t {
    char name[80];
    double diameter;
    int moons;
    double orbit_time;
    double rotation_time;
};

struct planet_t get_planet(void) {
    struct planet_t planet;

    printf("Enter: name diameter moons orbit-time rotation-time\n");
    scanf("%s %lf %d %lf %lf",
          planet.name,
          &planet.diameter,
          &planet.moons,
          &planet.orbit_time,
          &planet.rotation_time);

    return planet;
}

int main() {
    struct planet_t planet;
    
    planet = get_planet();
    
    printf("Planet: %s, Diameter: %.2f, Moons: %d, Orbit time: %.2f, Rotation time: %.2f\n",
       planet.name,
       planet.diameter,
       planet.moons,
       planet.orbit_time,
       planet.rotation_time);

    return 0;
}

