# load the dataset
data(iris)
head(iris)

summary(iris)
# split the dataset into training and testing
set.seed(123)
trainIndex <- createDataPartition(iris$Species, p = .8, 
                                  list = FALSE, 
                                  times = 1)
trainData <- iris[ trainIndex,]
testData  <- iris[-trainIndex,]

# knn
knnModel <- knn(train = trainData[,1:4], 
                test = testData[,1:4], 
                cl = trainData$Species, 
                k = 3)

# confusion matrix
confusionMatrix(knnModel, testData$Species)
