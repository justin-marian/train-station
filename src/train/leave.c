#include "train.h"

void leave_train(TrainStation* station, int platform) {
    if (platform < 0 || platform >= station->platforms_no) return;

    // Clear the locomotive power to indicate the train has left
    station->platforms[platform]->locomotive_power = -1;

    // Remove all train cars from the platform
    while (station->platforms[platform]->train_cars) {
        TrainCar* current_car = station->platforms[platform]->train_cars;
        station->platforms[platform]->train_cars = station->platforms[platform]->train_cars->next;
        free(current_car);
    }
}
