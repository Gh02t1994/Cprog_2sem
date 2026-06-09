#include <stdio.h>
#include "testing.h"

/**
 * @brief tests my_strpbrk function against standard strpbrk
 * 
 * @return int
 * count_fail - number of failed tests
 */
int test_strpbrk(void)
{
    int count_fail = ZERO;

    if (strpbrk("hello", "oe") != my_strpbrk("hello", "oe"))
    {
        count_fail++;
    }

    if (strpbrk("HELLO", "oe") != my_strpbrk("HELLO", "oe"))
    {
        count_fail++;
    }

    if (strpbrk("hello", "OE") != my_strpbrk("hello", "OE"))
    {
        count_fail++;
    }

    if (strpbrk("hello", "d") != my_strpbrk("hello", "d"))
    {
        count_fail++;
    }
    
    if (strpbrk("hello", "dpi") != my_strpbrk("hello", "dpi"))
    {
        count_fail++;
    }

    if (strpbrk("hello", "h") != my_strpbrk("hello", "h"))
    {
        count_fail++;
    }

    if (strpbrk("hello", "o") != my_strpbrk("hello", "o"))
    {
        count_fail++;
    }

    if (strpbrk("hello", "l") != my_strpbrk("hello", "l"))
    {
        count_fail++;
    }

    return count_fail;
}

/**
 * @brief tests my_strspn function against standard strspn
 * 
 * @return int
 * count_fail - number of failed tests
 */
int test_strspn(void)
{
    int count_fail = ZERO;

    if (strspn("abc123", "1") != my_strspn("abc123", "1"))
    {
        count_fail++;
    }

    if (strspn("abc123", "321") != my_strspn("abc123", "321"))
    {
        count_fail++;
    }

    if (strspn("abc123", "321123") != my_strspn("abc123", "321123"))
    {
        count_fail++;
    }

    if (strspn("abc123abc", "abc") != my_strspn("abc123abc", "abc"))
    {
        count_fail++;
    }

    if (strspn("abc123abc", "abcabc") != my_strspn("abc123abc", "abcabc"))
    {
        count_fail++;
    }

    if (strspn("abc123abc", "a1b2c3") != my_strspn("abc123abc", "a1b2c3"))
    {
        count_fail++;
    }

    if (strspn("abc123", "45") != my_strspn("abc123", "45"))
    {
        count_fail++;
    }

    return count_fail;
}

/**
 * @brief tests my_strcspn function against standard strcspn
 * 
 * @return int
 * count_fail - number of failed tests
 */
int test_strcspn(void)
{
    int count_fail = ZERO;

    if (strcspn("abc123", "12345") != my_strcspn("abc123", "12345"))
    {
        count_fail++;
    }

    if (strcspn("abc123", "abcd") != my_strcspn("abc123", "abcd"))
    {
        count_fail++;
    }

    if (strcspn("abc123", "d") != my_strcspn("abc123", "d"))
    {
        count_fail++;
    }

    if (strcspn("abc123abc", "a") != my_strcspn("abc123", "a"))
    {
        count_fail++;
    }

    if (strcspn("abc123", "aaa") != my_strcspn("abc123", "aaa"))
    {
        count_fail++;
    }

    return count_fail;
}

/**
 * @brief tests my_strchr function against standard strchr
 * 
 * @return int
 * count_fail - number of failed tests
 */
int test_strchr(void)
{
    int count_fail = ZERO;

    if (strchr("abc123", 'b') != my_strchr("abc123", 'b'))
    {
        count_fail++;
    }

    if (strchr("abc123", 'd') != my_strchr("abc123", 'd'))
    {
        count_fail++;
    }

    if (strchr("helllo", 'l') != my_strchr("helllo", 'l'))
    {
        count_fail++;
    }
    
    if (strchr("abc cba", 'b') != my_strchr("abc cba", 'b'))
    {
        count_fail++;
    }

    return count_fail;
}

/**
 * @brief tests my_strrchr function against standard strrchr
 * 
 * @return int
 * count_fail - number of failed tests
 */
int test_strrchr(void)
{
    int count_fail = ZERO;

    if (strrchr("abc123", 'b') != my_strrchr("abc123", 'b'))
    {
        count_fail++;
    }

    if (strrchr("abc123", 'd') != my_strrchr("abc123", 'd'))
    {
        count_fail++;
    }

    if (strrchr("helllo", 'l') != my_strrchr("helllo", 'l'))
    {
        count_fail++;
    }
    
    if (strrchr("abc cba", 'b') != my_strrchr("abc cba", 'b'))
    {
        count_fail++;
    }

    return count_fail;
}
