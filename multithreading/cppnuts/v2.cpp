#include<iostream>
#include<thread>

// void fun(int x){
//     std::cout << x << " was created\n";
//     for(int i = 0; i < 10000; i++){
//         continue;
//     }
//     std::cout << x << " was terminated\n";
// }

// int main(){
//     std::thread t1(fun, 1);
//     std::thread t2(fun, 2);
//     std::thread t3(fun, 3);
//     std::thread t4(fun, 4);
    
//     t1.join();
//     t2.join();
//     t3.join();
//     t4.join();
    
//     return 0;
// }

// int main(){
//     auto fun = [](int x){
//         while(x-- > 0){
//             std::cout << x << std::endl;
//         }
//     };

//     std::thread t(fun, 10);
//     t.join();
//     return 0;
// }

// class Base{
// public:
//     void operator () (int x){
//         while(x-- > 0){
//             std::cout << x << std::endl;
//         }
//     }
// };

// int main(){
//     std::thread t((Base()), 10);
//     t.join();
//     return 0;
// }

// 4. Non-static member function

// class Base{
//     public:
//     void run(int x){
//         int i = x;
//         while(i-- > 0){
//             std::cout << i << std::endl; 
//         }
//     }
// };

// int main(){
//     Base b;
//     std::thread t(&Base::run, &b, 10); // function, object
//     t.join();
//     return 0;
// }

// Static member functions
class Base
{
public:
    static void run(int x){
        while(x-- > 0){
            std::cout << x << std::endl;
        }
    }
};

int main(){
    std::thread t(&Base::run, 10);
    t.join();
    return 0;
}