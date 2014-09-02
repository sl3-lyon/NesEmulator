#ifndef TYPES_H
#define TYPES_H

#include <algorithm> // std::fill
#include <array>     // std::array
#include <numeric>   // std::accumulate
#include <string>    // std::string, std::to_string

#define to_u8(x) ((int)(x & 255))

inline int from_binary(int bin)
{
    int sum = 0, i = 0;
    for (auto c : std::to_string(bin))
    {
    	sum += (int)(c - '0') * 1 << i;
    	i++;
    }
    return sum;
}

typedef unsigned char u8; // Entier non signé sur 8 bits

template <int size = 8>
class bit_array
{
    public:
        bit_array()
        { std::fill(bits.begin(), bits.end(), 0); }
        
        bit_array(const std::array<int, size>& array)
        { bits = array; }

        bit_array(const bit_array& copy)
        { bits = copy.bits; }
      
        std::array<int, size> to_array() const
        { return bits; }
        
        int to_number() const
        { return std::accumulate(bits.begin(), bits.end(), 0); }
      
        int& operator[](int idx)
        { return bits[idx]; }
        
        bit_array& operator=(const std::array<int, size>& list)
        { bits = list; return *this; }
        
    private:
        std::array<int, size> bits;
};

#endif
