# Data types in R
num <- 3.7 #Decimals are part of the Numeric class in R
typeof(num)
i <- 10 #Whole numbers are known as integers
typeof(i) #To check the data type of the variable

t <- TRUE
f <- FALSE #Boolean values are part of the logical class
typeof(t)

ch <- "HELLO" #Text/string values are known as characters 
class (ch) #Checks the data type of a variable
typeof(ch) #Checks the data type of a variable

c <- 1+2i #R supports complex data type too
class(c)
length(c)



# Basic Arithmetic operations

6+2 #Addition
7-2 #Subtraction
2*2 #Multiplication
5/2 #Division
6^2 #Exponent
12%%5 #Modulo - returns the remainder



# Assigning values to  variables 
A <- 5000               #Assign variable1
A1 = 5000
B <- 2500                  #Assign variable2
C <- A - B     #Assign variable3
C                     #Displays the variable C



# Using the Print function

print ("hey") #Prints hey on the screen 

y <- 20
print(y) #Prints the value of y
print(paste('hello','students'))  #Paste function #use help 

print(paste('hello','students',sep=',')) #Sep is for the chosen separator between the pasted items

paste0('hello','students')  #Displays without space, when no separator is used

sprintf("%s is %f feet tall", "Saladi", 5.1) #Returns a character vector containing a formatted combination of text and variable values 
#%s is a placeholder for a string.
#%f is a placeholder for a floating-point number (a decimal).

library(datasets)  # Load/unload base packages manually #Inbuilt dataset 
x <- airquality     
head(airquality )
print(x)
# help for plot 
?plot  # Help for plot()

plot (x$Ozone,x$Month) #plot the two column in the data set
plot (x$Ozone,x$Solar.R)
plot (x$Ozone,x$Temp)
# plot functions in R 

plot(cos, 0, 3*pi)
plot(sin, 0, 3*pi) 
plot(exp, 1, 10)
plot(dnorm, -3, +3)

# Create vectors
vec1<-c(10,20,30) # CREATES VECTOR with specified values in the brackets
vec1
class(vec1)
?c

vec2<-c("a","b","c") # another form of vector creating 
vec2
class(vec2) # here the class of the vector is charectar 

vec3<-c(TRUE,FALSE,TRUE)

vec3
class(vec3)

# Print the above 3 vectors at once with semicolon
vec1;vec2;vec3 #';' is used to separate 2 or more variables 

############################################################
# different ways of assging values to a vector  in a sequece
# define vectors with lower and upper bound values on a line with space 1
vec2<-c(1:50)
vec2

vec4<-1:50
vec4

vec3<-seq(1,50) # this gives the sequence of the vector with space 1
vec3

##############
#Create a vector with space other than 1 
c1<-seq(0,100,5)
c1
#Create a vector with odd values in range 1 too 100

odd<-seq(1,100,2)
odd

#Create a vector with even values in range 1 too 100

even<-seq(0,100,2)
even

#Create vector with 20 odd values above 31
# length.out gives the length of the sequence
# by is the the spread on the linespace by the value assigned using "by"
odd<-seq(from=31,by=2,length.out=20)
odd
length(odd)
# Naming your vectors using names() function

# Create a numeric vector
numeric_vector <- c(1, 2, 3, 4, 5)
numeric_vector
# Name the elements of the vector
names(numeric_vector) <- c("One", "Two", "Three", "Four", "Five")

# Print the vector with names
print(numeric_vector)

# Another way to name your vectors

count <-c("One", "Two", "Three", "Four", "Five")
numeric_vector <- c(1, 2, 3, 4, 5)
names(numeric_vector) <-count
numeric_vector


# Basic operation on Vectors
numeric_vector <- c(1, 2, 3, 4, 5)
# Addition
result_addition <- numeric_vector + 10
result_addition
# Subtraction
result_subtraction <- numeric_vector - 3
result_subtraction
# Multiplication
result_multiplication <- numeric_vector * 2
result_multiplication
# Division
result_division <- numeric_vector / 2
result_division

# more example for operations between two vectors 
# Define two numeric vectors
vector1 <- c(1, 2, 3, 4, 5)
vector2 <- c(5, 4, 3, 2, 1)

# Addition
result_addition <- vector1 + vector2
print("Addition:")
print(result_addition)


# Subtraction
result_subtraction <- vector1 - vector2
print("\nSubtraction:")

print(result_subtraction)

# Multiplication
result_multiplication <- vector1 * vector2
print("\nMultiplication:")
print(result_multiplication)

# Division
result_division <- vector1 / vector2
print("\nDivision:")
print(result_division)

# Exponentiation
result_exponentiation <- vector1 ^ vector2
print("\nExponentiation:")
print(result_exponentiation)

vector1 <- c(1, 2, 3, 4, 5)
vector2 <- c(5, 4, 3, 2, 1)

# Element-wise comparison
comparison_result <- vector1 > vector2
print("\nElement-wise Comparison (Greater Than):")
print(comparison_result)

# Define two numeric vectors
vector1 <- c(1, 2, 3, 4, 5)
vector2 <- c(5, 4, 3, 2, 1)

# Absolute difference
absolute_difference <- abs(vector1 - vector2)
print("Absolute Difference:")
print(absolute_difference)

# Element-wise equality check
equality_check <- vector1 == vector2
print("\nElement-wise Equality Check:")
print(equality_check)

# Element-wise inequality check
inequality_check <- vector1 != vector2
print("\nElement-wise Inequality Check:")
print(inequality_check)

# Logical AND
logical_and <- vector1 > 2 & vector2 < 4
print("\nLogical AND:")
print(logical_and)

# Logical OR
logical_or <- vector1 < 2 | vector2 > 4
print("\nLogical OR:")
print(logical_or)



sum(vector1) # Add the values in a vector
sd(vector1) # Finds the standard deviation
var(vector1) # To display the variance
prod(vector1) # Give the product of the vector values
max(vector1) # Returns the maximum value 
min(vector1) # Returns the minimun value


# Vector slicing and indexing

# Vector slicing and indexing
v1 <- seq(50, 200, 20)
print("Original Vector:")
print(v1)
l<- length(v1)
l
# Naming the vector elements p1, p2, p3, ...
names(v1) <- paste0("p", 1:l)
print("\nNamed Vector:")
print(v1)  # price1 is a named vector

# 1. Using index position
print("\nIndexing Examples:")
print("Element at index 3:")
print(v1[3])

print("Elements at indices 3 to 4:")
print(v1[3:4])

print("Elements at indices 1 and 4:")
print(v1[c(1, 4)])

print("Elements at indices 2 and 6:")
print(v1[c(2, 6)])


#4.Using exclude position method
v1[-2]
v1[c(-2,-5)]
v1

#5. Using comparision operator
v1[v1>100]

filter <- v1>100
v1[filter]


# Clear console
cat("\014")  # ctrl+L


ID = c(1,2,3,4)
Patient_name=c("Ram", "Shyam", "N", "M")
num.patient = 4
patient_list = list(num.patient, ID, Patient_name)
patient_list[1]

for (i in ID){
  for (j in i){
    print(j)
  }
}


a = 3%%7
a
typeof(a)
a+10
