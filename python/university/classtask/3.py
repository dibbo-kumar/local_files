scores =[55,78,62,49,85,91,73]
new = [score for score in scores if score>=70]
print("new list is" ,new)

print("average is", sum(scores)/len(scores))
print("max is", max(scores))
print("min is", min(scores))