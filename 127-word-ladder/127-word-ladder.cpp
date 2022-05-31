class Solution {
public:
    int ladder;
    
    int bfs(string &beginword,string &endword,unordered_set<string> &st )
    {
        queue<pair<string, int>> qq; // BFS
        
        qq.push({beginword, 1});
       
        while(!qq.empty())
        {
            string cur = qq.front().first;
            int currMoves = qq.front().second;
            qq.pop();
            
            if (cur == endword) return currMoves;

            for(int i=0;i<cur.length();i++) // traversing string
            {   
                string temp=cur;

                //now changing each letter to find out any similar word present or not
                for(char ch='a';ch<='z';ch++)
                {
                    temp[i]=ch; // changing  letters of word

                    if(temp==cur) // if any letter made it to its ancestor OR parent again
                        continue;

                    if(st.find(temp) != st.end()) // if exist in set
                    {
                        qq.push({temp, currMoves + 1}); // adding in queue
                        st.erase(temp);// removing string from the set
                    }
                }
            } 
        }
        return 0;
    }
    
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
     
        unordered_set<string> st;
        int ladder=0;
        
        
        
        for(auto &it:wordList) st.insert(it);
        
        if(st.count(endWord)==0) return ladder;
        
        //now traversing begin word through BFS
        return bfs(beginWord,endWord,st);
        
        
    }
};