# Set the random seed for reproducibility
set.seed(123)

# Load the required libraries
library(ggplot2)
library(MASS)

# Generate random data with two circular clusters
n <- 150  # Total number of data points
centers <- 3  # Number of clusters
radius <- 0.6  # Radius of clusters

# Create random cluster centers in a circular pattern
theta <- seq(0, 2 * pi, length.out = centers + 1)[-1]  # Angle in radians
cluster_centers <- cbind(cos(theta) * radius, sin(theta) * radius)

# Generate data points around circular cluster centers
data_points <- matrix(0, n, 2)
for (i in 1:centers) {
  start <- 1 + (i - 1) * (n / centers)
  end <- i * (n / centers)
  data_points[start:end, ] <- mvrnorm(end - start + 1, mu = cluster_centers[i, ], Sigma = diag(2) * 0.01)
}

# plot the data points before clustering
ggplot(data = as.data.frame(data_points), aes(x = data_points[, 1], y = data_points[, 2])) +
  geom_point(size = 3) +
  labs(title = "Data Points (Three Circular Clusters)", x = "X-axis", y = "Y-axis")

# Perform K-means clustering
kmeans_result <- kmeans(data_points,3,15)
#?kmeans
print(kmeans_result)

# Extract cluster assignments
cluster_assignments <- kmeans_result$cluster

# Create a data frame for plotting
df <- data.frame(x = data_points[, 1], y = data_points[, 2], Cluster = as.factor(cluster_assignments))

# Plot the data points with cluster assignments
ggplot(df, aes(x, y, color = Cluster)) +
  geom_point(size = 3) +
  labs(title = "K-means Clustering (Three Circular Clusters)", x = "X-axis", y = "Y-axis") +
  scale_color_manual(values = c("red", "blue", "green"))  # Customize cluster colors as needed

