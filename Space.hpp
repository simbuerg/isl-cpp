#ifndef ISL_CXX_Space_IMPL_H
#define ISL_CXX_Space_IMPL_H

#include "isl/Space.h"

#include "isl/Id.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_space *Space::GetCopy() const {
  return isl_space_copy((isl_space *)This);
}
inline Space &Space::operator=(const Space &Other) {
  isl_space *New = Other.GetCopy();
  isl_space_free((isl_space *)This);
  This = New;
  return *this;
}
inline Space Space::alloc(const Ctx &ctx, unsigned int nparam, unsigned int n_in, unsigned int n_out) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_space *That = isl_space_alloc((ctx.Get()), nparam, n_in, n_out);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_space_alloc returned a NULL pointer.");
  }

  return Space(_ctx, That);
}

inline Space Space::setAlloc(const Ctx &ctx, unsigned int nparam, unsigned int dim) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_space *That = isl_space_set_alloc((ctx.Get()), nparam, dim);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_space_set_alloc returned a NULL pointer.");
  }

  return Space(_ctx, That);
}

inline Space Space::paramsAlloc(const Ctx &ctx, unsigned int nparam) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_space *That = isl_space_params_alloc((ctx.Get()), nparam);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_space_params_alloc returned a NULL pointer.");
  }

  return Space(_ctx, That);
}

inline Space Space::mapFromSet(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_space *That = isl_space_map_from_set((dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_space_map_from_set returned a NULL pointer.");
  }

  return Space(_ctx, That);
}

inline Space Space::mapFromDomainAndRange(const Space &domain, const Space &range) {
  const Ctx &_ctx = range.Context();
  _ctx.lock();
  isl_space *That = isl_space_map_from_domain_and_range((domain).GetCopy(), (range).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_space_map_from_domain_and_range returned a NULL pointer.");
  }

  return Space(_ctx, That);
}
inline Space::~Space() {
  isl_space_free((isl_space *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_space *Space::Give() {
  isl_space *res = (isl_space *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_space *Space::Get() const {  return (isl_space *)This;
}


inline Space Space::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  isl_space * res =  isl_space_add_dims((*this).GetCopy(), (enum isl_dim_type)type, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_add_dims returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::alignParams(const Space &dim2) const {
  ctx.lock();
  isl_space * res =  isl_space_align_params((*this).GetCopy(), (dim2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_align_params returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Bool Space::canCurry() const {
  ctx.lock();
  isl_bool res =  isl_space_can_curry((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Space::canUncurry() const {
  ctx.lock();
  isl_bool res =  isl_space_can_uncurry((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Space::canZip() const {
  ctx.lock();
  isl_bool res =  isl_space_can_zip((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline int Space::compatible(const Space &dim2) const {
  ctx.lock();
  int res =  isl_space_compatible((*this).Get(), (dim2).Get());
  ctx.unlock();
  return res;
}

inline Space Space::curry() const {
  ctx.lock();
  isl_space * res =  isl_space_curry((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_curry returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline unsigned int Space::dim(DimType type) const {
  ctx.lock();
  unsigned int res =  isl_space_dim((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return res;
}

inline Space Space::domain() const {
  ctx.lock();
  isl_space * res =  isl_space_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_domain returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::domainMap() const {
  ctx.lock();
  isl_space * res =  isl_space_domain_map((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_domain_map returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::domainProduct(const Space &right) const {
  ctx.lock();
  isl_space * res =  isl_space_domain_product((*this).GetCopy(), (right).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_domain_product returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::dropDims(DimType type, unsigned int first, unsigned int num) const {
  ctx.lock();
  isl_space * res =  isl_space_drop_dims((*this).GetCopy(), (enum isl_dim_type)type, first, num);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_drop_dims returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::dropInputs(unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_space * res =  isl_space_drop_inputs((*this).GetCopy(), first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_drop_inputs returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::dropOutputs(unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_space * res =  isl_space_drop_outputs((*this).GetCopy(), first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_drop_outputs returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::extend(unsigned int nparam, unsigned int n_in, unsigned int n_out) const {
  ctx.lock();
  isl_space * res =  isl_space_extend((*this).GetCopy(), nparam, n_in, n_out);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_extend returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline int Space::findDimById(DimType type, const Id &id) const {
  ctx.lock();
  int res =  isl_space_find_dim_by_id((*this).Get(), (enum isl_dim_type)type, (id).Get());
  ctx.unlock();
  return res;
}

inline int Space::findDimByName(DimType type, std::string name) const {
  ctx.lock();
  int res =  isl_space_find_dim_by_name((*this).Get(), (enum isl_dim_type)type, name.c_str());
  ctx.unlock();
  return res;
}

inline Space Space::fromDomain() const {
  ctx.lock();
  isl_space * res =  isl_space_from_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_from_domain returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::fromRange() const {
  ctx.lock();
  isl_space * res =  isl_space_from_range((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_from_range returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Id Space::getDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_id * res =  isl_space_get_dim_id((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_get_dim_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline std::string Space::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  const char * res =  isl_space_get_dim_name((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_space_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline std::string Space::getTupleName(DimType type) const {
  ctx.lock();
  const char * res =  isl_space_get_tuple_name((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_space_get_tuple_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Bool Space::hasDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_bool res =  isl_space_has_dim_id((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  return (Bool)res;
}

inline Bool Space::hasDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_bool res =  isl_space_has_dim_name((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  return (Bool)res;
}

inline Bool Space::hasTupleId(DimType type) const {
  ctx.lock();
  isl_bool res =  isl_space_has_tuple_id((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return (Bool)res;
}

inline Space Space::insertDims(DimType type, unsigned int pos, unsigned int n) const {
  ctx.lock();
  isl_space * res =  isl_space_insert_dims((*this).GetCopy(), (enum isl_dim_type)type, pos, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_insert_dims returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Bool Space::isDomain(const Space &space2) const {
  ctx.lock();
  isl_bool res =  isl_space_is_domain((*this).Get(), (space2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Space::isEqual(const Space &space2) const {
  ctx.lock();
  isl_bool res =  isl_space_is_equal((*this).Get(), (space2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Space::isMap() const {
  ctx.lock();
  isl_bool res =  isl_space_is_map((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Space::isParams() const {
  ctx.lock();
  isl_bool res =  isl_space_is_params((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Space::isRange(const Space &space2) const {
  ctx.lock();
  isl_bool res =  isl_space_is_range((*this).Get(), (space2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Space::isSet() const {
  ctx.lock();
  isl_bool res =  isl_space_is_set((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Space::isWrapping() const {
  ctx.lock();
  isl_bool res =  isl_space_is_wrapping((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Space Space::join(const Space &right) const {
  ctx.lock();
  isl_space * res =  isl_space_join((*this).GetCopy(), (right).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_join returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline int Space::match(DimType dim1_type, const Space &dim2, DimType dim2_type) const {
  ctx.lock();
  int res =  isl_space_match((*this).Get(), (enum isl_dim_type)dim1_type, (dim2).Get(), (enum isl_dim_type)dim2_type);
  ctx.unlock();
  return res;
}

inline Space Space::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  isl_space * res =  isl_space_move_dims((*this).GetCopy(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_move_dims returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::params() const {
  ctx.lock();
  isl_space * res =  isl_space_params((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_params returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::product(const Space &right) const {
  ctx.lock();
  isl_space * res =  isl_space_product((*this).GetCopy(), (right).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_product returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::range() const {
  ctx.lock();
  isl_space * res =  isl_space_range((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_range returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::rangeMap() const {
  ctx.lock();
  isl_space * res =  isl_space_range_map((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_range_map returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::rangeProduct(const Space &right) const {
  ctx.lock();
  isl_space * res =  isl_space_range_product((*this).GetCopy(), (right).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_range_product returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::resetTupleId(DimType type) const {
  ctx.lock();
  isl_space * res =  isl_space_reset_tuple_id((*this).GetCopy(), (enum isl_dim_type)type);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_reset_tuple_id returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::reverse() const {
  ctx.lock();
  isl_space * res =  isl_space_reverse((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_reverse returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::setDimId(DimType type, unsigned int pos, const Id &id) const {
  ctx.lock();
  isl_space * res =  isl_space_set_dim_id((*this).GetCopy(), (enum isl_dim_type)type, pos, (id).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_set_dim_id returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::setDimName(DimType type, unsigned int pos, std::string name) const {
  ctx.lock();
  isl_space * res =  isl_space_set_dim_name((*this).GetCopy(), (enum isl_dim_type)type, pos, name.c_str());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_set_dim_name returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::setFromParams() const {
  ctx.lock();
  isl_space * res =  isl_space_set_from_params((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_set_from_params returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::setTupleId(DimType type, const Id &id) const {
  ctx.lock();
  isl_space * res =  isl_space_set_tuple_id((*this).GetCopy(), (enum isl_dim_type)type, (id).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_set_tuple_id returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::setTupleName(DimType type, std::string s) const {
  ctx.lock();
  isl_space * res =  isl_space_set_tuple_name((*this).GetCopy(), (enum isl_dim_type)type, s.c_str());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_set_tuple_name returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Bool Space::tupleIsEqual(DimType type1, const Space &space2, DimType type2) const {
  ctx.lock();
  isl_bool res =  isl_space_tuple_is_equal((*this).Get(), (enum isl_dim_type)type1, (space2).Get(), (enum isl_dim_type)type2);
  ctx.unlock();
  return (Bool)res;
}

inline int Space::tupleMatch(DimType type1, const Space &space2, DimType type2) const {
  ctx.lock();
  int res =  isl_space_tuple_match((*this).Get(), (enum isl_dim_type)type1, (space2).Get(), (enum isl_dim_type)type2);
  ctx.unlock();
  return res;
}

inline Space Space::uncurry() const {
  ctx.lock();
  isl_space * res =  isl_space_uncurry((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_uncurry returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::unwrap() const {
  ctx.lock();
  isl_space * res =  isl_space_unwrap((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_unwrap returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::wrap() const {
  ctx.lock();
  isl_space * res =  isl_space_wrap((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_wrap returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::zip() const {
  ctx.lock();
  isl_space * res =  isl_space_zip((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_space_zip returned a NULL pointer.");
  }
  return Space(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_Space_IMPL_H
