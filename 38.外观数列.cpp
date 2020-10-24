class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
          return "1";
        }
        string previous = countAndSay(n-1);
        string result = "";
        int count = 1;
        for(int i=0;i<previous.size();i++){
          if(previous[i] == previous[i+1])
          {
            count++;
          }
          else
          {
            result += to_string(count)+previous[i];  
            //to_string 转化为string.
            count = 1;
          }
        }
        return result;
    }
};