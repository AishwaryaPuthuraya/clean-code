#include <iostream>
#include <vector>
#include <string>

// Class that encapsulates name filtering logic
class NameFilter {
private:
    std::vector<std::string> names;

public:
    // Constructor
    NameFilter(const std::vector<std::string>& inputNames) : names(inputNames) {}

    // Method to find names starting with a specific character
    std::vector<std::string> filterByStartingChar(char startChar) const {
        std::vector<std::string> result;
        for (const auto& name : names) {
            if (!name.empty() && name[0] == startChar) {
                result.push_back(name);
            }
        }
        return result;
    }
};

int main() {
    std::vector<std::string> nameList = {"Rita", "Anne", "Mark", "Robin", "Alice"};
    NameFilter nameFilter(nameList);

    char searchChar = 'R';
    std::vector<std::string> results = nameFilter.filterByStartingChar(searchChar);

    std::cout << "Names starting with '" << searchChar << "':\n";
    for (const auto& name : results) {
        std::cout << name << std::endl;
    }

    return 0;
}
