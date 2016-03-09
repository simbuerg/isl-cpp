#ifndef ISL_CXX_AstExpr_IMPL_H
#define ISL_CXX_AstExpr_IMPL_H

#include "isl/AstExpr.h"

#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_ast_expr *AstExpr::GetCopy() const {
  return isl_ast_expr_copy((isl_ast_expr *)This);
}
inline AstExpr &AstExpr::operator=(const AstExpr &Other) {
  isl_ast_expr *New = Other.GetCopy();
  isl_ast_expr_free((isl_ast_expr *)This);
  This = New;
  return *this;
}inline AstExpr::~AstExpr() {
  isl_ast_expr_free((isl_ast_expr *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_ast_expr *AstExpr::Give() {
  isl_ast_expr *res = (isl_ast_expr *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_ast_expr *AstExpr::Get() const {  return (isl_ast_expr *)This;
}

} // namespace isl
#endif //ISL_CXX_AstExpr_IMPL_H
