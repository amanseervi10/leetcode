#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int simulateCache(int cacheSize, const vector<int>& requests) {
    unordered_map<int, int> cache;
    int hits = 0;
    int currentTime = 0;

    for (int item : requests) {
        currentTime++;

        if (cache.find(item) != cache.end()) {
            cache[item] = currentTime;
            hits++;
        } else {
            if (cache.size() >= cacheSize) {
                int lruItem = -1;
                int lruTime = currentTime;
                for (const auto& entry : cache) {
                    if (entry.second < lruTime) {
                        lruTime = entry.second;
                        lruItem = entry.first;
                    }
                }
                cache.erase(lruItem);
            }
            cache[item] = currentTime;
        }
    }

    return hits;
}

int minimumCacheSize(const vector<string>& request, int k) {

    vector<int> requests;
    int curr=1;
    unordered_map<string,int> mp;
    for(auto i : request){
        if(mp.find(i)==mp.end()){
            mp[i]=curr;
            curr++;
        }
        requests.push_back(mp[i]);
    }

    int low = 1;
    int high = requests.size();
    int minCacheSize = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int hits = simulateCache(mid, requests);

        if (hits >= k) {
            minCacheSize = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    if(minCacheSize==-1) return -1;

    return minCacheSize;
}

int main() {
    int n, k;
    cout << "Enter the number of requests: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter the requests: ";
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    cout << "Enter the minimum number of hits required: ";
    cin >> k;

    int minCacheSize = minimumCacheSize(requests, k);

    if (minCacheSize == -1) {
        return -1;
    } else {
        return minCacheSize;
    }

    return 0;
}
