#include "functions.h"

/**
 * @brief removes trailing newline from string
 *
 * @param str - target string
 *
 * @return void
 */
void del_trans(char str[])
{
    size_t len = strlen(str);

    if (len > ZERO && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

/**
 * @brief checks if file can be opened for reading
 *
 * @param str - file name
 *
 * @return int
 * FILE_NOT_EXIST - file open error
 * SUCCESS - file exists
 */
int check_file(char str[])
{
    FILE *f = fopen(str, "r");

    if (f == NULL)
        return FILE_NOT_EXIST;
    
    fclose(f);
    return SUCCESS;
}

/**
 * @brief reads one product from file
 *
 * @param p - product pointer
 * @param f - input file
 *
 * @return int
 * INCORRECT_INPUT - read or parse error
 * SUCCESS - product read
 */
int read_product(Product *p, FILE *f)
{
    char buf[SIZE_BUFFER];

    if (!fgets(p->name, MAX_NAME, f))
        return INCORRECT_INPUT;
    del_trans(p->name);

    if (!fgets(p->maker, MAX_MAKER, f))
        return INCORRECT_INPUT;
    del_trans(p->maker);

    if (!fgets(buf, SIZE_BUFFER, f))
        return INCORRECT_INPUT;
    del_trans(buf);
    if (sscanf(buf, "%u", &p->price) != 1)
        return INCORRECT_INPUT;

    if (!fgets(buf, SIZE_BUFFER, f))
        return INCORRECT_INPUT;
    del_trans(buf);
    if (sscanf(buf, "%u", &p->count) != 1)
        return INCORRECT_INPUT;
    
    return SUCCESS;
}

/**
 * @brief reads all products from file into array
 *
 * @param p - products array
 * @param f - input file
 *
 * @return size_t
 * i - products count
 */
size_t take_array_products(Product p[], FILE *f)
{
    int rc = SUCCESS;
    size_t i = ZERO;

    while (rc == SUCCESS)
    {
        rc = read_product(&p[i], f);

        if (rc != SUCCESS)
            break;  
        
        i++;
    }

    rewind(f);
    return i;
}

/**
 * @brief writes products array to file
 *
 * @param p - products array
 * @param count - products count
 * @param f - output file
 *
 * @return void
 */
void file_printf(Product p[], size_t count, FILE *f)
{
    for (size_t i = ZERO; i < count; i++)
    {
        fprintf(f, "%s\n", p[i].name);
        fprintf(f, "%s\n", p[i].maker);
        fprintf(f, "%u\n", p[i].price);
        fprintf(f, "%u\n", p[i].count);
    }
}

/**
 * @brief sorts products from file by price and count
 *
 * @param f_src - source file
 * @param f_dst - destination file
 *
 * @return int
 * INCORRECT_INPUT - no products
 * SUCCESS - sort done
 */
int sort_arr_prod(FILE *f_src, FILE *f_dst)
{
    Product temp, p[MAX_PRODUCTS];
    size_t count = take_array_products(p, f_src);

    if (count == ZERO)
        return INCORRECT_INPUT;

    for (size_t i = ZERO; i < count; i++)
        for (size_t j = i + 1; j < count; j++)
        {
            if (p[i].price < p[j].price || (p[i].price == p[j].price && p[i].count < p[j].count))
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }

    file_printf(p, count, f_dst);
    return SUCCESS;
}

/**
 * @brief checks if substr is suffix of string
 *
 * @param str - source string
 * @param substr - substring
 *
 * @return int
 * FALSE - not suffix
 * TRUE - is suffix
 */
int is_substr(char str[], char substr[])
{
    size_t len_str = strlen(str);
    size_t len_sub = strlen(substr);

    if (len_sub > len_str)
        return FALSE;

    return strcmp(str + (len_str - len_sub), substr) == 0;
}

/**
 * @brief prints products whose name ends with given substring
 *
 * @param substr - target suffix
 * @param f - input file
 *
 * @return int
 * INCORRECT_INPUT - no products
 * SUCCESS - printed
 */
int print_if_substr(char substr[], FILE *f)
{
    Product p[MAX_PRODUCTS];
    size_t count = take_array_products(p, f);

    if (count == ZERO)
        return INCORRECT_INPUT;

    for (size_t i = ZERO; i < count; i++)
    {
        if (is_substr(p[i].name, substr))
        {
            printf("%s\n", p[i].name);
            printf("%s\n", p[i].maker);
            printf("%u\n", p[i].price);
            printf("%u\n", p[i].count);
        }
    }

    return SUCCESS;
}

/**
 * @brief reads new product from stdin
 *
 * @param p - product pointer
 *
 * @return int
 * INCORRECT_INPUT - wrong format
 * SUCCESS - product read
 */
int input_new_prod(Product *p)
{
    char temp[MAX_NAME];

    if (fgets(temp, MAX_NAME, stdin) == NULL)
        return INCORRECT_INPUT;
    del_trans(temp);
    strcpy(p->name, temp);

    if (fgets(temp, MAX_NAME, stdin) == NULL)
        return INCORRECT_INPUT;
    del_trans(temp);
    strcpy(p->maker, temp);

    if (!fgets(temp, SIZE_BUFFER, stdin))
        return INCORRECT_INPUT;
    del_trans(temp);
    if (sscanf(temp, "%u", &p->price) != 1)
        return INCORRECT_INPUT;

    if (!fgets(temp, SIZE_BUFFER, stdin))
        return INCORRECT_INPUT;
    del_trans(temp);
    if (sscanf(temp, "%u", &p->count) != 1)
        return INCORRECT_INPUT;

    return SUCCESS;
}

/**
 * @brief shifts products array to the right from position
 *
 * @param p - products array
 * @param count - current size
 * @param pos - insert position
 *
 * @return void
 */
void shift_arr(Product p[], size_t count, size_t pos)
{
    for (size_t i = count; i > pos; i--)
    {
        p[i] = p[i - 1];
    }
}

/**
 * @brief inserts new product into sorted array in file
 *
 * @param f - file with products
 *
 * @return int
 * INCORRECT_INPUT - no products
 * MANY_PRODUCTS_ERROR - array overflow
 * SUCCESS - product added
 */
int add_new_pr_in_arr(FILE *f)
{
    Product p_new, p[MAX_PRODUCTS];
    size_t count = take_array_products(p, f);
    size_t pos = count;
    int rc;

    if (count == ZERO)
        return INCORRECT_INPUT;
    if (count == MAX_PRODUCTS)
        return MANY_PRODUCTS_ERROR;
    
    rc = input_new_prod(&p_new);
    if (rc != SUCCESS)
        return rc;

    for (size_t i = ZERO; i < count; i++)
        if (p_new.price > p[i].price || (p_new.price == p[i].price && p_new.count > p[i].count))
        {
            pos = i;
            break;
        }
    
    shift_arr(p, count, pos);
    p[pos] = p_new;
    count++;

    file_printf(p, count, f);
    return SUCCESS;
}

/**
 * @brief handles 4-argument command line mode
 *
 * @param argv - arguments array
 *
 * @return int
 * FILE_NOT_EXIST - source file error
 * SUCCESS - command processed
 * WRONG_ARGV - unknown command
 * rc - error code from worker
 */
int argc_4(char **argv)
{
    int rc;
    if (strcmp(argv[1], "st") == ZERO)
    {
        if (check_file(argv[2]) != SUCCESS)
            return FILE_NOT_EXIST;
        FILE *f_1 = fopen(argv[2], "r");
        FILE *f_2 = fopen(argv[3], "wb");
        
        rc = sort_arr_prod(f_1, f_2);
        fclose(f_1);
        fclose(f_2);

        if (rc != SUCCESS)
            return rc;
    }
    else if (strcmp(argv[1], "ft") == ZERO)
    {
        if (check_file(argv[2]) != SUCCESS)
            return FILE_NOT_EXIST;

        FILE *f = fopen(argv[2], "r");
        rc = print_if_substr(argv[3], f);
        fclose(f);
        if (rc != SUCCESS)
            return rc;
    }

    return WRONG_ARGV;
}

/**
 * @brief handles 3-argument command line mode
 *
 * @param argv - arguments array
 *
 * @return int
 * FILE_NOT_EXIST - source file error
 * MANY_PRODUCTS_ERROR - overflow on insert
 * SUCCESS - product added
 * WRONG_ARGV - unknown command
 * rc - error code from worker
 */
int argc_3(char **argv)
{
    int rc;

    if (strcmp(argv[1], "at") == ZERO)
    {
        if (check_file(argv[2]) != SUCCESS)
            return FILE_NOT_EXIST;

        FILE *f = fopen(argv[2], "rb+");

        rc = add_new_pr_in_arr(f);

        if (rc != SUCCESS)
        {
            fclose(f);
            return rc;
        }
        
    }
    return WRONG_ARGV;
}
