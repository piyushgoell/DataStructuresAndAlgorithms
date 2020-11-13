/*
Given a binary tree with N number of nodes, find and return the sum of all nodes which are at Kth level.
Root is at level 1.
*/

long long sumOfNodes(BinaryTreeNode<int> *root, int k) {

    if(root==NULL) return 0;
	if(k==1) return root->data;

	return (sumOfNodes(root->left,k-1)+sumOfNodes(root->right,k-1));
}
