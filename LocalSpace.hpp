#ifndef ISL_CXX_LocalSpace_IMPL_H
#define ISL_CXX_LocalSpace_IMPL_H

#include "isl/LocalSpace.h"

#include "isl/Aff.hpp"
#include "isl/BasicMap.hpp"
#include "isl/Id.hpp"
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
inline isl_local_space *LocalSpace::GetCopy() const {
  return isl_local_space_copy((isl_local_space *)This);
}
inline LocalSpace &LocalSpace::operator=(const LocalSpace &Other) {
  isl_local_space *New = Other.GetCopy();
  isl_local_space_free((isl_local_space *)This);
  This = New;
  return *this;
}
inline LocalSpace LocalSpace::fromSpace(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_local_space *That = isl_local_space_from_space((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_local_space_from_space returned a NULL pointer.");
  }

  return LocalSpace(_ctx, That);
}
inline LocalSpace::~LocalSpace() {
  isl_local_space_free((isl_local_space *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_local_space *LocalSpace::Give() {
  isl_local_space *res = (isl_local_space *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_local_space *LocalSpace::Get() const {  return (isl_local_space *)This;
}

inline LocalSpace LocalSpace::asLocalSpace() const {
  return LocalSpace(ctx, GetCopy());
}

inline LocalSpace LocalSpace::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  // Call isl_local_space_add_dims
  isl_local_space * res =  isl_local_space_add_dims((self).Give(), (enum isl_dim_type)type, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_local_space_add_dims returned a NULL pointer.");
  }
  return LocalSpace(ctx, res);
}

inline int LocalSpace::dim(DimType type) const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  // Call isl_local_space_dim
  int res =  isl_local_space_dim((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline LocalSpace LocalSpace::domain() const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  // Call isl_local_space_domain
  isl_local_space * res =  isl_local_space_domain((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_local_space_domain returned a NULL pointer.");
  }
  return LocalSpace(ctx, res);
}

inline LocalSpace LocalSpace::dropDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  // Call isl_local_space_drop_dims
  isl_local_space * res =  isl_local_space_drop_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_local_space_drop_dims returned a NULL pointer.");
  }
  return LocalSpace(ctx, res);
}

inline LocalSpace LocalSpace::fromDomain() const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  // Call isl_local_space_from_domain
  isl_local_space * res =  isl_local_space_from_domain((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_local_space_from_domain returned a NULL pointer.");
  }
  return LocalSpace(ctx, res);
}

inline Id LocalSpace::getDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  // Call isl_local_space_get_dim_id
  isl_id * res =  isl_local_space_get_dim_id((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_local_space_get_dim_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline std::string LocalSpace::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  // Call isl_local_space_get_dim_name
  const char * res =  isl_local_space_get_dim_name((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_local_space_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Aff LocalSpace::getDiv(int pos) const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  // Call isl_local_space_get_div
  isl_aff * res =  isl_local_space_get_div((self).Get(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_local_space_get_div returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Space LocalSpace::getSpace() const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  // Call isl_local_space_get_space
  isl_space * res =  isl_local_space_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_local_space_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Bool LocalSpace::hasDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  // Call isl_local_space_has_dim_id
  isl_bool res =  isl_local_space_has_dim_id((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool LocalSpace::hasDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  // Call isl_local_space_has_dim_name
  isl_bool res =  isl_local_space_has_dim_name((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline LocalSpace LocalSpace::insertDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  // Call isl_local_space_insert_dims
  isl_local_space * res =  isl_local_space_insert_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_local_space_insert_dims returned a NULL pointer.");
  }
  return LocalSpace(ctx, res);
}

inline LocalSpace LocalSpace::intersect(const LocalSpace &ls2) const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  LocalSpace _cast_ls2 = ls2.asLocalSpace();
  // Call isl_local_space_intersect
  isl_local_space * res =  isl_local_space_intersect((self).Give(), (_cast_ls2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_local_space_intersect returned a NULL pointer.");
  }
  return LocalSpace(ctx, res);
}

inline Bool LocalSpace::isEqual(const LocalSpace &ls2) const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  LocalSpace _cast_ls2 = ls2.asLocalSpace();
  // Call isl_local_space_is_equal
  isl_bool res =  isl_local_space_is_equal((self).Get(), (_cast_ls2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool LocalSpace::isSet() const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  // Call isl_local_space_is_set
  isl_bool res =  isl_local_space_is_set((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline BasicMap LocalSpace::lifting() const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  // Call isl_local_space_lifting
  isl_basic_map * res =  isl_local_space_lifting((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_local_space_lifting returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline LocalSpace LocalSpace::range() const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  // Call isl_local_space_range
  isl_local_space * res =  isl_local_space_range((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_local_space_range returned a NULL pointer.");
  }
  return LocalSpace(ctx, res);
}

inline LocalSpace LocalSpace::setDimId(DimType type, unsigned int pos, const Id &id) const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_local_space_set_dim_id
  isl_local_space * res =  isl_local_space_set_dim_id((self).Give(), (enum isl_dim_type)type, pos, (_cast_id).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_local_space_set_dim_id returned a NULL pointer.");
  }
  return LocalSpace(ctx, res);
}

inline LocalSpace LocalSpace::setDimName(DimType type, unsigned int pos, std::string s) const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  // Call isl_local_space_set_dim_name
  isl_local_space * res =  isl_local_space_set_dim_name((self).Give(), (enum isl_dim_type)type, pos, s.c_str());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_local_space_set_dim_name returned a NULL pointer.");
  }
  return LocalSpace(ctx, res);
}

inline LocalSpace LocalSpace::setTupleId(DimType type, const Id &id) const {
  ctx.lock();
  LocalSpace self = asLocalSpace();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_local_space_set_tuple_id
  isl_local_space * res =  isl_local_space_set_tuple_id((self).Give(), (enum isl_dim_type)type, (_cast_id).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_local_space_set_tuple_id returned a NULL pointer.");
  }
  return LocalSpace(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_LocalSpace_IMPL_H
