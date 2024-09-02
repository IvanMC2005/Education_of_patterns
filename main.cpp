#include <iostream>
#include <ctime>
using namespace std;
template <typename T, typename T1> T search_min(T *, T1);
int main()
{
    setlocale(0, "rus");
    int size_mas = 10;
    int number;
    cout << "for double\n";
    {
        double mas[10];
        srand(time(0));
        for (int i{0}; i < size_mas; i++)
        {
            number = rand();
            mas[i] = rand() - number / 3;
        }
        for (int i{0}; i < size_mas; i++)
        {
            cout << mas[i] << " ";
        }
        cout << endl;
        cout << "Если вернёт -1 - нет таких элементов" << endl;
        cout << search_min<double, int>(mas, size_mas) << endl;
    }
    cout << "================================================================================================" << endl;
    cout << "for char\n";
    {
        char mas[10];
        srand(time(0) + 3);
        for (int i{0}; i < size_mas; i++)
        {
            number = rand();
            mas[i] = rand() - number / 3;
        }
        for (int i{0}; i < size_mas; i++)
        {
            cout << static_cast<int>(mas[i]) << " ";
        }
        cout << endl;
        cout << "Если вернёт -1 - нет таких элементов" << endl;
        cout << static_cast<int>(search_min<char, int>(mas, size_mas));
    }
    return 0;
}
template <typename T, typename T1> T search_min (T * mas, T1 length_mas)
{
    T1 i;
    T minimum = -1;
    for (i = 1; i <= (length_mas - 1) && mas[i] <= 0;  i += 2);
    if (i == length_mas + 1) return minimum;
    minimum = mas[i];
    for(; i < length_mas; i += 2)
    {
        if ((mas[i] < minimum)&& (mas[i] > 0)) minimum = mas[i];
    }
    return minimum;
}
