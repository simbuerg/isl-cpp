#ifndef ISL_CXX_ConstraintList_H
#define ISL_CXX_ConstraintList_H


#include "isl/constraint.h"
#include "isl/Ctx.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Constraint;

class ConstraintList {
protected:
  Ctx ctx;
  void * This;
  explicit ConstraintList(Ctx ctx, isl_constraint_list *That) : ctx(ctx), This((void *)That) {}
  explicit ConstraintList(Ctx ctx, void *That) : ctx(ctx), This(That) {}

public:
  const Ctx &Context() const { return ctx; }
  ///rief Wrap an existing isl object.
  ///
  /// This serves as an entry point into the C++ API.
  /// We take ownership of the isl object.
  ///
  /// \param That the isl_constraint_list we want to wrap.
  explicit ConstraintList(isl_constraint_list *That) : ConstraintList(Ctx(isl_constraint_list_get_ctx(That)), That) {}
  isl_constraint_list *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_constraint_list *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_constraint_list *Get() const;

  /// \brief Constructor for isl_constraint_list_alloc
  ///
  /// \param ctx
  /// \param n
  static ConstraintList alloc(const Ctx &ctx, int n);
  virtual ~ConstraintList();

  virtual ConstraintList asConstraintList() const;

  /// \brief Generated from  ::<isl_constraint_list_add>
  ///
  /// \param [in] el
  ///
  /// \returns A new ConstraintList
  ConstraintList add(const Constraint &el) const;
  ConstraintList(const ConstraintList &Other) : ConstraintList(Other.Context(), Other.GetCopy()) {}
  ConstraintList &operator=(const ConstraintList &Other);
  ConstraintList (ConstraintList && Other) : ConstraintList(Other.Context(), Other.This) {}
  ConstraintList &operator=(ConstraintList && Other) {
    isl_constraint_list *New = Other.Give();
    isl_constraint_list_free((isl_constraint_list *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const ConstraintList &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_ConstraintList_H
