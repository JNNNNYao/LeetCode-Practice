class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int r = image.size();
        int c = image[0].size();
        int oldColor = image[sr][sc];
        if(oldColor == newColor){
            return image;
        }
        image[sr][sc] = newColor;
        if(sr < r-1 && image[sr+1][sc] == oldColor){
            floodFill(image, sr+1, sc, newColor);
        }
        if(sr > 0 && image[sr-1][sc] == oldColor){
            floodFill(image, sr-1, sc, newColor);
        }
        if(sc < c-1 && image[sr][sc+1] == oldColor){
            floodFill(image, sr, sc+1, newColor);
        }
        if(sc > 0 && image[sr][sc-1] == oldColor){
            floodFill(image, sr, sc-1, newColor);
        }
        return image;
    }
};