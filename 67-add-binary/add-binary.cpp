class Solution {
public:
    string addBinary(string a, string b) {
         int i = a.length() - 1;   // pointer for a
    int j = b.length() - 1;   // pointer for b
    int carry = 0;            // carry for binary addition
    string result = "";       // final binary string (reversed)

    // Loop until both strings are processed or carry is left
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) {
            sum += a[i] - '0';   // convert char to int
            i--;
        }

        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }

        result.push_back((sum % 2) + '0');  // store result bit
        carry = sum / 2;                    // update carry
    }

    reverse(result.begin(), result.end()); // reverse to get correct binary string
    return result;
}
    
};