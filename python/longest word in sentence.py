s = input("Enter sentance: ").strip().split()
print("longest word: ",max(s,key=len))