import numpy as np

students = [('Alice',85), ('Bob',72), ('Charlie',90), ('David',65), ('Eva',88)]

# Convert to dictionary
student_dict = dict(students)

# List of students scoring above 80
top_students = [name for name, score in student_dict.items() if score > 80]

# Calculate average score using NumPy
average_score = np.mean(list(student_dict.values()))

print("Student dictionary:", student_dict)
print("Students scoring above 80:", top_students)
print("Average score:", average_score)