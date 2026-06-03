#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(){
    Data building;

    building.street_name = "maauunintie";
    building.apartment_num = 20;

    Data* origin = &building;

    uintptr_t raw = Serializer::serialize(origin);

    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original: " << origin << std::endl;
    std::cout << "Restored: " << restored << std::endl;

    std::cout << restored->street_name << std::endl;
    std::cout << restored->apartment_num << std::endl;


}