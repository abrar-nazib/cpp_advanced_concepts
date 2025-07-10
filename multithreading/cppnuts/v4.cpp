#include <iostream>
#include <mutex>
#include <thread>

int myAmount = 0;

std::mutex m;
void addMoney() {
  for (int i = 0; i < 1000000; i++) {
    m.lock();
    ++myAmount;
    m.unlock();
  }
}

int main() {
  std::thread t1(addMoney);
  std::thread t2(addMoney);

  t1.join();
  t2.join();

  std::cout << myAmount << std::endl;
  return 0;
}