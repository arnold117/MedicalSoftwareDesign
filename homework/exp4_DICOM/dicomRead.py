import pydicom
import matplotlib.pyplot as plt

ds = pydicom.dcmread('./11.dcm')
plt.figure(figsize=(10, 10))
plt.imshow(ds.pixel_array, cmap=plt.cm.bone)
plt.savefig('./output.png', dpi=600)

print(ds.PatientName)