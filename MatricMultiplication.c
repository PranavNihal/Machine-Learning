#include <stdio.h>
void multiplication(int rows1, int cols1, int rows2, int cols2, int arr1[], int arr2[], int result[])
{
    if (cols1 != rows2)
    {
        // Matrix multiplicationn is rendered invalid in the case this conditions is not satisfied.
        return;
    }
    {
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < cols2; j++)
            {
                int index_res = (i * cols2) + j;
                result[index_res] = 0;
                // We can use rows2 instead of cols1 also because they are supposed to be equal
                for (int k = 0; k < cols1; k++)
                {
                    int index1 = (i * cols1) + k;
                    int index2 = (k * cols2) + j;
                    result[index_res] += arr1[index1] * arr2[index2];
                }
            }
        }
    }
}
