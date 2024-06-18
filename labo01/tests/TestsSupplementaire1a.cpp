/**
 * @file TestsSupplementaire1a.cpp
 *
 * @brief Tests unitaires supplémentaires de la partie 1a
 *
 * Nom:
 * Code permanent :
 * Email :
 *
 */

#include "Matrix.h"
#include "Vector.h"

#include <gtest/gtest.h>

using namespace gti320;

TEST(TestLabo1a, Supplementaires)
{
    // TODO vos propres tests ici

	//Test 1 - Copie d'une sous-matrice dans une matrice avec la taille exacte.
	Matrix<double, Dynamic, Dynamic, ColumnStorage> A(4, 4);
	A(0, 0) = 1;    A(0, 1) = 1;    A(0, 2) = 1;    A(0, 3) = 1;
	A(1, 0) = 1;    A(1, 1) = 2;    A(1, 2) = 2;    A(1, 3) = 1;
	A(2, 0) = 1;    A(2, 1) = 2;    A(2, 2) = 2;    A(2, 3) = 1;
	A(3, 0) = 1;    A(3, 1) = 1;    A(3, 2) = 1;    A(3, 3) = 1;

	Matrix<double> B(2, 2);
	B = A.block(1, 1, 2, 2);

	EXPECT_DOUBLE_EQ(B(0, 0), 2.0);
	EXPECT_DOUBLE_EQ(B(0, 1), 2.0);
	EXPECT_DOUBLE_EQ(B(1, 0), 2.0);
	EXPECT_DOUBLE_EQ(B(1, 1), 2.0);

	//Test 2 - Copie d'une sous-matrice dans une matrice qui n'as pas la taille exacte. (Verification du resize)
	Matrix<double> C(3, 4);
	C = A.block(1, 1, 2, 2);
	EXPECT_DOUBLE_EQ(C.rows(), 2);
	EXPECT_DOUBLE_EQ(C.cols(), 2);


	//Test 3 - Copie de la valeur d'une matrice de la meme taille que la sous-matrice dans la sous-matrice
	Matrix<double, Dynamic, Dynamic, ColumnStorage> D(2, 2);
	D(0, 0) = 10;    D(0, 1) = 11;
	D(1, 0) = 12;    D(1, 1) = 13;

	SubMatrix<double, Dynamic, Dynamic, ColumnStorage> sousMatriceA(A, 1, 1, 2, 2);

	sousMatriceA = D;

	EXPECT_DOUBLE_EQ(A(1, 1), 10);
	EXPECT_DOUBLE_EQ(A(1, 2), 11);
	EXPECT_DOUBLE_EQ(A(2, 1), 12);
	EXPECT_DOUBLE_EQ(A(2, 2), 13);

	//Test 4 - Transposition de la sous-matrice

	const auto sousMatriceATranspose = sousMatriceA.transpose<double, Dynamic, Dynamic, ColumnStorage>();

	EXPECT_DOUBLE_EQ(sousMatriceATranspose(0, 0), 10);
	EXPECT_DOUBLE_EQ(sousMatriceATranspose(0, 1), 12);
	EXPECT_DOUBLE_EQ(sousMatriceATranspose(1, 0), 11);
	EXPECT_DOUBLE_EQ(sousMatriceATranspose(1, 1), 13);



	//Test 5 - Transposition d'une matrice rowMajor
	Matrix<double, Dynamic, Dynamic, ColumnStorage> E(2, 2);
	E(0, 0) = 1;    E(0, 1) = 2;
	E(1, 0) = 3;    E(1, 1) = 4;

	const auto matriceETranspose = E.transpose<double, Dynamic, Dynamic, RowStorage>();

	EXPECT_DOUBLE_EQ(matriceETranspose(0, 0), 1);
	EXPECT_DOUBLE_EQ(matriceETranspose(0, 1), 3);
	EXPECT_DOUBLE_EQ(matriceETranspose(1, 0), 2);
	EXPECT_DOUBLE_EQ(matriceETranspose(1, 1), 4);

    // TEST 6 
    //

    // TEST 7
    //

    // TEST 8 
    //

    // TEST 9 
    //

    // TEST 10 
    //
}
