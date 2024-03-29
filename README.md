# Train Station

## Description

The *Hogsmeade* **Train Station** management system streamlines train and carriage operations at the station. It leverages efficient **linked lists** to organize train carriages, enabling quick identification of trains with specific characteristics, such as power or excess carriages.

## Structures

**Linked lists** also facilitate *optimal arrangement of carriages*, *enhancing overall performance*. With its straightforward approach, the system simplifies train station management.

| Structure    | Description                                                   |
|:------------:|---------------------------------------------------------------|
| `TrainStation` | **number of platforms** present in the train station and a **comprehensive list of platforms**, each possibly with an associated train. |
| `Train`      | **locomotive power** and a **pointer to the first train car** in the sequence of attached cars. |
| `TrainCar`   | **weight** of the train car and **pointer to the next train car** in the sequence. |

These structures allow for the representation of a train station with multiple platforms, each platform having a train with a specific locomotive power and a sequence of train cars attached to it. The use of linked lists for the train cars enables efficient arrangement and manipulation of the train cars.

## Operations

| **Function**                       | **Description** |
|:-----------------------------------|:----------------|
| `open_train_station`               | **Initializes** *a train station* with a set **number** of platforms. |
| `close_train_station`              | **Cleans up** *the train station*, releasing **all** associated memory. |
| `show_existing_trains`             | **Outputs** *the details of all trains* at the station, including **platform number**, **locomotive power**, and **carriage weights**. |
| `arrive_train`                     | **Adds** *a train* to the station at a specified **platform** with given **locomotive power**. Replaces existing locomotive power if present. |
| `leave_train`                      | **Removes** *the train* from a specified **platform**, clearing all **train cars** and **locomotive power**. |
| `add_train_car`                    | **Attaches** *a train car* with a given **weight** to the train at the specified **platform**. |
| `remove_train_cars`                | **Detaches** *all train cars* matching a specified **weight** from the train situated at the designated **platform**, ensuring selective unloading. |
| `move_train_cars`                  | **Relocates** *a number of train cars* from one train to another within the station, from and to specified platforms and positions. |
| `order_train`                      | **Sorts** *the train* cars at a specified platform in *descending order by weight*. |
| `fix_overload_train`               | **Adjusts** *an overloaded train* by removing carriages to *balance the weight with the locomotive power*. |
| `find_express_train`               | **Searches** for *the train* with the highest power-to-weight difference, indicating a fast, express train, and returns its **platform number**. |
| `find_overload_train`              | **Identifies** *any train* that is too heavy to move and returns the **platform number**, or **-1** if none are overloaded. |
| `find_optimal_train`               | **Locates** *the train* with the most efficient balance of locomotive power to carriage weight, returning the **platform number**. |
| `find_heaviest_sequence_train`     | **Finds** *the train* with the heaviest consecutive sequence of carriages based on a specified **number** and returns **the platform number** and the start of the sequence. |

## Build the Project

1. Navigate to the `build` directory.
2. Run the `make` command to build the executable.

The `Makefile` provided will compile the source files and link them with the necessary libraries, specifies which compiler to use, the compiler flags, the files to compile, and how to link the object files to produce the final binary.

```bash
    cd ./build
    make
```

## Run the Project

To execute the **train-station** program and perform the associated tests, the `run.sh` script provides an automated approach. It sets up the environment, builds the program, and runs the test suite.

To run the project using the `run.sh` script, follow these steps:

- Navigate to the root directory of the project where the `run.sh` script is located.
- Execute the script by typing `./run.sh`. You may need to grant execution permissions to the script using:
  - `chmod +x run.sh` (*if it is not already executable*).

The script performs the following steps:

- Builds the project using `make`, compiling the source files into an executable located in `result/bin`.
- Executes the **train-station** program within Valgrind to detect memory leaks:

```bash
    valgrind --leak-check=full --error-exitcode=1 ./result/bin/hogesmade
```

Upon completion, the script prints **a report** for each *test case*, indicating a **pass/fail** status. This comprehensive output helps you to verify the implementation and integrity of the program. Compares the program's output against expected results found in the `result/reference` directory.
