#include "train_car.h"

/**
 * @brief Update the linked list of train cars on a platform
 * 
 * @param station pointer to the train station
 * @param platform index of the platform
 * @param previous_car pointer to the previous train car
 * @param current_car pointer to the current train car
*/
static void update_cars(TrainStation *station, int platform, TrainCar *previous_car, TrainCar *current_car) {
    if (previous_car) {
        previous_car->next = current_car;
    } else {
        station->platforms[platform]->train_cars = current_car;
    }
}

void remove_train_cars(TrainStation *station, int platform, int weight) {
    if (platform < 0 || platform >= station->platforms_no) return;
    if (!station->platforms[platform]->train_cars) return;

    TrainCar* current_car = station->platforms[platform]->train_cars;
    TrainCar* previous_car = NULL;

    // Traverse the linked list of train cars on the platform
    while (current_car) {
        // If the current train car has the specified weight, remove it from the linked list
        if (current_car->weight == weight) {
            TrainCar* temp = current_car;
            current_car = current_car->next;
            free(temp);
            update_cars(station, platform, previous_car, current_car);
        } else {
            // Move to the next train car and update the previous pointer
            previous_car = current_car;
            current_car = current_car->next;
        }
    }
}
