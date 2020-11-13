/*
For a given binary tree, convert it to its sum tree. 
That is, replace every node data with sum of its immediate children, keeping leaf nodes 0. Finally, return its preorder.
*/

void convert(BinaryTreeNode<int> *root){
 	if(root == NULL)
    	return; 
    int sum = 0;
    if(root->left != NULL)
    	sum = root->left->data;
    if(root->right!=NULL)
        sum += root->right->data;
    root->data = sum;
    convert(root->left);
    convert(root->right);
}

void preorder(BinaryTreeNode<int> *root, vector<int>& result){
	if(root == NULL)
        return;
    result.push_back(root->data);
    preorder(root->left,result);
    preorder(root->right,result);
}
vector<int> sumTree(BinaryTreeNode<int> *root)
{
    //Write your code here
    convert(root);
    vector<int> result;
    preorder(root, result);
    return result;
    
}