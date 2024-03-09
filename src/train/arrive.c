
#include "train.h"

void arrive_train(TrainStation* station, int platform, int locomotive_power) {
    if (platform < 0 || platform >= station->platforms_no) return;
    if (station->platforms[platform]->locomotive_power != -1) return;

    // Assign the locomotive power to the platform, indicating the arrival of a train
    station->platforms[platform]->locomotive_power = locomotive_power;
}
