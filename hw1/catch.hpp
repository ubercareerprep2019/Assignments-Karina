/*
 *  Catch v2.8.0
 *  Generated: 2019-05-26 21:29:22.235281
 *  ----------------------------------------------------------
 *  This file has been merged from multiple headers. Please don't edit it directly
 *  Copyright (c) 2019 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef TWOBLUECUBES_SINGLE_INCLUDE_CATCH_HPP_INCLUDED
#define TWOBLUECUBES_SINGLE_INCLUDE_CATCH_HPP_INCLUDED
// start catch.hpp


#define CATCH_VERSION_MAJOR 2
#define CATCH_VERSION_MINOR 8
#define CATCH_VERSION_PATCH 0

#ifdef __clang__
#    pragma clang system_header
#elif defined __GNUC__
#    pragma GCC system_header
#endif

// start catch_suppress_warnings.h

#ifdef __clang__
#   ifdef __ICC // icpc defines the __clang__ macro
#       pragma warning(push)
#       pragma warning(disable: 161 1682)
#   else // __ICC
#       pragma clang diagnostic push
#       pragma clang diagnostic ignored "-Wpadded"
#       pragma clang diagnostic ignored "-Wswitch-enum"
#       pragma clang diagnostic ignored "-Wcovered-switch-default"
#    endif
#elif defined __GNUC__
// Because REQUIREs trigger GCC's -Wparentheses, and because still
// supported version of g++ have only buggy support for _Pragmas,
// Wparentheses have to be suppressed globally.
#    pragma GCC diagnostic ignored "-Wparentheses" // See #674 for details

#    pragma GCC diagnostic push
#    pragma GCC diagnostic ignored "-Wunused-variable"
#    pragma GCC diagnostic ignored "-Wpadded"
#endif
// end catch_suppress_warnings.h
#if defined(CATCH_CONFIG_MAIN) || defined(CATCH_CONFIG_RUNNER)
#  define CATCH_IMPL
#  define CATCH_CONFIG_ALL_PARTS
#endif

// In the impl file, we want to have access to all parts of the headers
// Can also be used to sanely support PCHs
#if defined(CATCH_CONFIG_ALL_PARTS)
#  define CATCH_CONFIG_EXTERNAL_INTERFACES
#  if defined(CATCH_CONFIG_DISABLE_MATCHERS)
#    undef CATCH_CONFIG_DISABLE_MATCHERS
#  endif
#  if !defined(CATCH_CONFIG_ENABLE_CHRONO_STRINGMAKER)
#    define CATCH_CONFIG_ENABLE_CHRONO_STRINGMAKER
#  endif
#endif

#if !defined(CATCH_CONFIG_IMPL_ONLY)
// start catch_platform.h

#ifdef __APPLE__
# include <TargetConditionals.h>
# if TARGET_OS_OSX == 1
#  define CATCH_PLATFORM_MAC
# elif TARGET_OS_IPHONE == 1
#  define CATCH_PLATFORM_IPHONE
# endif

#elif defined(linux) || defined(__linux) || defined(__linux__)
#  define CATCH_PLATFORM_LINUX

#elif defined(WIN32) || defined(__WIN32__) || defined(_WIN32) || defined(_MSC_VER) || defined(__MINGW32__)
#  define CATCH_PLATFORM_WINDOWS
#endif

// end catch_platform.h

#ifdef CATCH_IMPL
#  ifndef CLARA_CONFIG_MAIN
#    define CLARA_CONFIG_MAIN_NOT_DEFINED
#    define CLARA_CONFIG_MAIN
#  endif
#endif

// start catch_user_interfaces.h

namespace Catch {
  unsigned int rngSeed();
}

// end catch_user_interfaces.h
// start catch_tag_alias_autoregistrar.h

// start catch_common.h

// start catch_compiler_capabilities.h

// Detect a number of compiler features - by compiler
// The following features are defined:
//
// CATCH_CONFIG_COUNTER : is the __COUNTER__ macro supported?
// CATCH_CONFIG_WINDOWS_SEH : is Windows SEH supported?
// CATCH_CONFIG_POSIX_SIGNALS : are POSIX signals supported?
// CATCH_CONFIG_DISABLE_EXCEPTIONS : Are exceptions enabled?
// ****************
// Note to maintainers: if new toggles are added please document them
// in configuration.md, too
// ****************

// In general each macro has a _NO_<feature name> form
// (e.g. CATCH_CONFIG_NO_POSIX_SIGNALS) which disables the feature.
// Many features, at point of detection, define an _INTERNAL_ macro, so they
// can be combined, en-mass, with the _NO_ forms later.

#ifdef __cplusplus

#  if (__cplusplus >= 201402L) || (defined(_MSVC_LANG) && _MSVC_LANG >= 201402L)
#    define CATCH_CPP14_OR_GREATER
#  endif

#  if (__cplusplus >= 201703L) || (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L)
#    define CATCH_CPP17_OR_GREATER
#  endif

#endif

#if defined(CATCH_CPP17_OR_GREATER)
#  define CATCH_INTERNAL_CONFIG_CPP17_UNCAUGHT_EXCEPTIONS
#endif

#ifdef __clang__

#       define CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS \
  _Pragma( "clang diagnostic push" ) \
  _Pragma( "clang diagnostic ignored \"-Wexit-time-destructors\"" ) \
  _Pragma( "clang diagnostic ignored \"-Wglobal-constructors\"")
#       define CATCH_INTERNAL_UNSUPPRESS_GLOBALS_WARNINGS \
  _Pragma( "clang diagnostic pop" )

#       define CATCH_INTERNAL_SUPPRESS_PARENTHESES_WARNINGS \
  _Pragma( "clang diagnostic push" ) \
  _Pragma( "clang diagnostic ignored \"-Wparentheses\"" )
#       define CATCH_INTERNAL_UNSUPPRESS_PARENTHESES_WARNINGS \
  _Pragma( "clang diagnostic pop" )

#       define CATCH_INTERNAL_SUPPRESS_UNUSED_WARNINGS \
  _Pragma( "clang diagnostic push" ) \
  _Pragma( "clang diagnostic ignored \"-Wunused-variable\"" )
#       define CATCH_INTERNAL_UNSUPPRESS_UNUSED_WARNINGS \
  _Pragma( "clang diagnostic pop" )

#       define CATCH_INTERNAL_SUPPRESS_ZERO_VARIADIC_WARNINGS \
  _Pragma( "clang diagnostic push" ) \
  _Pragma( "clang diagnostic ignored \"-Wgnu-zero-variadic-macro-arguments\"" )
#       define CATCH_INTERNAL_UNSUPPRESS_ZERO_VARIADIC_WARNINGS \
  _Pragma( "clang diagnostic pop" )

#endif // __clang__

////////////////////////////////////////////////////////////////////////////////
// Assume that non-Windows platforms support posix signals by default
#if !defined(CATCH_PLATFORM_WINDOWS)
    #define CATCH_INTERNAL_CONFIG_POSIX_SIGNALS
#endif

////////////////////////////////////////////////////////////////////////////////
// We know some environments not to support full POSIX signals
#if defined(__CYGWIN__) || defined(__QNX__) || defined(__EMSCRIPTEN__) || defined(__DJGPP__)
    #define CATCH_INTERNAL_CONFIG_NO_POSIX_SIGNALS
#endif

#ifdef __OS400__
#       define CATCH_INTERNAL_CONFIG_NO_POSIX_SIGNALS
#       define CATCH_CONFIG_COLOUR_NONE
#endif

////////////////////////////////////////////////////////////////////////////////
// Android somehow still does not support std::to_string
#if defined(__ANDROID__)
#    define CATCH_INTERNAL_CONFIG_NO_CPP11_TO_STRING
#endif

////////////////////////////////////////////////////////////////////////////////
// Not all Windows environments support SEH properly
#if defined(__MINGW32__)
#    define CATCH_INTERNAL_CONFIG_NO_WINDOWS_SEH
#endif

////////////////////////////////////////////////////////////////////////////////
// PS4
#if defined(__ORBIS__)
#    define CATCH_INTERNAL_CONFIG_NO_NEW_CAPTURE
#endif

////////////////////////////////////////////////////////////////////////////////
// Cygwin
#ifdef __CYGWIN__

// Required for some versions of Cygwin to declare gettimeofday
// see: http://stackoverflow.com/questions/36901803/gettimeofday-not-declared-in-this-scope-cygwin
#   define _BSD_SOURCE
// some versions of cygwin (most) do not support std::to_string. Use the libstd check.
// https://gcc.gnu.org/onlinedocs/gcc-4.8.2/libstdc++/api/a01053_source.html line 2812-2813
# if !((__cplusplus >= 201103L) && defined(_GLIBCXX_USE_C99) \
       && !defined(_GLIBCXX_HAVE_BROKEN_VSWPRINTF))

#define CATCH_INTERNAL_CONFIG_NO_CPP11_TO_STRING

# endif
#endif // __CYGWIN__

////////////////////////////////////////////////////////////////////////////////
// Visual C++
#ifdef _MSC_VER

#  if _MSC_VER >= 1900 // Visual Studio 2015 or newer
#    define CATCH_INTERNAL_CONFIG_CPP17_UNCAUGHT_EXCEPTIONS
#  endif

// Universal Windows platform does not support SEH
// Or console colours (or console at all...)
#  if defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP)
#    define CATCH_CONFIG_COLOUR_NONE
#  else
#    define CATCH_INTERNAL_CONFIG_WINDOWS_SEH
#  endif

// MSVC traditional preprocessor needs some workaround for __VA_ARGS__
// _MSVC_TRADITIONAL == 0 means new conformant preprocessor
// _MSVC_TRADITIONAL == 1 means old traditional non-conformant preprocessor
#  if !defined(_MSVC_TRADITIONAL) || (defined(_MSVC_TRADITIONAL) && _MSVC_TRADITIONAL)
#    define CATCH_INTERNAL_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR
#  endif

#endif // _MSC_VER

////////////////////////////////////////////////////////////////////////////////
// Check if we are compiled with -fno-exceptions or equivalent
#if defined(__EXCEPTIONS) || defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  define CATCH_INTERNAL_CONFIG_EXCEPTIONS_ENABLED
#endif

////////////////////////////////////////////////////////////////////////////////
// DJGPP
#ifdef __DJGPP__
#  define CATCH_INTERNAL_CONFIG_NO_WCHAR
#endif // __DJGPP__

////////////////////////////////////////////////////////////////////////////////
// Embarcadero C++Build
#if defined(__BORLANDC__)
    #define CATCH_INTERNAL_CONFIG_POLYFILL_ISNAN
#endif

////////////////////////////////////////////////////////////////////////////////

// Use of __COUNTER__ is suppressed during code analysis in
// CLion/AppCode 2017.2.x and former, because __COUNTER__ is not properly
// handled by it.
// Otherwise all supported compilers support COUNTER macro,
// but user still might want to turn it off
#if ( !defined(__JETBRAINS_IDE__) || __JETBRAINS_IDE__ >= 20170300L )
    #define CATCH_INTERNAL_CONFIG_COUNTER
#endif

////////////////////////////////////////////////////////////////////////////////
// Check if string_view is available and usable
// The check is split apart to work around v140 (VS2015) preprocessor issue...
#if defined(__has_include)
#if __has_include(<string_view>) && defined(CATCH_CPP17_OR_GREATER)
#    define CATCH_INTERNAL_CONFIG_CPP17_STRING_VIEW
#endif
#endif

////////////////////////////////////////////////////////////////////////////////
// Check if optional is available and usable
#if defined(__has_include)
#  if __has_include(<optional>) && defined(CATCH_CPP17_OR_GREATER)
#    define CATCH_INTERNAL_CONFIG_CPP17_OPTIONAL
#  endif // __has_include(<optional>) && defined(CATCH_CPP17_OR_GREATER)
#endif // __has_include

////////////////////////////////////////////////////////////////////////////////
// Check if variant is available and usable
#if defined(__has_include)
#  if __has_include(<variant>) && defined(CATCH_CPP17_OR_GREATER)
#    if defined(__clang__) && (__clang_major__ < 8)
// work around clang bug with libstdc++ https://bugs.llvm.org/show_bug.cgi?id=31852
// fix should be in clang 8, workaround in libstdc++ 8.2
#      include <ciso646>
#      if defined(__GLIBCXX__) && defined(_GLIBCXX_RELEASE) && (_GLIBCXX_RELEASE < 9)
#        define CATCH_CONFIG_NO_CPP17_VARIANT
#      else
#        define CATCH_INTERNAL_CONFIG_CPP17_VARIANT
#      endif // defined(__GLIBCXX__) && defined(_GLIBCXX_RELEASE) && (_GLIBCXX_RELEASE < 9)
#    else
#      define CATCH_INTERNAL_CONFIG_CPP17_VARIANT
#    endif // defined(__clang__) && (__clang_major__ < 8)
#  endif // __has_include(<variant>) && defined(CATCH_CPP17_OR_GREATER)
#endif // __has_include

#if defined(CATCH_INTERNAL_CONFIG_COUNTER) && !defined(CATCH_CONFIG_NO_COUNTER) && !defined(CATCH_CONFIG_COUNTER)
#   define CATCH_CONFIG_COUNTER
#endif
#if defined(CATCH_INTERNAL_CONFIG_WINDOWS_SEH) && !defined(CATCH_CONFIG_NO_WINDOWS_SEH) && !defined(CATCH_CONFIG_WINDOWS_SEH) && !defined(CATCH_INTERNAL_CONFIG_NO_WINDOWS_SEH)
#   define CATCH_CONFIG_WINDOWS_SEH
#endif
// This is set by default, because we assume that unix compilers are posix-signal-compatible by default.
#if defined(CATCH_INTERNAL_CONFIG_POSIX_SIGNALS) && !defined(CATCH_INTERNAL_CONFIG_NO_POSIX_SIGNALS) && !defined(CATCH_CONFIG_NO_POSIX_SIGNALS) && !defined(CATCH_CONFIG_POSIX_SIGNALS)
#   define CATCH_CONFIG_POSIX_SIGNALS
#endif
// This is set by default, because we assume that compilers with no wchar_t support are just rare exceptions.
#if !defined(CATCH_INTERNAL_CONFIG_NO_WCHAR) && !defined(CATCH_CONFIG_NO_WCHAR) && !defined(CATCH_CONFIG_WCHAR)
#   define CATCH_CONFIG_WCHAR
#endif

#if !defined(CATCH_INTERNAL_CONFIG_NO_CPP11_TO_STRING) && !defined(CATCH_CONFIG_NO_CPP11_TO_STRING) && !defined(CATCH_CONFIG_CPP11_TO_STRING)
#    define CATCH_CONFIG_CPP11_TO_STRING
#endif

#if defined(CATCH_INTERNAL_CONFIG_CPP17_OPTIONAL) && !defined(CATCH_CONFIG_NO_CPP17_OPTIONAL) && !defined(CATCH_CONFIG_CPP17_OPTIONAL)
#  define CATCH_CONFIG_CPP17_OPTIONAL
#endif

#if defined(CATCH_INTERNAL_CONFIG_CPP17_UNCAUGHT_EXCEPTIONS) && !defined(CATCH_CONFIG_NO_CPP17_UNCAUGHT_EXCEPTIONS) && !defined(CATCH_CONFIG_CPP17_UNCAUGHT_EXCEPTIONS)
#  define CATCH_CONFIG_CPP17_UNCAUGHT_EXCEPTIONS
#endif

#if defined(CATCH_INTERNAL_CONFIG_CPP17_STRING_VIEW) && !defined(CATCH_CONFIG_NO_CPP17_CAPTURE
#endif

#if !defined(CATCH_INTERNAL_CONFIG_EXCEPTIONS_ENABLED) && !defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)
#  define CATCH_CONFIG_DISABLE_EXCEPTIONS
#endif

#if defined(CATCH_INTERNAL_CONFIG_POLYFILL_ISNAN) && !defined(CATCH_CONFIG_NO_POLYFILL_ISNAN) && !defined(CATCH_CONFIG_POLYFILL_ISNAN)
#  define CATCH_CONFIG_POLYFILL_ISNAN
#endif

#iIADIC_WARNINGS
#endif

#if defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)
#define CATCH_TRY if ((true))
#define CATCH_CATCH_ALL if ((false))
#define CATCH_CATCH_ANON(type) if ((false))
#else
#define CATCH_TRY try
#define CATCH_CATCH_ALL catch (...)
#define CATCH_CATCH_ANON(type) catch (type)
#endif

#if defined(CATCH_INTERNAL_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR) && nt>

// We need a dummy global operator<< so we can bring it into Catch namespace later
struct Catch_global_namespace_dummy {};
std::ostream& operator<<(std::ostream&, Catch_global_namespace_dummy);

namespace Catch {

  struct CaseSensitive { enum Choice {
      Yes,
        No
    }; };

  class NonCopyable {
    NonCopyable( NonCopyable const& )              = delete;
    NonCopyable( NonCopyableLineInfo( SourceLineInfo&& )              noexcept = default;
		 SourceLineInfo& operator = ( SourceLineInfo&& ) noexcept = default;

		 bool empty() const noexcept;
		 bool operator == ( SourceLineInfo const& other ) const noexcept;
		 bool operator < ( SourceLineInfo const& other ) const noexcept;

		 char const* file;
		 std::size\
		 ::Catch::SourceLineInfo( __FILE__, static_cast<std::size_t>( __LINE__ ) )

		 // end catch_common.h
		 namespace Catch {

		   struct RegistrarForTagAliases {
		     RegistrarForTagAliases( char const* alias, char const* tag, SourceLineInfo const& lineInfo );
		   };

		   ) const = 0;
		 virtual std::vector<TestCase> const& getAllTestsSorted( IConfig const& config ) const = 0;
		 };

    bool matchTest( TestCase const& testCase, TestSpec const& testSpec, IConfig const& config );
    std::vector<TestCase> filterTests( std::vector<TestCase> const& testCases, TestSpec const& testSpec, IConfig const& config );
    std::vector<TestCase> const& getAllTestCasesSorted( IConfig const& config );

  }uld not be shared between
   /// threads.
  class StringRef {
  public:
    using size_type = std::size_t;

  private:
    friend struct StringRefTestAccess;

    char const* m_start;
    size_type m_size;

    char* m_data = nullptr;

    void takeOwnership();

    static constexpr char const* const s_empty = "";

  public: // construction/ assignment
    StringRef() noexcept
    :   StringRef( s_empty, ingRef( std::string const& stdString ) noexcept
		   :   m_start( stdString.c_str() ),
		   m_size( stdString.size() )
		   {}

		   ~StringRef() noexcept {
		     delete[] m_data;
		   }

		   auto operator = ( StringRef const &other ) noexcept -> StringRef& {
		     delete[] m_data;
		     m_data = nullptr;
		     ters() const noexcept -> size_type;
		     auto c_str() const -> char const*;

		   public: // substrings and searches
		     auto substr( size_type start, size_type size ) const noexcept -> StringRef;

		     // Returns the current start pointer.
		     // Note that the pointer can change when if the StringRef is a substring
		     auto currentData() const noexcept std::size_t size ) noexcept -> StringRef {
		     return StringRef( rawChars, size );
		   }

		   } // namespace Catch

      inline auto operator "" _catch_sr( char const* rawChars, std::size_t size ) noexcept -> Catch::StringRef {
      return Catch::StringRef( rawChars, size );
    }

    // end catch_stringref.h
    // start catch_type_trai.hpp


#define CATCH_RECURSION_LEVEL0(...) __VA_ARGS__
#define CATCH_RECURSION_LEVEL1(...) CATCH_RECURSION_LEVEL0(CATCH_RECURSION_LEVEL0(CATCH_RECURSION_LEVEL0(__VA_ARGS__)))
#define CATCH_RECURSION_LEVEL2(...) CATCH_RECURSION_LEVEL1(CATCH_RECURSION_LEVEL1(CATCH_RECURSION_LEVEL1(__VA_ARGS__)))
#define CATCH_RECURSION_LEVE(...)  CATCH_RECURSION_LEVEL5(__VA_ARGS__)
#endif

#define CATCH_REC_END(...)
#define CATCH_REC_OUT

#define CATCH_EMPTY()
#define CATCH_DEFER(id) id CATCH_EMPTY()

#define CATCH_REC_GET_END2() 0, CATCH_REC_END
#define CATCH_REC_GET_END1(...) CATCH_REC_GET_END2
#define CATCH_REC_GET_END(...) CATCH_REC_GET_END1
#define CATCH_REC_NEXT0(test, next, ...) next CATCH_REC_OUT
#defieek, CATCH_REC_LIST1_UD) ) ( f, userdata, peek, __VA_ARGS__ )
#define CATCH_REC_LIST1_UD(f, userdata, x, peek, ...) , f(userdata, x) CATCH_DEFER ( CATCH_REC_NEXT(peek, CATCH_REC_LIST0_UDINTERNAL_CATCH_DEF(...) INTERNAL_CATCH_DEF __VA_ARGS__
#define INTERNAL_CATCH_NOINTERNAL_CATCH_DEF
#define INTERNAL_CATCH_STRINGIZE(...) INTERNAL_CATCH_STRINGIZE2(__VA_ARGS__)
#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCECONFIG_TRADITIONAL_MSVC_PREPROCESSOR
#define INTERNAL_CATCH_MAKE_TYPE_LIST2(...) decltype(get_wrapper<INTERNAL_CATCH_REMOVE_PARENS_GEN(__VA_ARGS__)>())
#define INTERNAL_CATCH_MAKE_TYPE_LIST(...) INTERNAL_CATCH_MAKE_TYPE_LIST2(INTERNAL_CATCH_REMOVE_PARENS(__VA_ARGS__))
#else
#define INTERNAL_CATCH_MAKE_TYPE_LIST2(...) INTERNAL_CATCH_EXPAND_VARGS(decltype(get_wrapper<INTERNAL_CATCH_REMOVE_PARENS_GEN(__VA_ARGS__)>()))
#define INTERNAL_CATCH_MAKE_TYPE_LIST(...) INTERNAL_CATCH_EXPAND_VARGS(INTERNAL_CATCH_MAKE_TYPE_LIST2(INTE_2)
#define INTERNAL_CATCH_REMOVE_PARENS_4_ARG(_0, _1, _2, _3) INTERNAL_CATCH_REMOVE_PARENS(_0), INTERNAL_CATCH_REMOVE_PARENS_3_ARG(_1, _2, _3)
#define INTERNAL_CATCH_REMOVE_PARENS_5_ARG(_0, _1, _2, _3, _4) INTERNAL_CATCH_REMOVE_PARENS(_0), INTERNAL_CATCH_REMOVE_PARENS_4_ARG(_1, _2, _3, _4)
#define INTERNAL_CATCH_REMOVE_PARENS_6_ARG(_0, _1, _2, _3, _4, _5) INTERNAL_CATCH_REMOVE_PARENS(_0), INTERNAL_CATCH_REMOVE_PARENS_5_ARG(_1, _2, _3, _4, _5)
#define INTERNAL_CATCH_REMOVE_PARENS_7_ARG(_0, _1, _2, _3, _4, _5, _6) INTERNAL_CATCH_REMOVE_PARENS(_0), INTERNAL_CATCH_REMOVE_PARENS_6_ARG(_1, _2, _4, _5, _6)
#define INTERNAL_CATCH_REMOVE_PARENS_8_ARG(_0, _1, _2, _3, _4, _5, _6, _7) INTERNAL_C_5, _6, _7, _8, _9) INTERNAL_CATCH_REMOVE_PARENS(_0), INTERNAL_CATCH_REMOVE_PARENS_9_ARG(_1, _2, _3, _4, _5, _6, _7, _8, _9)
#define INTERNAL_CATCH_REMOVE_PARENS_11_ARG(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) INTERNAL_CATCH_REMOVE_PARENS(_0), INTERNAL_CATCH_REMOVE_PARENS_10_ARG(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10)

#define INTERNAL_CATCH_VA_NARGS_IMPL(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N

#define INTERNAL_CATCH_TYPE_GEN\
  template<typename...> struct TypeList {};\
  template<typename...Ts>\
  constexpr auto get_wrapper() noexcept -> TypeList<Ts...> { return {}; }\
    \
  template<template<typename...> class L1, typename...E1, templ1<E1...,E2...>{}, Rest{}...)) { return {}; }\
    \
										       template< template<typename...> class Container, template<typename...> class List, typename...elems>\
										       constexpr auto rewrap(List<elems...>) noexcept -> TypeList<Container<elems...>> { return {}; }\
										       template< template<typename...> class Container, template<typename...> class List, class...Elems, typename...Elements>\
										       constexpr auto rewrap(List<Elems...>,Elements...) noexcept -> decltype(append(TypeList<Container<Elems...>>{}, rewrap<Container>(Elements{}...))) { return {}; }\
    \
										       template<temp__VA_ARGS__> { return {}; } \
    \
										       template< template<INTERNAL_CATCH_REMOVE_PARENS(signature)> class Container, template<INTERNAL_CATCH_REMOVE_PARENS(signature)> class List, INTERNAL_CATCH_REMOVE_PARENS(signature)>\
										       constexpr auto rewrap(List<__VA_ARGS__>) noexcept -> TypeList<Container<__VA_ARGS__>> { return {}; }\
										       template< template<INTERNAL_CATCH_REMOVE_PARENS(signature)> class Container, template<INTERNAL_CATCH_REMOVE_PtName)
#define INTERNAL_CATCH_DECLARE_SIG_TEST1(TestName, signature)\
  template<INTERNAL_CATCH_REMOVE_PARENS(signature)>\
  static void TestName()
#define INTERNAL_CATCH_DECLARE_SIG_TEST_X(TestName, signature, ...)\
  template<INTERNAL_CATCH_REMOVE_PARENS(signature)>\
  static void TestName()

#define INTERNAL_CATCH_DEFINE_SIG_TEST0(TestName)
#define INTERNAL_CATCH_DEFINE_SIG_TEST1(TestName, signature)\
  template<INTERNAL_CATCH_REMRNAL_CATCH_REMOVE_PARENS(signature)>\
  void reg_test(Nttp<__VA_ARGS__>, Catch::NameAndTags nameAndTags)\
  {\
    Catch::AutoReg( Catch::makeTestInvoker(&TestFunc<__VA_ARGS__>), CATCH_INTERNAL_LINEINFO, Catch::StringRef(), nameAndTags);\
  }

#define INTERNAL_CATCH_NTTP_REGISTER_METHOD0(TestName, signature, ...)\
  template<typename Type>\
  void reg_test(TypeList<Type>, Catch::StringRef className, Catch::efine INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD1(TestName, ClassName, signature)\
		template<typename TestType> \
		struct TestName : INTERNAL_CATCH_REMOVE_PARENS(ClassName)<TestType> { \
		  void test();\
		}

#define INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X(TestName, ClassName, signature, ...)\
  template<INTERNAL_CATCH_REMOVE_PARENS(signature)> \
  struct TestName : INTERNAL_CATCH_RTP_GEN(...) INTERNAL_CATCH_VA_NARGS_IMPL(__VA_ARGS__, INTERNAL_CATCH_NTTP_1(__VA_ARGS__), INTERNAL_CATCH_NTTP_1(__VA_ARGS__), INTERNAL_CATCH_NTTP_1(__VA_ARGS__), INTERNAL_CATCH_NTTP_1(__VA_ARGS__), INTERNAL_CATCH_NTTP_1(__VA_ARGS__), INTERNAL_CATCH_NTTP_1( __VA_ARGS__), INTERNAL_CATCH_NTTP_1( __VA_ARGS__), INTERNAL_CATCH_NTTP_1( __Vdefine INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD(TestName, ClassName, ...) INTERNAL_CATCH_VA_NARGS_IMPL( "dummy", __VA_ARGS__, INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X,INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X, INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X, INTERERNAL_CATCH_NTTP_REGISTER_METHOD, INTERNAL_CATCH_NTTP_REGISTER_METHOD0, INTERNAL_CATCH_NTTP_REGISTER_METHOD0)(TestName, __VA_ARGS__)
#define INTERNAL_CATCH_NTTP_REG_GEN(TestFunc, ...) INTERNAL_CATCH_VA_NARGS_IMPL( "dummy", __VA_ARGS__, INIG_TEST1, INTERNAL_CATCH_DEFINE_SIG_TEST0)(TestName, __VA_ARGS__)
#define INTERNAL_CATCH_DECLARE_SIG_TEST(TestName, ...) INTERNAL_CATCH_VA_NARGS_IMPL( "dummy", __VA_ARGS__, INTERNAL_CATCH_DECLARE_SIG_TEST_X,CATCH_REMOVE_PARENS_1_ARG)(__VA_ARGS__)
#else
#define INTERNAL_CATCH_NTTP_0(signature)
#define INTERNAL_CATCH_NTTP_GEN(...) INTERNAL_CATCH_EXPAND_VARGS(INTEEFINE_SIG_TEST_METHOD0)(TestName, __VA_ARGS__))
#define INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD(TestName, ClassName, ...) INTERNAL_CATCH_EXPAND_VARGS(INTERNAL_CATC_CATCH_NTTP_REGISTER_METHOD, INTERNAL_CATCH_NTTP_REGISTER_METHOD, INTERNAL_CATCH_NTTP_REGISTER_METHOD, INTERNAL_CATCH_NTTP_REGISTER_METHOD, INTERNAL_CATCH_NTTP_REGISTER_METHOD0,EST_X, INTERNAL_CATCH_DEFINE_SIG_TEST_X, INTERNAL_CATCH_DEFINE_SIG_TEST_X, INTERNAL_CATCH_DEFINE_SIG_TEST_X,INTERNAL_CATCH_DEFINE_SIG_TEST_X,INTERNAL_CATCH_DEFINE_SIG_TEST1, INTERNAL_CATCH_DEFINE_SIG_TEST0)(TestName, __VA_ARGS__))
#define INTERNAL_CATCH_DRG,INTERNAL_CATCH_REMOVE_PARENS_7_ARG,INTERNAL_CATCH_REMOVE_PARENS_6_ARG,INTERNAL_CATCH_REMOVE_PARENS_5_ARG,INTERNAL_CATCH_REMOVE_PARENMethod<C>( testAsMethod );
}

    struct NameAndTags {
      NameAndTags( StringRef const& name_ = StringRef(), StringRef const& tags_ = StringRef() ) noexcept;
      StringRef name;
      StringRef tags;
    };

struct AutoReg : NonCopyable {
  AutoReg( ITestInvoker* invoker, SourceLineInfo const& lineInfo, StringRef const& clanature, ... )  \
  INTERNAL_CATCH_DEFINE_SIG_TEST(TestFunc, INTERNAL_CATCH_REMOVE_PARENS(Signature))
#define INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_NO_REGISTRATION_2( TestNameClass, TestName, ClassName, Name, Tags, Signature, ... )    NTERNAL_CATCH_TEMPLATE_TEST_CASE_NO_REGISTRATION_2( INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____ ), Name, Tags, typename TestType, __VA_ARGS__ )
    #else
#define INTERNAL_CATCH_TEMPLATE_TES___T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____ ), Name, Tags, Signature, __VA_ARGS__ )
    #else
#define INTERNAL_CATCH_TEMPLATE_TEST_CASE_SIG_NO_REGISTRATION(Name, Tags, Signature, ...) \
  INTERNAL_CATCH_EXPAND_VARGS( INTHOD_NO_REGISTRATION( ClassName, Name, Tags,... ) \
			       INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_NO_REGISTRATION_2( INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____C_L_A_S_S____ ), INTERNAL_CATCH_UNIQUE_ INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_NO_REGISTRATION_2( INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____C_L_A_S_S____ ), INTERNAL_CATCH_UNIQUE_NAME( ___///////////////////////////////////////
#define INTERNAL_CATCH_METHOD_AS_TEST_CASE( QualifiedMethod, ... ) \
        CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS \
        namespace{ Catch::AutoReg INTERNNTERNAL_UNSUPPRESS_GLOBALS_WARNINGS \
	    void TestName::test()
#define INTERNAL_CATCH_TEST_CASE_METHOD( ClassName, ... ) \
  INTERNAL_CATCH_TEST_CASE_METHOD2( INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H___DECLARE_SIG_TEST(TestFunc, INTERNAL_CATCH_REMOVE_PARENS(Signature));\
								namespace {\
								  namespace INTERNAL_CATCH_MAKE_NAMESPACE(TestName){\
								    _LISTS_FROM_TYPES(__VA_ARGS__)>();\
								    return 0;\
								  }();\
								}\
								}\
        CATCH_INTERNAL_UNSUPPRESS_GLOBALS_WARNINGS \
        CATCH_INTERNAL_UNSUPPRESS_ZERO_VARIADIC_WARNINGS \
				    INTGS__ ) )
#endif

#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR
#define INTERNAL_CATCH_TEMPLATE_TEST_CASE_SIG(Name, Tags, Signature, ...) \
  INTERNAL_CATCH_TEMPLATE_TEST_CASE_2( INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____ ), INTERNALNGS                \
				       template<typename TestType> static void TestFuncName();       \
				       namespace {\
					 namespace INTERNAL_CATCH_MAKE_NAMESPACE(TestName) {                                     \
            INTERNAL_CATCH_TYPE_GEN                                                  \
	      INTERNAL_CATCH_NTTP_GENINTERNAL_CATCH_REMOVE_PARENS(TypesList))};\
				       constexpr auto num_types = sizeof(types_list) / sizeof(types_list[0]);\
				       (void)expander{(Catch::AutoReg( Catch::makeTestInvoker               return 0;                                             \
								       }();                                                      \
						       }                                        D_VARGS( INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE2( INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____ ), Name, Tags, typename T, __ture, __VA_ARGS__ ) )
#endif

#define INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_2( TestNameClass, TestName, ClassName, Name, Tags, Signature, ... ) \
        CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS \
        CATCH_INTERNAL_SUPPRESS_ZERO_VARIADIC_WARNINGS \
        namespace {\
	  namespa[];\
	  (void)expander{(reg_test(Types{}, #ClassName, Catch::NameAndTags{ Name " - " + std::string(tmpl_types[index]), Tags } ), index++, 0)... };/* NOLINT */ \
	}\
	};me, Tags, typename T, __VA_ARGS__ )
#else
#define INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD( ClassName, Name, Tags,... ) \
  INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_2( INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____C_L_A_S_S____ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____ ) , ClassName, Name, Tags, typename T, __VA_ARGS__ ) )
#endif

#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR
#define INTERNAATE_TEST_CASE_METHOD_2( INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____C_L_A_S_S____ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____ ) , ClassName, Name, Tags, Signature, __VA_ARGS__ ) )
#endif

#define INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_2(TestNameClass, TestName, ClassName, Name, Tags, Signature, TmplTypes, TypesList)\
  CAT  int index = 0;\
  using expander = int[];\
  constexpr char const* tmpl_types[] = {CATCH_REC_LIST(INTERNAL_CATCH_STRINGIZE_WITHOUT_PARENS, INTERNAL_CATCH_REMOVE_PARENS(TmplTypes))};\
  constexpr char const* types_list[] = {CATCH_REC_LIST(INTERNAL_CATTCH_MAKE_TYPE_LISTS_FROM_TYPES(INTERNAL_CATCH_REMOVE_PARENS(TypesList))>{}));\
  TestInit t;\
  t.reg_tests();\
  return 0;\
  }(); \
															}\
							      }\
        CATCH_INTERNAL_UNSUPPRESS_GLOBALS_WARNINGS \
        CATCH_INTERNAL_UNSUPPRESS_ZERO_VARIADIC_WARNINGS \
			       template<typename TestType> \
			       void TestName<TestType>::test()

#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR
#define INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD( ClassName, Name, Tags, ... )\
  INTERNAL_CATCIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____ ), ClassName, Name, Tags, typename T,__VA_ARGS__ ) )
#endif

#ifndef CATCH_COe, Name, Tags, Signature,__VA_ARGS__ ) )
#endif

  // end catch_test_registry.h
  // start catch_capture.hpp

  // start catch_assertionhandler.h

  // start catch_assertioninfo.h

  // start catch_result_type.h

  namespace Catch {

  // ResultWas::OfType enum
  struct ResultWas { enum OfType {
      Unknown = -1,
      Ok = 0,
      Info = 1,
      Warning = 2,

      FailureBit = 0x10,

      ExpressionFailed = FailureBit | 1,
      Explici= 0x08         // Failures are reported but do not fail the test
    }; };

  ResultDisposition::Flags operator | ( ResultDisposition::Flags lhs, ResultDisposition::Flags rhs );

  bool shouldContinueOnFailure( int flags );
  inline bool isFalseTest( int flags ) { return ( flags & ResultDisposition::FalseTest ) != 0; }
  bool shouldSuppressFailure( int flags );

} // end namespace Catch

// end catch_result_type.h
namespace Catch {

    struct AssertionInfo
    {
      StringRef macroNlude <iosfwd>
#include <cstddef>
#include <ostream>

      namespace Catch {

	std::ostream& cout();
	std::ostream& cerr();
	std::ostream& clog();

	class StringRef;

	struct IStream {
	  virtual ~IStream();
	  virtual std::ostream& stream() const = 0;
	};

	auto makeStream( StringRef const &filename ) -> IStream const*;

	class ReusableStringStream {
	  std::size_t m_index;
	  std::ostream* m_oss;
	public:
	  ReusableStringStream();
	  ~ReusableStringStream();

	  auto str() const -> std::string;

	  template<typename T>
	  auto operator << ( T const& value ) -> Reusabtring>> m_values;

	  ~EnumInfo();

	  StringRef lookup( int value ) const;
        };
      } // namespace Detail

      struct IMutableEnumValuesRegistry {
        virtual ~IMutableEnumValuesRegistry();

        virtual Detail::EnumInfo const& registerEnum( StringRef enumName, StringRef allEnums, std::vector<int> cne CATCH_ARC_ENABLED __has_feature(objc_arc)
#else
#define CATCH_ARC_ENABLED 0
#endif

						      void arcSafeRelease( NSObject* obj );
						      id performOptionalSelector( id obwarning(disable:4180) // We attempt to stream a function (address) by const&, which MSVC complains about but is harmless
#endif

										  namespace Catch {
    namespac>
    typename std::enable_if<
      !std::is_enum<T>::value && !std::is_base_of<std::exception, T>::value,
      std::string>::type convertUnstreamable( T const& ) {
      return Detail::unprintableString;
      ring());
										    cli::pin_ptr<System::Byte> p = &bytes[0];
										    return std::string(reinterpret_cast<char const *>(p), bytes->Length);
										  }
#endif

										  } // namespace Detail

						      // If we decide for C++14, change theseGIFIER)
						      return Detail::convertUnstreamable(value);
#else
						      return CATCH_CONFIG_FALLBACK_STRINMaker<std::string> {
							static std::string convert(const std::string& str);
						      };

#ifdef CATCH_CONFIG_CPP17_STRING_VIEW
						      template   };
#endif

	// TBD: Should we use `strnlen` to ensure that we don't go out of the buffer,
	//      while keeping string semantics?
	template<int SZ>
	struct StringMaker<char[SZ]> {
	  static std::string convert(char const* str) {
	    emplate<>
	      struct StringMaker<long long> {
		static std::string convert(long long value);
	      };
	    template<>
	      struct StringMaker<unsigned int> {
	      static std::string convert(unsigned int value);
	    };
	    template<>
	      struct StringMaker<unsigned long> {
      
	      struct StringMaker<float> {
		static std::string convert(float value);
		static int precision;
	      };

	      template<>
	      struct StringMaker<double> {
		static std::string cef);
	    }
	  };
#endif

	  namespace Detail {
	    template<typename InputIterator>
	    std::string rangeToString(InputIterator first, InputIterator last) {
	      ReusableStringStream rss;
	      rss << "{ "; inline std::string stringify( NSString* nsstring ) {
		return StringMaker<NSString*>::convert( nsstring );
	      }

	    } // na<< ::Catch::Detail::stringify(pair.first)
	    << ", "
	    std::size_t N = 0,
	       bool = (N < std::tuple_size<Tuple>::value)
            >
            struct TupleElementPrinter {
	      static void print(consNFIG_ENABLE_TUPLE_STRINGMAKER

#if defined(CATCH_CONFIG_ENABLE_VARIANT_STRINGMAKER) && defined(CATCH_CONFIG_CPP17_VARIANT)
#include <variant>
				namespace Catch {
				  template<>
				  struct StringMaker<std::monostate> {
				    static std::string convert(const std::monostate&) {
				      return "{ }";
				    }
				  };

				  templateport begin/ end from std here so they are considered alongside the fallback (..true;
														       for( bool b : v ) {
															 if( first )
															   first = false;
															 else
															   rss << ", ";
															 <Ratio>::symbol() {
															   Catch::ReusableStringStream rss;
															   rss << '[' << Ratio::num << '/'
															       << Ratio::den << ']';
															   return rss.str();
															 }
															 template <>
															   struct ratio_string<std::atto> {
															   static std::string symbol();
															 };
															 template <>
															   struct ratio_string<std::femto> {
															   static std:      return rss.str();
															 }
														       };
														       template<typename Value>
														       struct StringMaker<std::chrono::duration<Value, std::ratio<1>>> {
															 static std::string convert(std::chrono::duration<Value, std::ratio<1>> const& duration) {
															   ReusableStringStream rss;
															   rss << duration.count() << " s";
															   return rss.str();
															 }
														       };
														       template<typename Value>
														       struct StringMaker<std::chrono::duration<Value, std::ratio<60>>> {
															 stati   };

														       ////////////
														       // std::chrono::time_point specialization
														       // Generic time_point cannot be specialized, only std::chrono::time_point<system_clock>
														       template<typename Clock, typename Duration>
														       struct StringMaker<std::chrono::time_point<Clock, Duration>> {
															 static std::string convert(std::chrono::time_point<Clock, Duration> const& time_point) {
															   return ::Catch::Detail::stringify(time_point.time_since_epoch()) + " since epoch";
															 }
														       };
														       // std::chrono::time_point<system_clock> specialization
														       template<typename Duration>
   dif

														       auto const timeStampSize = sizeof("2017-01-16T17:06:45Z");
														       char timeStamp[timeStampSize];
														       const char * const fmt = "%Y-%m-%dT%H:%M:%SZ";

#ifdef _MSC_VER
														       std::strftime(timeStamp, timeStampSize, fmt, &timeInfong(pop)
#endif

																     // end catch_tostring.h
#include <iosfwd>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4389) // '==' : signed/unsigned mismatch
#pragma warning(disable:4018) // more "signed/unsigned mismatch"
#pragma warning(disable:4312) // Converting int to T* using reinterpret_cast (issue on x64 platform)
#pragma warning(disable:4180) // qualifier applied to function type has no meaning
#pragma warning(disable:4800) // Fomplain if it's not here :-(
																     virtual ~ITransientExpression();

																     bool m_isBinaryExpression;
																     bool m_result;

																     };

														       void formatReconstructedExpression( std::ostream &os, std::string const& lhs, StringRef op, std::string const& rhs );

														       template<typename LhsT, typename RhsT>
														       class BinaryExpr  : public ITransientExpression {
															 LhsT m_lhs;
															 StringRef m_opsert(always_false<T>::value,
            "chained comparisons are not supported inside assertions, "
																	    "wrap the expression inside parentheses, or decompose it");
														       }

														       template<typename T>
														       auto operator || ( T ) const -> BinaryExpr<LhsT, RhsT const&> const {
															 static_assert(always_false<T>::value,
            "chained comparisons are not supported inside assertions, "
																       "wrap the expression inside parentheses, or decompose it")ssertions, "
            "wrap the expression inside parentheses, or decompose it");
        }

        template<typename T>
        auto operator > ( T ) const -> BinaryExpr<LhsT, RhsT const&> const {
            static_assert(always_false<T>::value,
            "chained comparisons are not supported inside assertions, "
            "wrap the expression inside parentheses, or decompose it");
        }

        template<typename T>
        auto operator < ( T ) const -> Binar   }

        template<typename T>
        auto operator <= ( T ) const -> BinaryExpr<LhsT, RhsT const&> const {
            static_assert(always_false<T>::value,
            "chained comparisons are not supported inside assertions, "
            "wrap the expression inside parentheses, or decompose it");
        }
    };

    template<typename LhsT>
    class UnaryExpr : public ITransientExpression {
        LhsT m_lhs;

        void streamReconstructedExpression( std::ostream &os ) const override {
            os << Catch::Detail::sme T>
    auto compareEqual( T* const& lhs, int rhs ) -> bool { return lhs == reinterpret_cast<void const*>( rhs ); }
    template<typename T>
    auto compareEqual( T* const& lhs, long rhs ) -> bool { return lhs == reinterpret_cast<void const*>( rhs ); }
    template<typename T>
    auto compareEq const& rhs ) -> bool { return reinterpret_cast<void const*>( lhs ) != rhs; }
    template<typename T>
    auto compareNotEqual( long lhs, T* const& rhs ) -> bool { return reinterpret_cast<void const*>( lhs ) != rhs; }

    template<typename LhsT>
    class ExprLhs {
        LhsT m_lhs;
    public:
      }

        template<typename RhsT>
        auto operator > ( RhsT const& rhs ) -> BinaryExpr<LhsT, RhsT const&> const {
            return { static_cast<bool>(m_lhs > rhs), m_lhs, ">", rhs };
        }
        template<typename RhsT>
        auto operssertions, "
															   "wrap the expression inside parentheses, or decompose it");
														       }

				    template<typename RhsT>
				    auto operator || ( RhsT const& ) -> BinaryExpr<LhsT, RhsT const&> const {
				    static_assert(always_false<RhsT>::value,
            "operator|| is not supported inside assertions, "
            "wrap the expression inside p end namespace Catch

#ifdef _MSC_VER
#pragma warning(pop)
#endif

// end catch_decomposer.h
// start catch_interfaces_capture.h

#include <string>

namespace Catch {

    class AssertionResult;
    struct AssertionInfo;
    struct SectionInfo;
    struct SectrkInfo const& info ) = 0;
        virtual void benchmarkEnded( BenchmarkStats const& stats ) = 0;

        virtual void pushScopedMessage( MessageInfo const& message ) = 0;
        virtual void popScopedMessage( MessageInfo const& message ) = 0;

        virtual void emplaceUnscopedMessage( MessageBuilder const& builder ) = 0;

        virtual void handleFatalErrorCondition( StringRef message ) = 0;

        virtual void handleExpr
                (   AssertionInfo const& info,
                    ITransientExpightException
                (   AssertionInfo const& info,
                    std::string const& message,
                    AssertionReaction& reaction ) = 0;
        virtual void handleIncomplete
                (   AssertionInfo const& info ) = 0;
        virtual void handleNonExpr
                (   AssertionInfo const &info,
                    ResultWas::OfType resultType,
                    AssertionReaction &reaction ) = 0;

        virtualonHandler;
        friend struct AssertionStats;
        friend class RunContext;

        ITransientExpression const* m_transientExpression = nullptr;
        bool m_isNegated;
    public:
        LazyExpression( bool isNegated );
        LazyExpression( LazyExpression const& other );
        LazyExpression& operator = ( LazyExpression const& ) = delete;

        explicit operator bool() const;

        friend auto operator << ( std::ostream& os, LazyExpression const& lazyExpr ) -> std::ostream&;
    };

    struct AssertionReaction {
        bool shouldDebugBreak = false;
        bool shouldThrow = false;
    };

    clultDisposition );
        ~AssertionHandler() {
            if ( !m_completed ) {
                m_resultCapture.handleIncomplete( m_assertionInfo );
            }
        }

        template<typename T>
        void handleExpr( ExprLhs<T> const& expr ) {
            handleExpr( expr.makeUnaryExpr() );
        }
        void handleExpr( ITransientExpression const& expr );

        void handleMessage(ResultWas::OfType resultType, StringRef const& message);

        void handleExceptionThrownAsExpected();
        void handleUnexpectedExceptionNotThrown();
        void handleExceptionNotThrownAsExpected();
        void handleThrowingCallSkipped();
        void handleUnexpectedInflightException();

        void complete();
        void setCompleted();

        // query
        auto allowThrows() const -> bool;
    };

    void handleExceptionMatchExpr( AssertionHandler& handler, std::string const& str, StringRef const& matcherString );

} // namespace Catch

// end catch_assertionhandler.h
// start catch_message.h

#include <string>
#include <vector>

namespace Catch {

    struct MessageInfo {
        MessageInfo(    StringRef const& _macroName,
                        SourceLineInfo const& _lineInfo,
                        ResultWas::OfType _type );

        StringRef macroName;
        std::string message;
        SourceLineInfo lineInfo;
        ResultWas::OfType type;
        unsigned int sequence;

        bool operator == ( MessageInfo const& other ) const;
        bool operator < ( MessageInfo const& other ) const;
    private:
        static unsigned int globalCount;
    };

    struct MessageStream {

        template<typename T>
        MessageStream& operator << ( T const& value ) {
            m_stream << value;
            return *this;
        }

        ReusableStringStream m_stream;
    };

    struct MessageBuilder : MessageStream {
        MessageBuilder( StringRef const& macroName,
                        SourceLineInfo const& lineInfo,
                        ResultWas::OfType typtemplate<typename T>
        MessageBuilder& operator << ( T const& value ) {
            m_stream << value;
            return *this;
        }

        MessageInfo m_info;
    };

    class ScopedMessage {
    public:
        explicit ScopedMessage( MessageBuilder const& builder );
        ScopedMessage( ScopedMessage& duplicate ) = delete;
        ScopedMessage( ScopedMessage&& old );
        ~ScopedMessage();

        MessageInfo m_info;
        bool m_moved;
    };

    class Capturer {
        std::vector<MessageInfo> m_messages;
        IResultCapture& m_resultCapture = getResultCapture();
        size_t m_captured = 0;
    public:
        Capturer( StringRef macroName, SourceLineInfo const& lineInfo, ResultWas::OfType resultType, StringRef names );
        ~Capturer();   }

        template<typename T, typename... Ts>
        void captureValues( size_t index, T const& value, Ts const&... values ) {
            captureValue( index, Catch::Detail::stringify(value) );
            captureValues( index+1, values... );
        }
    };

} // end namespace Catch

// end catch_message.h
#if !defined(CATCH_CONFIG_DISABLE)

#if !defined(CATCH_CONFIG_DISABLE_STRINGIFICATION)
  #define CATCH_INTERNAL_STRINGIFY(...) #__VA_ARGS__
#else
  #define CATCH_INTERNAL_STRINGIFY(...) "Disabled by CATCH_CONFIG_DISABLE_STRINGIFICATION"
#endif

#if defined(CATCH_CONFIG_FAST_COMPILE) || defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)

///////////////////////////////////////////////////////////////////////////////
// Another way to speed-up compilation is to omit local try-catch for REQUIRE*
// macros.
#define INTERNAL_CATCH_TRY
#define INTERNAL_CATCH_CATCH( capturer )

#else // CATCH_CONFIG_FAST_COMPILE

#define INTERNAL_CATCH_TRY try
#define INTERNAL_CATCH_CATCH( handler ) catch(...) { handler.handleUnexpectedInflightException(); }

#endif

#define INTERNAL_CATCH_REACT( handler ) handler.complete();

///////////////////////////////////////////////////////////////////////////////
#define INTERNAL_CATCH_TEST( macroName, resultDisposition, ... ) \
    do { \
        Catch::AssertionHandler catchAssertionHandler( macroName##_catch_sr, CATCH_INTERNAL_LINEINFO, CATCH_INTERNAL_STRINGIFY(__VA_ARGS__), resultDisposition ); \
        INTERNAL_CATCH_TRY { \
            CATCH_INTERNAL_SUPPRESS_PARENTHESES_WARNINGS \
            catchAssertionHandler.handleExpr( Catch::Decomposer() <= __VA_ARGS__ ); \
            CATCH_INTERNAL_UNSUPPRESS_PARENTHESES_WARNINGS \
        } INTERNAL_CATCH_CATCH( catchAssertionHandler ) \
        INTERNAL_CATCH_REACT( catchAssertionHandler ) \
    } while( (void)0, (false) && static_cast<bool>( !!(__VA_ARGS__) ) ) // the expression here is never evaluated at runtime but it forces the compiler to give it a look
    // The double negation silences MSVC's C4800 warning, the static_cast forces short-circuit evaluation if the type has overloaded &&.

///////////////////////////////////////////////////////////////////////////////
#define INTERNAL_CATCH_IF( macroName, resultDisposition, ... ) \
    INTERNAL_CATCH_TEST( macroName, resultDisposition, __VA_ARGS__ ); \
    if( Catch::getResultCapture().lastAssertionPassed() )

///////////////////////////////////////////////////////////////////////////////
#define INTERNAL_CATCH_ELSE( macroName, resultDisposition, ... ) \
    INTERNAL_CATCH_TEST( macroName, resultDisposition, __VA_ARGS__ ); \
    if( !Catch::getResultCapture().lastAssertionPassed() )

///////////////////////////////////////////////////////////////////////////////
#define INTERNAL_CATCH_NO_THROW( macroName, resultDisposition, ... ) \
    do { \
        Catch::AssertionHandler catchAssertionHandler( macroName##_catch_sr, CATCH_INTERNAL_LINEINFO, CATCH_INTERNAL_STRINGIFY(__VA_ARGS__), resultDisposition ); \
        try { \
            static_cast<void>(__VA_ARGS__); \
            catchAssertionHandler.handleExceptionNotThrownAsExpected(); \
        } \
        catch( ... ) { \
            catchAssertionHandler.handleUnexpectedInflightException(); \
        } \
        INTERNAL_CATCH_REACT( catchAssertionHandler ) \
    } while( false )

///////////////////////////////////////////////////////////////////////////////
#define INTERNAL_CATCH_THROWS( macroName, resultDisposition, ... ) \
    do { \
        Catch::AssertionHandler catchAssertionHandler( macroName##_catch_sr, CATCH_INTERNAL_LINEINFO, CATCH_INTERNAL_STRINGIFY(__VA_ARGS__), resultDisposition); \
        if( catchAssertionHandler.allowThrows() ) \
            try { \
                static_cast<void>(__VA_ARGS__); \
                catchAssertionHandler.handleUnexpectedExceptionNotThrown(); \
            } \
            catch( ... ) { \
                catchAssertionHandler.handleExceptionThrownAsExpected(); \
            } \
        else \
            catchAssertionHandler.handleThrowingCallSkipped(); \
        INTERNAL_CATCH_REACT( catchAssertionHandler ) \
    } while( false )

///////////////////////////////////////////////////////////////////////////////
#define INTERNAL_CATCH_THROWS_AS( macroName, exceptionType, resultDisposition, expr ) \
    do { \
        Catch::AssertionHandler catchAssertionHandler( macroName##_catch_sr, CATCH_INTERNAL_LINEINFO, CATCH_INTERNAL_STRINGIFY(expr) ", " CATCH_INTERNAL_STRINGIFY(exceptionType), resultDisposition ); \
        if( catchAssertionHandler.allowThrows() ) \
            try { \
                static_cast<void>(expr); \
                catchAssertionHandler.handleUnexpectedExceptionNotThrown(); \
            } \
            catch( exceptionType const& ) { \
                catchAssertionHandler.handleExceptionThrownAsExpected(); \
            } \
            catch( ... ) { \
                catchAssertionHandler.handleUnexpectedInflightException(); \
            } \
        else \
            catchAssertionHandler.handleThrowingCallSkipped(); \
        INTERNAL_CATCH_REACT( catchAssertionHandler ) \
    } while( false )

///////////////////////////////////////////////////////////////////////////////
#define INTERNAL_CATCH_MSG( macroName, messageType, resultDisposition, ... ) \
    do { \
        Catch::AssertionHandler catchAssertionHandler( macroName##_catch_sr, CATCH_INTERNAL_LINEINFO, Catch::StringRef(), resultDisposition ); \
        catchAssertionHandler.handleMessage( messageType, ( Catch::MessageStream() << __VA_A_CATCH_UNIQUE_NAME( scopedMessage )( Catch::MessageBuilder( macroName##_catch_sr, CATCH_INTERNAL_LINEINFO, Catch::ResultWas::Info ) << log );

///////////////////////////////////////////////////////////////////////////////
#define INTERNAL_CATCH_UNSCOPED_INFO( macroName, log ) \
    Catch::getResultCapture().emplaceUnscopedMessage( Catch::MessageBuilder( macroName##_catch_sr, CATCH_INTERNAL_LINEINFO, Catch::ResultWas::Info ) << log )

///////////////////////////////////////////////////////////////////////////////
// Although this is matcher-based, it can be used with just a string
#define INTERNAL_CATCH_THROWS_STR_MATCHES( macroName, resultDisposition, matcher, ... )       catchAssertionHandler.handleUnexpectedExceptionNotThrown(); \
            } \
            catch( ... ) { \
                Catch::handleExceptionMatchExpr( catchAssertionHandler, matcher, #matcher##_catch_sr ); \
            } \
        else \
            canst& other );

        Totals delta( Totals const& prevTotals ) const;

        int error = 0;
        Counts assertions;
        Counts testCases;
    };
}

// end catch_totals.h
#include <string>

namespace Catch {

    struct SectionInfo {
        SectionInfo
       etEstimatedClockResolution() -> uint64_t;

    class Timer {
        uint64_t m_nanoseconds = 0;
    public:
        void start();
        auto getElapsedNanoseconds() const -> uint64_t;
        auto getElapsedMicroseconds() const -> uint64_t;
        auto getElapsedMilliseconds() const -> unsigned int;
        auto getElapsedSeconds() const -> double;
  = Catch::SectionInfo( CATCH_INTERNAL_LINEINFO, __VA_ARGS__ ) ) \
    CATCH_INTERNAL_UNSUPPRESS_UNUSED_WARNINGS

#define INTERNAL_CATCH_DYNAMIC_SECTION( ... ) \
    CATCH_INTERNAL_SUPPRESS_UNUSED_WARNINGS \
    if( Catch::Section const& INTERNAL_CATCH_UNIQUE_NAME( catch_internal_Section ) = Catch::SectionInfo( CATCH_INTERNAL_LINEINFO, (Catch::ReusableStrtart();
            m_timer.start();
        }

        explicit operator bool() {
            if( m_count < m_iterationsToRun )
                return true;
            return needsMoreIterations();
        }

        void increment() {
            ++m_count;
        }

        void reportStart();
        auto needsMoreIterations() -> bool;
    };

} // end namespace Catch

#define BENCHMARK( name ) \
    for( Catch::BenchmarkLooper looper( name ); looper; looper.increment() )

// end catch_benchmark.h
// start catch_inteHub {
        virtual ~IRegistryHub();

        virtual IReporterRegistry const& getReporterRegistry() const = 0;
        virtual ITestCaseRegistry const& getTestCaseRegistry() const = 0;
        virtual ITagAliasRegistry const& getTagAliasRegistry() const = 0;
        virtual IExceptionTranslatorRegiserStartupException() noexcept = 0;
        virtual IMutableEnumValuesRegistry& getMutableEnumValuesRegistry() = 0;
    };

    IRegistryHub const& getRegistryHub();
    IMutableRegistryHub& getMutableRegistryHub();
    void cleanUp();
    std::string translateActiveException();

}

// end catch_interfaces_registry_hub.h
#if defined(CATCH_CONFIG_DISABLE)
    #define INTERNAL_CATCH_TRANSLATE_EXCEPTION_NO_REG( translatorName, signature) \
        static std::string translatorName( signature )
#endif

#include <exception>
#include <string>
#include <vector>

namespace Catch {
    using exceptionTranslateFunction = std::string(*)();

           virtual ~IExceptionTranslatorRegistry();

        virtual std::string translateActiveException() const = 0;
    };

    class ExceptionTranslatorRegistrar {
        template<typename T>
        class ExceptionTranslator : public IExceptionTranslator {
        public:

            ExceptionTranslator( std::string(*translateFunction)( T& ) )emplate<typename T>
        ExceptionTranslatorRegistrar( std::string(*translateFunction)( T& ) ) {
            getMutableRegistryHub().registerTranslator
                ( new ExceptionTranslator<T>( translateFunction ) );
        }
    };
}

///////////////////////////////////////////////////////////////////////////////
#define INTERNAL_CATCH_TRANSLATE_EXCEPTION2( translatorName, sign Detail {

    class Approx {
    private:
        bool equalityComparisonImpl(double other) const;
        // Validates the new margin (margin >= 0)
        // out-of-line tpe>
        explicit Approx( T const& value ): Approx(static_cast<double>(value))
        {}

        template <typename T, typename = typename std::enable_if<std::is_constructible<double, T>::value>::type>
        friend bool operator == ( const T& lhs, Approx cnst& lhs, T const& rhs ) {
            return !operator==( rhs, lhs );
        }

        template <typename T, typename = typename std::enable_if<std::is_constructible<double, T>::value>::type>
        friend bool operator <= ( T const& lhs, Approx const& rhs ) {
            return static_cast<double>(lhs) < rhs.m_value || lhs == rhs;
        }

        template <typename T, typename = typename std::enable_if<std: >= ( Approx const& lhs, T const& rhs ) {
            return lhs.m_value > static_cast<double>(rhs) || lhs == rhs;
        }

        template <typename T, typename = typename std::enable_if<std::is_constructible<double, T>::value>::type>
        Approx& epsilon( T const& newEpsilon ) {
            double epsilonAsDouble = static_cast<double>(newEpsilon);
            setEpsilon(epsilonAsDouble);
            return *this;
        }

        template <typename T, typename = typename std::enable_if<std::is_constructible<double, T>::value>::type>
        Approx& margin( T const& newMargin ) {
            double marginAsDouble = static_cast<double>(newMargin);
            setMargin(marginAsDouble);
            return *this;
        };

    private:
        double m_epsilon;
        double m_margin;
        double m_scale;
        double m_value;
    };
} // end namespace Detail

namespace literals {
    Detail::Approx operator "" _a(long double val);
    Detail::Approx operator "" _a(unsigned long long val);
} // end namespace literals

template<>
struct StringMaker<Catch::Detail::Approx> {
    static std::string convert(Catch::Detail::Approx const& value);
};

} // end namespace Catch

// end catch_approx.h
// start catch_string_manip.h

#include <string>
#include <iosfwd>
#include <vector>

namespace Catch {

 rim( std::string const& str );

    // !!! Be aware, returns refs into original string - make sure original string outlives them
    std::vector<StringRef> splitStringRef( StringRef str, char delimiter );
    bool replaceInPlace( std::string& str, std::string const& replaceThis, std::string const& withThis );

    struct pluralise {
        pluralise( std::size_t count, std::string const& label );

        friend std::ostream& operator << ( std::ostream& os, pluralise const& pluraliser );

        st() = default;
            MatcherUntypedBase ( MatcherUntypedBase const& ) = default;
            MatcherUntypedBase& operator = ( MatcherUntypedBase const& ) = delete;
            std::string toString() const;

        protected:
            virtual ~MatcherUntypedBase();
            virtual std::string describe() const = 0;
            mutable std::string m_cachedToString;
        };

#ifdef __clang__
#    pragma clang diagnostic push
#    pragma clang diagnostic ignored "-Wnon-virtual-dtor"
#endif

        template<typename ObjectT>
        struct MatcherMethod {
            virtual bool match( ObjectT const& arg ) const = 0;
        };

#ifdef __clang__
#    pragma clang diagnostic pop
#endif

        template<typename T>
        struct MatcherBase : Matchelate<typename ArgT>
        struct MatchAllOf : MatcherBase<ArgT> {
            bool match( ArgT const& arg ) const override {
                for( auto matcher : m_matchers ) {
                    if (!matcher->match(arg))
                        return false;
                }
                return true;
            }
            std::string describe() const override {
                std::string description;
                description.reserve( 4 + m_matchers.size()*32 );
                descripk( &other );
                return *this;
            }

            std::vector<MatcherBase<ArgT> const*> m_matchers;
        };
        template<typename ArgT>
        struct MatchAnyOf : MatcherBase<ArgT> {

            bool match( ArgT const& arg ) const override {
                for( auto matcher : m_matchers ) {
                    if (matcdescription;
            }

            MatchAnyOf<ArgT>& operator || ( MatcherBase<ArgT> const& other ) {
                m_matchers.push_back( &other );
                return *this;
            }

            std::vector<MatcherBase<ArgT> const*> m_matchers;
        };

        template<typename ArgT>
        struct MatchNotOf : MatcherBase<ArgT> {

            MatchNotOf( MatcherBase<ArgT> const& underlyingMatcher ) : m_underlyingMatcher( underlyingMatcher ) {}

            bhAnyOf<T> MatcherBase<T>::operator || ( MatcherBase const& other ) const {
            return MatchAnyOf<T>() || *this || other;
        }
        template<typename T>
        MatchNotOf<T> MatcherBase<T>::operator ! () const {
            return MatchNotOf<T>( *this );
        }

    } // namespace Impl

} // namespace Matchers

using namespace Matchers;
using Matchers::Impl::MatcherBase;

} // namespace Catch

// end catch_matchers.h
// start catch_matchers_floating.h

#include <type_traits>
#include <cmath>

namespace Catch lpsMatcher(double target, int ulps, FloatingPointKind baseType);
            bool match(double const& matchee) const override;
            std::string describe() const override;
        private:
            double m_target;
            int m_ulps;
            FloatingPointKind m_type;
        };

    } // namespace Floating

    // The following functions create the actual matcher objects.
    // This allows the types to be inferred
    Floating::WithinUlpsMatcher WithinULP(double target, int maxUlpDiff);
    Floating::WithinUlpsMatcher WithinULP(float target, int maxUlpT> {
    std::function<bool(T const&)> m_predicate;
    std::string m_description;
public:

    PredicateMatcher(std::function<bool(T const&)> const& elem, std::string const& descr)
        :m_predicate(std::move(elem)),
        m_description(Detail::finalizeDescription(descr))
    {}

    bool match( T const& item ) const override {
        return m_predicate(item);
    }

    std::string describe() const override {
        return m_description;
    }
}s_generic.hpp
// start catch_matchers_string.h

#include <string>

namespace Catch {
namespace Matchers {

    namespace StdString {

        struct CasedString
        {
            CasedString( std::string const& str, CaseSensitive::Choice caseSensitivity );
            std::string adjustString( std::string const& str ) const;
            std::string caseSensitivitySuffix() const;

            CaseSensitive::Choice m_caseSensitivity;
            std::string m_str;
        };

        struct StringMatcherBase : MatcherBase<std::string> {
            StringMatc         ContainsMatcher( CasedString const& comparator );
            bool match( std::string const& source ) const override;
        };
        struct StartsWithMatcher : StringMatcherBase {
            StartsWithMatcher( CasedString const& comparator );
            bool match( std::string const& source ) const override;
        };
        struct EndsWithMatcher : StringMatcherBase {
            EndsWithMatcher( CasedString const& comparator );
            bool match( std::string const& source ) const override;
        };

        struct RegexMatcher : MatcherBase<std::string> {
            RegexMatcher( std::string regex, CaseSensitive::Choice caseSensitivity );
            bool match( std::string const& matchee ) const override;
            std::string de the types to be inferred

    StdString::EqualsMatcher Equals( std::string const& str, CaseSensitive::Choice caseSensitivity = CaseSensitive::Yes );
    StdString::ContainsMatcher Contains( std::string const& str, CaseSensitive::Choice caseSensitivity = CaseSensitive::Yes );
    StdString::EndsWithMatcher EndsWith( std::string const& str, CaseSensitive::Choice caseSensitivity = CaseSensitive::Yes );
    StdString::StartsWithMatcher StartsWith( std::string const& str, CaseSensitive::Choice caseSensitivity = CaseSensitive::Yes );
    StdString::Rtor( comparator) {}

            bool match(std::vector<T> const &v) const override {
                for (auto const& el : v) {
                    if (el == m_comparator) {
                        return true;
                    }
                }
                return false;
            }

            std::string describe() const override {
                return "Contains: " + ::Catch::Detail::stringify( m_comparator );
            }

            T const& m_comparator;
        };

        template<typename T>
        struct ContainsMatcher : MatcherBase<std::vector<T>> {

            ContainsMatcher(std::vectoel : v) {
                        if (el == comparator) {
                            present = true;
                            break;
                        }
                    }
                    if (!present) {
                        return false;
                    }
                }
                return true;
            }
            std::string describe() const override {
                rpecialised for, e.g. std::vector<T> etc
                // - then just call that directly
                if (m_comparator.size() != v.size())
                    return false;
                for (std::size_t i = 0; i < v.size(); ++i)
                    if (m_comparator[i] != v[i])
                        return false;
                return true;
            }
            std::string describe() const override {
                return "Equals: " + ::Catch::Detail::stringify( m_comparator );
            }
            std::vector<T> const& m_comparator;
        };

        template<typename T>
        struct ApproxMatcher : MatcherBase<std::vector<T>> {

                        return false;
                return true;
            }
            std::string describe() const override {
                return "is approx: " + ::Catch::Detail::stringify( m_comparator );
            }
            template <typename = typename std::enable_if<std::is_constructible<double, T>::value>::type>
            ApproxM;
            mutable Catch::Detail::Approx approx = Catch::Detail::Approx::custom();
        };

        template<typename T>
        struct UnorderedEqualsMatcher : MatcherBase<std::vector<T>> {
            UnorderedEqualsMatcher(std::vector<T> const& target) : m_target(target) {}
            bool match(std::vector<T> const& vec) const override {
                // Note: This is a reimplementation of std::is_permutation,
                //       beual matcher objects.
    // This allows the types to be inferred

    template<typename T>
    Vector::ContainsMatcher<T> Contains( std::vector<T> const& comparator ) {
        return Vector::ContainsMatcher<T>( comparator );
    }

    template<typename T>
    Vector::ContainsElementMatcher<T> VectorContains( T const& comparator ) {
        return Vector::ContainsElementMatcher<T>( comparator );
    }
rgT, typename MatcherT>
    class MatchExpr : public ITransientExpression {
        ArgT const& m_arg;
        MatcherT m_matcher;
        StringRef m_matcherString;
    public:
        MatchExpr( ArgT const& arg, MatcherT const& matcher, StringRef const& matcherString )
        :   ITransientExpression{ true, matcher.match( arg ) },
            m_arg( arg ),
            m_matcher( matcher ),
            m_matcherString( matcherString )
        {}

        void streamReconstru   template<typename ArgT, typename MatcherT>
    auto makeMatchExpr( ArgT const& arg, MatcherT const& matcher, StringRef const& matcherString  ) -> MatchExpr<ArgT, MatcherT> {
        return MatchExpr<ArgT, MatcherT>( arg, matcher, matcherString );
    }

} // namespace Catch

///////////////////////////////////////////////////////////////////////////////
#define INTERNAL_CHECK_THAT( macroName, matcher, resultDisposWS_MATCHES( macroName, exceptionType, resultDisposition, matcher, ... ) \
    do { \
        Catch::AssertionHandler catchAssertionHandler( macroName##_catch_sr, CATCH_INTERNAL_LINEINFO, CATCH_INTERNAL_STRINGIFY(__VA_ARGS__) ", " CATCH_INTERNAL_STRINGIFY(exceptionType) ", " CATCH_INTERNAL_STRINGIFY(matcher), resultDisposition ); \
        if( catchure_matchers.h
#endif
// start catch_generators.hpp

// start catch_interfaces_generatortracker.h


#include <memory>

namespace Catch {

    namespace Generators {
        class GeneratorUntypedBase {
        public:
            GeneratorUntypedBase() = default;
            virtual ~GeneratorUntypedBase();
            // Attempts to move the generator to the next element
             //
             // Returns true iff the move succeeded (and a valt catch_enforce.h

#include <stdexcept>

namespace Catch {
#if !defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)
    template <typename Ex>
    [[noreturn]]
    void throw_exception(Ex const& e) {
        throw e;
    }
#else // ^^ Exceptions are enabled //  Exceptions are disabled vv
    [[noreturn]]
    void throw_exception(std::exception const& e);
#endif
} // namespace Catch;

#define CATCH_PREPARE_EXCEPTION( type, msg ) \
    type( ( Catch::ReusableStringStream() << msg ).str(nclude <vector>
#include <cassert>

#include <utility>
#include <exception>

namespace Catch {

class GeneratorException : public std::exception {
    const char* const m_msg = "";

public:
    GeneratorException(const char* msg):
        m_msg(msg)
    {}ueGenerator final : public IGenerator<T> {
        T m_value;
    public:
        SingleValueGenerator(T const& value) : m_value( value ) {}
        SingleValueGenerator(T&& value) : m_value(std::move(value)) {}

        T const& get() rator(std::move(generator))
        {}
        T const& get() const {
            return m_generator->get();
        }
        bool next() {
            return m_generator->next();
        }
    };

    template <typename T>
    GeneratorWrapper<T> value(T&& value) {
        return GeneratorWrapper<T>(pf::make_unique<SingleValueGenerator populate(T(std::move(val)));
        }
        template<typename U, typename... Gs>
        void populate(U&& valueOrGenerator, Gs... moreGenerators) {
            populate(std::forward<U>(valuealizer_list<std::tuple<typename std::decay<Ts>::type...>> tuples ) {
        return values<std::tuple<Trs<T> {
        return makeGenerators( value( T( std::forward<U>( val ) ) ), std::forward<Gs>( moreGenerators )... );
    }

    auto acquireGeneratorTracker( SourceLineIspace Generators
} // namespace Catch

#define GENERATE( ... ) \
    Catch::Generators::generate( CATCH_INTERNAL_LINEINFO, [ ]{ using namespace Catch::Generators; return makeGenerators( __VA_ARGS__ ); } )
#define GENERATE_COPY( ... ) \
    Catch::Generators::generate( = 0 && "Empty generators are not allowed");
        }
        T const& get() const override {
            return m_generator.get();
        }
        bool next() override {
            ++m_returned;
            if (m_returned >= m_target) {
                return false;
            }

            const auto success = m_generator.next(); FilterGenerator(P&& pred, GeneratorWrapper<T>&& generator):
            m_generator(std::move(generator)),
            m_predicate(std::forward<P>(pred))
        {
            if (!m_predicate(m_generator.get())) {
                // It might happen that there are no values that pass the
                // filter. In that case we throw an exception.
                auto has_initial_value = next();
                if (!has_initial_value) {
                    Catch::throw_exception(GeneratorException("No valid value found in fi   GeneratorWrapper<T> filter(Predicate&& pred, GeneratorWrapper<T>&& generator) {
      return GeneratorWrapper<T>(std::unique_ptr<IGenerator<T>>(pf::make_unique<FilterGenerator<T, Predicate>>(std::forward<Predturned[m_repeat_index];
													       }

								bool next() over   template <typename T>
								GeneratorWrapper<T> repeat(size_t repeats, Generator if (success) {
								    m_cache = m_function(m_generator.get());
								  }
								  return success;
								  }
								};

#if defined(__cpp_lib_is_invocable) && __cpp_lib_is_invocable >= 201703
				 // std::result_of is deprecated in C++17 and removed in C++20. Hence, it is
				 // replaced with std::invoke_result here. Also *_t format is pion), std::move(generator))
				 );
    }

						  template <typename T, typename U, typename Func>
						  GeneratorWrapper<T> map(Func&& function, GeneratorWrapper<U>&& generator) {
						    return GeneratorWrapper<T>(
									       pf::make_unique<MapGenerator<T, U, Func>>(std::forward<Func>(function), std::move(generator))
									       );
						  }

						  template <typename T>
						  class ChunkGenerator final : public IGenerator<std::vector<T>> {
						    std::vector<T> m_chunk;
						    size_t m_chunk_size;
        Generunk"));
                }
                m_chunk.push_back(m_generator.get());
            }
        }
        std::vector<T> const& get() const override {
            return m_chunk;
        }
        bool next() override {
            m_chunk.clear();
            for (size_t idx = 0; idx < m_chunk_size; ++truct IConfig;
    struct IMutableContext;

    using IConfigPtr = std::shared_ptr<IConfig const>;

    struct IContext
    {
        virtual ~IContext();

        virtual IResultCapture* getResultCapture() = 0text& getCurrentContext()
    {
        return getCurrentMutableContext();
    }

    void cleanUpContext();
}

// end catch_context.h
// start catch_interfaces_config.h

#include <iosfwd>
#include <string>
#include <vector>
#include <memory>

namespace Catch {

    enum class Verbosity {
        Qu      virtual ~IConfig();

        virtual bool allowThrows() const = 0;
        virtual std::ostream& stream() const = 0;
        virtual std::string namonst = 0;
        virtual Verbosity verbosity() const = 0;
    };

    using IConfigPtr = std::shared_ptr<IConfig const>;
}

// end catch_interfaces_config.h
#include <random>

namespace Catch {
nic:

    RandomIntegerGenerator(Integer a, Integer b):
        m_rand(getCurrentContext().getConfig()->rngSeed()),
        m_dist(a, or final : public IGenerator<T> {
    T m_current;
    T m_end;
    T m_step;
    bool m_positive;

public:
    RangeGenerator(T const& start, T const& end, T const& step):
        m_current(start),
     !std::is_same<T, bool>::value, "Type must be an integer");
    return GeneratorWrapper<T>(pf::make_unique<RangeGenerator<T>>(start, end, st << 3,
            Throws = 1 << 4,
            NonPortable = 1 << 5,
            Benchmark = 1 << 6
        };

      o&& info );

        TestCase withName( std::string const& _newName ) const;

        void invoke() const;

        TestCaseInfo const& getTestCaseInfo() const;

        bool operast to make sure they are included by the single
// header for non obj-usage

///////////////////////////////////////////////////////////////////////////////
// This protocol is reallt& annotationName,
                                            std::string const& testCaseName ) {
            NSString* selStr = [[NSString alloc] initWithFormat:@"Catch_%s_%s", annotationName.c_str(), testCaseName.c_str()];
            SEL sel = NSSelectorFromString( selStr );
            arcSafent ; m++ ) {
                    SEL selector = method_getName(methods[m]);
            amespace NSStringMatchers {

            struct StringHolder : MatcherBase<NSString*>{
                StringHolder( NSString* substr ) : m_substr( [substr copy] ){}
                StringHolder( StringHolder const& other ) : m_substr( [other.m_substr copy] ){}
                StringHolder() {
                    arcSafeRelease( m_substr );
                }

              }
            };

            struct Contains : StringHolder {
                Contains( NSString* substr ) : ify( m_substr );
              ng* substr ){ return Impl::NSStringMatchers::Stt catch_interfaces_reporter.h

// start     };
}

// end catch_wildcard_pattern.h
#include <string>
#include <vector>
#include <memory>

namespace Catch {

    class TestSpec {
        struct Pattern {
            virtual ~Pattern();
            virtual bool matches( TestCaseInfo const& testCase ) const = 0;
        };
     nderlyingPattern );
            virtual ~ExcludedPattern();
            bool matches( TestCaseInfo const& testCase ) const override;
        private:
            PatternPtr m_underlyingPattern;
        };

        struct Filter {
            std::vector<PatternPtr> m_patterns;

          static ITagAliasRegistry const& get();
    };

} // end namespace Catch

// end catch_interfaces_tag_alias_registry.h
namespace Catch {

    class TestSpecParser {
        enum Mode{ None, Nai = 0; i < m_escapeChars.size(); ++i )
                token = token.substr( 0, m_escapeChars[i]-m_start-i ) + token.substr( m_escapering>

#ifndef CATCH_CONFIG_CONSOLE_WIDTH
#define CATCH_CONFIG_CONSOLE_WIDTH 80
#endif

namespace Catch {

    struct IStream;

    struct ConfigData {
        bool listTests = false;
        bool listTags = false;
        bool listReporters = false;
        bool listTestNamesOnly = false;

        bool showSuccessfulTests = falspress::Never;

        std::string outputFilename;
        std::string name;
        std::string processName;
#ifndef CATCH_CONFIG_DEFAULT_REPORTER
#define CATCH_CONFIG_DEFAULT_REPORTER "console"
#endif
        std::string reporterName = CATCH_CONFIG_DEFAULT_REPORTER;
#undef CATCH_CONFIG_DEFAULT_REPORTER

        std::vector<std::string> testsOrTags;
        std::vector<std::string> sectionsToRun;
    };

    class Config : public IConfig {
    public:

        Config() = default;
        Config( ConfigData const& data );
        virtual ~Config() = default;

        std::string const& getFilename() const;

        bool listTests() const;
        bool listTestNamesOnly() const;
        bool listTags()  testSpec() const override;
        bool hasTestFilters() const override;

        bool showHelp() const;

        // IConfig interface
        bool allowThrows() const override;
        std::ostream& stream() const override;
        std::string name() const override;
        bool includeSuccessfulResults() const override;
        bool warnAboutMissingAssertions() const override;
        bool warnAboutNoTests() const override;
        ShowDurations::OrNot showDurations() const override;
        RunTests::InWhatOrder runOrder() const override;
        unsigned int rngSeed() const override;
        int benchmarkResolutionMultiple() const override;
        UseCo   TestSpec m_testSpec;
        bool m_hasTestFilters = false;
    };

} // end namespace Catch

// end catch_config.hpp
// start catch_assertionresult.h

#include <string>

namespace Catch {

    struct AssertionResultData
    {
        AssertionResultData() = delete;

        AssertionResultData( ResultWas::OfType _resultType, LazyExpression const& _lazyExpression );

        std::string message;
        mutable std::string reconstructedExpression;
        LazyExpression lazyExpression;
        ResultWas::OfType resultType;

        std::sst;
        bool hasExpandedExpression() const;
        std::string getExpandedExpression() const;
        std::string getMessage() const;
        SourceLineInfo getSourceInfo() const;
        StringRef getTestMacroName() const;

    //protected:
        AssertionInfo m_info;
        AssertionResultData m_resultData;
    };

} // end namespace Catch

// end catch_assertionresult.h
// start catch_option.hpp

namespace Catch {

    // An optional type
    template<typenage ) T( *_other );
            }
            return *this;
        }
        Option& operator = ( T const& _value ) {
            reset();
            nullableValue = new( storage ) T( _value );
            return *this;
        }

        void reset() {
            if( nullableValue )
                nullableValue->~T();
            nullableValue = nullptr;
        }

        T& operator*() { return *nullableValue; }
        T const& operator*() const { return *nullablenullableValue;
        alignas(alignof(T)) char storage[sizeof(T)];
    };

} // end namespace Catch

// end catch_option.hpp
#include <string>
#include <iosfwd>
#include <map>
#include <set>
#include <memory>

namespace Catch {

    struct ReporterConfig {
        explicit ReporterConfig( IConfigPtr const& _fullConfig );

        ReporterConfig( IConfigPtr const& _fullConfig, std::ostream& _stream );

        std::ostream& stream() const;
        IConfigPtr fullConfig() const;

    private:
        std::ostream* m_stream;
        IConfigPtr m_fullConfig;
    };

    struct ReporterPreferences {
        bool shouldRedirectStdOut = false;
        bool shouldReportAllAssertions = false;
    };

    template<typename T>
    struct LazyStat : Option<T> {
        = false;
    };

    struct TestRunInfo {
        TestRunInfo( std::string const& _name );
        std::string name;
    };
    struct GroupInfo {
        GroupInfo(  std::string const& _name,
                    std::size_t _groupIndex,
                    std::size_t _groupsCount );

        std::string name;
        std::size_t groupIndex;
        std::size_t groupsCounts;
    };

    struct AssertionStats {
        AssertionStats( AssertionResult const& _assertionResult,
                        std::vector<MessageInfo> const& _infoMessages,
                        Totals const& _totals );

        AssertionStats( AssertionStats const& )              = default;
        AssertionStats( AssertionStats && )                  = default;tals totals;
    };

    struct SectionStats {
        SectionStats(   SectionInfo const& _sectionInfo,
                        Counts const& _assertions,
                        double _durationInSeconds,
                        bool         = default;
        TestCaseStats( TestCaseStats && )                  = default;
        TestCaseStats& operator = ( TestCaseStats const& ) = default;
        TestCaseStats& operator = ( TestCaseStats && )     = default;
        virtual ~TestCaseStats();

        TestCaseInfo testInfo;
        Totals totals;
        std::string stdOut;
        std::string stdErr;
 ting;
    };

    struct TestRunStats {
        TestRunStats(   TestRunInfo const& _runInfo,
                        Totals const& _totals,
                        bool _aborting );

        TestRunStats( TestRunStats const& )              = default;
        TestRunStats( TestRunStats && )                  = default;
        TestRunStats& operator = ( TestRunStats const& ) = default;
        TestRunStats& operator = ( TestRunStats && )     = dortedVerbosities()

        virtual ReporterPreferences getPreferences() const = 0;

        virtual void noMatchingTestCases( std::string const& spec ) = 0;

        virtual void testRunStarting( TestRunInfo const& testRunInfo ) = 0;
        virtual void testGroupStarting( GroupInfo const& groupInfo ) = 0;

        virtual void testCaseStarting( TestCaseInfo const& testInfo ) = 0;
        virtual void sectionStarting( SectionInfo const& sectionInfo ) = ats const& testCaseStats ) = 0;
        virtual void testGroupEnded( TestGroupStats const& testGroupStats ) = 0;
        virtual void testRunEnded( TestRunStats const& testRunStats ) = 0;

        virtual void skipTest( TestCaseInfo const& testInfo ) = 0;

        // Default empty implementation provided
        virtual void fatalErrorEncountered( StringRef name );

        virtual bool isMulti() const;
    };
    using IStreamingReporterPtr = std::::string const& name, IConfigPtr const& config ) const = 0;
        virtual FactoryMap const& getFactories() const = 0;
        virtual Listeners const& getListeners() const = 0;
    };

} // end namespace Catch

// end catch_interfaces_reporter.h
#include <algorithm>
#include <cstring>
#include <cfloat>
#include <cstdio>
#include <cassert>
#include <memory>
#include <ostream>

namespace Catch {
    void prepareExpandedExpression(AssertionResult& result);

    // Returns double formatted as %.3f (format expected on output)
    std::string getFormattedDurat.count( m_config->verbosity() ) )
                CATCH_ERROR( "Verbosity level not supported by this reporter" );
        }

        ReporterPreferences getPreferences() const override {
            return m_reporterPrefs;
        }

        static std::set<Verbosity> getSupportedVerbosities() {
            return { Verbosity::Normal };
        }

        ~StreamingReporterBase() override = default;

        void noMatchingTestCStats const& /* _sectionStats */) override {
            m_sectionStack.pop_back();
        }
        void testCaseEnded(TestCaseStats const& /* _testCaseStats */) override {
            currentTestCaseInfo.reset();
        }
        void testGroupEnded(TestGroupStats const& /* _testGroupStats */) override {
            currentGrouporterPreferences m_reporterPrefs;
    };

    template<typename DerivedT>
    struct CumulativeReporterBase : IStreamingReporter {
        template<typename T, typename ChildNodeT>
        struct Node {
            explicit Node( T const& _value ) : value( _value ) {}
            virtual ~Node() {}

            using ChildNodes = std::vector<std::shared_ptr<ChildNodeT>== g Assertions = std::vector<AssertionStats>;
            ChildSections childSections;
            Assertions assertions;
            std::string stdOut;
            std::string stdErr;
        };

        struct BySectionInfo {
            BySectionInfo( SectionInfo const& other ) : m_other( other ) {}
            BySectionInfo( BySectionInfo const& other ) : m_other( other.m_other ) {}
            bool operator() (std::shared_ptr<SectionNode> const& node) const {
                return ((node->stats.sectionInfo.name == m_other.name) &&       :   m_config( _config.fullConfig() ),
            stream( _config.stream() )
        {
            m_reporterPrefs.shouldRedirectStdOut = false;
            if( !DerivedT::getSupportedVerbosities().count( m_config->verbosity() ) )
                CATCH_ERROR( "Verbosity level not supported by this reporter" );
        }
        ~CumulativeReporterBase() override = default;

        ReporterPreferences getPreferences() const override {
            return m_reporterPrefs;
        }

        static std::set<Verbosity> getSupportedVerbosities() {
            return { Verbosity::Normal };
        }

        void testRunStarting( TestRunInfo const& ) override {}
        void testGroupStarting( GroupInfo const& ) override {}

        void testCaseStarting( TestCaseInfo const& ) override {}

        void sectionStarting( SectionInfo const& sectionInfo ) override {
            SectionStats incompleteStats( sectionInfo, Counts(), 0, false );
     nStack.empty() ) {
                if( !m_rootSection )
                    m_rootSection = std::make_shared<SectionNode>( incompleteStats );
                node = m_rootSection;
            }
            else {
                SectionNode& parentNode = *m_sectionStack.back();
                auto it =
                    std::find_if(   parentNode.childSections.begin(),
                                    parentNode.childSections.end(),
                                    BySectionInfo( sectionInfo ) );
                if( it == parentNode.childSections.end() ) {
                    node = std::make_shared<SectionNode>( incompleteStats );
                    parentNode.childSections.push_back( node );
                }
                else
                    node = *it;
            }
            m_sectionStack.push_back( node );
            m_deepestSection = std::move(node);
        }

      tionStats) override {
            assert(!m_sectionStack.empty());
            // AssertionResult holds a pointer to a temporary DecomposedExpression,
            // which getExpandedExpression() calls to build the expression string.
            // Our section stack copy of the assertionResult will likely outlive the
            // temporary, so it must be expanded or discarded now to avoid calling
            // a destroyed object later.
            prepareExpandedExpression(const_cast<AssertionResult&>( assertionStats.assertionResult ) );
            SectionNode& sectionNode = *m_sectionStack.back();
            sectionNode.assertions.push_back(asseeStats) override {
            auto node = std::make_shared<TestCaseNode>(testCaseStats);
            assert(m_sectionStack.size() == 0);
            node->children.push_back(m_rootSection);
            m_testCases.push_back(node);
            m_rootSection.reset();

            assert(m_deepestSection);
            m_deepestSection->stdOut = testCaseStats.stdOut;
            m_deepestSection->stdEd skipTest(TestCaseInfo const&) override {}

        IConfigPtr m_config;
        std::ostream& stream;
        std::vector<AssertionStats> m_assertions;
        std::vector<std::vector<std::shared_ptr<SectionNode>>> m_sections;
        std::vector<std::shared_ptr<TestCaseNode>> m_testCases;
        std::vector<std::shared_ptr<TestGroupNode>> m_testGroups;

        std::vector<std::shared_ptr<TestRunNode>> m_testRuns;

        std::shared_{
        TestEventListenerBase( ReporterConfig const& _config );

        static std::set<Verbosity> getSupportedVerbosities();

        void assertionStarting(AssertionInfo const&) override;
        bool assertionEnded(AssertionStats const&) override;
    };

} // end namespace Catch

// end catch_reporter_bases.hpp
// start catch_console_colour.h

namespace Catch {

    s         Error = BrightRed,
            Success = Green,

            OriginalExpression = Cyan,
            ReconstructedExpression = BrightYellow,

            SecondaryText = LightGrey,
            Headers = White
        };

        // Use constructed object for RAII guard
        Colour( Code _colour) );
            }

            std::string getDescription() const override {
                return T::getDescription();
            }
        };

    public:

        explicit ReporterRegistrar( std::string const& name ) {
            getMutablBALS_WARNINGS          \
    namespace{ Catch::ReporterRegistrar<reporterType> catch_internal_RegistrarFor##reporterType( name ); } \
    CATCH_INTERNAL_UNSUPPRESS_GLOBALS_WARNINGS

#define CATCH_REGISTER_LISTENER( listenerType ) \
     CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS   \
     namespace{ Catch::Lis    void noMatchingTestCases(std::string const& spec) override;

        void assertionStarting(AssertionInfo const&) override;

        bool assertionEnded(AssertionStats const& _assertionStats) override;

        void sectionEnded(SectionStats const& _sectionStats) override;

        void testRunEnded(TestRunStats coverride;
        static std::string getDescription();

        void noMatchingTestCases(std::string const& spec) override;

        void assertionStarting(AssertionInfo const&) override;

        bool assertionEnded(AssertionStats const& _assertionStats) override;

        void sectionStarting(SectionInfo const&stCaseAndSectionHeader();

        void printClosedHeader(std::string const& _name);
        void printOpenHeader(std::string const& _name);

        // if string has a : in first line will set indent to follow it on
        // subsequent lines
        void printHeaderString(std::string const& _string, std::size_t indent = 0);

        void printTotals(Totals const& totals);
  forWhat = ForTextNodes );

        void encodeTo( std::ostream& os ) const;

        friend std::ostream& operator << ( std::ostream& os, XmlEncode const& xmlEncode );

    private:
        std::string m_str;
        ForWhat m_forWhat;
    };

    class XmlWriter {
    public:

        class ScopedElement {
        publicWriter( XmlWriter const& ) = delete;
        XmlWriter& operator=( XmlWriter const& ) = delete;

        XmlWriter& startElement( std::string const& name );

        ScopedElement scopedElement( std::string const& name );

        XmlWriter& endElement();

        XmlWriter& writeAttribute( std::string const& name, std::string const& attribute );

        XmlWriter& writeAttribute( std::string const& name, bool attri);

        bool m_tagIsOpen = false;
        bool m_needsNewline = false;
        std::vector<std::string> m_tags;
        std::string m_indent;
        std::ostream& m_os;
    };

}

// end catch_xmlwriter.h
namespace Catch {

    class JunitReporter : public CumulativeReporterBase<JunitReporter> {
    public:
        JunitReporter(ReporterConfig const& _config);

        ~JunitReporter() od writeGroup(TestGroupNode const& groupNode, double suiteTime);

        void writeTestCase(TestCaseNode const& testCaseNode);

        void writeSection(std::string const& className,
                          std::string const& rootName,
                          SectionNode const& sectionNode);

        void writeAssertions(SectionNode const& sectionNode);
        void writeAssertion(AssertionStats const& stats);

        XmlWriter xml;ceInfo(SourceLineInfo const& sourceInfo);

    public: // StreamingReporterBase

        void noMatchingTestCases(std::string coh

// end catch_external_interfaces.h
#endif

#endif // ! CATCH_CONFIG_IMPL_ONLY

#ifdef CATCH_IMPL
// start catch_impl.hpp

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wweak-vtables"
#e Started but not complete
        virtual bool hasChildren() const = 0;

        virtual ITracker& parent() = 0;

        // actions
        virtual void close() = 0; // Successfully complete
        virtual void fail() = 0;
        virtual void markAsNeedingAnotherRun() = 0;

        virtual void addChild( ITrackerPtr cst;
        ITracker& currentTracker();
        void setCurrentTracker( ITracker* tracker );
    };

    class TrackerBase : public ITracker {
    protected:
        enum CycleState {
            NotStarted,
            Executing,
            ExecutingChildren,
            NeedsAnotherRun,
            CompletedSuccessfully,
            Failed
        };

        using ChildrfindChild( NameAndLocation const& nameAndLocation ) override;
        ITracker& parent() override;

        void openChild() override;

        bool isSectionTracker() const override;
        bool isGeneratorTracker() const override;

        void open();

        void c   };

} // namespace TestCaseTracking

using TestCaseTracking::ITracker;
using TestCaseTracking::TrackerContext;
using TestCaseTracking::SectionTracker;

} // namespace Catch

// end catch_test_case_tracker.h

// start catch_leak_detector.h

namespace Catch {

    struct LeakDetector {
        L     return Approx( 0 );
    }

    Approx Approx::operator-() const {
        auto temp(*this);
        temp.m_value = -temp.m_value;
        return temp;
    }

    std::string Approx::toString() const {
        ReusableStringStream rss;
        rss << "Approx( " << ::Catch::Detail::stringify newEpsilon) {
        CATCH_ENFORCE(newEpsilon >= 0 && newEpsilon <= 1.0,
            "Invalid Approx::epsilon: " << newEpsilon << '.'
            << " Approx::epsilon has to be in [0, 1]");
        m_epsilon = newEpsilon;
    }

} // end namesocation of the failing check instead of breaking inside
    // raise() called from it, i.e. one stack frame below.
    #if defined(__GNUC__) && (defined(__i386) || defined(__x86_64))
        #define CATCH_TRAP() asm volatile ("int $3") /* NOLINT */
    #elsNMAX
#endif
#if !defined(WIN32_LEAN_AND_MEAN) && !defined(CATCH_CONFIG_NO_WIN32_LEAN_AND_MEAN)
#  define CATCH_DEFINED_WIN32_LEAN_AND_MEAN
#  define WIN32_LEAN_AND_MEAN
#endif

#ifdef __AFXDLL
#include <AfxWin.h>
#else
#inc bool isSet;
        static struct sigaction oldSigActions[];
        static stack_t oldSigStack;
        static char altStackMem[];

        static void handleSignal( int sig );

        FatalConditionHandler();
        ~FatalConditionHandler();
        static voi testGroupEnded( std::string const& testSpec, Totals const& totals, std::size_t groupIndex, std::size_t groupsCount );

        Totals runTest(TestCase const& testCase);

        IConfigPtr config() const;
        IStreamingReporte,
                    AssertionReaction& reaction ) override;
        void handleIncomplete
                (   AssertionInfo const& info ) override;
        void handleNonExpr
                (   AssertionInfo const &info,
                    ResultW ) override;

        std::string getCurrentTestName() const override;

        const AssertionResult* getLastResult() const override;

        void exceptionEarlyReported() override;

        void handleFatalErrorCondition( StringRef message ) override;

        bool lastAssertionPassed() override;

        void assertionPassed() override;

    public:
        // !TBD We needvate:

        void handleUnfinishedSections();

        TestRunInfo m_runInfo;
        IMutableContext& m_context;
        TestCase const* m_activeTestCase = nullptr;
        ITracker* m_testCaseTracker = nullptr;
        Option<AssertionResult> m_lastResult;

        IConfigPtr m_config;
        Totals m_totals;
        IStreamingReporterPtr m_reporter;
        std::vector<Messag          expr.streamReconstructedExpression( os );
            return os;
        }
    }

    LazyExpression::LazyExpression( bool isNegated )
    :   m_isNegated( isNegated )
    {}

    LazyExpression::LazyExpression( LazyExpression const& other ) : m_isNegated( other.m_isNegated ) {}

    LazyExpression::operator bool() const {
        return m_transientExpression != nullptr;
    }

    auto operator << ( std::os        SourceLineInfo const& lineInfo,
            StringRef capturedExpression,
            ResultDisposition::Flags resultDisposition )
    :   m_assertionInfo{ macroName, lineInfo, capturedExpression, resultDisposition },
        m_resultCapture( getResultCapture() )
    {}

    void AssertionHandler::handleExpr( ITransientExpression consiled assertion)

            // (To go back to the test and change execution, jump over the throw, next)
            CATCH_BREAK_INTO_DEBUGGER();
        }
        if (m_reaction.shouldThrow) {
#if !defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)
            throw Catch::TestFailureException();
#else
            CATCH_ERROR( "Test failure requires aborting test!" );
#endif
        }
    }
    void AssertionHandler::setCompleted() {
        m_completed = true;
    }

 Thrown() {
        m_resultCapture.handleUnexpectedExceptionNotThrown( m_assertionInfo, m_reaction );
    }

    void AssertionHandler::handleThrowingCallSkipped() {
        m_resultCapture.handleNonExpr(m_assertionInfo, ResultWas::Ok, m_reaction);
    }

    // This is the overload that takes a s{

        if( reconstructedExpression.empty() ) {
            if( lazyExpression ) {
                ReusableStringStream rss;
                rss << lazyExpression;
                reconstructedExpression = rss.str();
            }
        }
        return reconstructedExpression;
    }

    AssertionResssertionResult::hasMessage() const {
        return !m_resultData.message.empty();
    }

    std::string AssertionResult::getExpression() const {
        if( isFalseTest( m_info.resultDisposition ) )
            return "!(" + m_info.capturedExpression + ")";
        else
            return m_info.capturedExpression;
    }

    std::string AssertionResult::getExpressionInMacro() const {
        std::string expr;
        if( m_info.macroName[0] == 0 )
            expr = m_info.capturedExpression;
        else {
            expr.reserve( m_info.macroName.size() + m_info.capturedExpression.size() + 4 );
            expr += m_info.macroName;
            expr += "( ";
            expr += m_info.capturedExpression;
            expr += ltData.reconstructExpression();
        return expr.empty()
                ? getExpression()
                : expr;
    }

    std::string AssertionResult::getMessage() const {
        return m_resultData.message;
    }
    SourceLineInfo AssertionResult::getSourceInfo() const {
        return m_info.lineInfo;
    }

    StringRef AssertionResult::getTestMacroName() const {
        return m_info.macroName;
    }

} // end namespace Catch
// end catch_assertionresult.cpp
// start catch_benchmark.cpp

namespace Catch {

    auto BenchmarkLooper::getResolution() -> uint64_t {
        return getEstimatedClockResolution() * getCurrentContext().getConfig()->benchmarkResolutionMultiple();
    }

    void BenchmarkLooper::reportStart() {
        getResultCapture().benchmarkStarting( { m_name } );
    }
    auto BenchmarkLooper::needsMoreIterations() -> bool {
     if( elapsed < m_resolution ) {
            m_iterationsToRun *= 10;
            return true;
        }

        getResultCapture().benchmarkEnded( { { m_name }, m_count, elapsed } );
        return false;
    }

} // end namespace Catch
// end catch_benchmark.cpp
// start catch_capture_matchers.cpp

namespace Catch {

    using StringMatcher = Matchers::Impl::MatcherBase<std::string>;

    // This is the general overload that takes a any string matcher
    // There is another overload, in catch_assertionhandler.h/.cpp, that only takes a string and infers
    // the Equals matcher (so the header does not mention matchers)
    void handleExceptionMatchExpr( AssertionHandler& handler, StringMatcher const& matcher, StringRef const& matcherString  ) {
        std::string exceptionMessage = Catch::translateActiveException();
        MatchExpr<std::sers.cpp
// start catch_commandline.cpp

// start catch_commandline.h

// start catch_clara.h

// Use Catch's value for console width (store Clara's off to the side, if present)
#ifdef CLARA_CONFIG_CONSOLE_WIDTH
#define CATCH_TEMP_CLARA_CONFIG_CONSOLE_WIDTH CATCH_CLARA_TEXTFLOW_CONFIG_CONSOLE_WIDTH
#undef CATCH_CLARA_TEXTFLOW_CONFIG_CONSOLE_WIDTH
#endif
#define CATCH_CLARA_TEXTFLOW_CONFIG_CONSOLE_WIDTH CATCH_CONFIG_CONSOLE_WIDTH-1

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostFIG_CONSOLE_WIDTH 80
#endif

#ifndef CATCH_CLARA_TEXTFLOW_CONFIG_CONSOLE_WIDTH
#define CATCH_CLARA_TEXTFLOW_CONFIG_CONSOLE_WIDTH CATCH_CLARA_CONFIG_CONSOLE_WIDTH
#endif

#ifndef CLARA_CONFIG_OPTIONAL_TYPE
#ifdef __has_include
#if __has_include(<optional>) && __cplusplus >= 201703L
#include <optional>
#define CLARA_CONFIG_OPTIONAL_TYPE std::optional
#endif
#endif
#endif

// ----------- #included from clara_textflow.hpp -----------

// TextFlowCpp
//
// A single-header library for wrapping and laying out basic text, by Phil Nash
//
// Distributed under the Boost Software License, Version 1.0. (See accomhitespace(char c) -> bool {
static std::string chars = " \t\n\r";
return chars.find(c) != std::string::npos;
}
inline auto isBreakableBefore(char c) -> bool {
static std::string chars = "[({<|";
return chars.find(c) != std::string::npos;
}
inline auto isBreakableAfter(char c) -> bool {
static std::string chars = "])}>.,:;*+-=&/\\";
return chars.find(c) != std::string::npos;
}

class Columns;

class Column {
std::vector<std::string> m_strings;
size_t m_width = CATCH_CLARA_TEXTFLOW_CONFIG_CONSOLE_WIDTH;
size_t m_indent = 0;
size_t m_initialIndent = std::string::npos;

public:
class iterato > 0);
assert(at <= line().size());

return at == line().size() ||
(isWhitespace(line()[at]) && !isWhitespace(line()[at - 1])) ||
isBreakableBefore(line()[at]) ||
isBreakableAfter(line()[at - 1]);
}

void calcLength() {
assert(m_stringIndex < m_column.m_strings.size());

m_suffix = false;
auto width = m_column.m_indent : initial;
}

auto addIndentAndSuffix(std::string const &plain) const -> std::string {
return std::string(indent(), ' ') + (m_suffix ? plain + "-" : plain);
}

public:
using difference_type = std::ptrdiff_t;
using value_type = std::string;
using pointer = value_type * ;
using reference = value_type & ;
using iterator_category = std::forward_iterator_tag;

explicit iterator(Column const& column) : m_column(column) {
assert(m_column.m_width > m_column.m_indent);
assert(m_column.m_initialIndent == std::string::npos || m_column.m_width > m_column.m_initialIndent);
calcLength();
if (m_len == 0)
m_stringIndex++; < line().size() && isWhitespace(line()[m_pos]))
++m_pos;

if (m_pos == line().size()) {
m_pos = 0;
++m_stringIndex;
}
if (m_stringIndex < m_column.m_strings.size())
calcLength();
return *this;
}
auto operator ++(int) -> iterator {
iterator prev(*this);
operator++();
return prev;
}

auto operator ==(iterator const& other) const -> bool {
return
m_pos == other.m_pos &&
m_stringIndex == other.m_stringIndex &&
&m_column t -> size_t { return m_width; }
auto begin() const -> iterator { return iterator(*this); }
auto end() const -> iterator { return { *this, m_strings.size() }; }

inline friend std::ostream& operator << (std::ostream& os, Column const& col) {
bool first = true;
for (auto line : col) {
if (first)
first = false;
else
os << "\n";
os << line;
}
return os;
}

auto operator + (Column const& other)->Columns;

auto toString() const -> std::string {
std::ostringstream oss;
oss << *this;
return oss.str();
}
};

class Spacer : public Column {

public:
explicit Spacer(size_t spaceWidth) : Column("") {
width(spaceWidth);
}
};

class Columns {
std::vector<Column> m_columns;

public:

class iterator {
friend Columns;
struct EndTag {};

std::vector<Column> const& m_mns.size());

for (auto const& col : m_columns)
m_iterators.push_back(col.end());
}

public:
using difference_type = std::ptrdiff_t;
using value_type = std::string;
using pointer = value_type * ;
using reference = value_type & ;
using iterator_category = std::forward_iterator_tag;

explicit iterator(Columns const& columns)
: m_columns(columns.m_columns),
m_activeIterators(m_columns.size()) {
m_iterators.reserve(m_columns.size());

for (auto const& col : m_columns)
m_iterators.push_back(col.begin());
}

auto operator ==(iterator const& other) const -> bool {
return m_iterators == other.m_iterators;
}
auto operator !=(iterator const& other) const -> bool {
return m_iterators != other.m_iterators;
}
auto operator *() const -> std::string {
std::string row, padding;

for (size_t i = 0; i < m_columns.size(); ++i) {
auto width = m_columns[i].width();
if (m_iterators[i] != m_columns[i].end()) {
std::string col = *m_iterators[i];
row += padding + col;
if (col.size() < width)
padding = std::string(width - col.size(), ' ');
else
padding = "";
} else {
padding += std::string(width, ' ');
}
}
return row;
}
auto operator ++() -> iterator& {
for (size_t i = 0; i < m_columns.size(); ++i) {
if (m_iterators[i] != m_columns[i].end())
++m_iterators[i];
}
return *this;
}
auto operator ++(int) -> iterator {
iterator prev(*this);
operator++();
return prev;
}
};
using const_iterator = iterator;

auto begin() const -> iterator { return irst)
first = false;
else
os << "\n";
os << line;
}
return Traits<ReturnT( ClassT::* )( Args... ) const> {
        static const bool isValid = false;
    };

    template<typename ClassT, typename ReturnT, typename ArgT>
    struct UnaryLambdaTraits<ReturnT( ClassT::* )( ArgT ) const> {
        static const bool isValid = true;
        using ArgType = typename std::remove_const<typename std::remove_reference<ArgT>::type>::type;
        using ReturnType = ReturnT;
    };

    class TokenStream;

    // ame;
        }
    };

    // Wraps a token coming from a token stream. These may not directly correspond to strings as a single string
    // may encode an option + its argument if the : or = form is used
    enum class TokenType {
        Option, Argument
    };
    struct Token {
        TokenType type;
        std::string token;
    };

    inline auto isOptPrefix( char c ) -> bool {
        return c == '-'
#ifdef CATCH_PLATFORM_WINDOWS
            || c == '/'
#endif
        ;
    }

    // Abstracts iterators into args as a stream of tokens, with option arguments uniformly handled
    class TokenStream {
        using Iterator = std::vector<std::string>::const_iterator;
        Iterator it;
        Iterator itEnd;
        std::vector<Token> m_tokenBuffer;

        void loadBuffe             if( isOptPrefix( next[0] ) ) {
                    auto delimiterPos = next.find_first_of( " :=" );
                    if( delimiterPos != std::string::npos ) {
                        m_tokenBuffer.push_back( { TokenType::Option, next.substr( 0, delimiterPos ) } );
                        m_tokenBuffer.push_back( { TokenType::Argument, next.substr( delimiterPos + 1 ) } );
                    } else {
                        if( next[1] != '-' && next.size() > 2 ) {
                            std::string opt = "- ";
                            for( size_t i = Argument, next } );
                }
            }
        }

    public:
        explicit TokenStream( Args const &args ) : TokenStream( args.m_args.begin(), args.m_args.end() ) {}

        TokenStream( Iterator it, Iterator itEnd ) : it( it ), itEnd( itEnd ) {
            loadBuffer();
        }

        explicit operator bool() const {
            return !m_tokenBuffer.empty() || it != itEnd;
        }

        auto count() const -> size_t { return m_tokenBuffer.size() + (itEnd - it); }

                 loadBuffer();
            }
            return *this;
        }
    };

    class ResultBase {
    public:
        enum Type {
            Ok, LogicError, RuntimeError
        };

    protected:
        ResultBase( Type type ) : m_type( type ) {}
        virtual ~ResultBase() = default;

        virtual void enforceOk() const = 0;

        Type m_type;
    };

    template<typename T>
    class ResultValueBase : public ResultBase {
    public:
        auto value(e & {
            if( m_type == ResultBase::Ok )
                m_value.~T();
            ResultBase::operator=(other);
            if( m_type == ResultBase::Ok )
                new( &m_value ) T( other.m_value );
            return *this;
        }

        ~ResultValueBase() override {
            if( m_type == Ok )
                m_value.~T();
        }

        union {
            T m_value;
        };
    };

    template<>
    class ResultValueBase<void> :  }
        static auto ok() -> BasicResult { return { ResultBase::Ok }; }
        static auto logicError( std::string const &message ) -> BasicResult { return { ResultBase::LogicError, message }; }
        static auto runtimeError( std::string const &message ) -> BasicResult { return { ResultBase::RuntimeError, message }; }

        explicit operator bool() const { return m_type == ResultBase::Ok; }
        auto type(icResult( ResultBase::Type type, std::string const &message )
        :   ResultValueBase<T>(type),
            m_errorMessage(message)
        {
            assert( m_type != ResultBase::Ok );
        }

        using ResultValueBase<T>::ResultValueBase;
        using ResultBase::m_type;
    };

    enum class ParseResultType {
        Matched, NoMatch, ShortCircuitAll, ShortCircuitSame
    };

    class ParseState {
    public:

        ParseState( ParseResultType type, TokenStream const &remainingTokens )
        : m_type(type),
          m_remainingTokens( remainingTokens )
        {}

        auto type() const -> :string left;
        std::string right;
    };

    template<typename T>
    inline auto convertInto( std::string const &source, T& target ) -> ParserResult {
        std::stringstream ss;
        ss << source;
        ss >> target;
        if( ss.fail() )
            return ParserResult::runtimeError( "Unable to convert '" + source + "' to destination type" );
        else
            return ParserResult::ok( ParseResultType::Matched );
    }
    inline auto convertInto( std::string const &source, std::string& target ) -> ParserResult {
        target = source;
        return ParserResult::ok( ParseResultType::Matched );
    }
    inline auto convertInto( std::string const &source, bool &target ) -> ParserResult {
        std::string srcLC = source;
        std::transform( srcLC.begin(), srcLC.end(), srcLC.begin(), []( char c ) { return static_cast<char>( std::tolower(c) ); } );
        if (srcLC == "y" || srcLC == "1" || srcLC == "true" || srcLC == "yes" || srcLC == "on")
            target = true;
        else if (srcLC == "n" || srcLC == "0" || srcLC == "false" || srcLC == "no" || srcLC == "off")
            target = false;
        else
            return ParserResult::runtimeError( "Expected a boolean value but did not recognise: '" + source + "'" );
        return ParserResult::ok( ParseResultType::Matched );
    }
#ifdef CLARA_CONFIG_OPTIONAL_TYPE
    template<typename T>
    inline auto convertInto( std::string const &source, CLARA_CONFIG_OPTIONAL_TYPE<T>& target ) -> ParserResult {
        T temp;
        auto result = convertInto( source, temp );
        if( result )
            target = std::move(temp);
        return result;
    }
#endif // CLARA_CONFIG_OPTIONAL_TYPE

    struct NonCopyable {
        NonCopyable() = default;
        NonCopyable( NonCopyable const & ) = dual ~BoundRef() = default;
        virtual auto isContainer() const -> bool { return false; }
        virtual auto isFlag() const -> bool { return false; }
    };
    struct BoundValueRefBase : BoundRef {
        virtual auto setValue( std::string const &arg ) -> ParserResult = 0;
    };
    struct BoundFlagRefBase : BoundRef {
        virtual auto setFlag( bool flag ) -> ParserResult = 0;
        virtual auto isFlag() const -> bool { return true; }
    };

    template<typename T>
    struct BoundValueRefo setValue( std::string const &arg ) -> ParserResult override {
            T temp;
            auto result = convertInto( arg, temp );
            if( result )
                m_ref.push_back( temp );
            return result;
        }
    };

    struct BoundFlagRef : BoundFlagRefBase {
        bool &m_ref;

        explicit BoundFlagRef( bool &ref ) : m_ref( ref ) {}

        auto setFlag( bool flag ) -> ParserResult override {
            m_ref = flag;
            return ParserResult::ok( ParseResultType::Matched );
        }
    };

    template<typename ReturnType>
    struct LambdaInvoker {
        static_assert( std::is_same<ReturnType, ParserResuuto invoke( L const &lambda, ArgType const &arg ) -> ParserResult {
            lambda( arg );
            return ParserResult::ok( ParseResultType::Matched );
        }
    };

    template<typename ArgType, typename L>
    inline auto invokeLambda( L const &lambda, std::string const &arg ) -> ParserResult {
        ArgType temp{};
        auto result = convertInto( arg, temp );
        return !result
           ? result
           : LambdaInvoker<typename UnaryLambdaTraits<L>::ReturnType>::invoke( lambda, temp );
    }

    template<typename L>
 agLambda : BoundFlagRefBase {
        L m_lambda;

        static_assert( UnaryLambdaTraits<L>::isValid, "Supplied lambda must take exactly one argument" );
        static_assert( std::is_same<typename UnaryLambdaTraits<L>::ArgType, bool>::value, "flags must be boolean" );

        explicit BoundFlagLambda( L const &lambda ) : m_lambda( lambda ) {}

        auto setFlag( bool flag ) -> ParserResult override {
            return LambdaInvoker<typename UnaryLambdaTraits<L>::ReturnType>::invoke( m_lambda, flag );
        }
    };

    enum class Optionality { Optional, Required };

    struct Parser;

    class ParserBase {
    public:
        virtual ~ParserBase() = default;
        virtual auto validate() const -> Result { return Result::ok(); }
        virtual auto urn parse( args.exeName(), TokenStream( args ) );
        }
    };

    template<typename DerivedT>
    class ComposableParserImpl : public ParserBase {
    public:
        template<typename T>
        auto operator|( T const &other ) const -> Parser;

template<typename T>
        auto operator+( T const &other ) const -> Parser;
    };

    // Common code and state for Args and Opts
    template<typename DerivedT>
    class ParserRefImpl : public ComposableParserImpl<DerivedT> {
    protected:
        Optionality m_optionality = Optionality::Opnonst &ref, std::string const &hint )
        :   m_ref( std::make_shared<BoundLambda<LambdaT>>( ref ) ),
            m_hint(hint)
        {}

        auto operator()( std::string const &description ) -> DerivedT & {
            m_description = description;
            return static_cast<DerivedT &>( *this );
        }

        auto optional() -> DerivedT & {
            m_optionality = Optionality::Optional;
            return static_cast<DerivedT &>( *this );
        };

        auto required() -> DerivedT & {
            m_optionality = Optionality::Required;
            return static_cast<DerivedT &>( *this );
        };

        auto isOptional(arserImpl<ExeName> {
        std::shared_ptr<std::string> m_name;
        std::shared_ptr<BoundValueRefBase> m_ref;

        template<typename LambdaT>
        static auto makeRef(LambdaT const &lambda) -> std::shared_ptr<BoundValueRefBase> {
            return std::make_shared<BoundLambda<LambdaT>>( lambda) ;
        }

    public:
        ExeName() : m_name( std::make_shared<std::string>( "<executable>" ) ) {}

        explicit ExeName( std::string &ref ) : ExeName() {
            m_ref = std::make_shared<BoundValueRef<std::string>>( ref );
        }

        template<typename LambdaT>
        explicit ExeName( LambdaT const& las ) );
        }

        auto name() const -> std::string { return *m_name; }
        auto set( std::string const& newName ) -> ParserResult {

            auto lastSlash = newName.find_last_of( "\\/" );
            auto filename = ( lastSlash == std::string::npos )
                    ? newName
                    : newName.substr( lastSlash+1 );

            *m_name = filename;
            if( m_ref )
                return m_ref->setValue( filename );
            else
                return ParserResult::ok( ParseResultType::Matched );
        }
    };

    class Arg : public ParserRefImpl<Arg> {
    public:
        using ParserRefImpl:    if( token.type != TokenType::Argument )
                return InternalParseResult::ok( ParseState( ParseResultType::NoMatch, remainingTokens ) );

            assert( !m_ref->isFlag() );
            auto valueRef = static_cast<detail::BoundValueRefBase*>( m_ref.get() );

            auto result = valueRef->setValue( remainingTokens->token );
            if( !result )
                return InternalParseResult( result );
            else
                return InternalParseResult::ok( ParseState( ParseResultType::Matched, ++remainingTokens ) );
        }
    };

    istd::make_shared<BoundFlagLambda<LambdaT>>( ref ) ) {}

        explicit Opt( bool &ref ) : ParserRefImpl( std::make_shared<BoundFlagRef>( ref ) ) {}

        template<typename LambdaT>
        Opt( LambdaT const &ref, std::string const &hint ) : ParserRefImpl( ref, hint ) {}

        template<typename T>
        Opt( T &ref, std::string const &hint ) : ParserRefImpl( ref, hint ) {}

        auto operator[]( std::string const &optName ) -> Opt & {
            m_optNames.push_back( optName );
            return *this;
        }

        auto ge    auto isMatch( std::string const &optToken ) const -> bool {
            auto normalisedToken = normaliseOpt( optToken );
            for( auto const &name : m_optNames ) {
                if( normaliseOpt( name ) == normalisedToken )
                    return true;
            }
            return false;
        }

        using ParserBase::parse;

        auto parse( std::string const&, TokenStream const &tokens ) const -> InternalParseResult override {
            auto validationResult = validate();
       tFlag( true );
                        if( !result )
                            return InternalParseResult( result );
                        if( result.value() == ParseResultType::ShortCircuitAll )
                            return InternalParseResult::ok( ParseState( result.value(), remainingTokens ) );
                    } else {
                        auto valueRef = static_cast<detail::BoundValueRefBase*>( m_ref.get() );
                        ++remainingTokens;
                        if( !remainingTokens )
                            return InternalParseResult::runtimeError( "Expec          return InternalParseResult( result );
                        if( result.value() == ParseResultType::ShortCircuitAll )
			  return InternalParseResult::ok( ParseState( result.value(), remainingTokens ) );
		       }
			return InternalParseResult::ok( ParseState( ParseResultType::Matched, ++remainingTokens ) );
			}
						  }
            return InternalParseResult::ok( ParseState( Par#else
                if( name[0] != '-' )
		  return Result::logicError( "Option name must begin with '-'" );
#endif
							}
					    return ParserRefImpl::validate();
					    }
						  };

				    struct Help : Opt {
        Help( bool &showHelpFlag )
	  :   Opt([&]( bool flag ) {
	      showHelpFlag = flag;
	      return ParserResult::ok( ParseResultType::ShortCircuitAll );
            })
				      {
				      }

				      auto operator|=( Opt const &opt ) -> Parser & {
					m_options.push_back(opt);
					return *this;
				      }

				      auto operator|=( Parser const &other ) -> Parser & {
					m_options.insert(m_options.end(), other.m_options.begin(), other.m_options.end());
					m_args.insert(m_args.en auto childCols = o.getHelpColumns();
						      cols.insert( cols.end(), childCols.begin(), childCols.end() );
						      }
					  return cols;
				      }

				      void writeToStream( std::ostream &os ) const {
					if (!m_exeName.name().empty()) {
					  os << "usage:\n" << "  " << m_exeName.name() << " ";
					  bool required = true, first = true;
					  for( auto const &arg : m_args ) {
					    if (first)
					      first = false;
					    os << "\n\nwhere options are:" << std::endl;
					  }

					  auto rows = getHelpColumns();
					  size_t consoleWidth = CATCH_CLARA_CONFIG_CONSOLE_WIDTH;
					  size_t optWidth = 0;
					  for( auto const &cols : rows )
					    optWidth = (std::max)(optWidth, cols.left.size() + 2);

					  optWidth = (std::min)(optWidth, consoleWidth/2);

					  for( auto const &cols : rows ) {
                auto row =
		  TextFlow::Column( cols.left                 auto result = opt.validate();
				    if( !result )
				      return result;
				    }
		  for( auto const &arg : m_args ) {
		    auto result = arg.validate();
		    if( !result )
		      return result;
		  }
		return Result::ok();
					  }

					  using ParserBase::parse;

					  const &arg : m_args) parseInfos[i++].parser = &arg;
				      }

				      m_exeName.set( exeName );

				      auto result = InternalParseResult::ok( ParseState( ParseResultType::NoMatch, tokens ) );
				      while( result.value().remainingTokens() ) {
					bool tokenParsed = false;

					for( size_t i = 0; i < totalParsers; ++i ) {
					  t.value().type() == ParseResultType::ShortCircuitAll )
					  return result;
					  if( !tokenParsed )
					    return InternalParseResult::runtimeError( "Unrecognised token: " + result.value().remainingTokens()->token );
				      }
				      // !TBD Check missing required options
				      return result;
				    }
				  };

				  template<typename DerivedT>
				  template<typename T>
				  auto ComposableParserImpl<DerivedT>::operator|( T const &other ) const -> Parser {
				    return Parser() Type;

				    // Result type for parser operation
				    using detail::ParserResult;

				  }} // namespace Catch::clara

				// end clara.hpp
#ifdef __clang__
#pragma clang diagnostic pop
#endif

// Restore Clara's value for console width, if present
#ifdef CATCH_TEMP_CLARA_CONFIG_CONSOLE_WIDTH
#define CATCH_CLARA_TEXTFLOW_CONFIG_CONSOLE_WIDTH CATCH_TEMP_CLARA_CONFIG_CONSOLE_WIDTH
#undef CATCH_TEMP_CLARA_CONFIG_CONSOLE_WIDTH
#endif

				// end catch_clara.h
				namespace Catch {

				  clara::Parser makeCommandLineParser( ConfigData& config );

				} // rnAbout::NoTests;

				return WarnAbout::Nothing;
				}();

                if (warningSet == WarnAbout::Nothing)
		  return ParserResult::runtimeError( "Unrecognised warning: '" + warning + "'" );
	      config.warnings = static_cast<WarnAbout::What>( config.warnings | warningSet );
	      return ParserResult::ok( ParseResultType::Matched );
            };
	    auto const loadTestNamesFromFile = [&]( std::string const& filename ) {
	      onfig.testsOrTags.push_back( line + ',' );
	    }
	  }
	  return ParserResult::ok( ParseResultType::Matched );
	};
        auto const setTestOrder = [&]( std::string const& order ) {
	  if( startsWith( "declared", order ) )
	    config.runOrder = RunTests::InDeclarationOrder;
	  else if( startsWith( "lexical", order ) )
	    config.runOrder = RunTests::InLexicographicgSeed = static_cast<unsigned int>( std::time(nullptr) );
	  return ParserResult::ok( ParseResultType::Matched );
	};
        auto const setColourUsage = [&]( std::string const& useColour ) {
	  auto mode = toLower( useColour );

	  if( mode == "yes" )
	    config.useColour = UseColo  config.waitForKeypress = WaitForKeypress::BeforeStart;
	  else if( keypressLc == "exit" )
	    config.waitForKeypress = WaitForKeypress::BeforeExit;
	  else if( keypressLc == "both" )
	    config.waitForKeypress = WaitForKeypress::BeforeStartAndExit;
                else
		  return ParserResult::runtimeError( "keypress argument must be one of: start, exit or both. '" + keypress +sult::runtimeError( "Unrecognised verbosity, '" + verbosity + "'" );
						     return ParserResult::ok( ParseResultType::Matched );
						     };
	  auto const setReporter = [&]( std::string const& reporter ) {
            IReporterRegistry::FactoryMap const& factories = getRegistryHub().getReporterRegistry().getFactories();

            auto lcReporter = toLower( reporter );
            auto result = factories.find( lcReporter );

            if( factories.end() != result )
	      config.reporterName = lcReporter;
            else
	      return ParserResult::runtimeError( "Unrecogs )
                ["-t"]["--list-tags"]
                ( "list all/matching tags" )
            | Opt( config.showSuccessfulTests )
                ["-s"]["--success"]
                ( "include successful tests in output" )
            | Opt( config.shouldDebugBreak )
                ["-b"]["--break"]
                ( "break into debugger on failure" )
            | Opt( config.noThrow )
                ["-e"]["--nothrow"]
                ( "skip exception tests" )
            | OortAfter = 1; } )
                ["-a"]["--abort"]
                ( "abort at first failure" )
            | Opt( [&]( int x ){ config.abortAfter = x; }, "no. failures" )
                ["-x"]["--abortx"]
                ( "abort after x failures" )
            | Opt( setWarning, "warning name" )
                ["-w"]["--warn"]
                ( "enable warnings" )
            | Opt( [&]( bool flag ) { config.showDurations = flag ? ShowDurations::Always : ShowDurations::Never; }, "Opt( setVerbosity, "quiet|normal|high" )
                ["-v"]["--verbosity"]
						 ( "set output verbosity" )
						 | Opt( config.listTestNamesOnly )
                ["--list-test-names-only"]
						 ( "list all/match    ["--wait-for-keypress"]
                ( "waits for a keypress before exiting" )
            | Opt( config.benchmarkResolutionMultiple, "multiplier" )
                ["--benchmark-resolution-multiple"]
                ( "multiple of clock resolution to run benchmarks" )

            | Arg( config.testsOrTags, "test name|pattern|tags" )
                ( "which test or tests to use" );

        return cli;
    }

} // end namespace Catch
// end catch_commandline.cpp
// start catch_common.cpp

#include <cstring>
#include <oshe pointers are the same, there is no point in calling the strcmp
        return line < other.line || ( line == other.line && file != other.file && (std::strcmp(file, other.file) < 0));
    }

    std::ostream& operator << ( std::ostream& os, SourceLineInfo const& info ) {
#ifndef __GNUG__
        os << info.file << '(' << info.line << ')';
#else
        os << info.file << ':' << info.line;
#endif
        retur     }
        m_testSpec = parser.testSpec();
    }

    std::string const& Config::getFilename() const {
        return m_data.outputFilename ;
    }

    bool Config::listTests() const          { return m_data.listTests; }
    bool Config::listTestNamesOnly() const  { return m_data.listTestNam
    // IConfig interface
    bool Config::allowThrows() const                   { return !m_data.noThrow; }
    std::ostream& Config::stream() const               { return m_stream->stream(); }
    std::string Config::name() const                   { return m_data.name.empty() ? m_data.processName : m_data.name; }
    bool Config::includour() const       { return m_data.useColour; }
    bool Config::shouldDebugBreak() const              { return m_data.shouldDebugBreak; }
    int Config::abortAfter() const                     { return m_data.abortAfter; }
    bool Config::showInvisibles() const                { return m_data.showInvisibles; }
    Verbosity Config::verbosity() const                { return m_data.verbosity; }

    IStream const* Config::openStream() {
        return Catch::makeStream(m_data.outputFilename);
    }

} // end namespace Catch
// end catch_config.cpp
// start catch_console_colour.cpp

#if defined(__clang__)
#    pragma clang diagnostic push
#    pragma clang diagnostic ignored "-Wexit-time-destructors"
#endif

// start catch_errno_guard.h

namespace Catch {

    class ErrnoGuard {
    public:
        ErrnoGuard()IColourImpl() = default;
            virtual void use( Colour::Code _colourCode ) = 0;
        };

        struct NoColourImpl : IColourImpl {
            void use( Colour::Code ) {}

            static IColourImpl* instance() {
                static NoColourImpl s_instance;
                return &s_instance;
            }
        };

    } // anon namespace
} // namespace Catch

#if !defined( CATCH_CONFIG_COLOUR_NONE ) && !defined( CATCH_CONFIG_COLOUR_WINDOWS ) && !defined( CATCH_CONFIG_COLOUR_ANSI )
#   ifdef CATCH_PLATFORM_WINDOWS
#       define CATCH_CONFIG_COLOUR_WINDOWS
#   else
#       define CATCH_CONFIG_COLOUR_ANSI
#   endif
#endif

#if defined ( CATCH_CONFIG_COLOUR_WINDOWS ) /////////////////////////////////////////

namespace Catch {
namespace iInfo );
            originalForegroundAttributes = csbiInfo.wAttributes & ~( BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY );
            originalBackgroundAttributes = csbiInfo.wAttributes & ~( FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        }

        void use( Colour::Code _colourCode ) override {
            switch( _colourCode ) {
                case Colour::None:      return setTextAttribute( originalForegroundAttributes );
                case Colour::White:     return setTextAttribute( FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE );
                case Colour::Red:       return setTextAttribute( FOREGROUND_RED );
                case Colour::Green:     return setTextAttribute( FOREGROUND_GREEN );
                case Colour:: setTextAttribute( FOREGROUND_RED | FOREGROUND_GREEN );
                case Colour::Grey:      return setTextAttribute( 0 );

                case Colour::LightGrey:     return setTextAttribute( FOREGROUND_INTENSITY );
                case Colour::BrightRed:     return setTextAttribute( FOREGROUND_INTENSITY | FOREGROUND_RED );
                case Colour::BrightGreen:   return setTextAttribute( FOREGROUND_INTENSITY | FOREGROUND_GREEN );
                case Colour::BrightWhite:   return setTextAttribute( FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE );
                case Colour::BrightYellow:  return setTextAttribute( FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN );

                case Colour::Bright: CATCH_INTERNAL_ERROR( "not a colour" );

                default:
                    CATCH_ERROR( "Unknown colour requested" );
            }
        }

    private:
        void setTextAttribute( WORD _textAttribute ) {
            SetConsoledle, _textAttribute | originalBackgroundAttributes );
        }
        HANDLE stdoutHandle;
        WORD originalForegroundAttributes;
        WORD originalBackgroundAttributes;
    };

    IColourImpl* platformColourInstance() {
        static Win32ColourImpl s_instance;

        IConfigPtr config = getCurrentContext().getConfig();
        UseColour::YesOrNo colourMode = config
            ? config->useColour()
            : UseColour::Auto;
        if( colourMode == UseColour::Auto )
            colourMode = UseColour::Yes;
        return colourMode == UseColour::Yes
            ? &s_instance
            : NoColourImpl::instance();
    }

} // end anon namespace
} // end namespace Catch

#elif defined( CATCH_CONFIG_COLOUR_ANSI ) //////////////////////////////////////

#include <unistd.h>

namespace Catch {
namespace {

    // use POSIX/ ANSI console terminal codes
    // Thanks to Adam Strzelecki for original con31
    class PosixColourImpl : public IColourImpl {
    public:
        void use( Colour::Code _colourCode ) override {
            switch( _colourCode ) {
                case Colour::None:
                case Colour::White:     return setColour( "[0m" );
                case Colour::Red:       return setColour( "[0;31m" );
                case Colour::Green:     return setColour( "[0;32m" );
                case Colour::Blue:      return setColour( "[0;34m" );
                case Colour::Cyan:      return setColour( "[0;36m" );
                case Colour::Yellow:    return setColour( "[0;33m" );
                case Colour::Grey:      return setColour( "[1;30m" );

                case Colour::LightGrey:     return setColour( "[0;37m" );
                case Colour::BrightRed:     return setColour( "[1;31m" );
                case Colour::BrightGreen:   return setColour( "[1;32m" );
                case Colour::BrightWhite:   return setColour( "[1;37m" );
                case Colour::BrightYellow:  return setColour( "[1;33m" );

                case Colour::Bright: CATCH_INTERNAL_ERROR( "not a colour" );
                default: CATCH_INTERNAL_ERROR( "Unknown colour requested" );
            }
        }
        static IColourImpl* instance() {
            static PosixColourImpl s_instance;
            return &s_instance;
        }

    private:
        void setColour( const char* _escapeCode ) {
            getCurrentContext().getConfig()->stream()
                << '\033' << _escapeCode;
        }
    };

    bool useColourOnPlatform() {
        return
#ifdef CATCH_PLATFORM_MAC
            !isDebuggerActive() &&
#endif
#if !(defined(__DJGPP__) && defined(__STRICT_ANSI__))
            isatty(STDOUT_FILENO)
#else
            false
#endif
            ;
    }
    IColourImpl* platformColourInstance() {
        ErrnoGuard guard;
        IConfigPtr config = getCurrentContext().getConfig();
        UseColour::YesOrNo colourMode = config
            ? config->useColour()
            : UseColour::Auto;
        if( colourMode == UseColour::Auto )
            colourMode = useColourOnPlatform()
                ? UseColour::Yes
                : UseColour::No;
        return colourMode == UseColour::Yes
            ? PosixColourImpl::instance()
            : NoColourImpl::instance();
    }

} // end anon namespace
} // end namespace Catch

#else  // not Windows or ANSI ///////////////////////////////////////////////

namespace Catch {

    static IColourImpl* platformColourInstance() { return NoColourImpl::instance(); }

} // end namespace Catch

#endif // Windows/ ANSI/ None

namespace Catch {

    Colour::Colour( Code _colourCode ) { use( _colourCode ); }
    Colour::Colour( Colour&& rhs ) noexcept {
        m_moved = rhs.m_moved;
        rhs.m_moved = true;
    }
    Colour& Colour::operator=( Colour&& rhs ) noexcept {
        m_moved = rhs.m_moved;
        rhs.m_moved  = true;
        return *this;
    }

    Colour::~Colour(){ if( !m_moved ) use( None ); }

    void Colour::use( Code _colourCode ) {
        static IColourImpl* impl = platformColourInstance();
        impl->use( _colourCode );
    }

    std::ostream& operator << ( std::ostream& os, Colour const& ) {
        return os;
    }

} // end namespace Catch

#if defined(__clang__)
#    pragma clang diagnostic pop
#endif

// end catch_console_colour.cpp
// start catch_context.cpp

namespace Catch {

    class Context : public IMutableContext, NonCopyable {

    public: // IContext
        IResultCapture* getResultCapture() override {
            return m_resultCapture;
        }
        IRunner* getRunner() override {
            return m_runner;
        }

        IConfigPtr const& getConfig() const override {
            return m_config;
        }

        ~Context() override;

    public: // IMutableContext
        void setResultCapture( IResultCapture* resultCapture ) override {
            m_resultCapture = resultCapture;
        }
        void setRunner( IRunner* runner ) override {
            m_runner = runner;
        }
        void setConfig( IConfigPtr const& config ) override {
            m_config = config;
        }

        friend IMutableContext& getCurrentMutableContext();

    private:
        IConfigPtr m_config;
        IRunner* m_runner = nullptr;
        IResultCapture* m_resultCapture = nullptr;
    };

    IMutableContext *IMutableContext::currentContext = nullptr;

    void IMutableContext::createContext()
    {
        currentContext = new Context();
    }

    void cleanUpContext() {
        delete IMutableContext::currentContext;
        IMutableContext::currentContext = nullptr;
    }
    IContext::~IContext() = default;
    IMutableContext::~IMutableContext() = default;
    Context::~Context() = default;
}
// end catch_context.cpp
// start catch_debug_console.cpp

// start catch_debug_console.h

#include <string>

namespace Catch {
    void writeToDebugConsole( std::string const& text );
}

// end catch_debug_console.h
#ifdef CATCH_PLATFORM_WINDOWS

    namespace Catch {
        void writeToDebugConsole( std::string const& text ) {
            ::OutputDebugStringA( text.c_str() );
        }
    }

#else

    namespace Catch {
        void writeToDebugConsole( std::string const& text ) {
            // !TBD: Need a version for Mac/ XCode and other IDEs
            Catch::cout() << text;
        }
    }

#endif // Platform
// end catch_debug_console.cpp
// start catch_debugger.cpp

#ifdef CATCH_PLATFORM_MAC

#  include <assert.h>
#  include <stdbool.h>
#  include <sys/types.h>
#  include <unistd.h>
#  include <cstddef>
#  include <ostream>

#ifdef __apple_build_version__
    // These headers will only compile with AppleClang (XCode)
    // For other compilers (Clang, GCC, ... ) we need to exclude them
#  include <sys/sysctl.h>
#endif

    namespace Catch {
        #ifdef __apple_build_version__
        // The following function is taken directly from the following technical note:
        // https://developer.apple.com/library/archive/qa/qa1361/_index.html

        // Returns true if the current process is being debugged (either
        // running under the debugger or has a debugger attached post facto).
        bool isDebuggerActive(){
            int                 mib[4];
            struct kinfo_proc   info;
            std::size_t         size;

            // Initialize the flags so that, if sysctl fails for some bizarre
            // reason, we get a predictable result.

            info.kp_proc.p_flag = 0;

            // Initialize mib, which tells sysctl the info we want, in this case
            // we're looking for information about a specific process ID.

            mib[0] = CTL_KERN;
            mib[1] = KERN_PROC;
            mib[2] = KERN_PROC_PID;
            mib[3] = getpid();

            // Call sysctl.

            size = sizeof(info);
            if( sysctl(mib, sizeof(mib) / sizeof(*mib), &info, &size, nullptr, 0) != 0 ) {
                Catch::cerr() << "\n** Call to sysctl failed - unable to determine if debugger is active **\n" << std::endl;
                return false;
            }

            // We're being debugged if the P_TRACED flag is set.

            return ( (info.kp_proc.p_flag & P_TRACED) != 0 );
        }
        #else
        bool isDebuggerActive() {
            // We need to find another way to determine this for non-appleclang compilers on macOS
            return false;
        }
        #endif
    } // namespace Catch

#elif defined(CATCH_PLATFORM_LINUX)
    #include <fstream>
    #include <string>

    namespace Catch{
        // The standard POSIX way of detecting a debugger is to attempt to
        // ptrace() the process, but this needs to be done from a child and not
        // this process itself to still allow attaching to this process later
        // if wanted, so is rather heavy. Under Linux we have the PID of the
        // "debugger" (which doesn't need to be gdb, of course, it could also
        // be strace, for example) in /proc/$PID/status, so just get it from
        // there instead.
        bool isDebuggerActive(){
            // Libstdc++ has a bug, where std::ifstream sets errno to 0
            // This way our users can properly assert over errno values
            ErrnoGuard guard;
            std::ifstream in("/proc/self/status");
            for( std::string line; std::getline(in, line); ) {
                static const int PREFIX_LEN = 11;
                if( line.compare(0, PREFIX_LEN, "TracerPid:\t") == 0 ) {
                    // We're traced if the PID is not 0 and no other PID starts
                    // with 0 digit, so it's enough to check for just a single
                    // character.
                    return line.length() > PREFIX_LEN && line[PREFIX_LEN] != '0';
                }
            }

            return false;
        }
    } // namespace Catch
#elif defined(_MSC_VER)
    extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
    namespace Catch {
        bool isDebuggerActive() {
            return IsDebuggerPresent() != 0;
        }
    }
#elif defined(__MINGW32__)
    extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
    namespace Catch {
        bool isDebuggerActive() {
            return IsDebuggerPresent() != 0;
        }
    }
#else
    namespace Catch {
       bool isDebuggerActive() { return false; }
    }
#endif // Platform
// end catch_debugger.cpp
// start catch_decomposer.cpp

namespace Catch {

    ITransientExpression::~ITransientExpression() = default;

    void formatReconstructedExpression( std::ostream &os, std::string const& lhs, StringRef op, std::string const& rhs ) {
        if( lhs.size() + rhs.size() < 40 &&
                lhs.find('\n') == std::string::npos &&
                rhs.find('\n') == std::string::npos )
            os << lhs << " " << op << " " << rhs;
        else
            os << lhs << "\n" << op << "\n" << rhs;
    }
}
// end catch_decomposer.cpp
// start catch_enforce.cpp

namespace Catch {
#if defined(CATCH_CONFIG_DISABLE_EXCEPTIONS) && !defined(CATCH_CONFIG_DISABLE_EXCEPTIONS_CUSTOM_HANDLER)
    [[noreturn]]
    void throw_exception(std::exception const& e) {
        Catch::cerr() << "Catch will terminate because it needed to throw an exception.\n"
                      << "The message was: " << e.what() << '\n';
        std::terminate();
    }
#endif
} // namespace Catch;
// end catch_enforce.cpp
// start catch_enum_values_registry.cpp
// start catch_enum_values_registry.h

#include <vector>
#include <memory>

namespace Catch {

    namespace Detail {

        std::unique_ptr<EnumInfo> makeEnumInfo( StringRef enumName, StringRef allValueNames, std::vector<int> const& values );

        class EnumValuesRegistry : public IMutableEnumValuesRegistry {

            std::vector<std::unique_ptr<EnumInfo>> m_enumInfos;

            EnumInfo const& registerEnum( StringRef enumName, StringRef allEnums, std::vector<int> const& values) override;
        };

        std::vector<std::string> parseEnums( StringRef enums );

    } // Detail

} // Catch

// end catch_enum_values_registry.h

#include <map>
#include <cassert>

namespace Catch {

    IMutableEnumValuesRegistry::~IMutableEnumValuesRegistry() {}

    namespace Detail {

        std::vector<std::string> parseEnums( StringRef enums ) {
            auto enumValues = splitStringRef( enums, ',' );
            std::vector<std::string> parsed;
            parsed.reserve( enumValues.size() );
            for( auto const& enumValue : enumValues ) {
                auto identifiers = splitStringRef( enumValue, ':' );
                parsed.push_back( Catch::trim( identifiers.back() ) );
            }
            return parsed;
        }

        EnumInfo::~EnumInfo() {}

        StringRef EnumInfo::lookup( int value ) const {
            for( auto const& valueToName : m_values ) {
                if( valueToName.first == value )
                    return valueToName.second;
            }
            return "{** unexpected enum value **}";
        }

        std::unique_ptr<EnumInfo> makeEnumInfo( StringRef enumName, StringRef allValueNames, std::vector<int> const& values ) {
            std::unique_ptr<EnumInfo> enumInfo( new EnumInfo );
            enumInfo->m_name = enumName;
            enumInfo->m_values.reserve( values.size() );

            const auto valueNames = Catch::Detail::parseEnums( allValueNames );
            assert( valueNames.size() == values.size() );
            std::size_t i = 0;
            for( auto value : values )
                enumInfo->m_values.push_back({ value, valueNames[i++] });

            return enumInfo;
        }

        EnumInfo const& EnumValuesRegistry::registerEnum( StringRef enumName, StringRef allValueNames, std::vector<int> const& values ) {
            auto enumInfo = makeEnumInfo( enumName, allValueNames, values );
            EnumInfo* raw = enumInfo.get();
            m_enumInfos.push_back( std::move( enumInfo ) );
            return *raw;
        }

    } // Detail
} // Catch

// end catch_enum_values_registry.cpp
// start catch_errno_guard.cpp

#include <cerrno>

namespace Catch {
        ErrnoGuard::ErrnoGuard():m_oldErrno(errno){}
        ErrnoGuard::~ErrnoGuard() { errno = m_oldErrno; }
}
// end catch_errno_guard.cpp
// start catch_exception_translator_registry.cpp

// start catch_exception_translator_registry.h

#include <vector>
#include <string>
#include <memory>

namespace Catch {

    class ExceptionTranslatorRegistry : public IExceptionTranslatorRegistry {
    public:
        ~ExceptionTranslatorRegistry();
        virtual void registerTranslator( const IExceptionTranslator* translator );
        std::string translateActiveException() const override;
        std::string tryTranslators() const;

    private:
        std::vector<std::unique_ptr<IExceptionTranslator const>> m_translators;
    };
}

// end catch_exception_translator_registry.h
#ifdef __OBJC__
#import "Foundation/Foundation.h"
#endif

namespace Catch {

    ExceptionTranslatorRegistry::~ExceptionTranslatorRegistry() {
    }

    void ExceptionTranslatorRegistry::registerTranslator( const IExceptionTranslator* translator ) {
        m_translators.push_back( std::unique_ptr<const IExceptionTCATCH_CONFIG_DISABLE_EXCEPTIONS)
    std::string ExceptionTranslatorRegistry::translateActiveException() const {
        try {
#ifdef __OBJC__
            // In Objective-C try objective-c exceptions first
            @try {
                return tryTranslators();
            }
            @catch (NSException *exception) {
                return Catch::Detail::stringify( [exception description] );
            }
#else
            // Compiling a mixed mode project with MSVC means that CLR
            // exceptions will be caught in (...) as well. However, these
            // do not fill-in std::current_exception and thus leadon. Possibly a CLR exception.";
								}
								return tryTranslators();
#endif
								}
								catch( TestFailureException& ) {
								  std::rethrow_exception(std::current_exception());
								}
								catch( std::exception& ex ) {
								  return ex.what();
								}
								catch( std::string& msg ) {
								  return msg;
								}
								catch( const char* msg ) {
								  return msg;
								}
								catch(.der CATCH_CONFIG_DISABLE_EXCEPTIONS!");
    }

    std::string ExceptionTranslatorRegistry::tryTranslators() const {
        CATCH_INTERNAL_ERROR("Attempted to use exception translators under CATCH_CONFIG_DISABLE_EXCEPTIONS!");
    }
#endif

}
// end catch_exception_translator_registry.cpp
// start catch_fatal_condition.cpp

#if defined(__GNUC__)
#    pragma GCC diagnostic push
#    pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#if defined( CATCH_CONFIG_WINDOWS_SEH ) || defined( CATCH_CONFIG_POSIX_SIGNALS )

namespace {
    // but SigInt, SigTerm, etc are handled differently.
    static SignalDefs signalDefs[] = {
        { static_cast<DWORD>(EXCEPTION_ILLEGAL_INSTRUCTION),  "SIGILL - Illegal instruction signal" },
        { static_cast<DWORD>(EXCEPTION_STACK_OVERFLOW), "SIGSEGV - Stack overflow" },
        { static_cast<DWORD>(EXCEPTION_ACCESS_VIOLATION), "SIGSEGV - Segmentation violation signal" },
        { static_cast<DWORD>(EXCEPTION_INT_DIVIDE_BY_ZERO), "Divide by zero error" },
    };

    LONG CALLBACK FatalConditionHandler::handleVectoredException(PEXCEPTION_POINTERS ExceptionInfo) {
        for (auto const& def : signalDefs) {
            if (ExceptionInfo->ExceptionRecord->ExceptionCode == def.id) {
     eems enough for Catch to handle stack overflow,
        // but the value was found experimentally, so there is no strong guarantee
        guaranteeSize = 32 * 1024;
        exceptionHandlerHandle = nullptr;
        // Register as first handler in current chain
        exceptionHandlerHandle = AddVectoredExceptionHandler(1, handleVectoredException);
        // Pass in guarantee size to be filled
        SetThreadStackGuarantee(&guaranteeSize);
    }

    void FatalConditionHandler::reset() {
        if (isSet) {
            RemoveVectoredExceptionHandler(exceptionHandlerHandle);
            SetThreadStackGuarantee(&guaranteeSize);
            exceptionHandlerHandle = nullptr;
            isSet = false;
        }
    }

    FatalConditionHandler::~FatalCondiS )

namespace Catch {

    struct SignalDefs {
        int id;
        const char* name;
    };

    // 32kb for the alternate stack seems to be sufficient. However, this value
    // is experimentally determined, so that's not guaranteed.
    constexpr static std::size_t sigStackSize = 32768 >= MINSIGSTKSZ ? 32768 : MINSIGSTKSZ;

    static SignalDefs signalDefs[] = {
        { SIGINT,  "SIGINT - Terminal interrupt signal" },
        { SIGILL,  "SIGILL - Illegal instruction signal" },
        { SIGFPE,  "SIGFPE - Floating point error signal" },
        { SIGSEGV, "SIGSEGV - Segmentation violation signal" },
        { SIGTERM, "SIGTERM - Termination request signal" },
        { SIGABRT, "SIGABRT - Abort (abnormal termination) signal" }
    };

    void FatalConditionHandler::handleSignal( int sig ) {
        char const * name = "<unknown signal>";
        for (auto const& def : signalDefs) {
            if (sig == def.id) {
                name = def.name;
                break;
            }
        }
     reset();
        reportFatal(name);
        raise( sig );
    }

    FatalConditionHandler::FatalConditionHandler() {
        isSet = true;
        stack_t sigStack;
        sigStack.ss_sp = altStackMem;
        sigStack.ss_size = sigStackSize;
        sigStack.ss_flags = 0;
        sigaltstack(&sigStack, &oldSigStack);
        struct sigaction sa = { };

        sa.sa_handler = handleSignal;
        sa.sa_flags = SA_ONSTACK;
        for (std::size_t i = 0; i < sizeof(signalDefs)/sizeof(SignalDefs); ++i) {
            sigaction(signalDefs[i].id, &sa, &oldSigActions[i]);
        }
    }

    FatalConditionHandler::~FatalConditionHandler() {
        reset();
    }

    void FatalConditionHandler::reset() {
        if( isSet ) {
            // Set sig   // Return the old stack
            sigaltstack(&oldSigStack, nullptr);
            isSet = false;
        }
    }

    bool FatalConditionHandler::isSet = false;
    struct sigaction FatalConditionHandler::oldSigActions[sizeof(signalDefs)/sizeof(SignalDefs)] = {};
    stack_t FatalConditionHandler::oldSigStack = {};
    char FatalConditi::what() const noexcept {
    return m_msg;
}

namespace Generators {

    GeneratorUntypedBase::~GeneratorUntypedBase() {}

    auto acquireGeneratorTracker( SourceLineInfo const& lineInfo ) -> IGeneratorTracker& {
        return getResultCapture().acquireGeneratorTracker( lineInfo );
    }

} // namespace Generators
} // namespace Catch
// end catch_generators.cpp
// start catch_interfaces_capture.cpp

namespace Catch {
    IResultCapture::~IResultCapture() = default;
}
// end catch_interfaces_capture.cpp
// start catch_interfaces_config.cpp

namespace Catch {
    IConfig::~IConfig() = default;
}
// end catch_interfaces_config.cpp
// start catch_interfaces_exception.cpp

namespace Catch {
    IExceptionTranslator::~IExceptionTranslator() = default;
    IExceptionTranslatorRegistry::~IExceptionTranslatorRegistry() = default;
}
// end catch_interfaces_exception.cpp
// start catch_interfaces_registry_hub.cpp

namespace Catch {
    IRegistryHub::~IRegistryHub() = default;
    IMutableRegistryHub::~IMutableRegistryHub() = default;
}
// end catch_interfaces_registry_hub.cpp
// start catch_interfaces_reporter.cpp

// start catch_reporter_listening.h

namespace Catch {

    class ListeningReporter : public IStreamingReporter {
        using Reporters = std::vector<IStreamingReporterPtr>;
        Reporters m_listeners;
        IStreamingReporterPtr m_reporter = nullptr;
        ReporterPreferences m_preferences;

    public:
        ListeningReporter();

        void addListener( IStreamingReporterPtr&& listener );
        void addReporter( IStreamingReporterPtr&& reporter );

    public: // IStreamingReporter

        ReporterPreferences getPreferences() const override;

        void noMatchingTestCases( std::string const& spec ) override;

        static std::set<Verbosity> getSupportedVerbosities();

        void benchmarkStarting( BenchmarkInfo const& benchmarkInfo ) override;
        void benchmarkEnded( BenchmarkStats const& benchmarkStats ) override;

        void testRunStarting( TestRunInfo const& testRunInfo ) override;
        void testGroupStarting( GroupInfo const& groupInfo ) override;
        void testCaseStarting( TestCaseInfo const& testInfo ) override;
        void sectionStarting( SectionInfo const& sectionInfo ) override;
        void assertionStarting( AssertionInfo const& assertionInfo ) override;

        // The return value indicates if the messages buffer should be cleared:
        bool assertionEnded( AssertionStats const& assertionStats ) override;
        void sectionEnded( SectionStats const& sectionStats ) override;
        void testCaseEnded( TestCaseStats const& testCaseStats ) override;
        void testGroupEnded( TestGroupStats const& testGroupStats ) override;
        void testRunEnded( TestRunStats const& testRunStats ) override;

        void skipTest( TestCaseInfo const& testInfo ) override;
        bool isMulti() const override;

    };

} // end namespace Catch

// end catch_reporter_listening.h
namespace Catch {

    ReporterConfig::ReporterConfig( IConfigPtr const& _fullConfig )
    :   m_stream( &_fullConfig->stream() ), m_fullConfig( _fullConfig ) {}

    ReporterConfig::ReporterConfig( IConfigPtr const& _fullConfig, std::ostream& _stream )
    :   m_stream( &_stream ), m_fullConfig( _fullConfig ) {}

    std::ostream& ReporterConfig::stream() const { return *m_stream; }
    IConfigPtr ReporterConfig::fullConfig() const { return m_fullConfig; }

    TestRunInfo::TestRunInfo( std::string const& _name ) : name( _name ) {}

    GroupInfo::GroupInfo(  std::string const& _name,
                           std::size_t _groupIndex,
                           std::size_t _groupsCount )
    :   name( _name ),
        groupIndex( _groupIndex ),
        groupsCounts( _groupsCount )
    {}

     AssertionStats::AssertionStats( AssertionResult const& _assertionResult,
                                     std::vector<MessageInfo> const& _infoMessages,
                                     Totals const& _totals )
    :   assertionResult( _assertionResult ),
        infoMessages( _infoMessages ),
        totals( _totals )
    {
        assertionResult.m_resultData.lazyExpression.m_transientExpression = _assertionResult.m_resultData.lazyExpression.m_transientExpression;

        if( assertionResult.hasMessage() ) {
            // Copy message into messages list.
            // !TBD This should have been done earlier, somewhere
            MessageBuilder builder( assertionResult.getTestMacroName(), assertionResult.getSourceInfo(), assertionResult.getResultType() );
            builder << assertionResult.getMessage();
            builder.m_info.message = builder.m_stream.str();

            infoMessages.push_back( builder.m_info );
        }
    }

     AssertionStats::~AssertionStats() = default;

    SectionStats::SectionStats(  SectionInfo const& _sectionInfo,
                                 Counts const& _assertions,
                                 double _durationInSeconds,
                                 bool _missingAssertions )
    :   sectionInfo( _sectionInfo ),
        assertions( _as,
        durationInSeconds( _durationInSeconds ),
        missingAssertions( _missingAssertions )
    {}

    SectionStats::~SectionStats() = default;

    TestCaseStats::TestCaseStats(  TestCaseInfo const& _testInfo,
                                   Totals const& _totals,
                                   std::string const& _stdOut,
                                   std::string const& _stdErr,
                                   bool _aborting )
    : testInfo( _testInfo ),
        totals( _totals ),
        stdOut( _stdOut ),
        stdErr( _stdErr ),
        aborting( _aborting )
    {}

    TestCaseStats::~TestCaseStats() = default;

    TestGroupStats::TestGroupStats( GroupInfo const& _groupInfo,
                                    Totals const& _totals,
                                    bool _aborting )
    :   groupInfo( _groupInfo ),
        totals( _totals ),
        aborting( _aborting )
    {}

    TestGroupStats::TestGroupStats( GroupInfo const& _groupInfo )
    :   groupInfo( _groupInfo ),
        aborting( false )
    {}

    TestGroupStats::~TestGroupStats() = default;

    TestRunStats::TestRunStats(   TestRunInfo const& _runInfo,
                    Totals const& _totals,
                    bool _aborting )
    :   runInfo( _runInfo ),
        totals( _totals ),
        aborting( _aborting )
    {}

    TestRunStats::~TestRunStats() = default;

    void IStreamingReporter::fatalErrorEncountered( StringRef ) {}
    bool IStreamingReporter::isMulti() const { return false; }

    IReporterFactory::~IReporterFactory() = default;
    IReporterRegistry::~IReporterRegistry() = default;

} // end namespace Catch
// end catch_interfaces_reporter.cpp
// start catch_interfaces_runner.cpp

namespace Catch {
    IRunner::~IRunner() = default;
}
// end catch_interfaces_runner.cpp
// start catch_interfaces_testcase.cpp

namespace Catch {
    ITestInvoker::~ITestInvoker() = default;
    ITestCaseRegistry::~ITestCaseRegistry() = default;
}
// end catch_interfaces_testcase.cpp
// start catch_leak_detector.cpp

#ifdef CATCH_CONFIG_WINDOWS_CRTDBG
#include <crtdbg.h>

namespace Catch {

    LeakDetector::LeakDetector() {
        int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
        flag |= _CRTDBG_LEAK_CHECK_DF;
        flag |= _CRTDBG_ALLOC_MEM_DF;
        _CrtSetDbgFlag(flag);
        _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
        _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
        // Change this to leaking allocation's number to break there
        _CrtSetBreakAlloc(-1);
    }
}

#else

    Catch::LeakDetector::LeakDetector() {}

#endif

Catch::LeakDetector::~LeakDetector() {
    Catch::cleanUp();
}
// end catch_leak_detector.cpp
// start ca  std::size_t count = 0;
    };

    std::size_t listTags( Config const& config );

    std::size_t listReporters();

    Option<std::size_t> list( std::shared_ptr<Config> const& config );

} // end namespace Catch

// end catch_list.h
// start catch_text.h

namespace Catch {
    using namespace clara::TextFlow;
}

// end catch_text.h
#include <limits>
#include <algorithm>
#include <iomanip>

namespace Catch {

    std::size_t listTests( Config const& config ) {
        TestSpec testSpec = config.testSpec();
        if( config.hasTestFilters() )
            Catch::cout() << "Matching test cases:\n";
        else {
            Catch::cout() << "All available test cases:\n";
        }

        auto matchedTestCases = filterTests( getAllTestCasesSorted( config ), testSpec, config );
        for( auto const& testCaseInfo : matchedTestCases ) {
            Colour::Code colour = testCaseInfo.isHidden()
                ? C
            Catch::cout() << Column( testCaseInfo.name ).initialIndent( 2 ).indent( 4 ) << "\n";
            if( config.verbosity() >= Verbosity::High ) {
                Catch::cout() << Column( Catch::Detail::stringify( testCaseInfo.lineInfo ) ).indent(4) << std::endl;
                std::string description = testCaseInfo.description;
                if( description.empty() )
                    description = "(NO DESCRIPTION)";
                Catch::cout() << Column( description ).indent(4) << std::endl;
            }
            if( !testCaseInfo.tags.empty() )
                Catch::cout() << Column( testCaseInfo.tagsAsString() ).indent( 6 ) << "\n";
        }

        if( !config.hasTestFilters() )
            Catch::cout() << pluralise( matchedTestCases.size(), "test case" ) << '\n' << std::endl;
        else
            Catch::cout() << pluralise( matchedTestCases.size(), "matConfig const& config ) {
								  TestSpec testSpec = config.testSpec();
								  std::size_t matchedTests = 0;
								  std::vector<TestCase> matchedTestCases = filterTests( getAllTestCasesSorted( config ), testSpec, config );
								  for( auto const& testCaseInfo : matchedTestCases ) {
								    matchedTests++;
								    if( startsWith( testCaseInfo.name, '#' ) )
								      Catch::cout() << '"' << testCaseInfo.name << '"';
								    else
								      Catch::cout() << testCaseInfo.name;
								    if ( config.verbosity() >= Verbosity::High )
								      Catch::cout() << "\t@" << testCaseInfo.lineInfo;
								    Catch::cout() << std::endl;
								  }
								  return matchedTests;
								}

								void TagInfo::add( std::string const& spelling ) {
								  ++count;
								  spellings.insert( sistTags( Config const& config ) {
								      TestSpec testSpec = config.testSpec();
								      if( config.hasTestFilters() )
									Catch::cout() << "Tags for matching test cases:\n";
								      else {
									Catch::cout() << "All available tags:\n";
								      }

								      std::map<std::string, TagInfo> tagCounts;

								      std::vector<TestCase> matchedTestCases = filterTests( getAllTestCasesSorted( config ), testSpec, config );
								      for( auto const& testCase : matchedTestCases ) {
									for( auto const& tagName : testCase.getTestCaseInfo().tags ) {
									  std::string lcaseTagName = toLower( tagName );
									  td::setw(2) << tagCount.second.count << "  ";
									  auto str = rss.str();
									  auto wrapper = Column( tagCount.second.all() )
									    .initialIndent( 0 )
									    .indent( str.size() )
									    .width( CATCH_CONFIG_CONSOLE_WIDTH-10 );
									  Catch::cout() << str << wrapper << '\n';
									}
									Catch::cout() << pluralise( tagCounts.size(), "tag" ) << '\n' << std::endl;
									return tagCounts.size();
								      }

								      std::size_t listReporters() {
									Catch::cout() << "Available reporters:\n";
									IReporterRegistry::FactoryMap const& factories = getRegistryHub().g< Column( factoryKvp.first + ":" )
									  .indent(2)
									  .width( 5+maxNameLen )
									  +  Column( factoryKvp.second->getDescription() )
									  .initialIndent(0)
									  .indent(2)
									  .width( CATCH_CONFIG_CONSOLE_WIDTH - maxNameLen-8 )
									  << "\n";
								      }
								      Catch::cout     listedCount = listedCount.valueOr(0) + listReporters();
								      return listedCount;
								    }

								    } // end namespace Catch
								    // end catch_list.cpp
								    // start catch_matchers.cpp

								    namespace Catch {
								      namespace Matchers {
									namespace Impl {

									  std::string MatcherUntypedBase::toString() const {
									    if( m_cachedToString.empty() )
									      m_cachedToString = describe();
									    return m_cachedToString;
									  }

									  MatcherUntypedBase::~MatcherUntypedBase() = default;

									} // namespace Impl
								      } // namespace Matchers

								      using namespace Matchers;
								      using Matchers::Impl::MatcherBase;

								    } // namespace Catch
								  // end catch_matchers.cpp
								  // start catch_mat;
#else
								  ReusableStringStream rss;
								  rss << t;
								  return rss.str();
#endif
								}
								} // end namespace Catch

								// end catch_to_string.hpp
#include <cstdlib>
#include <cstdint>
#include <cstring>

								namespace Catch {
								  namespace Matchers {
								    namespace Floating {
								      enum class FloatingPointKind : uint8_t {
									Float,
    Double
									  };
								    }
								  }
								}

								namespace {

								  template <typename T>
								  struct Converter;

								  template <>
/ Comparison with NaN should always be false.
								  // This way we can rule it out before getting into the ugly details
								  if (Catch::isnan(lhs) || Catch::isnan(rhs)) {
								    return false;
								  }

								  auto lc = convert(lhs);
								  auto rc = convert(rhs);

								  if ((lc.i < 0) != (rc.i < 0)) {
								    // Potentially we can have +0 and -0
								    return lhs == rhs;
								  }

								  auto ulpDiff = std::abs(lc.i - rc.i);
								  returnm_margin >= matchee);
								}

								std::string WithinAbsMatcher::describe() const {
								       return "is within " + ::Catch::Detail::stringify(m_margin) + " of " + ::Catch::Detail::stringify(m_target);
								     }

								WithinUlpsMatcher::WithinUlpsMatcher(double target, int ulps, FloatingPointKind baseTyp        default:
												     CATCH_INTERNAL_ERROR( "Unknown FloatingPointKind value" );
												     }
								}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

							    std::string WithinUlpsMatcher::describe() const {
								     return "is within " + Catch::to_string(m_ulps) + " ULPs of " + ::Catch::Detail::stringify(m_target) + ((m_type == FloatingPointKind::Generic::Detail::finalizeDescription(const std::string& desc) {
									   if (desc.empty()) {
									     return "matches undescribed predicate";
									   } else {
									     return "matches predicate: \"" + desc + '"';
									   }
									 }
									 // end catch_matchers_generic.cpp
									 // start catch_matchers_string.cpp

#rcherBase( std::string const& operation, CasedString const& comparator )
									 : m_comparator( comparator ),
									 m_operation( operation ) {
									 }

									 std::string StringMatcherBase::describe() const {
									   std::string description;
									   description.reserve(5 + m_operation.size() + m_comparator.m_str.size() +
											       & comparator ) : StringMatcherBase( "contains", comparator ) {}

									   bool ContainsMatcher::match( std::string const& source ) const {
									     return contains( m_comparator.adjustString( source ), m_comparator.m_str );
									   }

									   StartsWithMatcher::StartsWithMatcher( CasedString const& comparator ) : StringMatcherBase( "starts with", comparator ) {}

									   bool StartsWithMatcher::match( std::string const& source ) const {
									     return startsWith( m_comparator.adjustString( source ), m_comparator.m_ser::match(std::string const& matchee) const {
										 auto flags = std::regex::ECMAScript; // ECMAScript is the default syntax option anyway
										 if (m_caseSensitivity == CaseSensitive::Choice::No) {
										   flags |= std::regex::icase;
										 }seSensitivity) );
									   }
									   StdString::EndsWithMatcher EndsWith( std::string const& str, CaseSensitive::Choice caseSensitivity ) {
									     return StdString::EndsWithMatcher( StdString::CasedString( str, caseSensitivity) );
									   }
									   StdString::StartsWithMatcher StartsWith( std::string const& str, CaseSensitive::Choice caseSensitivity ) {
									     return StdString::StartsWithMatcher( StdString::CasedString( str, caseSensitivity) );
									   }

									   StdString::RegexMatcheeLineInfo const& _lineInfo,
									     ResultWas::OfType _type )
									 :   macroName( _macroName ),
									 lineInfo( _lineInfo ),
									 type( _type ),
									 sequence( ++globalCount )
								       {}

									 bool MessageInfo::operator==( MessageInfo const& other ) const {
									   return sequence == other.sequence;
									 }

									 bool MessageInfo::operator<( MessageInfo const& other ) const {
									   return sequence < other.sequence;
									 }

									 // This may need protecageBuilder const& builder )
									 : m_info( builder.m_info ), m_moved()
								       {
									 m_info.message = builder.m_stream.str();
									 getResultCapture().pushScopedMessage( m_info );
								       }

									 ScopedMessage::ScopedMessage( ScopedMessage&& old )
									 : m_info( old.m_info ), m_moved()
								       {
									 old.m_moved = true;
								       }

									 ScopedMessage::~ScopedMessage() {
									   if ( !uncaught_excepttart + 1; i < names.size() ; ++i) {
									     if (names[i] == quote)
									       return i;
									     if (names[i] == '\\')
									       ++i;
									   }
									   CATCH_INTERNAL_ERROR("CAPTURE parsing encountered unmatched quote");
									 };

									 size_t start = 0;
									 std::stack<char> openings;
									 for (size_t pos = 0; pos < (start != pos && openings.size() == 0) {
									     m_messages.emplace_back(macroName, lineInfo, resultType);
									     m_messages.back().message = trimmed(start, pos);
									     m_messages.back().message += " := ";
									     start = pos;copedMessage( m_messages[index] );
									     m_captured++;
									   }

										} // end namespace Catch
									 // e        ReusableStringStream m_rss;
									 o use tmpnam(_s) and
									   //     TempFile m_stderectedStdOut() : m_cout( Catch::cou                CATCH_RUNTIME_ERROR("Could not translate errno to a string");
									   }
								       CATCH_RUNTIME_ERROR("Could not open the temp file: '" << m_buffer << "' because: " << Redirect(std::string& stdout_dest, std::string& stderr_dest) :
											   m_originalStdout(dup(1)),
        m_originp
											   // start catch_polyfills.cpp

#include <cmatl.h

#include <vens;
											   mutablestd::string cos( std::string const& unaceT = InterfaceT>
														   class Singleton getTestC_testCaseRegistry.registerTest(            Detail::EnumValuesRegistry m_enumValuesRegistry;
																						      };
														   }

											   using RegistryHubSingleton = Singleton<RegistryHub, IRegistryHub, IMutableRegistryHub>;

											   IRegistryHub const& getRegistryHub() {
											     return RegistryHubSingleton::get();
											   }
											   IMutableRegistryHub& getMutableRegistryHub() {
											     return RegistryHubSingleton::getMutable();
											   }
											   vReporterConfig( config ) );
								       }

								       void ReporterRegistry::registerReporter( std::string const& name, IReporterFactoryPtr const& factory ) {
								       m_factories.emplace(name, factory);
								     }
								     void ReporterRegistry::registerListener( IReporterFactoryPtr const& factory ) {
								       m_listeners.push_back( factory );
								     }

								     IReporterRegistry::FactoryMap const& ReporterRegistry::getFactories() const {
								       ) | static_cast<int>( rhs ) );
							    }

							    bool shouldContinueOnFailure( int flags )    { return ( flags & ResultDisposition::ContinueOnFailure ) != 0; }
							    bool shouldSuppressFailure( int flags )      { return ( flags & ResultDisposition::SuppressFail ) != 0; }

							    } // end namespace Catch
							    // end catch_result_type.cpp
							    // start catch_run_context.cp  ITracker& currentTracker = ctx.currentTracker();
							    if( TestCaseTracking::ITrackerPtr childTracker = currentTracker.findChild( nameAndLocation ) ) {
							      assert( childTracker );
							      assert( childTracker->isGeneratorTracker() );
							      TrackerBase::close();
							      // Generator interface only finds out if it has another item on atual move
							      if (m_runState == CompletedSuccessfully && m_generator->next()) {
								m_children.clear();
								m_runState ition::Normal },
								m_includeSuccessfulResults( m_config->includeSuccessfulResults() || m_reporter->getPreferences().shouldReportAllAssertions )
								  {
								    m_context.setRunner(this);
								    m_context.setConfig(m_config);
								    m_context.setResultCapture(this);
								    m_reporter->testRunStart   std::string redirectedCout;
								    std::string redirectedCerr;

								    auto const& testInfo = testCase.getTestCaseInfo();

								    m_reporter->testCaseStarting(testInfo);

								    m_activeTestCase = &testCase;

								    ITracker& rootTracker = m_trackerContext.startRun();
								    assert(rootTracker.isSectionTracker());
								    static_cast<SectionTracker&>(rootTracker).addInitialFilters(m_coailed++;
																}
								      m_totals.testCases += deltaTotals.testCases;
								    m_reporter->testCaseEnded(TestCaseStats(testInfo,
													    deltaTotals,
													    redirectedCout,
													    redirectedCerr,
													    aborting()));

								    m_activeTestCase = nullptr;
								    m_testCaseTracker = nullptr;

								    return deltaTotals;
								  }

								m_totals.assertions.failed++;
							    }
							    else {
							      m_lastAssertionPassed = true;
							    }

							    // We have no use for the return value (whether messages should be cleared), because messages were made scoped
							    // and should be let to clear themselves out.
							    static_cast<void>(m_reporter->assertionEnded(AssertionStats(result, m_messages, m_totals)));

							    if (result.getResultType() != ResultWas::Warning)
							      m_messageScopes.clear();

							    // Reset working state
							    resetAssertionInfo();
							    m_laInfo.lineInfo));
							    if (!sectionTracker.isOpen())
							      return false;
							    m_activeSections.push_back(&sectionTracker);

							    m_lastAssertionInfo.lineInfo = sectionInfo.lineInfo;

							    m_reporter->sectionStarting(sectionInfo);

							    assertions = m_totals.assertions;

							    return true;
							    }
							    auto RunContext::acquireGeneratorTracker( SourceLineInfo const& lineInfo ) -> IGeneratorTracker& {
							   using namespace Generators;
							   Geotals.assertions.failed++;
							   assertions.failed++;
							   return true;
							 }

							    void RunContext::sectionEnded(SectionEndInfo const & endInfo) {
							      Counts assertions = m_totals.assertions - endInfo.prevAssertions;
							      bool missingAssertions = testForMissingAssertions(assertions);

							      if (!m_activeSections.empty()) {
								m_activeSections.back()->close();
								m_activeSections.pop_back();
							      }

							      m_reporter->sectionEnded(SectionStats(endInfo.sectionInfo, assertions, endInfo.durreporter->benchmarkStarting( info );
												    }
										       void RunContext::benchmarkEnded( BenchmarkStats const& stats ) {
											 m_reporter->benchmarkEnded( stStringRef message ) {
											   // First notify reporter that bad things happened
											   m_reporter->fato();

											   Totals deltaTotals;
											   deltaTotals.testCases.failed = 1;
											   deltaTotals.assertions.failed = 1;, std::string & redirectedCerr) {
											   auto const& testCaseInfo = m_activeTest               invokeActiveTestCase();
											 }
											 duration = timer.getElapsedSeconds();;
											 m_reporter->sectionEnded(testCaseSectionStats);
										       }

										       void RunContext::invokeActiveTestCase() {
											 FatalCt ) {
											 if (!m_includeSuccessfulResults) {
											   assertionPassed();
       nReaction& reaction
	 ) {
											   m_reporter->assertionStarting( info );

											   m_lastAssertionInfo = info;

											   AssertionResultData data( resultType, LazyExpression( false ) );
											   data.message = message;
											   AssertionResult ast{ info, data };
											   assertionEnded( assertionResult );
											   populateReaction( reaction );
											 }

											 void RunContext:ssion( false ) );
										       AssertionResult assertionResult{ info, data };
										       assertionEnded( assertionResult );

										       if( !assertionResult.isOk() )
											 populateReactinfo );
							    }
							    }

							    // This indicates whether the section should be executed or not
							    Section::operator bool() const {
							 return m_sectionIncluded;
						       }

							    } // end namespace Catch
						   // end catch_section.cpp
						   // start catch_section_info.cpp

						   namnfigData );

						 template<typename CharT>
						 int run(int argc, CharT const * const argv[]) {
						   if (m_startup           unsigned int _minorVersion,
						       unsigned int _patchNumber,
						       char const * const _branchName,
						       unsigned < "'");

						   return reporter;
						 }

						 IStreamingReporterPtr makeReporter(std::shared_ptr<Config> const& config) {
						   if (e(Catch::ReporterConfig(config)));
						 }
						 multi.addReporter(createReporter(config->getReporterName(), config));
						 return ret;
						 }

	    Catch::Totals runTests(std::shared_ptr<Config> const& config) {
		auto reporter = makeReporter(config);

		RunContext context(config, std::move(reporter));

		Totals totaf (config->warnAboutNoTests() && totals.testCases.total() == 0) {
		  ReusableStringStream testConfig;

		  bool first = true;
		  for (const auto& input : config->getTestsOrTags()) {
                    if (!first) { testConfig << ' '; }
                    filename.erase(0, lastSlash);
                    filename[0] = '#';
		  }

		  auto lastDot = filename.find_last_of('.');
		  if (lastDot != std::string::npos) {
                    filename.erase(lastetCurrentMutableContext().setConfig(m_config);

				   m_startupExceptions = true;
				   Colour colourGuard( Colour::Red );
				   Catch::cerCatch::cout()
				   << std::left << std::setw(16) << "description: " << "A Catch tes )
            showHelp();
        if( m_configData.libIdentify )
            libIdentify();
        m_config.reset();
        return 0;
    }

#if defined(CATCH_CONFIG_WCHAR) && defined(WIN32) && defined(UNICigData.waitForKeypress & WaitForKeypress::BeforeStart ) != 0 ) {
            Catch::cout() << "...waiting for enter/ return before        if (m_configData.showHelp || m_configData.libIdentify) {
				       return 0;
				     }

				   CATCH_TRY {
				     config(); // Force con
				   }

				   } // end namespace Catch
		      // end catch_session.cpp
		      // start catch_singletons.cpp

#include <vector>

		      namespace Catch {

			namespace {
			  static auto getSingletons() -> std::vector<ISingleton*>*& {
			    static std::vector<ISingleton*>* g_singletons = nullptr;
			    if( !g_singletons )
			      g_sback(exception);
			  } CATCH_CATCH_ALL {
			    // If we run out of memory during start-up there's really not a lot more we can do about it
			    std::terminate();
			  }
			}

			std::vector<std::exception_ptr> const& StartupExceptionRegistry::getExceptions() const noexcept {
			  return m_exceptions;
			}

		      } // end namespace Catch
		    // end catch_startup_exception_registry.cpp
		    // start catch_stream.cpp

#include <cstdio>
#include <iostream>
#include <fstream>
#include   }

		private:
		    int overflow( int c ) override {
		      sync();

		      if( c != EOF ) {
			if( pbase() == epptr() )
			  m_writer( std::string( 1, static_cast<char>( c ) ) );
			else
			  sputc( static_cast<char>( c ) );
		      }
		      return 0;
		    }

		    int sync() override {
		      if( 
			 class FileStream : public IStream {
			   mutable std::ofstream m_ofs;
			 public:
			   FileStream( StringRef filename ) {
			     m_ofs.open( filename.c_str() );
			     CATCH_ENFORCE( !m_ofs.fail(), "Unable to open file: '" << filename << "'" );
			   }
			   ~FileStream() override = default;
			 public: //////////////////////////////////////////////////////////////

			   class DebugOutStream : public IStream {
			     std::unique_ptr<StreamBufImpl<OutputDebugWriter>> m_streamBuf;
			     mutable std::ostream m_os;
			     lename << "'" );
			 }
			 else
			   return new detail::FileStrm::ReusableStringStream()
			     :   m_index( Singleton<StringStreams>::getMutable().add() ),
			 m_ossce {
			     char toLowerCh(char c) {
			       return static_cast<char   toLowerInPlace( lc );
			       return lc;
			     }
			     std::string trim( std::string const& str ) {
			       static char const* whitespaceChars = "\n\r\t ";
			       std::string::size_type start = str.find_first_not_of( whitespaceChars );
			       std::string::size_type end = str.find_last_not_of( whitespaceCstr, char delimiter ) {
				 std::vector<StringRef> subStrings;
				 std::size_t start = 0;
				 for(std::size_t pos = 0; pos < sgnored "-Wexit-time-destructors"
#endif

#include <ostream>
# noexcept -> bool {
				       return m_data != nullptr;
				     }
				       auto StringRef::isSubstring() const noexceptart[index];
				     }

				 auto StringRef::numberOfCharacters() std::string( lhs ) + std::string( rhs );
			       }

			       auto operator << ( std::ostream& os, StringRef const& str ) -> std::ostream& {
        rstead register the exception to be processed later
	  getMutableRegistryHub().registerStartupException();
			       }
			     }

			   }
			 // end catch_tag_alias_autoregistrar.cpp
			 // start catch_tag_alias_registry.cpp

#include <sstream>

			 namespace Catch {

			   TagAliasRegistry::~TagAliasRegistry() {}

			   TagAlias const* TagAliasRegistry::find( std::string const& alias ) const {
			     auto it = m_registry.find( alias );
			     if( it != m_registry.end() )
			       return &(it->second);
			     else
			       return nullptr;
			   }

			   s               expandedTestSpec.substr( pos + registryKvp.first.size() );
			 }
			 }
		      return expandedTestSpec;
		    }

		    void TagAliasRegistry::add( std::string const& alias, std::string const& tag, SourceLineInfo const& lineInfo ) {
		      CATCH_ENFORCE( startsWith(alias, "[@") && endsWith(alias, ']'),
				     "error: tag alias, '" << alias << "' is not of the form [@alias name].\n" << lineInfo );

		      CATCH_ENFORCE( m_regis#include <cctype>
#include <exception>
#include <algorithm>
#include <sstream>

				     namespace Catch {

				       namespace {
					 TestCaseInfo::SpecialProperties parseSpecialTag( std::string const& tag ) {
					   if( startsWith( tag, '.' ) ||
					       tag == "!hide" )
					     return TestCaseInfo::IsHidden;
					   else if( tag == "!throws" )
					     return TestCaseInfo::Throws;
					   else if( tag == "!shouldfail" )
					     return TestCaseInfnfo::None && tag.size() > 0 && !std::isalnum( static_cast<unsigned char>(tag[0]) );
					 }
					 void enforceNotReservedTag( std::string const& tag, SourceLineInfo const& _lineInfo ) {
					   CATCH_ENFORCE( !isReservedTag(tag),
							  "Tag name: [" << tag << "] is not allowed.\n"
							  << "Tag names starting wi      inTag = true;
                else
                    desc += c;
            }
            else {
                if( c == ']' ) {
                    TestCaseInfo::SpecialProperties prop = parseSpecialTag( tag );
                    if( ( prop & TestCaseInfo::IsHidden ) != 0 )
                        isHidden = true;
       tags.push_back( "." );
        }

        TestCaseInfo info( nameAndTags.name, _className, desc, tags, _lineInfo );
        return TestCase( _testCase, std::move(info) );
    }

    void setTags( TestCaseInfo& testCaseInfo, std::vector<std::string> tags ) {
        std::sort(begin(tags), end(tags));
        tags.erase(std::unique(begin(tags), end(tags)), end(tags));
        testCaseInfo.lcaseTags.clear();

        for( auto const& t                              SourceLineInfo const& _lineInfo )
    :   name( _name ),
        className( _className ),
        description( _description ),
        lineInfo( _lineInfo ),
        properties( None )
    {
        setTags( *this, _tags );
    }

    bool TestCaseInfo::isHidden() const {
        return ( properties & IsHidden ) != 0;
    }
    bool TestCaseInfo::throws() const {
        return ( properties & Throws ) != 0;
    }
    bool TestCaseInfet.append(tag);
            ret.push_back(']');
        }

        return ret;
    }

    TestCase::TestCase( ITestInvoker* testCase, TestCaseInfo&& info ) : TestCaseInfo( std::move(info) ), test( testCase ) {}

    TestCase TestCase::withName( std::string const& _newName ) const {
        TestCase other( *this );
        other.name = _newName;
      IConfig const& config, std::vector<TestCase> const& unsortedTestCases ) {

        std::vector<TestCase> sorted = unsortedTestCases;

        switch( config.runOrder() ) {
            case RunTests::InLexicographicalOrder:
                std::sort( sorted.begin(), sorted.end() );
                break;
            case RunTests::InRandomOrder:
                seedRng( config );
                std::shuffle( sortev = seenFunctions.insert( function );
            CATCH_ENFORCE( prev.second,
                    "error: TEST_CASE( \"" << function.name << "\" ) already defined.\n"
                    << "\tFirst sSorted( config );
							  }

					     void TestRegistry::registerTest( TestCase const& testCase ) {
					     std::string name = testCase.getTestCaseInfo().name;
					     if( name.empty() ) {
					       ReusableStringStream rss;
					       rss << "Anonymous test case " << ++m_unnamedCount;
					       return registerTest( testCase.withName( rss.str() ) );
					     }
					     m_function/////////////////
					       TestInvokerAsFunction::TestInvokerAsFunction( void(*testAsFunction)() ) noexcept : m_testAsFunction( testAsFunction ) {}

					     void TestInvokerAsFunction::invoke() const {
					       m_testAsFunction();
					     }

					     std::string extractClassName( StringRef const& classOrQualifiedMethodName ) {
					       std::string className = classOrQualifiedMethodName;
					       if( startsWith( clas)
#    pragma clang diagnostic push
#    pragma clang diagnostic ignored "-Wexit-time-destructors"
#endif

						   namespace Catch {
						     namespace TestCaseTracking {

						       NameAndLocation::NameAndLocation( std::string const& _name, SourceLineInfo const& _location )
							 :   name( _name ),
							     location( _location )
						       {}

						       ITracker::~ITracker() = default;

						       ITracker& TrackerContext::startRun() {
							 m_rootTracker = std::make_shared<SectionTrackerle() const {
							   return m_runState == CompletedCycle;
							 }
							 ITracker& TrackerContext::currentTracker() {
							   return *m_currentTracker;
							 }
							 void TrackerContext::setCurrentTracker( ITracker* tracker ) {
							   m_currentTracker = tracker;
							 }

							 TrackerBase::TrackerBase( NameAndLocation const& nameAndLocation, TrackerContext& ctx, ITracker* parent )
							   :   m_nameAndLocatioerBase::addChild( ITrackerPtr const& child ) {
							   m_children.push_back( child );
							 }

							 ITrackerPtr TrackerBase::findChild( NameAndLocation const& nameAndLocation ) {
							   auto it = std::find_if( m_children.begin(), m_children.end(),
										   [&nameAndLocation]( ITrackerPtr const& tracker ){
                return
		tracker->nameAndLocation().location == nameAndLocation.location &&
		tracker->nameAndLocation().name == nameAndLocation.name;
										   } );
							   return( it != m_children.end() )
            ? *it
							     : nullptr;
							 }
							 ITracker& TrackerBase::parent() {
							   assert( m_parent ); // Should always be non-null except for robool TrackerBase::isGeneratorTracker() const { return false; }

							   void TrackerBase::open() {
							     m_runState = Executing;
							     moveToThis();
							     if( m_parent )
							       m_parent->openChild();
							   }

							   void TrackerBase::close() {

							     // Close any still open children (e.g. generators)
							     while( &m_ctx.currentTracker() != this )
							       m_ctx.currentTracker().close();

							     switch( m_runState ) {
							     case NeedsAnotherRun:
							       break;

							     case Executing:
							       m_runState = CompletedSuccessfully;
							       break;
							     case ExecutingChildren:
							       if( m_children.empty() || m_children.back()->isComplete() )
							       ate: " << m_runState );
        }
        moveToParent();
        m_ctx.completeCycle();
    }
    void TrackerBase::fail() {
        m_runState = Failed;
        if( m_parent )
            m_parent->markAsNeedingAnotherRun();
        moveToParent();
        m_ctx.completeCycle();
    }
    void TrackerBase::markAsNeedingAnotherRun() {
        m_runState = NeedsAnotherRun;
    }

    void TrackerBase::moveToParent() {
        assert( m_parent );
        m_ctx.setCurrentTracker( m_parent );
    }
    void TrackerBase::moveToThis() {
        m_ctx.setCurrentTracker( this );
    }

    SectionTracker::SectionTracker( NameAndLocation co }
    }

    bool SectionTracker::isComplete() const {
        bool complete = true;

        if ((m_filters.empty() || m_filters[0] == "") ||
             std::find(m_filters.begin(), m_filters.end(),
                       m_nameAndLocation.name) != m_filters.end())
            complete = TrackerBase::isComplete();
        return complete;

    }

    bool SectionTracker::isSectionTracker() const { return true; }

    SectionTracker& SectionTracker::acquire( TrackerContext& ctx, NameAndLocation const& nameAndLocation ) {
        std::shared_ptr<Section      currentTracker.addChild( section );
        }
        if( !ctx.completedCycle() )
            section->tryOpen();
        return *section;
    }

    void SectionTracker::tryOpen() {
        if( !isComplete() && (m_filters.empty() || m_filters[0].empty() ||  m_filters[0] == m_nameAndLocation.name ) )
            open();
    }

    void SectionTracker::addInitialFilteCaseTracking::SectionTracker;

} // namespace Catch

#if defined(__clang__)
#    pragma clang diagnostic pop
#endif
// end catch_test_case_tracker.cpp
// start catch_test_registry.cpp

namespace Catch {

    auto makeTestInvoker( void(*testAsFunction)() ) noexcept -> ITestInvoker* {
        return new(std::nothrow) TestInvokerAsFunction( testAsFunction );
    }

    NameAndTags::NameAndTags( StringRef const& name_ , StringRef cg global objects, instead register the exception to be processed later
            getMutableRegistryHub().registerStartupException();
        }
    }

    AutoReg::~AutoReg() = default;
}
// end catch_test_registry.cpp
// start catch_test_spec.cpp

#include <algorithm>
#include <string>
#include <vector>
#include <memory>

namesp   return std::find(begin(testCase.lcaseTags),
                         end(testCase.lcaseTags),
                         m_tag) != end(testCase.lcaseTags);
    }

    TestSpec::ExcludedPattern::ExcludedPattern( PatternPtr const& underlyingPattern ) : m_underlyingPattern( underlyingPattern ) {}
    bool TestSpec::ExcludedPattern::matches( TestCaseInfo const& testCase ) const { retes( testCase ) )
                return true;
        return false;
    }
}
// end catch_test_spec.cpp
// start catch_test_spec_parser.cpp

namespace Catch {

    TestSpecParser::TestSpecParser( ITagAliasRegistry const& tagAliases ) : m_tagAliases( &tagAliases ) {}

    TestSpecParser& TestSpecParser::parse( std::string const& arg ) {
        m_mode = None;
        m_exclusion = false;
        m_start = std::string::npos;
        m_arg = m_tagAliases->expandAliatNewMode( Tag, ++m_pos );
            case '"': return startNewMode( QuotedName, ++m_pos );
            case '\\': return escape();
            default: startNewMode( Name, m_pos ); break;
            }
        }
        if( m_mode == Name ) {
            if( c == ',' ) {
                addPattern<TestSpec::NamePattern>();
                addFilter();
            }
            else if( c == '[' ) {
                if( subString() ==e_t start ) {
        m_mode = mode;
        m_start = start;
    }
    void TestSpecParser::escape() {
        if( m_mode == None )
            m_start = m_pos;
        m_mode = EscapedName;
        m_escapeChars.push_back( m_pos );
    }
    std::string TestSpecParser::subString() const { return m_arg.substr( m_start, m_pos - m_start ); }

    void TestSpecParser::addFilter() {
        if( !m_currentFilter.m_patterns.empty() ) {
            m_testSpec.m_filters.push_b:high_resolution_clock::now().time_since_epoch() ).count();
    }

    namespace {
        auto estimateClockResolution() -> uint64_t {
            uint64_t sum = 0;
            static const uint64_t iterations = 1000000;

            auto startTime = getCurrentNanosecondsSinceEpoch();

            for( std::size_t i = 0; i < iterations; ++i ) {

                uint64_t ticks;
                uint64_t baseTicks = getCurrentNanosecondsSinceEpoch();
                do {
                    ticks = getCurrentNanosecondsSinceEpoch();
                } while( ticks == baseTicks );

                auto delta = ticks - baseTicks;
                sum += delta;

                // If we have been calibrating for over 3  }

            // We're just taking the mean, here. To do better we could take the std. dev and exclude outliers
							 // - and potentially do more iterations if there's a high variance.
							 return sum/iterations;
			    }
							     }
							     auto getEstimatedClockResolution() -> uint64_t {
							       static auto s_resolution = estimateClockResolution();
							       return s_resolution;
							     }

							     void Timer::start() {
							       m_nanoseconds = getCurrentNanosecondsSinceEpoch();
							     }
							     auto Timer::getElapsedNanoseconds() const -> uint64_t {
							       return getCurrentNanosecondsSinceEpoch() - m_nanoseconds;
							     }
							     auto Timer::getElapsedMicroseconds() const -> uint64_t {
							       return getElapsedNanoseconds()/1000;
							     }
							     auto Timer::getElapsedMilliseconds() const -> unsigned int {
        return static_cast<unsigned intr.cpp
	  // start catch_tostring.cpp

#if defined(__clang__)
#    pragma clang diagnostic push
#    pragma clang diagnostic ignored "-Wexit-time-destructors"
#    pragma clang diagnostic ignored "-Wglobal-constructors"
#endif

	  // Enable specific decls locally
#if !defined(CATCH_CONFIG_ENABLE_CHRONO_STRINGMAKER)
#define CATCH_CONFIG_ENABLE_CHRONO_STRINGMAKER
#endif

#include <cmath>
#include <iomanip>

	  namespace Catch {

	  namespace Detail {

	    const std::string unprintableString = "{?}";

	    namespace {
	      const int hexThreshold = 255;

	      struct Endianness {
		enum Arch { Big, Little };

		static Arch which() {
		  union _{
                    int asInt;
                    char asChar[sizeof (int)];
		  } u;

		  u.asInt = 1;
		  return ( u.asChar[sizeof(int)-1] == 1 ) ? Big : Little;
		}
  architectures
  int i = 0, end = static_cast<int>( size ), inc = 1;
		if( Endianness::which() == Endianness::Little ) {
		  i = end-1;
		  end = inc = -1;
		}

		unsigned char const *bytes = static_cast<unsigned char const *>(object);
		ReusableStringStream rss;
		rss << "0x" << std::setfill('0') << std::hex;
		for( ; i != end; i += inc )
		  rss << std::setw(2) << static_cast<unsigned>(bytes[i]);
		return rss.str();
	      }
	    }

	    template<typename T>
	    std::string fpToString( T value, int precision ) {
	      ============= ////
	      //
	      //   Out-of-line defs for full specialization of StringMaker
	      //
	      //// ======================================================= ////

	      std::string StringMaker<std::string>::convert(const std::string& str) {
		if (!getCurrentContext().getConfig()->showInvisibles()) {
		  return '"' + str + '"';
		}

		std::string s("\"");
		for (char c : str) {
		  switch (c) {
		  case '\n':
		    s.append("\\n");
		    break;
		  case '\t':
		    s.append("\\t");
		    break;
		  default:
		    s.push_back(c);
		    break;
		  }
		}
		s.append("\"");
		return s;
	      }

#ifdef CATCH_CONFIG_CPP17_STRING_VIEW
	      std::string StringMaker< }
	  }
	  std::string StringMaker<char*>::convert(char* str) {
	    if (str) {
	      return ::Catch::Detail::stringify(std::string{ str });
	    } else {
	      return{ "{null string}" };
	    }
	  }

#ifdef CATCH_CONFIG_WCHAR
	  std::string StringMaker<std::wstring>::convert(const std::wstring& wstr) {
	    std::string s;
	    s.reserve(wstr.size());
	    for (auto c : wstr) {
	      s += (c <= 0xff) ? static_cast<char>(c) : '?';
	    }
	    return ::Catch::Detail::stringify(s);
	  }

# ifdef CATCH_CONFIG_CPP17_STRING_VIEW
	  std::string StringMaker<std::wstring_view>::convert(std::wstring_view str) {
	    return StringMaker<std::wstring>::convert(std::wstring(str));
	  }
# endif

	  std::string StringMaker<wchar_t const*>::convert(wchar_t const * str) {
	    if (str) {
	      return ::Catch::Detail::stringify(std::wstring{ str });
	    } else {
	      return{ "{null string}" };
	    }
	  }
	  std::string StringMaker<wc{
	    return{ "{null string}" };
	  }
	}
#endif

	std::string StringMaker<int>::convert(int value) {
	  return ::Catch::Detail::stringify(static_cast<long long>(value));
	}
	std::string StringMaker<long>::convert(long value) {
	  return ::Catch::Detail::stringify(static_cast<long long>(value));
	}
	std::string StringMaker<long long>::convert(long long value) {
	  ReusableStringStream rss;
	  rss << value;
	  if (value > Detail::hexThreshold) {
	    rss << " (0x" << std::hex << value << ')';
	  }
	  return rss.str();
	}

	std::string StringMaker<unsigned int>::convert(unsigned int value) x" << std::hex << value << ')';
    }
    return rss.str();
}

std::string StringMaker<bool>::convert(bool b) {
    return b ? "true" : "false";
}

std::string StringMaker<signed char>::convert(signed char value) {
    if (value == '\r') {
        return "'\\r'";
    } else if (value == '\f') {
        return "'\\f'";
    } else if (value == '\n') {
        return "'\\n'";
    } else if (value == '\t') {
        return "cision = 5;

	std::string StringMaker<float>::convert(float value) {
	  return fpToString(value, precision) + 'f';
	}

	int StringMaker<double>::precision = 10;

	std::string StringMaker<double>::convert(double value) {
	  return fpToString(value, precision);
	}

	std::string ratio_string<std::atto>::symbol() { return "a"; }
	std::string ratio_string<std::femto>::symbol() { return "f"; }
	std::string ratio_string<std::pico>::symbol() { return "p"; }
	std::string ratio_string<std::nano>::symbol() { return "n"; }
	std::string ratio_string<std::micro>::symbol() { return "u"; }
	std::string ratio_string<std::milldButOk;
        return diff;
							     }

							     Counts& Counts::operator += ( Counts const& other ) {
							       passed += other.passed;
							       failed += other.failed;
							       failedButOk += other.failedButOk;
							       return *this;
							     }

							     std::size_t Counts::total() const {
							       return passed + failed + failedButOk;
							     }
							     bool Counts::allPassed() const {
							       return failed == 0 && failedButOk == 0;
							     }
							     bool Counts::allOk() const {
							       return failed == 0;
							     }

							     Totals Totals::operator - ( Totals const& other ) const {
							       To+diff.testCases.failed;
							       else if( diff.assertions.failedButOk > 0 )
								 ++diff.testCases.failedButOk;
							       else
								 ++diff.testCases.passed;
							       return diff;
							     }

							   }
							   // end catch_totals.cpp
							   // start catch_uncaught_exceptions.cpp

#include <exception>

							   namespace Catch {mber )
							     {}

							     std::ostream& operator << ( std::ostream& os, Version const& version ) {
							       os  << version.majorVersion << '.'
								   << version.minorVersion << '.'
								   << version.patchNumber;
							       // branchName is never null -> 0WildcardAtStart;
							     }
							     if( endsWith( m_pattern, '*' ) ) {
							       m_pattern = m_pattern.substr( 0, m_pattern.size()-1 );
							       m_wildcard = static_cast<WildcardPosition>( m_wildcard | WildcardAtEnd );
							     }
							 }

							 bool WildcardPattern::matches( std::string const& str ) const {
							   switch( m_wildcard ) {
							   case NoWildcard:
         catch_xmlwriter.cpp

#include <iomanip>

	   using uchar = unsigned char;

	 namespace Catch {

	   namespace {

	     size_t trailingBytes(unsigned char c) {
	       if ((c & 0xE0) == 0xC0)        os.flags(f);
	     }

	   } // anonymous namespace

	   XmlEncode::XmlEncode( std::string const& str, ForWhat forWhat )
	     :   m_str( str ),
		 m_forWhat( forWha     break;

		 default:
			    // Check for control characters and invalid utf-8

			    // Escape control characters in standard ascii
			    //|
			    c >= 0xF8) {
	     hexEscapeChar(os, c);
	     break;
	   }

	   auto                  (!valid) ||
	   // Overlong encodings
	   (value < 0x80) ||
	     pedElement( ScopedElement&& other ) noexcept
	     :   m_writer( other.m_writer ){
	     other.m_writer = nullptr;
	   }
	   XmlWriter::ScopedElement& XmlWriter::Sc< m_indent << '<' << name;
	   m_tags.push_back( name );
	   m_indent += "  ";
	   m_tagIsOpen = true;
	   return *this;
	 }

	 XmlWter::writeAttribute( std::string const& name, bool attribute ) {
	   m_os << ' ' << name << "=\"" << ( attribute ? "true" }

	     void XmlWriter::ensureTagClosed() {
	     if( m_tagIsOpen ) {
            m_os r decimal point
	      // + 3 for the 3 decimal places
	      // + 1 for null terminator
	      const std::size_t maxDoubleSize = DBL_MAX_10_EXP + 1 + 1 + 3 + 1;
	    char buffer[maxDoubleSize];

	    {
	      return { Verbosity::Quiet, Verbosity::Normal, Verbosity::High };
	    }

	    void TestEventListenerBase::assertionStarting(AssertionInfo const &) {}

	    bool TestEventListenerBase::assertionEnded(AssertionStats const &) {
       all] M assertions.
	      // - white: Passed [both/all] N test cases (no assertions).
	      // -   red: Failed N tests cases, failed M assertions.
	      // - green: Passed [both/all] N tests cases with M assertions.
	      void printTotals(std::ostream& out, const Totals& totals) {
	      if (totals.testCases.total() == 0) {
		out << "No tests ran.";
	      } else if (totals.testCases.failed == totals.testCases.total()) {
   
		<< pluralise(totals.testCases.total(), "test case")
		  << " (no assertions).";
	      } else if (totals.assertions.failed) {
		Colour colout)
		, messages(_stats.infoMessages)
		    , itMessage(_stats.infoMessages.begin())
		    , printInfoMessages(_pri     case ResultWas::ThrewException:
					printResultType(Colour::Error, failedString());
					printIssue("unex    printResultType(Colour::None, "warning");
            printMessage();
            printRemainingMessages();
            break;
        case ResultWas::ExplicitFailure:
            printResultType(Colour::Error, failedString());
            printIssue("explicitly")      }
    }

    void printIssue(std::string const& issue) const {
        stream << ' ' << issue;
    }

    void printExpressionWas() {
        if (result.hasExpression()) {
            stream << ';';
            {
                Colour colour(dimColour())= dimColour()) {
        if (itMessage == messages.end())
            return;

        // using messages.end() directly yields (or auto) compilation error:
        std::vector<MessageInfo>::const_iterator itEnd = messages.end();
        const std::size_t N = static_cast<std::size_t>(std::distance(itMessage, itEnd));

        {
            Colour colourGuard(colour);
            stream << " with " << perator itMessage;
    bool printInfoMessages;
};

} // anon namespace

        std::string CompactReporter::getDescription() {
            return "Reports test results on a single line, suitable for IDEs";
        }

        ReporterPreferences CompactReporter::getPreferences() const {
            return m_reporterPrefs;
        }

        void CompactReporter::noMatchingTestCases( std::string const& spec ) {
            stream << "No test cases matched '" << spec << '\'' << st    return false;
                printInfoMessages = false;
            }

            AssertionPrinter printer( stream, _assertionStats, printInfoMessages );
            printer.print();

            stream << std::endl;
            return true;
        }le.cpp

#include <cfloat>
#include <cstdio>

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4061) // Not all labels are EXPLICITLY handled in switch
 // Note that 4062 (not all labels are handled
 // and default is missing) is enabled
#endif

namespace Catch {

namespace {

// Formatter impl for ConsoleReporter
class ConsoleAssertionPrinter {
public:
    ConsoleAssertionPrinter& operator= (ConsoleAssertionPrinter const&) = delete;
    ConsoleAssert        //if( result.hasMessage() )
            if (_stats.infoMessages.size() == 1)
                messageLabel = "with message";
            if (_stats.infoMessages.size() > 1)
                messageLabel = "with messages";
            break;
        case ResultWas::ExpressionFailed:
            if (result.isOk()) {
                colour = Colour::Success;
                passOrFail = "FAILED - but was ok";
            } else {
                colour =_stats.infoMessages.size() > 1)
                messageLabel += "messages";
            break;
        case Resultreak;
            // These cases are here to prevent compiler warnings
        case ResultWa';
						   }
					}
	      void printReconstructedExpression() const {
		if (result.hasExpandedExpression()) {
		  stream << "with expansion:\n";
		  Colour colourGuard(Colour::ReconstructedExpression);
		  stream << Column(result.getExpandedExpressng message;
				   std::vector<MessageInfo> messages;
				   bool printInfoMessages;
				   };

		  std::size_t makeRatio(std::size_t number, std::size_t total)dsInAMillisecond;
		  static const uint64_t s_nanosecondsInAMinute = 60 * s_nanosecondsInASecond;

		  uint64_t m_inNanoseconds;
		  Unit m_units;

		public:
		  explicit Duration(uint64_t inNanoseconds, Unit units = Unit::Auto)
		    : m_inNanoseconds(inNanoseconds)        case Unit::Milliseconds:
		  return m_inNanoseconds / static_cast<double>(s_na
							       }
		};
	      } // end anon namespace

	      class TablePrinter {
		std::ostream& m_os;
		std::vector<ColumnInfo> m_columnInfos;
		std::ostringstream m_oss;
		nst& value) {
		tp.m_oss << value;
		return tp;
	      }

	      friend TablePrinter& operator << (TablePrinter& tp, ColumnBreak) {
		auto colStr = tp.    if (tp.m_currentColumn > 0) {
		  tp.m_os << "\n";
		  tp.m_currentColumn = -1;
		}
		return tp;
		sertionResult;

		bool includeResults = m_config->includeSuccessfulResults() || !result.isOk();

		// Drop out if result was successful but we're not printing them.
		if (!includeResults && result.getResultType() != ResultWas::Warning)
		  return false;

		lazyPrint();

		ConsoleAssertionPrinter printer(stream, _assertionStats, includeResults);
		printer.print();
		stream << std::endl;
		return true;
	      }

	      void ConsoleReporter::sectionStarting(SectionInfo const& _sectionInfo) {
		m_headerPrinted = false;
		StreamingReporterBase::sectionStarting(_sectionInfo);
	      }
	      void ConsoleReporter::sectionEnded(SectionStats const& _sectionStats) {
		m_tablePrinter->close();
		if (_sectionStats.missingAssertions) {
		  std::endl;
		}
		if (m_config->showDurations() == ShowDurations::Always) {
		  stream << getFormattedDuration(_sectionStats.durationInSeconds) << " s: " << _sectionStats.sectionInfo.name << std::endl;
		}
		if (m_headerPrinted) {
		  m_headerPrinted = false;
		}
		StreamingReporterBase::sectionEnded(_sectionStats);
	      }

	      void ConsoleReporter::benchmarkStarting(BenchmarkInfo const& info) {
		lazyPrintWithoutClosingBenchmarkTable();

		auto nameCol = Column( info.name ).width( static_cast<std::size_t>( m_tablePrinter->columnInfos()[0].width - 2 ) ts.iterations << ColumnBreak()
							  << stats.elapsedTimeInNanoseconds << ColumnBreak()
							  << average << ColumnBreak();
							  }

		  void ConsoleReporter::testCaseEnded(TestCaseStats const& _testCaseStats) {
		  m_tablePrinter->close();
		  StreamingReporterBase::testCaseEnded(_testCaseStats);
		  m_headerPrinted = false;
		}
		void ConsoleReporter::testGroupEnded(TestGroupStats const& _testGroupStats) {
		  if (currentGroupInfo.used) {
		    printSummaryDivider();
		    stream << "Summary for group '" << _testGroupStats.groupInfo.name << "':\n";
		    printTotals(_testGroupStats.totals);
		    stream << '\n' << std::endl;
		  }
		  StreamingReporterBase::testGroupEnded(_testGroupStats);
		}
		void ConsoleReporter::testRunEnded(TestRunStats const& _testRunStats) {
		  printTotalsDivider(_testRunStats.totals);
		  printTotals(_testRunStats.totals);
		  stream << std::endl;
		  StreamingReporterBase::testRunEnded(_testRunStats);
		}
		void ConsoleReporter::testRunStarting(TestRunInfo const& _testInfo) {
		  StreamingReporterBase::testRunStarting(_testInfo);
		  printTestFilters();
		}

		void ConsoleReporter::lazyPrint() {

		  m_tablePrinter->close();
		  lazyPrintWithoutClosingBenchmarkTable();
		}

		void ConsoleReporter::lazyPrintWithoutClosingBenchmarkTable() {

		  if (!currentTestRunInfo.used)
		    lazyPrintRunInfo();
		  if (!currentGroupInfo.used)
		    lazyPrintGroupInfo();

		  if (!m_headerPrinted) {
		    printTestCaseAndSectionHeader();
		    m_headerPrinted = true;
		  }
		}
		void ConsoleReporter::lazyPrintRunInfo() {
		  stream << '\n' << getLineOfChars<'~'>() << '\n';
		  Colour colour(Colour::SecondaryText);
		  stream << currentInfo->groupsCounts > 1) {
		  printClosedHeader("Group: " + currentGroupInfo->name);
		  currentGroupInReporter::printOpenHeader(std::string const& _name) {
		    stream << getLineOfChars<'-'>() << '\n';
		    {
		      Colour colourGuard(Colour::Headers);
		      printHe())
		      row = ' ' + row;
		  }
		  rows.push_back(row);
		  return *this;
		}

		std::string label;
		Colour::Code colour;
		std::vector<std::string> rows;

	      };

	      void ConsoleReport    .addRow(totals.testCases.passed)
		.addRow(totals.assertions.passed));
        - none -";
        } else if (value != "0") {
            stream << Colour(Colour::LightGrey) << " | ";
            stream << Colour(col.col'=');
        stream << Colour(Colour::ResultExpectedFailure) << std::string(failedButOkRatio, '=');
        if (totals.testCases.allPassed())
            stream << Colour(Colour::ResultSuccess) << std::string(pas<algorithm>

namespace Catch {

    namespace {
        std::string getCurrentTimestamp() {
            // Beware, this is not reentrant because of backward compatibility issues
            // Also, UTC only, again because of backward compatibility (%z is C++11)
                                          end(tags),
                                   [] (std::string const& tag) {return tag.front() == '#'; });
            if (it != tags.end())
             }

    void JunitReporter::testGroupStarting( GroupInfo const& groupInfo ) {
        suiteTimer.start();
        stdOroupStats ) {
        double suiteTime = suiteTimer.getElapsedSeconds();
        CumulativeReporterBase::testGroupEnded( testGr       xml.writeAttribute( "timestamp", getCurrentTimestamp() );

        // Write se );
    }

    void JunitReporter::writeTestCase( TestCaseNode const& testCaseNode ) {
        TestCaseStats const& stats = testC trim( sectionNode.stats.sectionInfo.name );
        if( !rootName.empty() )
            name = rootName + '/' + nm-err" ).writeText( trim( sectionNode.stdErr ), false );
	   }
	   for( auto const& childNode : sectionNode.childS    break;
	   case ResultWas::ExpressionFailed:
		  elementName = "failure";
                uto const& msg : stats.infoMessages )
	     if( msg.type == ResultWas::Info )
	       rss << msg.message << '\n';

	   rss <<>getPreferences().shouldRedirectStdOut;
	 }

	 ReporterPreferences ListeningReporter::getPreferences() const {
	   return m_preferences;
	 }

	 std::set<Verbosity> List benchmarkStats );
							 }

							 void ListeningReporter::testRunStarting( TestRunInfo const& testRunInfo ) {
							   for ( auto const& listener : m_listeners ) {
							     listener->testRunStartintionInfo );
							 }

							 void ListeningReporter::assertionStarting( AssertionInfo const& assertionInfo ) {
							   for ( auto const& listener : m_ : m_listeners ) {
							     listener->testCaseEnded( testCaseStats );
							   }
							   m_reporter->testCaseEnded( testCaseStats );
							 }

    void ListeningRetart catch_reporter_xml.cpp

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disableceInfo.line );
      }

						       void XmlReporter::noMatchingTestCases( std::string const& s ) {
							 StreamingReporterBase::noMatchingTestCases( s );
						       }
						       tartElement( "Group" )
						       .writeAttribute( "name", groupInfo.name );
						     }

						   }
						   }

					       void XmlReporter::assertionStarting( AssertionInfo const& ) { }

					       bool XmlReporter::tResultType() != ResultWas::Warning )
					       return true;rCondition:
					       m_xml.startElement( "FatalErrorCondition" );
					       writeSourceInfo( result.getSourceInfo() );
					       StreamingReporterBase::sectionEnded( sectionStats );
					       if( --m_sectionDepth > 0 ) {
						 XmlWriter::ScopedElement e = m_xml.scopedElement( "OverallResults" );
						 e.writeAttribute( "successes", sectionStats.assertions.passed );
          ionInSeconds", m_testCaseTimer.getElapsedSeconds() );

        if( !Base::testRunEnded( testRunStats );
        m_xml.scopedElement( "OverallResults" )
            .writeAttribute( "successes", tes char * argv[]) {
#endif

    return Catch::Session().run( argc, argv );
}

#else // __OBJC__

// Objective-C entry poi_VA_ARGS__ )

#define CATCH_REQUIRE_THROWS( ... ) INTERNAL_CATCH_THROWS( "CATCH_REQUIRE_THROWS", Catch::ResultDisposition::Normal, __VA_ARGS__ )
#define CATCH_REQUIRE_THROWS_AS( expr, exceptionType ) INTERNAL_CATCH_THROWH_CHECK_FALSE( ... ) INTERNAL_CATCH_TEST( "CATCH_CHECK_FALS Catch::ResultDisposition::ContinueOnFailure, matcher, expr )
#if !defined(CATCH_CONFIG_DISABLE_MATCHERS)
#define CATCH_CHECK_THROWS_MATCHES( expr, exceptionType, matcher ) INTERNAL_CATCH_THROWS_MATCHES( "CATCH_CHECK_THROWS_MATCHES", exceptionType, Catch::ResultDisposition::ContinueOnFailure, matcher, expr )
#e CATCH_WARN( msg ) INTERNAL_CATCH_MSG( "CATCH_WARN", Catch::ResultWas::Warning, Catch::ResultDisposition::ContinueOnFailure, msg )
#define CATCH_CAPTURE( ... ) INTERNAL_CATCH_CAPTURE( INTERNAL_CATCH_UNIQUE_NAME(capturer), "CATCH_CAPTURE",__VA_ARGS__ )

#define CATCH_TEST_CASE( ... ) INTERNAL_CATCH_TESTCASE( __VA_ARGS__ )
#define CATCH_TEST_CASE_METHOD( className, ... ) INTERNAL_CATCH_TEST_CASE_METHOD( className, __VA_ARGS__ )
#define CATCH_METHOD_AS_TEST_CASE( method, ... ) INTERNAL_CATCH_METHOD_AS_TEST_CASE( method, __VA_ARGS__ )
#define CATCH_REGISTER_TEST_CASE( Function, ... ) INTERNAL_CATCH_REGISTER_TESTCASE( Function, __VA_ARGS__ )
#define CATCH_SECas::ExplicitFailure, Catch::ResultDisposition::ContinueOnFailure, __VA_ARGS__ )
#define CATCH_SUCCEED( ... ) INTERNAL_CATCH_MSG( "CATCH_SUCCEED", Catch::ResultWas::Ok, Catch::ResultDisposition::ContinueOnFailure, __VA_ARGS__ )

#define CATCH_ANON_TEST_CASE() INTERNAL_CATCH_TESTCASE()

#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR
#define CATCH_TEMPLATE_TEST_CASE( ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE( __VA_ARGS__ )
#define CATCH_TEMPLATE_TEST_CASE_SIG( ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE_SIG( __VA_ARGS__ )
#define CATCH_TEMPLATE_TEST_CASE_METHOD( className, ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD( clODUCT_TEST_CASE_METHOD( className, ... ) INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD( className, __VA_ARGS__ )
#define CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG( className, ... ) INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG( className, __VA_ARGS__ )
#else
#define CATCH_TEMPLATE_TEST_CASE( ... ) INTERNAL_CATCH_EXPAND_VARG ) INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_SIG( __VA_ARGS__ ) )
#define CATCH_TEMPLATE_PRODUCT_TEST_CAARGS__ )
#define CATCH_SCENARIO_METHOD( className, ... ) INTERNAL_CATCH_TEST_CASE_METHOD( className, "Scenario: " __ROWS( ... ) INTERNAL_CATCH_THROWS( "REQUIRE_THROWS", Catch::ResultDisposition::Normal, __VA_ARGS__ )
#define REQUIRE_THROWS_AS( expr, exceptionType ) INTERNAL_CATCH_THROWS_A:ResultDisposition::FalseTest, __VA_ARGS__ )
#define CHECKED_IF( ... ) INTERNAL_CATCH_IF( "CHECKED_IF", Catch::ResultDisposition::ContinueOnFailure, __VA_ARGS__ )
#define CHECKED_ELSE( ... ) INTERNAL_CATCH_ELSE( "CHECKED_ELSE", Catch::ResultDisposition::ContinueOnFailure, __VA_ARGS__ )
#define CHECK_NOFAIL( ... ) INTERNAL_CATCH_TEST( "CHECK_NOFAIL", Catch::ResultDisposition::ContS_MATCHES( "CHECK_THROWS_MATCHES", exceptionType, Catch::ResultDisposition::ContinueOnFailure, mNAL_CATCH_TESTCASE( __VA_ARGS__ )
#define TEST_CASE_METHOD( className, ... ) INTERNAL_CATCH_TEST_CASE_METHOD( className, __VA_ARGS_E( ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE( __VA_ARGS__ )
#define TEMPLATE_TEST_CASE_SIG( ... ) IE_SIG( ... ) INTERNAL_CATCH_EXPAND_VARGS( INTE !defined(CATCH_CONFIG_RUNTIME_STATIC_REQUIRE)
#define STATIC_REQUIRE( ... )       static_assert(   __VA_ARGS__,  #__VA_ARGS__ ); SUCCEED( #__VA_ARGS__ )
#define STATIC_REQUIRE_FALSE( ... ) static_assert( !(__VA_ARGS__), "!(" #__VA_ARGS__ ")" ); SUCCEED( "!(" #__VA_ARGS__ ")" )
#else
#define STATIC_RMIC_SECTION( " And when: " << desc )
#define THEN( desc )      INTERNAL_CATCH_DYNAMIC_SECTION( "     Then: " << desc )
#define AND_THEN( desc )  INTERNAL_CATCH_DYNAMIC_SECTION( "      And: " << desc )

					 using Catch::Detail::Approx;

#else // CATCH_CONFIG_DISABLE

					 //////
					 // If this config identifier is defined then all CATCH macros are prefixed with CATCH_
#ifdef CATCH_CONFIG_PREFIX_ALL

#define CATCH_REQUIRE( ... )        (void)(0)
#define CATCH_REQUIRE_FALSE( ... )  (void)(0)

#define CATCH_REQUIRE_THROWS( ... ) (void)(0)
#define CATCH_REQUIRE_THROWS_AS( expr, exceptionType ) (void)(0)
#define CATCH_REQUIRE_THROWS_WITH( expr, matcher )     (void)(0)
#if !CHECKED_ELSE( ... )  if (!(__VA_ARGS__))
#define CATCH_CHECK_NOFAIL( ... )  (void)(0)

#define CATCH_CHECK_THROWS( ... )  (void)(0)
#define CATCH_CHECK_THROWS_AS( expr, exceptionType ) (void)(0)
#define CATCH_CHECK_THROWS_WITH( expr, matcher )     (void)(0)
#if !defined(CATCH_CONFIG_DISABLE_MATCAL_CATCH_TESTCASE_NO_REGISTRATION(INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_S_T____ ))
#define CATCH_METHOD_AS_TEST_CASE( method, ... )
#define CATCH_REGISTER_TEST_CASE( Function, ... ) (void)(0)
#define CATCH_SECTION( ... )
#define D_SIG_NO_REGISTRATION(className, __VA_ARGS__ )
#define CATCH_TEMPLATE_PRODUCT_TEST_CASE( ... ) CATCH_TEMPLATE_TEST_CASE( __VA_ARGS__ )
#define CATCH_TEMPLATE_PRODUCT_TEST_CASE_SIG( ... ) CATCH_TEMPLATE_TEST_CASE( __VA_ARGS__ )
#define CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD( className, ... ) CATCH_TEMPLATE_TEST_CASE_METHOD( className, __VA_ARGS__ )
#define CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG( className, ... ) CATCH_TEMPLATE_TEST_CASE_METHOD( classNameNTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_SIG_NO_REGISTRATION(className, __VA_ARGS__ ) )
#define CATCH_TEMPLATE_PRODUCT_TEST_CASE( ... ) CATCH_TEMPLATEHEN( desc )

#define CATCH_STATIC_REQUIRTCHERS)
#define CHECK_THROWS_MATCHES( expr, exceptionType, matcher ) (void)(0)
#endif // CATCH_CONFIG_DISABLE_MATCHERS
#define CHECK_NOTHROW( ... ) (void)(0)

#if !defined(CATCHATCH_TESTCASE_NO_REGISTRATION(INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_S_T____ ))

#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR
#define TEMPLATE_TEST_CASE( ... ) INTERNAL_CATCH_TEMPLATE_TESTE_TEST_CASE( ... ) INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_TEST_CASE_NO_REGISTRATION(__VA_ARGS__) )
#define TEMPLATE_TEST_CASE_SIG( ... ) I
#define STATIC_REQUIRE_FALSE( ... ) (void)(0)

#endif

#define CATCH_TRANSLATE_EXCEPTION( signature ) INTERNAL_CATCH_TRANSLATE_EXCEPTION_NO_REG( INTERNAL_CATCH_UNIQUE_NAME( catch_internal_ExceptionTransd catch_reenable_warnings.h
					 // end catch.hpp
#endif // TWOBLUECUBES_SINGLE_INCLUDE_CATCH_HPP_INCLUDED
