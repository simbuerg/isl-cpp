#ifndef ISL_CXX_DimType_H
#define ISL_CXX_DimType_H

namespace isl {
enum DimType {
  DTAll = 5,
  DTCst = 0,
  DTDiv = 4,
  DTIn = 2,
  DTOut = 3,
  DTParam = 1,
  DTSet = 3,
};
} // namespace isl
#endif //ISL_CXX_DimType_H
