class Solution {
public:
    struct Edge{
        long long from, to, capacity, cost;
    };

    vector<vector<long long>> adj, cost, capacity;

    const long long INF = 1e18;
    void shortest_paths(long long n, long long v0, vector<long long>& d, vector<long long>& p) {
        d.assign(n, INF);
        d[v0] = 0;
        vector<bool> inq(n, false);
        queue<long long> q;
        q.push(v0);
        p.assign(n, -1);
        while (!q.empty()) {
            long long u = q.front();
            q.pop();
            inq[u] = false;
            for (int v : adj[u]) {
                if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                    d[v] = d[u] + cost[u][v];
                    p[v] = u;
                    if (!inq[v]) {
                        inq[v] = true;
                        q.push(v); 
                    }
                }
            }
        }
    }

    long long min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
        N+=7;
        adj.assign(N, vector<long long>());
        cost.assign(N, vector<long long>(N, 0));
        capacity.assign(N, vector<long long>(N, 0));
        for (Edge e : edges) {
            adj[e.from].push_back(e.to);
            adj[e.to].push_back(e.from);
            cost[e.from][e.to] = e.cost;
            cost[e.to][e.from] = -e.cost;
            capacity[e.from][e.to] = e.capacity;
        }
        long long flow = 0;
        long long cost = 0;
        vector<long long> d, p;
        while (flow < K) {
            shortest_paths(N, s, d, p);
            if (d[t] == INF)
                break;
            // find max flow on that path
            long long f = K - flow;
            long long cur = t;
            while (cur != s) {
                f = min(f, capacity[p[cur]][cur]);
                cur = p[cur];
            }
            // apply flow
            flow += f;
            cost += f * d[t];
            cur = t;
            while (cur != s) {
                capacity[p[cur]][cur] -= f;
                capacity[cur][p[cur]] += f;
                cur = p[cur];
            }
        }

        if (flow < K)
            return -1;
        else
            return cost;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();
        vector<Edge> E;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                E.push_back({i,n+j,1,abs(robot[i]-factory[j][0])});
            }
            E.push_back({n+m,i,1,0});
        }
        for(int i = 0;i<m;i++)
            E.push_back({n+i,n+m+1,factory[i][1],0});
        
        return min_cost_flow(n+m+2,E,n,n+m,n+m+1);
    }
};