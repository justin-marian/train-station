#include "tests.h"

void create_output_directory(void) {
    struct stat st = {0};
    if (stat("../result/output", &st) == -1) {
        mkdir("./result/output", 0700);
    }
}

void test_arrive_train(void) {
    FILE *fin = fopen("../result/output/output_arrive_train.out", "w");
    if (fin == NULL) {
        printf("Error opening file!\n");
        return;
    }
    T_arrive_train(fin);
    fclose(fin);
}

void test_leave_train(void) {
    FILE *fin = fopen("../result/output/output_leave_train.out", "w");
    if (fin == NULL) {
        printf("Error opening file!\n");
        return;
    }
    T_leave_train(fin);
    fclose(fin);
}

void test_add_train_car(void) {
    FILE *fin = fopen("../result/output/output_add_train_car.out", "w");
    if (fin == NULL) {
        printf("Error opening file!\n");
        return;
    }
    T_add_train_car(fin);
    fclose(fin);
}

void test_remove_train_cars(void) {
    FILE *fin = fopen("../result/output/output_remove_train_cars.out", "w");
    if (fin == NULL) {
        printf("Error opening file!\n");
        return;
    }
    T_remove_train_cars(fin);
    fclose(fin);
}

void test_move_train_cars(void) {
    FILE *fin = fopen("../result/output/output_move_train_cars.out", "w");
    if (fin == NULL) {
        printf("Error opening file!\n");
        return;
    }
    T_move_train_cars(fin);
    fclose(fin);
}

void test_find_express_train(void) {
    FILE *fin = fopen("../result/output/output_find_express_train.out", "w");
    if (fin == NULL) {
        printf("Error opening file!\n");
        return;
    }
    T_find_express_train(fin);
    fclose(fin);
}

void test_find_overload_train(void) {
    FILE *fin = fopen("../result/output/output_find_overload_train.out", "w");
    if (fin == NULL) {
        printf("Error opening file!\n");
        return;
    }
    T_find_overload_train(fin);
    fclose(fin);
}

void test_find_optimal_train(void) {
    FILE *fin = fopen("../result/output/output_find_optimal_train.out", "w");
    if (fin == NULL) {
        printf("Error opening file!\n");
        return;
    }
    T_find_optimal_train(fin);
    fclose(fin);
}

void test_find_heaviest_sequence_train(void) {
    FILE *fin = fopen("../result/output/output_find_heaviest_sequence_train.out", "w");
    if (fin == NULL) {
        printf("Error opening file!\n");
        return;
    }
    T_find_heaviest_sequence_train(fin);
    fclose(fin);
}

void test_order_train(void) {
    FILE *fin = fopen("../result/output/output_order_train.out", "w");
    if (fin == NULL) {
        printf("Error opening file!\n");
        return;
    }
    T_order_train(fin);
    fclose(fin);
}

void test_fix_overload_train(void) {
    FILE *fin = fopen("../result/output/output_fix_overload_train.out", "w");
    if (fin == NULL) {
        printf("Error opening file!\n");
        return;
    }
    T_fix_overload_train(fin);
    fclose(fin);
}

int main(void) {
    create_output_directory();

    test_arrive_train();
    test_leave_train();
    test_add_train_car();
    test_remove_train_cars();
    test_move_train_cars();
    test_find_express_train();
    test_find_overload_train();
    test_find_optimal_train();
    test_find_heaviest_sequence_train();
    test_order_train();
    test_fix_overload_train();

    return EXIT_SUCCESS;
}
