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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;  
typedef vector<int> vi;  
typedef vector<vector<int>> vvi;  
typedef vector<string> vs;  
typedef pair<int, int> pii;

ull nChoosek( unsigned n, unsigned k )
{
    if(n == k) return 1;
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ull result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int n, m;
        cin >> n >> m;
        if(cases != 0) cout << nChoosek(n, m-1) << endl;
        else cout << nChoosek(n, m-1);
    }   
}