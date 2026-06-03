#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "iostream"
#include "ctime"
#include "cstdlib"




Base* generate(void){
    switch (std::rand() % 3)
    {
    case 0:
		std::cout << "Generate created A" << std::endl;
        return new A();
        break;
    case 1:
		std::cout << "Generate created B" << std::endl;
        return new B();
        break;
    default:
		std::cout << "Generate created C" << std::endl;
        return new C();
        break;
    }
}

// what derived type is behind base pointer
// param is pointer
// if fails, returns nullptr
// dynamic cast checks at the runtime
void identify(Base* p){
    if(dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unexpected type" << std::endl;
}

// what derived type is behind base ref
// param is ref
// if fails, throws
// ref cannot be null
//
void identify(Base& p){
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch(...){
    }
    try{
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch(...){
    }
     try{
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch(...){
    }
    std::cout << "Unexpected type" << std::endl;
}



int main(){
std::srand(std::time(0));

Base* obj = generate();
std::cout << std::endl;

std::cout << "Pointer check: ";
identify(obj);
std::cout << std::endl;

std::cout << "Reference check: ";
identify(*obj);
std::cout << std::endl;

delete obj;

}