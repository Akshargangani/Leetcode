class Solution {
public:
    string winningPlayer(int x, int y) {
        return (min(x,y/4)%2==1)?"Alice":"Bob";
    }
};