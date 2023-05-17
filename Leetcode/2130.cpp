#include<bits/stdc++.h>
#include<stdio.h>
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

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        int sum = INT_MIN;
        vt<int> demo;
        while (head != NULL) {
            demo.push_back(head->val);
            head = head->next;
        }
        int n = demo.size();
        //just doing the loop till n/2 as given 
        F_OR3(i,0,n/2) {
            sum = max(sum, demo[i] + demo[n - 1 - i]);
        }
        return sum;
    }
};

void solve() {
   
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);

    Solution solution;
    int result = solution.pairSum(head);
    cout << "Maximum twin sum: " << result << endl;


    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;
}

int main() {
    solve();
    return 0;
}


//Using stack

 /*
Create a ListNode pointer current and initialize it to head.
Initialize an integer stack st to store the node values in the linked list.
Iterate while current is not null:
      -->Push current->val into st.
      -->Update current to current->next.
Set current back to head to iterate the list again from the start.
Initialize size as st.size() and count as 1 to count the number of twin pairs.
Create an integer variable maximumSum and initialize it to 0 to track the maximum sum of a node and its twin.
While count is less than or equal to size/2:
    -->Update maximumSum if the current twin sum is greater than the previous one:
     maximumSum = max(maximumSum, current->val + st.top()).
    -->Update current to current->next.
    -->Pop the top element from the stack st.
    -->Increment count by 1.
Return maximumSum.
*/

 /*
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* current = head;
        stack<int> st;

        while (current) {
            st.push(current->val);
            current = current->next;
        }

        current = head;
        int size = st.size(), count = 1;
        int maximumSum = 0;
        while (count <= size / 2) {
            maximumSum = max(maximumSum, current->val + st.top());
            current = current->next;
            st.pop();
            count++;
        }

        return maximumSum;
    }
};
*/