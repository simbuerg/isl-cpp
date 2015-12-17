#ifndef ISL_CXX_UnionPwQpolynomialFold_H
#define ISL_CXX_UnionPwQpolynomialFold_H


#include "isl/polynomial.h"
#include "isl/Bool.h"
#include "isl/Fold.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/polynomial.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Point;
class PwQpolynomialFold;
class Set;
class Space;
class UnionPwQpolynomial;
class UnionSet;
class Val;

class UnionPwQpolynomialFold {
protected:

public:
  Ctx ctx;
  void * This;
  explicit UnionPwQpolynomialFold(Ctx ctx, isl_union_pw_qpolynomial_fold *That) : ctx(ctx), This((void *)That) {}
  explicit UnionPwQpolynomialFold(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_union_pw_qpolynomial_fold *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_union_pw_qpolynomial_fold *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_union_pw_qpolynomial_fold *Get() const;

  /// \brief Constructor for isl_union_pw_qpolynomial_fold_from_pw_qpolynomial_fold
  ///
  /// \param pwf
  static UnionPwQpolynomialFold fromPwQpolynomialFold(const PwQpolynomialFold &pwf);
  /// \brief Constructor for isl_union_pw_qpolynomial_fold_zero
  ///
  /// \param dim
  /// \param type
  static UnionPwQpolynomialFold zero(const Space &dim, Fold type);
  virtual ~UnionPwQpolynomialFold();

  virtual UnionPwQpolynomialFold asUnionPwQpolynomialFold() const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_fold_add_union_pw_qpolynomial>
  ///
  /// \param [in] upwqp
  ///
  /// \returns A new UnionPwQpolynomialFold
  UnionPwQpolynomialFold addUnionPwQpolynomial(const UnionPwQpolynomial &upwqp) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_fold_align_params>
  ///
  /// \param [in] model
  ///
  /// \returns A new UnionPwQpolynomialFold
  UnionPwQpolynomialFold alignParams(const Space &model) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_fold_coalesce>
  ///
  ///
  /// \returns A new UnionPwQpolynomialFold
  UnionPwQpolynomialFold coalesce() const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_fold_domain>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet domain() const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_fold_eval>
  ///
  /// \param [in] pnt
  ///
  /// \returns A new Val
  Val eval(const Point &pnt) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_fold_extract_pw_qpolynomial_fold>
  ///
  /// \param [in] dim
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold extractPwQpolynomialFold(const Space &dim) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_fold_fold>
  ///
  /// \param [in] upwf2
  ///
  /// \returns A new UnionPwQpolynomialFold
  UnionPwQpolynomialFold fold(const UnionPwQpolynomialFold &upwf2) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_fold_fold_pw_qpolynomial_fold>
  ///
  /// \param [in] pwqp
  ///
  /// \returns A new UnionPwQpolynomialFold
  UnionPwQpolynomialFold foldPwQpolynomialFold(const PwQpolynomialFold &pwqp) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_fold_foreach_pw_qpolynomial_fold>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachPwQpolynomialFold(const std::function<isl_stat(isl_pw_qpolynomial_fold *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_fold_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_fold_get_type>
  ///
  ///
  /// \returns A new Fold
  Fold getType() const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_fold_gist>
  ///
  /// \param [in] context
  ///
  /// \returns A new UnionPwQpolynomialFold
  UnionPwQpolynomialFold gist(const UnionSet &context) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_fold_gist_params>
  ///
  /// \param [in] context
  ///
  /// \returns A new UnionPwQpolynomialFold
  UnionPwQpolynomialFold gistParams(const Set &context) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_fold_intersect_domain>
  ///
  /// \param [in] uset
  ///
  /// \returns A new UnionPwQpolynomialFold
  UnionPwQpolynomialFold intersectDomain(const UnionSet &uset) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_fold_intersect_params>
  ///
  /// \param [in] set
  ///
  /// \returns A new UnionPwQpolynomialFold
  UnionPwQpolynomialFold intersectParams(const Set &set) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_fold_plain_is_equal>
  ///
  /// \param [in] upwf2
  ///
  /// \returns A new Bool
  Bool plainIsEqual(const UnionPwQpolynomialFold &upwf2) const;

  /// \brief Generated from  ::<isl_union_pw_qpolynomial_fold_scale_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new UnionPwQpolynomialFold
  UnionPwQpolynomialFold scaleVal(const Val &v) const;
  UnionPwQpolynomialFold(const UnionPwQpolynomialFold &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  UnionPwQpolynomialFold &operator=(const UnionPwQpolynomialFold &Other);
  UnionPwQpolynomialFold (UnionPwQpolynomialFold && Other) : ctx(Other.Context()), This(Other.This) {}
  UnionPwQpolynomialFold &operator=(UnionPwQpolynomialFold && Other) {
    isl_union_pw_qpolynomial_fold *New = Other.Give();
    isl_union_pw_qpolynomial_fold_free((isl_union_pw_qpolynomial_fold *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const UnionPwQpolynomialFold &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_UnionPwQpolynomialFold_H
