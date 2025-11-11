doc = input()
word = input()

cnt = 0
pos = 0

while True:
    idx = doc.find(word, pos)
    if idx == -1:
        break
    cnt += 1
    pos = idx + len(word)

print(cnt)