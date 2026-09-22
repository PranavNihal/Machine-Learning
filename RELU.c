#include <stdio.h>
int *RELU(const int *array, int cols, int rows)
{
    if (array == NULL || rows <= 0 || cols <= 0)
    {
        return NULL;
    }
    int *applied = create_matrix(rows, cols);
    if (applied == NULL)
    {
        return NULL;
    }
    int size = rows * cols;
    for (int i = 0; i < size; i++)
    {
        if (array[i] <= 0)
        {
            applied[i] = 0;
        }
        else
        {
            applied[i] = array[i];
        }
    }
    return applied;
}