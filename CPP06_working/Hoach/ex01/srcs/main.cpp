#include <iostream>
#include "Serializer.hpp"

int main()
{

    std::cout << "\n ------------------Testing ex01 --------------------- \n" << std::endl;
    // Create a Data object
    Data data;
    data.id = 42;
    data.name = "Test_Data";

    // Print the original Data object
    std::cout << "Original Data address: " << &data << std::endl;
    std::cout << "Original Data ID: " << data.id << std::endl;
    std::cout << "Original Data Name: " << data.name << std::endl;

    // Serialize the Data object's address
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;

    // Deserialize the raw value back to a Data pointer
    Data* deserializedData = Serializer::deserialize(raw);

    // Print the deserialized Data object
    std::cout << "Deserialized Data address: " << deserializedData << std::endl;
    std::cout << "Deserialized Data ID: " << deserializedData->id << std::endl;
    std::cout << "Deserialized Data Name: " << deserializedData->name << std::endl;

    // Verify that the deserialized pointer matches the original
    if (deserializedData == &data) 
    {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    } 
    else
    {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }
    std::cout << "\n ------------------Done ex01 --------------------- \n" << std::endl;
    return 0;
}