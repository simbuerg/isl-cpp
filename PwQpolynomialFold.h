#ifndef ISL_CXX_PwQpolynomialFold_H
#define ISL_CXX_PwQpolynomialFold_H


#include "isl/polynomial.h"
#include "isl/Bool.h"
#include "isl/DimType.h"
#include "isl/Fold.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/polynomial.h"
#include "isl/set.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class Point;
class PwQpolynomial;
class QpolynomialFold;
class Set;
class Space;
class Val;

class PwQpolynomialFold {
protected:
  Ctx ctx;
  void * This;
public:
  explicit PwQpolynomialFold(Ctx ctx, isl_pw_qpolynomial_fold *That) : ctx(ctx), This(That) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_pw_qpolynomial_fold *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_pw_qpolynomial_fold *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_pw_qpolynomial_fold *Get() const;


  /// \brief Constructor for isl_pw_qpolynomial_fold_from_pw_qpolynomial
  ///
  /// \param type
  /// \param pwqp
  static PwQpolynomialFold fromPwQpolynomial(Fold type, const PwQpolynomial &pwqp);


  /// \brief Constructor for isl_pw_qpolynomial_fold_alloc
  ///
  /// \param type
  /// \param set
  /// \param fold
  static PwQpolynomialFold alloc(Fold type, const Set &set, const QpolynomialFold &fold);


  /// \brief Constructor for isl_pw_qpolynomial_fold_zero
  ///
  /// \param dim
  /// \param type
  static PwQpolynomialFold zero(const Space &dim, Fold type);
public:
  virtual ~PwQpolynomialFold();
  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_add>
  ///
  /// \param [in] pwf2
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold add(const PwQpolynomialFold &pwf2) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_add_disjoint>
  ///
  /// \param [in] pwf2
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold addDisjoint(const PwQpolynomialFold &pwf2) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_bound>
  ///
  /// \param [in] tight
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold bound(int * tight) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_coalesce>
  ///
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold coalesce() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_dim>
  ///
  /// \param [in] type
  ///
  /// \returns A new unsigned int
  unsigned int dim(DimType type) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_domain>
  ///
  ///
  /// \returns A new Set
  Set domain() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_drop_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold dropDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_eval>
  ///
  /// \param [in] pnt
  ///
  /// \returns A new Val
  Val eval(const Point &pnt) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_fold>
  ///
  /// \param [in] pwf2
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold fold(const PwQpolynomialFold &pwf2) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_foreach_lifted_piece>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachLiftedPiece(const std::function<isl_stat(isl_set *, isl_qpolynomial_fold *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_foreach_piece>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachPiece(const std::function<isl_stat(isl_set *, isl_qpolynomial_fold *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_get_domain_space>
  ///
  ///
  /// \returns A new Space
  Space getDomainSpace() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_gist>
  ///
  /// \param [in] context
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold gist(const Set &context) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_gist_params>
  ///
  /// \param [in] context
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold gistParams(const Set &context) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_has_equal_space>
  ///
  /// \param [in] pwf2
  ///
  /// \returns A new int
  int hasEqualSpace(const PwQpolynomialFold &pwf2) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_intersect_domain>
  ///
  /// \param [in] set
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold intersectDomain(const Set &set) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_intersect_params>
  ///
  /// \param [in] set
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold intersectParams(const Set &set) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_is_zero>
  ///
  ///
  /// \returns A new Bool
  Bool isZero() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_max>
  ///
  ///
  /// \returns A new Val
  Val max() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_min>
  ///
  ///
  /// \returns A new Val
  Val min() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_move_dims>
  ///
  /// \param [in] dst_type
  /// \param [in] dst_pos
  /// \param [in] src_type
  /// \param [in] src_pos
  /// \param [in] n
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_plain_is_equal>
  ///
  /// \param [in] pwf2
  ///
  /// \returns A new Bool
  Bool plainIsEqual(const PwQpolynomialFold &pwf2) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_project_domain_on_params>
  ///
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold projectDomainOnParams() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_reset_space>
  ///
  /// \param [in] dim
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold resetSpace(const Space &dim) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_scale_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold scaleVal(const Val &v) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_set_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] s
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold setDimName(DimType type, unsigned int pos, std::string s) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fold_size>
  ///
  ///
  /// \returns A new size_t
  size_t size() const;

  PwQpolynomialFold(const PwQpolynomialFold &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  PwQpolynomialFold &operator=(const PwQpolynomialFold &Other);
  PwQpolynomialFold (PwQpolynomialFold && Other) : ctx(Other.Context()), This(Other.This) {}
  PwQpolynomialFold &operator=(PwQpolynomialFold && Other) {
    isl_pw_qpolynomial_fold *New = Other.Give();
    isl_pw_qpolynomial_fold_free((isl_pw_qpolynomial_fold *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const PwQpolynomialFold &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_PwQpolynomialFold_H
