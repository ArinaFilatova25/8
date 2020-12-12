#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int sravn=0, perest = 0;

void quicksort(int *arr,int first,int last)
{
    int t;
    if (first>=last)
        return;
    int p_ind = first + abs(last-first) / 2;
    int piv = arr[p_ind];
    printf("Опорный элемент: %d\n", piv);

    int i = first, j = last;

    do
    {
        while (i != p_ind && arr[i] < piv)
        {
            if (i < j)
                sravn++;
            i++;

        }
        if (i != p_ind && i < j)

            sravn++;


        while (j != p_ind && arr[j] > piv)
        {
            if (i < j)
                sravn++;

            j--;

        }
        if (j != p_ind && i < j)
            sravn++;

        if (i <= j)
        {
            {
                t=arr[j];
                arr[j]=arr[i];
                arr[i]=t;
            }


            if (i != j)
                perest++;
            i++;
            j--;

        }
    }
    while (i <= j);

    if (i < last)

        quicksort(arr,i,last);

    if (j > first)

        quicksort(arr,first,j);
}

void bubblesort(int *arr,int n)
{
    int i,j,t;

    for (i=0; i < n-1; i++)
    {
        for (j=0; j < n-i-1; j++)
        {
            sravn++;
            printf("%d %d\n", j,j+1);
            if ( arr[j] > arr[j+1])
            {
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
                perest++;
            }
        }
    }
}

void insertsort(int *arr,int n)
{
    int i,k,j;
    for (i = 1; i < n; i++)
    {
        k = arr[i];
        j=i-1;
        sravn++;
        while (j >= 0 && arr[j] > k)
        {
            perest++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int k;
    while(k!=0)
    {
        int  *arr, n, i;

        printf("\nЖелаемая сортировка \n");
        printf("0) exit\n");
        printf("1) quicksort\n");
        printf("2) insertsort\n");
        printf("3) bubblesort\n");

        printf("Выберите сортировку = ");
        scanf("%d", &k);


        printf("Введите кол-во элементов массива\n");
        scanf("%d", &n);
        int first = 0, last = n-1;
        arr = (int*) malloc(n*sizeof(int));

        printf("Введите элементы массива\n");
        for (i=0; i<n; i++)
            scanf("%d", &arr[i]);

        switch (k)
        {
        case 1:
            quicksort(arr, first, last) ;
            break;

        case 2:
            insertsort(arr, n);
            break;

        case 3:
            bubblesort(arr, n);
            break;
        default:
            k=0;
            break;

        }

        printf("\nМассив:\n");

        for(i=0; i<n; i++)
            printf("%d  ", arr[i]);
        printf("\nКол-во перестановок: ");
        printf("%d\n",perest);
        printf("Кол-во сравнений: ");
        printf("%d\n", sravn);
        sravn = 0;
        perest = 0;

    }

}
