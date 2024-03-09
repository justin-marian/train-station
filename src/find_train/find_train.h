#pragma once

#ifndef FIND_TRAIN_H
#define FIND_TRAIN_H

#include "../utils.h"

/**
 * @brief Find the platform with hosting the express train with the greatest disparity
 * between locomotive power and total train weight.
 *
 * @param station A pointer to the TrainStation structure.
 *
 * @return Index of the platform with the heaviest sequence,or -1 if none found.
 */
int find_express_train(TrainStation *station);

/**
 * @brief Find the platform with the heaviest sequence of train cars.
 *
 * Calculates the weight of each sequence  of 'carsNo' consecutive train cars.
 * Stores the pointer to the first train car of the heaviest sequence in 'firstCar'.
 *
 * @param station  Pointer to the TrainStation structure.
 * @param carsNo   Number of consecutive train cars to consider.
 * @param firstCar Pointer to the first train car in the heaviest sequence.
 *
 * @return Index of the platform with the heaviest sequence,or -1 if none found.
 */
int find_heaviest_sequence_train(TrainStation *station, int carsNo, TrainCar **firstCar);

/**
 * @brief Find the optimal train platform based on remaining locomotive power.
 * 
 * Determines the optimal platform for the train based on the remaining
 * locomotive power after considering the total weight on each platform.
 * 
 * @param station Pointer to the TrainStation structure.
 * 
 * @return The index of the optimal train platform, or -1 if no valid platform is found.
 */
int find_optimal_train(TrainStation *station);

/**
 * @brief Find the platform index of an overloaded train.
 * 
 * Determines the platform index of an overloaded train in the given TrainStation.
 * 
 * @param station Pointer to the TrainStation structure.
 * 
 * @return The index of the overloaded train platform, or -1 if none.
 */
int find_overload_train(TrainStation *station);

#endif /* FIND_TRAIN_H */
