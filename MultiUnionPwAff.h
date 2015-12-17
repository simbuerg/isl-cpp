#ifndef ISL_CXX_MultiUnionPwAff_H
#define ISL_CXX_MultiUnionPwAff_H


#include "isl/aff.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Aff;
class MultiAff;
class MultiPwAff;
class MultiVal;
class PwMultiAff;
class Set;
class UnionMap;
class UnionPwAff;
class UnionPwMultiAff;
class UnionSet;

class MultiUnionPwAff {
protected:

public:
  Ctx ctx;
  void * This;
  explicit MultiUnionPwAff(Ctx ctx, isl_multi_union_pw_aff *That) : ctx(ctx), This((void *)That) {}
  explicit MultiUnionPwAff(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_multi_union_pw_aff *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_multi_union_pw_aff *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_multi_union_pw_aff *Get() const;

  /// \brief Constructor for isl_multi_union_pw_aff_from_multi_aff
  ///
  /// \param ma
  static MultiUnionPwAff fromMultiAff(const MultiAff &ma);
  /// \brief Constructor for isl_multi_union_pw_aff_from_union_pw_aff
  ///
  /// \param upa
  static MultiUnionPwAff fromUnionPwAff(const UnionPwAff &upa);
  /// \brief Constructor for isl_multi_union_pw_aff_from_multi_pw_aff
  ///
  /// \param mpa
  static MultiUnionPwAff fromMultiPwAff(const MultiPwAff &mpa);
  /// \brief Constructor for isl_multi_union_pw_aff_multi_val_on_domain
  ///
  /// \param domain
  /// \param mv
  static MultiUnionPwAff multiValOnDomain(const UnionSet &domain, const MultiVal &mv);
  /// \brief Constructor for isl_multi_union_pw_aff_multi_aff_on_domain
  ///
  /// \param domain
  /// \param ma
  static MultiUnionPwAff multiAffOnDomain(const UnionSet &domain, const MultiAff &ma);
  /// \brief Constructor for isl_multi_union_pw_aff_from_union_pw_multi_aff
  ///
  /// \param upma
  static MultiUnionPwAff fromUnionPwMultiAff(const UnionPwMultiAff &upma);
  /// \brief Constructor for isl_multi_union_pw_aff_from_union_map
  ///
  /// \param umap
  static MultiUnionPwAff fromUnionMap(const UnionMap &umap);
  /// \brief Constructor for isl_multi_union_pw_aff_read_from_str
  ///
  /// \param ctx
  /// \param str
  static MultiUnionPwAff readFromStr(const Ctx &ctx, std::string str);
  virtual ~MultiUnionPwAff();

  virtual MultiUnionPwAff asMultiUnionPwAff() const;

  /// \brief Generated from  ::<isl_multi_union_pw_aff_apply_aff>
  ///
  /// \param [in] aff
  ///
  /// \returns A new UnionPwAff
  UnionPwAff applyAff(const Aff &aff) const;

  /// \brief Generated from  ::<isl_multi_union_pw_aff_apply_multi_aff>
  ///
  /// \param [in] ma
  ///
  /// \returns A new MultiUnionPwAff
  MultiUnionPwAff applyMultiAff(const MultiAff &ma) const;

  /// \brief Generated from  ::<isl_multi_union_pw_aff_apply_pw_multi_aff>
  ///
  /// \param [in] pma
  ///
  /// \returns A new MultiUnionPwAff
  MultiUnionPwAff applyPwMultiAff(const PwMultiAff &pma) const;

  /// \brief Generated from  ::<isl_multi_union_pw_aff_domain>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet domain() const;

  /// \brief Generated from  ::<isl_multi_union_pw_aff_floor>
  ///
  ///
  /// \returns A new MultiUnionPwAff
  MultiUnionPwAff floor() const;

  /// \brief Generated from  ::<isl_multi_union_pw_aff_gist>
  ///
  /// \param [in] context
  ///
  /// \returns A new MultiUnionPwAff
  MultiUnionPwAff gist(const UnionSet &context) const;

  /// \brief Generated from  ::<isl_multi_union_pw_aff_gist_params>
  ///
  /// \param [in] context
  ///
  /// \returns A new MultiUnionPwAff
  MultiUnionPwAff gistParams(const Set &context) const;

  /// \brief Generated from  ::<isl_multi_union_pw_aff_intersect_domain>
  ///
  /// \param [in] uset
  ///
  /// \returns A new MultiUnionPwAff
  MultiUnionPwAff intersectDomain(const UnionSet &uset) const;

  /// \brief Generated from  ::<isl_multi_union_pw_aff_intersect_params>
  ///
  /// \param [in] params
  ///
  /// \returns A new MultiUnionPwAff
  MultiUnionPwAff intersectParams(const Set &params) const;

  /// \brief Generated from  ::<isl_multi_union_pw_aff_intersect_range>
  ///
  /// \param [in] set
  ///
  /// \returns A new MultiUnionPwAff
  MultiUnionPwAff intersectRange(const Set &set) const;

  /// \brief Generated from  ::<isl_multi_union_pw_aff_plain_is_equal>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new Bool
  Bool plainIsEqual(const MultiUnionPwAff &multi2) const;

  /// \brief Generated from  ::<isl_multi_union_pw_aff_pullback_union_pw_multi_aff>
  ///
  /// \param [in] upma
  ///
  /// \returns A new MultiUnionPwAff
  MultiUnionPwAff pullbackUnionPwMultiAff(const UnionPwMultiAff &upma) const;

  /// \brief Generated from  ::<isl_multi_union_pw_aff_union_add>
  ///
  /// \param [in] mupa2
  ///
  /// \returns A new MultiUnionPwAff
  MultiUnionPwAff unionAdd(const MultiUnionPwAff &mupa2) const;
  MultiUnionPwAff(const MultiUnionPwAff &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  MultiUnionPwAff &operator=(const MultiUnionPwAff &Other);
  MultiUnionPwAff (MultiUnionPwAff && Other) : ctx(Other.Context()), This(Other.This) {}
  MultiUnionPwAff &operator=(MultiUnionPwAff && Other) {
    isl_multi_union_pw_aff *New = Other.Give();
    isl_multi_union_pw_aff_free((isl_multi_union_pw_aff *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const MultiUnionPwAff &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_MultiUnionPwAff_H
