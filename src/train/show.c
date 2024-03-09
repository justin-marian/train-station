#include "train.h"

void show_existing_trains(TrainStation* station, FILE* f) {
    if (!station) return;

    for (int platform = 0; platform < station->platforms_no; ++platform) {
        // Print the platform number
        fprintf(f, "%d: ", platform);

        // Check if the platform has a locomotive power assigned to it
        if (station->platforms[platform]->locomotive_power >= 0) {
            // Print the locomotive power for the platform
            fprintf(f, "(%d)", station->platforms[platform]->locomotive_power);

            // Print the weights of each train car on the platform
            for (TrainCar* traincar = station->platforms[platform]->train_cars; traincar; traincar = traincar->next)
                fprintf(f, "-|%d|", traincar->weight);
        }

        // Move to the next line for the next platform
        fprintf(f, "\n");
    }
}
