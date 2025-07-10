#include <iostream>
#include<memory>


int main(){
    std::shared_ptr<int> p1 = std::make_shared<int>(4);
    std::cout << "p1 value: " << *p1 << "\n";

    std::shared_ptr<int> p2 = p1; // Both point to the same int

    std::cout << "p1 use_count: " << p1.use_count() << "\n";

    p1.reset(); // p1 gives up ownership
    std::cout << "p2 still holds: " << *p2 << std::endl; // Still valid

    return 0;
}