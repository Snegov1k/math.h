#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(s21_asin_usual_test) {
  double test_values[] = {0.0,    0.4313,  0.823, -0.7283,
                          -0.392, 0.58495, 1.0,   -1.0};
  for (int i = 0; i < (int)(sizeof(test_values) / sizeof(test_values[0]));
       i++) {
    ck_assert_double_eq_tol(s21_asin(test_values[i]), asin(test_values[i]),
                            1e-6);
  }

  ck_assert_double_nan(s21_asin(853));
}
END_TEST

Suite *s21_asin_suite() {
  Suite *s = suite_create("s21_asin");
  TCase *tc = tcase_create("s21_asin");

  tcase_add_test(tc, s21_asin_usual_test);
  suite_add_tcase(s, tc);

  return s;
}

int main() {
  int number_failed;
  SRunner *runner;

  runner = srunner_create(s21_asin_suite());

  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
