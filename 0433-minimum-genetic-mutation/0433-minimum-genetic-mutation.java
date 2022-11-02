class Solution {
    public int minMutation(String start, String end, String[] bank) {
        String geneTypes = "ACGT";
        Set<String> visitedMutations = new HashSet<>();
        Set<String> mutationBank = new HashSet<>();
        
        for (String mutation : bank) mutationBank.add(mutation);
        
        Queue<Mutation> mutationQueue = new LinkedList<>();
        mutationQueue.add(new Mutation(start, 0));
        visitedMutations.add(start);
        while (!mutationQueue.isEmpty()) {
            Mutation currentMutation = mutationQueue.poll();
            String currentMutationName = currentMutation.mutationName;
            
            if (currentMutationName.equals(end)) return currentMutation.noOfMutations;
            
            for (int i = 0; i < currentMutationName.length(); i++) {
                for (int j = 0; j < geneTypes.length(); j++) {
                    char geneType = geneTypes.charAt(j);
                    if (geneType != currentMutationName.charAt(i)) {
                        String nextMutationName = currentMutationName.substring(0, i) + 
                                                    geneType + 
                                                    currentMutationName.substring(i + 1);
                        if (mutationBank.contains(nextMutationName) && !visitedMutations.contains(nextMutationName)) {
                            mutationQueue.add(new Mutation(nextMutationName, currentMutation.noOfMutations + 1));
                            visitedMutations.add(nextMutationName);
                        }
                    }
                }
            }           
        }
        
        return -1;
    }
    
    class Mutation {
        String mutationName;
        int noOfMutations;
        public Mutation(String mutationName, int noOfMutations) {
            this.mutationName = mutationName;
            this.noOfMutations = noOfMutations;
        }
    }
}