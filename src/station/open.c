#include "station.h"

TrainStation* open_train_station(int platforms_no) {
    TrainStation* station = (TrainStation*)malloc(sizeof(TrainStation));
    if (!station) return NULL;

    station->platforms_no = platforms_no;
    station->platforms = (Train**)malloc(platforms_no * sizeof(Train*));
    if (!station->platforms) {
        free(station);
        return NULL;
    }

    for (int platform = 0; platform < platforms_no; ++platform) {
        // Allocate memory for each platform structure
        station->platforms[platform] = (Train*)malloc(sizeof(Train));

        if (!station->platforms[platform]) {
            // Free memory for the platforms and the station
            for (int idx_p = 0; idx_p < platform; ++idx_p) {
                free(station->platforms[idx_p]);
            }
            free(station->platforms);
            free(station);
            return NULL;
        }

        station->platforms[platform]->locomotive_power = -1;
        station->platforms[platform]->train_cars = NULL;
    }

    return station;
}
