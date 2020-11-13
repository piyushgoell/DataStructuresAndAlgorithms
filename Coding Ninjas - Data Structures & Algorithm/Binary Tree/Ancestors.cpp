/*
Given a binary tree with N number of nodes and a node K, 
you need to find and return a list of all ancestors of the given node K.

Constraints :
1 <= N <= 10^5

Sample Input :
1 2 3 4 5 -1 7 -1 -1 6 -1 8 -1 -1 -1 -1 -1
6

Sample Output :
1
2
5
*/


#include <vector>

bool traverse (BinaryTreeNode<int> *root, int k, vector<int> & res){
	if(root == NULL)
        return false;
    if(root->data == k)
        return true;
    if(traverse(root->left,k,res) || traverse(root->right,k,res)){
		res.push_back(root->data);
        return true;
    }
    return false;
}
vector<int> ancestors(BinaryTreeNode<int> *root, int k) {
    /* Don't write main().
     * Don't read input, they are passed as function arguments.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    vector<int> res;
    traverse(root,k,res);
    return res;    
    
}