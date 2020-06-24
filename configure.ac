AC_PREREQ([2.68])
AC_INIT([hometec], [0.1], [], [],
 [https://github.com/sjgarani/hometec.git])
AM_INIT_AUTOMAKE([-Werror -Wno-override foreign])
AM_SILENT_RULES([yes])

AC_LANG([Erlang])
AC_ERLANG_SUBST_LIB_DIR
if test -z "${ERLANG_INSTALL_LIB_DIR}" ; then
	ERLANG_INSTALL_LIB_DIR=$ERLANG_LIB_DIR
fi
AC_ERLANG_SUBST_ROOT_DIR
AC_ERLANG_SUBST_INSTALL_LIB_DIR

# Checks for programs.

AC_PATH_PROG(SED, sed)

AC_ERLANG_NEED_ERLC
AC_ERLANG_NEED_ERL
AC_ERLANG_SUBST_ERTS_VER
AC_ERLANG_CHECK_LIB([kernel],[],[])
AC_ERLANG_CHECK_LIB([stdlib],[],[])

# Checks for header files.

# Checks for library functions.

dnl ----------------------------------------------------------------------
dnl Set version
dnl ----------------------------------------------------------------------

HOMETEC_VSN=`git describe --tags --always 2>/dev/null`
if test "$HOMETEC_VSN" = "";
  then HOMETEC_VSN=`cat $srcdir/HOMETEC_VSN`
  else echo $HOMETEC_VSN>$srcdir/HOMETEC_VSN
fi
AC_SUBST(HOMETEC_VSN)

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 sys/Makefile
                 sys/hometec.rel
                 sys/hometec.start
                 sys/hometec.stop])

AC_OUTPUT