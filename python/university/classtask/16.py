import numpy as np

data = [('A',[10,20,30]), ('B',[5,15,25]), ('C',[12,18,24])]
data_dict = dict(data)

# Compute mean directly on lists
mean_dict = {key: np.mean(value) for key, value in data_dict.items()}

print(mean_dict)