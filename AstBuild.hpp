#ifndef ISL_CXX_AstBuild_IMPL_H
#define ISL_CXX_AstBuild_IMPL_H

#include "isl/AstBuild.h"

#include "isl/AstExpr.hpp"
#include "isl/AstNode.hpp"
#include "isl/MultiPwAff.hpp"
#include "isl/PwAff.hpp"
#include "isl/PwMultiAff.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/UnionMap.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/ast.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_ast_build *AstBuild::GetCopy() const {
  return isl_ast_build_copy((isl_ast_build *)This);
}
inline AstBuild &AstBuild::operator=(const AstBuild &Other) {
  isl_ast_build *New = Other.GetCopy();
  isl_ast_build_free((isl_ast_build *)This);
  This = New;
  return *this;
}
inline AstBuild AstBuild::fromContext(const Set &set) {
  Ctx _ctx = set.Context();
  _ctx.lock();
  Set _cast_set = set.asSet();
  isl_ast_build *That = isl_ast_build_from_context((_cast_set).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_ast_build_from_context returned a NULL pointer.");
  }

  return AstBuild(_ctx, That);
}
inline AstBuild::~AstBuild() {
  isl_ast_build_free((isl_ast_build *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_ast_build *AstBuild::Give() {
  isl_ast_build *res = (isl_ast_build *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_ast_build *AstBuild::Get() const {  return (isl_ast_build *)This;
}

inline AstBuild AstBuild::asAstBuild() const {
  return AstBuild(GetCopy());
}

inline AstExpr AstBuild::accessFromMultiPwAff(const MultiPwAff &mpa) const {
  ctx.lock();
  AstBuild self = asAstBuild();
  // Prepare arguments
  MultiPwAff _cast_mpa = mpa.asMultiPwAff();
  // Call isl_ast_build_access_from_multi_pw_aff
  isl_ast_expr * res =  isl_ast_build_access_from_multi_pw_aff((self).Get(), (_cast_mpa).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_build_access_from_multi_pw_aff returned a NULL pointer.");
  }
  return AstExpr(res);
}

inline AstExpr AstBuild::accessFromPwMultiAff(const PwMultiAff &pma) const {
  ctx.lock();
  AstBuild self = asAstBuild();
  // Prepare arguments
  PwMultiAff _cast_pma = pma.asPwMultiAff();
  // Call isl_ast_build_access_from_pw_multi_aff
  isl_ast_expr * res =  isl_ast_build_access_from_pw_multi_aff((self).Get(), (_cast_pma).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_build_access_from_pw_multi_aff returned a NULL pointer.");
  }
  return AstExpr(res);
}

inline AstNode AstBuild::astFromSchedule(const UnionMap &schedule) const {
  ctx.lock();
  AstBuild self = asAstBuild();
  // Prepare arguments
  UnionMap _cast_schedule = schedule.asUnionMap();
  // Call isl_ast_build_ast_from_schedule
  isl_ast_node * res =  isl_ast_build_ast_from_schedule((self).Get(), (_cast_schedule).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_build_ast_from_schedule returned a NULL pointer.");
  }
  return AstNode(res);
}

inline AstExpr AstBuild::callFromMultiPwAff(const MultiPwAff &mpa) const {
  ctx.lock();
  AstBuild self = asAstBuild();
  // Prepare arguments
  MultiPwAff _cast_mpa = mpa.asMultiPwAff();
  // Call isl_ast_build_call_from_multi_pw_aff
  isl_ast_expr * res =  isl_ast_build_call_from_multi_pw_aff((self).Get(), (_cast_mpa).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_build_call_from_multi_pw_aff returned a NULL pointer.");
  }
  return AstExpr(res);
}

inline AstExpr AstBuild::callFromPwMultiAff(const PwMultiAff &pma) const {
  ctx.lock();
  AstBuild self = asAstBuild();
  // Prepare arguments
  PwMultiAff _cast_pma = pma.asPwMultiAff();
  // Call isl_ast_build_call_from_pw_multi_aff
  isl_ast_expr * res =  isl_ast_build_call_from_pw_multi_aff((self).Get(), (_cast_pma).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_build_call_from_pw_multi_aff returned a NULL pointer.");
  }
  return AstExpr(res);
}

inline AstExpr AstBuild::exprFromPwAff(const PwAff &pa) const {
  ctx.lock();
  AstBuild self = asAstBuild();
  // Prepare arguments
  PwAff _cast_pa = pa.asPwAff();
  // Call isl_ast_build_expr_from_pw_aff
  isl_ast_expr * res =  isl_ast_build_expr_from_pw_aff((self).Get(), (_cast_pa).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_build_expr_from_pw_aff returned a NULL pointer.");
  }
  return AstExpr(res);
}

inline UnionMap AstBuild::getSchedule() const {
  ctx.lock();
  AstBuild self = asAstBuild();
  // Prepare arguments
  // Call isl_ast_build_get_schedule
  isl_union_map * res =  isl_ast_build_get_schedule((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_build_get_schedule returned a NULL pointer.");
  }
  return UnionMap(res);
}

inline Space AstBuild::getScheduleSpace() const {
  ctx.lock();
  AstBuild self = asAstBuild();
  // Prepare arguments
  // Call isl_ast_build_get_schedule_space
  isl_space * res =  isl_ast_build_get_schedule_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_build_get_schedule_space returned a NULL pointer.");
  }
  return Space(res);
}

inline AstBuild AstBuild::setAtEachDomain(const std::function<isl_ast_node *(isl_ast_node *, isl_ast_build *, void *)> && fn, void * user) const {
  ctx.lock();
  AstBuild self = asAstBuild();
  // Prepare arguments
  // Call isl_ast_build_set_at_each_domain
  isl_ast_build * res =  isl_ast_build_set_at_each_domain((self).Give(), get_fn_ptr<0>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_build_set_at_each_domain returned a NULL pointer.");
  }
  return AstBuild(res);
}

} // namespace isl
#endif //ISL_CXX_AstBuild_IMPL_H
