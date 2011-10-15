PHP_ARG_ENABLE(cexp, whether to enable cexp support,
[ --enable-cexp   Enable cexp support])

if test "$PHP_CEXP" = "yes"; then
  AC_DEFINE(HAVE_CEXP, 1, [Whether you have cexp])
  PHP_NEW_EXTENSION(cexp, cexp.c, $ext_shared)
fi
