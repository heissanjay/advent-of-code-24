# include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    vector<pair<int, int>> locationIDs;

    priority_queue<int,vector<int>,greater<int>> firstList;
    priority_queue<int, vector<int>, greater<int>> secondList;

    vector<int> distanceList;

    for (int i = 0; i < 1000; i++){
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        locationIDs.push_back(temp);
    }

    // iterate over the locationID and populate both the heap
    for (auto &it: locationIDs){
        firstList.push(it.first);
        secondList.push(it.second);
    }

    while(!firstList.empty() && !secondList.empty()){
        // get the smallest number in the first and second
        int first = firstList.top();firstList.pop();
        int second = secondList.top();secondList.pop();
        int dist = abs(first - second);
        distanceList.push_back(dist);
    }    
    int result = 0;
    // iterate over the distanceList
    for (const auto dist: distanceList){
        result += dist;
    }

    cout << "Result: "<< result <<endl;


    // PART TWO
    freopen("input.txt", "r", stdin);
    unordered_map<int, int> frequency_map;
    vector<pair<int, int>> locationIDs;

    for (int i = 0; i < 1000; i++){
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        locationIDs.push_back(temp);
    }

    for (const auto &it: locationIDs){
        frequency_map[it.second]++;
    }
    vector<int> frequencyList;
    for (const auto &it: locationIDs){
        int freq = it.first * frequency_map[it.first];
        frequencyList.push_back(freq);
    }
    int result = 0;
    for(const auto freq: frequencyList){
        result += freq;
    }
    cout << "Result: " << result <<  endl;

    return 0;
}