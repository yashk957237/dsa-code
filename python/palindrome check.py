word = input("Enter a word to check for palindrome: ").strip().split()[0].lower()
print("Palindrome") if word == word[::-1] else print("Not Plindrome")