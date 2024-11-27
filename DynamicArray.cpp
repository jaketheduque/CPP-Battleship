#ifndef DYNAMICARRAY_CPP
#define DYNAMICARRAY_CPP

#include <iostream>

template <typename T>
class DynamicArray {
    T* content;
    int size;
    int maxSize;

    public:
        DynamicArray() {
            size = 0;
            maxSize = 5;
            content = new T[5];
        };

        DynamicArray(T* content, int size) {
            size = size;
            maxSize = size;
            this->content = new T[size];

            for (int i = 0 ; i < size ; i++) {
                this->content[size] = content[size];
            }
        };
        
        DynamicArray(const DynamicArray<T>& rhs) {
            size = rhs.size;
            maxSize = rhs.maxSize;
            content = new T[maxSize];

            for (int i = 0 ; i < size ; i++) {
                content[i] = rhs.content[i];
            }
        };

        ~DynamicArray() {
            delete[] content;
        };

        T* getContent() {
            return content;
        };

        int getSize() {
            return size;
        }

        int getMaxSize() {
            return maxSize;
        };

        T& get(int index) {
            return content[index];
        };

        bool exists(T check) {
            for (int i = 0 ; i < size ; i++) {
                if (content[i] == check) {
                    return true;
                }
            }

            return false;
        }

        void add(T add) {
            if (size == maxSize) {
                resize();
            }

            content[size] = add;
            size++;
        };

        void add(DynamicArray<T> array) {
            for (int i = 0 ; i < array.size ; i++) {
                add(array.get(i));
            }
        };

        void resize() {
            maxSize += 5;
            T* bigger = new T[maxSize];

            for (int i = 0 ; i < size ; i++) {
                bigger[i] = content[i];
            }

            delete[] content;
            content = bigger;
        };

        DynamicArray<T> operator =(const DynamicArray<T>& rhs) {
            size = rhs.size;
            maxSize = rhs.maxSize;
            
            if (content) {
                delete[] content;
            }
            
            content = new T[maxSize];

            for (int i = 0 ; i < size ; i++) {
                content[i] = rhs.content[i];
            }

            return *this;
        }
};

#endif