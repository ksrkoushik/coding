import struct
print(f"memory space for int64: {struct.calcsize('q')}\n")
print(f"memory space for float64: {struct.calcsize('d')}\n")
print(f"memory space for character: {struct.calcsize('c')}\n")
