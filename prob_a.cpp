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

#define FIRST_CUT 1

bool compare_weights(const pair<double, int> pair_a, const pair<double, int> pair_b){
    return pair_a.first/pair_a.second < pair_b.first/pair_b.second;
}

int main(){
    int n, weight;
    double threshold_ratio, current_ratio, max_val, min_val;
    vector<pair<double, int>> pieces;
    pair<double, int> weights_cuts;          // pair defined as <piece original weight, num of cuts>
    vector<pair<double, int>>::iterator max_it, min_it;
    int total_cuts = 0;
    cin >> threshold_ratio >> n;
    while(n--){
        cin >> weight;
        weights_cuts = make_pair((double)weight, FIRST_CUT); 
        pieces.push_back(weights_cuts);
    }
    // the general algorith is to take the biggest piece and cut it to one more piece than it was already planned to cut             
    while(current_ratio < threshold_ratio){
        max_it = max_element(pieces.begin(), pieces.end(), compare_weights);
        min_it = min_element(pieces.begin(), pieces.end(), compare_weights);
        max_val = max_it->first / max_it->second;
        min_val = min_it->first / min_it->second;
        current_ratio = min_val / max_val;

        max_it->second++;
        if (current_ratio < threshold_ratio) total_cuts++;
    }
    cout << total_cuts << endl;
}