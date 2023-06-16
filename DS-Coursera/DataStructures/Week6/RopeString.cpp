
#include <iostream>
#include <string>

using namespace std;

struct Vertex {
    char symbol;
    int size;
    Vertex* left;
    Vertex* right;
    Vertex* parent;

    Vertex(char symbol, int size, Vertex* left, Vertex* right, Vertex* parent)
        : symbol(symbol), size(size), left(left), right(right), parent(parent) {}
};

class Rope {
private:
    string s;
    Vertex* root;

public:
    Rope(const string& s) : s(s), root(nullptr) {
        root = buildRope(s, 0, s.size() - 1, nullptr);
    }

    Vertex* buildRope(const string& s, int start, int end, Vertex* parent) {
        if (start > end)
            return nullptr;

        int mid = (start + end) / 2;
        Vertex* v = new Vertex(s[mid], end - start + 1, nullptr, nullptr, parent);
        v->left = buildRope(s, start, mid - 1, v);
        v->right = buildRope(s, mid + 1, end, v);

        return v;
    }

    string getResult() {
        return inOrderTraversal(root);
    }

    string inOrderTraversal(Vertex* v) {
        if (v == nullptr)
            return "";

        string left = inOrderTraversal(v->left);
        string right = inOrderTraversal(v->right);

        return left + v->symbol + right;
    }

    Vertex* find(Vertex* v, int index) {
        if (v == nullptr)
            return nullptr;

        int leftSize = (v->left != nullptr) ? v->left->size : 0;

        if (index == leftSize + 1)
            return v;

        if (index < leftSize + 1)
            return find(v->left, index);

        return find(v->right, index - leftSize - 1);
    }

    pair<Vertex*, Vertex*> split(Vertex* v, int index) {
        if (v == nullptr)
            return make_pair(nullptr, nullptr);

        int leftSize = (v->left != nullptr) ? v->left->size : 0;

        if (index == leftSize + 1)
            return make_pair(v->left, v->right);

        if (index < leftSize + 1) {
            pair<Vertex*, Vertex*> leftSplit = split(v->left, index);
            v->left = leftSplit.second;
            if (v->left != nullptr)
                v->left->parent = v;
            if (leftSplit.second != nullptr)
                leftSplit.second->parent = nullptr;
            v->size -= (leftSplit.second != nullptr) ? leftSplit.second->size : 0;
            return make_pair(leftSplit.first, v);
        }

        pair<Vertex*, Vertex*> rightSplit = split(v->right, index - leftSize - 1);
        v->right = rightSplit.first;
        if (v->right != nullptr)
            v->right->parent = v;
        if (rightSplit.first != nullptr)
            rightSplit.first->parent = nullptr;
        v->size -= (rightSplit.first != nullptr) ? rightSplit.first->size : 0;
        return make_pair(v, rightSplit.second);
    }

    Vertex* merge(Vertex* left, Vertex* right) {
        if (left == nullptr)
            return right;

        if (right == nullptr)
            return left;

        int randNum = rand() % (left->size + right->size);

        if (randNum < left->size) {
            left->right = merge(left->right, right);
            if (left->right != nullptr)
                left->right->parent = left;
            left->size = (left->right != nullptr) ? left->right->size + 1 : 1;
            return left;
        }

        right->left = merge(left, right->left);
        if (right->left != nullptr)
            right->left->parent = right;
        right->size = (right->left != nullptr) ? right->left->size + 1 : 1;
        return right;
    }

    void process(int i, int j, int k) {
        pair<Vertex*, Vertex*> leftMid = split(root, i);
        pair<Vertex*, Vertex*> midRight = split(leftMid.second, j - i + 1);
        pair<Vertex*, Vertex*> tmp = split(midRight.first, k + 1);

        root = merge(merge(leftMid.first, tmp.second), merge(midRight.first, tmp.first));
    }
};

int main() {
    string s;
    int operationsCount;
    cin >> s;
    cin >> operationsCount;

    Rope rope(s);

    for (int op = 0; op < operationsCount; op++) {
        int i, j, k;
        cin >> i >> j >> k;
        rope.process(i, j, k);
    }

    cout << "Input:\n" << s << endl;
    cout << operationsCount << endl;

    for (int op = 0; op < operationsCount; op++) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << i << " " << j << " " << k << endl;
    }

    cout << "Output:" << endl;
    cout << rope.getResult() << endl;

    return 0;
}
