#include <chrono>
#include <iostream>
#include <thread>

void run(int count) {
  while (count-- > 0) {
    std::cout << "Hii" << std::endl;
  }
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::cout << "Thread finished" << std::endl;
}

int main() {
  std::thread t1(run, 10);
  for (int i = 0; i < 100000; i++) {
    continue;
  }
  std::cout << "Inside main" << std::endl;
  t1.detach();
  std::cout << "End of Main" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(5));
  return 0;
}