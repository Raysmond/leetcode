Word Break II
======

##Description
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

##Solution
```cpp
public class Solution {
	public ArrayList<String> wordBreak(String s, Set<String> dict) {
		int len = s.length();
		boolean[] dp = new boolean[len + 1];
		dp[len] = true;
		for (int i = len - 1; i >= 0; i--) {
			for (int j = i; j < len; j++) {
				String str = s.substring(i, j + 1);
				if (dict.contains(str) && dp[j + 1]) {
					dp[i] = true;
				}
			}
		}
		ArrayList<String> result = new ArrayList<String>();
		if (dp[0])
			findBreaks(result, "", s, 0, dict);
		return result;
	}

	public void findBreaks(ArrayList<String> result, String ret, String s,
			int n, Set<String> dict) {
		if (n == s.length()) {
			result.add(ret);
			return;
		}
		for (int i = n; i < s.length(); i++) {
			String str = s.substring(n, i + 1);
			if (dict.contains(str)) {
				String tmp = ret.equals("") ? str : ret + " " + str;
				findBreaks(result, tmp, s, i + 1, dict);
			}
		}
	}
}
```