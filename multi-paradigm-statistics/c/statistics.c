#include <stdio.h>
#include <stdlib.h>

/*
 * This program demonstrates procedural programming in C.
 * The solution is broken into step-by-step functions that operate on arrays.
 * Loops, direct array access, and explicit size handling make the procedural
 * style visible and easy to discuss in an assignment report.
 */

double calculate_mean(const int data[], int size) {
    int sum = 0;

    /*
     * Procedural style is visible here because we explicitly loop through
     * the array and accumulate the result one element at a time.
     */
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }

    return (double)sum / size;
}

int compare_ints(const void *a, const void *b) {
    const int first = *(const int *)a;
    const int second = *(const int *)b;
    return first - second;
}

double calculate_median(const int data[], int size) {
    /*
     * C requires explicit data handling, so we copy the array before sorting.
     * This keeps the original dataset unchanged while still allowing us to
     * use qsort to prepare the median calculation.
     */
    int *sorted = malloc((size_t)size * sizeof(int));
    if (sorted == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        sorted[i] = data[i];
    }

    qsort(sorted, (size_t)size, sizeof(int), compare_ints);

    double median;
    if (size % 2 == 0) {
        median = (sorted[size / 2 - 1] + sorted[size / 2]) / 2.0;
    } else {
        median = sorted[size / 2];
    }

    free(sorted);
    return median;
}

int calculate_mode(const int data[], int size, int modes[], int max_modes) {
    int *sorted = malloc((size_t)size * sizeof(int));
    if (sorted == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        sorted[i] = data[i];
    }

    qsort(sorted, (size_t)size, sizeof(int), compare_ints);

    /*
     * This function supports multiple modes in a general way.
     * We walk through the sorted array, count repeated values,
     * and store every value tied for the highest frequency.
     */
    int best_count = 0;
    int mode_count = 0;
    int current_value = sorted[0];
    int current_count = 1;

    for (int i = 1; i <= size; i++) {
        if (i < size && sorted[i] == current_value) {
            current_count++;
        } else {
            if (current_count > best_count) {
                best_count = current_count;
                mode_count = 0;
                if (mode_count < max_modes) {
                    modes[mode_count++] = current_value;
                }
            } else if (current_count == best_count) {
                if (mode_count < max_modes) {
                    modes[mode_count++] = current_value;
                }
            }

            if (i < size) {
                current_value = sorted[i];
                current_count = 1;
            }
        }
    }

    free(sorted);
    return mode_count;
}

void print_modes(const int modes[], int mode_count) {
    printf("Mode(s): [");
    for (int i = 0; i < mode_count; i++) {
        printf("%d", modes[i]);
        if (i < mode_count - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main(void) {
    /*
     * The dataset is fixed to match the assignment requirements exactly.
     * Using a plain array highlights direct data storage in procedural C.
     */
    const int data[] = {12, 6, 3, 6, 9, 15, 6, 3, 12};
    const int size = (int)(sizeof(data) / sizeof(data[0]));
    int modes[size];

    const double mean = calculate_mean(data, size);
    const double median = calculate_median(data, size);
    const int mode_count = calculate_mode(data, size, modes, size);

    printf("========================================\n");
    printf("Statistics Calculator Demo\n");
    printf("========================================\n");
    printf("Data: [12, 6, 3, 6, 9, 15, 6, 3, 12]\n");
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    print_modes(modes, mode_count);

    return 0;
}
