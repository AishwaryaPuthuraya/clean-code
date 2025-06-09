#include "teleColorCodeMgr.h"

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

// The handler function for actual printing (can be replaced during testing)
void printColorPair(int index, const char* major, const char* minor) {
    printf("%d | %s | %s\n", index, major, minor);
}

// This function takes a handler to be used for each color pair
int printColorMap(ColorPairHandler handler) {
    int i, j;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            int pairNumber = i * 5 + j;
            handler(pairNumber, majorColor[i], minorColor[j]);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap(printColorPair);  // Inject the printer
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
