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
int r,i,n,z=1, x=0, res=0,e,a=0,j, temp, objective;
vector <int> v;
//definicion
void mostrar()
{
  for(i=0;i<v.size();i++)
    {
        cout << v[i] << " ";
    }
    cout<<" \n";
}//fin

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
}//fin

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
}//fin

void borrar()
{
  cout<<"\n que elemento queires eliminar?: \n";
      cin>>i;
    v.erase(v.begin()+i);
  mostrar();
}//fin

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
void swap(int &a,int &b){
    int aux = a;
    a = b;
    b = aux;
}//fin
int particion(vector<int>&v, int beg, int fin)
{
  temp = v[beg];
  int i = beg +1;
  for(int j = i; j <= fin; j++)
  {
    if (v[j] < temp)
    {
      swap(v[i], v[j]);
      i++;
    }
  }
  swap(v[beg], v[i-1]);
  return i-1;
}//fin
void quick(vector <int> &v, int beg, int fin)
{
  if(beg<fin)
  {
 temp = particion(v,beg,fin);
    quick(v,beg,temp-1);
    quick(v,temp+1,fin);
  }
}//fin
int binaria(vector<int>&v,int left, int right, int objective)
{
  if (right >= left)
  {
    int mid = left + (right - left) / 2;
    if (v[mid] == objective)
    {
      return mid;
    }
    if (v[mid] > objective)
    {
      return binaria(v,left,mid-1,objective);
    }
    return binaria(v, mid + 1, right, objective);
  }
   return -1;
}//fin

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
      else if(e==2)
      {
      quick(v,0,v.size()-1);
      mostrar();
      goto inicio;
      }
    break;//fin
    case 7:
      cout<<"Escribe el numero que quieres encontrar: \n";
      cin>>objective;
      res = binaria(v,0,v.size()-1, objective);
      if(res == -1)
      {
        cout<<"El elemento no se ha encontrado \n";
      }
      else {
        cout<<"El elemento se ha encontrado en la posicion: "<<res +1 <<endl;
      }
      goto inicio;
    break;//fin
    default:
      goto inicio;
    break;//fin
  }
}
