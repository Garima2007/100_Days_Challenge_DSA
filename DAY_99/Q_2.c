/*
853. Car Fleet
Constraints:

n == position.length == speed.length
1 <= n <= 105
0 < target <= 106
0 <= position[i] < target
All the values of position are unique.
0 < speed[i] <= 106
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    double time;
} Car;

int compare(const void *a, const void *b) {
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;
    return c2->position - c1->position;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    Car *cars = (Car *)malloc(sizeof(Car) * positionSize);

    for (int i = 0; i < positionSize; i++) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    qsort(cars, positionSize, sizeof(Car), compare);

    int fleets = 0;
    double prevTime = 0;

    for (int i = 0; i < positionSize; i++) {
        if (cars[i].time > prevTime) {
            fleets++;
            prevTime = cars[i].time;
        }
    }

    free(cars);
    return fleets;
}
