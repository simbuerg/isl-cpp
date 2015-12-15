#ifndef ISL_CXX_AstExprList_IMPL_H
#define ISL_CXX_AstExprList_IMPL_H

#include "isl/AstExprList.h"

#include "isl/AstExpr.hpp"
#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_ast_expr_list *AstExprList::GetCopy() const {
  return isl_ast_expr_list_copy((isl_ast_expr_list *)This);
}
inline AstExprList &AstExprList::operator=(const AstExprList &Other) {
  isl_ast_expr_list *New = Other.GetCopy();
  isl_ast_expr_list_free((isl_ast_expr_list *)This);
  This = New;
  return *this;
}
inline AstExprList AstExprList::alloc(const Ctx &ctx, int n) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_ast_expr_list *That = isl_ast_expr_list_alloc((ctx.Get()), n);
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_ast_expr_list_alloc returned a NULL pointer.");
  }

  return AstExprList(_ctx, That);
}
inline AstExprList::~AstExprList() {
  isl_ast_expr_list_free((isl_ast_expr_list *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_ast_expr_list *AstExprList::Give() {
  isl_ast_expr_list *res = (isl_ast_expr_list *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_ast_expr_list *AstExprList::Get() const {  return (isl_ast_expr_list *)This;
}

inline AstExprList AstExprList::asAstExprList() const {
  return AstExprList(GetCopy());
}

inline AstExprList AstExprList::add(const AstExpr &el) const {
  ctx.lock();
  AstExprList self = asAstExprList();
  // Prepare arguments
  AstExpr _cast_el = el.asAstExpr();
  // Call isl_ast_expr_list_add
  isl_ast_expr_list * res =  isl_ast_expr_list_add((self).Give(), (_cast_el).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_expr_list_add returned a NULL pointer.");
  }
  return AstExprList(res);
}

} // namespace isl
#endif //ISL_CXX_AstExprList_IMPL_H
