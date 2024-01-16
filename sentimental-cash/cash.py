def main():
    cents = get_cents("Change owed: ")
    quarters = get_quarters(cents)
    cents -= (quarters * 25)
    dimes = get_dimes(cents)
    cents -= (dimes * 10)
    nickels = get_nickels(cents)
    cents -= (nickels * 5)
    pennies = get_pennies(cents)
    cents -= (pennies * 1)
    print(quarters + dimes + nickels + pennies)


def get_cents(prompt):
    while True:
        try:
            x = float(input(prompt)) * 100
            if x < 1:
                continue
            else:
                 return x
        except (ValueError):
            continue


def get_quarters(cents):
    quarters_count = 0
    while cents >= 25:
        cents -= 25
        quarters_count += 1
    return quarters_count


def get_dimes(cents):
    dimes_count = 0
    while cents >= 10:
        cents -= 10
        dimes_count += 1
    return dimes_count


def get_nickels(cents):
    nickels_count = 0
    while cents >= 5:
        cents -= 5
        nickels_count += 1
    return nickels_count


def get_pennies(cents):
    pennies_count = 0
    while cents > 0:
        cents -= 1
        pennies_count += 1
    return pennies_count

if __name__ == "__main__":
    main()