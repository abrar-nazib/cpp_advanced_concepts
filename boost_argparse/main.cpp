#include<iostream>
#include<string>
#include<boost/program_options.hpp>

namespace bpo = boost::program_options;

int main(int argc, char* argv[]){
    std::string name;
    int age = 0;
    bool debug = false;

    bpo::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "Show help message")
        ("name", bpo::value<std::string>(&name)->default_value("Abrar"), "User's name")
        ("age", bpo::value<int>(&age)->default_value(20), "User's age")
        ("debug", bpo::bool_switch(&debug), "Enable debug mode");

    bpo::variables_map vm;
    bpo::store(bpo::parse_command_line(argc, argv, desc), vm);
    bpo::notify(vm);

    if(vm.count("help")){
        std::cout << desc << "\n";
        return 0;
    }

    std::cout << "Name: " << name << "\n";
    std::cout << "Age: "   << age << "\n";
    std::cout << "Debug: " << (debug? "ON" : "OFF") << "\n";

    return 0;
}