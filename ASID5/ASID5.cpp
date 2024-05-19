#include <iostream>
#include <random>
#include <cstdlib>
#include <iomanip>

void printTab(int* tab, int size) 
{
    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(4) << tab[i];
    }
}
void quicksort(int* tab, int left, int right) {
    int pivotIndex = (int)((left + right) / 2);
    int pivot = tab[pivotIndex];
    
    int i = left;
    int j = i;

    std::cout << "i<-left = " << i << "\n";
    std::cout << "right = " << right << "\n";
    std::cout << "j<-i = " << j << "\n\n";

    std::cout << "tab[pivotIndex=" << pivotIndex << "] =" << tab[pivotIndex] << " <- " << "tab[right = " << right << "] = " << tab[right] << "\n";
    tab[pivotIndex] = tab[right];  

    std::cout << "Petla while:\n";
    while (i<right)
    {
        std::cout <<"tab[i="<<i<<"]= "<< tab[i] << " < " <<"pivot = " << pivot << " ? ";
        if (tab[i] < pivot) {
            std::cout << std::setw(4) << "zamien tab[i=" << i << "]=" << tab[i] << " z "  << "tab[j="<< j<<"] = "<<tab[j] << "\n";
            std::swap(tab[i], tab[j]);
            j++;
        }
        else std::cout << "NIE\n";
        i++;
    }
    
    tab[right] = tab[j];
    tab[j] = pivot;
    std::cout << "Czy left = " << left<< " < j-1 = " << j - 1 << "? ";
    if (left < j - 1)
    {
        std::cout << "\nTAK. dokonaj partycji z lewej strony \n";
        std::cout << "\n";
        quicksort(tab, left, j - 1);
    }
    else std::cout << "NIE\n";
    std::cout << "Czy j+1 = " << j+1<< " < right = " << right<< "? ";
    if (j + 1 < right)  
    {
        std::cout << "\nTAK. dokonaj partycji z prawej strony \n";
        std::cout << "\n";
        quicksort(tab, j + 1, right);
    }
    else std::cout << "NIE\n";
}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 100);
    int n = 5; //Wielkość tablicy
    int *tab = new int[n];

    for (int i = 0; i < n; i++)
    {
        tab[i] = distr(gen);
    }
    std::cout << "Przed sortowaniem:\n";
    printTab(tab, n);
    std::cout << "\n";

    quicksort(tab, 0, n - 1);
    std::cout << "Po sortowaniu:\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << std::setw(4) << tab[i];
    }
    std::cout << "\n";

    return 0;
}

