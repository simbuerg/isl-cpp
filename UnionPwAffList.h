#ifndef ISL_CXX_UnionPwAffList_H
#define ISL_CXX_UnionPwAffList_H


#include "isl/aff.h"
#include "isl/Ctx.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class UnionPwAff;

class UnionPwAffList {
protected:

public:
  Ctx ctx;
  void * This;
  explicit UnionPwAffList(Ctx ctx, isl_union_pw_aff_list *That) : ctx(ctx), This((void *)That) {}
  explicit UnionPwAffList(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_union_pw_aff_list *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_union_pw_aff_list *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_union_pw_aff_list *Get() const;

  /// \brief Constructor for isl_union_pw_aff_list_alloc
  ///
  /// \param ctx
  /// \param n
  static UnionPwAffList alloc(const Ctx &ctx, int n);
  virtual ~UnionPwAffList();

  virtual UnionPwAffList asUnionPwAffList() const;

  /// \brief Generated from  ::<isl_union_pw_aff_list_add>
  ///
  /// \param [in] el
  ///
  /// \returns A new UnionPwAffList
  UnionPwAffList add(const UnionPwAff &el) const;
  UnionPwAffList(const UnionPwAffList &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  UnionPwAffList &operator=(const UnionPwAffList &Other);
  UnionPwAffList (UnionPwAffList && Other) : ctx(Other.Context()), This(Other.This) {}
  UnionPwAffList &operator=(UnionPwAffList && Other) {
    isl_union_pw_aff_list *New = Other.Give();
    isl_union_pw_aff_list_free((isl_union_pw_aff_list *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const UnionPwAffList &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_UnionPwAffList_H
