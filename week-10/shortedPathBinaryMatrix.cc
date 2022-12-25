class Solution {
public:
    struct P{
        int x, y, t;
        P(int _x, int _y, int _t): x(_x), y(_y), t(_t){};
    };
    int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] || grid[n-1][n-1]) 
            return -1;
        queue<P> q;
        q.emplace(0, 0, 1);
        grid[0][0] = 1; 
        while(!q.empty()){
            auto [x, y, t] = q.front();
            q.pop();
            if(x==n-1 && y==n-1) 
                return t;
            for(int i=0;i<8;i++){
                int xx=x+dir[i][0], yy=y+dir[i][1], tt=t+1;
                if(xx>=0 && xx<n && yy>=0 && yy<n && !grid[xx][yy]){
                    q.emplace(xx, yy, tt);
                    grid[xx][yy] = 1;
                }
            }
        }
        return -1;
    }
};
