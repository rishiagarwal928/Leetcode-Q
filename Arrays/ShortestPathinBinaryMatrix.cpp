

class Solution {
public:
//to explore all directions.
    vector<pair<int,int>> directions{{-1,-1},{-1,1},{1,-1},{1,1},{-1,0},{1,0},{0,-1},{0,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
		//if start or end is invalid then path not possible.
        if(grid[0][0]==1 || grid.back().back()==1)
            return -1;
		//start with 0,0.
        q.push({0,0});
        pair<int,int> end={grid.size()-1,grid.size()-1};
        int level=0;
		//code for level order traversal (BFS).
        while(!q.empty()){
            level++;
            int size=q.size();
            while(size--){
                pair<int,int> temp=q.front();
                q.pop();
                if(temp==end)
                    return level;
                for(auto dir:directions){
                    int x=temp.first+dir.first;
                    int y=temp.second+dir.second;
                    if(x>=0 && y>=0 && x<grid.size() && y<grid.size() && grid[x][y]==0){
                        q.push({x,y});
                        grid[x][y]=1;
                    }
                }
            }
        }
        return -1;
    }
};

