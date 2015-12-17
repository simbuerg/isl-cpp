#ifndef ISL_CXX_AstExpr_IMPL_H
#define ISL_CXX_AstExpr_IMPL_H

#include "isl/AstExpr.h"

#include "isl/Id.hpp"
#include "isl/IdToAstExpr.hpp"
#include "isl/Val.hpp"
#include "isl/AstExprType.h"
#include "isl/AstOpType.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

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
}
inline AstExpr AstExpr::fromVal(const Val &v) {
  const Ctx &_ctx = v.Context();
  _ctx.lock();
  Val _cast_v = v.asVal();
  isl_ast_expr *That = isl_ast_expr_from_val((_cast_v).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_ast_expr_from_val returned a NULL pointer.");
  }

  return AstExpr(_ctx, That);
}

inline AstExpr AstExpr::fromId(const Id &id) {
  const Ctx &_ctx = id.Context();
  _ctx.lock();
  Id _cast_id = id.asId();
  isl_ast_expr *That = isl_ast_expr_from_id((_cast_id).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_ast_expr_from_id returned a NULL pointer.");
  }

  return AstExpr(_ctx, That);
}
inline AstExpr::~AstExpr() {
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

inline AstExpr AstExpr::asAstExpr() const {
  return AstExpr(ctx, GetCopy());
}

inline AstExpr AstExpr::add(const AstExpr &expr2) const {
  ctx.lock();
  AstExpr self = asAstExpr();
  // Prepare arguments
  AstExpr _cast_expr2 = expr2.asAstExpr();
  // Call isl_ast_expr_add
  isl_ast_expr * res =  isl_ast_expr_add((self).Give(), (_cast_expr2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_expr_add returned a NULL pointer.");
  }
  return AstExpr(ctx, res);
}

inline AstExpr AstExpr::and_(const AstExpr &expr2) const {
  ctx.lock();
  AstExpr self = asAstExpr();
  // Prepare arguments
  AstExpr _cast_expr2 = expr2.asAstExpr();
  // Call isl_ast_expr_and
  isl_ast_expr * res =  isl_ast_expr_and((self).Give(), (_cast_expr2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_expr_and returned a NULL pointer.");
  }
  return AstExpr(ctx, res);
}

inline AstExpr AstExpr::div(const AstExpr &expr2) const {
  ctx.lock();
  AstExpr self = asAstExpr();
  // Prepare arguments
  AstExpr _cast_expr2 = expr2.asAstExpr();
  // Call isl_ast_expr_div
  isl_ast_expr * res =  isl_ast_expr_div((self).Give(), (_cast_expr2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_expr_div returned a NULL pointer.");
  }
  return AstExpr(ctx, res);
}

inline Id AstExpr::getId() const {
  ctx.lock();
  AstExpr self = asAstExpr();
  // Prepare arguments
  // Call isl_ast_expr_get_id
  isl_id * res =  isl_ast_expr_get_id((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_expr_get_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline AstExpr AstExpr::getOpArg(int pos) const {
  ctx.lock();
  AstExpr self = asAstExpr();
  // Prepare arguments
  // Call isl_ast_expr_get_op_arg
  isl_ast_expr * res =  isl_ast_expr_get_op_arg((self).Get(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_expr_get_op_arg returned a NULL pointer.");
  }
  return AstExpr(ctx, res);
}

inline int AstExpr::getOpNArg() const {
  ctx.lock();
  AstExpr self = asAstExpr();
  // Prepare arguments
  // Call isl_ast_expr_get_op_n_arg
  int res =  isl_ast_expr_get_op_n_arg((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline AstOpType AstExpr::getOpType() const {
  ctx.lock();
  AstExpr self = asAstExpr();
  // Prepare arguments
  // Call isl_ast_expr_get_op_type
  enum isl_ast_op_type res =  isl_ast_expr_get_op_type((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (AstOpType)res;
}

inline AstExprType AstExpr::getType() const {
  ctx.lock();
  AstExpr self = asAstExpr();
  // Prepare arguments
  // Call isl_ast_expr_get_type
  enum isl_ast_expr_type res =  isl_ast_expr_get_type((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (AstExprType)res;
}

inline Val AstExpr::getVal() const {
  ctx.lock();
  AstExpr self = asAstExpr();
  // Prepare arguments
  // Call isl_ast_expr_get_val
  isl_val * res =  isl_ast_expr_get_val((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_expr_get_val returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline AstExpr AstExpr::mul(const AstExpr &expr2) const {
  ctx.lock();
  AstExpr self = asAstExpr();
  // Prepare arguments
  AstExpr _cast_expr2 = expr2.asAstExpr();
  // Call isl_ast_expr_mul
  isl_ast_expr * res =  isl_ast_expr_mul((self).Give(), (_cast_expr2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_expr_mul returned a NULL pointer.");
  }
  return AstExpr(ctx, res);
}

inline AstExpr AstExpr::neg() const {
  ctx.lock();
  AstExpr self = asAstExpr();
  // Prepare arguments
  // Call isl_ast_expr_neg
  isl_ast_expr * res =  isl_ast_expr_neg((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_expr_neg returned a NULL pointer.");
  }
  return AstExpr(ctx, res);
}

inline AstExpr AstExpr::or_(const AstExpr &expr2) const {
  ctx.lock();
  AstExpr self = asAstExpr();
  // Prepare arguments
  AstExpr _cast_expr2 = expr2.asAstExpr();
  // Call isl_ast_expr_or
  isl_ast_expr * res =  isl_ast_expr_or((self).Give(), (_cast_expr2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_expr_or returned a NULL pointer.");
  }
  return AstExpr(ctx, res);
}

inline AstExpr AstExpr::setOpArg(int pos, const AstExpr &arg) const {
  ctx.lock();
  AstExpr self = asAstExpr();
  // Prepare arguments
  AstExpr _cast_arg = arg.asAstExpr();
  // Call isl_ast_expr_set_op_arg
  isl_ast_expr * res =  isl_ast_expr_set_op_arg((self).Give(), pos, (_cast_arg).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_expr_set_op_arg returned a NULL pointer.");
  }
  return AstExpr(ctx, res);
}

inline AstExpr AstExpr::sub(const AstExpr &expr2) const {
  ctx.lock();
  AstExpr self = asAstExpr();
  // Prepare arguments
  AstExpr _cast_expr2 = expr2.asAstExpr();
  // Call isl_ast_expr_sub
  isl_ast_expr * res =  isl_ast_expr_sub((self).Give(), (_cast_expr2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_expr_sub returned a NULL pointer.");
  }
  return AstExpr(ctx, res);
}

inline AstExpr AstExpr::substituteIds(const IdToAstExpr &id2expr) const {
  ctx.lock();
  AstExpr self = asAstExpr();
  // Prepare arguments
  IdToAstExpr _cast_id2expr = id2expr.asIdToAstExpr();
  // Call isl_ast_expr_substitute_ids
  isl_ast_expr * res =  isl_ast_expr_substitute_ids((self).Give(), (_cast_id2expr).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_expr_substitute_ids returned a NULL pointer.");
  }
  return AstExpr(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_AstExpr_IMPL_H
