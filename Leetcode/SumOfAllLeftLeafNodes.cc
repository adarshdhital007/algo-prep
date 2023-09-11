#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int leftsum=0;
    
     bool isleaf(TreeNode * root){
        if(root==nullptr){
            return false;
        }
        
        if(root->left==nullptr && root->right==nullptr){
            return true;
        }
        return false; 
    }
    
    void helper(TreeNode * root){
        if(root==nullptr)
            return;
        
        if(isleaf(root->left))
            leftsum+=root->left->val;
        
        helper(root->left);
        helper(root->right);
    }
    
    
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root);
        return leftsum;
    }
};


int main() {
    // Creating a binary tree with left and right nodes
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);


    Solution solution;
    int result = solution.sumOfLeftLeaves(root);
    cout << "Sum of left leaves: " << result << endl;

    //Optional
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
