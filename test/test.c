/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <mmeyer@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:31:31 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/11/23 10:41:24 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include "tinytest.h"
#include <bsd/string.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define LONG_MIN -9223372036854775808
#define INT_MAX 2147483647

int strncmp_nul(char *s1, char *s2, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (s1[i] != '\0' || s2[i] != '\0')
			return (1);
	}
	return (0);
}

void success(const char *file)
{
	printf("%c%s[OK]%c%s [%s]\n",
		   TT_COLOR_CODE,
		   TT_COLOR_GREEN,
		   TT_COLOR_CODE,
		   TT_COLOR_RESET,
		   file);
}

void fail(char *file)
{
	printf("%c%sFAILED%c%s [%s] \n",
		   TT_COLOR_CODE,
		   TT_COLOR_RED,
		   TT_COLOR_CODE,
		   TT_COLOR_RESET,
		   file);
}

void test_ft_isalpha(void)
{
	for (int i = -1; i < 500; i++)
		ASSERT_EQUALS(isalpha(i) > 0, ft_isalpha(i) > 0);

	success(__FUNCTION__);
}

void test_ft_isdigit(void)
{
	for (int i = -1; i < 500; i++)
		ASSERT_EQUALS(isdigit(i) > 0, ft_isdigit(i) > 0);

	success(__FUNCTION__);
}

void test_ft_isalnum(void)
{
	for (int i = -1; i < 127; i++)
		ASSERT_EQUALS(isalnum(i) > 0, ft_isalnum(i) > 0);

	success(__FUNCTION__);
}

void test_ft_isascii(void)
{
	for (int i = -200; i < 530; i++)
		ASSERT_EQUALS(__isascii(i) > 0, ft_isascii(i) > 0);

	success(__FUNCTION__);
}

void test_ft_isprint(void)
{
	for (int i = -200; i < 530; i++)
		ASSERT_EQUALS(isprint(i) > 0, ft_isprint(i) > 0);

	success(__FUNCTION__);
}

void test_ft_toupper(void)
{
	for (int i = -1; i < 530; i++)
		ASSERT_EQUALS(toupper(i) > 0, ft_toupper(i) > 0);

	success(__FUNCTION__);
}
void test_ft_tolower(void)
{
	for (int i = -1; i < 530; i++)
		ASSERT_EQUALS(tolower(i) > 0, ft_tolower(i) > 0);

	success(__FUNCTION__);
}

void test_ft_strlen(void)
{
	ASSERT_EQUALS(strlen("Aa"), ft_strlen("Aa"));
	ASSERT_EQUALS(strlen("Hello"), ft_strlen("Hello"));
	ASSERT_EQUALS(strlen("How are you?"), ft_strlen("How are you?"));
	ASSERT_EQUALS(strlen("just some text"), ft_strlen("just some text"));
	ASSERT_EQUALS(strlen("       "), ft_strlen("       "));
	ASSERT_EQUALS(strlen("      hello"), ft_strlen("      hello"));
	ASSERT_EQUALS(strlen(""), ft_strlen(""));
	ASSERT_EQUALS(strlen("what about a \0 in the middle?"),
				  ft_strlen("what about a \0 in the middle?"));

	success(__FUNCTION__);
}

void test_ft_atoi(void)
{
	ASSERT_EQUALS(atoi("0"), ft_atoi("0"));
	ASSERT_EQUALS(atoi("546:5"), ft_atoi("546:5"));
	ASSERT_EQUALS(atoi("-4886"), ft_atoi("-4886"));
	ASSERT_EQUALS(atoi("+548"), ft_atoi("+548"));
	ASSERT_EQUALS(atoi("054854"), ft_atoi("054854"));
	ASSERT_EQUALS(atoi("000074"), ft_atoi("000074"));
	ASSERT_EQUALS(atoi("+-54"), ft_atoi("+-54"));
	ASSERT_EQUALS(atoi("-+48"), ft_atoi("-+48"));
	ASSERT_EQUALS(atoi("--47"), ft_atoi("--47"));
	ASSERT_EQUALS(atoi("++47"), ft_atoi("++47"));
	ASSERT_EQUALS(atoi("+47+5"), ft_atoi("+47+5"));
	ASSERT_EQUALS(atoi("-47-5"), ft_atoi("-47-5"));
	ASSERT_EQUALS(atoi("\e475"), ft_atoi("\e475"));
	ASSERT_EQUALS(atoi("\t\n\r\v\f  469 \n"), ft_atoi("\t\n\r\v\f  469 \n"));
	ASSERT_EQUALS(atoi("-2147483648"), ft_atoi("-2147483648"));
	ASSERT_EQUALS(atoi("2147483647"), ft_atoi("2147483647"));
	ASSERT_EQUALS(atoi("2147483648"), ft_atoi("2147483648"));
	ASSERT_EQUALS(atoi("2147483648"), ft_atoi("2147483648"));
	ASSERT_EQUALS(atoi("-3147483649"), ft_atoi("-3147483649"));
	ASSERT_EQUALS(atoi("9223372036854775999"), ft_atoi("9223372036854775999"));
	ASSERT_EQUALS(atoi("-9223372036854775999"), ft_atoi("-9223372036854775999"));
	ASSERT_EQUALS(atoi("999999999999999999"), ft_atoi("999999999999999999"));
	ASSERT_EQUALS(atoi("-999999999999999999"), ft_atoi("-999999999999999999"));
	ASSERT_EQUALS(atoi("9999999999999999991"), ft_atoi("9999999999999999991"));
	ASSERT_EQUALS(atoi("-9999999999999999991"), ft_atoi("-9999999999999999991"));
	ASSERT_EQUALS(atoi("214748400000"), ft_atoi("214748400000"));
	ASSERT_EQUALS(atoi("\t\n\r\v\fd469 \n"), ft_atoi("\t\n\r\v\fd469 \n"));
	ASSERT_EQUALS(atoi("\n\n\n  -46\b9 \n5d6"),
				  ft_atoi("\n\n\n  -46\b9 \n5d6"));
	ASSERT_EQUALS(atoi(""), ft_atoi(""));

	success(__FUNCTION__);
}

void test_ft_strncmp(void)
{
	ASSERT_EQUALS(strncmp("A", "a", 1), ft_strncmp("A", "a", 1));
	ASSERT_EQUALS(strncmp("Hello", "Hello", 5),
				  ft_strncmp("Hello", "Hello", 5));
	ASSERT_EQUALS(strncmp("Fail", "FaiL", 10),
				  ft_strncmp("Fail", "FaiL", 10));
	ASSERT_EQUALS(strncmp("This is A Example", "This is A Example", 25),
				  ft_strncmp("This is A Example", "This is A Example", 25));
	ASSERT_EQUALS(strncmp("This is A", "This is A Example", 9),
				  ft_strncmp("This is A", "This is A Example", 9));
	ASSERT_EQUALS(strncmp("ThiA is A", "ThiS is A Example", 3),
				  ft_strncmp("ThiA is A", "ThiS is A Example", 3));
	ASSERT_EQUALS(strncmp("this is just an examle", "this is ", 20), ft_strncmp("this is just an examle", "this is ", 20));
	ASSERT_EQUALS(strncmp("this is just an examle", "this is just an examle", 20), ft_strncmp("this is just an examle", "this is just an examle", 20));
	ASSERT_EQUALS(strncmp("this is just an examle", "this is just an examle\0a", 150), ft_strncmp("this is just an examle", "this is just an examle\0a", 150));

	success(__FUNCTION__);
}

void test_ft_strlcat(void)
{
	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff1[0xF00] = "there is no stars in the sky";
	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;

	ft_strlcat(buff1, str, max);

	ft_strlcat(buff1, str, max);
	char s1[4] = "";
	ft_strlcat(s1, "thx to ntoniolo for this test !", 4);

	max = strlen(str) + strlen("there is no stars in the sky");
	ft_strlcat(buff1, str, max);

	success(__FUNCTION__);
}

void test_ft_strlcpy(void)
{

	char *str2 = "World hahha!";
	char buffer[12];
	char *str3 = "";

	ASSERT_EQUALS(12, ft_strlcpy(buffer, str2, 12));
	ASSERT_EQUALS(0, ft_strlcpy(buffer, NULL, 12));
	ASSERT_EQUALS(strlen(str2), ft_strlcpy(NULL, str2, 12));
	ASSERT_EQUALS(0, ft_strlcpy(NULL, NULL, 12));
	ASSERT_EQUALS(0, ft_strlcpy(buffer, str3, 0));
	ASSERT_EQUALS(0, ft_strlcpy(buffer, NULL, 0));
	ASSERT_EQUALS(0, ft_strlcpy(buffer, NULL, 0));
	ASSERT_EQUALS(0, ft_strlcpy(buffer, NULL, 5));

	success(__FUNCTION__);
}

void test_ft_strdup(void)
{
	char *str_1 = "this is a test";
	char *str_2 = ft_strdup(str_1);
	ASSERT_STRING_EQUALS(str_2, str_1);
	free(str_2);
	char *str_3 = "";
	char *str_4 = ft_strdup(str_3);
	ASSERT_STRING_EQUALS(str_3, str_4);
	free(str_4);

	success(__FUNCTION__);
}

void test_ft_strjoin_simple_input()
{
	char *s1 = "my favorite animal is";
	char *s2 = " ";
	char *s3 = "the nyancat";
	char *tmp = ft_strjoin(s1, s2);
	char *test = ft_strjoin(tmp, s3);
	char *expected = "my favorite animal is the nyancat";

	ASSERT_STRING_EQUALS(expected, test);
	free(tmp);
	free(test);
}

void test_ft_strjoin_simple_input2()
{
	char *s1 = "my favorite animal is";
	char *s2 = " ";
	char *s3 = "the nyancat";
	char *tmp = ft_strjoin(s1, s2);
	char *test = ft_strjoin(tmp, s3);
	char *expected = "my favorite animal is the nyancat";
	ASSERT_STRING_EQUALS(expected, test);
	free(tmp);
	free(test);
}

void test_ft_strjoin_simple_input3()
{
	char *s1 = "where is my ";
	char *s2 = "malloc ???";
	char *expected = "where is my malloc ???";
	char *test = ft_strjoin(s1, s2);
	ASSERT_STRING_EQUALS(expected, test);
	free(test);
}

void test_ft_strjoin_at_end_of_str()
{
	char *s1 = "my favorite animal is ";
	char *s2 = s1 + 20;
	char *test = ft_strjoin(s2, s1);
	char *expected = "s my favorite animal is ";
	ASSERT_STRING_EQUALS(expected, test);
	free(test);
}

void test_ft_strjoin_s1_NULL()
{
	char *s1 = "where is my ";
	char *test = ft_strjoin(NULL, s1);
	ASSERT_EQUALS(NULL, test);
	free(test);
}

void test_ft_strjoin_s2_NULL()
{
	char *s1 = "where is my ";
	char *test = ft_strjoin(s1, NULL);
	ASSERT_EQUALS(NULL, test);
	free(test);
}

void test_ft_strjoin(void)
{
	test_ft_strjoin_simple_input();
	test_ft_strjoin_simple_input2();
	test_ft_strjoin_simple_input3();
	test_ft_strjoin_at_end_of_str();
	test_ft_strjoin_s1_NULL();
	test_ft_strjoin_s2_NULL();

	success(__FUNCTION__);
}

void test_ft_memset(void)
{
	char str_1[26] = "This";
	char str_2[26] = "anot";
	ASSERT_STRING_EQUALS((char *)memset(str_1, '$', 7),
						 (char *)ft_memset(str_2, '$', 7));
	ASSERT_STRING_EQUALS((char *)memset(str_1, '$', 1),
						 (char *)ft_memset(str_2, '$', 1));

	success(__FUNCTION__);
}

void test_ft_bzero(void)
{
	char str_1[25] = "This is a test for bzero";
	char str_2[25] = "another a test for bzero";

	bzero(str_1, 0);
	ft_bzero(str_2, 0);
	ASSERT_EQUALS(1, strncmp_nul(str_1, str_2, 2));

	bzero(str_1, 1);
	ft_bzero(str_2, 1);
	ASSERT_EQUALS(0, strncmp_nul(str_1, str_2, 1));
	ASSERT_EQUALS(1, strncmp_nul(str_1, str_2, 2));

	bzero(str_1, 6);
	ft_bzero(str_2, 6);
	ASSERT_EQUALS(0, strncmp_nul(str_1, str_2, 6));
	ASSERT_EQUALS(1, strncmp_nul(str_1, str_2, 7));

	bzero(str_1, 20);
	ft_bzero(str_2, 20);
	ASSERT_EQUALS(0, strncmp_nul(str_1, str_2, 20));
	ASSERT_EQUALS(1, strncmp_nul(str_1, str_2, 21));

	success(__FUNCTION__);
}

void test_ft_memcpy(void)
{
	const char *str_1 = "test1";
	const char *str_2 = "another test, test_1";

	char buffer1[50];
	char buffer2[50];

	ft_memcpy(buffer1, str_1, 6);
	memcpy(buffer2, str_1, 6);
	ASSERT_STRING_EQUALS(buffer1, buffer2);

	ft_memcpy(buffer1 + 2, str_1, 0);
	memcpy(buffer2 + 2, str_1, 0);
	ASSERT_STRING_EQUALS(buffer1, buffer2);

	ft_memcpy(buffer1, str_2, 21);
	memcpy(buffer2, str_2, 21);
	ASSERT_STRING_EQUALS(buffer1, buffer2);

	ft_memcpy(buffer1 + 2, str_2, 0);
	memcpy(buffer2 + 2, str_2, 0);
	ASSERT_STRING_EQUALS(buffer1, buffer2);

	ft_memcpy(NULL, NULL, 3);

	success(__FUNCTION__);
}

void test_ft_memccpy(void)
{

	const char *str_1 = "test1 for memccpy";

	char buffer1[50] = "$$$$$$$$$ - memccpy after the change";

	ASSERT_STRING_EQUALS(" - memccpy after the change",
						 ft_memccpy(buffer1, str_1, 'r', 14));
	ASSERT_STRING_EQUALS("test1 for - memccpy after the change", buffer1);

	ASSERT_EQUALS(NULL, ft_memccpy(buffer1, str_1, 't', 0));
	ASSERT_EQUALS(NULL, ft_memccpy(buffer1, str_1, 'H', 17));
	ASSERT_EQUALS(NULL, ft_memccpy(buffer1, str_1, 'r', 5));

	success(__FUNCTION__);
}

void test_ft_memmove(void)
{
	char str[] = "memmove can be very useful......";
	char str2[] = "memmove can be very useful......";
	char str3[] = "memmove can be very useful......";
	char str4[] = "memmove can be very useful......";
	char dest_1[10];
	char dest_2[10];
	bzero(dest_1, 10);
	bzero(dest_2, 10);

	ASSERT_STRING_EQUALS(ft_memmove(str + 5, str + 21, 11),
						 memmove(str2 + 5, str2 + 21, 11));
	ASSERT_STRING_EQUALS(ft_memmove(str3 + 20, str + 15, 11),
						 memmove(str4 + 20, str2 + 15, 11));
	ASSERT_STRING_EQUALS(ft_memmove(dest_1, str4, 9), memmove(dest_2, str4, 9));

	success(__FUNCTION__);
}

void test_ft_memcmp(void)
{
	char buffer1[] = "DWGaOts12df0";
	char buffer2[] = "DWgaOtP12df0";

	ASSERT_EQUALS(memcmp(buffer1, buffer2, sizeof(buffer1)),
				  ft_memcmp(buffer1, buffer2, sizeof(buffer1)));

	char buffer3[] = "these ARe5almos5 identical";
	char buffer4[] = "these are almost identical";

	ASSERT_EQUALS(memcmp(buffer3, buffer4, sizeof(buffer3)),
				  ft_memcmp(buffer3, buffer4, sizeof(buffer3)));

	char buffer5[] = "jdehken";
	char buffer6[] = "enfksmd";
	ASSERT_EQUALS(memcmp(buffer5, buffer6, 0), ft_memcmp(buffer5, buffer6, 0));

	success(__FUNCTION__);
}

void test_ft_memchr(void)
{
	const char *str = "Example string";

	ASSERT_STRING_EQUALS((char *)memchr(str, 'p', strlen(str)),
						 (char *)ft_memchr(str, 'p', strlen(str)));

	const char *str1 = "Another example with NULL";
	ASSERT_EQUALS((char *)memchr(str1, 'p', 5),
				  (char *)ft_memchr(str1, 'p', 5));

	ASSERT_EQUALS((char *)memchr(str1, 'p', 0),
				  (char *)ft_memchr(str1, 'p', 0));

	ASSERT_EQUALS((char *)memchr(str1, 'p', 25),
				  (char *)ft_memchr(str1, 'p', 25));

	success(__FUNCTION__);
}

void test_ft_strchr(void)
{
	char str[] = "This is a s\0ample string";
	ASSERT_STRING_EQUALS(strchr(str, 's'), ft_strchr(str, 's'));
	ASSERT_EQUALS(strchr(str, 'f'), ft_strchr(str, 'f'));
	ASSERT_STRING_EQUALS(strchr(str, 'T'), ft_strchr(str, 'T'));
	ASSERT_STRING_EQUALS(strchr(str, '\0') + 1, ft_strchr(str, '\0') + 1);

	success(__FUNCTION__);
}

void test_ft_strrchr(void)
{
	const char *str = "This is another test to find the last s";
	const char *str2 = "This is another \0 with a null in the middle s";
	ASSERT_EQUALS(strrchr(str, '\0'), ft_strrchr(str, '\0'));
	ASSERT_EQUALS(strrchr(str, 's'), ft_strrchr(str, 's'));
	ASSERT_EQUALS(strrchr(str2, '\0'), ft_strrchr(str2, '\0'));
	ASSERT_EQUALS(strrchr(str2, 's'), ft_strrchr(str2, 's'));

	success(__FUNCTION__);
}

void test_ft_strnstr(void)
{
	const char *big_1 = "This is a test";
	const char *little_1 = "is";
	ASSERT_STRING_EQUALS("is is a test", ft_strnstr(big_1, little_1, 9));

	const char *big_2 = "just another test";
	const char *little_2 = "test";
	ASSERT_STRING_EQUALS("test", ft_strnstr(big_2, little_2, 20));
	ASSERT_EQUALS(NULL, ft_strnstr(big_2, little_2, 5));

	const char *big_3 = "testest tea test";
	const char *little_3 = "test";
	ASSERT_EQUALS(NULL, ft_strnstr(big_3, little_3, 3));

	success(__FUNCTION__);
}

void test_ft_substr_simple_at_end()
{
	char *str = "this is my string";
	size_t size = 9;
	char *test = (char *)ft_substr(str, 8, size);
	char *expected = "my string";

	ASSERT_STRING_EQUALS(expected, test);
	ASSERT_EQUALS(size, strlen(test));
	free(test);
}

void test_ft_substr_simple_at_beg()
{
	char *str = "i just want this part #############";
	size_t size = 22;
	char *test = (char *)ft_substr(str, 0, size);
	char *expected = "i just want this part ";

	ASSERT_STRING_EQUALS(expected, test);
	ASSERT_EQUALS(size, strlen(test));
	free(test);
}

void test_ft_substr_in_the_middle()
{
	char *str = "i just want this part #############";
	char *expected = "t want this part ###";
	size_t size = 20;
	char *test = ft_substr(str, 5, size);

	ASSERT_STRING_EQUALS(expected, test);
	ASSERT_EQUALS(size, strlen(test));
	free(test);
}

void test_ft_substr_size_0()
{
	char *str = "i just want this part #############";
	size_t size = 0;
	char *test = ft_substr(str, 5, 0);
	ASSERT_STRING_EQUALS("", test);
	ASSERT_EQUALS(size, strlen(test));
	free(test);
}

void test_ft_substr_empty_str_size_0()
{
	char *str = "";
	char *expected = "";
	size_t size = 0;
	char *test = ft_substr(str, 5, size);
	ASSERT_STRING_EQUALS(expected, test);
	ASSERT_EQUALS(size, strlen(test));
	free(test);
}

void test_ft_substr_len_smaller_then_end()
{
	char *str = "i just want this part #############";
	char *expected = "t want this part ###";
	size_t size = 20;
	char *test = ft_substr(str, 5, size);
	ASSERT_STRING_EQUALS(expected, test);
	ASSERT_EQUALS(size, strlen(test));
	free(test);
}

void test_ft_substr_len_str_len()
{
	char *str = "all of this !";
	char *expected = "all of this !";
	size_t size = strlen(str);
	char *test = ft_substr(str, 0, size);
	ASSERT_STRING_EQUALS(expected, test);
	ASSERT_EQUALS(size, strlen(test));
	free(test);
}

void test_ft_substr_start_bigger_str_len_with_empty()
{

	char *str = "abcd";
	char *expected = "";
	size_t size = 20;
	char *test = ft_substr(str, 20, size);
	ASSERT_STRING_EQUALS(expected, test);
	free(test);
}

void test_ft_substr_start_bigger_str_len_with_str()
{
	char *str = "abcd";
	char *expected = "abcd";
	size_t size = 20;
	char *test = ft_substr(str, 0, size);
	ASSERT_STRING_EQUALS(expected, test);
	ASSERT_EQUALS(strlen(str), strlen(test));
	free(test);
}

void test_ft_substr(void)
{
	test_ft_substr_simple_at_end();
	test_ft_substr_simple_at_beg();
	test_ft_substr_in_the_middle();
	test_ft_substr_size_0();
	test_ft_substr_empty_str_size_0();
	test_ft_substr_len_str_len();
	test_ft_substr_len_smaller_then_end();
	test_ft_substr_start_bigger_str_len_with_empty();
	test_ft_substr_start_bigger_str_len_with_str();

	success(__FUNCTION__);
}

void test_ft_strtrim()
{
	char *str;
	char *expected;
	char *test;
	char *to_trim = " \n\t";

	str = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n "
		  "\t\t\n  ";
	expected = "Hello \t  Please\n Trim me !";

	test = ft_strtrim(str, to_trim);
	ASSERT_STRING_EQUALS(expected, test);
	ASSERT_EQUALS(strlen(test), strlen(expected));
	free(test);

	str = "  \t \t \n   \n\n\n\t \t\t\n  ";
	expected = "";
	test = ft_strtrim(str, to_trim);
	ASSERT_STRING_EQUALS(expected, test);
	ASSERT_EQUALS(strlen(test), strlen(expected));
	free(test);

	str = "\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  "
		  "\t\t\t\t  ";
	expected = "Hello \t  Please\n Trim me !";
	test = ft_strtrim(str, to_trim);
	ASSERT_STRING_EQUALS(expected, test);
	free(test);

	str = "\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  "
		  "\t\t\t\t  ";
	expected = "Hello \t  Please\n Trim me !";
	test = ft_strtrim(str, to_trim);
	ASSERT_STRING_EQUALS(expected, test);
	free(test);

	str = "\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  "
		  "\t\t\t\t  ";
	expected = "Hello \t  Please\n Trim me !";
	test = ft_strtrim(str, to_trim);
	ASSERT_STRING_EQUALS(expected, test);
	free(test);

	success(__FUNCTION__);
}

void test_ft_itoa_with_0()
{
	int number = 0;
	char *expected = "0";
	char *test = ft_itoa(number);
	ASSERT_STRING_EQUALS(expected, test);
	ASSERT_EQUALS(strlen(test), strlen(expected));
	free(test);
}
void test_ft_itoa_with_negative()
{
	int number = -42;
	char *expected = "-42";
	char *test = ft_itoa(number);
	ASSERT_STRING_EQUALS(expected, test);
	ASSERT_EQUALS(strlen(test), strlen(expected));
	free(test);
}
void test_ft_itoa_with_int_min()
{
	int number = INT_MIN;
	char *expected = "-2147483648";
	char *test = ft_itoa(number);
	ASSERT_STRING_EQUALS(expected, test);
	ASSERT_EQUALS(strlen(test), strlen(expected));
	free(test);
}
void test_ft_itoa_with_int_max()
{
	int number = INT_MAX;
	char *expected = "2147483647";
	char *test = ft_itoa(number);
	ASSERT_STRING_EQUALS(expected, test);
	ASSERT_EQUALS(strlen(test), strlen(expected));
	free(test);
}
void test_ft_itoa_with_negative_3_dig()
{
	int number = -623;
	char *expected = "-623";
	char *test = ft_itoa(number);
	ASSERT_STRING_EQUALS(expected, test);
	ASSERT_EQUALS(strlen(test), strlen(expected));
	free(test);
}

void test_ft_itoa_simple()
{
	int number = 156;
	char *expected = "156";
	char *test = ft_itoa(number);
	ASSERT_STRING_EQUALS(expected, test);
	ASSERT_EQUALS(strlen(test), strlen(expected));
	free(test);
}
void test_ft_itoa_with_minus_0()
{
	int number = -0;
	char *expected = "0";
	char *test = ft_itoa(number);
	ASSERT_STRING_EQUALS(expected, test);
	ASSERT_EQUALS(strlen(test), strlen(expected));
	free(test);
}

void test_ft_itoa()
{
	test_ft_itoa_with_0();
	test_ft_itoa_with_negative();
	test_ft_itoa_with_int_min();
	test_ft_itoa_with_int_max();
	test_ft_itoa_with_negative_3_dig();
	test_ft_itoa_simple();
	test_ft_itoa_with_minus_0();

	success(__FUNCTION__);
}

void test_ft_split_simple_str()
{
	const char *str = "hello, please split me, in three";
	char **result = ft_split(str, ',');
	char **expected =
		((char *[4]){"hello", " please split me", " in three", NULL});
	for (int i = 0; result[i] != NULL; i++)
		ASSERT_STRING_EQUALS(result[i], expected[i]);
	for (int i = 0; result[i] != NULL; i++)
		free(result[i]);
	free(result);
}

void test_ft_split_multiple_delimeters()
{
	char *str = "      split       this for   me  !       ";
	char **expected = ((char *[6]){"split", "this", "for", "me", "!", NULL});
	char **result = ft_split(str, ' ');

	for (int i = 0; result[i] != NULL; i++)
		ASSERT_STRING_EQUALS(result[i], expected[i]);

	for (int i = 0; result[i] != NULL; i++)
		free(result[i]);
	free(result);
}

void test_ft_split_delimeters_in_the_beg()
{
	char *str = "                  olol";
	char **expected = ((char *[2]){"olol", NULL});
	char **result = ft_split(str, ' ');

	for (int i = 0; result[i] != NULL; i++)
		ASSERT_STRING_EQUALS(result[i], expected[i]);

	for (int i = 0; result[i] != NULL; i++)
		free(result[i]);
	free(result);
}

void test_ft_split_delimeters_in_the_end()
{
	char *str = "olol                  ";
	char **expected = ((char *[2]){"olol", NULL});
	char **result = ft_split(str, ' ');

	for (int i = 0; result[i] != NULL; i++)
		ASSERT_STRING_EQUALS(result[i], expected[i]);

	for (int i = 0; result[i] != NULL; i++)
		free(result[i]);
	free(result);
}

void test_ft_split_null_ptr()
{
	char **result = ft_split(NULL, ' ');
	ASSERT_EQUALS(NULL, result);
	free(result);
}

void test_ft_split_empty()
{
	// char **result = ft_split("", 'b');
	// // printf("|%s|\n",result[0]);
	// // ASSERT_EQUALS("", result);
	// // free(result[0]);
	// free(result);
}

void test_ft_split_simple_input()
{
	char *str = "0 0 0 0 0 0 0 0 0";
	char **expected =
		((char *[10]){"0", "0", "0", "0", "0", "0", "0", "0", "0", NULL});
	char **result = ft_split(str, ' ');

	for (int i = 0; i < 9; i++)
		ASSERT_STRING_EQUALS(result[i], expected[i]);

	for (int i = 0; i < 9; i++)
		free(result[i]);
	free(result);
}

void test_ft_split_only_delimeters()
{
	char *str = "                ";
	char **expected = ((char *[1]){NULL});
	char **result = ft_split(str, ' ');
	ASSERT_EQUALS(result[0], expected[0]);
	free(result);
}

void test_ft_split_huge_str()
{
	int size = 10000000 * sizeof(char);
	char *str1 = malloc(size + 1);

	if (str1 == NULL)
		return;
	for (int i = 0; i < size; i += 2)
	{
		str1[i] = 'a';
		str1[i + 1] = ' ';
	}
	str1[size] = '\0';

	char **result = ft_split(str1, ' ');

	int index = 0;
	while (result[index] != NULL)
	{
		index++;
	}
	ASSERT_EQUALS(index, size / 2);
	index = 0;
	while (result[index] != NULL)
	{
		ASSERT_STRING_EQUALS(result[index], "a");
		free(result[index]);
		index++;
	}
	free(str1);
	free(result);
}

void test_ft_split()
{
	test_ft_split_simple_str();
	test_ft_split_simple_input();
	test_ft_split_multiple_delimeters();
	test_ft_split_delimeters_in_the_beg();
	test_ft_split_delimeters_in_the_end();
	test_ft_split_null_ptr();
	test_ft_split_only_delimeters();
	test_ft_split_huge_str();
	test_ft_split_empty();

	success(__FUNCTION__);
}

void test_ft_lstnew()
{
	t_list *l;
	l = ft_lstnew(NULL);
	ASSERT_EQUALS(NULL, l->content);
	free(l);

	char *data = "hello, i'm a data";
	l = ft_lstnew(data);
	ASSERT_STRING_EQUALS(data, l->content);
	free(l);

	int x = 3;
	l = ft_lstnew(&x);
	ASSERT_EQUALS(x, *((int *)l->content));
	free(l);

	success(__FUNCTION__);
}

void test_ft_lstadd_front()
{
	t_list *head;
	char *dataFirst = "data first element";
	char *dataSecond = "data second element";
	char *dataThird = "data third element";
	char *datas[4] = {dataThird, dataSecond, dataFirst};

	t_list *first = ft_lstnew(dataFirst);
	t_list *second = ft_lstnew(dataSecond);
	t_list *third = ft_lstnew(dataThird);

	head = first;

	ft_lstadd_front(&head, second);
	ft_lstadd_front(&head, third);

	t_list *current;
	current = head;
	int i = 0;
	while (current->next != NULL)
	{

		ASSERT_STRING_EQUALS(datas[i], (char *)current->content);
		current = current->next;
		++i;
	}
	ASSERT_EQUALS(NULL, current->next);

	ASSERT_STRING_EQUALS(dataFirst, (char *)(ft_lstlast(head))->content);
	ASSERT_EQUALS(NULL, (ft_lstlast(head))->next);

	free(first);
	free(second);
	free(third);

	success(__FUNCTION__);
}

void test_ft_lstadd_back_random()
{

	t_list *lst1 = ft_lstnew(NULL);
	t_list *lst2 = ft_lstnew("9saIFRqNlBR9RZfHSTYr1FjVO9gWm6Ly73qFccG8Wms1OrYprBDKBqu");
	t_list *lst3 = ft_lstnew("");
	t_list *lst4 = ft_lstnew("");

	ft_lstadd_back(&lst1, lst2);
	ft_lstadd_back(&lst1, NULL);
	ft_lstadd_back(&lst1, lst3);
	ft_lstadd_back(&lst1, lst4);

	ASSERT_EQUALS(4, ft_lstsize(lst1));

	free(lst1);
	free(lst2);
	free(lst3);
	free(lst4);

	lst1 = ft_lstnew("");
	ft_lstadd_back(&lst1, NULL);
	ft_lstadd_back(&lst1, NULL);
	ft_lstadd_back(&lst1, NULL);
	ft_lstadd_back(&lst1, NULL);

	ASSERT_EQUALS(1, ft_lstsize(lst1));

	free(lst1);

	lst1 = NULL;
	lst2 = ft_lstnew("dFufEUiAPXsEBPV4VgKBkYiSJtAm8QkCGwVlM9Mp8VFF5qJNXPb4LclTNSj3BbkNQajENtP0xhi89xCZQBOMYzV");
	ft_lstadd_back(&lst1, NULL);
	ft_lstadd_back(&lst1, NULL);
	ft_lstadd_back(&lst1, lst2);

	ASSERT_EQUALS(1, ft_lstsize(lst1));

	free(lst1);
}

void test_ft_lstadd_back()
{
	t_list **head;
	char *dataFirst = "data first element";
	char *dataSecond = "data second element";
	char *dataThird = "data third element";
	char *datas[4] = {dataFirst, dataSecond, dataThird};

	t_list *first = ft_lstnew(dataFirst);
	t_list *second = ft_lstnew(dataSecond);
	t_list *third = ft_lstnew(dataThird);

	head = &first;

	ft_lstadd_back(head, second);
	ft_lstadd_back(head, third);

	t_list *current;
	current = *head;
	int i = 0;
	while (current->next != NULL)
	{
		ASSERT_STRING_EQUALS(datas[i], (char *)current->content);
		current = current->next;
		++i;
	}
	ASSERT_EQUALS(NULL, current->next);

	ASSERT_STRING_EQUALS(dataThird, (char *)(ft_lstlast(*head))->content);

	free(first);
	free(second);
	free(third);

	test_ft_lstadd_back_random();

	success(__FUNCTION__);
}

void test_ft_lstsize()
{
	char *dataFirst = "data first element";
	char *dataSecond = "data second element";
	char *dataThird = "data third element";

	t_list *first = ft_lstnew(dataFirst);
	t_list *second = ft_lstnew(dataSecond);
	t_list *third = ft_lstnew(dataThird);

	t_list *head = NULL;
	ASSERT_EQUALS(0, ft_lstsize(head));

	head = first;
	ASSERT_EQUALS(1, ft_lstsize(head));

	ft_lstadd_front(&head, second);
	ASSERT_EQUALS(2, ft_lstsize(head));

	ft_lstadd_front(&head, third);
	ASSERT_EQUALS(3, ft_lstsize(head));

	ASSERT_STRING_EQUALS(dataFirst, (char *)first->content);

	free(first);
	free(second);
	free(third);

	success(__FUNCTION__);
}

void test_ft_lstlast()
{
	char *dataFirst = "data first element";
	char *dataSecond = "data second element";
	char *dataThird = "data third element";

	t_list *first = ft_lstnew(dataFirst);
	t_list *second = ft_lstnew(dataSecond);
	t_list *third = ft_lstnew(dataThird);

	t_list *head = first;
	ft_lstadd_front(&head, second);
	ft_lstadd_front(&head, third);

	ASSERT_STRING_EQUALS(dataFirst, (char *)first->content);
	ASSERT_STRING_EQUALS(dataSecond, (char *)second->content);
	ASSERT_STRING_EQUALS(dataThird, (char *)third->content);

	free(first);
	free(second);
	free(third);

	success(__FUNCTION__);
}

int main(void)
{
	RUN(test_ft_isalpha);
	RUN(test_ft_isdigit);
	RUN(test_ft_isalnum);
	RUN(test_ft_isascii);
	RUN(test_ft_isprint);
	RUN(test_ft_toupper);
	RUN(test_ft_tolower);
	RUN(test_ft_strlen);
	RUN(test_ft_atoi);
	RUN(test_ft_strncmp);
	RUN(test_ft_strlcat);
	RUN(test_ft_strlcpy);
	RUN(test_ft_strdup);
	RUN(test_ft_strjoin);
	RUN(test_ft_memset);
	RUN(test_ft_bzero);
	RUN(test_ft_memcpy);
	RUN(test_ft_memccpy);
	RUN(test_ft_memmove);
	RUN(test_ft_memcmp);
	RUN(test_ft_memchr);
	RUN(test_ft_strchr);
	RUN(test_ft_strrchr);
	RUN(test_ft_strnstr);
	RUN(test_ft_substr);
	RUN(test_ft_strtrim);
	RUN(test_ft_itoa);
	RUN(test_ft_split);
	RUN(test_ft_lstnew);
	RUN(test_ft_lstlast);
	RUN(test_ft_lstsize);
	RUN(test_ft_lstadd_back);
	RUN(test_ft_lstadd_front);
	return (TEST_REPORT());
}
