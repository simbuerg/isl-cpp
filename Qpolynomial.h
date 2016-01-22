#ifndef ISL_CXX_Qpolynomial_H
#define ISL_CXX_Qpolynomial_H


#include "isl/polynomial.h"
#include "isl/Bool.h"
#include "isl/DimType.h"
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
class Aff;
class BasicSet;
class Constraint;
class Point;
class Set;
class Space;
class Term;
class Val;

class Qpolynomial {
protected:
  Ctx ctx;
  void * This;
public:
  explicit Qpolynomial(Ctx ctx, isl_qpolynomial *That) : ctx(ctx), This((void *)That) {}
  explicit Qpolynomial(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_qpolynomial *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_qpolynomial *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_qpolynomial *Get() const;


  /// \brief Constructor for isl_qpolynomial_zero_on_domain
  ///
  /// \param dim
  static Qpolynomial zeroOnDomain(const Space &dim);


  /// \brief Constructor for isl_qpolynomial_one_on_domain
  ///
  /// \param dim
  static Qpolynomial oneOnDomain(const Space &dim);


  /// \brief Constructor for isl_qpolynomial_infty_on_domain
  ///
  /// \param dim
  static Qpolynomial inftyOnDomain(const Space &dim);


  /// \brief Constructor for isl_qpolynomial_neginfty_on_domain
  ///
  /// \param dim
  static Qpolynomial neginftyOnDomain(const Space &dim);


  /// \brief Constructor for isl_qpolynomial_nan_on_domain
  ///
  /// \param dim
  static Qpolynomial nanOnDomain(const Space &dim);


  /// \brief Constructor for isl_qpolynomial_val_on_domain
  ///
  /// \param space
  /// \param val
  static Qpolynomial valOnDomain(const Space &space, const Val &val);


  /// \brief Constructor for isl_qpolynomial_var_on_domain
  ///
  /// \param dim
  /// \param type
  /// \param pos
  static Qpolynomial varOnDomain(const Space &dim, DimType type, unsigned int pos);


  /// \brief Constructor for isl_qpolynomial_from_constraint
  ///
  /// \param c
  /// \param type
  /// \param pos
  static Qpolynomial fromConstraint(const Constraint &c, DimType type, unsigned int pos);


  /// \brief Constructor for isl_qpolynomial_from_term
  ///
  /// \param term
  static Qpolynomial fromTerm(const Term &term);


  /// \brief Constructor for isl_qpolynomial_from_aff
  ///
  /// \param aff
  static Qpolynomial fromAff(const Aff &aff);
public:
  virtual ~Qpolynomial();

  Qpolynomial asQpolynomial() const;

  /// \brief Generated from  ::<isl_qpolynomial_add>
  ///
  /// \param [in] qp2
  ///
  /// \returns A new Qpolynomial
  Qpolynomial add(const Qpolynomial &qp2) const;

  /// \brief Generated from  ::<isl_qpolynomial_add_dims>
  ///
  /// \param [in] type
  /// \param [in] n
  ///
  /// \returns A new Qpolynomial
  Qpolynomial addDims(DimType type, unsigned int n) const;

  /// \brief Generated from  ::<isl_qpolynomial_align_params>
  ///
  /// \param [in] model
  ///
  /// \returns A new Qpolynomial
  Qpolynomial alignParams(const Space &model) const;

  /// \brief Generated from  ::<isl_qpolynomial_as_polynomial_on_domain>
  ///
  /// \param [in] bset
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new int
  int asPolynomialOnDomain(const BasicSet &bset, const std::function<int(isl_basic_set *, isl_qpolynomial *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_qpolynomial_dim>
  ///
  /// \param [in] type
  ///
  /// \returns A new unsigned int
  unsigned int dim(DimType type) const;

  /// \brief Generated from  ::<isl_qpolynomial_drop_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Qpolynomial
  Qpolynomial dropDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_qpolynomial_eval>
  ///
  /// \param [in] pnt
  ///
  /// \returns A new Val
  Val eval(const Point &pnt) const;

  /// \brief Generated from  ::<isl_qpolynomial_foreach_term>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachTerm(const std::function<isl_stat(isl_term *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_qpolynomial_get_constant_val>
  ///
  ///
  /// \returns A new Val
  Val getConstantVal() const;

  /// \brief Generated from  ::<isl_qpolynomial_get_domain_space>
  ///
  ///
  /// \returns A new Space
  Space getDomainSpace() const;

  /// \brief Generated from  ::<isl_qpolynomial_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_qpolynomial_gist>
  ///
  /// \param [in] context
  ///
  /// \returns A new Qpolynomial
  Qpolynomial gist(const Set &context) const;

  /// \brief Generated from  ::<isl_qpolynomial_gist_params>
  ///
  /// \param [in] context
  ///
  /// \returns A new Qpolynomial
  Qpolynomial gistParams(const Set &context) const;

  /// \brief Generated from  ::<isl_qpolynomial_homogenize>
  ///
  ///
  /// \returns A new Qpolynomial
  Qpolynomial homogenize() const;

  /// \brief Generated from  ::<isl_qpolynomial_insert_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Qpolynomial
  Qpolynomial insertDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_qpolynomial_involves_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Bool
  Bool involvesDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_qpolynomial_is_infty>
  ///
  ///
  /// \returns A new Bool
  Bool isInfty() const;

  /// \brief Generated from  ::<isl_qpolynomial_is_nan>
  ///
  ///
  /// \returns A new Bool
  Bool isNan() const;

  /// \brief Generated from  ::<isl_qpolynomial_is_neginfty>
  ///
  ///
  /// \returns A new Bool
  Bool isNeginfty() const;

  /// \brief Generated from  ::<isl_qpolynomial_is_zero>
  ///
  ///
  /// \returns A new Bool
  Bool isZero() const;

  /// \brief Generated from  ::<isl_qpolynomial_move_dims>
  ///
  /// \param [in] dst_type
  /// \param [in] dst_pos
  /// \param [in] src_type
  /// \param [in] src_pos
  /// \param [in] n
  ///
  /// \returns A new Qpolynomial
  Qpolynomial moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_qpolynomial_mul>
  ///
  /// \param [in] qp2
  ///
  /// \returns A new Qpolynomial
  Qpolynomial mul(const Qpolynomial &qp2) const;

  /// \brief Generated from  ::<isl_qpolynomial_neg>
  ///
  ///
  /// \returns A new Qpolynomial
  Qpolynomial neg() const;

  /// \brief Generated from  ::<isl_qpolynomial_plain_is_equal>
  ///
  /// \param [in] qp2
  ///
  /// \returns A new Bool
  Bool plainIsEqual(const Qpolynomial &qp2) const;

  /// \brief Generated from  ::<isl_qpolynomial_pow>
  ///
  /// \param [in] power
  ///
  /// \returns A new Qpolynomial
  Qpolynomial pow(unsigned int power) const;

  /// \brief Generated from  ::<isl_qpolynomial_project_domain_on_params>
  ///
  ///
  /// \returns A new Qpolynomial
  Qpolynomial projectDomainOnParams() const;

  /// \brief Generated from  ::<isl_qpolynomial_scale_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new Qpolynomial
  Qpolynomial scaleVal(const Val &v) const;

  /// \brief Generated from  ::<isl_qpolynomial_set_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] s
  ///
  /// \returns A new Qpolynomial
  Qpolynomial setDimName(DimType type, unsigned int pos, std::string s) const;

  /// \brief Generated from  ::<isl_qpolynomial_sgn>
  ///
  ///
  /// \returns A new int
  int sgn() const;

  /// \brief Generated from  ::<isl_qpolynomial_sub>
  ///
  /// \param [in] qp2
  ///
  /// \returns A new Qpolynomial
  Qpolynomial sub(const Qpolynomial &qp2) const;

  /// \brief Generated from  ::<isl_qpolynomial_substitute>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  /// \param [out] subs (isl_give)
  ///
  /// \returns A new Qpolynomial
  Qpolynomial substitute(DimType type, unsigned int first, unsigned int n, std::unique_ptr<Qpolynomial> * subs) const;
  Qpolynomial(const Qpolynomial &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  Qpolynomial &operator=(const Qpolynomial &Other);
  Qpolynomial (Qpolynomial && Other) : ctx(Other.Context()), This(Other.This) {}
  Qpolynomial &operator=(Qpolynomial && Other) {
    isl_qpolynomial *New = Other.Give();
    isl_qpolynomial_free((isl_qpolynomial *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const Qpolynomial &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_Qpolynomial_H
