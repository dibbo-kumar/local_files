import numpy as np
arr = np.array([5,12,7,20,3,15,8])
greater = arr[arr > 10]
print(greater)
arr[arr<10] = 0
print(arr)