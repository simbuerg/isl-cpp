#ifndef ISL_CXX_Id_H
#define ISL_CXX_Id_H


#include "isl/id.h"
#include "isl/Ctx.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Printer;

class Id {
protected:
  Ctx ctx;
  void * This;
  explicit Id(Ctx ctx, isl_id *That) : ctx(ctx), This((void *)That) {}
  explicit Id(Ctx ctx, void *That) : ctx(ctx), This(That) {}

public:
  const Ctx &Context() const { return ctx; }
  ///rief Wrap an existing isl object.
  ///
  /// This serves as an entry point into the C++ API.
  /// We take ownership of the isl object.
  ///
  /// \param That the isl_id we want to wrap.
  explicit Id(isl_id *That) : Id(Ctx(isl_id_get_ctx(That)), That) {}
  isl_id *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_id *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_id *Get() const;

  /// \brief Constructor for isl_id_alloc
  ///
  /// \param ctx
  /// \param name
  /// \param user
  static Id alloc(const Ctx &ctx, std::string name, void * user);
  virtual ~Id();
  std::string toStr(isl::Format F = isl::Format::FIsl) const;

  virtual Id asId() const;

  /// \brief Generated from  ::<isl_id_get_name>
  ///
  ///
  /// \returns A new std::string
  std::string getName() const;
  Id(const Id &Other) : Id(Other.Context(), Other.GetCopy()) {}
  Id &operator=(const Id &Other);
  Id (Id && Other) : Id(Other.Context(), Other.This) {}
  Id &operator=(Id && Other) {
    isl_id *New = Other.Give();
    isl_id_free((isl_id *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const Id &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_Id_H
