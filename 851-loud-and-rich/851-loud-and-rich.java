class Solution {
    public int[] loudAndRich(int[][] richer, int[] quiet) {
        int n = quiet.length;
        int[] indegree = new int[n];
        int[] answer = new int[n];
        
        for (int i = 0; i < n; i++)
            answer[i] = i;
        
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        Queue<List<Integer>> queue = new LinkedList<>();
        
        for (int i = 0; i < n; i++)
            graph.add(new ArrayList<Integer>());
        
        for (int i = 0; i < richer.length; i++) {
            int u = richer[i][0];
            int v = richer[i][1];
            graph.get(u).add(v);
            indegree[v]++;
        }
        
        
        
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                queue.add(new ArrayList(Arrays.asList(i, i)));
        }
        
        while (!queue.isEmpty()) {
            List<Integer> parentNode = queue.remove();
            int nodeIndex = parentNode.get(0);
            int quietNode = parentNode.get(1);
            
            for (Integer childNode : graph.get(nodeIndex)) {
                if (quiet[answer[childNode]] > quiet[answer[nodeIndex]])
                    answer[childNode] = answer[nodeIndex];
                indegree[childNode]--;
                if(indegree[childNode] == 0)
                    queue.add(new ArrayList(Arrays.asList(childNode, answer[childNode])));
            }
        }
        
        return answer;
    }
}