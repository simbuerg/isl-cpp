#ifndef ISL_CXX_IslException_H
#define ISL_CXX_IslException_H

#include <exception>
#include <string>

namespace isl {
class IslException : public std::exception {
  std::string What;

public:
  IslException(std::string What) : What(What) {}
  virtual const char *what() const throw() override {
    return What.c_str();
  }
};
} //namespace isl
#endif //ISL_CXX_IslException_H
