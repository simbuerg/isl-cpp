#ifndef ISL_CXX_Mat_IMPL_H
#define ISL_CXX_Mat_IMPL_H

#include "isl/Mat.h"

#include "isl/Val.hpp"
#include "isl/Vec.hpp"
#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_mat *Mat::GetCopy() const {
  return isl_mat_copy((isl_mat *)This);
}
inline Mat &Mat::operator=(const Mat &Other) {
  isl_mat *New = Other.GetCopy();
  isl_mat_free((isl_mat *)This);
  This = New;
  return *this;
}
inline Mat Mat::alloc(const Ctx &ctx, unsigned int n_row, unsigned int n_col) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_mat *That = isl_mat_alloc((ctx.Get()), n_row, n_col);
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_mat_alloc returned a NULL pointer.");
  }

  return Mat(_ctx, That);
}

inline Mat Mat::fromRowVec(const Vec &vec) {
  const Ctx &_ctx = vec.Context();
  _ctx.lock();
  Vec _cast_vec = vec.asVec();
  isl_mat *That = isl_mat_from_row_vec((_cast_vec).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_mat_from_row_vec returned a NULL pointer.");
  }

  return Mat(_ctx, That);
}
inline Mat::~Mat() {
  isl_mat_free((isl_mat *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_mat *Mat::Give() {
  isl_mat *res = (isl_mat *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_mat *Mat::Get() const {  return (isl_mat *)This;
}

inline Mat Mat::asMat() const {
  return Mat(ctx, GetCopy());
}

inline Mat Mat::addRows(unsigned int n) const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  // Call isl_mat_add_rows
  isl_mat * res =  isl_mat_add_rows((self).Give(), n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_mat_add_rows returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline Mat Mat::addZeroCols(unsigned int n) const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  // Call isl_mat_add_zero_cols
  isl_mat * res =  isl_mat_add_zero_cols((self).Give(), n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_mat_add_zero_cols returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline Mat Mat::addZeroRows(unsigned int n) const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  // Call isl_mat_add_zero_rows
  isl_mat * res =  isl_mat_add_zero_rows((self).Give(), n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_mat_add_zero_rows returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline int Mat::cols() const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  // Call isl_mat_cols
  int res =  isl_mat_cols((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Mat Mat::concat(const Mat &bot) const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  Mat _cast_bot = bot.asMat();
  // Call isl_mat_concat
  isl_mat * res =  isl_mat_concat((self).Give(), (_cast_bot).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_mat_concat returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline Val Mat::getElementVal(int row, int col) const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  // Call isl_mat_get_element_val
  isl_val * res =  isl_mat_get_element_val((self).Get(), row, col);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_mat_get_element_val returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline int Mat::initialNonZeroCols() const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  // Call isl_mat_initial_non_zero_cols
  int res =  isl_mat_initial_non_zero_cols((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Mat Mat::insertCols(unsigned int col, unsigned int n) const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  // Call isl_mat_insert_cols
  isl_mat * res =  isl_mat_insert_cols((self).Give(), col, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_mat_insert_cols returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline Mat Mat::insertRows(unsigned int row, unsigned int n) const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  // Call isl_mat_insert_rows
  isl_mat * res =  isl_mat_insert_rows((self).Give(), row, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_mat_insert_rows returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline Mat Mat::insertZeroCols(unsigned int first, unsigned int n) const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  // Call isl_mat_insert_zero_cols
  isl_mat * res =  isl_mat_insert_zero_cols((self).Give(), first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_mat_insert_zero_cols returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline Mat Mat::insertZeroRows(unsigned int row, unsigned int n) const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  // Call isl_mat_insert_zero_rows
  isl_mat * res =  isl_mat_insert_zero_rows((self).Give(), row, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_mat_insert_zero_rows returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline int Mat::isEqual(const Mat &mat2) const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  Mat _cast_mat2 = mat2.asMat();
  // Call isl_mat_is_equal
  int res =  isl_mat_is_equal((self).Get(), (_cast_mat2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Mat Mat::moveCols(unsigned int dst_col, unsigned int src_col, unsigned int n) const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  // Call isl_mat_move_cols
  isl_mat * res =  isl_mat_move_cols((self).Give(), dst_col, src_col, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_mat_move_cols returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline Mat Mat::normalize() const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  // Call isl_mat_normalize
  isl_mat * res =  isl_mat_normalize((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_mat_normalize returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline Mat Mat::normalizeRow(int row) const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  // Call isl_mat_normalize_row
  isl_mat * res =  isl_mat_normalize_row((self).Give(), row);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_mat_normalize_row returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline Mat Mat::rightInverse() const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  // Call isl_mat_right_inverse
  isl_mat * res =  isl_mat_right_inverse((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_mat_right_inverse returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline Mat Mat::rightKernel() const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  // Call isl_mat_right_kernel
  isl_mat * res =  isl_mat_right_kernel((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_mat_right_kernel returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline int Mat::rows() const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  // Call isl_mat_rows
  int res =  isl_mat_rows((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Mat Mat::setElementVal(int row, int col, const Val &v) const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_mat_set_element_val
  isl_mat * res =  isl_mat_set_element_val((self).Give(), row, col, (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_mat_set_element_val returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline Mat Mat::vecConcat(const Vec &bot) const {
  ctx.lock();
  Mat self = asMat();
  // Prepare arguments
  Vec _cast_bot = bot.asVec();
  // Call isl_mat_vec_concat
  isl_mat * res =  isl_mat_vec_concat((self).Give(), (_cast_bot).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_mat_vec_concat returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_Mat_IMPL_H
