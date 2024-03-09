#include "find_train.h"

/**
 * @brief Check if the platform has a locomotive assigned (train present)
 * 
 * @param platform A pointer to the platform
 * 
 * @return True if the platform should be skipped, false otherwise
*/
static inline bool skip_platform(const Train *platform) {
    return platform->locomotive_power == -1;
}

/**
 * @brief Calculate the total weight of all train cars on the platform
 * 
 * @param station A pointer to the train station
 * 
 * @return The total weight of all train cars
*/
static int weight(TrainCar *train_cars) {
    int total_weight = 0;
    TrainCar* current_car = train_cars;

    // Sum up the weights of all train cars
    while (current_car) {
        total_weight += current_car->weight;
        current_car = current_car->next;
    }

    return total_weight;
}

int find_overload_train(TrainStation *station) {
    for (int platform = 0; platform < station->platforms_no; ++platform) {
        // Check if platform has a locomotive assigned (train present)
        if (skip_platform(station->platforms[platform])) {
            continue;
        }

        int total_weight = weight(station->platforms[platform]->train_cars);
        // Check if total weight exceeds the locomotive power
        // (indicating an overloaded train on this platform)
        if (station->platforms[platform]->locomotive_power < total_weight) {
            return platform;
        }
    }

    return -1;
}
