#include "find_train.h"

/**
 * @brief Check if the platform has an express train
 * 
 * @param platform A pointer to the platform
 * 
 * @return True if the platform has an express train, false otherwise
*/
static inline bool skip_platform(const Train *platform) {
    return platform->locomotive_power == -1;
}

/**
 * @brief Calculate the total weight of all train cars
 * 
 * @param train_cars A pointer to the first train car in the linked list
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

int find_express_train(TrainStation *station) {
    int max_diff = -1, platform_express = -1;

    for (int platform = 0; platform < station->platforms_no; ++platform) {        
        // Check if platform has an express train
        if (skip_platform(station->platforms[platform])) {
            continue;
        }

        int locomotive_power = station->platforms[platform]->locomotive_power;
        // Total weight of all train cars
        int total_weight = weight(station->platforms[platform]->train_cars);
        // Difference between locomotive power and total train weight
        int diff = locomotive_power - total_weight;

        // Update if higher difference found
        if (diff > max_diff) {
            max_diff = diff;
            platform_express = platform;
        }
    }

    return platform_express;
}
