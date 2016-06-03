#ifndef ISL_CXX_Constraint_H
#define ISL_CXX_Constraint_H


#include "isl/constraint.h"
#include "isl/Bool.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class Aff;
class LocalSpace;
class Space;
class Val;

class Constraint {
protected:
  Ctx ctx;
  void * This;
public:
  explicit Constraint(Ctx ctx, isl_constraint *That) : ctx(ctx), This(That) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_constraint *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_constraint *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_constraint *Get() const;


  /// \brief Constructor for isl_constraint_alloc_equality
  ///
  /// \param ls
  static Constraint allocEquality(const LocalSpace &ls);


  /// \brief Constructor for isl_constraint_alloc_inequality
  ///
  /// \param ls
  static Constraint allocInequality(const LocalSpace &ls);
public:
  virtual ~Constraint();
  /// \brief Generated from  ::<isl_constraint_dim>
  ///
  /// \param [in] type
  ///
  /// \returns A new int
  int dim(DimType type) const;

  /// \brief Generated from  ::<isl_constraint_get_aff>
  ///
  ///
  /// \returns A new Aff
  Aff getAff() const;

  /// \brief Generated from  ::<isl_constraint_get_bound>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Aff
  Aff getBound(DimType type, int pos) const;

  /// \brief Generated from  ::<isl_constraint_get_coefficient_val>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Val
  Val getCoefficientVal(DimType type, int pos) const;

  /// \brief Generated from  ::<isl_constraint_get_constant_val>
  ///
  ///
  /// \returns A new Val
  Val getConstantVal() const;

  /// \brief Generated from  ::<isl_constraint_get_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new std::string
  std::string getDimName(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_constraint_get_div>
  ///
  /// \param [in] pos
  ///
  /// \returns A new Aff
  Aff getDiv(int pos) const;

  /// \brief Generated from  ::<isl_constraint_get_local_space>
  ///
  ///
  /// \returns A new LocalSpace
  LocalSpace getLocalSpace() const;

  /// \brief Generated from  ::<isl_constraint_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_constraint_involves_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Bool
  Bool involvesDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_constraint_is_div_constraint>
  ///
  ///
  /// \returns A new int
  int isDivConstraint() const;

  /// \brief Generated from  ::<isl_constraint_is_equality>
  ///
  ///
  /// \returns A new Bool
  Bool isEquality() const;

  /// \brief Generated from  ::<isl_constraint_is_lower_bound>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Bool
  Bool isLowerBound(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_constraint_is_upper_bound>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Bool
  Bool isUpperBound(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_constraint_negate>
  ///
  ///
  /// \returns A new Constraint
  Constraint negate() const;

  /// \brief Generated from  ::<isl_constraint_set_coefficient_si>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] v
  ///
  /// \returns A new Constraint
  Constraint setCoefficientSi(DimType type, int pos, int v) const;

  /// \brief Generated from  ::<isl_constraint_set_coefficient_val>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] v
  ///
  /// \returns A new Constraint
  Constraint setCoefficientVal(DimType type, int pos, const Val &v) const;

  /// \brief Generated from  ::<isl_constraint_set_constant_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new Constraint
  Constraint setConstantVal(const Val &v) const;

  Constraint(const Constraint &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  Constraint &operator=(const Constraint &Other);
  Constraint (Constraint && Other) : ctx(Other.Context()), This(Other.Give()) {}
  Constraint &operator=(Constraint && Other) {
    isl_constraint *New = Other.Give();
    isl_constraint_free((isl_constraint *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const Constraint &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_Constraint_H
