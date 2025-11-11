class Solution {
    public long solution(long n) {
        long answer = 0;
        
        double root = Math.sqrt(n);
        if(Math.floor(root) == root) {
            answer = (long) Math.pow((root + 1), 2);
        }
        else {
            answer = -1;
        }
        
        return answer;
    }
}