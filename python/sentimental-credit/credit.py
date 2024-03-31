def main():
    card_no = int(input("Number: "))
    x = int(str(card_no)[:2])
    count = 0
    digits = digits_of(card_no)
    for _ in digits:
        count += 1
    amex = [34, 37]
    mastercard = [51, 52, 53, 54, 55]
    if luhn_checksum(card_no) == 0:
        if count == 15 and x in amex:
            print("AMEX")
        elif count == 13 or count == 16 and int(str(card_no)[:1]) == 4:
            print("VISA")
        elif count == 16 and x in mastercard:
            print("MASTERCARD")
        else:
            print("INVALID")
    else:
        print("INVALID")
        exit()


def luhn_checksum(card_number):
    digits = digits_of(card_number)
    odd_digits = digits[-1::-2]
    even_digits = digits[-2::-2]
    checksum = 0
    checksum += sum(odd_digits)
    for d in even_digits:
        checksum += sum(digits_of(d * 2))
    return checksum % 10


def digits_of(n):
    return [int(d) for d in str(n)]


if __name__ == "__main__":
    main()
