#ifndef ISL_CXX_UnionSetList_H
#define ISL_CXX_UnionSetList_H


#include "isl/union_set.h"
#include "isl/Ctx.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class UnionSet;

class UnionSetList {
protected:
  Ctx ctx;
  void * This;
public:
  explicit UnionSetList(Ctx ctx, isl_union_set_list *That) : ctx(ctx), This(That) {}
  UnionSetList() : ctx(Ctx(nullptr)), This(nullptr) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_union_set_list *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_union_set_list *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_union_set_list *Get() const;


  /// \brief Constructor for isl_union_set_list_alloc
  ///
  /// \param ctx
  /// \param n
  static UnionSetList alloc(const Ctx &ctx, int n);
public:
  virtual ~UnionSetList();
  /// \brief Generated from  ::<isl_union_set_list_add>
  ///
  /// \param [in] el
  ///
  /// \returns A new UnionSetList
  UnionSetList add(const UnionSet &el) const;

  UnionSetList(const UnionSetList &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  UnionSetList &operator=(const UnionSetList &Other);
  UnionSetList (UnionSetList && Other) : ctx(Other.Context()), This(Other.Give()) {}
  UnionSetList &operator=(UnionSetList && Other) {
    isl_union_set_list *New = Other.Give();
    isl_union_set_list_free((isl_union_set_list *)This);
    This = New;
    ctx = Other.Context();
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const UnionSetList &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_UnionSetList_H
