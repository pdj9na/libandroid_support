#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libandroid_support], [0.0.1],[1846935695@qq.com])

AC_CONFIG_MACRO_DIR([m4])
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_HEADERS([include/config.h])

case $target_os in
     *android)	arch_sub=android;;
esac

if test "$ac_env_CFLAGS_set" != set; then
	CFLAGS="-g -O2"

	if test "$arch_sub" = android;then
		CFLAGS="$CFLAGS -fPIE -pie"
	fi
fi

if test "$ac_env_CPPFLAGS_set" != set; then
	CPPFLAGS="-D_FILE_OFFSET_BITS=64 $CPPFLAGS"
fi

AC_PROG_LIBTOOL
AC_PROG_CC
AC_PROG_MKDIR_P
AM_PROG_CC_C_O

VERSION_NUM=$(echo $VERSION | awk -F. '{printf("%s:%s:%s",$1,$2,$3)}')
AC_SUBST(VERSION_NUM)

AC_CONFIG_FILES([Makefile lib/Makefile])
AC_OUTPUT
