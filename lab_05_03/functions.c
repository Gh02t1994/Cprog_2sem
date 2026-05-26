/**
 * Выбранный целочисленный тип - int
 * Алогритм сортировки - сортировка выбором
 * «Направление» упорядочивания - по возрастанию
 */

#include "functions.h"

/**
 * @brief generates a random integer in the range [-100; 100]
 * 
 * @return int
 * random integer between -100 and 100
 */
int randint(void)
{
    return rand() % 201 - 100;
}

/**
 * @brief counts the number of integers stored in a binary file
 * 
 * @param f - file
 * 
 * @return size_t
 * count - number of integers in the file
 */
size_t take_count(FILE *f)
{
    size_t count = ZERO;
    int numb;

    while (fread(&numb, SIZE, 1, f) == 1)
    {
        count++;
    }

    rewind(f);
    return count;
}

/**
 * @brief fills a binary file with random integers in the range [-100; 100]
 * 
 * @param f - file
 * @param count - number of random integers to generate
 * 
 * @return void
 */
void make_new_file(FILE *f, size_t count)
{
    srand(clock());
    int numb;

    for (size_t i = ZERO; i < count; i++)
    {
        numb = randint();
        fwrite(&numb, SIZE, 1, f);
    }
}

/**
 * @brief prints all integers from a binary file to stdout
 * 
 * @param f - file
 * 
 * @return int
 * EMPTY_FILE - empty file return code
 * SUCCESS - success return code
 */
int print_file(FILE *f)
{
    size_t count = take_count(f);
    int have_prev = FALSE;
    int numb;
    int prev;
    if (count == ZERO)
        return EMPTY_FILE;

    while (fread(&numb, SIZE, 1, f) == 1)
    {
        if (have_prev)
            printf("%d ", prev);
        prev = numb;
        have_prev = TRUE;
    }

    if (have_prev)
        printf("%d", prev);
    return SUCCESS;
}
/**
 * @brief reads an integer from a binary file by its position
 * 
 * @param f - file
 * @param pos - zero-based index of the element in the file
 * @param number - pointer to store the read integer
 * 
 * @return int
 * SUCCESS - if the number was successfully read
 * WRONG_POSITION - if seek to the requested position failed
 * READ_ERROR - if reading from file failed
 */
int get_number_by_pos(FILE *f, size_t pos, int *number)
{
    if (fseek(f, pos * SIZE, SEEK_SET) != 0)
        return WRONG_POSITION;

    if (fread(number, SIZE, 1, f) != 1)
        return READ_ERROR;

    return SUCCESS;
}

/**
 * @brief writes an integer to a binary file at a given position
 * 
 * @param f - file
 * @param pos - zero-based index of the element in the file
 * @param number - integer value to write
 * 
 * @return int
 * SUCCESS - if the number was successfully written
 * WRONG_POSITION - if seek to the requested position failed
 * WRITE_ERROR - if writing to file failed
 */
int put_number_by_pos(FILE *f, size_t pos, int number)
{
    if (fseek(f, pos * SIZE, SEEK_SET) != 0)
        return WRONG_POSITION;

    if (fwrite(&number, SIZE, 1, f) != 1)
        return WRITE_ERROR;

    return SUCCESS;
}

/**
 * @brief sorts integers in a binary file in ascending order using selection sort
 * 
 * @param f - file
 * 
 * @return int
 * EMPTY_FILE - empty file return code
 * SUCCESS - success return code
 */
int sort_file(FILE *f)
{
    size_t count = take_count(f);
    size_t min_index;
    int min_numb, cur_numb;
    if (count == ZERO)
        return EMPTY_FILE;

    for (size_t i = ZERO; i < count; i++)
    {
        min_index = i;
        for (size_t j = i + 1; j < count; j++)
        {
            get_number_by_pos(f, min_index, &min_numb);
            get_number_by_pos(f, j, &cur_numb);

            if (cur_numb < min_numb)
                min_index = j;
        }

        if (min_index != i)
        {
            get_number_by_pos(f, min_index, &min_numb);
            get_number_by_pos(f, i, &cur_numb);

            put_number_by_pos(f, min_index, cur_numb);
            put_number_by_pos(f, i, min_numb);
        }
    }
    return SUCCESS;
}

/**
 * @brief checks if a string represents a non-negative integer value
 * 
 * @param str - input string to check
 * @param number - pointer to store converted non-negative integer value
 * 
 * @return int
 * SUCCESS - if string is a valid non-negative integer
 * NOT_NUMBER - if string is not a valid non-negative integer
 */
int check_is_num(char str[], size_t *number)
{
    char *endptr = NULL;
    int tmp = strtoul(str, &endptr, DECIMAL);

    if (*endptr != '\0' || tmp <= ZERO)
        return NOT_NUMBER;

    *number = (size_t)tmp;
    return SUCCESS;
}

/**
 * @brief checks if a file with given name exists and can be opened for reading
 * 
 * @param str - name of the file to check
 * 
 * @return int
 * SUCCESS - if file exists and was opened successfully
 * FILE_NOT_EXIST - if file cannot be opened
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
 * @brief converts a text file with integers to a binary file
 * 
 * @param txt_name - name of source text file
 * @param bin_name - name of destination binary file
 * 
 * @return void
 */
void txt_to_bin(char txt_name[], char bin_name[])
{
    FILE *f_t = fopen(txt_name, "r");
    FILE *f_b = fopen(bin_name, "wb");
    int num;

    while (fscanf(f_t, "%d", &num) == 1)
    {
        fwrite(&num, SIZE, 1, f_b);
    }

    fclose(f_t);
    fclose(f_b);
}

/**
 * @brief converts a binary file with integers to a text file
 * 
 * @param bin_name - name of source binary file
 * @param txt_name - name of destination text file
 * 
 * @return void
 */
void bin_to_txt(char bin_name[], char txt_name[])
{
    FILE *f_b = fopen(bin_name, "rb");
    FILE *f_t = fopen(txt_name, "w");
    int have_prev = FALSE;
    int numb;
    int prev;

    while (fread(&numb, SIZE, 1, f_b) == 1)
    {
        if (have_prev)
            fprintf(f_t, "%d ", prev);
        prev = numb;
        have_prev = TRUE;
    }

    if (have_prev)
        fprintf(f_t, "%d", prev);
}
