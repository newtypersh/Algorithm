#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// diff      = 난이도
// time_cur  = 현재 퍼즐의 소요 시간
// time_prev = 이전 퍼즐의 소요 시간
// level     = 숙련도 
// limit     = 제한시간
// diff > level => diff - level번 틀림 ((time_cur + timeprev) * (diff - level)) + time_cur

// diffs_len은 배열 diffs의 길이입니다.
// times_len은 배열 times의 길이입니다.

long long min(long long a, long long b){
    if(a > b) return b;
    return a;
}

long long time_calculate(int diffs[], size_t diffs_len, int times[], size_t times_len, int level){
    long long result = 0;
    for(int i=0;i<diffs_len;i++){
        if(diffs[i] <= level){
            result += times[i];
        }
        else{
            if(i == 0){
                result += (times[i] * (diffs[i] - level)) + times[i];
            }
            else{
                result += ((times[i] + times[i-1]) * (diffs[i] - level)) + times[i];
            }
        }
    }
    return result;
}

int solution(int diffs[], size_t diffs_len, int times[], size_t times_len, long long limit) {
    int answer = 1000000;
    int low = 1;
    int high = 100001;
    
    while(low <= high){
        int mid = (low + high) / 2;
        long long calc = time_calculate(diffs, diffs_len, times, times_len, mid);
        if(calc > limit) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
            answer = min(answer, mid);
        }
    }
    
    return answer; // = level = 숙련도
}