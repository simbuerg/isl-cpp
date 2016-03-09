#ifndef ISL_CXX_PwMultiAff_IMPL_H
#define ISL_CXX_PwMultiAff_IMPL_H

#include "isl/PwMultiAff.h"

#include "isl/Id.hpp"
#include "isl/MultiAff.hpp"
#include "isl/PwAff.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/MultiPwAff.hpp"
#include "isl/Stat.h"
#include "isl/aff.h"
#include "isl/set.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_pw_multi_aff *PwMultiAff::GetCopy() const {
  return isl_pw_multi_aff_copy((isl_pw_multi_aff *)This);
}
inline PwMultiAff &PwMultiAff::operator=(const PwMultiAff &Other) {
  isl_pw_multi_aff *New = Other.GetCopy();
  isl_pw_multi_aff_free((isl_pw_multi_aff *)This);
  This = New;
  return *this;
}
inline PwMultiAff PwMultiAff::fromMultiAff(const MultiAff &ma) {
  const Ctx &_ctx = ma.Context();
  _ctx.lock();
  isl_pw_multi_aff *That = isl_pw_multi_aff_from_multi_aff((ma).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_multi_aff_from_multi_aff returned a NULL pointer.");
  }

  return PwMultiAff(_ctx, That);
}

inline PwMultiAff PwMultiAff::fromPwAff(const PwAff &pa) {
  const Ctx &_ctx = pa.Context();
  _ctx.lock();
  isl_pw_multi_aff *That = isl_pw_multi_aff_from_pw_aff((pa).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_multi_aff_from_pw_aff returned a NULL pointer.");
  }

  return PwMultiAff(_ctx, That);
}

inline PwMultiAff PwMultiAff::alloc(const Set &set, const MultiAff &maff) {
  const Ctx &_ctx = maff.Context();
  _ctx.lock();
  isl_pw_multi_aff *That = isl_pw_multi_aff_alloc((set).GetCopy(), (maff).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_multi_aff_alloc returned a NULL pointer.");
  }

  return PwMultiAff(_ctx, That);
}

inline PwMultiAff PwMultiAff::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_pw_multi_aff *That = isl_pw_multi_aff_read_from_str((ctx.Get()), str.c_str());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_multi_aff_read_from_str returned a NULL pointer.");
  }

  return PwMultiAff(_ctx, That);
}
inline PwMultiAff::~PwMultiAff() {
  isl_pw_multi_aff_free((isl_pw_multi_aff *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_pw_multi_aff *PwMultiAff::Give() {
  isl_pw_multi_aff *res = (isl_pw_multi_aff *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_pw_multi_aff *PwMultiAff::Get() const {  return (isl_pw_multi_aff *)This;
}

inline PwMultiAff PwMultiAff::add(const PwMultiAff &pma2) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_add((*this).GetCopy(), (pma2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_add returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline PwMultiAff PwMultiAff::alignParams(const Space &model) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_align_params((*this).GetCopy(), (model).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_align_params returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline PwMultiAff PwMultiAff::coalesce() const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_coalesce((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_coalesce returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline unsigned int PwMultiAff::dim(DimType type) const {
  ctx.lock();
  unsigned int res =  isl_pw_multi_aff_dim((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return res;
}

inline Set PwMultiAff::domain() const {
  ctx.lock();
  isl_set * res =  isl_pw_multi_aff_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_domain returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline PwMultiAff PwMultiAff::dropDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_drop_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_drop_dims returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline PwMultiAff PwMultiAff::flatRangeProduct(const PwMultiAff &pma2) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_flat_range_product((*this).GetCopy(), (pma2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_flat_range_product returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline Stat PwMultiAff::foreachPiece(const std::function<isl_stat(isl_set *, isl_multi_aff *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_pw_multi_aff_foreach_piece((*this).Get(), get_fn_ptr<6>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline Id PwMultiAff::getDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_id * res =  isl_pw_multi_aff_get_dim_id((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_get_dim_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline std::string PwMultiAff::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  const char * res =  isl_pw_multi_aff_get_dim_name((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Space PwMultiAff::getDomainSpace() const {
  ctx.lock();
  isl_space * res =  isl_pw_multi_aff_get_domain_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_get_domain_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline PwAff PwMultiAff::getPwAff(int pos) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_multi_aff_get_pw_aff((*this).Get(), pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_get_pw_aff returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Space PwMultiAff::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_pw_multi_aff_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Id PwMultiAff::getTupleId(DimType type) const {
  ctx.lock();
  isl_id * res =  isl_pw_multi_aff_get_tuple_id((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_get_tuple_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline std::string PwMultiAff::getTupleName(DimType type) const {
  ctx.lock();
  const char * res =  isl_pw_multi_aff_get_tuple_name((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_get_tuple_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline PwMultiAff PwMultiAff::gist(const Set &set) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_gist((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_gist returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline PwMultiAff PwMultiAff::gistParams(const Set &set) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_gist_params((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_gist_params returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline Bool PwMultiAff::hasTupleId(DimType type) const {
  ctx.lock();
  isl_bool res =  isl_pw_multi_aff_has_tuple_id((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return (Bool)res;
}

inline Bool PwMultiAff::hasTupleName(DimType type) const {
  ctx.lock();
  isl_bool res =  isl_pw_multi_aff_has_tuple_name((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return (Bool)res;
}

inline PwMultiAff PwMultiAff::intersectDomain(const Set &set) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_intersect_domain((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_intersect_domain returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline PwMultiAff PwMultiAff::intersectParams(const Set &set) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_intersect_params((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_intersect_params returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline Bool PwMultiAff::plainIsEqual(const PwMultiAff &pma2) const {
  ctx.lock();
  isl_bool res =  isl_pw_multi_aff_plain_is_equal((*this).Get(), (pma2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline PwMultiAff PwMultiAff::product(const PwMultiAff &pma2) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_product((*this).GetCopy(), (pma2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_product returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline PwMultiAff PwMultiAff::projectDomainOnParams() const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_project_domain_on_params((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_project_domain_on_params returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline PwMultiAff PwMultiAff::pullbackMultiAff(const MultiAff &ma) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_pullback_multi_aff((*this).GetCopy(), (ma).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_pullback_multi_aff returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline PwMultiAff PwMultiAff::pullbackPwMultiAff(const PwMultiAff &pma2) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_pullback_pw_multi_aff((*this).GetCopy(), (pma2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_pullback_pw_multi_aff returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline PwMultiAff PwMultiAff::rangeProduct(const PwMultiAff &pma2) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_range_product((*this).GetCopy(), (pma2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_range_product returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline PwMultiAff PwMultiAff::scaleVal(const Val &v) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_scale_val((*this).GetCopy(), (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_scale_val returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline PwMultiAff PwMultiAff::setDimId(DimType type, unsigned int pos, const Id &id) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_set_dim_id((*this).GetCopy(), (enum isl_dim_type)type, pos, (id).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_set_dim_id returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline PwMultiAff PwMultiAff::setPwAff(unsigned int pos, const PwAff &pa) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_set_pw_aff((*this).GetCopy(), pos, (pa).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_set_pw_aff returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline PwMultiAff PwMultiAff::setTupleId(DimType type, const Id &id) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_set_tuple_id((*this).GetCopy(), (enum isl_dim_type)type, (id).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_set_tuple_id returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline PwMultiAff PwMultiAff::sub(const PwMultiAff &pma2) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_sub((*this).GetCopy(), (pma2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_sub returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline PwMultiAff PwMultiAff::unionAdd(const PwMultiAff &pma2) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_union_add((*this).GetCopy(), (pma2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_union_add returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline PwMultiAff PwMultiAff::unionLexmax(const PwMultiAff &pma2) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_union_lexmax((*this).GetCopy(), (pma2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_union_lexmax returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline PwMultiAff PwMultiAff::unionLexmin(const PwMultiAff &pma2) const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_pw_multi_aff_union_lexmin((*this).GetCopy(), (pma2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_union_lexmin returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_PwMultiAff_IMPL_H
