#ifndef ISL_CXX_IdToAstExpr_IMPL_H
#define ISL_CXX_IdToAstExpr_IMPL_H

#include "isl/IdToAstExpr.h"

#include "isl/AstExpr.hpp"
#include "isl/Id.hpp"
#include "isl/Printer.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/ast.h"
#include "isl/id.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_id_to_ast_expr *IdToAstExpr::GetCopy() const {
  return isl_id_to_ast_expr_copy((isl_id_to_ast_expr *)This);
}
inline IdToAstExpr &IdToAstExpr::operator=(const IdToAstExpr &Other) {
  isl_id_to_ast_expr *New = Other.GetCopy();
  isl_id_to_ast_expr_free((isl_id_to_ast_expr *)This);
  This = New;
  return *this;
}
inline IdToAstExpr IdToAstExpr::alloc(const Ctx &ctx, int min_size) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_id_to_ast_expr *That = isl_id_to_ast_expr_alloc((ctx.Get()), min_size);
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_id_to_ast_expr_alloc returned a NULL pointer.");
  }

  return IdToAstExpr(_ctx, That);
}
inline IdToAstExpr::~IdToAstExpr() {
  isl_id_to_ast_expr_free((isl_id_to_ast_expr *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_id_to_ast_expr *IdToAstExpr::Give() {
  isl_id_to_ast_expr *res = (isl_id_to_ast_expr *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_id_to_ast_expr *IdToAstExpr::Get() const {  return (isl_id_to_ast_expr *)This;
}
inline std::string IdToAstExpr::toStr(isl::Format F) const {
  Printer p = Printer::toStr(ctx);
  p = p.setOutputFormat(F);
  p = p.printIdToAstExpr(*this);
  return p.getStr();
}

inline IdToAstExpr IdToAstExpr::asIdToAstExpr() const {
  return IdToAstExpr(GetCopy());
}

inline Stat IdToAstExpr::foreach_(const std::function<isl_stat(isl_id *, isl_ast_expr *, void *)> && fn, void * user) const {
  ctx.lock();
  IdToAstExpr self = asIdToAstExpr();
  // Prepare arguments
  // Call isl_id_to_ast_expr_foreach
  isl_stat res =  isl_id_to_ast_expr_foreach((self).Get(), get_fn_ptr<7>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline AstExpr IdToAstExpr::get(const Id &key) const {
  ctx.lock();
  IdToAstExpr self = asIdToAstExpr();
  // Prepare arguments
  Id _cast_key = key.asId();
  // Call isl_id_to_ast_expr_get
  isl_ast_expr * res =  isl_id_to_ast_expr_get((self).Get(), (_cast_key).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_id_to_ast_expr_get returned a NULL pointer.");
  }
  return AstExpr(res);
}

inline Bool IdToAstExpr::has(const Id &key) const {
  ctx.lock();
  IdToAstExpr self = asIdToAstExpr();
  // Prepare arguments
  Id _cast_key = key.asId();
  // Call isl_id_to_ast_expr_has
  isl_bool res =  isl_id_to_ast_expr_has((self).Get(), (_cast_key).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline IdToAstExpr IdToAstExpr::set(const Id &key, const AstExpr &val) const {
  ctx.lock();
  IdToAstExpr self = asIdToAstExpr();
  // Prepare arguments
  Id _cast_key = key.asId();
  AstExpr _cast_val = val.asAstExpr();
  // Call isl_id_to_ast_expr_set
  isl_id_to_ast_expr * res =  isl_id_to_ast_expr_set((self).Give(), (_cast_key).Give(), (_cast_val).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_id_to_ast_expr_set returned a NULL pointer.");
  }
  return IdToAstExpr(res);
}

} // namespace isl
#endif //ISL_CXX_IdToAstExpr_IMPL_H
