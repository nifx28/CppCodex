/*
 * TClass
 */

#pragma once

#ifndef TCLASS_H
#define TCLASS_H

#include "TMain.h"

namespace main
{
    static long long ptr = 0;

    template <class T, std::size_t N>
    class TClass {
    private:
        std::array<T, N> list;

        friend tostream& operator<<(tostream& os, const TClass& obj)
        {
            tostringstream oss;
            size_t pos = 0;

            if (ptr > 0)
            {
                pos = static_cast<size_t>(((long long)&obj - ptr) / 40);
                oss << pos;
            }
            else
            {
                ptr = (long long)&obj;
                oss << ptr;
            }

            //return os << oss.str();
            return os << obj[pos];
        }

    public:
        TClass(T (&arr)[N])
        {
            std::copy(std::begin(arr), std::end(arr), std::begin(list));
        }

        const T& operator[](std::size_t idx) const
        {
            return list.data()[idx];
        }
    };
}

#endif /* TCLASS_H */
