/* confdefs.h */
#define PACKAGE_NAME "aria2"
#define PACKAGE_TARNAME "aria2"
#define PACKAGE_VERSION "1.37.0"
#define PACKAGE_STRING "aria2 1.37.0"
#define PACKAGE_BUGREPORT "https://github.com/aria2/aria2/issues"
#define PACKAGE_URL "https://aria2.github.io/"
#define PACKAGE "aria2"
#define VERSION "1.37.0"
#define HAVE_STDIO_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_STDINT_H 1
#define HAVE_STRINGS_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_UNISTD_H 1
#define HAVE_WCHAR_H 1
#define STDC_HEADERS 1
#define _ALL_SOURCE 1
#define _DARWIN_C_SOURCE 1
#define _GNU_SOURCE 1
#define _HPUX_ALT_XOPEN_SOCKET_API 1
#define _NETBSD_SOURCE 1
#define _OPENBSD_SOURCE 1
#define _POSIX_PTHREAD_SEMANTICS 1
#define __STDC_WANT_IEC_60559_ATTRIBS_EXT__ 1
#define __STDC_WANT_IEC_60559_BFP_EXT__ 1
#define __STDC_WANT_IEC_60559_DFP_EXT__ 1
#define __STDC_WANT_IEC_60559_EXT__ 1
#define __STDC_WANT_IEC_60559_FUNCS_EXT__ 1
#define __STDC_WANT_IEC_60559_TYPES_EXT__ 1
#define __STDC_WANT_LIB_EXT2__ 1
#define __STDC_WANT_MATH_SPEC_FUNCS__ 1
#define _TANDEM_SOURCE 1
#define __EXTENSIONS__ 1
#define HAVE_DLFCN_H 1
#define LT_OBJDIR ".libs/"
#define BUILD "aarch64-apple-darwin24.4.0"
#define HOST "aarch64-apple-darwin24.4.0"
#define TARGET "aarch64-apple-darwin24.4.0"
#define HAVE_CXX11 1
#define CXX11_OVERRIDE override
#define HAVE_ZLIB 1
#define HAVE_GZBUFFER 1
#define HAVE_GZSETPARAMS 1
#define HAVE_LIBXML2 1
#define HAVE_SQLITE3 1
#define HAVE_SQLITE3_OPEN_V2 1
#define HAVE_APPLETLS 1
#define HAVE_LIBSSH2 1
#define HAVE_LIBCARES 1
#define USE_APPLE_MD 1
#define ENABLE_SSL 1
#define USE_INTERNAL_BIGNUM 1
#define USE_INTERNAL_ARC4 1
#define ENABLE_BITTORRENT 1
#define ENABLE_METALINK 1
#define ENABLE_XML_RPC 1
#define ENABLE_ASYNC_DNS 1
#define HAVE_ALLOCA_H 1
#define HAVE_ALLOCA 1
#define HAVE_ARPA_INET_H 1
#define HAVE_FCNTL_H 1
#define HAVE_FLOAT_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_LANGINFO_H 1
#define HAVE_LIBINTL_H 1
#define HAVE_LIMITS_H 1
#define HAVE_LOCALE_H 1
#define HAVE_NETDB_H 1
#define HAVE_NETINET_IN_H 1
#define HAVE_NETINET_TCP_H 1
#define HAVE_POLL_H 1
#define HAVE_SIGNAL_H 1
#define HAVE_STDDEF_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_STRINGS_H 1
#define HAVE_SYS_IOCTL_H 1
#define HAVE_SYS_PARAM_H 1
#define HAVE_SYS_RESOURCE_H 1
#define HAVE_SYS_SIGNAL_H 1
#define HAVE_SYS_SOCKET_H 1
#define HAVE_SYS_TIME_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_SYS_UIO_H 1
#define HAVE_SYS_UTSNAME_H 1
#define HAVE_TERMIOS_H 1
#define HAVE_UNISTD_H 1
#define HAVE_UTIME_H 1
#define HAVE_WCHAR_H 1
#define HAVE_IFADDRS_H 1
#define HAVE_PWD_H 1
#define HAVE_STDBOOL_H 1
#define HAVE_SYS_TIME_H 1
#define HAVE_SYS_SELECT_H 1
#define HAVE_SYS_SOCKET_H 1
#define HAVE_PTRDIFF_T 1
#define HAVE_A2_STRUCT_TIMESPEC 1
#define HAVE_CFPREFERENCESCOPYAPPVALUE 1
#define HAVE_CFLOCALECOPYPREFERREDLANGUAGES 1
/* end confdefs.h.  */

#include <stdlib.h>
#include <iconv.h>

int
main (void)
{
iconv_t cd = iconv_open("","");
           iconv(cd,NULL,NULL,NULL,NULL);
           iconv_close(cd);
  ;
  return 0;
}
