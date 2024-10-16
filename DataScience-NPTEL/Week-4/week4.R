# NPTEL Problem Solving Session - Week 4
# TA: Saladi Pravallika
# Course: Data Science for Engineers

# Calculate the gradients of a given function using deriv() and D() function
# Define the uni-variate function
f = expression(x^2 + 5*x + 1)

# 1st Derivative
cat("1 st derivative using deriv() function:\n")
print(deriv(f, "x"))

cat("\n 1st derivative using D() function:\n")
f_prime=D(f, 'x')
print(f_prime)

# 2nd Derivative
cat("\n2nd derivative using D() function:\n")
print(D(f_prime, 'x'))
#____________________________________________________________________#

# Define the multivariate function
f = expression(x^2 + 5*x*y -y^2)

# Derivative wrt x
cat("\n1st derivative using D() function wrt x:\n")
print(D(f, 'x'))

# Derivative wrt y
cat("\n1st derivative using D() function wrt y:\n")
print(D(f, 'y'))
#____________________________________________________________________#

#Calculate hessian matrix

# Install and load the numDeriv package
install.packages("numDeriv")
library(numDeriv)

# Define the function
f <- function(x) x[1]^2 + 4 * x[2]^2 + x[1] * x[2]

# Calculate the Hessian matrix using the hessian() function
hessian_matrix <- hessian(f, x = c(1, 2))

# Print the Hessian matrix
print(hessian_matrix)
#____________________________________________________________________#
# Gradient Descent Algorithm with Plotting
gradient_descent_plot <- function(gradient_func, learning_rate, initial_x, num_steps) {
  x <- initial_x
  trajectory <- numeric(num_steps + 1)
  
  for (i in 1:num_steps) {
    gradient <- gradient_func(x)
    x <- x - learning_rate * gradient
    trajectory[i + 1] <- x
  }
  
  return(trajectory)
}

# Quadratic function: f(x) = x^2
quadratic_function <- function(x) {
  return(2 * x)  # Gradient of f(x) = x^2
}

# Parameters
learning_rate <- 0.01
initial_x <- 100
num_steps <- 500

# Run the gradient descent algorithm and get the trajectory
trajectory <- gradient_descent_plot(quadratic_function, learning_rate, initial_x, num_steps)

# Plotting the trajectory
library(ggplot2)

df <- data.frame(step = 0:num_steps, x = trajectory)
ggplot(df, aes(x = step, y = x)) +
  geom_line() +
  geom_point(color = "red") +
  labs(x = "Step", y = "Value of x", title = "Gradient Descent Trajectory")

