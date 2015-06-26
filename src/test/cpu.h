#ifndef __cpu_h__
#define __cpu_h__

#include <array>   // std::array
#include <cstdint> // uint8_t, uint16_t

using u8 = 	uint8_t;
using u16 = uint16_t;

namespace nes {
	namespace cpu {
		
		struct Registers {
			u8 A;   // accumulator
			u8 X;   // index register X
			u8 Y;   // index register Y
			u8 P;   // processor status
			u8 SP;  // stack pointer
			u16 PC; // program counter
		};
		
		class Stack {
		public:
			Stack();
			void push(u8 value);
			u8 pop();
		private:
			std::array<u8, 0xff> stack_;
			int index_;
		};

		using BasicMemory = std::array<u8, 65536>;	

	} // namespace cpu
} // namespace nes

#endif // __cpu_h__
