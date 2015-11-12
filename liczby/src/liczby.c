/*
 * liczby.c
 *
 *  Created on: 12 lis 2015
 *      Author: daniel.las
 */

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Losujemy liczbę z zadanego przedzialu
double losuj_liczbe(double min, double max) {
	return min + ((double) rand() / (double) RAND_MAX) * (double) (max - min);
}

// Losujemy "ilosc" z zadanego przedzialu
double * losuj_liczby(double min, double max, int ilosc) {
	// Rezerwujemy miejsce na ilosc liczb i rozmiarze double
	double * liczby = malloc(ilosc * sizeof(double));
	int i = 0;

	for (i = 0; i < ilosc; i++) {
		liczby[i] = losuj_liczbe(min, max);
	}

	return liczby;
}

// Sumujemy z tablicy liczby o rozmiarze ilosc
double sumuj(double * liczby, int ilosc) {
	double suma = 0;
	int i = 0;

	for (i = 0; i < ilosc; i++) {
		suma = suma + liczby[i];
	}

	return suma;
}

// Szukamy max
double znajdz_max(double * liczby) {
	double max = DBL_MIN;
	int i = 0;

	for (i = 0; i < 5; i++) {
		if (liczby[i] > max) {
			max = liczby[i];
		}
	}

	return max;
}
//Szukamy min
double znajdz_min(double * liczby) {
	double min = DBL_MAX;
	int i = 0;

	for (i = 0; i < 5; i++) {
		if (liczby[i] < min) {
			min = liczby[i];
		}
	}

	return min;
}

// Zamieniamy współrzędne x,y tablicy dwywymiarowej na pozycję w tablicy jednowymiarowej
int pozycja_tablicy(int x, int y, int rozmiar) {
	return x + y * rozmiar;
}

// Losujemy liczby i wkłądamy do tablicy 2 wymiarowej
double * losuj_2wym(double min, double max, int rozmiar) {
	double * liczby = malloc(rozmiar * rozmiar * sizeof(double));
	int i = 0, j = 0;

	for (i = 0; i < rozmiar; i++) {
		for (j = 0; j < rozmiar; j++) {
			liczby[pozycja_tablicy(i, j, rozmiar)] = losuj_liczbe(min, max);
		}
	}

	return liczby;
}

// Zwracamy na jakiej pozycji tablica jest wartosc
int znajdz_index(double * liczby, double wartosc) {
	int i = 0;

	for (i = 0; i < 5; i++) {
		if (liczby[i] == wartosc) {
			return i;
		}
	}

	return i;
}

// Zwracamy przekatną tablicy o zadanym rozmiarze
double * przekatna_tablicy(double * tablica, int rozmiar) {
	double * przekatna = malloc(rozmiar * sizeof(double));
	int i = 0;

	for (i = 0; i < rozmiar; i++) {
		przekatna[i] = tablica[pozycja_tablicy(i, i, 5)];
	}

	return przekatna;
}

// Sortujemy używając algorytmu bubble sort - sortoanie bąbelkowe
void sortuj(double * liczby, int rozmiar) {
	int i = 0, d = 0;
	double z;

	// Lecimy po wszystkich elementach oprócz ostatniego
	for (i = 0; i < (rozmiar - 1); i++) {
		// Zaczynamy od początku, zakładamy że końcówka jest już posortowana w poprzednich iteracjach
		for (d = 0; d < rozmiar - i - 1; d++) {
			// Jeśli liczba na pozycji d jest większa od liczby na następnej pozycji
			if (liczby[d] > liczby[d + 1]) {
				// Zamieniamy je miejscami
				z = liczby[d];
				liczby[d] = liczby[d + 1];
				liczby[d + 1] = z;
			}
		}
	}
}

int main(void) {
	double * liczby = losuj_liczby(-5, 5, 5);
	int i = 0;

	printf("Wylosowane liczby:\n");
	for (i = 0; i < 5; i++) {
		printf("%f\n", liczby[i]);
	}

	double suma = sumuj(liczby, 5);

	printf("Suma: %f\n", suma);

	double max = znajdz_max(liczby);

	printf("Max: %f\n", max);

	int index_max = znajdz_index(liczby, max);

	printf("Index max: %i\n", index_max);

	double min = znajdz_min(liczby);

	printf("Main: %f\n", min);

	int index_min = znajdz_index(liczby, min);

	printf("Index min: %i\n", index_min);

	double * tablica = losuj_2wym(-2, 10, 5);

	int j = 0;

	printf("Tablica:\n");
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			printf("%f,", tablica[pozycja_tablicy(i, j, 5)]);
		}
		printf("\n");
	}

	printf("Przekątna:\n");
	double * przekatna = przekatna_tablicy(tablica, 5);

	for (i = 0; i < 5; i++) {
		printf("%f,", przekatna[i]);
	}
	printf("\n");

	double suma_przekatnej = sumuj(przekatna, 5);
	printf("Suma przekątnej:%f\n", suma_przekatnej);

	sortuj(przekatna, 5);
	printf("Posortowana przekątna:\n");
	for (i = 0; i < 5; i++) {
		printf("%f,", przekatna[i]);
	}

	return EXIT_SUCCESS;
}
