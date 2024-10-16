# Set seed for reproducibility
set.seed(123)

# Generate 100 points for the independent variable (Temperature)
x <- seq(1, 100, by = 1)

# Generate corresponding dependent variable values (Pressure) with random noise
y <- 3 * x + rnorm(100, mean = 0, sd = 10)

# Introduce outliers by modifying 10 randomly selected points
num_outliers <- 10
outlier_indices <- sample(1:100, num_outliers, replace = FALSE)
y[outlier_indices] <- y[outlier_indices] + rnorm(num_outliers, mean = 500, sd = 20)

# Create a data frame with x and y
data <- data.frame(x, y)

# Plot the data
plot(data$x, data$y, main = "Experiment Data with Outliers", xlab = "Temp", ylab = "Pressure")

#_____________________________________#
# Fit a linear regression model
lm_model1 <- lm(y ~ x, data = data)

# Print the summary of the model
summary(lm_model1)

# Plot the data with the regression line
plot(data$x, data$y, main = "Linear Regression with Outliers", xlab = "Temp", ylab = "Pressure")
abline(lm_model1, col = "red")

#_____________________________________#
# Remove outliers from the dataset
clean_data <- data[-outlier_indices, ]

# Fit a linear model with the cleaned data
lm_model2 <- lm(y ~ x, data = clean_data)

# Summary of the linear model
summary(lm_model)

# Plot the cleaned data and the linear model
plot(clean_data$x, clean_data$y, main = "Experiment Data without Outliers", xlab = "Temp", ylab = "Pressure")
abline(lm_model1, col = "red")
abline(lm_model2, col = "green")

