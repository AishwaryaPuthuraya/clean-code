#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <tuple>

extern "C" {
    #include "teleColorCodeMgr.h"

}

// Struct to store calls to the handler
struct ColorPairCall {
    int index;
    std::string major;
    std::string minor;
};

// Global vector to record calls
std::vector<ColorPairCall> recordedCalls;

// Mock handler function that records the calls
void mockColorPairHandler(int index, const char* major, const char* minor) {
    recordedCalls.push_back(ColorPairCall{index, std::string(major), std::string(minor)});
}

// Test to verify the printColorMap interaction
TEST(ColorMapTest, InteractionTest) {
    recordedCalls.clear();

    int count = printColorMap(mockColorPairHandler);

    // There should be exactly 25 calls (5 majors * 5 minors)
    EXPECT_EQ(count, 25);
    EXPECT_EQ(recordedCalls.size(), 25);

    // Verify first and last call (spot checks)
    EXPECT_EQ(recordedCalls[0].index, 0);
    EXPECT_EQ(recordedCalls[0].major, "White");
    EXPECT_EQ(recordedCalls[0].minor, "Blue");

    EXPECT_EQ(recordedCalls[24].index, 24);
    EXPECT_EQ(recordedCalls[24].major, "Violet");
    EXPECT_EQ(recordedCalls[24].minor, "Slate");

    // Optional: Verify all indices are sequential and match their position
    for (size_t i = 0; i < recordedCalls.size(); ++i) {
        EXPECT_EQ(recordedCalls[i].index, (int)i);
    }
}
