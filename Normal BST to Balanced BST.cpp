class Solution{
    
    public:
    void inorder(Node *root , vector<int>&v){
        if(root==NULL){
            return;
        }
        inorder(root->left , v);
        v.push_back(root->data);
        inorder(root->right , v);
    }
    Node *createBst( vector<int>&v ,int s , int e){
        if(s>e){
            return NULL;
        }
        int mid=s+(e-s)/2;
        Node* root=new Node(v[mid]);
        root->left=createBst(v , s ,mid-1);
        root->right=createBst(v , mid+1 , e);
        return root;
    }
    // Your are required to complete this function
    // function should return root of the modified BST
    Node* buildBalancedTree(Node* root)
    {
    	
    	if(root==NULL){
    	    return NULL;
    	}
    	vector<int>v;
    	inorder(root , v);
    	int n=v.size();
    return	createBst(v , 0 , n-1);
    	
    	
    	
    }
};
