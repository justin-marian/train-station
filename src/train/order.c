#include "train.h"

/**
 * @brief Tortoise and Haire algorithm to find the middle of the linked list.
 * 
 * @param head Pointer to the head of the linked list.
 * 
 * @return Pointer to the middle of the linked list.
*/
static TrainCar* find_middle(TrainCar* head) {
    if (head == NULL || head->next == NULL) return head;

    TrainCar* slow = head;
    TrainCar* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

/**
 * @brief Merges two linked lists of train cars into a single linked list.
 * 
 * @param cars1 Pointer to the head of the first linked list.
 * @param cars2 Pointer to the head of the second linked list.
 * 
 * @return Pointer to the head of the merged linked list.
*/
static TrainCar* merge_cars(TrainCar* cars1, TrainCar* cars2) {
    TrainCar dummy;
    TrainCar* tail = &dummy;
    dummy.next = NULL;

    while (cars1 && cars2) {
        if (cars1->weight >= cars2->weight) {
            tail->next = cars1;
            cars1 = cars1->next;
        } else {
            tail->next = cars2;
            cars2 = cars2->next;
        }
        tail = tail->next;
    }

    tail->next = (cars1 != NULL) ? cars1 : cars2;

    return dummy.next;
}

/**
 * @brief Sorts the linked list of train cars in descending order based on their weights.
 * 
 * @param head Pointer to the head of the linked list.
 * 
 * @return Pointer to the head of the sorted linked list.
*/
static TrainCar* merge_sort(TrainCar* head) {
    if (head == NULL || head->next == NULL) return head;

    TrainCar* midNode = find_middle(head);
    TrainCar* rightList = midNode->next;
    midNode->next = NULL;

    TrainCar* sortedLeft = merge_sort(head);
    TrainCar* sortedRight = merge_sort(rightList);

    return merge_cars(sortedLeft, sortedRight);
}

void order_train(TrainStation* station, int platform) {
    if (platform < 0 || platform >= station->platforms_no) return;
    if (!station->platforms[platform]->train_cars) return;
    if (!station->platforms[platform]->train_cars->next) return;

    station->platforms[platform]->train_cars = merge_sort(station->platforms[platform]->train_cars);

    // Reconnect the sorted list of train cars
    TrainCar* current_car = station->platforms[platform]->train_cars;
    while (current_car->next != NULL) {
        current_car = current_car->next;
    }

    // Update the tail of the list
    current_car->next = NULL;
}

// ! OLDER VERSION WITH BUBBLE SORT SENTINEL NODES ~ INEFFICIENT //
/**
 * @brief Orders the train cars on a platform in descending order based on their weights.
 * 
 * @param station Pointer to the train station.
 * @param platform The platform number.
 *
 * @note The function uses the Bubble Sort algorithm to order the train cars.
 * @note The function uses sentinel nodes to mark the start and end of the linked list. 
*/
void __order_train(TrainStation* station, int platform) {
    if (platform < 0 || platform >= station->platforms_no) return;
    Train* train = station->platforms[platform];
    if (!train->train_cars || !train->train_cars->next) return;

    TrainCar* current_car;
    TrainCar* next_car;
    
    // Create sentinel nodes to mark the start and end of the linked list
    TrainCar* sentinelS = (TrainCar*)malloc(sizeof(TrainCar));
    TrainCar* sentinelF = (TrainCar*)malloc(sizeof(TrainCar));
    if (!sentinelS || !sentinelF) {
        // Handle memory allocation failure
        fprintf(stderr, "[ERR]: Memory allocation failed...\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the sentinel nodes
    sentinelS->next = train->train_cars;
    sentinelF->next = NULL;
    sentinelS->weight = sentinelF->weight = 0;

    // Connect the last train car to the sentinelF node
    for (current_car = train->train_cars; current_car->next; current_car = current_car->next);
    current_car->next = sentinelF;

    // Perform Bubble Sort to order the train cars based on their weights
    int swapped;
    do {
        swapped = 0;
        current_car = sentinelS;
        while (current_car->next->next != sentinelF) {
            next_car = current_car->next;
            if (current_car->next->weight < next_car->next->weight) {
                current_car->next = next_car->next;
                next_car->next = current_car->next->next;
                current_car->next->next = next_car;
                swapped = 1;
            }
            current_car = current_car->next;
        }
    } while (swapped);
    // Update the head of the train cars list after sorting
    train->train_cars = sentinelS->next;

    // Disconnect from the sentinelF node
    for (current_car = train->train_cars; current_car->next != sentinelF; current_car = current_car->next);
    current_car->next = NULL;

    free(sentinelS);
    free(sentinelF);
}
