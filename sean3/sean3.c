/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_sean3.h"

/* If you declare any globals in php_sean3.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(sean3)
*/

/* True global resources - no need for thread safety here */
static int le_sean3;

/* {{{ sean3_functions[]
 *
 * Every user visible function must have an entry in sean3_functions[].
 */
const zend_function_entry sean3_functions[] = {
	PHP_FE(confirm_sean3_compiled,	NULL)		/* For testing, remove later. */
    PHP_FE(sean3_get_globals, NULL)
	PHP_FE_END	/* Must be the last line in sean3_functions[] */
};
/* }}} */

/* {{{ sean3_module_entry
 */
zend_module_entry sean3_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"sean3",
	sean3_functions,
	PHP_MINIT(sean3),
	PHP_MSHUTDOWN(sean3),
	PHP_RINIT(sean3),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(sean3),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(sean3),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_SEAN3_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SEAN3
ZEND_GET_MODULE(sean3)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("sean3.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_sean3_globals, sean3_globals)
    STD_PHP_INI_ENTRY("sean3.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_sean3_globals, sean3_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_sean3_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_sean3_init_globals(zend_sean3_globals *sean3_globals)
{
	sean3_globals->global_value = 0;
	sean3_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(sean3)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(sean3)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(sean3)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(sean3)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(sean3)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "sean3 support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_sean3_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_sean3_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "sean3", arg);
	RETURN_STRINGL(strg, len, 0);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/


//    zval **doll_get = NULL;
//
//    if ( zend_hash_find(&EG(symbol_table), "_GET",sizeof("_GET"),(void **)&doll_get) == SUCCESS ){
//        php_var_dump(doll_get, 1 TSRMLS_CC);
//    }else{
//        php_printf("not find $_GET\n");
//    }
//    
//    
//    zval **fooval = NULL;
    
//    if( zend_hash_find(EG(active_symbol_table),"foo",sizeof("foo"),(void **)&fooval) == SUCCESS){
//        php_var_dump(fooval, 1 TSRMLS_CC);
//    }else{
//        php_printf("$foo is not defined!");
//    }
//    
//    ZVAL_STRING(*fooval, "123", 1);
    
    
    
    
//    char *test = emalloc(sizeof("test")+1);
//    *test = "test";

PHP_FUNCTION(sean3_get_globals){
    zval *testval;
    MAKE_STD_ZVAL(testval);
    ZVAL_STRING(testval, "test", 1);
    
    
    
    ZEND_SET_SYMBOL(&EG(symbol_table),"foo",testval);
    
    /*
    zval **orig_var;
    if (zend_hash_find(&EG(symbol_table), "foo", sizeof("foo"), (void **) &orig_var)==SUCCESS){
        efree(*orig_var);
        zend_hash_update(&EG(symbol_table), "foo", sizeof("foo"),&testval, sizeof(zval*), NULL);
    }else{
        zend_hash_add(&EG(symbol_table), "foo", sizeof("foo"), &testval, sizeof(zval*), NULL);
    }
    */
}





/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
