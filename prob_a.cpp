#include <algorithm>
#include <bitset> 
#include <cmath>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <deque>  
#include <functional>
#include <iostream>  
#include <map>  
#include <queue>  
#include <set>  
#include <stack>  
#include <string> 
#include <vector>  
#include <numeric>  
#include <iomanip>
#include <climits>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;  
typedef vector<int> vi;  
typedef pair<int, int> pii;

bool compare_weights(const pair<double, int> pair_a, const pair<double, int> pair_b){
    return pair_a.first/pair_a.second < pair_b.first/pair_b.second;
}

int main(){
    int n, weight;
    double threshold_ratio, current_ratio, max_ratio, min_ratio;
    vector<pair<double, int>> pieces;
    pair<double, int> weights_cuts;        
    vector<pair<double, int>>::iterator max_it, min_it;
    int total_cuts = 0;
    cin >> threshold_ratio >> n;
    while(n--){
        cin >> weight;
        weights_cuts = make_pair((double)weight, 1); 
        pieces.push_back(weights_cuts);
    }      
    while(current_ratio < threshold_ratio){
        max_it = max_element(pieces.begin(), pieces.end(), compare_weights);
        min_it = min_element(pieces.begin(), pieces.end(), compare_weights);
        max_ratio = max_it->first / max_it->second;
        min_ratio = min_it->first / min_it->second;
        current_ratio = min_ratio / max_ratio;

        max_it->second++;
        if (current_ratio < threshold_ratio) total_cuts++;
    }
    cout << total_cuts << endl;
}