"""Write a Python program to maitain club members, sort on roll numbers in ascending order .  
   Write function "Ternary Search " to search whether particular student is member of club or not .
   Design menu driven program :
   1.Linear Search 
   2.Binary Search 
   3.Ternary Search """
class Club:
    st = [] #for storing unsorted student list
    rn = [] #for storing unsorted roll no
    sts = 0 #for storing sorted student list
    rns = 0 #for storing sorted roll no
    n = 0
    def member(self):
        a = int(input("Enter the number of students in the club : ")) #no. of students
        Club.n = a 
        for i in range(0,a):
            s=input("Enter the name of the student : ")  #Accepting Student's names
            Club.st.append(s)
            r=int(input("Enter the ID of the student : "))  #Accepting roll numbers
            Club.rn.append(r)
        print("The Entered Data is : ")
        for i in range(0,a) :
            print("Name : ",Club.st[i]," Roll  No. : ",Club.rn[i])
    #using zip and sorted keyword for sorting lists simultaneously
    #Output is tuple again converting it into list
    def sort(self):
        x=Club.n
        Club.rn, Club.st = zip(*sorted(zip(Club.rn, Club.st)))
        Club.sts=list(Club.st)
        Club.rns=list(Club.rn)
        print("Data after sorting")
        for i in range(0,x) :
            print("Name : ",Club.sts[i]," Roll  No. : ",Club.rns[i])
    def linear_search(self):
        f=False
        x=Club.n
        s=int(input("Enter ID you want to search : "))
        for i in range(0,x):
            if ( Club.rns[i]==s ):
                f=True
                print("The Entered Student Roll No. ",s," is in the Club ")
        if not f :
            print("The Entered Student Roll No. is not in the club ")
    def binary_search(self):
        x=Club.n
        s=int(input("Enter ID you want to search : "))
        f=False
        low = 0
        high = Club.n - 1
        mid = 0  
        while low <= high:   
            mid = int((high + low) / 2)  
                     # Check if x is present at mid
            if Club.rns[mid] == s :
                f=True
                break
            if Club.rns[mid] < s: 
                low = mid + 1  
                # If x is greater, ignore left half 
            elif Club.rns[mid] > s: 
                high = mid - 1  
                # If x is smaller, ignore right half
        if not f:
            print("The Entered Student Roll No. is not in the club ")
        else :
            print("The Entered Student Roll No. ",s," is in the Club ")
    def ternary_search(self):
        x=Club.n
        s=int(input("Enter ID you want to search : "))
        f=0
        low=0
        high = Club.n - 1
        m1 = 0
        m2 = 0
        while low <= high :
            m1 = int(low + (low+high) / 3)
            m2 = int(low + 2*(low+high) / 3)
            if Club.rns[low]==s:
                print("The Entered Student Roll No. ",s," is in the Club ")
                break
            elif Club.rns[high] == s:
                print("The Entered Student Roll No. ",s," is in the Club ")
                break
            elif s < Club.rns[low] or s > Club.rns[high]:
                print("The Entered Student Roll No. is not in the club ")
                break
            elif s <= Club.rns[m1]:
                high = m1
            elif s > Club.rns[m1] and s <= Club.rns[m2]:
                low = m1 + 1
                high = m2
            else:
                low = m3 + 1
    def Menu(self):
        print("-----------------MENU-----------------")
        flag=1
        while flag==1 :    
            print("""1)Linear Search
2)Binary Search
3)Ternary Search
---------------------------------""")
            m=int(input("Enter your Choice : "))   #Menu Choice Variable
            x=Club.n
            #Linear Search
            if m==1 :
                obj.linear_search()
            #Binary Search
            elif m==2 :
                obj.binary_search()
                #Ternary Search
            elif m==3 :
                obj.ternary_search()
            else:
                print("Please enter a valid choice")
            b=int(input("Enter 1 to return to the Menu or enter 0 to exit the Menu "))
            flag=b
        
obj = Club() #Creating Object of class
obj.member()
obj.sort()
obj.Menu()

"""Enter the number of students in the club : 4
Enter the name of the student : A
Enter the ID of the student : 7
Enter the name of the student : B
Enter the ID of the student : 9
Enter the name of the student : D
Enter the ID of the student : 6
Enter the name of the student : C
Enter the ID of the student : 8
The Entered Data is : 
Name :  A  Roll  No. :  7
Name :  B  Roll  No. :  9
Name :  D  Roll  No. :  6
Name :  C  Roll  No. :  8
Data after sorting
Name :  D  Roll  No. :  6
Name :  A  Roll  No. :  7
Name :  C  Roll  No. :  8
Name :  B  Roll  No. :  9
-----------------MENU-----------------
1)Linear Search
2)Binary Search
3)Ternary Search
---------------------------------
Enter your Choice : 1
Enter ID you want to search : 6
The Entered Student Roll No.  6  is in the Club 
Enter 1 to return to the Menu or enter 0 to exit the Menu 1
1)Linear Search
2)Binary Search
3)Ternary Search
---------------------------------
Enter your Choice : 2
Enter ID you want to search : 8
The Entered Student Roll No.  8  is in the Club 
Enter 1 to return to the Menu or enter 0 to exit the Menu 1
1)Linear Search
2)Binary Search
3)Ternary Search
---------------------------------
Enter your Choice : 3
Enter ID you want to search : 2
The Entered Student Roll No. is not in the club 
Enter 1 to return to the Menu or enter 0 to exit the Menu 0"""
