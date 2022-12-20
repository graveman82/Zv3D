#ifndef ZV3D_CORE_COMMON_CRTDEFS_H
#define ZV3D_CORE_COMMON_CRTDEFS_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: crt types and routines declarations.
/*
	20-Dec-2022	grv creation.
*/

//-----------------------------------------------------------------------------
// Headers.
#include <stddef.h>

//-----------------------------------------------------------------------------
// crt integers
typedef ZvdLangSize_t              ZvdLangSize_t;
typedef ZvdLangFile					ZvdLangFile;

extern void* ZvdStdIn;
extern void* ZvdStdOut;
extern void* ZvdStdErr;
//-----------------------------------------------------------------------------
/* Function prototypes */

// malloc.h
typedef void *			(*__cdecl Zvdcalloc_t)(ZvdLangSize_t, ZvdLangSize_t);
typedef void			(*__cdecl Zvdfree_t)(void *);
typedef void *			(*__cdecl Zvdmalloc_t)(ZvdLangSize_t);
typedef void *			(*__cdecl Zvdrealloc_t)(void *, ZvdLangSize_t);
typedef void			(*__cdecl Zvd_aligned_free_t)(void *);
typedef void *			(*__cdecl Zvd_aligned_malloc_t)(ZvdLangSize_t, ZvdLangSize_t);
typedef void *			(*__cdecl Zvd_aligned_offset_malloc_t)(ZvdLangSize_t, ZvdLangSize_t, ZvdLangSize_t);
typedef void *			(*__cdecl Zvd_aligned_realloc_t)(void *, ZvdLangSize_t, ZvdLangSize_t);
typedef void *			(*__cdecl Zvd_aligned_offset_realloc_t)(void *, ZvdLangSize_t, ZvdLangSize_t, ZvdLangSize_t);
typedef int				(*__cdecl Zvd_resetstkoflw_t)(void);

// string.h

typedef void *			(*__cdecl Zvdmemcpy_t)(void *, const void *, ZvdLangSize_t);
typedef int				(*__cdecl Zvdmemcmp_t)(const void *, const void *, ZvdLangSize_t);
typedef void *			(*__cdecl Zvdmemset_t)(void *, int, ZvdLangSize_t);
typedef char *			(*__cdecl Zvd_strset_t)(char *, int);
typedef char *			(*__cdecl Zvdstrcpy_t)(char *, const char *);
typedef char *			(*__cdecl Zvdstrcat_t)(char *, const char *);
typedef int				(*__cdecl Zvdstrcmp_t)(const char *, const char *);
typedef ZvdLangSize_t	(*__cdecl Zvdstrlen_t)(const char *);

typedef void *			(*__cdecl Zvd_memccpy_t)(void *, const void *, int, ZvdLangSize_t);
typedef void *			(*__cdecl Zvdmemchr_t)(const void *, int, ZvdLangSize_t);
typedef int				(*__cdecl Zvd_memicmp_t)(const void *, const void *, ZvdLangSize_t);

typedef void *			(*__cdecl Zvdmemmove_t)(void *, const void *, ZvdLangSize_t);

typedef char *			(*__cdecl Zvdstrchr_t)(const char *, int);
typedef int				(*__cdecl Zvd_strcmpi_t)(const char *, const char *);
typedef int				(*__cdecl Zvd_stricmp_t)(const char *, const char *);
typedef int				(*__cdecl Zvdstrcoll_t)(const char *, const char *);
typedef int				(*__cdecl Zvd_stricoll_t)(const char *, const char *);
typedef int				(*__cdecl Zvd_strncoll_t)(const char *, const char *, ZvdLangSize_t);
typedef int				(*__cdecl Zvd_strnicoll_t)(const char *, const char *, ZvdLangSize_t);
typedef ZvdLangSize_t	(*__cdecl Zvdstrcspn_t)(const char *, const char *);
typedef char *			(*__cdecl Zvd_strdup_t)(const char *);
typedef char *			(*__cdecl Zvd_strerror_t)(const char *);
typedef char *			(*__cdecl Zvdstrerror_t)(int);
typedef char *			(*__cdecl Zvd_strlwr_t)(char *);
typedef char *			(*__cdecl Zvdstrncat_t)(char *, const char *, ZvdLangSize_t);
typedef int				(*__cdecl Zvdstrncmp_t)(const char *, const char *, ZvdLangSize_t);
typedef int				(*__cdecl Zvd_strnicmp_t)(const char *, const char *, ZvdLangSize_t);
typedef char *			(*__cdecl Zvdstrncpy_t)(char *, const char *, ZvdLangSize_t);
typedef char *			(*__cdecl Zvd_strnset_t)(char *, int, ZvdLangSize_t);
typedef char *			(*__cdecl Zvdstrpbrk_t)(const char *, const char *);
typedef char *			(*__cdecl Zvdstrrchr_t)(const char *, int);
typedef char *			(*__cdecl Zvd_strrev_t)(char *);
typedef ZvdLangSize_t	(*__cdecl Zvdstrspn_t)(const char *, const char *);
typedef char *			(*__cdecl Zvdstrstr_t)(const char *, const char *);
typedef char *			(*__cdecl Zvdstrtok_t)(char *, const char *);
typedef char *			(*__cdecl Zvd_strupr_t)(char *);
typedef ZvdLangSize_t	(*__cdecl Zvdstrxfrm_t)(char *, const char *, ZvdLangSize_t);


typedef wchar_t *		(*__cdecl Zvdwcscat_t)(wchar_t *, const wchar_t *);
typedef wchar_t *		(*__cdecl Zvdwcschr_t)(const wchar_t *, wchar_t);
typedef int				(*__cdecl Zvdwcscmp_t)(const wchar_t *, const wchar_t *);
typedef wchar_t *		(*__cdecl Zvdwcscpy_t)(wchar_t *, const wchar_t *);
typedef ZvdLangSize_t	(*__cdecl Zvdwcscspn_t)(const wchar_t *, const wchar_t *);
typedef ZvdLangSize_t	(*__cdecl Zvdwcslen_t)(const wchar_t *);
typedef wchar_t *		(*__cdecl Zvdwcsncat_t)(wchar_t *, const wchar_t *, ZvdLangSize_t);
typedef int				(*__cdecl Zvdwcsncmp_t)(const wchar_t *, const wchar_t *, ZvdLangSize_t);
typedef wchar_t *		(*__cdecl Zvdwcsncpy_t)(wchar_t *, const wchar_t *, ZvdLangSize_t);
typedef wchar_t *		(*__cdecl Zvdwcspbrk_t)(const wchar_t *, const wchar_t *);
typedef wchar_t *		(*__cdecl Zvdwcsrchr_t)(const wchar_t *, wchar_t);
typedef ZvdLangSize_t	(*__cdecl Zvdwcsspn_t)(const wchar_t *, const wchar_t *);
typedef wchar_t *		(*__cdecl Zvdwcsstr_t)(const wchar_t *, const wchar_t *);
typedef wchar_t *		(*__cdecl Zvdwcstok_t)(wchar_t *, const wchar_t *);
typedef wchar_t *		(*__cdecl Zvd_wcserror_t)(int);
typedef wchar_t *		(*__cdecl Zvd__wcserror_t)(const wchar_t *);

typedef wchar_t *		(*__cdecl Zvd_wcsdup_t)(const wchar_t *);
typedef int				(*__cdecl Zvd_wcsicmp_t)(const wchar_t *, const wchar_t *);
typedef int				(*__cdecl Zvd_wcsnicmp_t)(const wchar_t *, const wchar_t *, ZvdLangSize_t);
typedef wchar_t *		(*__cdecl Zvd_wcsnset_t)(wchar_t *, wchar_t, ZvdLangSize_t);
typedef wchar_t *		(*__cdecl Zvd_wcsrev_t)(wchar_t *);
typedef wchar_t *		(*__cdecl Zvd_wcsset_t)(wchar_t *, wchar_t);

typedef wchar_t *		(*__cdecl Zvd_wcslwr_t)(wchar_t *);
typedef wchar_t *		(*__cdecl Zvd_wcsupr_t)(wchar_t *);
typedef ZvdLangSize_t	(*__cdecl Zvdwcsxfrm_t)(wchar_t *, const wchar_t *, ZvdLangSize_t);
typedef int				(*__cdecl Zvdwcscoll_t)(const wchar_t *, const wchar_t *);
typedef int				(*__cdecl Zvd_wcsicoll_t)(const wchar_t *, const wchar_t *);
typedef int				(*__cdecl Zvd_wcsncoll_t)(const wchar_t *, const wchar_t *, ZvdLangSize_t);
typedef int				(*__cdecl Zvd_wcsnicoll_t)(const wchar_t *, const wchar_t *, ZvdLangSize_t);

// stdio.h
typedef int				(*__cdecl Zvd_filbuf_t)(ZvdLangFile *);
typedef int				(*__cdecl Zvd_flsbuf_t)(int, ZvdLangFile *);

typedef ZvdLangFile *	(*__cdecl Zvd_fsopen_t)(const char *, const char *, int);

typedef void			(*__cdecl Zvdclearerr_t)(ZvdLangFile *);
typedef int				(*__cdecl Zvdfclose_t)(ZvdLangFile *);
typedef int				(*__cdecl Zvd_fcloseall_t)(void);

typedef ZvdLangFile *	(*__cdecl Zvd_fdopen_t)(int, const char *);

typedef int				(*__cdecl Zvdfeof_t)(ZvdLangFile *);
typedef int				(*__cdecl Zvdferror_t)(ZvdLangFile *);
typedef int				(*__cdecl Zvdfflush_t)(ZvdLangFile *);
typedef int				(*__cdecl Zvdfgetc_t)(ZvdLangFile *);
typedef int				(*__cdecl Zvd_fgetchar_t)(void);
typedef int				(*__cdecl Zvdfgetpos_t)(ZvdLangFile *, fpos_t *);
typedef char *			(*__cdecl Zvdfgets_t)(char *, int, ZvdLangFile *);

typedef int				(*__cdecl Zvd_fileno_t)(ZvdLangFile *);

typedef int				(*__cdecl Zvd_flushall_t)(void);
typedef ZvdLangFile *	(*__cdecl Zvdfopen_t)(const char *, const char *);
typedef int				(*__cdecl Zvdfprintf_t)(ZvdLangFile *, const char *, ...);
typedef int				(*__cdecl Zvdfputc_t)(int, ZvdLangFile *);
typedef int				(*__cdecl Zvd_fputchar_t)(int);
typedef int				(*__cdecl Zvdfputs_t)(const char *, ZvdLangFile *);
typedef ZvdLangSize_t	(*__cdecl Zvdfread_t)(void *, ZvdLangSize_t, ZvdLangSize_t, ZvdLangFile *);
typedef ZvdLangFile *	(*__cdecl Zvdfreopen_t)(const char *, const char *, ZvdLangFile *);
typedef int				(*__cdecl Zvdfscanf_t)(ZvdLangFile *, const char *, ...);
typedef int				(*__cdecl Zvdfsetpos_t)(ZvdLangFile *, const fpos_t *);
typedef int				(*__cdecl Zvdfseek_t)(ZvdLangFile *, long, int);
typedef long			(*__cdecl Zvdftell_t)(ZvdLangFile *);
typedef ZvdLangSize_t	(*__cdecl Zvdfwrite_t)(const void *, ZvdLangSize_t, ZvdLangSize_t, ZvdLangFile *);
typedef int				(*__cdecl Zvdgetc_t)(ZvdLangFile *);
typedef int				(*__cdecl Zvdgetchar_t)(void);
typedef int				(*__cdecl Zvd_getmaxstdio_t)(void);
typedef char *			(*__cdecl Zvdgets_t)(char *);
typedef int				(*__cdecl Zvd_getw_t)(ZvdLangFile *);
typedef void			(*__cdecl Zvdperror_t)(const char *);
typedef int				(*__cdecl Zvd_pclose_t)(ZvdLangFile *);
typedef ZvdLangFile *	(*__cdecl Zvd_popen_t)(const char *, const char *);
typedef int				(*__cdecl Zvdprintf_t)(const char *, ...);
typedef int				(*__cdecl Zvdputc_t)(int, ZvdLangFile *);
typedef int				(*__cdecl Zvdputchar_t)(int);
typedef int				(*__cdecl Zvdputs_t)(const char *);
typedef int				(*__cdecl Zvd_putw_t)(int, ZvdLangFile *);
typedef int				(*__cdecl Zvdremove_t)(const char *);
typedef int				(*__cdecl Zvdrename_t)(const char *, const char *);
typedef void			(*__cdecl Zvdrewind_t)(ZvdLangFile *);
typedef int				(*__cdecl Zvd_rmtmp_t)(void);
typedef int				(*__cdecl Zvdscanf_t)(const char *, ...);
typedef void			(*__cdecl Zvdsetbuf_t)(ZvdLangFile *, char *);
typedef int				(*__cdecl Zvd_setmaxstdio_t)(int);
typedef int				(*__cdecl Zvdsetvbuf_t)(ZvdLangFile *, char *, int, ZvdLangSize_t);
typedef int				(*__cdecl Zvd_snprintf_t)(char *, ZvdLangSize_t, const char *, ...);
typedef int				(*__cdecl Zvdsprintf_t)(char *, const char *, ...);
typedef int				(*__cdecl Zvd_scprintf_t)(const char *, ...);
typedef int				(*__cdecl Zvdsscanf_t)(const char *, const char *, ...);
typedef int				(*__cdecl Zvd_snscanf_t)(const char *, ZvdLangSize_t, const char *, ...);
typedef char *			(*__cdecl Zvd_tempnam_t)(const char *, const char *);
typedef ZvdLangFile *	(*__cdecl Zvdtmpfile_t)(void);
typedef char *			(*__cdecl Zvdtmpnam_t)(char *);
typedef int				(*__cdecl Zvdungetc_t)(int, ZvdLangFile *);
typedef int				(*__cdecl Zvd_unlink_t)(const char *);
typedef int				(*__cdecl Zvdvfprintf_t)(ZvdLangFile *, const char *, va_list);
typedef int				(*__cdecl Zvdvprintf_t)(const char *, va_list);
typedef int				(*__cdecl Zvd_vsnprintf_t)(char *, ZvdLangSize_t, const char *, va_list);
typedef int				(*__cdecl Zvdvsprintf_t)(char *, const char *, va_list);
typedef int				(*__cdecl Zvd_vscprintf_t)(const char *, va_list);

#endif // ZV3D_CORE_COMMON_CRTDEFS_H