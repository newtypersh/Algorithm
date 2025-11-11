class Solution {
    public boolean solution(int x) {
        boolean answer = true;
        
        String[] s = String.valueOf(x).split("");
        
        int sum = 0;
        for(String temp : s) {
            sum += Integer.parseInt(temp);
        }
        
        if(x % sum != 0) answer = false;
        
        return answer;
    }
}