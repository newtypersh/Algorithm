class Solution {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        int row_length = arr1.length;
        int col_length = arr1[0].length;  
        
        int[][] answer = new int[row_length][col_length];
        
        for(int i = 0; i < row_length; i++) {
            for(int j = 0; j < col_length; j++) {
                answer[i][j] = arr1[i][j] + arr2[i][j];
            }
        }
        
        return answer;
    }
}