#include "cpu.h"
#include <algorithm> // std::fill
 
Stack::Stack() : index_(0) {
	std::fill(stack_.begin(), stack_.end(), 0);
}

void Stack::push(u8 value) {
	stack_[index_] = value;
	index_++;
}

u8 Stack::pop() {
	index_--;
	u8 value = stack_[index_];
	stack_[index_] = 0;
	return value;
}
