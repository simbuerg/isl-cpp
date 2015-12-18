#ifndef ISL_CXX_AstExprType_H
#define ISL_CXX_AstExprType_H

namespace isl {
enum class AstExprType {
  ExprError = -1,
  ExprId = 1,
  ExprInt = 2,
  ExprOp = 0,
};
} // namespace isl
#endif //ISL_CXX_AstExprType_H
