vector<int> bfsOfGraph(int V, vector<int> adj[]) {
          vector<int> re;
          vector<int> visited(V, 0);
          int s = 0;
          queue<int> q;
          q.push(s);
          visited[0] = 1;
          
          while(!q.empty()) {
              re.push_back(q.front());
              for(auto it = adj[q.front()].begin(); it != adj[q.front()].end(); it++)  {
                  if(visited[*it] == 0) {
                      q.push(*it);
                      visited[*it] = 1;
                  }
              }
              q.pop();
          }
                
          return re;
    }