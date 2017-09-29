class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() -1,
            j = b.length() -1;
        // result
        int k = max(i,j);
        string res(k+1, '0');
        //
        char carry = 0;
        for (;i >= 0 && j >= 0; i--, j--, k--) {
            char sum = (a[i] - '0') + (b[j] - '0') + carry;
            res[k] = sum % 2 + '0';
            carry = sum / 2;
        }
        for (; i >= 0; i--, k--) {
            char sum = (a[i] - '0') + carry;
            res[k] = sum % 2 + '0';
            carry = sum / 2;
        }
        for (; j >= 0; j--, k--) {
            char sum = (b[j] - '0') + carry;
            res[k] = sum % 2 + '0';
            carry = sum / 2;
        }
        if (carry)
            res.insert(0, 1, '0' + carry);

        return res;
    }
};