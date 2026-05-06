marks ={
    "maths": 90,
    "physics": 85,  
    "chemistry": 92,
    "english": 88,
    }
print("subjects are ", marks.keys())
print("marks are ", marks.values())
print(max(marks.values()))
print("average mark is : ", sum(marks.values())/len(marks))
max_value = max(marks, key = marks.get)
print("subject with highest mark is : ", max_value)
