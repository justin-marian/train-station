#include "train_car.h"

void move_train_cars(TrainStation *station, int platform_a, int pos_a, int cars_no, int platform_b, int pos_b) {
    if (cars_no <= 0 || !station->platforms[platform_a]->train_cars) return;
    if (platform_a < 0 || platform_a >= station->platforms_no) return;
    if (platform_b < 0 || platform_b >= station->platforms_no) return;
    if (station->platforms[platform_a]->locomotive_power == -1) return;
    if (station->platforms[platform_b]->locomotive_power == -1) return;

    // Find the starting train car and ending train car in platform_a to be moved
    TrainCar* current_car = station->platforms[platform_a]->train_cars;
    TrainCar* start_car = NULL;
    int current_position = pos_a;
    while (current_car && current_position != 1) {
        if (current_position == 2) {
            start_car = current_car;
        }
        current_position--;
        current_car = current_car->next;
    }

    // Check if the starting position is valid
    if (current_position > 1 || !current_car) {
        return;
    }

    TrainCar* end_car = current_car;
    int remaining_cars = cars_no;
    // Find the ending train car in platform_a to be moved
    while (end_car && remaining_cars != 1) {
        end_car = end_car->next;
        remaining_cars--;
    }

    // Check if the ending position is valid
    if (!end_car || remaining_cars != 1) {
        return;
    }

    // Find the train car at position pos_b in platform_b (the destination position)
    TrainCar* destination_car = station->platforms[platform_b]->train_cars;
    TrainCar* position_car = NULL;
    int destination_position = pos_b;
    while (destination_car && destination_position != 1) {
        if (destination_position == 2) {
            position_car = destination_car;
        }
        destination_position--;
        destination_car = destination_car->next;
    }

    // Check if the destination position is valid
    if (destination_position == 1) {
        // Remove the train cars from platform_a and update the linked list
        if (pos_a == 1) {
            station->platforms[platform_a]->train_cars = end_car->next;
        } else {
            start_car->next = end_car->next;
        }

        // Insert the train cars to platform_b and update the linked list
        if (pos_b == 1) {
            end_car->next = station->platforms[platform_b]->train_cars;
            station->platforms[platform_b]->train_cars = current_car;
        } else {
            end_car->next = position_car->next;
            position_car->next = current_car;
        }
    }
}
