/*
Given a binary tree having N nodes and an integer M you have to return the level of node M.
Note : Consider root to be at level 1.
*/

int solve(BinaryTreeNode<int>* root, int M){
    // Write your code here
    
    if(root == NULL)
        return 0;
    
    int dist = -1;
    
    if(root->data == M || (dist = solve(root->left,M))>=0 || (dist = solve(root->right,M))>=0)
        return dist + 1;
    return dist;

}