 /*
Insertion at the Beginning: Insert a new node at the beginning of the linked list.
Insertion at the End: Insert a new node at the end of the linked list.
Insertion at a Given Position: Insert a new node at a specific position in the linked list.
Deletion at the Beginning: Remove the first node from the linked list.
Deletion at the End: Remove the last node from the linked list.
*/
#include <bits/stdc++.h>
using namespace std;
/*adarshdhital007*/
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
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
    
template<class T> bool umin(T& a, const T& b) {
    return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) { 
    return a<b?a=b, 1:0;
} 
    
ll FT(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb)/2;
        f(mb)?rb=mb:lb=mb+1; 
    } 
    return lb;
}
ll LT(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb+1)/2;
        f(mb)?lb=mb:rb=mb-1; 
    } 
    return lb;
}
    
template<class A> void rd(vt<A>& v);
template<class A, size_t S> void rd(ar<A, S>& a);
template<class T> void rd(T& x) {
    cin >> x;
}
void rd(double& d) {
    string t;
    rd(t);
    d=stod(t);
}
void rd(long double& d) {
    string t;
    rd(t);
    d=stold(t);
}
template<class H, class... T> void rd(H& h, T&... t) {
    rd(h);
    rd(t...);
}
template<class A> void rd(vt<A>& x) {
    EACH(a, x)
        rd(a);
}
template<class A, size_t S> void rd(array<A, S>& x) {
    EACH(a, x)
        rd(a);
}
    
string to_string(char c) {
    return string(1, c);
}
string to_string(bool b) {
    return b?"true":"false";
}
string to_string(const char* s) {
    return string(s);
}
string to_string(string s) {
    return s;
}
string to_string(vt<bool> v) {
    string res;
    FOR(sz(v))
        res+=char('0'+v[i]);
    return res;
}
    
template<size_t S> string to_string(bitset<S> b) {
    string res;
    FOR(S)
        res+=char('0'+b[i]);
    return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
        if(!f)
            res+=' ';
        f=0;
        res+=to_string(x);
    }
    return res;
}
    
template<class A> void wr(A x) {
    cout << to_string(x);
}
template<class H, class... T> void wr(const H& h, const T&... t) { 
    wr(h);
    wr(t...);
}
void print() {
    wr("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
    wr(h);
    if(sizeof...(t))
        wr(' ');
    print(t...);
}
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1}; 

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    private:
    Node* head;

    public:
    //constructing
    LinkedList(){
        head=NULL;
    }

    //insertion at the beginning
    void insertatbeginning(int value){
        Node* newNode=new Node;
        newNode->data=value;
        newNode->next=head;
        head=newNode;
    }
    //insertion at the end
    void insertatend(int value){
        Node* newNode=new Node;
        newNode->data=value;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
            return;
        }
        Node* current=head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newNode;
    }

    void insertionatposition(int value, int position){
        if(position==1){
            insertatbeginning(value);
            return;
        }
        Node* newNode=new Node;
        newNode->data=value;

        Node* current=head;
            for(int i=1;i<position-1 && current!=NULL;i++){
            current=current->next;
        }
        
        if(current == NULL){
            print("Invalid Position");
            return;
        }
        newNode->next=current->next;
        current->next=newNode;
    }

    void deleteatbeginning(){
        if(head == NULL){
            print("Linked list is empty");
            return;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    void deleteatend(){
        if(head == NULL){
            print("Linked List is empty");
            return;
        }
        if(head->next==NULL){
            delete head;
            head=NULL;
            return;
        }
        Node* current=head;
        while(current->next->next!=NULL){
            current=current->next;
        }
        delete current->next;
        current->next=NULL;
    }

    void display(){
        if(head==NULL){
            wr("Linked list is empty");
        }
        Node* current= head;
        while(current!=NULL){
            wr(current->data);
            wr(" ");
            current=current->next;
        }
        print();
    }
};

void solve(){
 LinkedList list;

    wr("Linked list before any operation: ");
    list.display();
    print();

    list.insertatbeginning(8);
    list.insertatbeginning(9);
    list.insertatbeginning(10);
    wr("Linked list after inserting 10 at the beginning: ");
    list.display();
    print();

    list.insertatend(20);
    wr("Linked list after inserting 20 at the end: ");
    list.display();
    print();

    list.insertionatposition(30, 4);
    wr("Linked list after inserting 30 at position 4: ");
    list.display();
    print();

    list.deleteatbeginning();
    wr("Linked list after deleting at the beginning: ");
    list.display();
    print();

    list.deleteatend();
    wr("Linked list after deleting at the end: ");
    list.display();

}
  
int main(){
    solve();
    return 0;
}