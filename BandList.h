#ifndef ISL_CXX_BandList_H
#define ISL_CXX_BandList_H


#include "isl/band.h"
#include "isl/Ctx.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/band.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class Band;

class BandList {
protected:
  Ctx ctx;
  void * This;
public:
  explicit BandList(Ctx ctx, isl_band_list *That) : ctx(ctx), This(That) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_band_list *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_band_list *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_band_list *Get() const;


  /// \brief Constructor for isl_band_list_alloc
  ///
  /// \param ctx
  /// \param n
  static BandList alloc(const Ctx &ctx, int n);
public:
  virtual ~BandList();
  /// \brief Generated from  ::<isl_band_list_add>
  ///
  /// \param [in] el
  ///
  /// \returns A new BandList
  BandList add(const Band &el) const;

  /// \brief Generated from  ::<isl_band_list_foreach_band>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new int
  int foreachBand(const std::function<int(isl_band *, void *)> && fn, void * user) const;

  BandList(const BandList &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  BandList &operator=(const BandList &Other);
  BandList (BandList && Other) : ctx(Other.Context()), This(Other.This) {}
  BandList &operator=(BandList && Other) {
    isl_band_list *New = Other.Give();
    isl_band_list_free((isl_band_list *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const BandList &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_BandList_H
