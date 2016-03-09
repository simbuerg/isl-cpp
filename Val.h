#ifndef ISL_CXX_Val_H
#define ISL_CXX_Val_H


#include "isl/val.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/MultiVal.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {

class Val {
protected:
  Ctx ctx;
  void * This;
public:
  explicit Val(Ctx ctx, isl_val *That) : ctx(ctx), This(That) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_val *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_val *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_val *Get() const;


  /// \brief Constructor for isl_val_zero
  ///
  /// \param ctx
  static Val zero(const Ctx &ctx);


  /// \brief Constructor for isl_val_one
  ///
  /// \param ctx
  static Val one(const Ctx &ctx);


  /// \brief Constructor for isl_val_negone
  ///
  /// \param ctx
  static Val negone(const Ctx &ctx);


  /// \brief Constructor for isl_val_nan
  ///
  /// \param ctx
  static Val nan(const Ctx &ctx);


  /// \brief Constructor for isl_val_infty
  ///
  /// \param ctx
  static Val infty(const Ctx &ctx);


  /// \brief Constructor for isl_val_neginfty
  ///
  /// \param ctx
  static Val neginfty(const Ctx &ctx);


  /// \brief Constructor for isl_val_int_from_si
  ///
  /// \param ctx
  /// \param i
  static Val intFromSi(const Ctx &ctx, long i);


  /// \brief Constructor for isl_val_int_from_ui
  ///
  /// \param ctx
  /// \param u
  static Val intFromUi(const Ctx &ctx, unsigned long u);


  /// \brief Constructor for isl_val_int_from_chunks
  ///
  /// \param ctx
  /// \param n
  /// \param size
  /// \param chunks
  static Val intFromChunks(const Ctx &ctx, size_t n, size_t size, const void * chunks);


  /// \brief Constructor for isl_val_read_from_str
  ///
  /// \param ctx
  /// \param str
  static Val readFromStr(const Ctx &ctx, std::string str);
public:
  virtual ~Val();
  /// \brief Generated from  ::<isl_val_abs>
  ///
  ///
  /// \returns A new Val
  Val abs() const;

  /// \brief Generated from  ::<isl_val_abs_eq>
  ///
  /// \param [in] v2
  ///
  /// \returns A new Bool
  Bool absEq(const Val &v2) const;

  /// \brief Generated from  ::<isl_val_add>
  ///
  /// \param [in] v2
  ///
  /// \returns A new Val
  Val add(const Val &v2) const;

  /// \brief Generated from  ::<isl_val_ceil>
  ///
  ///
  /// \returns A new Val
  Val ceil() const;

  /// \brief Generated from  ::<isl_val_div>
  ///
  /// \param [in] v2
  ///
  /// \returns A new Val
  Val div(const Val &v2) const;

  /// \brief Generated from  ::<isl_val_eq>
  ///
  /// \param [in] v2
  ///
  /// \returns A new Bool
  Bool eq(const Val &v2) const;

  /// \brief Generated from  ::<isl_val_floor>
  ///
  ///
  /// \returns A new Val
  Val floor() const;

  /// \brief Generated from  ::<isl_val_gcd>
  ///
  /// \param [in] v2
  ///
  /// \returns A new Val
  Val gcd(const Val &v2) const;

  /// \brief Generated from  ::<isl_val_ge>
  ///
  /// \param [in] v2
  ///
  /// \returns A new Bool
  Bool ge(const Val &v2) const;

  /// \brief Generated from  ::<isl_val_gt>
  ///
  /// \param [in] v2
  ///
  /// \returns A new Bool
  Bool gt(const Val &v2) const;

  /// \brief Generated from  ::<isl_val_is_divisible_by>
  ///
  /// \param [in] v2
  ///
  /// \returns A new Bool
  Bool isDivisibleBy(const Val &v2) const;

  /// \brief Generated from  ::<isl_val_is_infty>
  ///
  ///
  /// \returns A new int
  int isInfty() const;

  /// \brief Generated from  ::<isl_val_is_int>
  ///
  ///
  /// \returns A new int
  int isInt() const;

  /// \brief Generated from  ::<isl_val_is_nan>
  ///
  ///
  /// \returns A new int
  int isNan() const;

  /// \brief Generated from  ::<isl_val_is_neg>
  ///
  ///
  /// \returns A new int
  int isNeg() const;

  /// \brief Generated from  ::<isl_val_is_neginfty>
  ///
  ///
  /// \returns A new int
  int isNeginfty() const;

  /// \brief Generated from  ::<isl_val_is_negone>
  ///
  ///
  /// \returns A new int
  int isNegone() const;

  /// \brief Generated from  ::<isl_val_is_nonneg>
  ///
  ///
  /// \returns A new int
  int isNonneg() const;

  /// \brief Generated from  ::<isl_val_is_nonpos>
  ///
  ///
  /// \returns A new int
  int isNonpos() const;

  /// \brief Generated from  ::<isl_val_is_one>
  ///
  ///
  /// \returns A new int
  int isOne() const;

  /// \brief Generated from  ::<isl_val_is_pos>
  ///
  ///
  /// \returns A new int
  int isPos() const;

  /// \brief Generated from  ::<isl_val_is_rat>
  ///
  ///
  /// \returns A new int
  int isRat() const;

  /// \brief Generated from  ::<isl_val_is_zero>
  ///
  ///
  /// \returns A new int
  int isZero() const;

  /// \brief Generated from  ::<isl_val_le>
  ///
  /// \param [in] v2
  ///
  /// \returns A new Bool
  Bool le(const Val &v2) const;

  /// \brief Generated from  ::<isl_val_lt>
  ///
  /// \param [in] v2
  ///
  /// \returns A new Bool
  Bool lt(const Val &v2) const;

  /// \brief Generated from  ::<isl_val_max>
  ///
  /// \param [in] v2
  ///
  /// \returns A new Val
  Val max(const Val &v2) const;

  /// \brief Generated from  ::<isl_val_min>
  ///
  /// \param [in] v2
  ///
  /// \returns A new Val
  Val min(const Val &v2) const;

  /// \brief Generated from  ::<isl_val_mod>
  ///
  /// \param [in] v2
  ///
  /// \returns A new Val
  Val mod(const Val &v2) const;

  /// \brief Generated from  ::<isl_val_mul>
  ///
  /// \param [in] v2
  ///
  /// \returns A new Val
  Val mul(const Val &v2) const;

  /// \brief Generated from  ::<isl_val_mul_ui>
  ///
  /// \param [in] v2
  ///
  /// \returns A new Val
  Val mulUi(unsigned long v2) const;

  /// \brief Generated from  ::<isl_val_ne>
  ///
  /// \param [in] v2
  ///
  /// \returns A new Bool
  Bool ne(const Val &v2) const;

  /// \brief Generated from  ::<isl_val_neg>
  ///
  ///
  /// \returns A new Val
  Val neg() const;

  /// \brief Generated from  ::<isl_val_sgn>
  ///
  ///
  /// \returns A new int
  int sgn() const;

  /// \brief Generated from  ::<isl_val_sub>
  ///
  /// \param [in] v2
  ///
  /// \returns A new Val
  Val sub(const Val &v2) const;

  /// \brief Generated from  ::<isl_val_trunc>
  ///
  ///
  /// \returns A new Val
  Val trunc() const;

  Val(const Val &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  Val &operator=(const Val &Other);
  Val (Val && Other) : ctx(Other.Context()), This(Other.This) {}
  Val &operator=(Val && Other) {
    isl_val *New = Other.Give();
    isl_val_free((isl_val *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const Val &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_Val_H
