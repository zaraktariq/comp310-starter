#include <stdlib.h>
#include <stdio.h>

int linearSearch(int a[], int t, int length) {
    for (int i = 0; i < length; i++) {
        if (a[i] == t)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char** argv) {
    int array[] = {1, 4, 7, 9, 12};
    int target = 9;
    int aLength = sizeof(array) / sizeof(array[0]);

    int index = linearSearch(array, target, aLength);
    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found :(\n");
    }
    

}