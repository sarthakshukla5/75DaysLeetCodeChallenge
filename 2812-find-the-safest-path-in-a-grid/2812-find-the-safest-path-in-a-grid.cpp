class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] || grid[n-1][n-1])return 0;
        vector<vector<int>>vis(n,vector<int>(n,0));
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                    q.push({0,i,j});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int d=q.front()[0],u=q.front()[1],v=q.front()[2];
            q.pop();
            vector<int>dx={0,0,-1,1},dy={-1,1,0,0};
            for(int i=0;i<4;i++){
                int x=u+dx[i],y=v+dy[i];
                if(x>=0 && x<n && y>=0 && y<n && !vis[x][y]){
                    vis[x][y]=1;
                    grid[x][y]=d+1;
                    q.push({d+1,x,y});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vis[i][j]=0;
            }
        }
        set<vector<int>,greater<>>s;
        s.insert({grid[0][0],0,0});
        vis[0][0]=1;
        while(!s.empty()){
            auto it = s.begin();
            int d = (*it)[0];
            int u = (*it)[1];
            int v = (*it)[2];
            s.erase(it);
            if(u==n-1 && v==n-1)return d;
            vector<int>dx={0,0,-1,1},dy={-1,1,0,0};
            for(int i=0;i<4;i++){
                int x=u+dx[i],y=v+dy[i];
                if(x>=0 && x<n && y>=0 && y<n && !vis[x][y]){
                    vis[x][y]=1;
                    s.insert({min(d,grid[x][y]),x,y});
                }
            }
        }
        return 0;
    }
};