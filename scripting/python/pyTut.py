#!/bin/python3

# Importing

print("Importing is important")

import sys # system functions and parameters

from datetime import datetime # We can choose to only import modules
print(datetime.now())

from datetime import datetime as dt # Importing with an alias
print(dt.now())

# Advanced strings

my_name = "Donnie Darko"
print(my_name[0:6])
print(my_name[-5:])

sent = "This is a sentence."

print(sent.split())

sent_split = sent.split()
sent_join = ' '.join(sent_split)
print(sent_join)

print('\n'.join(sent_split))

quoteception = "I said, 'give me all the money'"

print(quoteception)


quoteception = "I said, \"give me all the money\""

print(quoteception)

print("A" in "Apple")
# Boolean logic so it returns True

letter = "a"
word = "Apple"
print(letter in word)
print(letter.lower() in word.lower())

word_two = "Bingo"

print((letter.lower() in word.lower()) and not (letter.lower() in
    word_two.lower()))

too_much_space = "             help          "
print(too_much_space.strip())


full_name = "eath Adams"
print(full_name.replace("eath", "Heath"))
print(full_name.find("Adams"))

movie = "The Hangover"
print("My favourite movie is {}".format(movie))

def favourite_book(title, author):
    fav = "My favourite book is \"{}\". which is written by {}".format(title, author)
    return fav

print(favourite_book("The great", "F Scotty"))


# Dictionaries

print("Dictionaries are keys and values:")
drinks = {"White Russians": 7, "Old Fashion": 10, "Lemon Drop": 8}

print(drinks)
