#ifndef PHP_CEXP_H
#define PHP_CEXP_H 1

#define PHP_CEXP_VERSION "1.0"
#define PHP_CEXP_EXTNAME "cexp"

PHP_FUNCTION(ifnull);
PHP_FUNCTION(ifempty);

extern zend_module_entry cexp_module_entry;
#define phpext_cexp_ptr &cexp_module_entry

#endif
