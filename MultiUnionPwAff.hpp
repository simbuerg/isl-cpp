#ifndef ISL_CXX_MultiUnionPwAff_IMPL_H
#define ISL_CXX_MultiUnionPwAff_IMPL_H

#include "isl/MultiUnionPwAff.h"

#include "isl/Aff.hpp"
#include "isl/MultiAff.hpp"
#include "isl/MultiPwAff.hpp"
#include "isl/MultiVal.hpp"
#include "isl/PwMultiAff.hpp"
#include "isl/Set.hpp"
#include "isl/UnionMap.hpp"
#include "isl/UnionPwAff.hpp"
#include "isl/UnionPwMultiAff.hpp"
#include "isl/UnionSet.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_multi_union_pw_aff *MultiUnionPwAff::GetCopy() const {
  return isl_multi_union_pw_aff_copy((isl_multi_union_pw_aff *)This);
}
inline MultiUnionPwAff &MultiUnionPwAff::operator=(const MultiUnionPwAff &Other) {
  isl_multi_union_pw_aff *New = Other.GetCopy();
  isl_multi_union_pw_aff_free((isl_multi_union_pw_aff *)This);
  This = New;
  return *this;
}
inline MultiUnionPwAff MultiUnionPwAff::fromMultiAff(const MultiAff &ma) {
  Ctx _ctx = ma.Context();
  _ctx.lock();
  MultiAff _cast_ma = ma.asMultiAff();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_from_multi_aff((_cast_ma).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_from_multi_aff returned a NULL pointer.");
  }

  return MultiUnionPwAff(_ctx, That);
}

inline MultiUnionPwAff MultiUnionPwAff::fromUnionPwAff(const UnionPwAff &upa) {
  Ctx _ctx = upa.Context();
  _ctx.lock();
  UnionPwAff _cast_upa = upa.asUnionPwAff();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_from_union_pw_aff((_cast_upa).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_from_union_pw_aff returned a NULL pointer.");
  }

  return MultiUnionPwAff(_ctx, That);
}

inline MultiUnionPwAff MultiUnionPwAff::fromMultiPwAff(const MultiPwAff &mpa) {
  Ctx _ctx = mpa.Context();
  _ctx.lock();
  MultiPwAff _cast_mpa = mpa.asMultiPwAff();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_from_multi_pw_aff((_cast_mpa).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_from_multi_pw_aff returned a NULL pointer.");
  }

  return MultiUnionPwAff(_ctx, That);
}

inline MultiUnionPwAff MultiUnionPwAff::multiValOnDomain(const UnionSet &domain, const MultiVal &mv) {
  Ctx _ctx = mv.Context();
  _ctx.lock();
  UnionSet _cast_domain = domain.asUnionSet();
  MultiVal _cast_mv = mv.asMultiVal();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_multi_val_on_domain((_cast_domain).Give(), (_cast_mv).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_multi_val_on_domain returned a NULL pointer.");
  }

  return MultiUnionPwAff(_ctx, That);
}

inline MultiUnionPwAff MultiUnionPwAff::multiAffOnDomain(const UnionSet &domain, const MultiAff &ma) {
  Ctx _ctx = ma.Context();
  _ctx.lock();
  UnionSet _cast_domain = domain.asUnionSet();
  MultiAff _cast_ma = ma.asMultiAff();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_multi_aff_on_domain((_cast_domain).Give(), (_cast_ma).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_multi_aff_on_domain returned a NULL pointer.");
  }

  return MultiUnionPwAff(_ctx, That);
}

inline MultiUnionPwAff MultiUnionPwAff::fromUnionPwMultiAff(const UnionPwMultiAff &upma) {
  Ctx _ctx = upma.Context();
  _ctx.lock();
  UnionPwMultiAff _cast_upma = upma.asUnionPwMultiAff();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_from_union_pw_multi_aff((_cast_upma).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_from_union_pw_multi_aff returned a NULL pointer.");
  }

  return MultiUnionPwAff(_ctx, That);
}

inline MultiUnionPwAff MultiUnionPwAff::fromUnionMap(const UnionMap &umap) {
  Ctx _ctx = umap.Context();
  _ctx.lock();
  UnionMap _cast_umap = umap.asUnionMap();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_from_union_map((_cast_umap).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_from_union_map returned a NULL pointer.");
  }

  return MultiUnionPwAff(_ctx, That);
}

inline MultiUnionPwAff MultiUnionPwAff::readFromStr(const Ctx &ctx, std::string str) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_read_from_str((ctx.Get()), str.c_str());
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_read_from_str returned a NULL pointer.");
  }

  return MultiUnionPwAff(_ctx, That);
}
inline MultiUnionPwAff::~MultiUnionPwAff() {
  isl_multi_union_pw_aff_free((isl_multi_union_pw_aff *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_multi_union_pw_aff *MultiUnionPwAff::Give() {
  isl_multi_union_pw_aff *res = (isl_multi_union_pw_aff *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_multi_union_pw_aff *MultiUnionPwAff::Get() const {  return (isl_multi_union_pw_aff *)This;
}

inline MultiUnionPwAff MultiUnionPwAff::asMultiUnionPwAff() const {
  return MultiUnionPwAff(GetCopy());
}

inline UnionPwAff MultiUnionPwAff::applyAff(const Aff &aff) const {
  ctx.lock();
  MultiUnionPwAff self = asMultiUnionPwAff();
  // Prepare arguments
  Aff _cast_aff = aff.asAff();
  // Call isl_multi_union_pw_aff_apply_aff
  isl_union_pw_aff * res =  isl_multi_union_pw_aff_apply_aff((self).Give(), (_cast_aff).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_apply_aff returned a NULL pointer.");
  }
  return UnionPwAff(res);
}

inline MultiUnionPwAff MultiUnionPwAff::applyMultiAff(const MultiAff &ma) const {
  ctx.lock();
  MultiUnionPwAff self = asMultiUnionPwAff();
  // Prepare arguments
  MultiAff _cast_ma = ma.asMultiAff();
  // Call isl_multi_union_pw_aff_apply_multi_aff
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_apply_multi_aff((self).Give(), (_cast_ma).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_apply_multi_aff returned a NULL pointer.");
  }
  return MultiUnionPwAff(res);
}

inline MultiUnionPwAff MultiUnionPwAff::applyPwMultiAff(const PwMultiAff &pma) const {
  ctx.lock();
  MultiUnionPwAff self = asMultiUnionPwAff();
  // Prepare arguments
  PwMultiAff _cast_pma = pma.asPwMultiAff();
  // Call isl_multi_union_pw_aff_apply_pw_multi_aff
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_apply_pw_multi_aff((self).Give(), (_cast_pma).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_apply_pw_multi_aff returned a NULL pointer.");
  }
  return MultiUnionPwAff(res);
}

inline UnionSet MultiUnionPwAff::domain() const {
  ctx.lock();
  MultiUnionPwAff self = asMultiUnionPwAff();
  // Prepare arguments
  // Call isl_multi_union_pw_aff_domain
  isl_union_set * res =  isl_multi_union_pw_aff_domain((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_domain returned a NULL pointer.");
  }
  return UnionSet(res);
}

inline MultiUnionPwAff MultiUnionPwAff::floor() const {
  ctx.lock();
  MultiUnionPwAff self = asMultiUnionPwAff();
  // Prepare arguments
  // Call isl_multi_union_pw_aff_floor
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_floor((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_floor returned a NULL pointer.");
  }
  return MultiUnionPwAff(res);
}

inline MultiUnionPwAff MultiUnionPwAff::gist(const UnionSet &context) const {
  ctx.lock();
  MultiUnionPwAff self = asMultiUnionPwAff();
  // Prepare arguments
  UnionSet _cast_context = context.asUnionSet();
  // Call isl_multi_union_pw_aff_gist
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_gist((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_gist returned a NULL pointer.");
  }
  return MultiUnionPwAff(res);
}

inline MultiUnionPwAff MultiUnionPwAff::gistParams(const Set &context) const {
  ctx.lock();
  MultiUnionPwAff self = asMultiUnionPwAff();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_multi_union_pw_aff_gist_params
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_gist_params((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_gist_params returned a NULL pointer.");
  }
  return MultiUnionPwAff(res);
}

inline MultiUnionPwAff MultiUnionPwAff::intersectDomain(const UnionSet &uset) const {
  ctx.lock();
  MultiUnionPwAff self = asMultiUnionPwAff();
  // Prepare arguments
  UnionSet _cast_uset = uset.asUnionSet();
  // Call isl_multi_union_pw_aff_intersect_domain
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_intersect_domain((self).Give(), (_cast_uset).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_intersect_domain returned a NULL pointer.");
  }
  return MultiUnionPwAff(res);
}

inline MultiUnionPwAff MultiUnionPwAff::intersectParams(const Set &params) const {
  ctx.lock();
  MultiUnionPwAff self = asMultiUnionPwAff();
  // Prepare arguments
  Set _cast_params = params.asSet();
  // Call isl_multi_union_pw_aff_intersect_params
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_intersect_params((self).Give(), (_cast_params).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_intersect_params returned a NULL pointer.");
  }
  return MultiUnionPwAff(res);
}

inline MultiUnionPwAff MultiUnionPwAff::intersectRange(const Set &set) const {
  ctx.lock();
  MultiUnionPwAff self = asMultiUnionPwAff();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_multi_union_pw_aff_intersect_range
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_intersect_range((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_intersect_range returned a NULL pointer.");
  }
  return MultiUnionPwAff(res);
}

inline Bool MultiUnionPwAff::plainIsEqual(const MultiUnionPwAff &multi2) const {
  ctx.lock();
  MultiUnionPwAff self = asMultiUnionPwAff();
  // Prepare arguments
  MultiUnionPwAff _cast_multi2 = multi2.asMultiUnionPwAff();
  // Call isl_multi_union_pw_aff_plain_is_equal
  isl_bool res =  isl_multi_union_pw_aff_plain_is_equal((self).Get(), (_cast_multi2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline MultiUnionPwAff MultiUnionPwAff::pullbackUnionPwMultiAff(const UnionPwMultiAff &upma) const {
  ctx.lock();
  MultiUnionPwAff self = asMultiUnionPwAff();
  // Prepare arguments
  UnionPwMultiAff _cast_upma = upma.asUnionPwMultiAff();
  // Call isl_multi_union_pw_aff_pullback_union_pw_multi_aff
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_pullback_union_pw_multi_aff((self).Give(), (_cast_upma).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_pullback_union_pw_multi_aff returned a NULL pointer.");
  }
  return MultiUnionPwAff(res);
}

inline MultiUnionPwAff MultiUnionPwAff::unionAdd(const MultiUnionPwAff &mupa2) const {
  ctx.lock();
  MultiUnionPwAff self = asMultiUnionPwAff();
  // Prepare arguments
  MultiUnionPwAff _cast_mupa2 = mupa2.asMultiUnionPwAff();
  // Call isl_multi_union_pw_aff_union_add
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_union_add((self).Give(), (_cast_mupa2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_union_add returned a NULL pointer.");
  }
  return MultiUnionPwAff(res);
}

} // namespace isl
#endif //ISL_CXX_MultiUnionPwAff_IMPL_H
