#include <iostream>
#include <string>

void f1(int k) {
    std::string err = "F1 ERROR";
    if (!k) {
        throw err;
        std::cout << "f1: error!" << std::endl;
    } else {
        std::cout << "f1: success!" << std::endl;
    }
}

void f2(int j) {
    try {
        f1(j);
    } catch (std::string e) {
        std::cout << "exception caught in f2" << std::endl;
        throw e;
    }
    std::cout << "f2: success!" << std::endl;
}

void f3(int i) {
    f2(i);
    std::cout << "f3: success!" << std::endl;
}

int main() {
    std::cout << "Try {f3(1);}" << std::endl;
    try {
        f3(1);
    } catch (std::string e) {
        std::cout << "Caught exception: " <<  e << std::endl;
    }
    std::cout << std::endl << "Try {f3(0)};" << std::endl;
    try {
        f3(0);
    } catch (std::string e) {
        std::cout << "Caught exception: " <<  e << std::endl;
    }
}