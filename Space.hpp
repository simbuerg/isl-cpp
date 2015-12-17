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
  ctx.unlock();

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
  ctx.unlock();

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
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_space_params_alloc returned a NULL pointer.");
  }

  return Space(_ctx, That);
}

inline Space Space::mapFromSet(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_space *That = isl_space_map_from_set((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_space_map_from_set returned a NULL pointer.");
  }

  return Space(_ctx, That);
}

inline Space Space::mapFromDomainAndRange(const Space &domain, const Space &range) {
  const Ctx &_ctx = range.Context();
  _ctx.lock();
  Space _cast_domain = domain.asSpace();
  Space _cast_range = range.asSpace();
  isl_space *That = isl_space_map_from_domain_and_range((_cast_domain).Give(), (_cast_range).Give());

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

inline Space Space::asSpace() const {
  return Space(ctx, GetCopy());
}

inline Space Space::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_add_dims
  isl_space * res =  isl_space_add_dims((self).Give(), (enum isl_dim_type)type, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_add_dims returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::alignParams(const Space &dim2) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  Space _cast_dim2 = dim2.asSpace();
  // Call isl_space_align_params
  isl_space * res =  isl_space_align_params((self).Give(), (_cast_dim2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_align_params returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Bool Space::canCurry() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_can_curry
  isl_bool res =  isl_space_can_curry((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Space::canUncurry() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_can_uncurry
  isl_bool res =  isl_space_can_uncurry((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Space::canZip() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_can_zip
  isl_bool res =  isl_space_can_zip((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline int Space::compatible(const Space &dim2) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  Space _cast_dim2 = dim2.asSpace();
  // Call isl_space_compatible
  int res =  isl_space_compatible((self).Get(), (_cast_dim2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Space Space::curry() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_curry
  isl_space * res =  isl_space_curry((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_curry returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline unsigned int Space::dim(DimType type) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_dim
  unsigned int res =  isl_space_dim((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Space Space::domain() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_domain
  isl_space * res =  isl_space_domain((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_domain returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::domainMap() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_domain_map
  isl_space * res =  isl_space_domain_map((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_domain_map returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::domainProduct(const Space &right) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  Space _cast_right = right.asSpace();
  // Call isl_space_domain_product
  isl_space * res =  isl_space_domain_product((self).Give(), (_cast_right).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_domain_product returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::dropDims(DimType type, unsigned int first, unsigned int num) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_drop_dims
  isl_space * res =  isl_space_drop_dims((self).Give(), (enum isl_dim_type)type, first, num);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_drop_dims returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::dropInputs(unsigned int first, unsigned int n) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_drop_inputs
  isl_space * res =  isl_space_drop_inputs((self).Give(), first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_drop_inputs returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::dropOutputs(unsigned int first, unsigned int n) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_drop_outputs
  isl_space * res =  isl_space_drop_outputs((self).Give(), first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_drop_outputs returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::extend(unsigned int nparam, unsigned int n_in, unsigned int n_out) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_extend
  isl_space * res =  isl_space_extend((self).Give(), nparam, n_in, n_out);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_extend returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline int Space::findDimById(DimType type, const Id &id) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_space_find_dim_by_id
  int res =  isl_space_find_dim_by_id((self).Get(), (enum isl_dim_type)type, (_cast_id).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline int Space::findDimByName(DimType type, std::string name) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_find_dim_by_name
  int res =  isl_space_find_dim_by_name((self).Get(), (enum isl_dim_type)type, name.c_str());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Space Space::fromDomain() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_from_domain
  isl_space * res =  isl_space_from_domain((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_from_domain returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::fromRange() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_from_range
  isl_space * res =  isl_space_from_range((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_from_range returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Id Space::getDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_get_dim_id
  isl_id * res =  isl_space_get_dim_id((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_get_dim_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline std::string Space::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_get_dim_name
  const char * res =  isl_space_get_dim_name((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_space_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline std::string Space::getTupleName(DimType type) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_get_tuple_name
  const char * res =  isl_space_get_tuple_name((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_space_get_tuple_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Bool Space::hasDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_has_dim_id
  isl_bool res =  isl_space_has_dim_id((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Space::hasDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_has_dim_name
  isl_bool res =  isl_space_has_dim_name((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Space::hasTupleId(DimType type) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_has_tuple_id
  isl_bool res =  isl_space_has_tuple_id((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Space Space::insertDims(DimType type, unsigned int pos, unsigned int n) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_insert_dims
  isl_space * res =  isl_space_insert_dims((self).Give(), (enum isl_dim_type)type, pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_insert_dims returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Bool Space::isDomain(const Space &space2) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  Space _cast_space2 = space2.asSpace();
  // Call isl_space_is_domain
  isl_bool res =  isl_space_is_domain((self).Get(), (_cast_space2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Space::isEqual(const Space &space2) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  Space _cast_space2 = space2.asSpace();
  // Call isl_space_is_equal
  isl_bool res =  isl_space_is_equal((self).Get(), (_cast_space2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Space::isMap() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_is_map
  isl_bool res =  isl_space_is_map((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Space::isParams() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_is_params
  isl_bool res =  isl_space_is_params((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Space::isRange(const Space &space2) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  Space _cast_space2 = space2.asSpace();
  // Call isl_space_is_range
  isl_bool res =  isl_space_is_range((self).Get(), (_cast_space2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Space::isSet() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_is_set
  isl_bool res =  isl_space_is_set((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Space::isWrapping() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_is_wrapping
  isl_bool res =  isl_space_is_wrapping((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Space Space::join(const Space &right) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  Space _cast_right = right.asSpace();
  // Call isl_space_join
  isl_space * res =  isl_space_join((self).Give(), (_cast_right).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_join returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline int Space::match(DimType dim1_type, const Space &dim2, DimType dim2_type) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  Space _cast_dim2 = dim2.asSpace();
  // Call isl_space_match
  int res =  isl_space_match((self).Get(), (enum isl_dim_type)dim1_type, (_cast_dim2).Get(), (enum isl_dim_type)dim2_type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Space Space::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_move_dims
  isl_space * res =  isl_space_move_dims((self).Give(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_move_dims returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::params() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_params
  isl_space * res =  isl_space_params((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_params returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::product(const Space &right) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  Space _cast_right = right.asSpace();
  // Call isl_space_product
  isl_space * res =  isl_space_product((self).Give(), (_cast_right).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_product returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::range() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_range
  isl_space * res =  isl_space_range((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_range returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::rangeMap() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_range_map
  isl_space * res =  isl_space_range_map((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_range_map returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::rangeProduct(const Space &right) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  Space _cast_right = right.asSpace();
  // Call isl_space_range_product
  isl_space * res =  isl_space_range_product((self).Give(), (_cast_right).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_range_product returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::resetTupleId(DimType type) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_reset_tuple_id
  isl_space * res =  isl_space_reset_tuple_id((self).Give(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_reset_tuple_id returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::reverse() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_reverse
  isl_space * res =  isl_space_reverse((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_reverse returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::setDimId(DimType type, unsigned int pos, const Id &id) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_space_set_dim_id
  isl_space * res =  isl_space_set_dim_id((self).Give(), (enum isl_dim_type)type, pos, (_cast_id).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_set_dim_id returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::setDimName(DimType type, unsigned int pos, std::string name) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_set_dim_name
  isl_space * res =  isl_space_set_dim_name((self).Give(), (enum isl_dim_type)type, pos, name.c_str());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_set_dim_name returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::setFromParams() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_set_from_params
  isl_space * res =  isl_space_set_from_params((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_set_from_params returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::setTupleId(DimType type, const Id &id) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_space_set_tuple_id
  isl_space * res =  isl_space_set_tuple_id((self).Give(), (enum isl_dim_type)type, (_cast_id).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_set_tuple_id returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::setTupleName(DimType type, std::string s) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_set_tuple_name
  isl_space * res =  isl_space_set_tuple_name((self).Give(), (enum isl_dim_type)type, s.c_str());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_set_tuple_name returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Bool Space::tupleIsEqual(DimType type1, const Space &space2, DimType type2) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  Space _cast_space2 = space2.asSpace();
  // Call isl_space_tuple_is_equal
  isl_bool res =  isl_space_tuple_is_equal((self).Get(), (enum isl_dim_type)type1, (_cast_space2).Get(), (enum isl_dim_type)type2);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline int Space::tupleMatch(DimType type1, const Space &space2, DimType type2) const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  Space _cast_space2 = space2.asSpace();
  // Call isl_space_tuple_match
  int res =  isl_space_tuple_match((self).Get(), (enum isl_dim_type)type1, (_cast_space2).Get(), (enum isl_dim_type)type2);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Space Space::uncurry() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_uncurry
  isl_space * res =  isl_space_uncurry((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_uncurry returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::unwrap() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_unwrap
  isl_space * res =  isl_space_unwrap((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_unwrap returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::wrap() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_wrap
  isl_space * res =  isl_space_wrap((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_wrap returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Space::zip() const {
  ctx.lock();
  Space self = asSpace();
  // Prepare arguments
  // Call isl_space_zip
  isl_space * res =  isl_space_zip((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_space_zip returned a NULL pointer.");
  }
  return Space(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_Space_IMPL_H
