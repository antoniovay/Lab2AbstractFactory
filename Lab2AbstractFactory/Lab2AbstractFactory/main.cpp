#include <iostream>

#include "generateProgram.hpp"

int main() {
    std::cout << "=============== C++ ===============\n\n";
    CPPFactory cpp_factory;
    std::cout << generateProgram(&cpp_factory) << std::endl;
    
    std::cout << "=============== Java ==============\n\n";
    JavaFactory java_factory;
    std::cout << generateProgram(&java_factory) << std::endl;
    
    std::cout << "=============== C# ================\n\n";
    CSHFactory csh_factory;
    std::cout << generateProgram(&csh_factory) << std::endl;
    
    return 0;
}

