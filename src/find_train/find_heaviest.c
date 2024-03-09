#include "find_train.h"

/**
 * @brief Check if the platform should be skipped
 * 
 * @param platform pointer to the platform
 * 
 * @return True if the platform should be skipped, false otherwise
*/
static inline bool skip_platform(const Train *platform) {
    return platform->locomotive_power == -1 || platform->train_cars == NULL;
}

/**
 * @brief Traverse the train cars and calculate the total weight and sequence length
 * 
 * @param start pointer to the first train car in the sequence
 * 
 * @param cars_no number of cars in the sequence
*/
static void traverse_cars(const TrainCar *start, int cars_no, int *total_weight, int *sequence_length) {
    const TrainCar *current = start;
    *total_weight = 0, *sequence_length = 0;

    // Sum up the weights of all train cars
    while (current != NULL && *sequence_length < cars_no) {
        *total_weight += current->weight;
        current = current->next;
        (*sequence_length)++;
    }
}

int find_heaviest_sequence_train(TrainStation *station, int cars_no, TrainCar **start_car) {
    int max_weight = -1, platform_heaviest = -1;
    *start_car = NULL;

    for (int platform = 0; platform < station->platforms_no; ++platform) {
        if (skip_platform(station->platforms[platform])) {
            continue;
        }

        // Iterate through the train cars on the platform
        TrainCar* current_car = station->platforms[platform]->train_cars;
        while (current_car) {
            int sequence_weight, sequence_length;
            // Weight and length of the current sequence
            traverse_cars(current_car, cars_no, &sequence_weight, &sequence_length);

            // Check if the sequence length matches the required number of cars and if the weight is higher
            if (sequence_length == cars_no && sequence_weight > max_weight) {
                max_weight = sequence_weight;
                platform_heaviest = platform;
                *start_car = current_car;
            }

            current_car = current_car->next;
        }
    }

    return platform_heaviest;
}
