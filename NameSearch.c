#include <stdio.h>
#include <string.h>

int main() {
    // Define the array of names
    char *names[] = {"Rita", "Anne", "Mark", "Robin", "Alice"};
    int size = sizeof(names) / sizeof(names[0]);

    printf("Names starting with 'R':\n");

    // Iterate through the array and check the first character
    for (int i = 0; i < size; i++) {
        if (names[i][0] == 'R') {
            printf("%s\n", names[i]);
        }
    }

    return 0;
}
