class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() != popV.size()){ return false; }
        if (0 == pushV.size()) { return true; }
        
        stack<int> s;
        int pushIdx = 0, popIdx = 0;
        while (pushIdx < pushV.size() && popIdx < popV.size()){
            if (pushV[pushIdx] == popV[popIdx]){
                ++pushIdx;
                ++popIdx;
            } else {
                s.push(pushV[pushIdx++]);
            }
        }
        while (!s.empty()){
            if (s.top() != popV[popIdx]){
                return false;
            }
            s.pop();
            ++popIdx;
        }
        
        return true;
    }
};
