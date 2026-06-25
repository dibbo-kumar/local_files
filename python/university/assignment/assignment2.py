import csv
import random
import math

# =====================================================
# FUNCTION TO LOAD CSV DATA
# =====================================================

def load_csv(filenamer):
    dataset = []

    with open(filenamer, 'r') as file:
        csv_reader = csv.reader(file)

        for row in csv_reader:

            if len(row) == 0:
                continue

            dataset.append(row)

    return dataset


# =====================================================
# CONVERT STRING FEATURES TO FLOAT
# =====================================================

def convert_features_to_float(dataset):

    for row in dataset:

        for i in range(len(row) - 1):
            row[i] = float(row[i])

    return dataset


# =====================================================
# SPLIT DATASET
# 70% TRAIN
# 15% VALIDATION
# 15% TEST
# =====================================================

def split_dataset(dataset):

    Train_set = []
    Val_set = []
    Test_set = []

    for sample in dataset:

        R = random.random()

        if R >= 0 and R <= 0.7:
            Train_set.append(sample)

        elif R > 0.7 and R <= 0.85:
            Val_set.append(sample)

        else:
            Test_set.append(sample)

    return Train_set, Val_set, Test_set


# =====================================================
# EUCLIDEAN DISTANCE
# =====================================================

def euclidean_distance(row1, row2):

    distance = 0

    for i in range(len(row1) - 1):

        distance += (row1[i] - row2[i]) ** 2

    return math.sqrt(distance)


# =====================================================
# KNN CLASSIFICATION
# =====================================================

def knn_classification(train_set, validation_set, K):

    correct = 0

    for V in validation_set:

        L = []

        for T in train_set:

            distance = euclidean_distance(V, T)

            L.append((T, distance))

        # sort by distance
        L.sort(key=lambda x: x[1])

        # take first K neighbors
        neighbors = L[:K]

        class_count = {}

        for neighbor in neighbors:

            label = neighbor[0][-1]

            if label not in class_count:
                class_count[label] = 1
            else:
                class_count[label] += 1

        # majority class
        predicted_class = max(class_count, key=class_count.get)

        actual_class = V[-1]

        if predicted_class == actual_class:
            correct += 1

    accuracy = (correct / len(validation_set)) * 100

    return accuracy


# =====================================================
# KNN REGRESSION
# =====================================================

def knn_regression(train_set, validation_set, K):

    error = 0

    for V in validation_set:

        L = []

        for T in train_set:

            distance = euclidean_distance(V, T)

            L.append((T, distance))

        # sort by distance
        L.sort(key=lambda x: x[1])

        # take first K neighbors
        neighbors = L[:K]

        total_output = 0

        for neighbor in neighbors:

            output = float(neighbor[0][-1])

            total_output += output

        predicted_output = total_output / K

        true_output = float(V[-1])

        error += (true_output - predicted_output) ** 2

    mse = error / len(validation_set)

    return mse


# =====================================================
# IRIS DATASET (CLASSIFICATION)
# =====================================================

print("============== KNN CLASSIFICATION ==============")

iris_data = load_csv(r"c:\Users\pc\Desktop\program\python\university\assignment\iris.csv")

# remove header
iris_data = iris_data[1:]

iris_data = convert_features_to_float(iris_data)

Train_set, Val_set, Test_set = split_dataset(iris_data)

K_values = [1, 3, 5, 10, 15]

best_k = 0
best_accuracy = 0

print("\nK\tValidation Accuracy")

for K in K_values:

    accuracy = knn_classification(Train_set, Val_set, K)

    print(K, "\t", round(accuracy, 2), "%")

    if accuracy > best_accuracy:
        best_accuracy = accuracy
        best_k = K

print("\nBest K =", best_k)

# TEST ACCURACY

test_accuracy = knn_classification(Train_set, Test_set, best_k)

print("Test Accuracy =", round(test_accuracy, 2), "%")


# =====================================================
# DIABETES DATASET (REGRESSION)
# =====================================================

print("\n============== KNN REGRESSION ==============")

diabetes_data = load_csv(r"c:\Users\pc\Desktop\program\python\university\assignment\diabetes.csv")

# remove header
diabetes_data = diabetes_data[1:]

diabetes_data = convert_features_to_float(diabetes_data)

Train_set, Val_set, Test_set = split_dataset(diabetes_data)

best_k = 0
minimum_mse = 999999999

print("\nK\tValidation MSE")

for K in K_values:

    mse = knn_regression(Train_set, Val_set, K)

    print(K, "\t", round(mse, 2))

    if mse < minimum_mse:
        minimum_mse = mse
        best_k = K

print("\nBest K =", best_k)

# TEST MSE

test_mse = knn_regression(Train_set, Test_set, best_k)

print("Test MSE =", round(test_mse, 2))