class NumArray {
private:
    int n;
    vector<int> segTree;
    
    void build(int l, int r, int index, vector<int>& nums) {
        if(l == r){
            segTree[index] = nums[l];
        }
        else{
            int mid = (l+r)/2;
            build(l, mid, index*2, nums);
            build(mid+1, r, index*2+1, nums);
            segTree[index] = segTree[index*2] + segTree[index*2+1];
        }
    }
    
    void updateRecursion(int l, int r, int index, int pos, int val) {
        if(l == r){
            segTree[index] = val;
        }
        else{
            int mid = (l+r)/2;
            if(pos <= mid){
                updateRecursion(l, mid, index*2, pos, val);
            }
            else{
                updateRecursion(mid+1, r, index*2+1, pos, val);
            }
            segTree[index] = segTree[index*2] + segTree[index*2+1];
        }
    }
    
    int sumRangeRecursion(int l, int r, int L, int R, int index) {
        if(l == L && r == R){
            return segTree[index];
        }
        int mid = (L+R)/2;
        if(r <= mid){
            return sumRangeRecursion(l, r, L, mid, index*2);
        }
        else if(l > mid){
            return sumRangeRecursion(l, r, mid+1, R, index*2+1);
        }
        else{
            return sumRangeRecursion(l, mid, L, mid, index*2) + sumRangeRecursion(mid+1, r, mid+1, R, index*2+1);
        }
    }
    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(n*4, 0);
        build(0, n-1, 1, nums);
    }
    
    void update(int index, int val) {
        updateRecursion(0, n-1, 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return sumRangeRecursion(left, right, 0, n-1, 1);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */



// poor performance linked list version
struct Node {
    Node* left;
    Node* right;
    int start;
    int end;
    int sum;
    
    Node(int start,int end){
        this->left = NULL;
        this->right = NULL;
        this->start = start;
        this->end = end;
        this->sum = 0;
    }
};

class NumArray {
private:
    Node* root = NULL;
    int n;
    
    Node* buildSegTree(int start, int end, vector<int>& nums) {
        Node* node = new Node(start, end);
        if(start == end){
            node->sum = nums[start];
        }
        else{
            int mid = (start + end)/2;
            node->left = buildSegTree(start, mid, nums);
            node->right = buildSegTree(mid+1, end, nums);
            node->sum = node->left->sum + node->right->sum;   
        }
        return node;
    }
    
    int sumRangeRecursion(Node* root, int left, int right) {
        if(root->start==left && root->end==right){
            return root->sum;
        }
        int mid = (root->start + root->end)/2;
        if(right <= mid){
            return sumRangeRecursion(root->left, left, right);
        }

        else if(left > mid){
            return sumRangeRecursion(root->right, left, right);
        }

        else{
            return sumRangeRecursion(root->left, left, mid) + sumRangeRecursion(root->right, mid+1,right);
        }
    }
    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        root = buildSegTree(0, n-1, nums);
    }
    
    void update(int index, int val) {
        int start = 0;
        int end = n-1;
        if(start == end){
            root->sum = val;
            return;
        }
        stack<Node*> st;
        Node* curr = root;
        while(start != end){
            st.push(curr);  // push all ancestor into stack
            int mid = (start + end)/2;
            if(index <= mid){
                end = mid;
                curr = curr->left;
            }
            else{
                start = mid+1;
                curr = curr->right;
            }
        }   // after while loop curr will be the node to bo update
        curr->sum = val;
        while(!st.empty()){
            Node* temp = st.top();
            st.pop();
            temp->sum = temp->left->sum + temp->right->sum;
        }
    }
    
    int sumRange(int left, int right) {
        return sumRangeRecursion(root, left, right);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */