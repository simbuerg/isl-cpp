#ifndef ISL_CXX_UnionPwQpolynomial_H
#define ISL_CXX_UnionPwQpolynomial_H


#include "isl/polynomial.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/Fold.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/polynomial.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class Point;
class PwQpolynomial;
class Set;
class Space;
class UnionPwQpolynomialFold;
class UnionSet;
class Val;

class UnionPwQpolynomial {
protected:
  Ctx ctx;
  void * This;
public:
  explicit UnionPwQpolynomial(Ctx ctx, isl_union_pw_qpolynomial *That) : ctx(ctx), This(That) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_union_pw_qpolynomial *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_union_pw_qpolynomial *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_union_pw_qpolynomial *Get() const;


  /// \brief Constructor for isl_union_pw_qpolynomial_from_pw_qpolynomial
  ///
  /// \param pwqp
  static UnionPwQpolynomial fromPwQpolynomial(const PwQpolynomial &pwqp);


  /// \brief Constructor for isl_union_pw_qpolynomial_zero
  ///
  /// \param dim
  static UnionPwQpolynomial zero(const Space &dim);


  /// \brief Constructor for isl_union_pw_qpolynomial_read_from_str
  ///
  /// \param ctx
  /// \param str
  static UnionPwQpolynomial readFromStr(const Ctx &ctx, std::string str);
public:
  virtual ~UnionPwQpolynomial();
  /// \brief Generated from  ::<isl_union_pw_qpolynomial_add>
  ///
  /// \param [in] upwqp2
  ///
  /// \returns A new UnionPwQpolynomial
  UnionPwQpolynomial add(const UnionPwQpolynomial &upwqp2) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_add_pw_qpolynomial>
  ///
  /// \param [in] pwqp
  ///
  /// \returns A new UnionPwQpolynomial
  UnionPwQpolynomial addPwQpolynomial(const PwQpolynomial &pwqp) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_align_params>
  ///
  /// \param [in] model
  ///
  /// \returns A new UnionPwQpolynomial
  UnionPwQpolynomial alignParams(const Space &model) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_bound>
  ///
  /// \param [in] type
  /// \param [in] tight
  ///
  /// \returns A new UnionPwQpolynomialFold
  UnionPwQpolynomialFold bound(Fold type, int * tight) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_coalesce>
  ///
  ///
  /// \returns A new UnionPwQpolynomial
  UnionPwQpolynomial coalesce() const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_domain>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet domain() const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_eval>
  ///
  /// \param [in] pnt
  ///
  /// \returns A new Val
  Val eval(const Point &pnt) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_extract_pw_qpolynomial>
  ///
  /// \param [in] dim
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial extractPwQpolynomial(const Space &dim) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_foreach_pw_qpolynomial>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachPwQpolynomial(const std::function<isl_stat(isl_pw_qpolynomial *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_gist>
  ///
  /// \param [in] context
  ///
  /// \returns A new UnionPwQpolynomial
  UnionPwQpolynomial gist(const UnionSet &context) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_gist_params>
  ///
  /// \param [in] context
  ///
  /// \returns A new UnionPwQpolynomial
  UnionPwQpolynomial gistParams(const Set &context) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_intersect_domain>
  ///
  /// \param [in] uset
  ///
  /// \returns A new UnionPwQpolynomial
  UnionPwQpolynomial intersectDomain(const UnionSet &uset) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_intersect_params>
  ///
  /// \param [in] set
  ///
  /// \returns A new UnionPwQpolynomial
  UnionPwQpolynomial intersectParams(const Set &set) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_mul>
  ///
  /// \param [in] upwqp2
  ///
  /// \returns A new UnionPwQpolynomial
  UnionPwQpolynomial mul(const UnionPwQpolynomial &upwqp2) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_plain_is_equal>
  ///
  /// \param [in] upwqp2
  ///
  /// \returns A new Bool
  Bool plainIsEqual(const UnionPwQpolynomial &upwqp2) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_scale_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new UnionPwQpolynomial
  UnionPwQpolynomial scaleVal(const Val &v) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_sub>
  ///
  /// \param [in] upwqp2
  ///
  /// \returns A new UnionPwQpolynomial
  UnionPwQpolynomial sub(const UnionPwQpolynomial &upwqp2) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_to_polynomial>
  ///
  /// \param [in] sign
  ///
  /// \returns A new UnionPwQpolynomial
  UnionPwQpolynomial toPolynomial(int sign) const;

  UnionPwQpolynomial(const UnionPwQpolynomial &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  UnionPwQpolynomial &operator=(const UnionPwQpolynomial &Other);
  UnionPwQpolynomial (UnionPwQpolynomial && Other) : ctx(Other.Context()), This(Other.This) {}
  UnionPwQpolynomial &operator=(UnionPwQpolynomial && Other) {
    isl_union_pw_qpolynomial *New = Other.Give();
    isl_union_pw_qpolynomial_free((isl_union_pw_qpolynomial *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const UnionPwQpolynomial &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_UnionPwQpolynomial_H
