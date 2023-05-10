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
#include <ios>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;  
typedef vector<int> vi;  
typedef vector<string> vs;  
typedef pair<int, int> pii;


typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;
const ld  prec = .000001;

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set
struct car {
    ll pos;
    ll vel;
};

// Compute the position of a car given its initial position and velocity and a time
ld getpos(const car& c, ld time) {
    return c.pos + c.vel * time;
}

// Compute the distance between the leftmost and rightmost cars at a given time
ld getwindow(const vector<car>& v, ld time) {
    ld lo = INFINITY;
    ld hi = -INFINITY;
    for (const auto& i : v) {
        ld val = getpos(i, time);
        lo = min(lo, val);
        hi = max(hi, val);
    }
    return hi - lo;
}

int main() {
    // Read in the number of cars and their positions and velocities
    int n;
    cin >> n;
    vector<car> v(n);
    for (auto& i : v) {
        cin >> i.pos >> i.vel;
    }

    // Perform ternary search to find the time that minimizes the distance between the leftmost and rightmost cars
    ld lo = 0;
    ld hi = 200001;
    while (hi - lo > 0.000001) { // Use a tolerance of 0.000001 for floating-point comparisons
        ld r = (lo + hi * 2) / 3; // Compute two tentative times, l and r, that divide the search range into three equal parts
        ld l = (lo * 2 + hi) / 3;

        ld val1 = getwindow(v, l); // Compute the distance between the leftmost and rightmost cars at times l and r
        ld val2 = getwindow(v, r);

        if (val1 < val2) { // If the distance is smaller at l than at r, discard the upper third of the search range
            hi = r;
        } else { // Otherwise, discard the lower third of the search range
            lo = l;
        }
    }

    // Output the minimum distance with 5 decimal places of precision
    cout << fixed  << getwindow(v, lo) << endl;

    return 0;
}