tuple = ("cpp", "python", "java", "c#", "ruby")
print(tuple[0])
print(tuple[4])
# if tuple.count("python") > 0:
#     print("python is in the tuple")
# else:
#     print("python is not in the tuple")
if "python" in tuple:
    print("python is in the tuple")
else:
    print("python is not in the tuple")

list1 = list(tuple)
print(type(list1))
list1.append("Rust")
print(list1)