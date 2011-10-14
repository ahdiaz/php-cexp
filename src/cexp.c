#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_cexp.h"

static function_entry cexp_functions[] = {
    PHP_FE(ifnull, NULL)
    PHP_FE(ifempty, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry cexp_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_CEXP_EXTNAME,
    cexp_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_CEXP_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_CEXP
ZEND_GET_MODULE(cexp)
#endif

PHP_FUNCTION(ifnull) {

	zval *value;
	zval *null_value;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &value, &null_value) == FAILURE) {
		RETURN_NULL();
	}

	switch (Z_TYPE_P(value)) {
		case IS_NULL:
			*return_value = *null_value;
			break;
		default:
			*return_value = *value;
	}

	zval_copy_ctor(return_value);
	return;
}

PHP_FUNCTION(ifempty) {

	zval *value;
	zval *empty_value;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &value, &empty_value) == FAILURE) {
		RETURN_NULL();
	}

	switch (Z_TYPE_P(value)) {
		case IS_NULL:
			*return_value = *empty_value;
			break;
			
		case IS_STRING:
			if (Z_STRLEN_P(value) == 0) {
				*return_value = *empty_value;
			} else {
				*return_value = *value;
			}
			break;
			
		case IS_BOOL:
			if (Z_BVAL_P(value) == 0) {
				*return_value = *empty_value;
			} else {
				*return_value = *value;
			}
			break;
			
		case IS_LONG:
		case IS_DOUBLE:
			if (Z_LVAL_P(value) == 0) {
				*return_value = *empty_value;
			} else {
				*return_value = *value;
			}
			break;
			
		default:
			*return_value = *value;
	}

	zval_copy_ctor(return_value);
	return;
}
