#ifndef ISL_CXX_Space_H
#define ISL_CXX_Space_H


#include "isl/space.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Id;

class Space {
protected:

public:
  Ctx ctx;
  void * This;
  explicit Space(Ctx ctx, isl_space *That) : ctx(ctx), This((void *)That) {}
  explicit Space(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_space *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_space *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_space *Get() const;

  /// \brief Constructor for isl_space_alloc
  ///
  /// \param ctx
  /// \param nparam
  /// \param n_in
  /// \param n_out
  static Space alloc(const Ctx &ctx, unsigned int nparam, unsigned int n_in, unsigned int n_out);
  /// \brief Constructor for isl_space_set_alloc
  ///
  /// \param ctx
  /// \param nparam
  /// \param dim
  static Space setAlloc(const Ctx &ctx, unsigned int nparam, unsigned int dim);
  /// \brief Constructor for isl_space_params_alloc
  ///
  /// \param ctx
  /// \param nparam
  static Space paramsAlloc(const Ctx &ctx, unsigned int nparam);
  /// \brief Constructor for isl_space_map_from_set
  ///
  /// \param dim
  static Space mapFromSet(const Space &dim);
  /// \brief Constructor for isl_space_map_from_domain_and_range
  ///
  /// \param domain
  /// \param range
  static Space mapFromDomainAndRange(const Space &domain, const Space &range);
  virtual ~Space();

  virtual Space asSpace() const;

  /// \brief Generated from  ::<isl_space_add_dims>
  ///
  /// \param [in] type
  /// \param [in] n
  ///
  /// \returns A new Space
  Space addDims(DimType type, unsigned int n) const;

  /// \brief Generated from  ::<isl_space_align_params>
  ///
  /// \param [in] dim2
  ///
  /// \returns A new Space
  Space alignParams(const Space &dim2) const;

  /// \brief Generated from  ::<isl_space_can_curry>
  ///
  ///
  /// \returns A new Bool
  Bool canCurry() const;

  /// \brief Generated from  ::<isl_space_can_uncurry>
  ///
  ///
  /// \returns A new Bool
  Bool canUncurry() const;

  /// \brief Generated from  ::<isl_space_can_zip>
  ///
  ///
  /// \returns A new Bool
  Bool canZip() const;

  /// \brief Generated from  ::<isl_space_compatible>
  ///
  /// \param [in] dim2
  ///
  /// \returns A new int
  int compatible(const Space &dim2) const;

  /// \brief Generated from  ::<isl_space_curry>
  ///
  ///
  /// \returns A new Space
  Space curry() const;

  /// \brief Generated from  ::<isl_space_dim>
  ///
  /// \param [in] type
  ///
  /// \returns A new unsigned int
  unsigned int dim(DimType type) const;

  /// \brief Generated from  ::<isl_space_domain>
  ///
  ///
  /// \returns A new Space
  Space domain() const;

  /// \brief Generated from  ::<isl_space_domain_map>
  ///
  ///
  /// \returns A new Space
  Space domainMap() const;

  /// \brief Generated from  ::<isl_space_domain_product>
  ///
  /// \param [in] right
  ///
  /// \returns A new Space
  Space domainProduct(const Space &right) const;

  /// \brief Generated from  ::<isl_space_drop_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] num
  ///
  /// \returns A new Space
  Space dropDims(DimType type, unsigned int first, unsigned int num) const;

  /// \brief Generated from  ::<isl_space_drop_inputs>
  ///
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Space
  Space dropInputs(unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_space_drop_outputs>
  ///
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Space
  Space dropOutputs(unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_space_extend>
  ///
  /// \param [in] nparam
  /// \param [in] n_in
  /// \param [in] n_out
  ///
  /// \returns A new Space
  Space extend(unsigned int nparam, unsigned int n_in, unsigned int n_out) const;

  /// \brief Generated from  ::<isl_space_find_dim_by_id>
  ///
  /// \param [in] type
  /// \param [in] id
  ///
  /// \returns A new int
  int findDimById(DimType type, const Id &id) const;

  /// \brief Generated from  ::<isl_space_find_dim_by_name>
  ///
  /// \param [in] type
  /// \param [in] name
  ///
  /// \returns A new int
  int findDimByName(DimType type, std::string name) const;

  /// \brief Generated from  ::<isl_space_from_domain>
  ///
  ///
  /// \returns A new Space
  Space fromDomain() const;

  /// \brief Generated from  ::<isl_space_from_range>
  ///
  ///
  /// \returns A new Space
  Space fromRange() const;

  /// \brief Generated from  ::<isl_space_get_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Id
  Id getDimId(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_space_get_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new std::string
  std::string getDimName(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_space_get_tuple_name>
  ///
  /// \param [in] type
  ///
  /// \returns A new std::string
  std::string getTupleName(DimType type) const;

  /// \brief Generated from  ::<isl_space_has_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Bool
  Bool hasDimId(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_space_has_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Bool
  Bool hasDimName(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_space_has_tuple_id>
  ///
  /// \param [in] type
  ///
  /// \returns A new Bool
  Bool hasTupleId(DimType type) const;

  /// \brief Generated from  ::<isl_space_insert_dims>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] n
  ///
  /// \returns A new Space
  Space insertDims(DimType type, unsigned int pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_space_is_domain>
  ///
  /// \param [in] space2
  ///
  /// \returns A new Bool
  Bool isDomain(const Space &space2) const;

  /// \brief Generated from  ::<isl_space_is_equal>
  ///
  /// \param [in] space2
  ///
  /// \returns A new Bool
  Bool isEqual(const Space &space2) const;

  /// \brief Generated from  ::<isl_space_is_map>
  ///
  ///
  /// \returns A new Bool
  Bool isMap() const;

  /// \brief Generated from  ::<isl_space_is_params>
  ///
  ///
  /// \returns A new Bool
  Bool isParams() const;

  /// \brief Generated from  ::<isl_space_is_range>
  ///
  /// \param [in] space2
  ///
  /// \returns A new Bool
  Bool isRange(const Space &space2) const;

  /// \brief Generated from  ::<isl_space_is_set>
  ///
  ///
  /// \returns A new Bool
  Bool isSet() const;

  /// \brief Generated from  ::<isl_space_is_wrapping>
  ///
  ///
  /// \returns A new Bool
  Bool isWrapping() const;

  /// \brief Generated from  ::<isl_space_join>
  ///
  /// \param [in] right
  ///
  /// \returns A new Space
  Space join(const Space &right) const;

  /// \brief Generated from  ::<isl_space_match>
  ///
  /// \param [in] dim1_type
  /// \param [in] dim2
  /// \param [in] dim2_type
  ///
  /// \returns A new int
  int match(DimType dim1_type, const Space &dim2, DimType dim2_type) const;

  /// \brief Generated from  ::<isl_space_move_dims>
  ///
  /// \param [in] dst_type
  /// \param [in] dst_pos
  /// \param [in] src_type
  /// \param [in] src_pos
  /// \param [in] n
  ///
  /// \returns A new Space
  Space moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_space_params>
  ///
  ///
  /// \returns A new Space
  Space params() const;

  /// \brief Generated from  ::<isl_space_product>
  ///
  /// \param [in] right
  ///
  /// \returns A new Space
  Space product(const Space &right) const;

  /// \brief Generated from  ::<isl_space_range>
  ///
  ///
  /// \returns A new Space
  Space range() const;

  /// \brief Generated from  ::<isl_space_range_map>
  ///
  ///
  /// \returns A new Space
  Space rangeMap() const;

  /// \brief Generated from  ::<isl_space_range_product>
  ///
  /// \param [in] right
  ///
  /// \returns A new Space
  Space rangeProduct(const Space &right) const;

  /// \brief Generated from  ::<isl_space_reset_tuple_id>
  ///
  /// \param [in] type
  ///
  /// \returns A new Space
  Space resetTupleId(DimType type) const;

  /// \brief Generated from  ::<isl_space_reverse>
  ///
  ///
  /// \returns A new Space
  Space reverse() const;

  /// \brief Generated from  ::<isl_space_set_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] id
  ///
  /// \returns A new Space
  Space setDimId(DimType type, unsigned int pos, const Id &id) const;

  /// \brief Generated from  ::<isl_space_set_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] name
  ///
  /// \returns A new Space
  Space setDimName(DimType type, unsigned int pos, std::string name) const;

  /// \brief Generated from  ::<isl_space_set_from_params>
  ///
  ///
  /// \returns A new Space
  Space setFromParams() const;

  /// \brief Generated from  ::<isl_space_set_tuple_id>
  ///
  /// \param [in] type
  /// \param [in] id
  ///
  /// \returns A new Space
  Space setTupleId(DimType type, const Id &id) const;

  /// \brief Generated from  ::<isl_space_set_tuple_name>
  ///
  /// \param [in] type
  /// \param [in] s
  ///
  /// \returns A new Space
  Space setTupleName(DimType type, std::string s) const;

  /// \brief Generated from  ::<isl_space_tuple_is_equal>
  ///
  /// \param [in] type1
  /// \param [in] space2
  /// \param [in] type2
  ///
  /// \returns A new Bool
  Bool tupleIsEqual(DimType type1, const Space &space2, DimType type2) const;

  /// \brief Generated from  ::<isl_space_tuple_match>
  ///
  /// \param [in] type1
  /// \param [in] space2
  /// \param [in] type2
  ///
  /// \returns A new int
  int tupleMatch(DimType type1, const Space &space2, DimType type2) const;

  /// \brief Generated from  ::<isl_space_uncurry>
  ///
  ///
  /// \returns A new Space
  Space uncurry() const;

  /// \brief Generated from  ::<isl_space_unwrap>
  ///
  ///
  /// \returns A new Space
  Space unwrap() const;

  /// \brief Generated from  ::<isl_space_wrap>
  ///
  ///
  /// \returns A new Space
  Space wrap() const;

  /// \brief Generated from  ::<isl_space_zip>
  ///
  ///
  /// \returns A new Space
  Space zip() const;
  Space(const Space &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  Space &operator=(const Space &Other);
  Space (Space && Other) : ctx(Other.Context()), This(Other.This) {}
  Space &operator=(Space && Other) {
    isl_space *New = Other.Give();
    isl_space_free((isl_space *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const Space &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_Space_H
