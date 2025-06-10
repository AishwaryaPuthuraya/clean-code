#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> names = {"Rita", "Anne", "Mark", "Robin", "Alice"};
    char searchChar = 'R';

    std::cout << "Names starting with '" << searchChar << "':" << std::endl;

    for (const auto& name : names) {
        if (!name.empty() && name[0] == searchChar) {
            std::cout << name << std::endl;
        }
    }

    return 0;
}
