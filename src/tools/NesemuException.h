#ifndef NESEMU_EXCEPTION
#define NESEMU_EXCEPTION

#include <exception> // std::exception
#include <string>    // std::string

namespace tools {

class NesemuException : public std::exception
{
public:
    NesemuException() = delete;
    NesemuException(const std::string& what) : what_(what) {}
    const char* what() const noexcept { return what_.c_str(); }
private:
    std::string what_;
};

} // tools

#endif // NESEMU_EXCEPTION
