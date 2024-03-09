#ifndef _STATION_H_
#define _STATION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct TrainCar {
    int weight;                 // weight of a traincar
    struct TrainCar *next;      // next traincar in the sequence
} TrainCar;

typedef struct Train {
    int locomotive_power;       // power of the train
    TrainCar *train_cars;       // pointer to traincars of the train
} Train;

typedef struct TrainStation {
    int platforms_no;           // number of platforms
    Train **platforms;          // list of platforms, each platform with a train
} TrainStation;

#include "station/station.h"
#include "train/train.h"
#include "train_car/train_car.h"
#include "find_train/find_train.h"

#endif /* _STATION_H_ */
