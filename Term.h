#ifndef ISL_CXX_Term_H
#define ISL_CXX_Term_H


#include "isl/polynomial.h"
#include "isl/DimType.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Aff;

class Term {
protected:
  Ctx ctx;
  void * This;
public:
  explicit Term(Ctx ctx, isl_term *That) : ctx(ctx), This((void *)That) {}
  explicit Term(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_term *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_term *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_term *Get() const;
public:
  virtual ~Term();

  Term asTerm() const;

  /// \brief Generated from  ::<isl_term_dim>
  ///
  /// \param [in] type
  ///
  /// \returns A new unsigned int
  unsigned int dim(DimType type) const;

  /// \brief Generated from  ::<isl_term_get_div>
  ///
  /// \param [in] pos
  ///
  /// \returns A new Aff
  Aff getDiv(unsigned int pos) const;

  /// \brief Generated from  ::<isl_term_get_exp>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new int
  int getExp(DimType type, unsigned int pos) const;
  Term(const Term &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  Term &operator=(const Term &Other);
  Term (Term && Other) : ctx(Other.Context()), This(Other.This) {}
  Term &operator=(Term && Other) {
    isl_term *New = Other.Give();
    isl_term_free((isl_term *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const Term &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_Term_H
