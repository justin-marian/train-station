#include "train_car.h"

/**
 * @brief Calculate the total weight of all train cars
 * 
 * @param train_cars pointer to the first train car in the linked list
 * 
 * @return The total weight of all train cars
*/
static int weight(TrainCar *train_cars) {
    int total_weight = 0;
    TrainCar *current_car = train_cars;

    // Sum up the weights of all train cars
    while (current_car) {
        total_weight += current_car->weight;
        current_car = current_car->next;
    }

    return total_weight;
}

/**
 * @brief Find the platform with an overloaded train
 * 
 * Find the first platform with a locomotive assigned (train present) and
 * check if the total weight exceeds the locomotive power (indicating an overloaded train).
 * 
 * @param station pointer to the train station
 * @param locomotive_power value of the locomotive power
 * @param total_weight value of the total weight
 * 
 * @return The index of the platform with an overloaded train
*/
static TrainCar* find_overloaded_car(TrainCar *train_cars, int locomotive_power, int total_weight) {
    TrainCar *overloaded_car = NULL;
    int max_locomotive_power = locomotive_power;
    TrainCar *current_car = train_cars;

    // Find the train car that contributes most to the overload based on the remaining locomotive power
    while (current_car) {
        int remaining_weight = total_weight - current_car->weight;
        int remaining_power = locomotive_power - remaining_weight;

        if (remaining_power >= 0 && remaining_power < max_locomotive_power) {
            max_locomotive_power = remaining_power;
            overloaded_car = current_car;
        }

        current_car = current_car->next;
    }

    return overloaded_car;
}

/**
 * @brief Remove the overloaded train car from the train
 * 
 * Remove the overloaded train car from the linked list of train cars on the platform and
 * update the linked list to exclude the overloaded car.
 * 
 * @param station pointer to the train station
 * @param platform_with_overload index of the platform with an overloaded train
 * @param overloaded_car pointer to the overloaded train car
 * 
 * @return The index of the platform with an overloaded train
*/
static void remove_overloaded_car(TrainStation *station, int platform_with_overload, TrainCar *overloaded_car) {
    TrainCar *current_car = station->platforms[platform_with_overload]->train_cars;
    TrainCar *previous_car = NULL;

    // Traverse the linked list to find the overloaded car and remove it
    while (current_car && current_car != overloaded_car) {
        previous_car = current_car;
        current_car = current_car->next;
    }

    // Update the linked list to exclude the overloaded car
    if (previous_car) {
        previous_car->next = overloaded_car->next;
    } else {
        station->platforms[platform_with_overload]->train_cars = overloaded_car->next;
    }

    free(overloaded_car);
}

void fix_overload_train(TrainStation *station) {
    // Find the platform with an overloaded train
    int platform_with_overload = find_overload_train(station);
    if (platform_with_overload == -1) return;
    if (!station->platforms[platform_with_overload]->train_cars) return;

    // Get locomotive power and train cars on the overloaded platform
    TrainCar *train_cars = station->platforms[platform_with_overload]->train_cars;
    int total_weight = weight(train_cars);
    int locomotive_power = station->platforms[platform_with_overload]->locomotive_power;

    // Find the train car to remove that minimizes the remaining locomotive power
    TrainCar *overloaded_car = find_overloaded_car(train_cars, locomotive_power, total_weight);

    // Remove the overloaded train car from the train
    if (overloaded_car) {
        remove_overloaded_car(station, platform_with_overload, overloaded_car);
    }
}
