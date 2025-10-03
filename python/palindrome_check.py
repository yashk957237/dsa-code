def is_palindrome(text):
    # Normalize by converting to lowercase and removing spaces/punctuation
    clean_text = ''.join(filter(str.isalnum, text)).lower()
    
    # Check if the reversed string equals the original
    return clean_text == clean_text[::-1]

# Example
word1 = "A man, a plan, a canal: Panama"
word2 = "hello world"

print(f"'{word1}' is palindrome: {is_palindrome(word1)}")
print(f"'{word2}' is palindrome: {is_palindrome(word2)}")