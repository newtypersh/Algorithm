def solution(s):
    answer = ''
    result = []
    words = s.split(' ')
    
    for word in words:
        new_word = ""
        for j, char in enumerate(word):
            if j % 2 == 0:
                new_word += char.upper()
            else:
                new_word += char.lower()
        result.append(new_word)

    answer = " ".join(result)
    
    return answer