import threading
import random
import time



while (True):
    num = random.randint(0,1)
    if num == 0:
        print("Voglio esplodere...")
    else:
        print("Non voglio esplodere...")
    time.sleep(1) 