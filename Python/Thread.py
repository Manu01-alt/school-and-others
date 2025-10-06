import threading
import time

print("USANDO I THREAD")

def thread_function(Numero, Secondi):
        print(f"Processo {Numero} - durata: {Secondi} secondi")
        time.sleep(Secondi)
        print("\n")
        print(f"Processo {Numero} - Fine")
    

inizio = time.time()
thread = threading.Thread(target = thread_function, args=(1, 2))
thread2 = threading.Thread(target = thread_function, args=(2, 2))
thread3 = threading.Thread(target = thread_function, args=(3, 2))

thread.start()
thread2.start()
thread3.start()

thread.join() 
thread2.join()
thread3.join()
print("Fine programma")

fine = time.time()
print(f"\nTempo totale: {fine - inizio:.2f} secondi\n")

#------------------------------------------------------------
print("NON USANDO I THREAD")

inizio = time.time()

thread_function(1, 2)
thread_function(2, 2)
thread_function(3, 2)
print("Fine programma")

fine = time.time()
print(f"Tempo totale: {fine - inizio:.2f} secondi")