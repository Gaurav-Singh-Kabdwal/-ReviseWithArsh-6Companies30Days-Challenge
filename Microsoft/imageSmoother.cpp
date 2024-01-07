class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int dir[][2] = {{0,1},{1,0},{1,1},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1}};
        int cnt=0, n = img.size(), m= img[0].size(); 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                int sum = img[i][j], cnt = 1;
     
                for(int k=0;k<8;k++){

                   int x = i+dir[k][0], y=j+ dir[k][1];
                   if(x<n&& x>=0&&y<m&&y>=0){
                       sum += (img[x][y]&255);
                       cnt++;
                   }
                }
                img[i][j] |= (sum/cnt)<<8;
                
            }

        }
        
        for(int i=0; i<n;i++){
            for(int j=0;j<m;j++){
                img[i][j] >>= 8;
            }
        }

        return img;
    }
};