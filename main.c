/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:33:25 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/25 17:12:30 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	
}

/* #include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <assert.h>

#define TEST(expected_str, expected_ret, fmt, ...) do {                 \
    char buf[256] = {0};                                               \
    int ret = snprintf(buf, sizeof(buf), fmt, ##__VA_ARGS__);         \
    assert(ret == (expected_ret));                                     \
    assert(strcmp(buf, (expected_str)) == 0);                          \
                                                                       \
    int my_ret = ft_printf(fmt, ##__VA_ARGS__);                        \
    assert(my_ret == (expected_ret));                                  \
    assert(strcmp(buf, buf) == 0); \
} while (0)


int main(void) {
    //–– Simple strings and %%
    TEST("hello, world", 12, "hello, world");
    TEST("100% sure",    10, "100%% sure");

    //–– Integer formats
    TEST("zero 0",        6, "zero %d", 0);
    TEST("minus -42",     8, "minus %i", -42);
    TEST("max 2147483647",14, "max %d", INT_MAX);
    TEST("min -2147483648",15,"min %d", INT_MIN);
    TEST("u 4294967295", 12, "u %u", UINT_MAX);
    TEST("oct 17",        5, "oct %o", 15);
    TEST("hex ff",        6, "hex %x", 255);
    TEST("HEX FF",        6, "HEX %X", 255);

    //–– Pointers
    void *p = (void*)0x1234;
    char expected[64];
	int exp_ret = snprintf(expected, sizeof(expected), "ptr %p", p);
	TEST(expected, exp_ret, "ptr %p", p);

    //–– Characters
    TEST("A", 1, "%c", 'A');
    TEST("\0", 1, "%c", '\0');

    //–– Strings (including NULL)
    TEST("(null)", 6, "%s", (char*)NULL);
    TEST("hi",     2, "%s", "hi");

    //–– Float formats
    TEST("3.140000", 8, "%f", 3.14);
    TEST("nan",      3, "%f", 0.0/0.0);
    TEST("inf",      3, "%f", 1.0/0.0);

    //–– Exponential and shortest
    TEST("1.234500e+02",12,"%e", 123.45);
    TEST("1.2345e+02", 10,"%g", 123.45);

    //–– Width and precision
    TEST("   42", 5, "%5d", 42);
    TEST("00042", 5, "%05d", 42);
    TEST("42   ", 5, "%-5d", 42);
    TEST("0x2a",  4, "%#x", 42);
    TEST("0X2A",  4, "%#X", 42);
    TEST("+1.00", 5, "%+.2f", 1.0);

    //–– Dynamic width/precision
    TEST("   7", 4, "%*d", 4, 7);
    TEST("3.14", 4, "%.*f", 2, 3.14159);

    //–– Length modifiers
    long long llv = LLONG_MAX;
    TEST("ll 9223372036854775807", 22, "ll %lld", llv);
    short sv = SHRT_MAX;
    TEST("sh 32767",              8,  "sh %hd", sv);

    //–– Mixed specifiers
    TEST("A=65, s=hello, f=2.50", 20,
         "A=%c, s=%s, f=%.2f", 'A', "hello", 2.5);

    puts("All tests passed!");
    return 0;
} */
