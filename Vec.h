#ifndef ISL_CXX_Vec_H
#define ISL_CXX_Vec_H


#include "isl/vec.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Val;

class Vec {
protected:
  Ctx ctx;
  void * This;
public:
  explicit Vec(Ctx ctx, isl_vec *That) : ctx(ctx), This((void *)That) {}
  explicit Vec(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_vec *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_vec *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_vec *Get() const;


  /// \brief Constructor for isl_vec_alloc
  ///
  /// \param ctx
  /// \param size
  static Vec alloc(const Ctx &ctx, unsigned int size);
public:
  virtual ~Vec();

  Vec asVec() const;

  /// \brief Generated from  ::<isl_vec_add>
  ///
  /// \param [in] vec2
  ///
  /// \returns A new Vec
  Vec add(const Vec &vec2) const;

  /// \brief Generated from  ::<isl_vec_clr>
  ///
  ///
  /// \returns A new Vec
  Vec clr() const;

  /// \brief Generated from  ::<isl_vec_cmp_element>
  ///
  /// \param [in] vec2
  /// \param [in] pos
  ///
  /// \returns A new int
  int cmpElement(const Vec &vec2, int pos) const;

  /// \brief Generated from  ::<isl_vec_concat>
  ///
  /// \param [in] vec2
  ///
  /// \returns A new Vec
  Vec concat(const Vec &vec2) const;

  /// \brief Generated from  ::<isl_vec_drop_els>
  ///
  /// \param [in] pos
  /// \param [in] n
  ///
  /// \returns A new Vec
  Vec dropEls(unsigned int pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_vec_extend>
  ///
  /// \param [in] size
  ///
  /// \returns A new Vec
  Vec extend(unsigned int size) const;

  /// \brief Generated from  ::<isl_vec_get_element_val>
  ///
  /// \param [in] pos
  ///
  /// \returns A new Val
  Val getElementVal(int pos) const;

  /// \brief Generated from  ::<isl_vec_insert_els>
  ///
  /// \param [in] pos
  /// \param [in] n
  ///
  /// \returns A new Vec
  Vec insertEls(unsigned int pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_vec_insert_zero_els>
  ///
  /// \param [in] pos
  /// \param [in] n
  ///
  /// \returns A new Vec
  Vec insertZeroEls(unsigned int pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_vec_is_equal>
  ///
  /// \param [in] vec2
  ///
  /// \returns A new Bool
  Bool isEqual(const Vec &vec2) const;

  /// \brief Generated from  ::<isl_vec_move_els>
  ///
  /// \param [in] dst_col
  /// \param [in] src_col
  /// \param [in] n
  ///
  /// \returns A new Vec
  Vec moveEls(unsigned int dst_col, unsigned int src_col, unsigned int n) const;

  /// \brief Generated from  ::<isl_vec_neg>
  ///
  ///
  /// \returns A new Vec
  Vec neg() const;

  /// \brief Generated from  ::<isl_vec_set_element_val>
  ///
  /// \param [in] pos
  /// \param [in] v
  ///
  /// \returns A new Vec
  Vec setElementVal(int pos, const Val &v) const;

  /// \brief Generated from  ::<isl_vec_set_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new Vec
  Vec setVal(const Val &v) const;

  /// \brief Generated from  ::<isl_vec_size>
  ///
  ///
  /// \returns A new int
  int size() const;

  /// \brief Generated from  ::<isl_vec_sort>
  ///
  ///
  /// \returns A new Vec
  Vec sort() const;

  /// \brief Generated from  ::<isl_vec_zero_extend>
  ///
  /// \param [in] size
  ///
  /// \returns A new Vec
  Vec zeroExtend(unsigned int size) const;
  Vec(const Vec &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  Vec &operator=(const Vec &Other);
  Vec (Vec && Other) : ctx(Other.Context()), This(Other.This) {}
  Vec &operator=(Vec && Other) {
    isl_vec *New = Other.Give();
    isl_vec_free((isl_vec *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const Vec &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_Vec_H
