#ifndef ISL_CXX_MultiAff_IMPL_H
#define ISL_CXX_MultiAff_IMPL_H

#include "isl/MultiAff.h"

#include "isl/Aff.hpp"
#include "isl/LocalSpace.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/Bool.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

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
inline MultiAff MultiAff::fromAff(const Aff &aff) {
  const Ctx &_ctx = aff.Context();
  _ctx.lock();
  Aff _cast_aff = aff.asAff();
  isl_multi_aff *That = isl_multi_aff_from_aff((_cast_aff).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_aff_from_aff returned a NULL pointer.");
  }

  return MultiAff(_ctx, That);
}

inline MultiAff MultiAff::identity(const Space &space) {
  const Ctx &_ctx = space.Context();
  _ctx.lock();
  Space _cast_space = space.asSpace();
  isl_multi_aff *That = isl_multi_aff_identity((_cast_space).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_aff_identity returned a NULL pointer.");
  }

  return MultiAff(_ctx, That);
}

inline MultiAff MultiAff::domainMap(const Space &space) {
  const Ctx &_ctx = space.Context();
  _ctx.lock();
  Space _cast_space = space.asSpace();
  isl_multi_aff *That = isl_multi_aff_domain_map((_cast_space).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_aff_domain_map returned a NULL pointer.");
  }

  return MultiAff(_ctx, That);
}

inline MultiAff MultiAff::rangeMap(const Space &space) {
  const Ctx &_ctx = space.Context();
  _ctx.lock();
  Space _cast_space = space.asSpace();
  isl_multi_aff *That = isl_multi_aff_range_map((_cast_space).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_aff_range_map returned a NULL pointer.");
  }

  return MultiAff(_ctx, That);
}

inline MultiAff MultiAff::projectOutMap(const Space &space, DimType type, unsigned int first, unsigned int n) {
  const Ctx &_ctx = space.Context();
  _ctx.lock();
  Space _cast_space = space.asSpace();
  isl_multi_aff *That = isl_multi_aff_project_out_map((_cast_space).Give(), (enum isl_dim_type)type, first, n);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_aff_project_out_map returned a NULL pointer.");
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

inline MultiAff MultiAff::asMultiAff() const {
  return MultiAff(ctx, GetCopy());
}

inline MultiAff MultiAff::flattenDomain() const {
  ctx.lock();
  MultiAff self = asMultiAff();
  // Prepare arguments
  // Call isl_multi_aff_flatten_domain
  isl_multi_aff * res =  isl_multi_aff_flatten_domain((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_aff_flatten_domain returned a NULL pointer.");
  }
  return MultiAff(ctx, res);
}

inline MultiAff MultiAff::floor() const {
  ctx.lock();
  MultiAff self = asMultiAff();
  // Prepare arguments
  // Call isl_multi_aff_floor
  isl_multi_aff * res =  isl_multi_aff_floor((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_aff_floor returned a NULL pointer.");
  }
  return MultiAff(ctx, res);
}

inline MultiAff MultiAff::gist(const Set &context) const {
  ctx.lock();
  MultiAff self = asMultiAff();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_multi_aff_gist
  isl_multi_aff * res =  isl_multi_aff_gist((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_aff_gist returned a NULL pointer.");
  }
  return MultiAff(ctx, res);
}

inline MultiAff MultiAff::gistParams(const Set &context) const {
  ctx.lock();
  MultiAff self = asMultiAff();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_multi_aff_gist_params
  isl_multi_aff * res =  isl_multi_aff_gist_params((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_aff_gist_params returned a NULL pointer.");
  }
  return MultiAff(ctx, res);
}

inline Set MultiAff::lexGeSet(const MultiAff &ma2) const {
  ctx.lock();
  MultiAff self = asMultiAff();
  // Prepare arguments
  MultiAff _cast_ma2 = ma2.asMultiAff();
  // Call isl_multi_aff_lex_ge_set
  isl_set * res =  isl_multi_aff_lex_ge_set((self).Give(), (_cast_ma2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_aff_lex_ge_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set MultiAff::lexLeSet(const MultiAff &ma2) const {
  ctx.lock();
  MultiAff self = asMultiAff();
  // Prepare arguments
  MultiAff _cast_ma2 = ma2.asMultiAff();
  // Call isl_multi_aff_lex_le_set
  isl_set * res =  isl_multi_aff_lex_le_set((self).Give(), (_cast_ma2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_aff_lex_le_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline MultiAff MultiAff::lift(std::unique_ptr<LocalSpace> * ls) const {
  ctx.lock();
  MultiAff self = asMultiAff();
  // Prepare arguments
  isl_local_space * _ls = nullptr;
  // Call isl_multi_aff_lift
  isl_multi_aff * res =  isl_multi_aff_lift((self).Give(), (ls) ? &_ls : nullptr);
  // Handle result argument(s)
  if(ls) {
  if (ctx.hasError()) {
    handleError("ls became a NULL pointer.");
  }
    LocalSpace _tmp_ls = LocalSpace(ctx, _ls);
    ls->reset(new LocalSpace(_tmp_ls));
  }
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_aff_lift returned a NULL pointer.");
  }
  return MultiAff(ctx, res);
}

inline Bool MultiAff::plainIsEqual(const MultiAff &multi2) const {
  ctx.lock();
  MultiAff self = asMultiAff();
  // Prepare arguments
  MultiAff _cast_multi2 = multi2.asMultiAff();
  // Call isl_multi_aff_plain_is_equal
  isl_bool res =  isl_multi_aff_plain_is_equal((self).Get(), (_cast_multi2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline MultiAff MultiAff::pullbackMultiAff(const MultiAff &ma2) const {
  ctx.lock();
  MultiAff self = asMultiAff();
  // Prepare arguments
  MultiAff _cast_ma2 = ma2.asMultiAff();
  // Call isl_multi_aff_pullback_multi_aff
  isl_multi_aff * res =  isl_multi_aff_pullback_multi_aff((self).Give(), (_cast_ma2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_aff_pullback_multi_aff returned a NULL pointer.");
  }
  return MultiAff(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_MultiAff_IMPL_H
