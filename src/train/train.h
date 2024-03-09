#pragma once

#ifndef TRAIN_H
#define TRAIN_H

#include "../utils.h"

/**
 * @brief Arrives a train with the given locomotive power at the specified platform of the train station.
 *
 * Assigns a locomotive power to the specified platform, indicating that a train has arrived.
 * If the platform already has a locomotive power assigned, the function overwrites it with the new value.
 *
 * @param station          A pointer to the TrainStation where the train is arriving.
 * @param platform         The platform number where the train is arriving.
 * @param locomotive_power The locomotive power of the arriving train.
 */
void arrive_train(TrainStation* station, int platform, int locomotive_power);

/**
 * @brief Makes a train leave the specified platform of the train station.
 *
 * Clears the locomotive power and removes all train cars from the specified platform,
 * effectively making the train leave the station.
 *
 * @param station  A pointer to the TrainStation where the train is leaving.
 * @param platform The platform number from which the train is leaving.
 */
void leave_train(TrainStation* station, int platform);

/**
 * @brief Sorts the train cars on a platform in descending order of their weights.
 *
 * Rearranges the train cars on a platform in descending order of their weights using the merge sort algorithm.
 * If the train cars are already sorted in descending order or if there is only one train car on the platform,
 * the function returns without making any changes.
 *
 * @param station  Pointer to the TrainStation structure representing the train station.
 * @param platform The platform number where the train is located.
 */
void order_train(TrainStation *station, int platform);

/**
 * @brief Displays information about the existing trains on each platform of the train station.
 *
 * Prints the platform number, locomotive power (if available), and the weights of each train car on the platform.
 * If a platform does not have a locomotive or any train cars, it will be shown as empty.
 *
 * @param station A pointer to the TrainStation to display information for.
 * @param f       A pointer to the FILE where the information will be written.
 */
void show_existing_trains(TrainStation* station, FILE* f);

#endif /* TRAIN_H */
