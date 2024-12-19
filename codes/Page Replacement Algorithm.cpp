#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void lruPageReplacement(vector<int> pages, int capacity) {
    unordered_map<int, int> cache;
    vector<int> order;

    int pageFaults = 0;

    for (int page : pages) {
        if (cache.find(page) == cache.end()) {
            pageFaults++;
            if (cache.size() == capacity) {
                int oldest = order.front();
                order.erase(order.begin());
                cache.erase(oldest);
            }
        } else {
            order.erase(find(order.begin(), order.end(), page));
        }
        cache[page] = 1;
        order.push_back(page);
    }

    cout << "Page Faults: " << pageFaults << endl;
}

int main() {
    vector<int> pages = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int capacity = 3;
    lruPageReplacement(pages, capacity);
    return 0;
}
