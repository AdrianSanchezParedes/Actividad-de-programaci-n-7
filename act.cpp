/***********************************presentacion******************************
Nombre: Victor Eduardo Macias Macias
Fecha: 1/03/2022
programa: Actividad de programacion 7.
Centro Universitario de los Altos/ UNIVERSIDAD DE GUADALAJARA/ INGENIRÍA EN COMPUTACIÓN/ 2DO SEMESTRE
Profesor: Sergio Franco Casillas
*****************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
int r,i,n,z=1, x=0, res=0,e,a=0,j, temp;
vector <int> v;
//definicion
void mostrar()
{
  for(i=0;i<v.size();i++)
    {
        cout << v[i] << " ";
    }
    cout<<" \n";
}
void llenado()
{
  cout<<"ingresa el grado de la matriz: ";
  cin>>n;
  cout<<"ingresa el valor maximo del limite: ";
  cin>>x;
    for(i=0;i<n;i++)
    {
      v.push_back(1 + rand() % x);
    }
  mostrar();
}
void manual()
{
  cout<<"\n cuantos elementos quieres agregar?: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
      cout<<"escribe: ";
      cin>>x;
      v.push_back(x);
    }
  mostrar();
}
void borrar()
{
  cout<<"\n que elemento queires eliminar?: \n";
      cin>>i;
    v.erase(v.begin()+i);
  mostrar();
}
void operar()
{
  cout<<"Elige, 1 para sumar y mult | 2 para max, min, promedio: \n";
  cin>>r;
  if (r==1)
  {
    for(i=0;i<v.size();i++)
    {
      res += v[i];
      z = z * v[i];
    }
  cout<<"\nla suma es: "<< res;
  cout<<"\nla mult es: "<<z<<"\n";
    }
else if(r==2)
{
  for(i=0;i<n;i++)
    {
      if(x < v[i])
      {
        x=v[i];
      }
    }
    a = x;
    for(i=0;i<n;i++)
    {
      e += v[i];
    if (a > v[i])
    {
       a = v[i];
    }
    }
    cout<<"\npromedio: "<<e/n<<"\n";
    cout<<"\nEl mayor es: "<< x <<"\n el menor es: "<<a <<"\n";
}
}///fin
void burbuja()
{
  for(i=0;i<v.size();i++)
    {
      for(j = i+1; j < v.size();j++)
        {
          if (v[i]>v[j])
          {
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
          }
        }
    }
  mostrar();
}//fin

void quick(vector <int> &v, int beg, int fin)
{
  
}
int main()//inicio
{
  inicio:
  cout<<"\n ingresa la opcion deseada: \n 1: para ingresar elementos aleatorios \n 2: ingresar numeros manualmente \n 3: mostrar vector\n 4: borrar elementos del vector \n 5: realizar operaciones \n 6: implementar algoritmos \n 7: busqueda binaria\n ";
  cin>>r;
  switch(r)
  {
    case 1:
      llenado();
      goto inicio;
    break;//fin
    case 2:
      manual();
      goto inicio;
    break;//fin
    case 3:
      mostrar();
      goto inicio;
    break;//fin
    case 4:
      borrar();
      goto inicio;
    break;//fin
    case 5:
    operar();
    goto inicio;
    break;//fin
    case 6:
      cout<<"ingresa 1 para el metodo burbuja | 2 para metodo quick sort: ";
      cin >> e;
      if (e==1)
      {
      burbuja();
    goto inicio;
      }
      else
        
      goto inicio;
    break;//fin
    case 7:
      goto inicio;
    break;//fin
    default:
      goto inicio;
    break;//fin
  }
}
