#ifndef ISL_CXX_ConstraintList_IMPL_H
#define ISL_CXX_ConstraintList_IMPL_H

#include "isl/ConstraintList.h"

#include "isl/Constraint.hpp"
#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_constraint_list *ConstraintList::GetCopy() const {
  return isl_constraint_list_copy((isl_constraint_list *)This);
}
inline ConstraintList &ConstraintList::operator=(const ConstraintList &Other) {
  isl_constraint_list *New = Other.GetCopy();
  isl_constraint_list_free((isl_constraint_list *)This);
  This = New;
  return *this;
}
inline ConstraintList ConstraintList::alloc(const Ctx &ctx, int n) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_constraint_list *That = isl_constraint_list_alloc((ctx.Get()), n);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_constraint_list_alloc returned a NULL pointer.");
  }

  return ConstraintList(_ctx, That);
}
inline ConstraintList::~ConstraintList() {
  isl_constraint_list_free((isl_constraint_list *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_constraint_list *ConstraintList::Give() {
  isl_constraint_list *res = (isl_constraint_list *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_constraint_list *ConstraintList::Get() const {  return (isl_constraint_list *)This;
}

inline ConstraintList ConstraintList::add(const Constraint &el) const {
  ctx.lock();
  isl_constraint_list * res =  isl_constraint_list_add((*this).GetCopy(), (el).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_constraint_list_add returned a NULL pointer.");
  }
  return ConstraintList(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_ConstraintList_IMPL_H
