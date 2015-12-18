#ifndef ISL_CXX_DimType_H
#define ISL_CXX_DimType_H

namespace isl {
enum class DimType {
  All = 5,
  Cst = 0,
  Div = 4,
  In = 2,
  Out = 3,
  Param = 1,
  Set = 3,
};
} // namespace isl
#endif //ISL_CXX_DimType_H
