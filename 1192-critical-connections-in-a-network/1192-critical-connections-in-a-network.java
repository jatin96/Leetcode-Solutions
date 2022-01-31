class Solution {
    ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
    List<List<Integer>> res = new ArrayList<List<Integer>>();
    int n, e;
    void dfs(int u, int parent, boolean[] vis, int[] insertionTime, int[] lowestTime, int timer) {
        vis[u] = true;
        insertionTime[u] = lowestTime[u] = timer++;
        
        for (Integer v: graph.get(u)) {
            if (v == parent) continue;
            
            if (!vis[v]) {
                dfs(v, u, vis, insertionTime, lowestTime, timer);
                lowestTime[u] = Math.min(lowestTime[u], lowestTime[v]);
                
                if (lowestTime[v] > insertionTime[u])
                    res.add(Arrays.asList(u, v));
            } else {
                lowestTime[u] = Math.min(lowestTime[u], lowestTime[v]);
            }
        }
    }
    
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        
        this.n = n;
        this.e = connections.size();
        
        boolean[] vis = new boolean[n];
        int[] insertionTime = new int[n];
        int[] lowestTime = new int[n];
        
        for (int i = 0; i < n; i++)
            graph.add(new ArrayList<Integer>());
        
        for (int i = 0; i < e; i++) {
            int u = connections.get(i).get(0);
            int v = connections.get(i).get(1);
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        
        dfs(0, -1, vis, insertionTime, lowestTime, 0);
        
        return res;
    }
}