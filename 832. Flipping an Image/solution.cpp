class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i = 0; i < image.size(); i++){
            int j, k;
            for(j = 0, k = image[i].size()-1; j < k; j++, k--){
                int temp = image[i][j] ^ 1;
                image[i][j] = image[i][k] ^ 1;
                image[i][k] = temp;
            }
            if(j == k){
                image[i][j] = image[i][j] ^ 1;
            }
        }
        return image;
    }
};