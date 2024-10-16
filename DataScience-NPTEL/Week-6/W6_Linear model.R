# Data
X <- c(1, 2, 3, 4, 5, 6)
Y <- c(3, 5, 7, 8, 10, 12)

# preparing the dataset with dataframe
df <- data.frame(X, Y)

# Using linear fitting model function (lm) to fit model
model <- lm(Y ~ X, data = df)

#Printing the model
summary(model)

#plot
plot(X, Y, col = "blue", pch = 19, main = "Linear Regression")
abline(model, col = "red")



