"""Write a python program to compute the following:
a)Addition of two matrices         b)Subtraction of two matrices
c)Transpose of two matrices      d)Multiplication of two matrices
"""

#Declaring function
def print_matrix(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            print( "\t" , matrix[i][j], end=" ")
        print("\n")


#Initializing matrix to 0
def initiate_matrix(matrix,m,n):
    matrix=[[0 for j in range(0,n)]for i in range(0,m)]
    return matrix
    print_matrix(matrix)


#Input the matrix element
def read_matrix():
    mat=[]
    r=int(input("Enter no. of rows for first matrix"))
    c=int(input("Enter no. of columns for first matrix"))
    mat= initiate_matrix(mat,r,c)
    for i  in range(0,r):
        for j in range(0,c):
            mat[i][j]=int(input("Enter an element :"))
    return mat,r,c

#Addition of matrices
def add_mat(m1,m2,res,m,n):
    for i in range(0,m):
        for j in range(0,n):
            res[i][j] = m1[i][j] + m2[i][j]
    return res


#Subtraction of matrices
def sub_mat(m1,m2,res,m,n):
    for i in range(0,m):
        for j in range(0,n):
            res[i][j]=m1[i][j]-m2[i][j]
    return res


#Transpose of matrix
def tran_mat(m1,res,r1,c1):
    for i in range(0,r1):
        for j in range(0,r2):
            res[j][i] = m1[i][j]
    return res


#Multiplication of matrices:
def mult_mat(m1,m2,res,r1,c1,c2):

    for i in range(0,r1):
        for k in range(0,c2):   
            for j in range(0,c1):
                res[i][k] += m1[i][j] * m2[j][k]
    return res



#Driving code
mat1=[]
mat2=[]
res_matrix=[]
print("First Matrix : ")
mat1,r1,c1 = read_matrix()
print("Second Matrix : ")
mat2,r2,c2 = read_matrix()

res_matrix = initiate_matrix(res_matrix,r1,c2)

#printing matrices
print("Matrix 1 ",print_matrix(mat1))
print("Matrix 2 ",print_matrix(mat2))

flag=1
while flag:
    print("------------Menu------------")
    print("1.Addition of matrices")
    print("2.Subtraction of matrices")
    print("3.Transpose of matrix")
    print("4.Multiplication of matrices")
    print("--Press 0 to exit.--")
    choice=int(input("Enter your choice:"))


    if choice == 1:
        if r1==r2 and c1==c2:
            print("Addition of matrices is:")
            res_matrix=add_mat(mat1,mat2,res_matrix,r1,c1)
            print_matrix(res_matrix)
        else:
            print("Addition of matrices  cant be performed.")


    elif choice == 2:
        if r1==r2 and c1==c2:
            print("Subtraction of matrices is:")
            res_matrix=sub_mat(mat1,mat2,res_matrix,r1,c1)
            print_matrix(res_matrix)
        else:
            print("Subtraction of matrices cant be performed.")


    elif choice == 3:
        if c1==r2:
            print("Transpose of matrices is:")
            res_matrix=tran_mat(mat1,res_matrix,r1,c1)
            print_matrix(res_matrix)
        else:
            print("Transpose of matrices cant be performed.")

    elif choice == 4:
        if r2==c1:
            print("Multiplication of matrices")
            res_matrix=mult_mat(mat1,mat2,res_matrix,r1,c1,c2)
            print_matrix(res_matrix)
        else:
            print("Multiplication of matrices cant be performed")
    elif choice == 0:
        flag = 0

"""
Output:

First Matrix : 
Enter no. of rows for first matrix2
Enter no. of columns for first matrix2
Enter an element :1
Enter an element :3
Enter an element :4
Enter an element :2
Second Matrix : 
Enter no. of rows for first matrix2
Enter no. of columns for first matrix2
Enter an element :3
Enter an element :4
Enter an element :2
Enter an element :1
	 1 	 3 

	 4 	 2 

Matrix 1  None
	 3 	 4 

	 2 	 1 

Matrix 2  None
------------Menu------------
1.Addition of matrices
2.Subtraction of matrices
3.Transpose of matrix
4.Multiplication of matrices
--Press 0 to exit.--
Enter your choice:1
Addition of matrices is:
	 4 	 7 

	 6 	 3 

------------Menu------------
1.Addition of matrices
2.Subtraction of matrices
3.Transpose of matrix
4.Multiplication of matrices
--Press 0 to exit.--
Enter your choice:2
Subtraction of matrices is:
	 -2 	 -1 

	 2 	 1 

------------Menu------------
1.Addition of matrices
2.Subtraction of matrices
3.Transpose of matrix
4.Multiplication of matrices
--Press 0 to exit.--
Enter your choice:3
Transpose of matrices is:
	 1 	 4 

	 3 	 2 

------------Menu------------
1.Addition of matrices
2.Subtraction of matrices
3.Transpose of matrix
4.Multiplication of matrices
--Press 0 to exit.--
Enter your choice:4
Multiplication of matrices
	 10 	 11 

	 19 	 20 

------------Menu------------
1.Addition of matrices
2.Subtraction of matrices
3.Transpose of matrix
4.Multiplication of matrices
--Press 0 to exit.--
Enter your choice:0

"""
