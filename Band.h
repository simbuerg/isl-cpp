#ifndef ISL_CXX_Band_H
#define ISL_CXX_Band_H


#include "isl/band.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Printer;
class UnionMap;
class Vec;

class Band {
protected:
  Ctx ctx;
  void * This;
  explicit Band(Ctx ctx, isl_band *That) : ctx(ctx), This((void *)That) {}
  explicit Band(Ctx ctx, void *That) : ctx(ctx), This(That) {}

public:
  const Ctx &Context() const { return ctx; }
  ///rief Wrap an existing isl object.
  ///
  /// This serves as an entry point into the C++ API.
  /// We take ownership of the isl object.
  ///
  /// \param That the isl_band we want to wrap.
  explicit Band(isl_band *That) : Band(Ctx(isl_band_get_ctx(That)), That) {}
  isl_band *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_band *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_band *Get() const;

  virtual ~Band() = default;
  std::string toStr(isl::Format F = isl::Format::FIsl) const;

  virtual Band asBand() const;

  /// \brief Generated from  ::<isl_band_get_partial_schedule>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap getPartialSchedule() const;

  /// \brief Generated from  ::<isl_band_get_prefix_schedule>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap getPrefixSchedule() const;

  /// \brief Generated from  ::<isl_band_get_suffix_schedule>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap getSuffixSchedule() const;

  /// \brief Generated from  ::<isl_band_split>
  ///
  /// \param [in] pos
  ///
  /// \returns A new int
  int split(int pos) const;

  /// \brief Generated from  ::<isl_band_tile>
  ///
  /// \param [in] sizes
  ///
  /// \returns A new int
  int tile(const Vec &sizes) const;
  Band(const Band &Other) : Band(Other.Context(), Other.GetCopy()) {}
  Band &operator=(const Band &Other);
  Band (Band && Other) : Band(Other.Context(), Other.This) {}
  Band &operator=(Band && Other) {
    isl_band *New = Other.Give();
    isl_band_free((isl_band *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const Band &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_Band_H
