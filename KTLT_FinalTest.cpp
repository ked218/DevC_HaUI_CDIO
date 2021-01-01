#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<fstream>
#include<stdio.h>
 void xuat(int size, int arr[]);

using namespace std;

void nhap_mang (int &size)
{
	do
	{
		cout << "Nhap vao so phan tu cua mang (4<n<31): ";
		cin >> size;
	}
	while(size < 5 || size > 30);
}

void xuat_mang (int size, int arr[])
{
	arr[0] = size;
	for (int i = 1; i < size; ++i)
	{
		arr[i] = size + pow(i,2);
	}
	cout << "Mang da duoc thay doi (gtri phan tu = n + pow(i,2)) la: "<< endl;
	xuat(size,arr);
}

void xuat(int size, int arr[]){
	
	for (int i = 0; i < size; ++i)
	{
		cout << " "<<arr[i];
	}
	printf("\n");
}

//ktra so nguyen to va tong cua tat ca so khong phai ngto
void sum_num (int size, int arr[])
{
	int count = 0;
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 2; j <= sqrt(arr[i]); ++j)
		{
			if (arr[i] % j == 0)
			{
				count++;
			}
		}
		if (count != 0)
		{
			sum += arr[i];
		}
	}
	cout << endl;
	cout << "Tong cua cac so khong phai so nguyen to la: " <<sum;
}

void ghifile(FILE **f, int arr[], int size){
	
	for(int i=size-1; i>=0; --i){
		
		fprintf(*f,"%d ",arr[i]);
		printf("%d ",arr[i]);
	}
	fprintf(*f,"\n");
	printf("\n");
}

void ghifile1(FILE **f, int arr[], int size){
	
	for(int i=0; i<size; ++i){
		
		fprintf(*f,"%d ",arr[i]);
		printf("%d ",arr[i]);
	}
	fprintf(*f,"\n");
	printf("\n");
}

void sap_xep(int size, int arr[])
{
	for(int i=1; i<size; ++i){
		
		if(size > arr[i] && size <= arr[i+1]){
			
			arr[i-1] = arr[i];
			arr[i] = size;
		}
	}
}

int main()
{
	int size;
	int *arr = new int[size];
	nhap_mang (size);
	xuat_mang (size,arr);
	FILE *f;
	f = fopen("ktlt123.txt", "w");
	ghifile(&f,arr,size);
	sap_xep (size, arr);
	xuat(size,arr);
	ghifile1(&f,arr,size);
	sum_num (size, arr);
	fclose(f);
	return 0;
}


