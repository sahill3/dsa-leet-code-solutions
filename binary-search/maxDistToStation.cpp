// Minimize Max Distance to Gas Station
// Difficulty: Hard
/*
We have a horizontal number line. On that number line, we have gas stations at
positions stations[0], stations[1], ..., stations[n-1], where n is the size of the
stations array. Now, we add k more gas stations so that d, the maximum distance
between adjacent gas stations, is minimized. We have to find the smallest 
possible value of d. Find the answer exactly to 2 decimal places.
Note: stations is in a strictly increasing order.
*/

#include<bits/stdc++.h>
using namespace std;

/*
==== Brute force ====
Time: O(n x k) + O(n)
*/ 


double bruteForce(vector<int> &stations, int k) {
    int n = stations.size();
    vector<int> howMany(n-1, 0);
    
    for(int i = 1; i <= k; i++){
        long double maxSection = -1;
        int maxInd = -1;
        for(int j = 0; j < n-1; j++){
            long double diff = stations[j+1] - stations[j];
            long double sectionLen = diff / (long double) (howMany[j]+1);
            
            if (sectionLen > maxSection){
                maxSection = sectionLen;
                maxInd = j;
            }
        }
    howMany[maxInd]++;
    }
    
    double maxi = INT_MIN;
    for(int i = 0; i < n-1; i++){
        double diff = stations[i+1] - stations[i];
        double section = diff / (double) (howMany[i]+1);
        maxi = max(maxi, section);
    }
    
    return maxi;
}

/*
==== Efficient Heap Data Structure ====
Time: O(k x log N) + O(N log N)
Space: O(N-1)
*/ 

double heapBased(vector<int> &stations, int k){
    int n = stations.size();
    vector<int> howMany (n-1, 0);
    priority_queue<pair<long double, int>> pq;
    
    for(int i = 0; i < n-1; i++)
        pq.push({stations[i+1] - stations[i], i});

    for (int gasStations = 1; gasStations <= k; gasStations++){
        auto tp = pq.top(); pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        long double iniDiff = stations[secInd + 1] - stations[secInd];
        long double newDiff = iniDiff / (long double) (howMany[secInd] + 1);
        pq.push({newDiff, secInd});
    }
    double ans = pq.top().first;
    return round(ans * 100.0) / 100.0;
}


/*
==== Optimized Binary Search ====
Time: O(k x log N) + O(N)
Space: O(1)
*/ 

int numberOfGasStations(long double dist, vector<int> &arr){
    int cnt = 0;
    for(int i = 1; i < arr.size(); i++){
        int numberInBetween = (arr[i] - arr[i-1]) / dist;
        if ((arr[i+1] - arr[i]) == dist * numberInBetween) numberInBetween--;
        cnt += numberInBetween;
    }
    return cnt;
}

double optimized(vector<int> &stations, int k){
    int n = stations.size();
    long double low = 0;
    long double high = 0;

    for(int i = 0; i < n-1; i++)
        high = max(high, (long double) (stations[i+1] - stations[i]));

    long double diff = 1e-6;
    while(high - low > diff){
        long double mid = (low + high)/ (2.0);
        int cnt = numberOfGasStations(mid, stations);
        if (cnt > k) low = mid;
        else high = mid;
    }
    return high;
}

int main(){
    vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 9;
    cout << optimized(stations, k) << endl;

    vector<int> stations2 = {3, 6, 12, 19, 33, 44, 67, 72, 89, 95};
    int k2 = 2;
    cout << optimized(stations2, k2) << endl;

    return 0;
};