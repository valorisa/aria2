/* confdefs.h */
#define PACKAGE_NAME "wslay"
#define PACKAGE_TARNAME "wslay"
#define PACKAGE_VERSION "1.1.1"
#define PACKAGE_STRING "wslay 1.1.1"
#define PACKAGE_BUGREPORT "t-tujikawa@users.sourceforge.net"
#define PACKAGE_URL ""
#define HAVE_STDIO_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_STDINT_H 1
#define HAVE_STRINGS_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_UNISTD_H 1
#define STDC_HEADERS 1
#define HAVE_DLFCN_H 1
#define LT_OBJDIR ".libs/"
#define PACKAGE "wslay"
#define VERSION "1.1.1"
#define HAVE_ARPA_INET_H 1
#define HAVE_NETINET_IN_H 1
#define HAVE_STDDEF_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_UNISTD_H 1
#define HAVE_PTRDIFF_T 1
#define HAVE_MEMMOVE 1
#define HAVE_MEMSET 1
/* end confdefs.h.  */
/* Define ntohl to an innocuous variant, in case <limits.h> declares ntohl.
   For example, HP-UX 11i <limits.h> declares gettimeofday.  */
#define ntohl innocuous_ntohl

/* System header to define __stub macros and hopefully few prototypes,
   which can conflict with char ntohl (void); below.  */

#include <limits.h>
#undef ntohl

/* Override any GCC internal prototype to avoid an error.
   Use char because int might match the return type of a GCC
   builtin and then its argument prototype would still apply.  */
#ifdef __cplusplus
extern "C"
#endif
char ntohl (void);
/* The GNU C library defines this for functions which it implements
    to always fail with ENOSYS.  Some functions are actually named
    something starting with __ and the normal name is an alias.  */
#if defined __stub_ntohl || defined __stub___ntohl
choke me
#endif

int
main (void)
{
return ntohl ();
  ;
  return 0;
}
