#ifndef ISL_CXX_AstExprType_H
#define ISL_CXX_AstExprType_H

namespace isl {
enum AstExprType {
  AETExprError = -1,
  AETExprId = 1,
  AETExprInt = 2,
  AETExprOp = 0,
};
} // namespace isl
#endif //ISL_CXX_AstExprType_H
