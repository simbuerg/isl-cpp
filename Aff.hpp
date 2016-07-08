#ifndef ISL_CXX_Aff_IMPL_H
#define ISL_CXX_Aff_IMPL_H

#include "isl/Aff.h"

#include "isl/BasicSet.hpp"
#include "isl/Id.hpp"
#include "isl/LocalSpace.hpp"
#include "isl/MultiAff.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/PwAff.hpp"
#include <string>

#include <cassert>

namespace isl {

inline isl_aff *Aff::GetCopy() const {
  return isl_aff_copy((isl_aff *)This);
}
inline Aff &Aff::operator=(const Aff &Other) {
  isl_aff *New = Other.GetCopy();
  ctx = Other.Context();
  isl_aff_free((isl_aff *)This);
  This = New;
  return *this;
}
inline Aff Aff::zeroOnDomain(const LocalSpace &ls) {
  const Ctx &_ctx = ls.Context();
  _ctx.lock();
  isl_aff *That = isl_aff_zero_on_domain((ls).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_aff_zero_on_domain returned a NULL pointer.");
  }

  return Aff(_ctx, That);
}

inline Aff Aff::valOnDomain(const LocalSpace &ls, const Val &val) {
  const Ctx &_ctx = val.Context();
  _ctx.lock();
  isl_aff *That = isl_aff_val_on_domain((ls).GetCopy(), (val).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_aff_val_on_domain returned a NULL pointer.");
  }

  return Aff(_ctx, That);
}

inline Aff Aff::varOnDomain(const LocalSpace &ls, DimType type, unsigned int pos) {
  const Ctx &_ctx = ls.Context();
  _ctx.lock();
  isl_aff *That = isl_aff_var_on_domain((ls).GetCopy(), (enum isl_dim_type)type, pos);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_aff_var_on_domain returned a NULL pointer.");
  }

  return Aff(_ctx, That);
}

inline Aff Aff::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_aff *That = isl_aff_read_from_str((ctx.Get()), str.c_str());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_aff_read_from_str returned a NULL pointer.");
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

inline Aff Aff::add(const Aff &aff2) const {
  ctx.lock();
  isl_aff * res =  isl_aff_add((*this).GetCopy(), (aff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_add returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::addCoefficientSi(DimType type, int pos, int v) const {
  ctx.lock();
  isl_aff * res =  isl_aff_add_coefficient_si((*this).GetCopy(), (enum isl_dim_type)type, pos, v);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_add_coefficient_si returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::addCoefficientVal(DimType type, int pos, const Val &v) const {
  ctx.lock();
  isl_aff * res =  isl_aff_add_coefficient_val((*this).GetCopy(), (enum isl_dim_type)type, pos, (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_add_coefficient_val returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::addConstantNumSi(int v) const {
  ctx.lock();
  isl_aff * res =  isl_aff_add_constant_num_si((*this).GetCopy(), v);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_add_constant_num_si returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::addConstantSi(int v) const {
  ctx.lock();
  isl_aff * res =  isl_aff_add_constant_si((*this).GetCopy(), v);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_add_constant_si returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::addConstantVal(const Val &v) const {
  ctx.lock();
  isl_aff * res =  isl_aff_add_constant_val((*this).GetCopy(), (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_add_constant_val returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  isl_aff * res =  isl_aff_add_dims((*this).GetCopy(), (enum isl_dim_type)type, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_add_dims returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::alignParams(const Space &model) const {
  ctx.lock();
  isl_aff * res =  isl_aff_align_params((*this).GetCopy(), (model).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_align_params returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::ceil() const {
  ctx.lock();
  isl_aff * res =  isl_aff_ceil((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_ceil returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline int Aff::dim(DimType type) const {
  ctx.lock();
  int res =  isl_aff_dim((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return res;
}

inline Aff Aff::div(const Aff &aff2) const {
  ctx.lock();
  isl_aff * res =  isl_aff_div((*this).GetCopy(), (aff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_div returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::dropDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_aff * res =  isl_aff_drop_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_drop_dims returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::floor() const {
  ctx.lock();
  isl_aff * res =  isl_aff_floor((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_floor returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline BasicSet Aff::geBasicSet(const Aff &aff2) const {
  ctx.lock();
  isl_basic_set * res =  isl_aff_ge_basic_set((*this).GetCopy(), (aff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_ge_basic_set returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Val Aff::getCoefficientVal(DimType type, int pos) const {
  ctx.lock();
  isl_val * res =  isl_aff_get_coefficient_val((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_get_coefficient_val returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Val Aff::getConstantVal() const {
  ctx.lock();
  isl_val * res =  isl_aff_get_constant_val((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_get_constant_val returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Val Aff::getDenominatorVal() const {
  ctx.lock();
  isl_val * res =  isl_aff_get_denominator_val((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_get_denominator_val returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline std::string Aff::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  const char * res =  isl_aff_get_dim_name((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_aff_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Aff Aff::getDiv(int pos) const {
  ctx.lock();
  isl_aff * res =  isl_aff_get_div((*this).Get(), pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_get_div returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline LocalSpace Aff::getDomainLocalSpace() const {
  ctx.lock();
  isl_local_space * res =  isl_aff_get_domain_local_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_get_domain_local_space returned a NULL pointer.");
  }
  return LocalSpace(ctx, res);
}

inline Space Aff::getDomainSpace() const {
  ctx.lock();
  isl_space * res =  isl_aff_get_domain_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_get_domain_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline LocalSpace Aff::getLocalSpace() const {
  ctx.lock();
  isl_local_space * res =  isl_aff_get_local_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_get_local_space returned a NULL pointer.");
  }
  return LocalSpace(ctx, res);
}

inline Space Aff::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_aff_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Aff Aff::gist(const Set &context) const {
  ctx.lock();
  isl_aff * res =  isl_aff_gist((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_gist returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::gistParams(const Set &context) const {
  ctx.lock();
  isl_aff * res =  isl_aff_gist_params((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_gist_params returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::insertDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_aff * res =  isl_aff_insert_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_insert_dims returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Bool Aff::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_bool res =  isl_aff_involves_dims((*this).Get(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  return (Bool)res;
}

inline Bool Aff::isCst() const {
  ctx.lock();
  isl_bool res =  isl_aff_is_cst((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline BasicSet Aff::leBasicSet(const Aff &aff2) const {
  ctx.lock();
  isl_basic_set * res =  isl_aff_le_basic_set((*this).GetCopy(), (aff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_le_basic_set returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Aff Aff::modVal(const Val &mod) const {
  ctx.lock();
  isl_aff * res =  isl_aff_mod_val((*this).GetCopy(), (mod).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_mod_val returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  isl_aff * res =  isl_aff_move_dims((*this).GetCopy(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_move_dims returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::mul(const Aff &aff2) const {
  ctx.lock();
  isl_aff * res =  isl_aff_mul((*this).GetCopy(), (aff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_mul returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::neg() const {
  ctx.lock();
  isl_aff * res =  isl_aff_neg((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_neg returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline BasicSet Aff::negBasicSet() const {
  ctx.lock();
  isl_basic_set * res =  isl_aff_neg_basic_set((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_neg_basic_set returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Bool Aff::plainIsEqual(const Aff &aff2) const {
  ctx.lock();
  isl_bool res =  isl_aff_plain_is_equal((*this).Get(), (aff2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Aff::plainIsZero() const {
  ctx.lock();
  isl_bool res =  isl_aff_plain_is_zero((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Aff Aff::projectDomainOnParams() const {
  ctx.lock();
  isl_aff * res =  isl_aff_project_domain_on_params((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_project_domain_on_params returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::pullbackMultiAff(const MultiAff &ma) const {
  ctx.lock();
  isl_aff * res =  isl_aff_pullback_multi_aff((*this).GetCopy(), (ma).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_pullback_multi_aff returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::pullbackAff(const Aff &aff2) const {
  ctx.lock();
  isl_aff * res =  isl_aff_pullback_aff((*this).GetCopy(), (aff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_pullback_aff returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::scaleDownUi(unsigned int f) const {
  ctx.lock();
  isl_aff * res =  isl_aff_scale_down_ui((*this).GetCopy(), f);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_scale_down_ui returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::scaleDownVal(const Val &v) const {
  ctx.lock();
  isl_aff * res =  isl_aff_scale_down_val((*this).GetCopy(), (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_scale_down_val returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::scaleVal(const Val &v) const {
  ctx.lock();
  isl_aff * res =  isl_aff_scale_val((*this).GetCopy(), (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_scale_val returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::setCoefficientSi(DimType type, int pos, int v) const {
  ctx.lock();
  isl_aff * res =  isl_aff_set_coefficient_si((*this).GetCopy(), (enum isl_dim_type)type, pos, v);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_set_coefficient_si returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::setCoefficientVal(DimType type, int pos, const Val &v) const {
  ctx.lock();
  isl_aff * res =  isl_aff_set_coefficient_val((*this).GetCopy(), (enum isl_dim_type)type, pos, (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_set_coefficient_val returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::setConstantSi(int v) const {
  ctx.lock();
  isl_aff * res =  isl_aff_set_constant_si((*this).GetCopy(), v);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_set_constant_si returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::setConstantVal(const Val &v) const {
  ctx.lock();
  isl_aff * res =  isl_aff_set_constant_val((*this).GetCopy(), (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_set_constant_val returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::setDimId(DimType type, unsigned int pos, const Id &id) const {
  ctx.lock();
  isl_aff * res =  isl_aff_set_dim_id((*this).GetCopy(), (enum isl_dim_type)type, pos, (id).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_set_dim_id returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::setDimName(DimType type, unsigned int pos, std::string s) const {
  ctx.lock();
  isl_aff * res =  isl_aff_set_dim_name((*this).GetCopy(), (enum isl_dim_type)type, pos, s.c_str());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_set_dim_name returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::setTupleId(DimType type, const Id &id) const {
  ctx.lock();
  isl_aff * res =  isl_aff_set_tuple_id((*this).GetCopy(), (enum isl_dim_type)type, (id).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_set_tuple_id returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Aff::sub(const Aff &aff2) const {
  ctx.lock();
  isl_aff * res =  isl_aff_sub((*this).GetCopy(), (aff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_sub returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline BasicSet Aff::zeroBasicSet() const {
  ctx.lock();
  isl_basic_set * res =  isl_aff_zero_basic_set((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_zero_basic_set returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_Aff_IMPL_H
