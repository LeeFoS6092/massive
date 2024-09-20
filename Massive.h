#pragma once
#include <iostream>

using namespace std;

template <typename T>

class Massive
{
    private:
        size_t _size;
        T* _mass;
        size_t _point;
    public:
        Massive() {
            _size = 10;
            _mass = new T[_size];
            _point = 0;
        };

        Massive(int size) {
            _size = size;
            _mass = new T[_size];
            _point = 0;
        };

        void Print() {
            for (int i = 0; i<_size; i++) {
                std::cout << "Number: " << i+1 << " | Value: " << _mass[i] << std::endl;
            }
        }

        bool find(T el) {
            int left = 0;
            int right = _size;
            int middle;

            while (left <= right) {
                middle = (left + right) / 2;

                if (_mass[middle] == el) return true;
                if (_mass[middle] > el) right = middle - 1;
                else left = middle + 1;
            }

            return false;
        }

        void append(T el) {
            if (_point < _size) {
                _mass[_point] = el;
                int fl = 0;
                for (int i = _point; i > 0; i--) {
                    if (_mass[i-1] > _mass[i] ) {
                        swap(_mass[i], _mass[i-1]);
                        fl = 1;
                    } else {
                        break;
                    }
                }
                
                _point++;
                
            } else {
                T* mass = new T[_size*2];
                mass[_size] = el;
                for (int i = 0; i < _size; i++) {
                    mass[i] = _mass[i];
                }
                delete _mass;
                _mass = mass;
                _size*=2;
                _point++;
            }
        }

        int min() {
            return _mass[0];
        }

        int max() {
            return _mass[_point-1];
        }

        void sortMass(T arr[], size_t N) {

            for (int i = N; i > 0; i--) {
                if (arr[i] < arr[i-1]) {
                    swap(arr[i-1], arr[i]);
                } else {
                    break;
                }
            }
        }
};