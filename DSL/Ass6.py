#size of array
print("Please note that this program is to display\ntop five percentage so size must be greater than 5")
n=int(input("Enter size of array:"))
list1=[]  
#Accepting percentage
for i in range(0,n):
    array_input=float(input("Enter percentage of student:"))
    list1.append(array_input)
    
def partition(arr,low,high): 
    i = ( low-1 )         # index of smaller element 
    pivot = arr[high]     # pivot 
  
    for j in range(low , high): 
  
    # If current element is smaller than the pivot 
        if   arr[j] < pivot: 
          
        # increment index of smaller element 
            i = i+1 
            arr[i],arr[j] = arr[j],arr[i] 
  
    arr[i+1],arr[high] = arr[high],arr[i+1]
    return ( i+1 )
def quick_sort(arr,low,high): 
    if low < high: 
  
        # pi is partitioning index, arr[p] is now 
        # at right place 
        pi = partition(arr,low,high) 
        # Separately sort elements before 
        # partition and after partition 
        quick_sort(arr, low, pi-1) 
        quick_sort(arr, pi+1, high)
    
quick_sort(list1,0,n-1)
print(list1)
print("Top five scores are as follows:")
print(list1[-1],">",list1[-2],">",list1[-3],">",list1[-4],">",list1[-5])
"""Please note that this program is to display
top five percentage so size must be greater than 5
Enter size of array:6
Enter percentage of student:98
Enter percentage of student:44
Enter percentage of student:77
Enter percentage of student:66
Enter percentage of student:88
Enter percentage of student:85
[44.0, 66.0, 77.0, 85.0, 88.0, 98.0]
Top five scores are as follows:
98.0 > 88.0 > 85.0 > 77.0 > 66.0"""

