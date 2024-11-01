#include <stdio.h>
#include <stdbool.h>

#define SIZE 24
#define nRows 8
#define nCols 3
void print_array(int array[], int length);
void print_matrix(int mat[][nCols], int rows);
bool isValid(const int arr[], int length, int pos);
void remove_element(int arr[], int length, int pos);
bool insert_element(int arr[], int length, int pos, int value);
int main() {
    int arr[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  
    int arr2d[nRows][nCols] = {0};  
    print_matrix(arr2d, nRows);
    int test_pos = 5;
    printf("Testing isValid:\n");
    printf("Is index %d valid? %s\n\n", test_pos, isValid(arr, SIZE, test_pos) ? "Yes" : "No");
    printf("Array before removing element at index 4:\n");
    print_array(arr, SIZE);
    remove_element(arr, SIZE, 4);
    printf("Array after removing element at index 4:\n");
    print_array(arr, SIZE - 1);  
    int new_value = 99;
    int insert_pos = 5;
    if (insert_element(arr, SIZE, insert_pos, new_value)) {
        printf("Array after inserting %d at index %d:\n", new_value, insert_pos);
        print_array(arr, SIZE);
    }

    return 0;
}
void print_array(int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("array[%d]= %d\n", i, array[i]);
    }
}
void print_matrix(int mat[][nCols], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < nCols; j++)
            printf("mat[%d][%d]= %d\n", i, j, mat[i][j]);
        puts("");
    }
}
// Function 1: Checks if the given index is valid within array bounds
bool isValid(const int arr[], int length, int pos) {
    return (pos >= 0 && pos < length);
}
// Function 2: Removes an element at the specified position and shifts the rest
void remove_element(int arr[], int length, int pos) {
    if (isValid(arr, length, pos)) {
        for (int i = pos; i < length - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[length - 1] = 0; 
    } else {
        printf("Invalid index.\n");
    }
}
// Function 3: Inserts an element at the specified position
bool insert_element(int arr[], int length, int pos, int value) {
    if (pos < 0 || pos >= length) {
        printf("Invalid index for insertion.\n");
        return false;
    }
    for (int i = length - 1; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    return true;
}
