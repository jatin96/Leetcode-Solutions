class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        HashMap<String, Integer> hm = new HashMap<>();
        
        for (int i = 9; i < s.length(); i++) {
            String sub = s.substring(i - 9, i + 1);
            if (hm.containsKey(sub))
                hm.put(sub, hm.get(sub) + 1);
            else
                hm.put(sub, 1);
        }
        
        Iterator it = hm.entrySet().iterator();
        List<String> res = new ArrayList<>();
        while (it.hasNext()) {
            Map.Entry entry = (Map.Entry)it.next();
            if ((int)entry.getValue() >= 2)
                res.add((String)entry.getKey());
        }
        
        return res;
    }
}