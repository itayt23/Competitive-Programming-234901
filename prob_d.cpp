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
typedef vector<string> vs;  
typedef pair<int, int> pii;

int* values;
int n;
double ratio;

int main() {
    int n;
    vs out;
    string temp;
    cin >> n;
    int temp_n = n;
    int count_shots = 0;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    string s1 = "";
    string s2 = "";
    string s3 = "";
    if (n <= 20) {
        out.push_back("single " + to_string(n));
        num1 = n;
        s1 = "single ";
        count_shots = 1;
    }
    else if (n <= 40) {
        num1 = 20; num2 = n - 20;
        out.push_back("single 20");
        out.push_back("single " + to_string(n - 20));
        s1 = "single "; s2 = "single ";
        count_shots = 2;
    }
    else if (n <= 60) {
        num1 = 20; num2 = 20; num3 = n - 40;
        out.push_back("single 20");
        out.push_back("single 20");
        out.push_back("single " + to_string(n - 40));
        s1 = "single "; s2 = "single "; s3 = "single ";
        count_shots = 3;
    }
    else if (n <= 80) {
        num1 = 20; num2 = n - 60;
        out.push_back("triple 20");
        out.push_back("single " + to_string(n - 60));
        s1 = "triple "; s2 = "single ";
        count_shots = 2;
    }
    else if (n <= 100) {
        num1 = 20; num2 = 20; num3 = n - 80;
        out.push_back("triple 20");
        out.push_back("triple 20");
        out.push_back("single " + to_string(n - 80));
        s1 = "triple "; s2 = "single "; s3 = "single ";
        count_shots = 3;
    }
    else if (n <= 120) {
        num1 = 20; num2 = 20; num3 = n - 100;
        out.push_back("triple 20");
        out.push_back("triple 20");
        out.push_back("double " + to_string(n - 100));
        s1 = "triple "; s2 = "double "; s3 = "single ";
        count_shots = 3;
    }
    else if (n <= 140) {
        num1 = 20; num2 = 20; num3 = n - 120;
        out.push_back("triple 20");
        out.push_back("triple 20");
        out.push_back("triple " + to_string(n - 120));
        s1 = "triple "; s2 = "triple "; s3 = "single ";
        count_shots = 3;
    }
    else if (n <= 160) {
        if ((n - 120) % 3 == 0) {
            num1 = 20; num2 = 20; num3 = (n - 120) / 3;
            out.push_back("triple 20");
            out.push_back("triple 20");
            out.push_back("triple " + to_string((n - 120) / 3));
            s1 = "triple "; s2 = "triple "; s3 = "triple ";
            count_shots = 3;
        }
        else if (n % 2 != 0) {
            if ((n - 117) % 2 == 0) {
                num1 = 20; num2 = 19; num3 = (n - 117) / 2;
                out.push_back("triple 20");
                out.push_back("triple 19");
                out.push_back("double " + to_string((n - 117) / 2));
                s1 = "triple "; s2 = "triple "; s3 = "double ";
                count_shots = 3;
            }
            else {
                count_shots = 4;
            }
        }
        else {
            num1 = 20; num2 = 20; num3 = (n - 120) / 2;
            out.push_back("triple 20");
            out.push_back("triple 20");
            out.push_back("double " + to_string((n - 120) / 2));
            s1 = "triple "; s2 = "triple "; s3 = "double ";
            count_shots = 3;
        }
    }
    else if(n<=180){
        for (int i = 20; i >= 1; i--) {
            while (n >= 3*i) {
                temp = "triple " +to_string(i);
                out.push_back(temp);
                n -= 3*i;
            }
            if(n==0) break;
        }

        for (int i = 20; i >= 1; i--) {
            while (n >= 2*i) {
                temp = "double " +to_string(i);
                out.push_back(temp);
                n -= 2*i;
            }
            if(n==0) break;
        }

        for (int i = 20; i >= 1; i--) {
            if (n >= i) {
                temp = "single " +to_string(i);
                out.push_back(temp);
                n -= i;
            }
            if(n==0) break;
        }
        if (n != 0 || out.size() > 3) {
        cout << "impossible" << endl;
        }
        else{
            for(int i = 0; i < out.size(); i++){
                cout << out[i] << endl;
            }
        }
        return 0;
    }
    if(count_shots==1) cout << s1 << num1 << endl;//cout << out[0] << endl;
    else if(count_shots==2)
    {
        // cout << out[0] << endl;
        // cout << out[1] << endl;
        cout << s1 << num1 << endl;
        cout << s2 << num2 << endl;
    }
    else if(count_shots == 3)
    {
        // cout << out[0] << endl;
        // cout << out[1] << endl;
        // cout << out[2] << endl;
        cout << s1 << num1 << endl;
        cout << s2 << num2 << endl;
        cout << s3 << num3 << endl;
    }
    else
    {
        cout << "impossible" << endl;
    }
}