#ifndef ISL_CXX_BasicSet_H
#define ISL_CXX_BasicSet_H


#include "isl/set.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/Set.h"
#include "isl/Stat.h"
#include "isl/constraint.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class BasicMap;
class Constraint;
class Id;
class Mat;
class Point;
class Printer;
class Space;

class BasicSet : public Set {
protected:
  explicit BasicSet(Ctx ctx, isl_basic_set *That) : Set(ctx, (void *)That) {/* empty */}
  explicit BasicSet(Ctx ctx, void *That) : Set(ctx, (void *)That) {/* empty */}

public:
  ///rief Wrap an existing isl object.
  ///
  /// This serves as an entry point into the C++ API.
  /// We take ownership of the isl object.
  ///
  /// \param That the isl_basic_set we want to wrap.
  explicit BasicSet(isl_basic_set *That) : BasicSet(Ctx(isl_basic_set_get_ctx(That)), That) {}
  isl_basic_set *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_basic_set *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_basic_set *Get() const;

  /// \brief Constructor for isl_basic_set_read_from_str
  ///
  /// \param ctx
  /// \param str
  static BasicSet readFromStr(const Ctx &ctx, std::string str);
  /// \brief Constructor for isl_basic_set_from_point
  ///
  /// \param pnt
  static BasicSet fromPoint(const Point &pnt);
  /// \brief Constructor for isl_basic_set_box_from_points
  ///
  /// \param pnt1
  /// \param pnt2
  static BasicSet boxFromPoints(const Point &pnt1, const Point &pnt2);
  /// \brief Constructor for isl_basic_set_from_constraint_matrices
  ///
  /// \param dim
  /// \param eq
  /// \param ineq
  /// \param c1
  /// \param c2
  /// \param c3
  /// \param c4
  static BasicSet fromConstraintMatrices(const Space &dim, const Mat &eq, const Mat &ineq, DimType c1, DimType c2, DimType c3, DimType c4);
  /// \brief Constructor for isl_basic_set_from_constraint
  ///
  /// \param constraint
  static BasicSet fromConstraint(const Constraint &constraint);
  virtual ~BasicSet();
  std::string toStr(isl::Format F = isl::Format::FIsl) const;

  virtual BasicSet asBasicSet() const;

  virtual Set asSet() const override;

  virtual UnionSet asUnionSet() const override;

  /// \brief Generated from  ::<isl_basic_set_add_constraint>
  ///
  /// \param [in] constraint
  ///
  /// \returns A new BasicSet
  BasicSet addConstraint(const Constraint &constraint) const;

  /// \brief Generated from  ::<isl_basic_set_add_dims>
  ///
  /// \param [in] type
  /// \param [in] n
  ///
  /// \returns A new BasicSet
  BasicSet addDims(DimType type, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_set_affine_hull>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet affineHull() const;

  /// \brief Generated from  ::<isl_basic_set_align_params>
  ///
  /// \param [in] model
  ///
  /// \returns A new BasicSet
  BasicSet alignParams(const Space &model) const;

  /// \brief Generated from  ::<isl_basic_set_apply>
  ///
  /// \param [in] bmap
  ///
  /// \returns A new BasicSet
  BasicSet apply(const BasicMap &bmap) const;

  /// \brief Generated from  ::<isl_basic_set_coefficients>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet coefficients() const;

  /// \brief Generated from  ::<isl_basic_set_detect_equalities>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet detectEqualities() const;

  /// \brief Generated from  ::<isl_basic_set_dim>
  ///
  /// \param [in] type
  ///
  /// \returns A new unsigned int
  unsigned int dim(DimType type) const;

  /// \brief Generated from  ::<isl_basic_set_drop_constraints_involving_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new BasicSet
  BasicSet dropConstraintsInvolvingDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_set_drop_constraints_not_involving_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new BasicSet
  BasicSet dropConstraintsNotInvolvingDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_set_eliminate>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new BasicSet
  BasicSet eliminate(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_set_equalities_matrix>
  ///
  /// \param [in] c1
  /// \param [in] c2
  /// \param [in] c3
  /// \param [in] c4
  ///
  /// \returns A new Mat
  Mat equalitiesMatrix(DimType c1, DimType c2, DimType c3, DimType c4) const;

  /// \brief Generated from  ::<isl_basic_set_flat_product>
  ///
  /// \param [in] bset2
  ///
  /// \returns A new BasicSet
  BasicSet flatProduct(const BasicSet &bset2) const;

  /// \brief Generated from  ::<isl_basic_set_flatten>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet flatten() const;

  /// \brief Generated from  ::<isl_basic_set_foreach_bound_pair>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachBoundPair(DimType type, unsigned int pos, const std::function<isl_stat(isl_constraint *, isl_constraint *, isl_basic_set *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_basic_set_foreach_constraint>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachConstraint(const std::function<isl_stat(isl_constraint *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_basic_set_get_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Id
  Id getDimId(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_basic_set_get_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new std::string
  std::string getDimName(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_basic_set_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_basic_set_get_tuple_name>
  ///
  ///
  /// \returns A new std::string
  std::string getTupleName() const;

  /// \brief Generated from  ::<isl_basic_set_gist>
  ///
  /// \param [in] context
  ///
  /// \returns A new BasicSet
  BasicSet gist(const BasicSet &context) const;

  /// \brief Generated from  ::<isl_basic_set_inequalities_matrix>
  ///
  /// \param [in] c1
  /// \param [in] c2
  /// \param [in] c3
  /// \param [in] c4
  ///
  /// \returns A new Mat
  Mat inequalitiesMatrix(DimType c1, DimType c2, DimType c3, DimType c4) const;

  /// \brief Generated from  ::<isl_basic_set_insert_dims>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] n
  ///
  /// \returns A new BasicSet
  BasicSet insertDims(DimType type, unsigned int pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_set_intersect>
  ///
  /// \param [in] bset2
  ///
  /// \returns A new BasicSet
  BasicSet intersect(const BasicSet &bset2) const;

  /// \brief Generated from  ::<isl_basic_set_intersect_params>
  ///
  /// \param [in] bset2
  ///
  /// \returns A new BasicSet
  BasicSet intersectParams(const BasicSet &bset2) const;

  /// \brief Generated from  ::<isl_basic_set_involves_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Bool
  Bool involvesDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_set_is_empty>
  ///
  ///
  /// \returns A new Bool
  Bool isEmpty() const;

  /// \brief Generated from  ::<isl_basic_set_is_equal>
  ///
  /// \param [in] bset2
  ///
  /// \returns A new Bool
  Bool isEqual(const BasicSet &bset2) const;

  /// \brief Generated from  ::<isl_basic_set_is_subset>
  ///
  /// \param [in] bset2
  ///
  /// \returns A new Bool
  Bool isSubset(const BasicSet &bset2) const;

  /// \brief Generated from  ::<isl_basic_set_is_wrapping>
  ///
  ///
  /// \returns A new Bool
  Bool isWrapping() const;

  /// \brief Generated from  ::<isl_basic_set_lexmax>
  ///
  ///
  /// \returns A new Set
  Set lexmax() const;

  /// \brief Generated from  ::<isl_basic_set_lexmin>
  ///
  ///
  /// \returns A new Set
  Set lexmin() const;

  /// \brief Generated from  ::<isl_basic_set_lift>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet lift() const;

  /// \brief Generated from  ::<isl_basic_set_move_dims>
  ///
  /// \param [in] dst_type
  /// \param [in] dst_pos
  /// \param [in] src_type
  /// \param [in] src_pos
  /// \param [in] n
  ///
  /// \returns A new BasicSet
  BasicSet moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_set_n_constraint>
  ///
  ///
  /// \returns A new int
  int nConstraint() const;

  /// \brief Generated from  ::<isl_basic_set_neg>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet neg() const;

  /// \brief Generated from  ::<isl_basic_set_project_out>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new BasicSet
  BasicSet projectOut(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_set_reduced_basis>
  ///
  ///
  /// \returns A new Mat
  Mat reducedBasis() const;

  /// \brief Generated from  ::<isl_basic_set_remove_divs>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet removeDivs() const;

  /// \brief Generated from  ::<isl_basic_set_remove_divs_involving_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new BasicSet
  BasicSet removeDivsInvolvingDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_set_remove_unknown_divs>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet removeUnknownDivs() const;

  /// \brief Generated from  ::<isl_basic_set_sample>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet sample() const;

  /// \brief Generated from  ::<isl_basic_set_sample_point>
  ///
  ///
  /// \returns A new Point
  Point samplePoint() const;

  /// \brief Generated from  ::<isl_basic_set_set_tuple_id>
  ///
  /// \param [in] id
  ///
  /// \returns A new BasicSet
  BasicSet setTupleId(const Id &id) const;

  /// \brief Generated from  ::<isl_basic_set_solutions>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet solutions() const;

  /// \brief Generated from  ::<isl_basic_set_union>
  ///
  /// \param [in] bset2
  ///
  /// \returns A new Set
  Set union_(const BasicSet &bset2) const;

  /// \brief Generated from  ::<isl_basic_set_unwrap>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap unwrap() const;
  BasicSet(const BasicSet &Other) : Set(Other.Context(), Other.GetCopy()) {}
  BasicSet &operator=(const BasicSet &Other);
  BasicSet (BasicSet && Other) : Set(Other.Context(), Other.This) {}
  BasicSet &operator=(BasicSet && Other) {
    isl_basic_set *New = Other.Give();
    isl_basic_set_free((isl_basic_set *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const BasicSet &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_BasicSet_H
