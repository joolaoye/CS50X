#Check validility of a card
def main():
    card = input("Enter card number: ")
    for i in range(len(card)):
        if not card[i].isdigit():
            print("Input only integers")
            return 1
    global digits
    digits = list(card)
    if (normal_sum(card) + luhn_sum(card)) % 10 == 0:
        if (card[0] == '4') and (len(card) == 13 or len(card) == 16):
            print("VISA")
        elif (len(card) == 16) and (card[0]) == '5' and (card[1] == '1' or card[1] == '2' or card[1] == '3' or card[1] == '4'
            or card[1] == '5'):
            print("MASTERCARD")
        elif (len(card) == 15) and (card[0] == '3') and (card[1] == '4' or card[1] == '7'):
            print("AMEX")
        else:
            print("INVALID")
    else:
        print("INVALID")

def normal_sum(n):
    normal_digits = []
    i = len(n) - 1
    while i >= 0:
        normal_digits.append(int(digits[i]))
        i -= 2
    normal_sum = 0
    for i in range(len(normal_digits)):
        normal_sum += normal_digits[i]
    return normal_sum

def luhn_sum(n):
    luhn_digits = []
    i = len(n) - 2
    while i >= 0:
        digits[i] = int(digits[i]) * 2
        if digits[i] > 9:
            digits[i] = (digits[i] // 10) + (digits[i] % 10)
        luhn_digits.append(digits[i])
        i -= 2
    sum = 0
    for i in range(len(luhn_digits)):
        sum += luhn_digits[i]
    return sum
main()