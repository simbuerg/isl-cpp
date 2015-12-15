#ifndef ISL_CXX_PwMultiAff_IMPL_H
#define ISL_CXX_PwMultiAff_IMPL_H

#include "isl/PwMultiAff.h"

#include "isl/Id.hpp"
#include "isl/MultiAff.hpp"
#include "isl/Printer.hpp"
#include "isl/PwAff.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/aff.h"
#include "isl/set.h"
#include <string>
#include <ostream>

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
  Ctx _ctx = ma.Context();
  _ctx.lock();
  MultiAff _cast_ma = ma.asMultiAff();
  isl_pw_multi_aff *That = isl_pw_multi_aff_from_multi_aff((_cast_ma).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_multi_aff_from_multi_aff returned a NULL pointer.");
  }

  return PwMultiAff(_ctx, That);
}

inline PwMultiAff PwMultiAff::fromPwAff(const PwAff &pa) {
  Ctx _ctx = pa.Context();
  _ctx.lock();
  PwAff _cast_pa = pa.asPwAff();
  isl_pw_multi_aff *That = isl_pw_multi_aff_from_pw_aff((_cast_pa).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_multi_aff_from_pw_aff returned a NULL pointer.");
  }

  return PwMultiAff(_ctx, That);
}

inline PwMultiAff PwMultiAff::alloc(const Set &set, const MultiAff &maff) {
  Ctx _ctx = maff.Context();
  _ctx.lock();
  Set _cast_set = set.asSet();
  MultiAff _cast_maff = maff.asMultiAff();
  isl_pw_multi_aff *That = isl_pw_multi_aff_alloc((_cast_set).Give(), (_cast_maff).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_multi_aff_alloc returned a NULL pointer.");
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
inline std::string PwMultiAff::toStr(isl::Format F) const {
  Printer p = Printer::toStr(ctx);
  p = p.setOutputFormat(F);
  p = p.printPwMultiAff(*this);
  return p.getStr();
}

inline PwMultiAff PwMultiAff::asPwMultiAff() const {
  return PwMultiAff(GetCopy());
}

inline PwMultiAff PwMultiAff::add(const PwMultiAff &pma2) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  PwMultiAff _cast_pma2 = pma2.asPwMultiAff();
  // Call isl_pw_multi_aff_add
  isl_pw_multi_aff * res =  isl_pw_multi_aff_add((self).Give(), (_cast_pma2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_add returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline PwMultiAff PwMultiAff::alignParams(const Space &model) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  Space _cast_model = model.asSpace();
  // Call isl_pw_multi_aff_align_params
  isl_pw_multi_aff * res =  isl_pw_multi_aff_align_params((self).Give(), (_cast_model).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_align_params returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline PwMultiAff PwMultiAff::coalesce() const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  // Call isl_pw_multi_aff_coalesce
  isl_pw_multi_aff * res =  isl_pw_multi_aff_coalesce((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_coalesce returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline unsigned int PwMultiAff::dim(DimType type) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  // Call isl_pw_multi_aff_dim
  unsigned int res =  isl_pw_multi_aff_dim((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Set PwMultiAff::domain() const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  // Call isl_pw_multi_aff_domain
  isl_set * res =  isl_pw_multi_aff_domain((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_domain returned a NULL pointer.");
  }
  return Set(res);
}

inline PwMultiAff PwMultiAff::dropDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  // Call isl_pw_multi_aff_drop_dims
  isl_pw_multi_aff * res =  isl_pw_multi_aff_drop_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_drop_dims returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline PwMultiAff PwMultiAff::flatRangeProduct(const PwMultiAff &pma2) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  PwMultiAff _cast_pma2 = pma2.asPwMultiAff();
  // Call isl_pw_multi_aff_flat_range_product
  isl_pw_multi_aff * res =  isl_pw_multi_aff_flat_range_product((self).Give(), (_cast_pma2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_flat_range_product returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline Stat PwMultiAff::foreachPiece(const std::function<isl_stat(isl_set *, isl_multi_aff *, void *)> && fn, void * user) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  // Call isl_pw_multi_aff_foreach_piece
  isl_stat res =  isl_pw_multi_aff_foreach_piece((self).Get(), get_fn_ptr<10>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Id PwMultiAff::getDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  // Call isl_pw_multi_aff_get_dim_id
  isl_id * res =  isl_pw_multi_aff_get_dim_id((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_get_dim_id returned a NULL pointer.");
  }
  return Id(res);
}

inline std::string PwMultiAff::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  // Call isl_pw_multi_aff_get_dim_name
  const char * res =  isl_pw_multi_aff_get_dim_name((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Space PwMultiAff::getDomainSpace() const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  // Call isl_pw_multi_aff_get_domain_space
  isl_space * res =  isl_pw_multi_aff_get_domain_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_get_domain_space returned a NULL pointer.");
  }
  return Space(res);
}

inline PwAff PwMultiAff::getPwAff(int pos) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  // Call isl_pw_multi_aff_get_pw_aff
  isl_pw_aff * res =  isl_pw_multi_aff_get_pw_aff((self).Get(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_get_pw_aff returned a NULL pointer.");
  }
  return PwAff(res);
}

inline Space PwMultiAff::getSpace() const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  // Call isl_pw_multi_aff_get_space
  isl_space * res =  isl_pw_multi_aff_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_get_space returned a NULL pointer.");
  }
  return Space(res);
}

inline Id PwMultiAff::getTupleId(DimType type) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  // Call isl_pw_multi_aff_get_tuple_id
  isl_id * res =  isl_pw_multi_aff_get_tuple_id((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_get_tuple_id returned a NULL pointer.");
  }
  return Id(res);
}

inline std::string PwMultiAff::getTupleName(DimType type) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  // Call isl_pw_multi_aff_get_tuple_name
  const char * res =  isl_pw_multi_aff_get_tuple_name((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_get_tuple_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline PwMultiAff PwMultiAff::gist(const Set &set) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_pw_multi_aff_gist
  isl_pw_multi_aff * res =  isl_pw_multi_aff_gist((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_gist returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline PwMultiAff PwMultiAff::gistParams(const Set &set) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_pw_multi_aff_gist_params
  isl_pw_multi_aff * res =  isl_pw_multi_aff_gist_params((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_gist_params returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline Bool PwMultiAff::hasTupleId(DimType type) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  // Call isl_pw_multi_aff_has_tuple_id
  isl_bool res =  isl_pw_multi_aff_has_tuple_id((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool PwMultiAff::hasTupleName(DimType type) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  // Call isl_pw_multi_aff_has_tuple_name
  isl_bool res =  isl_pw_multi_aff_has_tuple_name((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline PwMultiAff PwMultiAff::intersectDomain(const Set &set) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_pw_multi_aff_intersect_domain
  isl_pw_multi_aff * res =  isl_pw_multi_aff_intersect_domain((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_intersect_domain returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline PwMultiAff PwMultiAff::intersectParams(const Set &set) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_pw_multi_aff_intersect_params
  isl_pw_multi_aff * res =  isl_pw_multi_aff_intersect_params((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_intersect_params returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline Bool PwMultiAff::plainIsEqual(const PwMultiAff &pma2) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  PwMultiAff _cast_pma2 = pma2.asPwMultiAff();
  // Call isl_pw_multi_aff_plain_is_equal
  isl_bool res =  isl_pw_multi_aff_plain_is_equal((self).Get(), (_cast_pma2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline PwMultiAff PwMultiAff::product(const PwMultiAff &pma2) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  PwMultiAff _cast_pma2 = pma2.asPwMultiAff();
  // Call isl_pw_multi_aff_product
  isl_pw_multi_aff * res =  isl_pw_multi_aff_product((self).Give(), (_cast_pma2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_product returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline PwMultiAff PwMultiAff::projectDomainOnParams() const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  // Call isl_pw_multi_aff_project_domain_on_params
  isl_pw_multi_aff * res =  isl_pw_multi_aff_project_domain_on_params((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_project_domain_on_params returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline PwMultiAff PwMultiAff::pullbackMultiAff(const MultiAff &ma) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  MultiAff _cast_ma = ma.asMultiAff();
  // Call isl_pw_multi_aff_pullback_multi_aff
  isl_pw_multi_aff * res =  isl_pw_multi_aff_pullback_multi_aff((self).Give(), (_cast_ma).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_pullback_multi_aff returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline PwMultiAff PwMultiAff::pullbackPwMultiAff(const PwMultiAff &pma2) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  PwMultiAff _cast_pma2 = pma2.asPwMultiAff();
  // Call isl_pw_multi_aff_pullback_pw_multi_aff
  isl_pw_multi_aff * res =  isl_pw_multi_aff_pullback_pw_multi_aff((self).Give(), (_cast_pma2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_pullback_pw_multi_aff returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline PwMultiAff PwMultiAff::rangeProduct(const PwMultiAff &pma2) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  PwMultiAff _cast_pma2 = pma2.asPwMultiAff();
  // Call isl_pw_multi_aff_range_product
  isl_pw_multi_aff * res =  isl_pw_multi_aff_range_product((self).Give(), (_cast_pma2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_range_product returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline PwMultiAff PwMultiAff::scaleVal(const Val &v) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_pw_multi_aff_scale_val
  isl_pw_multi_aff * res =  isl_pw_multi_aff_scale_val((self).Give(), (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_scale_val returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline PwMultiAff PwMultiAff::setDimId(DimType type, unsigned int pos, const Id &id) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_pw_multi_aff_set_dim_id
  isl_pw_multi_aff * res =  isl_pw_multi_aff_set_dim_id((self).Give(), (enum isl_dim_type)type, pos, (_cast_id).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_set_dim_id returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline PwMultiAff PwMultiAff::setPwAff(unsigned int pos, const PwAff &pa) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  PwAff _cast_pa = pa.asPwAff();
  // Call isl_pw_multi_aff_set_pw_aff
  isl_pw_multi_aff * res =  isl_pw_multi_aff_set_pw_aff((self).Give(), pos, (_cast_pa).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_set_pw_aff returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline PwMultiAff PwMultiAff::setTupleId(DimType type, const Id &id) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_pw_multi_aff_set_tuple_id
  isl_pw_multi_aff * res =  isl_pw_multi_aff_set_tuple_id((self).Give(), (enum isl_dim_type)type, (_cast_id).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_set_tuple_id returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline PwMultiAff PwMultiAff::sub(const PwMultiAff &pma2) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  PwMultiAff _cast_pma2 = pma2.asPwMultiAff();
  // Call isl_pw_multi_aff_sub
  isl_pw_multi_aff * res =  isl_pw_multi_aff_sub((self).Give(), (_cast_pma2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_sub returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline PwMultiAff PwMultiAff::unionAdd(const PwMultiAff &pma2) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  PwMultiAff _cast_pma2 = pma2.asPwMultiAff();
  // Call isl_pw_multi_aff_union_add
  isl_pw_multi_aff * res =  isl_pw_multi_aff_union_add((self).Give(), (_cast_pma2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_union_add returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline PwMultiAff PwMultiAff::unionLexmax(const PwMultiAff &pma2) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  PwMultiAff _cast_pma2 = pma2.asPwMultiAff();
  // Call isl_pw_multi_aff_union_lexmax
  isl_pw_multi_aff * res =  isl_pw_multi_aff_union_lexmax((self).Give(), (_cast_pma2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_union_lexmax returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline PwMultiAff PwMultiAff::unionLexmin(const PwMultiAff &pma2) const {
  ctx.lock();
  PwMultiAff self = asPwMultiAff();
  // Prepare arguments
  PwMultiAff _cast_pma2 = pma2.asPwMultiAff();
  // Call isl_pw_multi_aff_union_lexmin
  isl_pw_multi_aff * res =  isl_pw_multi_aff_union_lexmin((self).Give(), (_cast_pma2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_multi_aff_union_lexmin returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

} // namespace isl
#endif //ISL_CXX_PwMultiAff_IMPL_H
