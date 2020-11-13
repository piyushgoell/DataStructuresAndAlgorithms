/*
Given a binary tree having N number of nodes. 
Find and return the sum of all left nodes present in the input binary tree. 
That is, you need to take sum of all nodes which are left child of some node.
*/
int leftSum(BinaryTreeNode<int>* root){
    // Write your code here
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
       	 return 0;
     
    return root->left->data + leftSum(root->left) + leftSum(root->right); 

}
