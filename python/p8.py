import sys
import struct
max_int = sys.maxsize
min_int = -sys.maxsize-1
#unsigned_int_max = struct.unpack('I', struct.unpack('I', -1))[0]
unsigned_int_min = 0
print("Range of types int and unsigned int\n")
print("Type                   Minimum             Maximum\n")
print(f" int          {min_int}       {max_int}\n")
print(f" unsigned-int           {unsigned_int_min}               {max_int*2+1}\n")
