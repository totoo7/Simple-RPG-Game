#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Character.hpp"

class Array {
    public:
        Array(size_t count = 16);
        Array(const Array& rhs);
        Array& operator=(const Array& rhs);
        Character* const operator[](size_t index) const { return data[index]; };
        void add(Character* val);
        void remove(const char* name);
        size_t get_size() const { return size; };
        ~Array();
    private:
        Character** data;
        size_t size;
        size_t current_count = 0;
};

#endif