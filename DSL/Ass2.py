"""Write a Python program to compute following operations on String:
1)To display word with longest length
2)To determine the frequency of occurences of particular character in the string
4)To check whether given string is palindrome or not
5)To display index of first appearances of the substring
6)To print the occurrnces of each word in a given string
"""

#Accepting string from user
str1=input("Enter a String")
print("Entered String is :",str1)

#To display the word with the longest length
#Creating the list for separation of each word of string
list1=str1.split()
print("String is",list1)

len_word=0
word_pos=0
i=0

for i in range (len(list1[i])):
    if len_word < len(list1[i]):
        len_word=len(list1[i])
        word_pos=i
print("The word with longest length is ",list1[word_pos])


#To determine the frequency of occurrences of particular character in the string
str1=input("Enter a string")
list1=[str1]
i=0
Occ_Char=input("Enter the character to be searched in string")
counter = 0
for i in range (len(list1[i])):
    if Occ_Char==str1[i]:
        counter+=1
print("Chatracter",Occ_Char,"is present",counter,"times in string",str1)


#To check whether the given string is palindrome or not
str1=input("Enter a string")
str2=str1.replace(" ","")#to remove whitespaces from string

if(str2==str2[::-1]):
    print("The string is a palindrome")
else:
    print("Entered string is not a palindrome")

#To display the occurrences of each word in a given string
str1=input("Enter a string ")
substring = input("Enter the sub string to find starting index")
index=str1.find(substring)
if(index==-1):
    print("Substring is not present")
else:
    print("Substring start at index:",index)

#To count the occurrences of each word in a given string
print("By entering string below will show no.","\n",
      "of occurrences of word in entered string")
str1=input("Enter a string ")
dict1=[]
counts=dict()
words = str1.split()
for word in words:
    if word in counts:
        counts[word]+=1
    else:
        counts[word]=1
print(counts)

"""
Enter a Stringhi hello
Entered String is : hi hello
String is ['hi', 'hello']
The word with longest length is  hello
Enter a stringhi hello
Enter the character to be search in stringhi hello
Chatracter hi hello is present 0 times in string hi hello
Enter a stringhi hello
Entered string is not a palindrome
Enter a string hi hello
Enter the sub string to find starting indexh
Substring start at index: 0
By entering string below will show no. 
 of occurrences of word in entered string
Enter a string hi hello
{'hi': 1, 'hello': 1}
"""

        
