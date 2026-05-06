student ={
    "name": "dibbo",
    "age": 20,
    "dept" : "CSE",
    "cgpa" : 3.5
}
print(student.keys())
print(student.values())
student.update({"cgpa": 3.8})
print(student)
student["university"] = "uiu"
print(student)
student["age"] = 24
print(student)