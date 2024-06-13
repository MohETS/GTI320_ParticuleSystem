/**
 * @file TestsSupplementaire1b.cpp
 *
 * @brief Tests unitaires supplémentaires de la partie 1b
 *
 * Nom:
 * Code permanent :
 * Email :
 *
 */

#include "Matrix.h"
#include "Vector.h"
#include "Math3D.h"
#include "Operators.h"

#include <gtest/gtest.h>

using namespace gti320; 

TEST(TestLabo1b, Supplementaires)
{
    // TODO vos propres tests ici

	//Test 1 - Soustraction de deux vector.
	Vector<double> v1(3);
	v1(0) = 1;
	v1(1) = 2;
	v1(2) = 3;

	Vector<double> v2(3);
	v2(0) = 1;
	v2(1) = 1;
	v2(2) = 1;

	const auto r1 = v1 - v2;
	EXPECT_DOUBLE_EQ(r1(0), v1(0) - v2(0));
	EXPECT_DOUBLE_EQ(r1(1), v1(1) - v2(1));
	EXPECT_DOUBLE_EQ(r1(2), v1(2) - v2(2));

	//Test 2 - Verifie si la multiplication d'une matrice colonne avec un vecteur retourne les valeurs exactes.
	Matrix<double, Dynamic, Dynamic, ColumnStorage> m1Col(3, 3);
	m1Col(0, 0) = 1;    m1Col(0, 1) = 2;    m1Col(0, 2) = 3;
	m1Col(1, 0) = 4;    m1Col(1, 1) = 5;    m1Col(1, 2) = 6;
	m1Col(2, 0) = 7;    m1Col(2, 1) = 8;    m1Col(2, 2) = 9;

	const auto r2 = m1Col * v1;

	EXPECT_DOUBLE_EQ(r2(0), 14);
	EXPECT_DOUBLE_EQ(r2(1), 32);
	EXPECT_DOUBLE_EQ(r2(2), 50);

	//Test 3 - Verifie si la multiplication d'une matrice range avec un vecteur retourne les valeurs exactes.
	Matrix<double, Dynamic, Dynamic, RowStorage> m1Row(3, 3);
	m1Row(0, 0) = 9;    m1Row(0, 1) = 8;    m1Row(0, 2) = 7;
	m1Row(1, 0) = 6;    m1Row(1, 1) = 5;    m1Row(1, 2) = 4;
	m1Row(2, 0) = 3;    m1Row(2, 1) = 2;    m1Row(2, 2) = 1;


	const auto r3 = m1Row * v1;

	EXPECT_DOUBLE_EQ(r3(0), 46);
	EXPECT_DOUBLE_EQ(r3(1), 28);
	EXPECT_DOUBLE_EQ(r3(2), 10);

	//Test 4 - Verifie si la multiplication d'une matrice colonne avec un vecteur retourne les valeurs exactes lorsque la matrice n'est pas carree.
	Matrix<double, Dynamic, Dynamic, ColumnStorage> m2Col(4, 3);
	m2Col(0, 0) = 1;    m2Col(0, 1) = 2;    m2Col(0, 2) = 3;
	m2Col(1, 0) = 4;    m2Col(1, 1) = 5;    m2Col(1, 2) = 6;
	m2Col(2, 0) = 7;    m2Col(2, 1) = 8;    m2Col(2, 2) = 9;
	m2Col(3, 0) = 1;    m2Col(3, 1) = 2;    m2Col(3, 2) = 3;

	const auto r4 = m2Col * v1;

	EXPECT_DOUBLE_EQ(r4(0), 14);
	EXPECT_DOUBLE_EQ(r4(1), 32);
	EXPECT_DOUBLE_EQ(r4(2), 50);
	EXPECT_DOUBLE_EQ(r4(0), 14);

	//Test 5 - Verifie si la multiplication d'une matrice range avec un vecteur retourne les valeurs exactes lorsque la matrice n'est pas carree.
	Matrix<double, Dynamic, Dynamic, RowStorage> m2Row(4, 3);
	m2Row(0, 0) = 9;    m2Row(0, 1) = 8;    m2Row(0, 2) = 7;
	m2Row(1, 0) = 6;    m2Row(1, 1) = 5;    m2Row(1, 2) = 4;
	m2Row(2, 0) = 3;    m2Row(2, 1) = 2;    m2Row(2, 2) = 1;
	m2Row(3, 0) = 9;    m2Row(3, 1) = 8;    m2Row(3, 2) = 7;

	const auto r5 = m2Row * v1;

	EXPECT_DOUBLE_EQ(r5(0), 46);
	EXPECT_DOUBLE_EQ(r5(1), 28);
	EXPECT_DOUBLE_EQ(r5(2), 10);
	EXPECT_DOUBLE_EQ(r5(3), 46);

	//Test 6 - Verifie si l'addition d'une matrice colonne avec une matrice range retourne les valeurs exactes.
	const auto r6 = m1Col + m1Row;

	EXPECT_DOUBLE_EQ(r6(0, 0), 10);
	EXPECT_DOUBLE_EQ(r6(1, 0), 10);
	EXPECT_DOUBLE_EQ(r6(2, 0), 10);

	//Test 7 - Verifie si l'addition d'une matrice range avec une matrice colonne retourne les valeurs exactes.

	const auto r7 = m2Row + m2Col;

	EXPECT_DOUBLE_EQ(r7(0, 0), 10);
	EXPECT_DOUBLE_EQ(r7(1, 0), 10);
	EXPECT_DOUBLE_EQ(r7(2, 0), 10);
	EXPECT_DOUBLE_EQ(r7(3, 0), 10);

	//Test 8 - Verifie si une matrice 4F execute correctement la methode setIdentity();
	Matrix4f m4F;
	m4F.setIdentity();
	EXPECT_DOUBLE_EQ(m4F(0, 0), 1.0);
	EXPECT_DOUBLE_EQ(m4F(0, 1), 0.0);
	EXPECT_DOUBLE_EQ(m4F(0, 2), 0.0);
	EXPECT_DOUBLE_EQ(m4F(1, 1), 1.0);
	EXPECT_DOUBLE_EQ(m4F(1, 0), 0.0);
	EXPECT_DOUBLE_EQ(m4F(1, 2), 0.0);
	EXPECT_DOUBLE_EQ(m4F(2, 0), 0.0);
	EXPECT_DOUBLE_EQ(m4F(2, 1), 0.0);
	EXPECT_DOUBLE_EQ(m4F(2, 2), 1.0);

	//Test 9 - Verifie si une matrice 4D effectue correctement la methode inverse() sans la multiplie avec le vecteur
	Matrix4d m4D;
	m4D(0, 0) = 1;    m4D(0, 1) = 0;		 m4D(0, 2) = 0;			m4D(0, 3) = 1;
	m4D(1, 0) = 0;    m4D(1, 1) = 0.866025;	 m4D(1, 2) = -0.5;		m4D(1, 3) = 2;
	m4D(2, 0) = 0;    m4D(2, 1) = 0.5;		 m4D(2, 2) = 0.866025;	m4D(2, 3) = 3;
	m4D(3, 0) = 0;    m4D(3, 1) = 0;		 m4D(3, 2) = 0;			m4D(3, 3) = 1;

	const Matrix4d r9 = m4D.inverse();
	EXPECT_DOUBLE_EQ(r9(1, 1), 0.866025);
	EXPECT_DOUBLE_EQ(r9(1, 2), 0.5);
	EXPECT_DOUBLE_EQ(r9(2, 1), -0.5);
	EXPECT_DOUBLE_EQ(r9(2, 2), 0.866025);
	EXPECT_DOUBLE_EQ(r9(0, 3), -1);
	EXPECT_DOUBLE_EQ(r9(1, 3), -3.23205);
	EXPECT_DOUBLE_EQ(r9(2, 3), -1.5980750000000001);

	//Test 10 - Verifie si une matrice 4D multiplie par un vecteur donne les bon resultats (Matrice non inverse)
	Vector3d v3D;
	v3D(0) = 3;
	v3D(1) = 3;
	v3D(2) = 3;
	Vector3d r10 = m4D * v3D;

	EXPECT_DOUBLE_EQ(r10(0), 4);
	EXPECT_DOUBLE_EQ(r10(1), 3.0980750000000001);
	EXPECT_DOUBLE_EQ(r10(2), 7.0980749999999997);

}
