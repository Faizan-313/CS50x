text = input("Text: ")
S = 0
L = 0
word_count = 1
for c in text:
    if c == "." or c == "?" or c == "!":
        S += 1
    if c == " ":
        word_count += 1
    if c.isalpha():
        L += 1

s = S / word_count * 100
l = L / word_count * 100
index = 0.0588 * l - 0.296 * s - 15.8
if index > 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {round(index)}")
