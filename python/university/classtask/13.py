import numpy as np

inventory = {'apple':[10,1.5], 'banana':[25,0.8], 'orange':[15,1.2], 'mango':[8,2.0]}

# Calculate total value for each item
total_value = {item: qty * price for item, (qty, price) in inventory.items()}

# Compute average item value using NumPy
average_value = np.mean(list(total_value.values()))

print("Total value per item:", total_value)
print("Average item value:", average_value)