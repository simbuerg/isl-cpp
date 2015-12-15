#ifndef ISL_CXX_PwQpolynomial_H
#define ISL_CXX_PwQpolynomial_H


#include "isl/polynomial.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/DimType.h"
#include "isl/Fold.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/polynomial.h"
#include "isl/set.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Point;
class Printer;
class PwAff;
class PwQpolynomialFold;
class Qpolynomial;
class Set;
class Space;
class Val;

class PwQpolynomial {
protected:
  Ctx ctx;
  void * This;
  explicit PwQpolynomial(Ctx ctx, isl_pw_qpolynomial *That) : ctx(ctx), This((void *)That) {}
  explicit PwQpolynomial(Ctx ctx, void *That) : ctx(ctx), This(That) {}

public:
  const Ctx &Context() const { return ctx; }
  ///rief Wrap an existing isl object.
  ///
  /// This serves as an entry point into the C++ API.
  /// We take ownership of the isl object.
  ///
  /// \param That the isl_pw_qpolynomial we want to wrap.
  explicit PwQpolynomial(isl_pw_qpolynomial *That) : PwQpolynomial(Ctx(isl_pw_qpolynomial_get_ctx(That)), That) {}
  isl_pw_qpolynomial *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_pw_qpolynomial *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_pw_qpolynomial *Get() const;

  /// \brief Constructor for isl_pw_qpolynomial_zero
  ///
  /// \param dim
  static PwQpolynomial zero(const Space &dim);
  /// \brief Constructor for isl_pw_qpolynomial_alloc
  ///
  /// \param set
  /// \param qp
  static PwQpolynomial alloc(const Set &set, const Qpolynomial &qp);
  /// \brief Constructor for isl_pw_qpolynomial_from_qpolynomial
  ///
  /// \param qp
  static PwQpolynomial fromQpolynomial(const Qpolynomial &qp);
  /// \brief Constructor for isl_pw_qpolynomial_from_pw_aff
  ///
  /// \param pwaff
  static PwQpolynomial fromPwAff(const PwAff &pwaff);
  /// \brief Constructor for isl_pw_qpolynomial_read_from_str
  ///
  /// \param ctx
  /// \param str
  static PwQpolynomial readFromStr(const Ctx &ctx, std::string str);
  virtual ~PwQpolynomial();
  std::string toStr(isl::Format F = isl::Format::FIsl) const;

  virtual PwQpolynomial asPwQpolynomial() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_add>
  ///
  /// \param [in] pwqp2
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial add(const PwQpolynomial &pwqp2) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_add_dims>
  ///
  /// \param [in] type
  /// \param [in] n
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial addDims(DimType type, unsigned int n) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_add_disjoint>
  ///
  /// \param [in] pwqp2
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial addDisjoint(const PwQpolynomial &pwqp2) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_bound>
  ///
  /// \param [in] type
  /// \param [in] tight
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold bound(Fold type, int * tight) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_coalesce>
  ///
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial coalesce() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_dim>
  ///
  /// \param [in] type
  ///
  /// \returns A new unsigned int
  unsigned int dim(DimType type) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_domain>
  ///
  ///
  /// \returns A new Set
  Set domain() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_drop_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial dropDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_eval>
  ///
  /// \param [in] pnt
  ///
  /// \returns A new Val
  Val eval(const Point &pnt) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_fix_val>
  ///
  /// \param [in] type
  /// \param [in] n
  /// \param [in] v
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial fixVal(DimType type, unsigned int n, const Val &v) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_foreach_lifted_piece>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachLiftedPiece(const std::function<isl_stat(isl_set *, isl_qpolynomial *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_foreach_piece>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachPiece(const std::function<isl_stat(isl_set *, isl_qpolynomial *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_get_domain_space>
  ///
  ///
  /// \returns A new Space
  Space getDomainSpace() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_gist>
  ///
  /// \param [in] context
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial gist(const Set &context) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_gist_params>
  ///
  /// \param [in] context
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial gistParams(const Set &context) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_has_equal_space>
  ///
  /// \param [in] pwqp2
  ///
  /// \returns A new int
  int hasEqualSpace(const PwQpolynomial &pwqp2) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_insert_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial insertDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_intersect_domain>
  ///
  /// \param [in] set
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial intersectDomain(const Set &set) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_intersect_params>
  ///
  /// \param [in] set
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial intersectParams(const Set &set) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_involves_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Bool
  Bool involvesDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_is_zero>
  ///
  ///
  /// \returns A new Bool
  Bool isZero() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_max>
  ///
  ///
  /// \returns A new Val
  Val max() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_min>
  ///
  ///
  /// \returns A new Val
  Val min() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_move_dims>
  ///
  /// \param [in] dst_type
  /// \param [in] dst_pos
  /// \param [in] src_type
  /// \param [in] src_pos
  /// \param [in] n
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_mul>
  ///
  /// \param [in] pwqp2
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial mul(const PwQpolynomial &pwqp2) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_neg>
  ///
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial neg() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_plain_is_equal>
  ///
  /// \param [in] pwqp2
  ///
  /// \returns A new Bool
  Bool plainIsEqual(const PwQpolynomial &pwqp2) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_pow>
  ///
  /// \param [in] exponent
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial pow(unsigned int exponent) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_project_domain_on_params>
  ///
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial projectDomainOnParams() const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_reset_domain_space>
  ///
  /// \param [in] dim
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial resetDomainSpace(const Space &dim) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_scale_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial scaleVal(const Val &v) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_set_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] s
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial setDimName(DimType type, unsigned int pos, std::string s) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_split_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial splitDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_split_periods>
  ///
  /// \param [in] max_periods
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial splitPeriods(int max_periods) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_sub>
  ///
  /// \param [in] pwqp2
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial sub(const PwQpolynomial &pwqp2) const;

  /// \brief Generated from  ::<isl_pw_qpolynomial_to_polynomial>
  ///
  /// \param [in] sign
  ///
  /// \returns A new PwQpolynomial
  PwQpolynomial toPolynomial(int sign) const;
  PwQpolynomial(const PwQpolynomial &Other) : PwQpolynomial(Other.Context(), Other.GetCopy()) {}
  PwQpolynomial &operator=(const PwQpolynomial &Other);
  PwQpolynomial (PwQpolynomial && Other) : PwQpolynomial(Other.Context(), Other.This) {}
  PwQpolynomial &operator=(PwQpolynomial && Other) {
    isl_pw_qpolynomial *New = Other.Give();
    isl_pw_qpolynomial_free((isl_pw_qpolynomial *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const PwQpolynomial &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_PwQpolynomial_H
