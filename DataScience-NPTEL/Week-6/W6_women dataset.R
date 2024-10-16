# Import the data from environmental/History/Connection panel

# Check the dataset with head function
head(women)

#calculating summary of the data
print(summary(women))

#Plotting the dataset
plot(women, main='Height Vs Weight', xlab='Height', ylab='Weight')

# Building the linear model using lm function
model<-lm(weight~height,women)
print(model)

#plotting the regression model (Y-Intercept + Slope)
abline(model)