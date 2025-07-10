import threading
import time

OddSum = 0
EvenSum = 0

start = 0
end = 190_000_000

def find_even(start, end):
    global EvenSum
    for i in range(start, end + 1):
        if i % 2 == 0:
            EvenSum += i

def find_odd(start, end):
    global OddSum
    for i in range(start, end + 1):
        if i % 2 == 1:
            OddSum += i

# --- Threaded Execution ---
start_time = time.time()

t1 = threading.Thread(target=find_even, args=(start, end))
t2 = threading.Thread(target=find_odd, args=(start, end))

t1.start()
t2.start()

t1.join()
t2.join()

threaded_time = time.time() - start_time

print(f"Threaded OddSum: {OddSum}")
print(f"Threaded EvenSum: {EvenSum}")
print(f"Threaded Time: {threaded_time:.2f} seconds")

# --- Reset and Non-threaded Execution ---
OddSum = 0
EvenSum = 0

start_time = time.time()
find_even(start, end)
find_odd(start, end)
non_threaded_time = time.time() - start_time

print(f"\nNon-threaded OddSum: {OddSum}")
print(f"Non-threaded EvenSum: {EvenSum}")
print(f"Non-threaded Time: {non_threaded_time:.2f} seconds")
