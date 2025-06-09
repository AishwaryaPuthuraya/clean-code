#include <stdio.h>
#include <assert.h>

// Define a function pointer type for printing or handling color pairs
typedef void (*ColorPairHandler)(int, const char*, const char*);

int printColorMap(ColorPairHandler handler);
