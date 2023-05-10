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
typedef pair<int, int> pii;


int main() {
    int k;
    cin >> k;
    while(k--)
    {
        int m, n, c = 0, t, u;
        cin >> m >> n;
        int* A = new int[m];
        priority_queue<int, vector<int>, greater<int>> min_heap;
        priority_queue<int, vector<int>> max_heap;

        for (int i = 0; i < m; i++) {
            cin >> A[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> u;
            while (c < u) {
                min_heap.push(A[c]);
                if (!max_heap.empty() && min_heap.top() < max_heap.top()) {
                    t = min_heap.top();
                    min_heap.pop();
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                    max_heap.push(t);
                }
                c++;
            }
            if (!min_heap.empty()) {  
                cout << min_heap.top() <<endl;
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }

        delete[] A;
        if(k == 0) return 0;
        cout << "" <<endl;
    }
    
}
