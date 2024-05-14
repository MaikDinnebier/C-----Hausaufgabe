#include <iostream>
#include <vector>

int suchen(const std::vector<int>& v, int size, int key) {
    auto it = std::find(v.begin(), v.end(), key);
    if (it != v.end()) {
        int distance = std::distance(v.begin(), it);
        return distance;
    }
    else {
        return -1;
    }
}

int main() {
    std::vector<int> v = { 1, 5, 3, 8, 4, 2, 0, 6, 9 };
    std::cout << suchen(v, v.size(), 8);
    return 0;
}