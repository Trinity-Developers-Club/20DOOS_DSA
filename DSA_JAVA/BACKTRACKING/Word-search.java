// Ques:https://leetcode.com/problems/word-search/

class Solution {
    
    public boolean exist(char[][] board, String word) {
        boolean ans = false;
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				if (word.charAt(0) == board[i][j]) {
					ans = wordsearch(board, i, j, word,0);
					if (ans == true) {
						return ans;
					}

				}

			}

		}
		return false;
       
    }
  public static boolean wordsearch(char[][] board, int i, int j, String word, int idx) {
		// TODO Auto-generated method stub
		if(idx==word.length()) {
			return true;
		}

		if (i < 0 || j < 0 || i >= board.length || j >= board[0].length || word.charAt(idx) != board[i][j]) {
			return false;
		}
		board[i][j] = '*';

		int r[] = { -1, 1, 0, 0 };
		int c[] = { 0, 0, -1, 1 };

		for (int k = 0; k < c.length; k++) {
			boolean ans = wordsearch(board, i + r[k], j + c[k], word, idx + 1);
			if (ans == true) {
				return true;
			}

		}
		board[i][j] = word.charAt(idx);
		return false;
	}
    
}
