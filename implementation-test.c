/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "implementation-test.check" instead.
 */

#include <check.h>

#line 1 "implementation-test.check"
#include "implementation.h"
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include<check.h>
#define MAX 4096
char ostring1[MAX] = "MMCDXCIX";
char ostring2[MAX] = "MMCDXCVIII";

START_TEST(romancaltest)
{
#line 11
	ck_assert_str_eq(subtract(ostring1,ostring2), "I");
	

	
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, romancaltest);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
