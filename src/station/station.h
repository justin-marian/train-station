#pragma once

#ifndef STATION_H
#define STATION_H

#include "../utils.h"

/**
 * @brief Closes the train station and releases all the allocated memory for the platforms and train cars.
 *
 * @param station A pointer to the TrainStation to be closed.
 */
void close_train_station(TrainStation *station);

/**
 * @brief Creates and initializes a new TrainStation with the given number of platforms.
 *
 * @param platforms_no The number of platforms in the train station.
 * 
 * @return A pointer to the newly created TrainStation.
 */
TrainStation* open_train_station(int platforms_no);

#endif /* STATION_H */
