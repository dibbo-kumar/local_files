import numpy as np

# Step 1: Given data
courses = {'Alice':[85,90,78],'Bob':[70,75,80],'Charlie':[92,88,95]}

# Step 2 & 3: Compute average scores and store in a new dictionary
averages = {student: np.mean(scores) for student, scores in courses.items()}
print("Averages:", averages)

# Step 4: List of students with average > 85
top_students = [student for student, avg in averages.items() if avg > 85]
print("Students with average > 85:", top_students)

# Step 5: Top student and their score as a tuple
top_student = max(averages.items(), key=lambda x: x[1])
print("Top student:", top_student)