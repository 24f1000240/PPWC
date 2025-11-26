#include <stdio.h>
#include <string.h>

struct planet_t {
    char name[80];
    double diameter;
    int moons;
    double orbit_time;
    double rotation_time;
};

void fun_dia(double *d) {
    *d = *d + 10;
    printf("Inside func dia = %f\n", *d);
}

void fun1(struct planet_t *p1) {
    printf("printed inside fun1 %s %d %f\n", p1->name, p1->moons, p1->diameter);
    p1->moons += 1;
}

int main() {
    struct planet_t planet;
    struct planet_t *ptr = &planet;

    printf("Enter planet name: ");
    fgets(ptr->name, sizeof(ptr->name), stdin);

    printf("Enter diameter (km): ");
    scanf("%lf", &ptr->diameter);

    fun_dia(&ptr->diameter);
    printf("Inside main dia = %f\n", ptr->diameter);

    printf("Enter number of moons: ");
    scanf("%d", &ptr->moons);

    printf("Enter orbit time (years): ");
    scanf("%lf", &ptr->orbit_time);

    printf("Enter rotation time (hours): ");
    scanf("%lf", &ptr->rotation_time);

    fun1(&planet);

    printf("After fun1, moons = %d\n", planet.moons);

    return 0;
}

