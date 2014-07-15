/*
 * linearSolvertests.cxx
 *
 *  Created on: 24 janv. 2012
 *      Authors: CDMAT
 */

#include "Matrix.hxx"
#include "Vector.hxx"
#include "LinearSolverTests.hxx"

using namespace std;

//----------------------------------------------------------------------
void
LinearSolverTests::testClassLinearSolver( void )
//----------------------------------------------------------------------
{
	Matrix A(2,2);
    A(0,0)=3.;
    A(0,1)=-2.;
    A(1,0)=-2.;
    A(1,1)=4.;

    A*=A.transpose();

    Vector Xana(2);
    Xana(0)=1.;
    Xana(1)=2.;

    Vector B=A*Xana;

    LinearSolver LS(A,B,500,1.E-10,"GMRES","LU");

    Vector X=LS.solve();
	CPPUNIT_ASSERT(abs(X(0)-Xana(0))<1.E-10);
	CPPUNIT_ASSERT(abs(X(1)-Xana(1))<1.E-10);

	CPPUNIT_ASSERT_EQUAL(LS.getStatus(),true);

	CPPUNIT_ASSERT_EQUAL(LS.getNumberMaxOfIter(),500);
	CPPUNIT_ASSERT_EQUAL(LS.getTolerance(),1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS.getNameOfMethod(),(string)"GMRES");
	CPPUNIT_ASSERT_EQUAL(LS.getNumberOfIter(),1);
	CPPUNIT_ASSERT_EQUAL(LS.isSingular(),false);
	CPPUNIT_ASSERT_EQUAL(LS.getNameOfPc(),(string)"LU");

	LinearSolver LS2(A,B,500,1.E-10,"CG");
	Matrix A1(2,2);
    A1(0,0)=1.;
    A1(0,1)=-2.;
    A1(1,0)=-2.;
    A1(1,1)=4.;
	LS2.setMatrix(-1.*A1);
	LS2.setSndMember(-1*B);
	LS2.setTolerance(1.E-20);
	LS2.setNumberMaxOfIter(10);
	LS2.setSingularity(true);
	Vector X2=LS2.solve();

	CPPUNIT_ASSERT(abs(X2(0)-(-4.55555555556))<1.E-10);
	CPPUNIT_ASSERT(abs(X2(1)-4.55555555556)<1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS.getStatus(),true);
	CPPUNIT_ASSERT_EQUAL(LS2.getNumberOfIter(),2);
	CPPUNIT_ASSERT_EQUAL(LS2.isSingular(),true);
	CPPUNIT_ASSERT_EQUAL(LS2.getNameOfMethod(),(string)"CG");

	LinearSolver LS3(A,B,500,1.E-10,"BCG");
    Vector X3=LS3.solve();
	CPPUNIT_ASSERT(abs(X3(0)-Xana(0))<1.E-10);
	CPPUNIT_ASSERT(abs(X3(1)-2.)<1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS3.getStatus(),true);
	CPPUNIT_ASSERT_EQUAL(LS3.getNameOfMethod(),(string)"BCG");

	LinearSolver LS4(A,B,500,1.E-10,"CR");
    X3=LS4.solve();
	CPPUNIT_ASSERT(abs(X3(0)-Xana(0))<1.E-10);
	CPPUNIT_ASSERT(abs(X3(1)-2.)<1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS4.getStatus(),true);
	CPPUNIT_ASSERT_EQUAL(LS4.getNameOfMethod(),(string)"CR");

	LinearSolver LS5(A,B,500,1.E-10,"CGS");
    X3=LS5.solve();
	CPPUNIT_ASSERT(abs(X3(0)-Xana(0))<1.E-10);
	CPPUNIT_ASSERT(abs(X3(1)-2.)<1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS5.getStatus(),true);
	CPPUNIT_ASSERT_EQUAL(LS5.getNameOfMethod(),(string)"CGS");

	LinearSolver LS6(A,B,500,1.E-10,"BICG","LU");
    X3=LS6.solve();
	CPPUNIT_ASSERT(abs(X3(0)-Xana(0))<1.E-10);
	CPPUNIT_ASSERT(abs(X3(1)-2.)<1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS6.getStatus(),true);
	CPPUNIT_ASSERT_EQUAL(LS6.getNameOfMethod(),(string)"BICG");
	CPPUNIT_ASSERT_EQUAL(LS6.getNameOfPc(),(string)"LU");

	LinearSolver LS7(A,B,500,1.E-10,"GCR");
    X3=LS7.solve();
	CPPUNIT_ASSERT(abs(X3(0)-Xana(0))<1.E-10);
	CPPUNIT_ASSERT(abs(X3(1)-2.)<1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS7.getStatus(),true);
	CPPUNIT_ASSERT_EQUAL(LS7.getNameOfMethod(),(string)"GCR");

	LinearSolver LS8(A,B,500,1.E-10,"LSQR");
    X3=LS8.solve();
	CPPUNIT_ASSERT(abs(X3(0)-Xana(0))<1.E-10);
	CPPUNIT_ASSERT(abs(X3(1)-2.)<1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS8.getStatus(),true);
	CPPUNIT_ASSERT_EQUAL(LS8.getNameOfMethod(),(string)"LSQR");

	LinearSolver LS9(A,B,500,1.E-10,"CHOLESKY");
    X3=LS9.solve();
	CPPUNIT_ASSERT(abs(X3(0)-Xana(0))<1.E-10);
	CPPUNIT_ASSERT(abs(X3(1)-2.)<1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS9.getStatus(),true);
	CPPUNIT_ASSERT_EQUAL(LS9.getNameOfMethod(),(string)"CHOLESKY");

	LinearSolver LS10(A,B,500,1.E-10,"LU");
    X3=LS10.solve();
	CPPUNIT_ASSERT(abs(X3(0)-Xana(0))<1.E-10);
	CPPUNIT_ASSERT(abs(X3(1)-2.)<1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS10.getStatus(),true);
	CPPUNIT_ASSERT_EQUAL(LS10.getNameOfMethod(),(string)"LU");

	Matrix A2(6,6,14);
    A2(0,0)=2.;
    A2(0,1)=-1.;

    A2(1,0)=-1.;
    A2(1,1)=2.;
    A2(1,2)=-1.;

    A2(2,1)=-1.;
    A2(2,2)=2.;
    A2(2,3)=-1.;

    A2(3,2)=-1.;
    A2(3,3)=2.;
    A2(3,4)=-1.;

    A2(4,3)=-1.;
    A2(4,4)=2.;
    A2(4,5)=-1.;

    A2(5,4)=-1.;
    A2(5,5)=2.;

    Vector Xana2(6);
    Xana2(0)=1.;
    Xana2(1)=2.;
    Xana2(2)=3.;
    Xana2(3)=4.;
    Xana2(4)=5.;
    Xana2(5)=6.;

    Vector B2=A2*Xana2;

    LinearSolver LS11(A2,B2,500,1.E-10,"GMRES","ILU");
    Vector X11=LS11.solve();
    for (int i=0;i<X11.getNumberOfRows();i++)
    	CPPUNIT_ASSERT(abs(X11(i)-Xana2(i))<1.E-10);

	CPPUNIT_ASSERT_EQUAL(LS11.getStatus(),true);

	CPPUNIT_ASSERT_EQUAL(LS11.getNumberMaxOfIter(),500);
	CPPUNIT_ASSERT_EQUAL(LS11.getTolerance(),1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS11.getNumberOfIter(),1);

    LinearSolver LS12(A2,B2,500,1.E-10,"CG","ILU");
    Vector X12=LS12.solve();
    for (int i=0;i<X12.getNumberOfRows();i++)
    	CPPUNIT_ASSERT(abs(X12(i)-Xana2(i))<1.E-10);

	CPPUNIT_ASSERT_EQUAL(LS12.getStatus(),true);

	CPPUNIT_ASSERT_EQUAL(LS12.getNumberMaxOfIter(),500);
	CPPUNIT_ASSERT_EQUAL(LS12.getTolerance(),1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS12.getNumberOfIter(),1);

    LinearSolver LS13(A2,B2,500,1.E-10,"LGMRES","ILU");
    Vector X13=LS13.solve();
    for (int i=0;i<X13.getNumberOfRows();i++)
    	CPPUNIT_ASSERT(abs(X13(i)-Xana2(i))<1.E-10);

	CPPUNIT_ASSERT_EQUAL(LS13.getStatus(),true);

	CPPUNIT_ASSERT_EQUAL(LS13.getNumberMaxOfIter(),500);
	CPPUNIT_ASSERT_EQUAL(LS13.getTolerance(),1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS13.getNumberOfIter(),1);

    LinearSolver LS14(A2,B2,500,1.E-10,"BCG","ILU");
    Vector X14=LS14.solve();
	CPPUNIT_ASSERT_EQUAL(LS14.getStatus(),true);

	for (int i=0;i<X14.getNumberOfRows();i++)
    	CPPUNIT_ASSERT(abs(X14(i)-Xana2(i))<1.E-10);

	CPPUNIT_ASSERT_EQUAL(LS14.getNumberMaxOfIter(),500);
	CPPUNIT_ASSERT_EQUAL(LS14.getTolerance(),1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS14.getNumberOfIter(),1);

    LinearSolver LS15(A2,B2,500,1.E-10,"CR","ILU");
    Vector X15=LS15.solve();
	CPPUNIT_ASSERT_EQUAL(LS15.getStatus(),true);

	for (int i=0;i<X15.getNumberOfRows();i++)
    	CPPUNIT_ASSERT(abs(X15(i)-Xana2(i))<1.E-10);

	CPPUNIT_ASSERT_EQUAL(LS15.getNumberMaxOfIter(),500);
	CPPUNIT_ASSERT_EQUAL(LS15.getTolerance(),1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS15.getNumberOfIter(),1);

    LinearSolver LS16(A2,B2,500,1.E-10,"CGS","ILU");
    Vector X16=LS16.solve();
	CPPUNIT_ASSERT_EQUAL(LS16.getStatus(),true);

	for (int i=0;i<X16.getNumberOfRows();i++)
    	CPPUNIT_ASSERT(abs(X16(i)-Xana2(i))<1.E-10);

	CPPUNIT_ASSERT_EQUAL(LS16.getNumberMaxOfIter(),500);
	CPPUNIT_ASSERT_EQUAL(LS16.getTolerance(),1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS16.getNumberOfIter(),1);

    LinearSolver LS17(A2,B2,500,1.E-10,"BICG","ILU");
    Vector X17=LS17.solve();
	CPPUNIT_ASSERT_EQUAL(LS17.getStatus(),true);

	for (int i=0;i<X17.getNumberOfRows();i++)
    	CPPUNIT_ASSERT(abs(X17(i)-Xana2(i))<1.E-10);

	CPPUNIT_ASSERT_EQUAL(LS17.getNumberMaxOfIter(),500);
	CPPUNIT_ASSERT_EQUAL(LS17.getTolerance(),1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS17.getNumberOfIter(),1);

    LinearSolver LS18(A2,B2,500,1.E-10,"GCR","ILU");
    Vector X18=LS18.solve();
	CPPUNIT_ASSERT_EQUAL(LS18.getStatus(),true);

	for (int i=0;i<X18.getNumberOfRows();i++)
    	CPPUNIT_ASSERT(abs(X18(i)-Xana2(i))<1.E-10);

	CPPUNIT_ASSERT_EQUAL(LS18.getNumberMaxOfIter(),500);
	CPPUNIT_ASSERT_EQUAL(LS18.getTolerance(),1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS18.getNumberOfIter(),1);

    LinearSolver LS19(A2,B2,500,1.E-10,"LSQR","ILU");
    Vector X19=LS19.solve();
	CPPUNIT_ASSERT_EQUAL(LS19.getStatus(),true);

	for (int i=0;i<X19.getNumberOfRows();i++)
    	CPPUNIT_ASSERT(abs(X19(i)-Xana2(i))<1.E-10);

	CPPUNIT_ASSERT_EQUAL(LS19.getNumberMaxOfIter(),500);
	CPPUNIT_ASSERT_EQUAL(LS19.getTolerance(),1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS19.getNumberOfIter(),6);

    LinearSolver LS20(A2,B2,500,1.E-10,"CHOLESKY","ILU");
    Vector X20=LS20.solve();
	CPPUNIT_ASSERT_EQUAL(LS20.getStatus(),true);

	for (int i=0;i<X20.getNumberOfRows();i++)
    	CPPUNIT_ASSERT(abs(X20(i)-Xana2(i))<1.E-10);

	CPPUNIT_ASSERT_EQUAL(LS20.getNumberMaxOfIter(),500);
	CPPUNIT_ASSERT_EQUAL(LS20.getTolerance(),1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS20.getNumberOfIter(),1);

    LinearSolver LS21(A2,B2,500,1.E-10,"LU","ILU");
    Vector X21=LS21.solve();
	CPPUNIT_ASSERT_EQUAL(LS21.getStatus(),true);

	for (int i=0;i<X21.getNumberOfRows();i++)
    	CPPUNIT_ASSERT(abs(X21(i)-Xana2(i))<1.E-10);

	CPPUNIT_ASSERT_EQUAL(LS21.getNumberMaxOfIter(),500);
	CPPUNIT_ASSERT_EQUAL(LS21.getTolerance(),1.E-10);
	CPPUNIT_ASSERT_EQUAL(LS21.getNumberOfIter(),1);
}
