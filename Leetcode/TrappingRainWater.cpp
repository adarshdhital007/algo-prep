#include<bits/stdc++.h>
using namespace std;
//template(adarshdhital007)
#define ll long long
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()


#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define EACH(x, a) for (auto& x: a)

template<class T> bool umin(T& a, const T& b) {
return b<a?a=b, 1:0;
}

template<class T> bool umax(T& a, const T& b) { 
return a<b?a=b, 1:0;
}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}
//trapping the rain water
class Solution {
public:
    int trap(vt<int>& height) {
        int l=0;
        int r=height.size()-1;
        int ml=0;
        int mr=0;
        int w=0;

        while(l<=r){
            if(height[l]<=height[r]){
                ml=max(ml,height[l]);
                w+=ml-height[l];
                l++;
            }
            else{
                mr=max(mr,height[r]);
                w+=mr-height[r];
                r--;
            }
        }
        return w;
    }
};
void solve()
{
    vt<int> height={4,2,0,3,2,5};
    Solution solution;
    int ans = solution.trap(height);
    cout<<"The trapped rain water is : "<< ans <<endl;
}

int main(){
    solve();
    return 0;
}

//TC : O(n)
//SC : O(1)