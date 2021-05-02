class info {
public:
    int pos;
    int height;
    int index;
    bool isLeft;
    
    info(int pos, int height, int index, bool isLeft) {
        this->pos = pos;
        this->height = height;
        this->index = index;
        this->isLeft = isLeft;
    }
};

bool myfunction (info a,info b) { return (a.pos < b.pos); }

class Solution {
private:
    int n;
    vector<int> segTree;
    
    void update(int l, int r, int index, int pos, int val) {
        if(l == r){
            segTree[index] = val;
        }
        else{
            int mid = (l+r)/2;
            if(pos <= mid){
                update(l, mid, index*2, pos, val);
            }
            else{
                update(mid+1, r, index*2+1, pos, val);
            }
            segTree[index] = max(segTree[index*2], segTree[index*2+1]); // choose max height from two segment
        }
    }
    
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        n = buildings.size();
        segTree.resize(n*4, 0);
        
        vector<vector<int>> ans;
        
        vector<info> sorted;
        for(int i = 0; i < n; i++){
            sorted.push_back(info(buildings[i][0], buildings[i][2], i, true));
            sorted.push_back(info(buildings[i][1], buildings[i][2], i, false));
        }
        sort (sorted.begin(), sorted.end(), myfunction);    // sorted based on position
        
        int prevHeight = -1;
        for(int i = 0; i < n*2; i++){
            // if there are multiple buildings on same locations
            // put them in or take out from the segTree first before evaluate the skyline
            while(i+1 < n*2 && sorted[i].pos == sorted[i+1].pos){
                if(sorted[i].isLeft){
                    update(0, n-1, 1, sorted[i].index, sorted[i].height);
                }
                else{
                    update(0, n-1, 1, sorted[i].index, 0);
                }
                i++;
            }
            
            if(sorted[i].isLeft){
                update(0, n-1, 1, sorted[i].index, sorted[i].height);
            }
            else{
                update(0, n-1, 1, sorted[i].index, 0);
            }
            
            if(segTree[1] != prevHeight){
                vector<int> coordinate;
                coordinate.push_back(sorted[i].pos);
                coordinate.push_back(segTree[1]);
                ans.push_back(coordinate);
                prevHeight = segTree[1];
            }
        }
        
        return ans;
    }
};