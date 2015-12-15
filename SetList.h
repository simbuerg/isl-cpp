#ifndef ISL_CXX_SetList_H
#define ISL_CXX_SetList_H


#include "isl/set.h"
#include "isl/Ctx.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Set;

class SetList {
protected:
  Ctx ctx;
  void * This;
  explicit SetList(Ctx ctx, isl_set_list *That) : ctx(ctx), This((void *)That) {}
  explicit SetList(Ctx ctx, void *That) : ctx(ctx), This(That) {}

public:
  const Ctx &Context() const { return ctx; }
  ///rief Wrap an existing isl object.
  ///
  /// This serves as an entry point into the C++ API.
  /// We take ownership of the isl object.
  ///
  /// \param That the isl_set_list we want to wrap.
  explicit SetList(isl_set_list *That) : SetList(Ctx(isl_set_list_get_ctx(That)), That) {}
  isl_set_list *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_set_list *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_set_list *Get() const;

  /// \brief Constructor for isl_set_list_alloc
  ///
  /// \param ctx
  /// \param n
  static SetList alloc(const Ctx &ctx, int n);
  virtual ~SetList();

  virtual SetList asSetList() const;

  /// \brief Generated from  ::<isl_set_list_add>
  ///
  /// \param [in] el
  ///
  /// \returns A new SetList
  SetList add(const Set &el) const;
  SetList(const SetList &Other) : SetList(Other.Context(), Other.GetCopy()) {}
  SetList &operator=(const SetList &Other);
  SetList (SetList && Other) : SetList(Other.Context(), Other.This) {}
  SetList &operator=(SetList && Other) {
    isl_set_list *New = Other.Give();
    isl_set_list_free((isl_set_list *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const SetList &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_SetList_H
