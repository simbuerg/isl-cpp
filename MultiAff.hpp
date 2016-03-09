#ifndef ISL_CXX_MultiAff_IMPL_H
#define ISL_CXX_MultiAff_IMPL_H

#include "isl/MultiAff.h"

#include "isl/Aff.hpp"
#include "isl/AffList.hpp"
#include "isl/LocalSpace.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/MultiPwAff.hpp"
#include <string>

#include <cassert>

namespace isl {

inline isl_multi_aff *MultiAff::GetCopy() const {
  return isl_multi_aff_copy((isl_multi_aff *)This);
}
inline MultiAff &MultiAff::operator=(const MultiAff &Other) {
  isl_multi_aff *New = Other.GetCopy();
  isl_multi_aff_free((isl_multi_aff *)This);
  This = New;
  return *this;
}
inline MultiAff MultiAff::fromAffList(const Space &space, const AffList &list) {
  const Ctx &_ctx = list.Context();
  _ctx.lock();
  isl_multi_aff *That = isl_multi_aff_from_aff_list((space).GetCopy(), (list).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_aff_from_aff_list returned a NULL pointer.");
  }

  return MultiAff(_ctx, That);
}

inline MultiAff MultiAff::zero(const Space &space) {
  const Ctx &_ctx = space.Context();
  _ctx.lock();
  isl_multi_aff *That = isl_multi_aff_zero((space).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_aff_zero returned a NULL pointer.");
  }

  return MultiAff(_ctx, That);
}

inline MultiAff MultiAff::fromAff(const Aff &aff) {
  const Ctx &_ctx = aff.Context();
  _ctx.lock();
  isl_multi_aff *That = isl_multi_aff_from_aff((aff).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_aff_from_aff returned a NULL pointer.");
  }

  return MultiAff(_ctx, That);
}

inline MultiAff MultiAff::identity(const Space &space) {
  const Ctx &_ctx = space.Context();
  _ctx.lock();
  isl_multi_aff *That = isl_multi_aff_identity((space).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_aff_identity returned a NULL pointer.");
  }

  return MultiAff(_ctx, That);
}

inline MultiAff MultiAff::domainMap(const Space &space) {
  const Ctx &_ctx = space.Context();
  _ctx.lock();
  isl_multi_aff *That = isl_multi_aff_domain_map((space).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_aff_domain_map returned a NULL pointer.");
  }

  return MultiAff(_ctx, That);
}

inline MultiAff MultiAff::rangeMap(const Space &space) {
  const Ctx &_ctx = space.Context();
  _ctx.lock();
  isl_multi_aff *That = isl_multi_aff_range_map((space).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_aff_range_map returned a NULL pointer.");
  }

  return MultiAff(_ctx, That);
}

inline MultiAff MultiAff::projectOutMap(const Space &space, DimType type, unsigned int first, unsigned int n) {
  const Ctx &_ctx = space.Context();
  _ctx.lock();
  isl_multi_aff *That = isl_multi_aff_project_out_map((space).GetCopy(), (enum isl_dim_type)type, first, n);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_aff_project_out_map returned a NULL pointer.");
  }

  return MultiAff(_ctx, That);
}

inline MultiAff MultiAff::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_multi_aff *That = isl_multi_aff_read_from_str((ctx.Get()), str.c_str());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_aff_read_from_str returned a NULL pointer.");
  }

  return MultiAff(_ctx, That);
}
inline MultiAff::~MultiAff() {
  isl_multi_aff_free((isl_multi_aff *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_multi_aff *MultiAff::Give() {
  isl_multi_aff *res = (isl_multi_aff *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_multi_aff *MultiAff::Get() const {  return (isl_multi_aff *)This;
}

inline MultiAff MultiAff::add(const MultiAff &multi2) const {
  ctx.lock();
  isl_multi_aff * res =  isl_multi_aff_add((*this).GetCopy(), (multi2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_aff_add returned a NULL pointer.");
  }
  return MultiAff(ctx, res);
}

inline int MultiAff::findDimByName(DimType type, std::string name) const {
  ctx.lock();
  int res =  isl_multi_aff_find_dim_by_name((*this).Get(), (enum isl_dim_type)type, name.c_str());
  ctx.unlock();
  return res;
}

inline MultiAff MultiAff::flatRangeProduct(const MultiAff &multi2) const {
  ctx.lock();
  isl_multi_aff * res =  isl_multi_aff_flat_range_product((*this).GetCopy(), (multi2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_aff_flat_range_product returned a NULL pointer.");
  }
  return MultiAff(ctx, res);
}

inline MultiAff MultiAff::flattenDomain() const {
  ctx.lock();
  isl_multi_aff * res =  isl_multi_aff_flatten_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_aff_flatten_domain returned a NULL pointer.");
  }
  return MultiAff(ctx, res);
}

inline MultiAff MultiAff::floor() const {
  ctx.lock();
  isl_multi_aff * res =  isl_multi_aff_floor((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_aff_floor returned a NULL pointer.");
  }
  return MultiAff(ctx, res);
}

inline MultiAff MultiAff::fromRange() const {
  ctx.lock();
  isl_multi_aff * res =  isl_multi_aff_from_range((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_aff_from_range returned a NULL pointer.");
  }
  return MultiAff(ctx, res);
}

inline Space MultiAff::getDomainSpace() const {
  ctx.lock();
  isl_space * res =  isl_multi_aff_get_domain_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_aff_get_domain_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space MultiAff::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_multi_aff_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_aff_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline MultiAff MultiAff::gist(const Set &context) const {
  ctx.lock();
  isl_multi_aff * res =  isl_multi_aff_gist((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_aff_gist returned a NULL pointer.");
  }
  return MultiAff(ctx, res);
}

inline Set MultiAff::lexGeSet(const MultiAff &ma2) const {
  ctx.lock();
  isl_set * res =  isl_multi_aff_lex_ge_set((*this).GetCopy(), (ma2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_aff_lex_ge_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set MultiAff::lexLeSet(const MultiAff &ma2) const {
  ctx.lock();
  isl_set * res =  isl_multi_aff_lex_le_set((*this).GetCopy(), (ma2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_aff_lex_le_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline MultiAff MultiAff::lift(std::unique_ptr<LocalSpace> * ls) const {
  ctx.lock();
  isl_local_space * _ls = nullptr;
  isl_multi_aff * res =  isl_multi_aff_lift((*this).GetCopy(), (ls) ? &_ls : nullptr);
  if(ls) {
  if (ctx.hasError()) {
    handleError("ls became a NULL pointer.");
  }
    LocalSpace _tmp_ls = LocalSpace(ctx, _ls);
    ls->reset(new LocalSpace(_tmp_ls));
  }
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_aff_lift returned a NULL pointer.");
  }
  return MultiAff(ctx, res);
}

inline Bool MultiAff::plainIsEqual(const MultiAff &multi2) const {
  ctx.lock();
  isl_bool res =  isl_multi_aff_plain_is_equal((*this).Get(), (multi2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline MultiAff MultiAff::product(const MultiAff &multi2) const {
  ctx.lock();
  isl_multi_aff * res =  isl_multi_aff_product((*this).GetCopy(), (multi2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_aff_product returned a NULL pointer.");
  }
  return MultiAff(ctx, res);
}

inline MultiAff MultiAff::pullbackMultiAff(const MultiAff &ma2) const {
  ctx.lock();
  isl_multi_aff * res =  isl_multi_aff_pullback_multi_aff((*this).GetCopy(), (ma2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_aff_pullback_multi_aff returned a NULL pointer.");
  }
  return MultiAff(ctx, res);
}

inline MultiAff MultiAff::rangeProduct(const MultiAff &multi2) const {
  ctx.lock();
  isl_multi_aff * res =  isl_multi_aff_range_product((*this).GetCopy(), (multi2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_multi_aff_range_product returned a NULL pointer.");
  }
  return MultiAff(ctx, res);
}

inline std::string MultiAff::toStr() const {
  ctx.lock();
  char * res =  isl_multi_aff_to_str((*this).Get());
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_multi_aff_to_str returned a NULL pointer.");
  }
  res_ = res;
  free((void *)res);
  return res_;
}

} // namespace isl
#endif //ISL_CXX_MultiAff_IMPL_H
