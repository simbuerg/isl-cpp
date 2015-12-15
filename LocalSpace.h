#ifndef ISL_CXX_LocalSpace_H
#define ISL_CXX_LocalSpace_H


#include "isl/local_space.h"
#include "isl/Bool.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Aff;
class BasicMap;
class Id;
class Printer;
class Space;

class LocalSpace {
protected:
  Ctx ctx;
  void * This;
  explicit LocalSpace(Ctx ctx, isl_local_space *That) : ctx(ctx), This((void *)That) {}
  explicit LocalSpace(Ctx ctx, void *That) : ctx(ctx), This(That) {}

public:
  const Ctx &Context() const { return ctx; }
  ///rief Wrap an existing isl object.
  ///
  /// This serves as an entry point into the C++ API.
  /// We take ownership of the isl object.
  ///
  /// \param That the isl_local_space we want to wrap.
  explicit LocalSpace(isl_local_space *That) : LocalSpace(Ctx(isl_local_space_get_ctx(That)), That) {}
  isl_local_space *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_local_space *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_local_space *Get() const;

  /// \brief Constructor for isl_local_space_from_space
  ///
  /// \param dim
  static LocalSpace fromSpace(const Space &dim);
  virtual ~LocalSpace();
  std::string toStr(isl::Format F = isl::Format::FIsl) const;

  virtual LocalSpace asLocalSpace() const;

  /// \brief Generated from  ::<isl_local_space_add_dims>
  ///
  /// \param [in] type
  /// \param [in] n
  ///
  /// \returns A new LocalSpace
  LocalSpace addDims(DimType type, unsigned int n) const;

  /// \brief Generated from  ::<isl_local_space_dim>
  ///
  /// \param [in] type
  ///
  /// \returns A new int
  int dim(DimType type) const;

  /// \brief Generated from  ::<isl_local_space_domain>
  ///
  ///
  /// \returns A new LocalSpace
  LocalSpace domain() const;

  /// \brief Generated from  ::<isl_local_space_drop_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new LocalSpace
  LocalSpace dropDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_local_space_from_domain>
  ///
  ///
  /// \returns A new LocalSpace
  LocalSpace fromDomain() const;

  /// \brief Generated from  ::<isl_local_space_get_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Id
  Id getDimId(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_local_space_get_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new std::string
  std::string getDimName(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_local_space_get_div>
  ///
  /// \param [in] pos
  ///
  /// \returns A new Aff
  Aff getDiv(int pos) const;

  /// \brief Generated from  ::<isl_local_space_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_local_space_has_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Bool
  Bool hasDimId(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_local_space_has_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Bool
  Bool hasDimName(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_local_space_insert_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new LocalSpace
  LocalSpace insertDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_local_space_intersect>
  ///
  /// \param [in] ls2
  ///
  /// \returns A new LocalSpace
  LocalSpace intersect(const LocalSpace &ls2) const;

  /// \brief Generated from  ::<isl_local_space_is_equal>
  ///
  /// \param [in] ls2
  ///
  /// \returns A new Bool
  Bool isEqual(const LocalSpace &ls2) const;

  /// \brief Generated from  ::<isl_local_space_is_set>
  ///
  ///
  /// \returns A new Bool
  Bool isSet() const;

  /// \brief Generated from  ::<isl_local_space_lifting>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap lifting() const;

  /// \brief Generated from  ::<isl_local_space_range>
  ///
  ///
  /// \returns A new LocalSpace
  LocalSpace range() const;

  /// \brief Generated from  ::<isl_local_space_set_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] id
  ///
  /// \returns A new LocalSpace
  LocalSpace setDimId(DimType type, unsigned int pos, const Id &id) const;

  /// \brief Generated from  ::<isl_local_space_set_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] s
  ///
  /// \returns A new LocalSpace
  LocalSpace setDimName(DimType type, unsigned int pos, std::string s) const;

  /// \brief Generated from  ::<isl_local_space_set_tuple_id>
  ///
  /// \param [in] type
  /// \param [in] id
  ///
  /// \returns A new LocalSpace
  LocalSpace setTupleId(DimType type, const Id &id) const;
  LocalSpace(const LocalSpace &Other) : LocalSpace(Other.Context(), Other.GetCopy()) {}
  LocalSpace &operator=(const LocalSpace &Other);
  LocalSpace (LocalSpace && Other) : LocalSpace(Other.Context(), Other.This) {}
  LocalSpace &operator=(LocalSpace && Other) {
    isl_local_space *New = Other.Give();
    isl_local_space_free((isl_local_space *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const LocalSpace &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_LocalSpace_H
