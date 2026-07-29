class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            columnNumber--; // Shift to 0-based index for standard base-26 modulo
            
            int remainder = columnNumber % 26;
            result += (char)('A' + remainder);
            
            columnNumber /= 26;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};