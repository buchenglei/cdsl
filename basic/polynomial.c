/*
 * 用数组实现多项式的相加与相乘
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxDegree 5

/* 多项式结构 */
struct PolyNode
{
	int CoeffArray[ MaxDegree ];
	int HighPower;
};
typedef struct PolyNode* Polynomial;

/* 将多项式结构清零 */
void ZeroPolynomial(Polynomial Poly)
{
	int i;

	for( i = 0; i <= MaxDegree; i++)
		Poly->CoeffArray[ i ] = 0;
	Poly->HighPower = 0;
}

/* 将两个多项式相加 */
void AddPolynomial( const Polynomial Poly1,
				const Polynomial Poly2, Polynomial PolySum )
{
	int i;

	ZeroPolynomial( PolySum );
	PolySum->HighPower = Poly1->HighPower > Poly2->HighPower?
				Poly1->HighPower : Poly2->HighPower;
	for( i = PolySum->HighPower; i >= 0; i-- )
		PolySum->CoeffArray[ i ] = Poly1->CoeffArray[ i ]
							+ Poly2->CoeffArray[ i ];
}

/* 将两个多项式相乘 */
void MultPolynomial( const Polynomial Poly1,
				const Polynomial Poly2, Polynomial PolyProd )
{
	int i, j;

	ZeroPolynomial( PolyProd );
	PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;
	
	if( PolyProd->HighPower > MaxDegree )
		printf("Exceeded array size\n");
	else
		for( i = 0;i <= Poly1->HighPower; i++)
			for( j = 0;j <= Poly2->HighPower; j++ )
				PolyProd->CoeffArray[ i + j ] +=
					Poly1->CoeffArray[ i ] *
					Poly2->CoeffArray[ j ];

}

/* 输出多项式的结果 */
void ShowResult( Polynomial Poly )
{
	int i;
	
	printf("HighPower is %d\n", Poly->HighPower);
	for( i = MaxDegree - 1;i >= 0; i--)
		printf("%dx%d ",Poly->CoeffArray[ i ], i);

	printf("\n");
}

void main()
{
	Polynomial Poly1 = malloc( sizeof( struct PolyNode ) );
	Polynomial Poly2 = malloc( sizeof( struct PolyNode ) );
	Polynomial PolySum = malloc( sizeof( struct PolyNode ) );
	Polynomial PolyProd = malloc( sizeof( struct PolyNode ) );
	
	Poly1->HighPower = 2;
	Poly1->CoeffArray[ 0 ] = 1; 
	Poly1->CoeffArray[ 1 ] = 0; 
	Poly1->CoeffArray[ 2 ] = 1; 
	Poly1->CoeffArray[ 3 ] = 0; 
	Poly1->CoeffArray[ 4 ] = 0; 
	
	Poly2->HighPower = 1;
	Poly2->CoeffArray[ 0 ] = 1; 
	Poly2->CoeffArray[ 1 ] = 1; 
	Poly2->CoeffArray[ 2 ] = 0; 
	Poly2->CoeffArray[ 3 ] = 0; 
	Poly2->CoeffArray[ 4 ] = 0; 

	AddPolynomial( Poly1, Poly2, PolySum );
	MultPolynomial( Poly1, Poly2, PolyProd );

	ShowResult( Poly1 );
	ShowResult( Poly2 );
	ShowResult( PolySum );
	ShowResult( PolyProd );
}

