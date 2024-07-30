#ifndef ZV3D_CORE_COMMON_TYPETRAITS_H
#define ZV3D_CORE_COMMON_TYPETRAITS_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: type traits (support for stl type_traits).
/*
	24-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DCompiler.h"
#include <type_traits>

//-----------------------------------------------------------------------------
// "_t" short looking types


// enable_if_t
#ifdef ZVD_CPP14
namespace zvd
{
	template<bool VBoolCond, typename T = void>
	using enable_if_t = std::enable_if_t<VBoolCond, T>;
	
} // end of zvd
#else // ! cpp 14
namespace zvd
{
	template<bool VBoolCond, typename T = void>
	using enable_if_t = typename enable_if<VBoolCond, T>::type;
} // end of zvd
#endif



 /* ------------------------------------------------------------------------- */
 /*																				*/
 /* ------------------------------------------------------------------------- */

//-----------------------------------------------------------------------------
// Boolean logic in metaprogramming

#ifdef ZVD_CPP17
template<bool VBool>
using ZvdBoolConstant_t = std::bool_constant<VBool>;
#else
template<bool VBool>
using ZvdBoolConstant_t = std::integral_constant<bool, VBool>;
#endif

template<typename...>
struct ZvdAnd_t;

template<typename TBoolConstant1, typename TBoolConstant2>
struct ZvdAnd_t<TBoolConstant1, TBoolConstant2>
	: public std::conditional<TBoolConstant1::value
	, TBoolConstant2, TBoolConstant1>::type
{ };


template<typename...>
struct ZvdOr_t;

template<typename TBoolConstant1, typename TBoolConstant2>
struct ZvdOr_t<TBoolConstant1, TBoolConstant2>
	: public std::conditional<TBoolConstant1::value
	, TBoolConstant1, TBoolConstant2>::type
{ };

template<typename TBoolConstant>
struct ZvdNot_t
	: public ZvdBoolConstant_t <!bool(TBoolConstant::value)>
{ };

namespace zvd
{
#ifdef ZVD_CPP17

	template<typename...TArgs>
	using And_t = ZvdAnd_t<TArgs...>;

	template<typename...TArgs>
	using Or_t = ZvdAnd_t<TArgs...>;


#endif
	template<typename TBoolConstant>
	using Not_t = ZvdNot_t<TBoolConstant>;
} // eof zvd


//-----------------------------------------------------------------------------
// 

template <typename T>
struct ZvdIsNotCopyConstructible_t
	: public ZvdNot_t<std::is_copy_constructible<T>>::type { };

// Check type and result is true when whether:
// 1) type's move ctor does not throw exceptions;
// 2) if 1) is false type is not copy constructible.
template <typename T>
struct ZvdIsNoThrowMoveOrIsNotCopyConstructible_t
	: public ZvdOr_t<std::is_nothrow_move_constructible<T>,
					ZvdIsNotCopyConstructible_t<T>>::type { };

template<typename TIterator>
struct ZvdMakeMoveIteratorIfNoExcept
{
private:
	using UnderlyingValueType = typename std::iterator_traits<TIterator>::value_type;

	template <typename T>
	using Condition = ZvdIsNoThrowMoveOrIsNotCopyConstructible_t<T>;

public:

	using iterator_type = typename std::conditional<
		Condition<UnderlyingValueType>::value,
		std::move_iterator<TIterator>,
		TIterator
	>::type;

	static inline constexpr iterator_type
	make(TIterator it)
	{
		return iterator_type(it);
	}
};

template<typename T>
struct ZvdMakeMoveIteratorIfNoExcept<T*>
{
private:
	
	using UnderlyingValueType = T;

	template <typename U>
	using Condition = ZvdIsNoThrowMoveOrIsNotCopyConstructible_t<U>;

public:

	using iterator_type = typename std::conditional<
		Condition<UnderlyingValueType>::value,
		std::move_iterator<T*>,
		const T*
	>::type;

	static inline constexpr iterator_type
		make(T* p)
	{
		return iterator_type(p);
	}
};







#endif //ZV3D_CORE_COMMON_TYPETRAITS_H
