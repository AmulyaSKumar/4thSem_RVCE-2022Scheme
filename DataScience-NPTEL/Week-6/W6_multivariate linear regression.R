# Set seed for reproducibility
set.seed(123)

# Number of observations
n <- 100

# Generate independent variables
x1 <- rnorm(n, mean = 10, sd = 2)  # Variable 1
x2 <- rnorm(n, mean = 5, sd = 1)   # Variable 2

# Generate dependent variable
# Let's assume the true relationship is: y = 2*x1 + 3*x2 + error
error <- rnorm(n, mean = 0, sd = 2)
y <- 2*x1 + 3*x2 + error

# Combine variables into a data frame
data <- data.frame(x1, x2, y)

# Display first few rows of the dataset
head(data)

# Set up the plotting environment with two subplots
par(mfrow = c(1, 2))

# Plotting Variable 1 (x1)
plot(data$x1, data$y, main = "Scatter plot of x1 vs y", xlab = "x1", ylab = "y")

# Plotting Variable 2 (x2)
plot(data$x2, data$y, main = "Scatter plot of x2 vs y", xlab = "x2", ylab = "y")

# Reset the plotting environment to default
par(mfrow = c(1, 1))

# Fit a multivariate linear regression model
model <- lm(y ~ x1 + x2, data = data)

# Summarize the model
summary(model)

# Install and load the rgl package
install.packages("rgl")
library(rgl)

# Fit a multivariate linear regression model
model <- lm(y ~ x1 + x2, data = data)

# Create a 3D scatter plot with data points
plot3d(data$x1, data$x2, data$y, col = "red", type = "s", size = 2, main = "3D Scatter Plot with Regression Plane")

# install.packages("scatterplot3d")
# library(scatterplot3d)
# s3d <- scatterplot3d(data$x1, data$x2, data$y, pch = 16, highlight.3d = TRUE, type = "h", main = "3D Regression Plane")
# s3d$plane3d(model)

# Extract coefficients of the plane from the model
coef <- coef(model)

# Define the plane equation coefficients
a <- coef[2]  # coefficient of x1
b <- coef[3]  # coefficient of x2
c <- coef[1]  # intercept

# Create the regression plane
rgl::planes3d(a, b, -1, c, col = "blue", alpha = 0.5)

