class Solution {
public:
    bool checkValidString(string s) {
        int l = 0, r = 0;
        for (auto& x: s) {
            if (x == '(') l++, r++;
            else if (x == ')') l--, r--;
            else l--, r++;
            // If r < 0 means l is < 0 also, this is not a valid string so we break and will 
            // return false because of l == 0 validation at the end
            if (r < 0) break;
            // l cannot be lower than 0
            l = max(l, 0);
        }
        return l == 0;
    }
};
/*
NOTE: The following explanation belongs to Leetcode, if you would like to look at the whole article,
please visit this link: https://leetcode.com/articles/valid-parenthesis-string/.

When checking whether the string is valid, we only cared about the "balance": the number of extra, open 
left brackets as we parsed through the string. For example, when checking whether '(()())' is valid, we 
had a balance of 1, 2, 1, 2, 1, 0 as we parse through the string: '(' has 1 left bracket, '((' has 2, '(()' 
has 1, and so on. This means that after parsing the first i symbols, (which may include asterisks,) we only 
need to keep track of what the balance could be.
For example, if we have string '(***)', then as we parse each symbol, the set of possible values for the 
balance is [1] for '('; [0, 1, 2] for '(*'; [0, 1, 2, 3] for '(**'; [0, 1, 2, 3, 4] for '(***', and [0, 1, 2, 3] 
for '(***)'.
Furthermore, we can prove these states always form a contiguous interval. Thus, we only need to know the 
left and right bounds of this interval. That is, we would keep those intermediate states described above as 
[lo, hi] = [1, 1], [0, 2], [0, 3], [0, 4], [0, 3].
*/