#include<iostream>
using namespace std;

int partition(int a[], int lb, int ub){
    int down,up,temp,x;
    down = lb;
    up = ub;
    x = a[lb];
    while (down< up){
        while (a[down] <= x && down<up)
        down++;
        while (a[up] > x)
        up--;
        if(down< up){
            temp = a[down];
            a[down] = a[up];
            a[up] = temp;
        }
    }

    a[lb] = a[up];
    a[up] = x;
    return up;
}

void quicksort (int a[], int lb, int ub){
    int j;
    if (lb < ub){
        j = partition(a, lb, ub);
        quicksort(a,lb,j-1);
        quicksort(a,j+1,ub);
    }
}

int main() {
    int n,a[10];
    cout << "Enter the no. of elements" << endl;
    cin >> n;
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    quicksort(a,0,n-1);
    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
}