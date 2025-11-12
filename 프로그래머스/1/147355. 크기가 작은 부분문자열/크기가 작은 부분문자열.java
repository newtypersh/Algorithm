class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        int length = p.length();
        
        for(int i = length; i <= t.length(); i++) {
            String sub = t.substring(i - length, i);
            if(sub.compareTo(p) <= 0) answer++;
        }
        
        return answer;
    }
}