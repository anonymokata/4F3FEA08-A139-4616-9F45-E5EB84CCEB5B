/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "./Src/roman-test.check" instead.
 */

#include <check.h>

#line 1 "./Src/roman-test.check"
#include "romanconverter.h"
#include "romancalculator.h"
#include <stdlib.h>

START_TEST(romanConverterTest)
{
#line 6

	char buffer[20];
	

	// check roman2dec_str
	ck_assert_int_eq(roman2dec_str(""), 0);
	ck_assert_int_eq(roman2dec_str("m"), 1000);
	ck_assert_int_eq(roman2dec_str("lXxXvIiI"), 88);
	ck_assert_int_eq(roman2dec_str("MMMACIX"), 0);
	ck_assert_int_eq(roman2dec_str("MMMMMXII"), 0);


	// check dec2roman 
	dec2roman(1, buffer);
	ck_assert_str_eq(buffer,"I");
	dec2roman(4999, buffer);
	ck_assert_str_eq(buffer,"MMMMCMXCIX");
	dec2roman(5000, buffer);
	ck_assert_str_eq(buffer,"\0");
	ck_assert_int_eq(dec2roman(4999, buffer), 1);
	ck_assert_int_eq(dec2roman(5000, buffer), 0);

	// check isItValidRomanNumeral
	ck_assert_int_eq(isItValidRomanNum("X"),1);
	ck_assert_int_eq(isItValidRomanNum("IIX"),0);
	ck_assert_int_eq(isItValidRomanNum("XBI"),0);
	ck_assert_int_eq(isItValidRomanNum("XXXX"),0);
	ck_assert_int_eq(isItValidRomanNum("DD"),0);


}
END_TEST

START_TEST(romanCalcTest)
{
#line 37
	char buffer[20];
	
	ck_assert_int_eq(add2romanNum("I", "I", buffer), 1);
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, romanConverterTest);
    tcase_add_test(tc1_1, romanCalcTest);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
