# NPTEL Problem Solving Session - Week 3
# TA: Saladi Pravallika
# Course: Data Science for Engineers

# Topics: Random Variables, probability distributions, expected value, variance, covariance, correlation, conditional probability, Bayes' theorem
# Hypothesis Testing, Central Tendency, single sided and two sided tests, p-value

# Problem 1: A box contains 5 red balls and 3 green balls. Two balls are drawn at random. Find the probability that both balls are green.
# Solution: Let A be the event that the first ball is green and B be the event that the second ball is green. We need to find P(A and B).
# P(A and B) = P(A) * P(B|A) = (3/8) * (2/7) = 3/28

# In R we will try Problem 1
# Let's define the probability of drawing a green ball
P_A = 3/8
# Let's define the probability of drawing a green ball given that the first ball is green
P_B_given_A = 2/7
# Let's find the probability of drawing two green balls
P_A_and_B = P_A * P_B_given_A
P_A_and_B

# Probability Distribution (visualizing the distribution)
# Discrete Random Variable: Number of Green Balls Drawn
# Let's plot the probability distribution of the number of green balls drawn
# Let's define the number of green balls drawn
green_balls = c(0, 1, 2)
# Let's define the probability of drawing 0, 1, 2 green balls
prob_green_balls = c(5/28, 30/56, 3/28)
# Let's plot the probability distribution
barplot(prob_green_balls, names.arg = green_balls, xlab = "Number of Green Balls", ylab = "Probability", main = "Probability Distribution of Number of Green Balls Drawn")

# Continuous Random Variable: Height of Students
# Let's plot the probability distribution of the height of students
# Let's define the height of students
height = seq(140, 200, by = 1)
# Let's define the probability density function of the height of students
pdf_height = dnorm(height, mean = 170, sd = 10)
# Let's plot the probability distribution
plot(height, pdf_height, type = "l", xlab = "Height", ylab = "Probability Density", main = "Probability Distribution of Height of Students")

# Binomial Mass Function
# Let's plot the binomial mass function
# Let's define the number of trials
n = 5
# Let's define the probability of success
p = 0.5
# Let's define the number of successes
k = 0:5
# Let's find the binomial mass function
binomial_mass = dbinom(k, size = n, prob = p) 
binomial_mass
# Let's plot the binomial mass function
barplot(binomial_mass, names.arg = k, xlab = "Number of Successes", ylab = "Probability", main = "Binomial Mass Function")

# Gaussian or normal distribution
# Let's plot the Gaussian distribution
# Let's define the mean and standard deviation
mean = 0
sd = 1
# Let's define the range of x values
x = seq(-15, 15, by = 0.01)
# Let's find the Gaussian distribution
gaussian = dnorm(x, mean = mean, sd = sd)
gaussian
# Let's plot the Gaussian distribution
plot(x, gaussian, type = "l", xlab = "x", ylab = "Probability Density", main = "Gaussian Distribution")

# Chi-Square Distribution
# Let's plot the Chi-Square distribution
# Let's define the degrees of freedom
df = 15
# Let's define the range of x values
x = seq(0, 20, by = 0.01)
# Let's find the Chi-Square distribution
chi_square = dchisq(x, df = df)
# Let's plot the Chi-Square distribution
plot(x, chi_square, type = "l", xlab = "x", ylab = "Probability Density", main = "Chi-Square Distribution")

# Expected Value and Variance (Moments of PDF)
# Let's find the expected value and variance of the height of students
# Let's define the mean and standard deviation
mean = mean(height)
mean
variance = var(height)
variance

# Central Tendency
# Let's find the mode of the height of students
mode = height[which.max(pdf_height)].
mode
# Let's find the median of the height of students
median = median(height)
median
median

# Graphical Representations
# 1. Histogram
# Let's plot the histogram of the height of students
hist(height, breaks = 20, xlab = "Height", ylab = "Frequency", main = "Histogram of Height of Students")

# 2. Boxplot
# Let's plot the boxplot of the height of students
boxplot(height, xlab = "Height", ylab = "Frequency", main = "Boxplot of Height of Students")

# 3. Probability plot
# Let's plot the probability plot of the height of students
qqnorm(height)

# 4. Scatter plot (1 RV against another RV)
# Let's plot the scatter plot of the height of students
height_1 = rnorm(100, mean = 170, sd = 10)
height_2 = rnorm(100, mean = 170, sd = 10)
plot(height_1, height_2, xlab = "Height 1", ylab = "Height 2", main = "Scatter Plot of Height of Students")

# Hypothesis Testing
# Let's perform hypothesis testing on the height of students
# Let's define the null hypothesis
null_hypothesis = "The mean height of students is 170 cm"
# Let's define the alternative hypothesis
alternative_hypothesis = "The mean height of students is not 170 cm"
# Let's perform a two-sided t-test
t_test = t.test(height, mu = 170)
t_test
# Observe P values by changing mu

?t.test


