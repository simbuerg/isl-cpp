#ifndef ISL_CXX_Vec_IMPL_H
#define ISL_CXX_Vec_IMPL_H

#include "isl/Vec.h"

#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_vec *Vec::GetCopy() const {
  return isl_vec_copy((isl_vec *)This);
}
inline Vec &Vec::operator=(const Vec &Other) {
  isl_vec *New = Other.GetCopy();
  isl_vec_free((isl_vec *)This);
  This = New;
  return *this;
}
inline Vec Vec::alloc(const Ctx &ctx, unsigned int size) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_vec *That = isl_vec_alloc((ctx.Get()), size);
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_vec_alloc returned a NULL pointer.");
  }

  return Vec(_ctx, That);
}
inline Vec::~Vec() {
  isl_vec_free((isl_vec *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_vec *Vec::Give() {
  isl_vec *res = (isl_vec *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_vec *Vec::Get() const {  return (isl_vec *)This;
}

inline Vec Vec::asVec() const {
  return Vec(ctx, GetCopy());
}

inline Vec Vec::add(const Vec &vec2) const {
  ctx.lock();
  Vec self = asVec();
  // Prepare arguments
  Vec _cast_vec2 = vec2.asVec();
  // Call isl_vec_add
  isl_vec * res =  isl_vec_add((self).Give(), (_cast_vec2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_vec_add returned a NULL pointer.");
  }
  return Vec(ctx, res);
}

inline Vec Vec::clr() const {
  ctx.lock();
  Vec self = asVec();
  // Prepare arguments
  // Call isl_vec_clr
  isl_vec * res =  isl_vec_clr((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_vec_clr returned a NULL pointer.");
  }
  return Vec(ctx, res);
}

inline int Vec::cmpElement(const Vec &vec2, int pos) const {
  ctx.lock();
  Vec self = asVec();
  // Prepare arguments
  Vec _cast_vec2 = vec2.asVec();
  // Call isl_vec_cmp_element
  int res =  isl_vec_cmp_element((self).Get(), (_cast_vec2).Get(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Vec Vec::concat(const Vec &vec2) const {
  ctx.lock();
  Vec self = asVec();
  // Prepare arguments
  Vec _cast_vec2 = vec2.asVec();
  // Call isl_vec_concat
  isl_vec * res =  isl_vec_concat((self).Give(), (_cast_vec2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_vec_concat returned a NULL pointer.");
  }
  return Vec(ctx, res);
}

inline Vec Vec::dropEls(unsigned int pos, unsigned int n) const {
  ctx.lock();
  Vec self = asVec();
  // Prepare arguments
  // Call isl_vec_drop_els
  isl_vec * res =  isl_vec_drop_els((self).Give(), pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_vec_drop_els returned a NULL pointer.");
  }
  return Vec(ctx, res);
}

inline Vec Vec::extend(unsigned int size) const {
  ctx.lock();
  Vec self = asVec();
  // Prepare arguments
  // Call isl_vec_extend
  isl_vec * res =  isl_vec_extend((self).Give(), size);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_vec_extend returned a NULL pointer.");
  }
  return Vec(ctx, res);
}

inline Val Vec::getElementVal(int pos) const {
  ctx.lock();
  Vec self = asVec();
  // Prepare arguments
  // Call isl_vec_get_element_val
  isl_val * res =  isl_vec_get_element_val((self).Get(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_vec_get_element_val returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Vec Vec::insertEls(unsigned int pos, unsigned int n) const {
  ctx.lock();
  Vec self = asVec();
  // Prepare arguments
  // Call isl_vec_insert_els
  isl_vec * res =  isl_vec_insert_els((self).Give(), pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_vec_insert_els returned a NULL pointer.");
  }
  return Vec(ctx, res);
}

inline Vec Vec::insertZeroEls(unsigned int pos, unsigned int n) const {
  ctx.lock();
  Vec self = asVec();
  // Prepare arguments
  // Call isl_vec_insert_zero_els
  isl_vec * res =  isl_vec_insert_zero_els((self).Give(), pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_vec_insert_zero_els returned a NULL pointer.");
  }
  return Vec(ctx, res);
}

inline Bool Vec::isEqual(const Vec &vec2) const {
  ctx.lock();
  Vec self = asVec();
  // Prepare arguments
  Vec _cast_vec2 = vec2.asVec();
  // Call isl_vec_is_equal
  isl_bool res =  isl_vec_is_equal((self).Get(), (_cast_vec2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Vec Vec::moveEls(unsigned int dst_col, unsigned int src_col, unsigned int n) const {
  ctx.lock();
  Vec self = asVec();
  // Prepare arguments
  // Call isl_vec_move_els
  isl_vec * res =  isl_vec_move_els((self).Give(), dst_col, src_col, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_vec_move_els returned a NULL pointer.");
  }
  return Vec(ctx, res);
}

inline Vec Vec::neg() const {
  ctx.lock();
  Vec self = asVec();
  // Prepare arguments
  // Call isl_vec_neg
  isl_vec * res =  isl_vec_neg((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_vec_neg returned a NULL pointer.");
  }
  return Vec(ctx, res);
}

inline Vec Vec::setElementVal(int pos, const Val &v) const {
  ctx.lock();
  Vec self = asVec();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_vec_set_element_val
  isl_vec * res =  isl_vec_set_element_val((self).Give(), pos, (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_vec_set_element_val returned a NULL pointer.");
  }
  return Vec(ctx, res);
}

inline Vec Vec::setVal(const Val &v) const {
  ctx.lock();
  Vec self = asVec();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_vec_set_val
  isl_vec * res =  isl_vec_set_val((self).Give(), (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_vec_set_val returned a NULL pointer.");
  }
  return Vec(ctx, res);
}

inline int Vec::size() const {
  ctx.lock();
  Vec self = asVec();
  // Prepare arguments
  // Call isl_vec_size
  int res =  isl_vec_size((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Vec Vec::sort() const {
  ctx.lock();
  Vec self = asVec();
  // Prepare arguments
  // Call isl_vec_sort
  isl_vec * res =  isl_vec_sort((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_vec_sort returned a NULL pointer.");
  }
  return Vec(ctx, res);
}

inline Vec Vec::zeroExtend(unsigned int size) const {
  ctx.lock();
  Vec self = asVec();
  // Prepare arguments
  // Call isl_vec_zero_extend
  isl_vec * res =  isl_vec_zero_extend((self).Give(), size);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_vec_zero_extend returned a NULL pointer.");
  }
  return Vec(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_Vec_IMPL_H
