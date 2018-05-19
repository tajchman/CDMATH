import cdmath
import FiniteVolumes3DWithCDMATH
import matplotlib.pyplot as plt
import numpy as np
from math import log10

def test_validation3DVF_ns():
    #### 3D FV tetrahedra mesh
    nbMeshes=7
    error_tab=[0]*nbMeshes
    mesh_size_tab=[0]*nbMeshes
    mesh_path='../validation/3DTetrahedra/'
    mesh_name='meshCubeWithTetrahedra3DFV'
    i=0
    # Computation of the numerical error
    for filename in ['meshCubeTetrahedra_0','meshCubeTetrahedra_1','meshCubeTetrahedra_2','meshCubeTetrahedra_3','meshCubeTetrahedra_4','meshCubeTetrahedra_5','meshCubeTetrahedra_6']:
        error_tab[i], mesh_size_tab[i] =FiniteVolumes3DWithCDMATH.solve_file(mesh_path+filename)
        error_tab[i]=log10(error_tab[i])
        mesh_size_tab[i] = log10(mesh_size_tab[i])
        i=i+1
        
    # Least square linear regression
    # Find the best a,b such that f(x)=ax+b best approximates the convergence curve
    # The vector X=(a,b) solves a symmetric linear system AX=B with A=(a1,a2\\a2,a3), B=(b1,b2)
    a1=np.dot(mesh_size_tab,mesh_size_tab)
    a2=np.sum(mesh_size_tab)
    a3=nbMeshes
    b1=np.dot(error_tab,mesh_size_tab)   
    b2=np.sum(error_tab)
    
    det=a1*a3-a2*a2
    assert det!=0, 'test_validation3DVF_ns() : Make sure you use distinct meshes'
    a=( a3*b1-a2*b2)/det
    b=(-a2*b1+a1*b2)/det
    
    print "FV on 3D tetrahedral mesh : scheme order is ", -a
    assert abs(a+0.27)<0.1
    
    # Plot of figures
    plt.plot(mesh_size_tab, error_tab, label='log(|numerical-exact|)')
    plt.plot(mesh_size_tab, a*np.array(mesh_size_tab)+b,label='least square slope : '+'%.3f' % a)
    plt.legend()
    plt.xlabel('log(number of nodes)')
    plt.ylabel('log(error)')
    plt.title('Convergence of finite volumes for Laplace operator on a 3D tetrahedral mesh')
    plt.savefig(mesh_name+".png")

if __name__ == """__main__""":
    test_validation3DVF_ns()
