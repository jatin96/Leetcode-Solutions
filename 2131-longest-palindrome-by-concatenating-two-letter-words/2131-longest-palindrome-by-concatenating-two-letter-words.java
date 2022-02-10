class Solution {
    public int longestPalindrome(String[] words) {
        HashMap<String, Integer> hm = new HashMap<>();
        
        for (int i = 0; i < words.length; i++){
            hm.put(words[i], hm.getOrDefault(words[i], 0) + 1);
        }
        
        int res = 0;
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            if (word.charAt(0) != word.charAt(1)) {
                int cnt1 = hm.get(word);
                int cnt2 = hm.getOrDefault("" + word.charAt(1) + word.charAt(0), 0);
                res += 2*2*Math.min(cnt1, cnt2);
                hm.put(word, 0);
                hm.put("" + word.charAt(1) + word.charAt(0), 0);
            } else {
                int cnt = hm.get(word);
                if (cnt % 2 == 0) {
                    res += 2*cnt;
                    hm.put(word, 0);
                } else {
                    if (cnt > 1) {
                        res += 2*(cnt - 1);
                        hm.put(word, 1);
                    }
                }
            }
        }
        
        for (String word: hm.keySet()) {
            int cnt = hm.get(word);
            if (word.charAt(0) == word.charAt(1) && cnt == 1) {
                res += 2*cnt;
                hm.put(word, 0);
                break;
            }
        }
        
        return res;
    }
}