 /*
Reversing Linked List 
*/
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
    

struct ListNode{
    int data;
    ListNode* next;
    ListNode(int value):data(value),next(nullptr){}
};
ListNode* reverseLinkedList(ListNode*head){
    ListNode* prev=nullptr;
    ListNode* current=head;
    ListNode* next=nullptr;

    while(current!=NULL){
        next= current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}

void print(ListNode* head){
    ListNode* current =head;
     while(current!=NULL){
        cout<<current->data<< " ";
        current=current->next;
    }
    cout<<endl;
}

ListNode* createLinkedList() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    F_OR3(i,1,10) {
        ListNode* newNode = new ListNode(i);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}
void solve() {
    ListNode*head=createLinkedList();
    //before any changes
    cout<<"Original Linked List : ";
    print(head);

    //reversing the linked list
    head=reverseLinkedList(head);

    //printing rev linked list
    cout<<"Reversed linked list is : ";
    print(head);
}

int main() {
    solve();
    return 0;
}