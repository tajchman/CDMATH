/*
 * SparseMatrixPetsc.hxx
 *
 *  Created on: 03/11/2017. 2017
 *      Author: mndjinga
 */

#ifndef SOURCE_DIRECTORY__BASE_INC_SparseMatrixPetsc_HXX_
#define SOURCE_DIRECTORY__BASE_INC_SparseMatrixPetsc_HXX_

#include <iostream>

#include "GenericMatrix.hxx"
#include "Vector.hxx"
#include <petsc.h>

class SparseMatrixPetsc: public GenericMatrix {

public:
	SparseMatrixPetsc();
	virtual ~SparseMatrixPetsc();

	/**
	 * constructor for a block sparse matrix
	 * @param numberOfRows : The number of rows
	 * @param numberOfColumns : The number of columns
	 */
	SparseMatrixPetsc( int numberOfRows, int numberOfColumns ) ;

	/**
	 * constructor for a block sparse matrix with number of non zero coefficients given
	 * @param numberOfRows : The number of rows
	 * @param numberOfColumns : The number of columns
	 * @param nnz : The maximum number of nonzeros coefficients per line (or an upper bound)
	 */
	SparseMatrixPetsc( int numberOfRows, int numberOfColumns, int nnz ) ;

	/**
	 * constructor for a sparse matrix with block structure
	 * @param blockSize : The block size
	 * @param numberOfRows : The number of rows
	 * @param numberOfColumns : The number of columns
	 * @param nnz : The maximum number of nonzeros coefficients per line (or an upper bound)
     * @comment blockSize should always divide numberOfRows and numberOfColumns
	 */
    SparseMatrixPetsc( int blockSize, int numberOfRows, int numberOfColumns, int nnz );

	/**
	 * constructor by copy
	 * @param SparseMatrixPetsc : The SparseMatrixPetsc object to be copied
	 */
	SparseMatrixPetsc ( const SparseMatrixPetsc& sparseMatrixPetsc ) ;

	/**
	 * constructor with data
	 * @param Petsc matris : mat
	 */
	SparseMatrixPetsc(Mat mat);

	SparseMatrixPetsc transpose() const ;

	double operator()( int i, int j ) const ;

	void setValue( int i, int j, double value ) ;
	void addValue( int i, int j, double value ) ;

	void setValue( int i, int j, Matrix M ) ;
	void addValue( int i, int j, Matrix M ) ;

	void setValuesBlocked( int i, int j, Matrix M ) ;
	void addValuesBlocked( int i, int j, Matrix M ) ;

	SparseMatrixPetsc& operator+= (const SparseMatrixPetsc& SparseMatrixPetsc) ;

	SparseMatrixPetsc& operator-= (const SparseMatrixPetsc& SparseMatrixPetsc) ;

	SparseMatrixPetsc& operator*= (double value) ;

	SparseMatrixPetsc& operator/= (double value) ;

	SparseMatrixPetsc& operator*= (const SparseMatrixPetsc& matrix) ;

	Vector operator* (const Vector& vector) const ;

	const SparseMatrixPetsc& operator= ( const SparseMatrixPetsc& SparseMatrixPetsc ) ;

	friend SparseMatrixPetsc operator+ (const SparseMatrixPetsc& SparseMatrixPetsc1, const SparseMatrixPetsc& SparseMatrixPetsc2);

	friend SparseMatrixPetsc operator- (const SparseMatrixPetsc& SparseMatrixPetsc1, const SparseMatrixPetsc& SparseMatrixPetsc2);

	friend SparseMatrixPetsc operator* (double value , const SparseMatrixPetsc& SparseMatrixPetsc ) ;

	friend SparseMatrixPetsc operator* (const SparseMatrixPetsc& SparseMatrixPetsc, double value ) ;

	friend SparseMatrixPetsc operator/ (const SparseMatrixPetsc& SparseMatrixPetsc, double value) ;

	friend SparseMatrixPetsc operator*(const SparseMatrixPetsc& M, const SparseMatrixPetsc& N) ;

	void viewMatrix() const ;
	double getMatrixCoeff(int i, int j) const;    

	bool containsPetscMatrix() const;
	Mat getPetscMatrix() const;
    
    void diagonalShift(double lambda);

private:
	Mat _mat;

	int _numberOfNonZeros ;//The maximum number of nonzeros coefficients per line (or an upper bound)
};


#endif /* SOURCE_DIRECTORY__BASE_INC_SparseMatrixPetsc_HXX_ */
