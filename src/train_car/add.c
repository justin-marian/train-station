#include "train_car.h"

void add_train_car(TrainStation* station, int platform, int weight) {
    if (platform < 0 || platform >= station->platforms_no) return;
    if (station->platforms[platform]->locomotive_power == -1 || weight < 0) return;

    TrainCar* new_train_car = (TrainCar*)malloc(sizeof(TrainCar));
    if (!new_train_car) return;

    // Initialize the new train car
    new_train_car->weight = weight;
    new_train_car->next = NULL;

    // Add the new train car to the platform's linked list of train cars
    if (!station->platforms[platform]->train_cars) {
        station->platforms[platform]->train_cars = new_train_car;
    } else {
        TrainCar* current_car = station->platforms[platform]->train_cars;
        while (current_car->next) {
            current_car = current_car->next;
        }
        current_car->next = new_train_car;
    }
}
