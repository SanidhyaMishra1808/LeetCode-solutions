#include <vector>
#include <unordered_map>
#include <cstdlib>  // For rand()

class RandomizedSet {
public:
    vector<int> vec;
    unordered_map<int, int> mp;

    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) != mp.end()) { // Value already present
            return false;
        }
        // Add value to vector and store its index in the map
        vec.push_back(val);
        mp[val] = vec.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) { // Value does not exist in the map
            return false;
        }
        int idx = mp[val]; // Access index of the element to remove

        // Swap with last element
        int lastElement = vec.back();
        vec[idx] = lastElement;
        mp[lastElement] = idx;
        
        // Remove last element
        vec.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {
        int n = vec.size();
        int random = rand() % n;
        return vec[random];
    }
};