#ifndef ISL_CXX_MultiPwAff_IMPL_H
#define ISL_CXX_MultiPwAff_IMPL_H

#include "isl/MultiPwAff.h"

#include "isl/MultiAff.hpp"
#include "isl/PwAff.hpp"
#include "isl/PwAffList.hpp"
#include "isl/PwMultiAff.hpp"
#include "isl/Space.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/MultiUnionPwAff.hpp"
#include <string>

#include <cassert>

namespace isl {

inline isl_multi_pw_aff *MultiPwAff::GetCopy() const {
  return isl_multi_pw_aff_copy((isl_multi_pw_aff *)This);
}
inline MultiPwAff &MultiPwAff::operator=(const MultiPwAff &Other) {
  isl_multi_pw_aff *New = Other.GetCopy();
  ctx = Other.Context();
  isl_multi_pw_aff_free((isl_multi_pw_aff *)This);
  This = New;
  return *this;
}
inline MultiPwAff MultiPwAff::fromPwAffList(const Space &space, const PwAffList &list) {
  const Ctx &_ctx = list.Context();
  _ctx.lock();
  isl_multi_pw_aff *That = isl_multi_pw_aff_from_pw_aff_list((space).GetCopy(), (list).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_pw_aff_from_pw_aff_list returned a NULL pointer.");
  }

  return MultiPwAff(_ctx, That);
}

inline MultiPwAff MultiPwAff::zero(const Space &space) {
  const Ctx &_ctx = space.Context();
  _ctx.lock();
  isl_multi_pw_aff *That = isl_multi_pw_aff_zero((space).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_pw_aff_zero returned a NULL pointer.");
  }

  return MultiPwAff(_ctx, That);
}

inline MultiPwAff MultiPwAff::fromMultiAff(const MultiAff &ma) {
  const Ctx &_ctx = ma.Context();
  _ctx.lock();
  isl_multi_pw_aff *That = isl_multi_pw_aff_from_multi_aff((ma).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_pw_aff_from_multi_aff returned a NULL pointer.");
  }

  return MultiPwAff(_ctx, That);
}

inline MultiPwAff MultiPwAff::fromPwAff(const PwAff &pa) {
  const Ctx &_ctx = pa.Context();
  _ctx.lock();
  isl_multi_pw_aff *That = isl_multi_pw_aff_from_pw_aff((pa).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_pw_aff_from_pw_aff returned a NULL pointer.");
  }

  return MultiPwAff(_ctx, That);
}

inline MultiPwAff MultiPwAff::fromPwMultiAff(const PwMultiAff &pma) {
  const Ctx &_ctx = pma.Context();
  _ctx.lock();
  isl_multi_pw_aff *That = isl_multi_pw_aff_from_pw_multi_aff((pma).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_pw_aff_from_pw_multi_aff returned a NULL pointer.");
  }

  return MultiPwAff(_ctx, That);
}

inline MultiPwAff MultiPwAff::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_multi_pw_aff *That = isl_multi_pw_aff_read_from_str((ctx.Get()), str.c_str());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_pw_aff_read_from_str returned a NULL pointer.");
  }

  return MultiPwAff(_ctx, That);
}
inline MultiPwAff::~MultiPwAff() {
  isl_multi_pw_aff_free((isl_multi_pw_aff *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_multi_pw_aff *MultiPwAff::Give() {
  isl_multi_pw_aff *res = (isl_multi_pw_aff *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_multi_pw_aff *MultiPwAff::Get() const {  return (isl_multi_pw_aff *)This;
}

inline MultiPwAff MultiPwAff::add(const MultiPwAff &multi2) const {
  ctx.lock();
  isl_multi_pw_aff * res =  isl_multi_pw_aff_add((*this).GetCopy(), (multi2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_pw_aff_add returned a NULL pointer.");
  }
  return MultiPwAff(ctx, res);
}

inline int MultiPwAff::findDimByName(DimType type, std::string name) const {
  ctx.lock();
  int res =  isl_multi_pw_aff_find_dim_by_name((*this).Get(), (enum isl_dim_type)type, name.c_str());
  ctx.unlock();
  return res;
}

inline MultiPwAff MultiPwAff::flatRangeProduct(const MultiPwAff &multi2) const {
  ctx.lock();
  isl_multi_pw_aff * res =  isl_multi_pw_aff_flat_range_product((*this).GetCopy(), (multi2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_pw_aff_flat_range_product returned a NULL pointer.");
  }
  return MultiPwAff(ctx, res);
}

inline MultiPwAff MultiPwAff::fromRange() const {
  ctx.lock();
  isl_multi_pw_aff * res =  isl_multi_pw_aff_from_range((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_pw_aff_from_range returned a NULL pointer.");
  }
  return MultiPwAff(ctx, res);
}

inline Space MultiPwAff::getDomainSpace() const {
  ctx.lock();
  isl_space * res =  isl_multi_pw_aff_get_domain_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_pw_aff_get_domain_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space MultiPwAff::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_multi_pw_aff_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_pw_aff_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Bool MultiPwAff::plainIsEqual(const MultiPwAff &multi2) const {
  ctx.lock();
  isl_bool res =  isl_multi_pw_aff_plain_is_equal((*this).Get(), (multi2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline MultiPwAff MultiPwAff::product(const MultiPwAff &multi2) const {
  ctx.lock();
  isl_multi_pw_aff * res =  isl_multi_pw_aff_product((*this).GetCopy(), (multi2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_pw_aff_product returned a NULL pointer.");
  }
  return MultiPwAff(ctx, res);
}

inline MultiPwAff MultiPwAff::pullbackMultiAff(const MultiAff &ma) const {
  ctx.lock();
  isl_multi_pw_aff * res =  isl_multi_pw_aff_pullback_multi_aff((*this).GetCopy(), (ma).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_pw_aff_pullback_multi_aff returned a NULL pointer.");
  }
  return MultiPwAff(ctx, res);
}

inline MultiPwAff MultiPwAff::pullbackMultiPwAff(const MultiPwAff &mpa2) const {
  ctx.lock();
  isl_multi_pw_aff * res =  isl_multi_pw_aff_pullback_multi_pw_aff((*this).GetCopy(), (mpa2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_pw_aff_pullback_multi_pw_aff returned a NULL pointer.");
  }
  return MultiPwAff(ctx, res);
}

inline MultiPwAff MultiPwAff::pullbackPwMultiAff(const PwMultiAff &pma) const {
  ctx.lock();
  isl_multi_pw_aff * res =  isl_multi_pw_aff_pullback_pw_multi_aff((*this).GetCopy(), (pma).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_pw_aff_pullback_pw_multi_aff returned a NULL pointer.");
  }
  return MultiPwAff(ctx, res);
}

inline MultiPwAff MultiPwAff::rangeProduct(const MultiPwAff &multi2) const {
  ctx.lock();
  isl_multi_pw_aff * res =  isl_multi_pw_aff_range_product((*this).GetCopy(), (multi2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_pw_aff_range_product returned a NULL pointer.");
  }
  return MultiPwAff(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_MultiPwAff_IMPL_H
