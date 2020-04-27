#include <bits/stdc++.h>
#define endl "\n";
using namespace std;
typedef long long ll ;


//Calculates a Value raised to the power N will be Calculated in O(logN) time Complexity and O(1) Space Complexity
ll fastExponention(ll x , ll a) {
    if( a == 0) {
        return 1;
    }
    ll res = fastExponention(x, a / 2);
    if(a % 2) {
        return x * res * res;
    } else {
        return res * res ;
    }
}


int main()
{
    cout << fastExponention(2 , 5) << endl;
    return 0;
}
