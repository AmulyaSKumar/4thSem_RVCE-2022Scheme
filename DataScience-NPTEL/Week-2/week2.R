library(Matrix)

# Create the matrix
food_data <- matrix(c(2, 4, 3, 3, 1, 2, 1, 2, 1), nrow = 3, byrow = TRUE,
                    dimnames = list(c("Food A", "Food B", "Food C"),
                                    c("Protein", "Carbohydrates", "Fat")))
food_data

rank <- qr(food_data)$rank
cat("Rank of the matrix:", rank, "\n")

# There isn't a direct function to calculate the null space in base R

# Calculate the null space
tmp <- qr(food_data)
set <- if(tmp$rank == 0L) seq_len(ncol(food_data)) else  -seq_len(tmp$rank)
null_space=qr.Q(tmp, complete = TRUE)[, set, drop = FALSE]

cat("Null Space:\n")
print(null_space)

n <- ncol(food_data)
cat("Rank-Nullity Theorem Verification:\n")
cat("Rank + Nullity =", rank, "+", ncol(null_space), "=", n, "\n")

#---------- LINEAR Equations-----------------
install.packages("matlib", dependencies = TRUE) 
library(matlib)

#----------Consistent eqn----------
A <- matrix(c(1, 2, 2, 4), 2, 2) 
b <- c(3, 6) 
#Ax=b
showEqn(A, b)
c( R(A), R(cbind(A,b)) )          # show ranks
all.equal( R(A), R(cbind(A,b)) )  # consistent?
plotEqn(A,b)                      # Plot
Solve(A, b, fractions = TRUE)     # show solution 

#---------Unique----------
A1 <- matrix(c(1, 2, -1, 2), 2, 2)
b1 <- c(2,1)
#
showEqn(A1, b1)
c( R(A1), R(cbind(A1,b1)) ) 
all.equal( R(A1), R(cbind(A1,b1)) )  # consistent?
plotEqn(A1,b1)
Solve(A1, b1, fractions = TRUE)

#----Inconsistent eqn------
c <- matrix(c(1, 2, 2, 4), 2, 2)

d <- c(-3, 6)
showEqn(c, d)
c( R(c), R(cbind(c,d)) ) 
all.equal( R(c), R(cbind(c,d)) )  # consistent?
plotEqn(c,d)
Solve(c, d, fractions = TRUE)

# Similarly try for 3 consistent and inconsistent eqn

#Lets check if we have 3 unknown variables 
#Consistent
A <- matrix(c(2, 1, -1,
              -3, -1, 2,
              -2,  1, 2), 3, 3, byrow=TRUE)
colnames(A) <- paste0('x', 1:3)
colnames(A)
A
b <- c(8, -11, -3)
showEqn(A, b)
c( R(A), R(cbind(A,b)) )          # show ranks
all.equal( R(A), R(cbind(A,b)) )
solve(A, b)
solve(A) %*% b #For matrix form
inv(A) %*% b #alternative

# Alternative way to solve  (echelon form)
echelon(A, b)
echelon(A, b, verbose=TRUE, fractions=TRUE) #for full details (step by step)

#Plotting
plotEqn3d(A,b)
plotEqn3d(A,b, xlim=c(0,4), ylim=c(0,4))

#Inconsistent
A <- matrix(c(1,  3, 1,
              1, -2, -2,
              2,  1, -1), 3, 3, byrow=TRUE)
colnames(A) <- paste0('x', 1:3)
b <- c(2, 3, 6)
showEqn(A, b)
c( R(A), R(cbind(A,b)) )          # show ranks
all.equal( R(A), R(cbind(A,b)) )
solve(A, b)

# Orthogonal matrix
v1=c(1,-2,4)
v2=c(2,5,2)
V <- t(v1) %*% v2
V # 0 - orthogonal else its not

# distance
# Creating the vector objects
a = c(3, 1, 2)
b = c(4, 0, 3)
c = c(5, 4, 3)

# Using the rbind() function to row bind the vectors into a single matrix 
mymatrix <- rbind(a, b, c)
mymatrix
# Implementing the dist() function to calculate the manhattan distance between the rows of the matrix
dist(mymatrix, method = "manhattan", diag=TRUE, upper=TRUE)


# just for knowledge not so important fr this week
#orthonormal vectors
# Gram-Schmidt process
u1 <- v1
u2 <- v2 - (sum(u1 * v2) / sum(u1 * u1)) * u1

# Normalize vectors
u1 <- u1 / sqrt(sum(u1^2))
u2 <- u2 / sqrt(sum(u2^2))


# Create orthogonal matrix
Q <- cbind(u1, u2)

# Check if Q is orthogonal (optional)
is_orthogonal <- all(abs(t(Q) %*% Q - diag(ncol(Q))) < 1e-10)
cat("Is Q orthogonal:", is_orthogonal, "\n")
print(Q)

#Eigen values and Eigen Vectors
A <- matrix(c(13, -4, 2, -4, 11, -2, 2, -2, 8), 3, 3, byrow=TRUE)
A

ev <- eigen(A)
# extract components
(values <- ev$values) # eigenvalues
#eigen vectors
(vectors <- ev$vectors)

#properties of eigen values and eigen vectors
# 1. Orthogonality (A'A=I)
crossprod(vectors)
zapsmall(crossprod(vectors))
# 2. trace(V) = sum of eigen values
tr(A) #trace of A
sum(values)
# 3. sum of squares of A = sum of squares of eigenvalues
sum(A^2)
sum(values^2)
# 4. determinant = product of eigenvalues
det(A)
prod(values)
# 5. rank = number of non-zero eigenvalues
R(A)
sum(values!=0)
# 6. eigenvalues of A^−1= 1/eigenvalues of A
