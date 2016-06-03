#ifndef ISL_CXX_MultiVal_H
#define ISL_CXX_MultiVal_H


#include "isl/val.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/DimType.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class Space;
class Val;
class ValList;

class MultiVal {
protected:
  Ctx ctx;
  void * This;
public:
  explicit MultiVal(Ctx ctx, isl_multi_val *That) : ctx(ctx), This(That) {}
  MultiVal() : ctx(Ctx(nullptr)), This(nullptr) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_multi_val *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_multi_val *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_multi_val *Get() const;


  /// \brief Constructor for isl_multi_val_from_val_list
  ///
  /// \param space
  /// \param list
  static MultiVal fromValList(const Space &space, const ValList &list);


  /// \brief Constructor for isl_multi_val_zero
  ///
  /// \param space
  static MultiVal zero(const Space &space);


  /// \brief Constructor for isl_multi_val_read_from_str
  ///
  /// \param ctx
  /// \param str
  static MultiVal readFromStr(const Ctx &ctx, std::string str);
public:
  virtual ~MultiVal();

  /// \brief Generated from  ::<isl_multi_val_add>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new MultiVal
  MultiVal add(const MultiVal &multi2) const;

  /// \brief Generated from  ::<isl_multi_val_add_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new MultiVal
  MultiVal addVal(const Val &v) const;

  /// \brief Generated from  ::<isl_multi_val_find_dim_by_name>
  ///
  /// \param [in] type
  /// \param [in] name
  ///
  /// \returns A new int
  int findDimByName(DimType type, std::string name) const;

  /// \brief Generated from  ::<isl_multi_val_flat_range_product>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new MultiVal
  MultiVal flatRangeProduct(const MultiVal &multi2) const;

  /// \brief Generated from  ::<isl_multi_val_from_range>
  ///
  ///
  /// \returns A new MultiVal
  MultiVal fromRange() const;

  /// \brief Generated from  ::<isl_multi_val_get_domain_space>
  ///
  ///
  /// \returns A new Space
  Space getDomainSpace() const;

  /// \brief Generated from  ::<isl_multi_val_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_multi_val_mod_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new MultiVal
  MultiVal modVal(const Val &v) const;

  /// \brief Generated from  ::<isl_multi_val_plain_is_equal>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new Bool
  Bool plainIsEqual(const MultiVal &multi2) const;

  /// \brief Generated from  ::<isl_multi_val_product>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new MultiVal
  MultiVal product(const MultiVal &multi2) const;

  /// \brief Generated from  ::<isl_multi_val_range_product>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new MultiVal
  MultiVal rangeProduct(const MultiVal &multi2) const;

  /// \brief Generated from  ::<isl_multi_val_to_str>
  ///
  ///
  /// \returns A new std::string
  std::string toStr() const;

  MultiVal(const MultiVal &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  MultiVal &operator=(const MultiVal &Other);
  MultiVal (MultiVal && Other) : ctx(Other.Context()), This(Other.Give()) {}
  MultiVal &operator=(MultiVal && Other) {
    isl_multi_val *New = Other.Give();
    isl_multi_val_free((isl_multi_val *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const MultiVal &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_MultiVal_H
