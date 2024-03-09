#include "find_train.h"

/**
 * @brief Skip the platform if it has no locomotive assigned (train not present)
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
 * @param platform_idx An index of the platform
 * 
 * @return The total weight of all train cars
*/
static int weight(TrainStation *station, int platform_idx) {
    int total_weight = 0;
    TrainCar *current_car = station->platforms[platform_idx]->train_cars;

    // Sum up the weights of all train cars
    while (current_car) {
        total_weight += current_car->weight;
        current_car = current_car->next;
    }

    return total_weight;
}

/**
 * @brief Find the platform with the most optimal train
 * 
 * @param station A pointer to the train station
 * 
 * @return The index of the platform with the most optimal train
*/
int find_optimal_train(TrainStation *station) {
    int optimal_platform = 0;

    // Find the first platform with a locomotive assigned (train present)
    while (station->platforms[optimal_platform]->locomotive_power < 0) {
        optimal_platform++;
    }

    // Minimum remaining power for the optimal platform
    int optimal_weight = weight(station, optimal_platform);
    int min_power = station->platforms[optimal_platform]->locomotive_power - optimal_weight;
    int optimal_station = optimal_platform;

    for (int platform = optimal_platform + 1; platform < station->platforms_no; ++platform) {
        // Skip the platform if it has no locomotive assigned (train not present)
        if (skip_platform(station->platforms[platform])) {
            continue;
        }

        // Remaining power for the current platform
        int max_weight = weight(station, platform);
        int power_rest = station->platforms[platform]->locomotive_power - max_weight;

        // Update the optimal platform if the remaining power is less
        // than the minimum remaining power found so far
        if (min_power > power_rest) {
            min_power = power_rest;
            optimal_station = platform;
        }
    }

    return optimal_station;
}
