#include "Array.hpp"
#include <cstring>

Array::Array(size_t count) : size(count) {
    data = new Character*[size];
}

Array::Array(const Array& rhs) {
    //TODO
}

Array& Array::operator=(const Array& rhs) {
    //TODO
}

void Array::add(Character* val) {
    if (current_count >= size) throw std::runtime_error("Can't add more characters!");
    data[current_count++] = val->clone();
}

void Array::remove(const char* name) {
    
    if(!name) throw std::invalid_argument("Invalid name in remove passed!");

    size_t index = -1;

    for (size_t i = 0; i < size; i++) {
        if (strcmp(name, data[i]->get_name()) == 0) {
            index = i;
        }
    }
 
    delete data[index];
    for(size_t i = index; i < size-1; ++i)
        data[i] = data[i+1];

    --size;
}

Array::~Array() {
    for (size_t i = 0; i < size; i++) {
        delete data[i];
    }
    delete[] data;
}