class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int nCustomers = customers.size();
        int satisfied = 0, addSatisfied = 0, maxAddSatisfied = 0;
        for (int i = 0; i < nCustomers; i++) {
            satisfied += !grumpy[i] * customers[i];
            addSatisfied += grumpy[i] * customers[i];
            if(i >= minutes) {
                addSatisfied -= grumpy[i - minutes] * customers[i - minutes];
            }
            
            maxAddSatisfied = max(addSatisfied, maxAddSatisfied);
        }
        
        return satisfied + maxAddSatisfied;
    }
};