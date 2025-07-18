#include <iostream>
#include <mutex>
#include <thread>

std::mutex m1;
int buffer = 0;

void task_with_usual_syntax(const char *threadNumber, int loopFor) {
  m1.lock();
  for (int i = 0; i < loopFor; i++) {
    buffer++;
    std::cout << threadNumber << buffer << std::endl;
  }
  m1.unlock();
}

void task_with_lock_guard(const char *threadNumber, int loopFor) {
  std::lock_guard<std::mutex> lock(m1);
  for (int i = 0; i < loopFor; i++) {
    buffer++;
    std::cout << threadNumber << buffer << std::endl;
  }
}

int main() {
  std::thread t1(task_with_lock_guard, "T0", 10);
  std::thread t2(task_with_lock_guard, "T2", 10);
  t1.join();
  t2.join();
  std::cout << "Buffer: " << buffer << std::endl;
  return 0;
}