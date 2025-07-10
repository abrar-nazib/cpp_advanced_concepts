#include<iostream>
#include<chrono>
#include<thread>

void run(int count){
    while(count-- > 0){
        std::cout << "Hii" << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

int main(){
    std::thread t1(run, 10);
    std::cout << "Inside main" << std::endl;
    t1.join();
    std::cout << "End of Main" << std::endl;
    return 0;
}