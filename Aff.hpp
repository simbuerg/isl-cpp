#ifndef ISL_CXX_Aff_IMPL_H
#define ISL_CXX_Aff_IMPL_H

#include "isl/Aff.h"

#include "isl/BasicSet.hpp"
#include "isl/Id.hpp"
#include "isl/LocalSpace.hpp"
#include "isl/MultiAff.hpp"
#include "isl/Printer.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_aff *Aff::GetCopy() const {
  return isl_aff_copy((isl_aff *)This);
}
inline Aff &Aff::operator=(const Aff &Other) {
  isl_aff *New = Other.GetCopy();
  isl_aff_free((isl_aff *)This);
  This = New;
  return *this;
}
inline Aff Aff::zeroOnDomain(const LocalSpace &ls) {
  Ctx _ctx = ls.Context();
  _ctx.lock();
  LocalSpace _cast_ls = ls.asLocalSpace();
  isl_aff *That = isl_aff_zero_on_domain((_cast_ls).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_aff_zero_on_domain returned a NULL pointer.");
  }

  return Aff(_ctx, That);
}

inline Aff Aff::valOnDomain(const LocalSpace &ls, const Val &val) {
  Ctx _ctx = val.Context();
  _ctx.lock();
  LocalSpace _cast_ls = ls.asLocalSpace();
  Val _cast_val = val.asVal();
  isl_aff *That = isl_aff_val_on_domain((_cast_ls).Give(), (_cast_val).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_aff_val_on_domain returned a NULL pointer.");
  }

  return Aff(_ctx, That);
}

inline Aff Aff::varOnDomain(const LocalSpace &ls, DimType type, unsigned int pos) {
  Ctx _ctx = ls.Context();
  _ctx.lock();
  LocalSpace _cast_ls = ls.asLocalSpace();
  isl_aff *That = isl_aff_var_on_domain((_cast_ls).Give(), (enum isl_dim_type)type, pos);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_aff_var_on_domain returned a NULL pointer.");
  }

  return Aff(_ctx, That);
}
inline Aff::~Aff() {
  isl_aff_free((isl_aff *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_aff *Aff::Give() {
  isl_aff *res = (isl_aff *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_aff *Aff::Get() const {  return (isl_aff *)This;
}
inline std::string Aff::toStr(isl::Format F) const {
  Printer p = Printer::toStr(ctx);
  p = p.setOutputFormat(F);
  p = p.printAff(*this);
  return p.getStr();
}

inline Aff Aff::asAff() const {
  return Aff(GetCopy());
}

inline Aff Aff::add(const Aff &aff2) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Aff _cast_aff2 = aff2.asAff();
  // Call isl_aff_add
  isl_aff * res =  isl_aff_add((self).Give(), (_cast_aff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_add returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::addCoefficientSi(DimType type, int pos, int v) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_add_coefficient_si
  isl_aff * res =  isl_aff_add_coefficient_si((self).Give(), (enum isl_dim_type)type, pos, v);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_add_coefficient_si returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::addCoefficientVal(DimType type, int pos, const Val &v) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_aff_add_coefficient_val
  isl_aff * res =  isl_aff_add_coefficient_val((self).Give(), (enum isl_dim_type)type, pos, (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_add_coefficient_val returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::addConstantNumSi(int v) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_add_constant_num_si
  isl_aff * res =  isl_aff_add_constant_num_si((self).Give(), v);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_add_constant_num_si returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::addConstantSi(int v) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_add_constant_si
  isl_aff * res =  isl_aff_add_constant_si((self).Give(), v);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_add_constant_si returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::addConstantVal(const Val &v) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_aff_add_constant_val
  isl_aff * res =  isl_aff_add_constant_val((self).Give(), (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_add_constant_val returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_add_dims
  isl_aff * res =  isl_aff_add_dims((self).Give(), (enum isl_dim_type)type, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_add_dims returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::alignParams(const Space &model) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Space _cast_model = model.asSpace();
  // Call isl_aff_align_params
  isl_aff * res =  isl_aff_align_params((self).Give(), (_cast_model).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_align_params returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::ceil() const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_ceil
  isl_aff * res =  isl_aff_ceil((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_ceil returned a NULL pointer.");
  }
  return Aff(res);
}

inline int Aff::dim(DimType type) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_dim
  int res =  isl_aff_dim((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Aff Aff::div(const Aff &aff2) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Aff _cast_aff2 = aff2.asAff();
  // Call isl_aff_div
  isl_aff * res =  isl_aff_div((self).Give(), (_cast_aff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_div returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::dropDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_drop_dims
  isl_aff * res =  isl_aff_drop_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_drop_dims returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::floor() const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_floor
  isl_aff * res =  isl_aff_floor((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_floor returned a NULL pointer.");
  }
  return Aff(res);
}

inline BasicSet Aff::geBasicSet(const Aff &aff2) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Aff _cast_aff2 = aff2.asAff();
  // Call isl_aff_ge_basic_set
  isl_basic_set * res =  isl_aff_ge_basic_set((self).Give(), (_cast_aff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_ge_basic_set returned a NULL pointer.");
  }
  return BasicSet(res);
}

inline Val Aff::getCoefficientVal(DimType type, int pos) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_get_coefficient_val
  isl_val * res =  isl_aff_get_coefficient_val((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_get_coefficient_val returned a NULL pointer.");
  }
  return Val(res);
}

inline Val Aff::getConstantVal() const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_get_constant_val
  isl_val * res =  isl_aff_get_constant_val((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_get_constant_val returned a NULL pointer.");
  }
  return Val(res);
}

inline Val Aff::getDenominatorVal() const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_get_denominator_val
  isl_val * res =  isl_aff_get_denominator_val((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_get_denominator_val returned a NULL pointer.");
  }
  return Val(res);
}

inline std::string Aff::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_get_dim_name
  const char * res =  isl_aff_get_dim_name((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_aff_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Aff Aff::getDiv(int pos) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_get_div
  isl_aff * res =  isl_aff_get_div((self).Get(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_get_div returned a NULL pointer.");
  }
  return Aff(res);
}

inline LocalSpace Aff::getDomainLocalSpace() const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_get_domain_local_space
  isl_local_space * res =  isl_aff_get_domain_local_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_get_domain_local_space returned a NULL pointer.");
  }
  return LocalSpace(res);
}

inline Space Aff::getDomainSpace() const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_get_domain_space
  isl_space * res =  isl_aff_get_domain_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_get_domain_space returned a NULL pointer.");
  }
  return Space(res);
}

inline LocalSpace Aff::getLocalSpace() const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_get_local_space
  isl_local_space * res =  isl_aff_get_local_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_get_local_space returned a NULL pointer.");
  }
  return LocalSpace(res);
}

inline Space Aff::getSpace() const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_get_space
  isl_space * res =  isl_aff_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_get_space returned a NULL pointer.");
  }
  return Space(res);
}

inline Aff Aff::gist(const Set &context) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_aff_gist
  isl_aff * res =  isl_aff_gist((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_gist returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::gistParams(const Set &context) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_aff_gist_params
  isl_aff * res =  isl_aff_gist_params((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_gist_params returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::insertDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_insert_dims
  isl_aff * res =  isl_aff_insert_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_insert_dims returned a NULL pointer.");
  }
  return Aff(res);
}

inline Bool Aff::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_involves_dims
  isl_bool res =  isl_aff_involves_dims((self).Get(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Aff::isCst() const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_is_cst
  isl_bool res =  isl_aff_is_cst((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline BasicSet Aff::leBasicSet(const Aff &aff2) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Aff _cast_aff2 = aff2.asAff();
  // Call isl_aff_le_basic_set
  isl_basic_set * res =  isl_aff_le_basic_set((self).Give(), (_cast_aff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_le_basic_set returned a NULL pointer.");
  }
  return BasicSet(res);
}

inline Aff Aff::modVal(const Val &mod) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Val _cast_mod = mod.asVal();
  // Call isl_aff_mod_val
  isl_aff * res =  isl_aff_mod_val((self).Give(), (_cast_mod).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_mod_val returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_move_dims
  isl_aff * res =  isl_aff_move_dims((self).Give(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_move_dims returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::mul(const Aff &aff2) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Aff _cast_aff2 = aff2.asAff();
  // Call isl_aff_mul
  isl_aff * res =  isl_aff_mul((self).Give(), (_cast_aff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_mul returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::neg() const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_neg
  isl_aff * res =  isl_aff_neg((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_neg returned a NULL pointer.");
  }
  return Aff(res);
}

inline BasicSet Aff::negBasicSet() const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_neg_basic_set
  isl_basic_set * res =  isl_aff_neg_basic_set((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_neg_basic_set returned a NULL pointer.");
  }
  return BasicSet(res);
}

inline Bool Aff::plainIsEqual(const Aff &aff2) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Aff _cast_aff2 = aff2.asAff();
  // Call isl_aff_plain_is_equal
  isl_bool res =  isl_aff_plain_is_equal((self).Get(), (_cast_aff2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Aff::plainIsZero() const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_plain_is_zero
  isl_bool res =  isl_aff_plain_is_zero((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Aff Aff::projectDomainOnParams() const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_project_domain_on_params
  isl_aff * res =  isl_aff_project_domain_on_params((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_project_domain_on_params returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::pullbackAff(const Aff &aff2) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Aff _cast_aff2 = aff2.asAff();
  // Call isl_aff_pullback_aff
  isl_aff * res =  isl_aff_pullback_aff((self).Give(), (_cast_aff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_pullback_aff returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::pullbackMultiAff(const MultiAff &ma) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  MultiAff _cast_ma = ma.asMultiAff();
  // Call isl_aff_pullback_multi_aff
  isl_aff * res =  isl_aff_pullback_multi_aff((self).Give(), (_cast_ma).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_pullback_multi_aff returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::scaleDownUi(unsigned int f) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_scale_down_ui
  isl_aff * res =  isl_aff_scale_down_ui((self).Give(), f);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_scale_down_ui returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::scaleDownVal(const Val &v) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_aff_scale_down_val
  isl_aff * res =  isl_aff_scale_down_val((self).Give(), (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_scale_down_val returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::scaleVal(const Val &v) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_aff_scale_val
  isl_aff * res =  isl_aff_scale_val((self).Give(), (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_scale_val returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::setCoefficientSi(DimType type, int pos, int v) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_set_coefficient_si
  isl_aff * res =  isl_aff_set_coefficient_si((self).Give(), (enum isl_dim_type)type, pos, v);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_set_coefficient_si returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::setCoefficientVal(DimType type, int pos, const Val &v) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_aff_set_coefficient_val
  isl_aff * res =  isl_aff_set_coefficient_val((self).Give(), (enum isl_dim_type)type, pos, (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_set_coefficient_val returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::setConstantSi(int v) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_set_constant_si
  isl_aff * res =  isl_aff_set_constant_si((self).Give(), v);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_set_constant_si returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::setConstantVal(const Val &v) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_aff_set_constant_val
  isl_aff * res =  isl_aff_set_constant_val((self).Give(), (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_set_constant_val returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::setDimId(DimType type, unsigned int pos, const Id &id) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_aff_set_dim_id
  isl_aff * res =  isl_aff_set_dim_id((self).Give(), (enum isl_dim_type)type, pos, (_cast_id).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_set_dim_id returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::setDimName(DimType type, unsigned int pos, std::string s) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_set_dim_name
  isl_aff * res =  isl_aff_set_dim_name((self).Give(), (enum isl_dim_type)type, pos, s.c_str());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_set_dim_name returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::setTupleId(DimType type, const Id &id) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_aff_set_tuple_id
  isl_aff * res =  isl_aff_set_tuple_id((self).Give(), (enum isl_dim_type)type, (_cast_id).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_set_tuple_id returned a NULL pointer.");
  }
  return Aff(res);
}

inline Aff Aff::sub(const Aff &aff2) const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  Aff _cast_aff2 = aff2.asAff();
  // Call isl_aff_sub
  isl_aff * res =  isl_aff_sub((self).Give(), (_cast_aff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_sub returned a NULL pointer.");
  }
  return Aff(res);
}

inline BasicSet Aff::zeroBasicSet() const {
  ctx.lock();
  Aff self = asAff();
  // Prepare arguments
  // Call isl_aff_zero_basic_set
  isl_basic_set * res =  isl_aff_zero_basic_set((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_aff_zero_basic_set returned a NULL pointer.");
  }
  return BasicSet(res);
}

} // namespace isl
#endif //ISL_CXX_Aff_IMPL_H
