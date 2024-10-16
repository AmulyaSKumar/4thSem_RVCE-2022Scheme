# Logistic Regression
data <- read.csv('seeds_dataset.csv')
head(data)
tail(data)

#Missing values
is.na(data)
sum(is.na(data))

#dimensions of data
dim(data)

#another way to remove missing values
data <- na.omit(data)


# structure of data
str(data)

#summary of data
summary(data)

#splitting the data using a function from dplyr package
library(caret)

set.seed(46)

index<- createDataPartition(data$seedType,p=0.8,list=FALSE)
train<-data[index,]
test<-data[-index,]

# length of train and test data
nrow(train)
nrow(test)

library(tidyverse) # use for multi-classification
#fit the model
model<-nnet::multinom(seedType~.,data=train)

#model summary
summary(model)

#predicting the value of test dataset
pred<-predict(model,newdata=test,'class')
pred

#Building classification table
cm<-table(test$seedType,pred)
print(cm)

#calculating accuracy- sum of diagonal elements divided by total observations
(sum(diag(cm))/sum(cm)*100)

#confusion matrix
confusionMatrix(cm)
