#include "station.h"

void close_train_station(TrainStation* station) {
    if (!station) return;

    for (int platform = 0; platform < station->platforms_no; ++platform) {
        // Free all the train cars on the current platform
        while (station->platforms[platform]->train_cars) {
            TrainCar* current_car = station->platforms[platform]->train_cars;
            station->platforms[platform]->train_cars = station->platforms[platform]->train_cars->next;
            free(current_car);
        }

        // Free the memory allocated for the current platform
        free(station->platforms[platform]);
        station->platforms[platform] = NULL;
    }

    free(station->platforms);
    station->platforms = NULL;
    free(station);
}
