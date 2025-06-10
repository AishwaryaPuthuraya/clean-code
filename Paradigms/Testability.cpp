#include <iostream>
#include <vector>
#include <string>

// Function to find names starting with a specific character
std::vector<std::string> findNamesStartingWith(const std::vector<std::string>& names, char startChar) {
    std::vector<std::string> result;
    for (const auto& name : names) {
        if (!name.empty() && name[0] == startChar) {
            result.push_back(name);
        }
    }
    return result;
}

int main() {
    std::vector<std::string> names = {"Rita", "Anne", "Mark", "Robin", "Alice"};
    char searchChar = 'R';

    std::vector<std::string> matches = findNamesStartingWith(names, searchChar);

    std::cout << "Names starting with '" << searchChar << "':\n";
    for (const auto& name : matches) {
        std::cout << name << std::endl;
    }

    return 0;
}
