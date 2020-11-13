void solve(BinaryTreeNode<int>* root){
    	/* Don't write main().
	* Don't read input, it is passed as function argument.
	*/
    if(root == NULL)
        return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){
		int count = q.size();
        
        for(int i=0;i<count;i++){
            BinaryTreeNode<int>* curr = q.front();
        	q.pop();
			if(i==0 || i == count-1){
        		cout<<curr->data<<" ";
            }
            if(curr->left != NULL)
            	q.push(curr->left);
        	if(curr->right !=NULL)
            	q.push(curr->right);

        }
        
    }

}
