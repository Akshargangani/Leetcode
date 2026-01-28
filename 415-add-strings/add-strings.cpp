class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
       int i = num1.size()-1, j = num2.size()-1, c = 0;
        while(i>=0 || j>=0 || c){
            int sum =c;
            if(i>=0) sum +=num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            res += (sum % 10) + '0';
            c = sum / 10;

        }
        reverse(res.begin(), res.end());
        return res;
    }
};