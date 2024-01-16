# TODO
def main():
    text = input("Text: ")
    L = ((letter_length(text)) * 100) / (word_length(text))
    S = ((sentence_length(text)) * 100) / (word_length(text))
    index = round(((0.0588 * L) - (0.296 * S)) - 15.8)
    print(assign_grade(index))


def letter_length(word):
    letter_count = 0
    for i in word:
        if i.isalpha():
            letter_count += 1
    return letter_count


def word_length(word):
    word = word.split(" ")
    return len(word)


def sentence_length(word):
   sentence_count = 0
   for i in word:
       if i == "." or i == "!" or i == "?":
           sentence_count += 1
   return sentence_count


def assign_grade(index):
    if index < 1:
        return f"Before Grade 1"
    elif index > 16:
        return f"Grade 16+"
    else:
        return f"Grade {index}"


if __name__ == "__main__":
    main()