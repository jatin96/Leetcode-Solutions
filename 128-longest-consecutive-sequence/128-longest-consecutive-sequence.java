class UnionFind {
    private int[] parent;
    private int[] rankBySize;
    public UnionFind(int size) {
        parent = new int[size];
        rankBySize = new int[size];
        initialize(size);
    }
    
    private void initialize(int size) {
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            rankBySize[i] = 1;
        }
    }
    
    int find(int x) {
        if (x == parent[x]) return x;
        
        return parent[x] = find(parent[x]);
    }
    
    int[] getRanks() {
        return rankBySize;
    }
    
    void combine(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);
        
        int sizeOfA = rankBySize[parentA];
        int sizeOfB = rankBySize[parentB];
        
        if ( rankBySize[parentA] < rankBySize[parentB]) {
            parent[parentA] = parentB;
            rankBySize[parentB] += rankBySize[parentA];
        } else {
            parent[parentB] = parentA;
            rankBySize[parentA] += rankBySize[parentB];
        }
    }
}

class Solution {
    public int longestConsecutive(int[] nums) {
        Map<Integer, Integer> numberExists = new HashMap<>();
        UnionFind unionFind = new UnionFind(nums.length);
        
        for (int i = 0; i < nums.length; i++) {
            
            if(numberExists.containsKey(nums[i])) continue;
            
            if (numberExists.containsKey(nums[i] - 1)) {
                unionFind.combine(i, numberExists.get(nums[i] - 1));
            }
            
            if (numberExists.containsKey(nums[i] + 1)) {
                unionFind.combine(i, numberExists.get(nums[i] + 1));
            }
            
            numberExists.put(nums[i], i);
        }
        
        int[] ranks = unionFind.getRanks();
        
        int res = 0;
        for (int size : ranks) res = Math.max(res, size);
        
        return res;
    }
}