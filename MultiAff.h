#ifndef ISL_CXX_MultiAff_H
#define ISL_CXX_MultiAff_H


#include "isl/aff.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/MultiPwAff.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Aff;
class AffList;
class LocalSpace;
class Set;
class Space;

class MultiAff {
protected:
  Ctx ctx;
  void * This;
public:
  explicit MultiAff(Ctx ctx, isl_multi_aff *That) : ctx(ctx), This((void *)That) {}
  explicit MultiAff(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_multi_aff *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_multi_aff *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_multi_aff *Get() const;


  /// \brief Constructor for isl_multi_aff_from_aff_list
  ///
  /// \param space
  /// \param list
  static MultiAff fromAffList(const Space &space, const AffList &list);


  /// \brief Constructor for isl_multi_aff_zero
  ///
  /// \param space
  static MultiAff zero(const Space &space);


  /// \brief Constructor for isl_multi_aff_from_aff
  ///
  /// \param aff
  static MultiAff fromAff(const Aff &aff);


  /// \brief Constructor for isl_multi_aff_identity
  ///
  /// \param space
  static MultiAff identity(const Space &space);


  /// \brief Constructor for isl_multi_aff_domain_map
  ///
  /// \param space
  static MultiAff domainMap(const Space &space);


  /// \brief Constructor for isl_multi_aff_range_map
  ///
  /// \param space
  static MultiAff rangeMap(const Space &space);


  /// \brief Constructor for isl_multi_aff_project_out_map
  ///
  /// \param space
  /// \param type
  /// \param first
  /// \param n
  static MultiAff projectOutMap(const Space &space, DimType type, unsigned int first, unsigned int n);


  /// \brief Constructor for isl_multi_aff_read_from_str
  ///
  /// \param ctx
  /// \param str
  static MultiAff readFromStr(const Ctx &ctx, std::string str);
public:
  virtual ~MultiAff();

  MultiAff asMultiAff() const;

  MultiPwAff asMultiPwAff() const;

  MultiUnionPwAff asMultiUnionPwAff() const;

  /// \brief Generated from  ::<isl_multi_aff_add>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new MultiAff
  MultiAff add(const MultiAff &multi2) const;

  /// \brief Generated from  ::<isl_multi_aff_find_dim_by_name>
  ///
  /// \param [in] type
  /// \param [in] name
  ///
  /// \returns A new int
  int findDimByName(DimType type, std::string name) const;

  /// \brief Generated from  ::<isl_multi_aff_flat_range_product>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new MultiAff
  MultiAff flatRangeProduct(const MultiAff &multi2) const;

  /// \brief Generated from  ::<isl_multi_aff_flatten_domain>
  ///
  ///
  /// \returns A new MultiAff
  MultiAff flattenDomain() const;

  /// \brief Generated from  ::<isl_multi_aff_floor>
  ///
  ///
  /// \returns A new MultiAff
  MultiAff floor() const;

  /// \brief Generated from  ::<isl_multi_aff_from_range>
  ///
  ///
  /// \returns A new MultiAff
  MultiAff fromRange() const;

  /// \brief Generated from  ::<isl_multi_aff_get_domain_space>
  ///
  ///
  /// \returns A new Space
  Space getDomainSpace() const;

  /// \brief Generated from  ::<isl_multi_aff_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_multi_aff_gist>
  ///
  /// \param [in] context
  ///
  /// \returns A new MultiAff
  MultiAff gist(const Set &context) const;

  /// \brief Generated from  ::<isl_multi_aff_lex_ge_set>
  ///
  /// \param [in] ma2
  ///
  /// \returns A new Set
  Set lexGeSet(const MultiAff &ma2) const;

  /// \brief Generated from  ::<isl_multi_aff_lex_le_set>
  ///
  /// \param [in] ma2
  ///
  /// \returns A new Set
  Set lexLeSet(const MultiAff &ma2) const;

  /// \brief Generated from  ::<isl_multi_aff_lift>
  ///
  /// \param [out] ls (isl_give)
  ///
  /// \returns A new MultiAff
  MultiAff lift(std::unique_ptr<LocalSpace> * ls) const;

  /// \brief Generated from  ::<isl_multi_aff_plain_is_equal>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new Bool
  Bool plainIsEqual(const MultiAff &multi2) const;

  /// \brief Generated from  ::<isl_multi_aff_product>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new MultiAff
  MultiAff product(const MultiAff &multi2) const;

  /// \brief Generated from  ::<isl_multi_aff_pullback_multi_aff>
  ///
  /// \param [in] ma2
  ///
  /// \returns A new MultiAff
  MultiAff pullbackMultiAff(const MultiAff &ma2) const;

  /// \brief Generated from  ::<isl_multi_aff_range_product>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new MultiAff
  MultiAff rangeProduct(const MultiAff &multi2) const;
  MultiAff(const MultiAff &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  MultiAff &operator=(const MultiAff &Other);
  MultiAff (MultiAff && Other) : ctx(Other.Context()), This(Other.This) {}
  MultiAff &operator=(MultiAff && Other) {
    isl_multi_aff *New = Other.Give();
    isl_multi_aff_free((isl_multi_aff *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const MultiAff &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_MultiAff_H
