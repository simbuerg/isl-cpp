#ifndef ISL_CXX_MultiUnionPwAff_IMPL_H
#define ISL_CXX_MultiUnionPwAff_IMPL_H

#include "isl/MultiUnionPwAff.h"

#include "isl/Aff.hpp"
#include "isl/MultiAff.hpp"
#include "isl/MultiPwAff.hpp"
#include "isl/MultiVal.hpp"
#include "isl/PwMultiAff.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/UnionMap.hpp"
#include "isl/UnionPwAff.hpp"
#include "isl/UnionPwAffList.hpp"
#include "isl/UnionPwMultiAff.hpp"
#include "isl/UnionSet.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/DimType.h"
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
inline MultiUnionPwAff MultiUnionPwAff::fromUnionPwAffList(const Space &space, const UnionPwAffList &list) {
  const Ctx &_ctx = list.Context();
  _ctx.lock();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_from_union_pw_aff_list((space).GetCopy(), (list).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_from_union_pw_aff_list returned a NULL pointer.");
  }

  return MultiUnionPwAff(_ctx, That);
}

inline MultiUnionPwAff MultiUnionPwAff::zero(const Space &space) {
  const Ctx &_ctx = space.Context();
  _ctx.lock();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_zero((space).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_zero returned a NULL pointer.");
  }

  return MultiUnionPwAff(_ctx, That);
}

inline MultiUnionPwAff MultiUnionPwAff::fromMultiAff(const MultiAff &ma) {
  const Ctx &_ctx = ma.Context();
  _ctx.lock();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_from_multi_aff((ma).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_from_multi_aff returned a NULL pointer.");
  }

  return MultiUnionPwAff(_ctx, That);
}

inline MultiUnionPwAff MultiUnionPwAff::fromUnionPwAff(const UnionPwAff &upa) {
  const Ctx &_ctx = upa.Context();
  _ctx.lock();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_from_union_pw_aff((upa).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_from_union_pw_aff returned a NULL pointer.");
  }

  return MultiUnionPwAff(_ctx, That);
}

inline MultiUnionPwAff MultiUnionPwAff::fromMultiPwAff(const MultiPwAff &mpa) {
  const Ctx &_ctx = mpa.Context();
  _ctx.lock();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_from_multi_pw_aff((mpa).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_from_multi_pw_aff returned a NULL pointer.");
  }

  return MultiUnionPwAff(_ctx, That);
}

inline MultiUnionPwAff MultiUnionPwAff::multiValOnDomain(const UnionSet &domain, const MultiVal &mv) {
  const Ctx &_ctx = mv.Context();
  _ctx.lock();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_multi_val_on_domain((domain).GetCopy(), (mv).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_multi_val_on_domain returned a NULL pointer.");
  }

  return MultiUnionPwAff(_ctx, That);
}

inline MultiUnionPwAff MultiUnionPwAff::multiAffOnDomain(const UnionSet &domain, const MultiAff &ma) {
  const Ctx &_ctx = ma.Context();
  _ctx.lock();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_multi_aff_on_domain((domain).GetCopy(), (ma).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_multi_aff_on_domain returned a NULL pointer.");
  }

  return MultiUnionPwAff(_ctx, That);
}

inline MultiUnionPwAff MultiUnionPwAff::fromUnionPwMultiAff(const UnionPwMultiAff &upma) {
  const Ctx &_ctx = upma.Context();
  _ctx.lock();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_from_union_pw_multi_aff((upma).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_from_union_pw_multi_aff returned a NULL pointer.");
  }

  return MultiUnionPwAff(_ctx, That);
}

inline MultiUnionPwAff MultiUnionPwAff::fromUnionMap(const UnionMap &umap) {
  const Ctx &_ctx = umap.Context();
  _ctx.lock();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_from_union_map((umap).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_from_union_map returned a NULL pointer.");
  }

  return MultiUnionPwAff(_ctx, That);
}

inline MultiUnionPwAff MultiUnionPwAff::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_multi_union_pw_aff *That = isl_multi_union_pw_aff_read_from_str((ctx.Get()), str.c_str());

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


inline MultiUnionPwAff MultiUnionPwAff::add(const MultiUnionPwAff &multi2) const {
  ctx.lock();
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_add((*this).GetCopy(), (multi2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_add returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

inline UnionPwAff MultiUnionPwAff::applyAff(const Aff &aff) const {
  ctx.lock();
  isl_union_pw_aff * res =  isl_multi_union_pw_aff_apply_aff((*this).GetCopy(), (aff).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_apply_aff returned a NULL pointer.");
  }
  return UnionPwAff(ctx, res);
}

inline MultiUnionPwAff MultiUnionPwAff::applyMultiAff(const MultiAff &ma) const {
  ctx.lock();
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_apply_multi_aff((*this).GetCopy(), (ma).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_apply_multi_aff returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

inline MultiUnionPwAff MultiUnionPwAff::applyPwMultiAff(const PwMultiAff &pma) const {
  ctx.lock();
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_apply_pw_multi_aff((*this).GetCopy(), (pma).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_apply_pw_multi_aff returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

inline UnionSet MultiUnionPwAff::domain() const {
  ctx.lock();
  isl_union_set * res =  isl_multi_union_pw_aff_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_domain returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline int MultiUnionPwAff::findDimByName(DimType type, std::string name) const {
  ctx.lock();
  int res =  isl_multi_union_pw_aff_find_dim_by_name((*this).Get(), (enum isl_dim_type)type, name.c_str());
  ctx.unlock();
  return res;
}

inline MultiUnionPwAff MultiUnionPwAff::flatRangeProduct(const MultiUnionPwAff &multi2) const {
  ctx.lock();
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_flat_range_product((*this).GetCopy(), (multi2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_flat_range_product returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

inline MultiUnionPwAff MultiUnionPwAff::floor() const {
  ctx.lock();
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_floor((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_floor returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

inline MultiUnionPwAff MultiUnionPwAff::fromRange() const {
  ctx.lock();
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_from_range((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_from_range returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

inline Space MultiUnionPwAff::getDomainSpace() const {
  ctx.lock();
  isl_space * res =  isl_multi_union_pw_aff_get_domain_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_get_domain_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space MultiUnionPwAff::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_multi_union_pw_aff_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline MultiUnionPwAff MultiUnionPwAff::gist(const UnionSet &context) const {
  ctx.lock();
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_gist((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_gist returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

inline MultiUnionPwAff MultiUnionPwAff::gistParams(const Set &context) const {
  ctx.lock();
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_gist_params((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_gist_params returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

inline MultiUnionPwAff MultiUnionPwAff::intersectDomain(const UnionSet &uset) const {
  ctx.lock();
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_intersect_domain((*this).GetCopy(), (uset).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_intersect_domain returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

inline MultiUnionPwAff MultiUnionPwAff::intersectParams(const Set &params) const {
  ctx.lock();
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_intersect_params((*this).GetCopy(), (params).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_intersect_params returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

inline MultiUnionPwAff MultiUnionPwAff::intersectRange(const Set &set) const {
  ctx.lock();
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_intersect_range((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_intersect_range returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

inline Bool MultiUnionPwAff::plainIsEqual(const MultiUnionPwAff &multi2) const {
  ctx.lock();
  isl_bool res =  isl_multi_union_pw_aff_plain_is_equal((*this).Get(), (multi2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline MultiUnionPwAff MultiUnionPwAff::pullbackUnionPwMultiAff(const UnionPwMultiAff &upma) const {
  ctx.lock();
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_pullback_union_pw_multi_aff((*this).GetCopy(), (upma).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_pullback_union_pw_multi_aff returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

inline MultiUnionPwAff MultiUnionPwAff::rangeProduct(const MultiUnionPwAff &multi2) const {
  ctx.lock();
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_range_product((*this).GetCopy(), (multi2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_range_product returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

inline MultiUnionPwAff MultiUnionPwAff::unionAdd(const MultiUnionPwAff &mupa2) const {
  ctx.lock();
  isl_multi_union_pw_aff * res =  isl_multi_union_pw_aff_union_add((*this).GetCopy(), (mupa2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_union_pw_aff_union_add returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_MultiUnionPwAff_IMPL_H
