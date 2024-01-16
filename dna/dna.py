import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) < 3 or len(sys.argv) > 3:
        print("Invalid usage")
        sys.exit()
    elif sys.argv[1][len(sys.argv[1]) - 4:] != ".csv" or sys.argv[2][len(sys.argv[2]) - 4:] != ".txt":
        print("Invalid usage")
        sys.exit()

    # TODO: Read database file into a variable
    database = []
    subsequence = []
    count = {}
    compare_dict = {}
    with open(sys.argv[1]) as file:
        extract_file = csv.DictReader(file)
        for item in extract_file:
            database.append(item)

    for key in database[0].keys():
        subsequence.append(key)
    subsequence.pop(0)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as file1:
        dna_sequence = file1.readlines()

    # TODO: Find longest match of each STR in DNA sequence
    for items in subsequence:
        count[items] = longest_match(dna_sequence[0], items)

    # TODO: Check database for matching profiles
    for person in database:
        for key in count:
            compare_dict[key] = int(person[key])
        if compare_dict == count:
            sys.exit(person["name"])
    else:
        sys.exit("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
