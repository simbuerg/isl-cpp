#ifndef ISL_CXX_AffList_H
#define ISL_CXX_AffList_H


#include "isl/aff.h"
#include "isl/Ctx.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class Aff;

class AffList {
protected:
  Ctx ctx;
  void * This;
public:
  explicit AffList(Ctx ctx, isl_aff_list *That) : ctx(ctx), This(That) {}
  AffList() : ctx(Ctx(nullptr)), This(nullptr) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_aff_list *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_aff_list *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_aff_list *Get() const;


  /// \brief Constructor for isl_aff_list_alloc
  ///
  /// \param ctx
  /// \param n
  static AffList alloc(const Ctx &ctx, int n);
public:
  virtual ~AffList();
  /// \brief Generated from  ::<isl_aff_list_add>
  ///
  /// \param [in] el
  ///
  /// \returns A new AffList
  AffList add(const Aff &el) const;

  AffList(const AffList &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  AffList &operator=(const AffList &Other);
  AffList (AffList && Other) : ctx(Other.Context()), This(Other.Give()) {}
  AffList &operator=(AffList && Other) {
    isl_aff_list *New = Other.Give();
    isl_aff_list_free((isl_aff_list *)This);
    This = New;
    ctx = Other.Context();
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const AffList &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_AffList_H
