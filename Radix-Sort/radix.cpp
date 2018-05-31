#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int chave(int x, int d){
	return (int)(x/pow(10, d)) % 10;
}

void print_vector(int V[], int n){
	for(int i = 0; i < n; i++){
		cout << V[i] << " ";
	}
	cout << endl;
}

void couting_sort(int X[], int n, int d){
	int A[10];
	int Y[n];

	for(int i = 0; i < 10; i++){
		A[i] = 0;
	}

	for(int i = 0; i < n; i++){
		int j = chave(X[i], d);
		A[j]++;
	}

	for(int i = 1; i < 10; i++){
		A[i] += A[i-1];
	}

	for(int i = n-1; i >= 0; i--){
		int j = chave(X[i], d);
		Y[A[j]-1] = X[i];
		A[j]--;
	}

	for(int i = 0; i < n; i++){
		X[i] = Y[i];
	}
}

void radix_sort(int X[], int n, int d){
	print_vector(X, n);
	for(int i = 0; i < d; i++){
		couting_sort(X, n, i);
		print_vector(X, n);
	}
}

int main(){
	int X[10];

	srand(666);
	for(int i = 0; i < 10; i++){
		X[i] = rand() % 99999;
	}

	radix_sort(X, 10, 5);

	return 0;
}
