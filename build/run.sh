#!/bin/bash

# Build the project using 'make'
make

# Run the program with Valgrind to check for memory leaks
valgrind --leak-check=full --error-exitcode=1 ../result/bin/hogsemade
valgrind_error=$?

echo ""

# Initialize the score to 0
score=0

# Define file paths and extensions
begin_test='output_'
begin_result='../result/reference/result_'
termination='.out'

# Define test names and corresponding scores
arr=("arrive_train" "leave_train" "add_train_car"
     "remove_train_cars" "move_train_cars" "find_express_train"
     "find_overload_train" "find_optimal_train"
     "find_heaviest_sequence_train" "order_train"
     "fix_overload_train")
scores=(5 5 5 5 10 5 5 5 15 15 15)

# ANSI color codes for colored output
GREEN='\033[0;32m'
RED='\033[0;31m'
ORANGE='\033[0;33m'
NC='\033[0m' # No Color

# Loop through the test cases
for i in ${!arr[@]}; do
    element=${arr[$i]}
    testFileName="../result/output/"$begin_test$element$termination
    resultFileName=$begin_result$element$termination
    result=$(diff $testFileName $resultFileName | wc -l)

    if [ -f $testFileName ] && [ -f $resultFileName ] && [ "$result" -eq "0" ]; then
        # Print passed tests in orange
        echo -e "${ORANGE}Test $((i + 1)):${NC} ${arr[$i]} ........................... ${GREEN}passed${NC}"
        score=$((score + ${scores[$i]}))
    else
        # Print failed tests in orange
        echo -e "${ORANGE}Test $((i + 1)):${NC} ${arr[$i]} ........................... ${RED}failed${NC}"
    fi
done

echo ""

if [[ ${valgrind_error} -eq 0 ]]; then
    # Print Valgrind result in green if no errors
    echo -e "${GREEN}Valgrind errors...........................passed${NC}"
    score=$((score + 10))
else
    # Print Valgrind result in red if errors were found
    echo -e "${RED}Valgrind errors...........................failed${NC}"
fi

echo ""
echo -e "${ORANGE}Total: $score${NC}"
echo ""

# Clean up the project
make clean
