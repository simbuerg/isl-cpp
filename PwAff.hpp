#ifndef ISL_CXX_PwAff_IMPL_H
#define ISL_CXX_PwAff_IMPL_H

#include "isl/PwAff.h"

#include "isl/Aff.hpp"
#include "isl/Id.hpp"
#include "isl/LocalSpace.hpp"
#include "isl/MultiAff.hpp"
#include "isl/PwMultiAff.hpp"
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
inline isl_pw_aff *PwAff::GetCopy() const {
  return isl_pw_aff_copy((isl_pw_aff *)This);
}
inline PwAff &PwAff::operator=(const PwAff &Other) {
  isl_pw_aff *New = Other.GetCopy();
  isl_pw_aff_free((isl_pw_aff *)This);
  This = New;
  return *this;
}
inline PwAff PwAff::fromAff(const Aff &aff) {
  const Ctx &_ctx = aff.Context();
  _ctx.lock();
  Aff _cast_aff = aff.asAff();
  isl_pw_aff *That = isl_pw_aff_from_aff((_cast_aff).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_aff_from_aff returned a NULL pointer.");
  }

  return PwAff(_ctx, That);
}

inline PwAff PwAff::empty(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_pw_aff *That = isl_pw_aff_empty((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_aff_empty returned a NULL pointer.");
  }

  return PwAff(_ctx, That);
}

inline PwAff PwAff::alloc(const Set &set, const Aff &aff) {
  const Ctx &_ctx = aff.Context();
  _ctx.lock();
  Set _cast_set = set.asSet();
  Aff _cast_aff = aff.asAff();
  isl_pw_aff *That = isl_pw_aff_alloc((_cast_set).Give(), (_cast_aff).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_aff_alloc returned a NULL pointer.");
  }

  return PwAff(_ctx, That);
}

inline PwAff PwAff::zeroOnDomain(const LocalSpace &ls) {
  const Ctx &_ctx = ls.Context();
  _ctx.lock();
  LocalSpace _cast_ls = ls.asLocalSpace();
  isl_pw_aff *That = isl_pw_aff_zero_on_domain((_cast_ls).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_aff_zero_on_domain returned a NULL pointer.");
  }

  return PwAff(_ctx, That);
}

inline PwAff PwAff::varOnDomain(const LocalSpace &ls, DimType type, unsigned int pos) {
  const Ctx &_ctx = ls.Context();
  _ctx.lock();
  LocalSpace _cast_ls = ls.asLocalSpace();
  isl_pw_aff *That = isl_pw_aff_var_on_domain((_cast_ls).Give(), (enum isl_dim_type)type, pos);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_aff_var_on_domain returned a NULL pointer.");
  }

  return PwAff(_ctx, That);
}
inline PwAff::~PwAff() {
  isl_pw_aff_free((isl_pw_aff *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_pw_aff *PwAff::Give() {
  isl_pw_aff *res = (isl_pw_aff *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_pw_aff *PwAff::Get() const {  return (isl_pw_aff *)This;
}

inline PwAff PwAff::asPwAff() const {
  return PwAff(ctx, GetCopy());
}

inline PwAff PwAff::add(const PwAff &pwaff2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pwaff2 = pwaff2.asPwAff();
  // Call isl_pw_aff_add
  isl_pw_aff * res =  isl_pw_aff_add((self).Give(), (_cast_pwaff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_add returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_add_dims
  isl_pw_aff * res =  isl_pw_aff_add_dims((self).Give(), (enum isl_dim_type)type, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_add_dims returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::alignParams(const Space &model) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  Space _cast_model = model.asSpace();
  // Call isl_pw_aff_align_params
  isl_pw_aff * res =  isl_pw_aff_align_params((self).Give(), (_cast_model).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_align_params returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::ceil() const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_ceil
  isl_pw_aff * res =  isl_pw_aff_ceil((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_ceil returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::coalesce() const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_coalesce
  isl_pw_aff * res =  isl_pw_aff_coalesce((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_coalesce returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::cond(const PwAff &pwaff_true, const PwAff &pwaff_false) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pwaff_true = pwaff_true.asPwAff();
  PwAff _cast_pwaff_false = pwaff_false.asPwAff();
  // Call isl_pw_aff_cond
  isl_pw_aff * res =  isl_pw_aff_cond((self).Give(), (_cast_pwaff_true).Give(), (_cast_pwaff_false).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_cond returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline unsigned int PwAff::dim(DimType type) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_dim
  unsigned int res =  isl_pw_aff_dim((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline PwAff PwAff::div(const PwAff &pa2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pa2 = pa2.asPwAff();
  // Call isl_pw_aff_div
  isl_pw_aff * res =  isl_pw_aff_div((self).Give(), (_cast_pa2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_div returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Set PwAff::domain() const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_domain
  isl_set * res =  isl_pw_aff_domain((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_domain returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline PwAff PwAff::dropDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_drop_dims
  isl_pw_aff * res =  isl_pw_aff_drop_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_drop_dims returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Set PwAff::eqSet(const PwAff &pwaff2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pwaff2 = pwaff2.asPwAff();
  // Call isl_pw_aff_eq_set
  isl_set * res =  isl_pw_aff_eq_set((self).Give(), (_cast_pwaff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_eq_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline PwAff PwAff::floor() const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_floor
  isl_pw_aff * res =  isl_pw_aff_floor((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_floor returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Stat PwAff::foreachPiece(const std::function<isl_stat(isl_set *, isl_aff *, void *)> && fn, void * user) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_foreach_piece
  isl_stat res =  isl_pw_aff_foreach_piece((self).Get(), get_fn_ptr<9>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline PwAff PwAff::fromRange() const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_from_range
  isl_pw_aff * res =  isl_pw_aff_from_range((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_from_range returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Set PwAff::geSet(const PwAff &pwaff2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pwaff2 = pwaff2.asPwAff();
  // Call isl_pw_aff_ge_set
  isl_set * res =  isl_pw_aff_ge_set((self).Give(), (_cast_pwaff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_ge_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Id PwAff::getDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_get_dim_id
  isl_id * res =  isl_pw_aff_get_dim_id((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_get_dim_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline std::string PwAff::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_get_dim_name
  const char * res =  isl_pw_aff_get_dim_name((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_pw_aff_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Space PwAff::getDomainSpace() const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_get_domain_space
  isl_space * res =  isl_pw_aff_get_domain_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_get_domain_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space PwAff::getSpace() const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_get_space
  isl_space * res =  isl_pw_aff_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline PwAff PwAff::gist(const Set &context) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_pw_aff_gist
  isl_pw_aff * res =  isl_pw_aff_gist((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_gist returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::gistParams(const Set &context) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_pw_aff_gist_params
  isl_pw_aff * res =  isl_pw_aff_gist_params((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_gist_params returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Set PwAff::gtSet(const PwAff &pwaff2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pwaff2 = pwaff2.asPwAff();
  // Call isl_pw_aff_gt_set
  isl_set * res =  isl_pw_aff_gt_set((self).Give(), (_cast_pwaff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_gt_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Bool PwAff::hasDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_has_dim_id
  isl_bool res =  isl_pw_aff_has_dim_id((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool PwAff::hasTupleId(DimType type) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_has_tuple_id
  isl_bool res =  isl_pw_aff_has_tuple_id((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline PwAff PwAff::insertDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_insert_dims
  isl_pw_aff * res =  isl_pw_aff_insert_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_insert_dims returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::intersectDomain(const Set &set) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_pw_aff_intersect_domain
  isl_pw_aff * res =  isl_pw_aff_intersect_domain((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_intersect_domain returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::intersectParams(const Set &set) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_pw_aff_intersect_params
  isl_pw_aff * res =  isl_pw_aff_intersect_params((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_intersect_params returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Bool PwAff::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_involves_dims
  isl_bool res =  isl_pw_aff_involves_dims((self).Get(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool PwAff::isCst() const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_is_cst
  isl_bool res =  isl_pw_aff_is_cst((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool PwAff::isEmpty() const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_is_empty
  isl_bool res =  isl_pw_aff_is_empty((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline int PwAff::isEqual(const PwAff &pa2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pa2 = pa2.asPwAff();
  // Call isl_pw_aff_is_equal
  int res =  isl_pw_aff_is_equal((self).Get(), (_cast_pa2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Set PwAff::leSet(const PwAff &pwaff2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pwaff2 = pwaff2.asPwAff();
  // Call isl_pw_aff_le_set
  isl_set * res =  isl_pw_aff_le_set((self).Give(), (_cast_pwaff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_le_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set PwAff::ltSet(const PwAff &pwaff2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pwaff2 = pwaff2.asPwAff();
  // Call isl_pw_aff_lt_set
  isl_set * res =  isl_pw_aff_lt_set((self).Give(), (_cast_pwaff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_lt_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline PwAff PwAff::max(const PwAff &pwaff2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pwaff2 = pwaff2.asPwAff();
  // Call isl_pw_aff_max
  isl_pw_aff * res =  isl_pw_aff_max((self).Give(), (_cast_pwaff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_max returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::min(const PwAff &pwaff2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pwaff2 = pwaff2.asPwAff();
  // Call isl_pw_aff_min
  isl_pw_aff * res =  isl_pw_aff_min((self).Give(), (_cast_pwaff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_min returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::modVal(const Val &mod) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  Val _cast_mod = mod.asVal();
  // Call isl_pw_aff_mod_val
  isl_pw_aff * res =  isl_pw_aff_mod_val((self).Give(), (_cast_mod).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_mod_val returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_move_dims
  isl_pw_aff * res =  isl_pw_aff_move_dims((self).Give(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_move_dims returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::mul(const PwAff &pwaff2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pwaff2 = pwaff2.asPwAff();
  // Call isl_pw_aff_mul
  isl_pw_aff * res =  isl_pw_aff_mul((self).Give(), (_cast_pwaff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_mul returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline int PwAff::nPiece() const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_n_piece
  int res =  isl_pw_aff_n_piece((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Set PwAff::neSet(const PwAff &pwaff2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pwaff2 = pwaff2.asPwAff();
  // Call isl_pw_aff_ne_set
  isl_set * res =  isl_pw_aff_ne_set((self).Give(), (_cast_pwaff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_ne_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline PwAff PwAff::neg() const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_neg
  isl_pw_aff * res =  isl_pw_aff_neg((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_neg returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Set PwAff::nonZeroSet() const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_non_zero_set
  isl_set * res =  isl_pw_aff_non_zero_set((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_non_zero_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set PwAff::nonnegSet() const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_nonneg_set
  isl_set * res =  isl_pw_aff_nonneg_set((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_nonneg_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set PwAff::params() const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_params
  isl_set * res =  isl_pw_aff_params((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_params returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline PwAff PwAff::pullbackMultiAff(const MultiAff &ma) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  MultiAff _cast_ma = ma.asMultiAff();
  // Call isl_pw_aff_pullback_multi_aff
  isl_pw_aff * res =  isl_pw_aff_pullback_multi_aff((self).Give(), (_cast_ma).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_pullback_multi_aff returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::pullbackPwMultiAff(const PwMultiAff &pma) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwMultiAff _cast_pma = pma.asPwMultiAff();
  // Call isl_pw_aff_pullback_pw_multi_aff
  isl_pw_aff * res =  isl_pw_aff_pullback_pw_multi_aff((self).Give(), (_cast_pma).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_pullback_pw_multi_aff returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::scaleDownVal(const Val &f) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  Val _cast_f = f.asVal();
  // Call isl_pw_aff_scale_down_val
  isl_pw_aff * res =  isl_pw_aff_scale_down_val((self).Give(), (_cast_f).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_scale_down_val returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::scaleVal(const Val &v) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_pw_aff_scale_val
  isl_pw_aff * res =  isl_pw_aff_scale_val((self).Give(), (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_scale_val returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::setDimId(DimType type, unsigned int pos, const Id &id) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_pw_aff_set_dim_id
  isl_pw_aff * res =  isl_pw_aff_set_dim_id((self).Give(), (enum isl_dim_type)type, pos, (_cast_id).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_set_dim_id returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::setTupleId(DimType type, const Id &id) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_pw_aff_set_tuple_id
  isl_pw_aff * res =  isl_pw_aff_set_tuple_id((self).Give(), (enum isl_dim_type)type, (_cast_id).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_set_tuple_id returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::sub(const PwAff &pwaff2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pwaff2 = pwaff2.asPwAff();
  // Call isl_pw_aff_sub
  isl_pw_aff * res =  isl_pw_aff_sub((self).Give(), (_cast_pwaff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_sub returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::tdivQ(const PwAff &pa2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pa2 = pa2.asPwAff();
  // Call isl_pw_aff_tdiv_q
  isl_pw_aff * res =  isl_pw_aff_tdiv_q((self).Give(), (_cast_pa2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_tdiv_q returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::tdivR(const PwAff &pa2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pa2 = pa2.asPwAff();
  // Call isl_pw_aff_tdiv_r
  isl_pw_aff * res =  isl_pw_aff_tdiv_r((self).Give(), (_cast_pa2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_tdiv_r returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::unionAdd(const PwAff &pwaff2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pwaff2 = pwaff2.asPwAff();
  // Call isl_pw_aff_union_add
  isl_pw_aff * res =  isl_pw_aff_union_add((self).Give(), (_cast_pwaff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_union_add returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::unionMax(const PwAff &pwaff2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pwaff2 = pwaff2.asPwAff();
  // Call isl_pw_aff_union_max
  isl_pw_aff * res =  isl_pw_aff_union_max((self).Give(), (_cast_pwaff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_union_max returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::unionMin(const PwAff &pwaff2) const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  PwAff _cast_pwaff2 = pwaff2.asPwAff();
  // Call isl_pw_aff_union_min
  isl_pw_aff * res =  isl_pw_aff_union_min((self).Give(), (_cast_pwaff2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_union_min returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Set PwAff::zeroSet() const {
  ctx.lock();
  PwAff self = asPwAff();
  // Prepare arguments
  // Call isl_pw_aff_zero_set
  isl_set * res =  isl_pw_aff_zero_set((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_aff_zero_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_PwAff_IMPL_H
