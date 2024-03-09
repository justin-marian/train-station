#pragma once

#ifndef TRAIN_CAR_H
#define TRAIN_CAR_H

#include "../utils.h"

/**
 * @brief Adds a new train car to the specified platform in the train station.
 *
 * Adds a new train car with the specified weight to the given platform in the train station.
 *
 * @param station Pointer to the TrainStation structure.
 * @param platform The platform number to which the train car will be added.
 * @param weight The weight of the new train car.
 */
void add_train_car(TrainStation* station, int platform, int weight);

/**
 * @brief Fix an overloaded train on a specified platform in the train station.
 *
 * Attempts to fix an overloaded train on the specified platform in the train station.
 * It tries to remove one train car from the overloaded train to balance
 * the weight with the available locomotive power.
 *
 * @param station Pointer to the TrainStation structure.
 */
void fix_overload_train(TrainStation *station);

/**
 * @brief Move a specified number of train cars from one position to another in the train station.
 *
 * Moves a specified number of train cars
 * from position pos_a in platform_a to position pos_b in platform_b in the train station.
 *
 * @param station Pointer to the TrainStation structure.
 * @param platform_a The source platform from which the train cars are moved.
 * @param pos_a The position in platform_a from which the train cars are moved.
 * @param cars_no The number of train cars to move.
 * @param platform_b The destination platform to which the train cars are moved.
 * @param pos_b The position in platform_b to which the train cars are moved.
 */
void move_train_cars(TrainStation *station, int platform_a, int pos_a,
                    int cars_no, int platform_b, int pos_b);

/**
 * @brief Removes train cars with a specific weight from the specified platform of the train station.
 *
 * Removes all train cars with the given weight from the specified platform
 * of the train station, assuming the platform is valid and there are train cars on it.
 *
 * @param station  A pointer to the TrainStation from which the train cars will be removed.
 * @param platform The platform number from which the train cars will be removed.
 * @param weight   The weight of the train cars to be removed.
 */
void remove_train_cars(TrainStation *station, int platform, int weight);

#endif /* TRAIN_CAR_H */
