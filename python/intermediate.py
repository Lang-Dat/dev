from multiprocessing import Process
import os
from time import sleep

def nothing():
    for i in range(100):
        # print(i, end=" ")
        i * i
        # sleep(0.5)

processs = []
num_process = os.cpu_count() # 4

for i in range(num_process):
    p = Process(target=nothing)
    processs.append(p)
    p.start



print("end main")



