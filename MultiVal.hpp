#ifndef ISL_CXX_MultiVal_IMPL_H
#define ISL_CXX_MultiVal_IMPL_H

#include "isl/MultiVal.h"

#include "isl/Space.hpp"
#include "isl/Val.hpp"
#include "isl/ValList.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/DimType.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_multi_val *MultiVal::GetCopy() const {
  return isl_multi_val_copy((isl_multi_val *)This);
}
inline MultiVal &MultiVal::operator=(const MultiVal &Other) {
  isl_multi_val *New = Other.GetCopy();
  isl_multi_val_free((isl_multi_val *)This);
  This = New;
  return *this;
}
inline MultiVal MultiVal::fromValList(const Space &space, const ValList &list) {
  const Ctx &_ctx = list.Context();
  _ctx.lock();
  isl_multi_val *That = isl_multi_val_from_val_list((space).GetCopy(), (list).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_val_from_val_list returned a NULL pointer.");
  }

  return MultiVal(_ctx, That);
}

inline MultiVal MultiVal::zero(const Space &space) {
  const Ctx &_ctx = space.Context();
  _ctx.lock();
  isl_multi_val *That = isl_multi_val_zero((space).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_val_zero returned a NULL pointer.");
  }

  return MultiVal(_ctx, That);
}

inline MultiVal MultiVal::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_multi_val *That = isl_multi_val_read_from_str((ctx.Get()), str.c_str());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_val_read_from_str returned a NULL pointer.");
  }

  return MultiVal(_ctx, That);
}
inline MultiVal::~MultiVal() {
  isl_multi_val_free((isl_multi_val *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_multi_val *MultiVal::Give() {
  isl_multi_val *res = (isl_multi_val *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_multi_val *MultiVal::Get() const {  return (isl_multi_val *)This;
}

inline MultiVal MultiVal::add(const MultiVal &multi2) const {
  ctx.lock();
  isl_multi_val * res =  isl_multi_val_add((*this).GetCopy(), (multi2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_val_add returned a NULL pointer.");
  }
  return MultiVal(ctx, res);
}

inline MultiVal MultiVal::addVal(const Val &v) const {
  ctx.lock();
  isl_multi_val * res =  isl_multi_val_add_val((*this).GetCopy(), (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_val_add_val returned a NULL pointer.");
  }
  return MultiVal(ctx, res);
}

inline int MultiVal::findDimByName(DimType type, std::string name) const {
  ctx.lock();
  int res =  isl_multi_val_find_dim_by_name((*this).Get(), (enum isl_dim_type)type, name.c_str());
  ctx.unlock();
  return res;
}

inline MultiVal MultiVal::flatRangeProduct(const MultiVal &multi2) const {
  ctx.lock();
  isl_multi_val * res =  isl_multi_val_flat_range_product((*this).GetCopy(), (multi2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_val_flat_range_product returned a NULL pointer.");
  }
  return MultiVal(ctx, res);
}

inline MultiVal MultiVal::fromRange() const {
  ctx.lock();
  isl_multi_val * res =  isl_multi_val_from_range((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_val_from_range returned a NULL pointer.");
  }
  return MultiVal(ctx, res);
}

inline Space MultiVal::getDomainSpace() const {
  ctx.lock();
  isl_space * res =  isl_multi_val_get_domain_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_val_get_domain_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space MultiVal::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_multi_val_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_val_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline MultiVal MultiVal::modVal(const Val &v) const {
  ctx.lock();
  isl_multi_val * res =  isl_multi_val_mod_val((*this).GetCopy(), (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_val_mod_val returned a NULL pointer.");
  }
  return MultiVal(ctx, res);
}

inline Bool MultiVal::plainIsEqual(const MultiVal &multi2) const {
  ctx.lock();
  isl_bool res =  isl_multi_val_plain_is_equal((*this).Get(), (multi2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline MultiVal MultiVal::product(const MultiVal &multi2) const {
  ctx.lock();
  isl_multi_val * res =  isl_multi_val_product((*this).GetCopy(), (multi2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_val_product returned a NULL pointer.");
  }
  return MultiVal(ctx, res);
}

inline MultiVal MultiVal::rangeProduct(const MultiVal &multi2) const {
  ctx.lock();
  isl_multi_val * res =  isl_multi_val_range_product((*this).GetCopy(), (multi2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_val_range_product returned a NULL pointer.");
  }
  return MultiVal(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_MultiVal_IMPL_H
