class avgMarks:
#variables
    avg=0.0
    a=[]

    #function to calculate average of class
    def averageScore(self):
        absent=0
        sum=0

        print("Enter -1 if student is absent")
        n=int(input("Enter number of students to be inserted"))

        for i in range(0,n):
            score=int(input("Enter Score:"))
            avgMarks.a.append(score)

        for x in avgMarks.a:
            if x!= -1:
                sum = sum+x
            else:
                absent=absent+1

        avgMarks.avg=sum/(n-absent)
        print("Averge of score in the list",round(avgMarks.avg ,2 ))

    #function to find lowest score of the class
    def lowscore(self):
        min1=avgMarks.a[0]
        for x in  avgMarks.a:
            #If the other element is less than 1st element
            if x<min1 and x!=-1:
                min1=x
                print("The lowest score of the class is",min1)
    #function to find the highest score
    def highscore(self):
        max1=avgMarks.a[0]

        for x in avgMarks.a:
            if x> max1:
                max1 = x
        print("The Highest Score of the class is ",max1)
    #function for absent students
    def absentstudent(self):
        count=0
        for x in avgMarks.a:
            if x==-1:
                count+=1
        print("Total absent students are:",count)

    #function of frequency of largst score
    def freqcount(self):
        #find the largest element
        largest=max(avgMarks.a)

        #Counter variable to store the no.of occurences
        count=0

        for i in avgMarks.a:
            #IF the value of i is=largest element
            if (i==largest):
                count+=1    
                print("Frequency of largest score:",count)
       
    
                
            
#creating object
obj=avgMarks()

#calling functions
obj.averageScore()
obj.highscore()
obj.lowscore()
obj.absentstudent()
obj.freqcount()

"""Output:
Enter -1 if student is absent
Enter number of students to be inserted4
Enter Score:1
Enter Score:2
Enter Score:3
Enter Score:4
Averge of score in the list 2.5
The Highest Score of the class is  4
Total absent students are: 0
Frequency of largest score: 1"""
