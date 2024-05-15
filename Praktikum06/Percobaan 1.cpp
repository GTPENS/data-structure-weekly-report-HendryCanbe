#include <iostream>
#include <cstdlib>

//5223600002 / Bernadus Hendry Haryuwardhana

using namespace std;

#define MAX 10
int Data[MAX];

// Fungsi pengurutan penyisipan langsung
void StraightInsertSort()
{
    int i, j, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        j = i - 1;
        while (x < Data[j]) {
            Data[j + 1] = Data[j];
            j--;
        }
        Data[j + 1] = x;
    }
}

int main()
{
    int i;
    srand(0);
    // Membangkitkan bilangan acak
    cout << "Data sebelum berurutan" << endl;
    for (i = 0; i < MAX; i++)
    {
        Data[i] = (int)rand() / 1000 + 1;
        cout << "Data ke " << i << ": " << Data[i] << endl;
    }
    StraightInsertSort();
    // Data setelah terurut
    cout << "\nData setelah berurutan" << endl;
    for (i = 0; i < MAX; i++)
    {
        cout << "Data ke " << i << ": " << Data[i] << endl;
    }
    return 0;
}
