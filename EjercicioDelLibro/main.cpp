#include <iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
void t();
string tuva (string ti);
int tauva (int ta);
double totaluva (string ti,int ta,double p,int k );
double precio (double p);
int kilos (int k);
int main()
{
    string tipo;
    int taman=0,kx=0;
    double preciou=0;
    t();
    tipo=tuva(tipo);
    taman=tauva(taman);
    preciou=precio(preciou);
    kx=kilos (kx);
    cout << " La Ganancia es: "<<totaluva(tipo,taman,preciou,kx)<<endl;
    system ("pause");
    return 0;
}
void t ()
{
    cout<<setw(20)<<"VENICULTORES"<<endl;
    cout<<setw(20)<<"-------------------------"<<endl;
}
double precio(double p)
{
    ofstream datos ("vinos.txt",ios::out|ios::app);
    cout<<"-Ingrese el precio:";
    cin>>p;
    while (p<0)
    {
        cout <<setw(40)<<"Ingrese numeros mayores a 0"<<endl;
        cout<<"-Ingrese el precio:";
        cin>>p;
    }
    datos<<"Precio:"<<p<<" ";
    datos.close();
    return p;
}
int kilos(int k)
{
    ofstream datos ("vinos.txt",ios::out|ios::app);
    cout<<"-Ingrese los kilos:";
    cin>>k;
    while (k<0)
    {
        cout <<setw(40)<<"Ingrese numeros mayores a 0"<<endl;
        cout<<"-Ingrese el precio:";
        cin>>k;
    }
    datos<<"Kilos:"<<k<<" ";
    datos.close();
    return k;
}
string tuva(string ti)
{
    ofstream datos ("vinos.txt",ios::out|ios::app);
    cout<<"-Ingrese el tipo de uva (A o B):";
    getline(cin,ti);
    while (ti !="A"&& ti !="B")
    {
        cout<<" No existe la opcion"<<endl;
        cout<<"-Ingrese el tipo de uva (A o B):";
        getline (cin,ti);
    }
    datos<<"Tipo:"<<ti<<" ";
    datos.close();
    return ti;
}
int tauva (int ta)
{
    ofstream datos ("vinos.txt",ios::out|ios::app);
    cout<<"-Ingrese el tamanio de la uva (1/2):";
    cin>>ta;
    while (ta !=1 && ta !=2)
    {
        cout <<setw(40)<<"No existe la opcion"<<endl;
        cout<<"-Ingrese el tamanio de la uva (1/2):";
        cin>>ta;
    }
    datos<<"Tamanio:"<<ta<<" ";
    datos.close();
    return ta;
}
double totaluva (string ti,int ta,double p,int k)
{
    ofstream datos ("vinos.txt",ios::out|ios::app);
    const float p1=0.2, p2=0.3, p3=0.5;
    float g=0;
    if(ti=="A")
    {
        if (ta==1)
        {
            p=p+p1;
        }
        else
        {
            if(ta==2)
            {
                p=p+p3;
            }
        }
    }
    else
    {
        if(ti=="B")
        {
            if(ta==1)
            {
                p=p-p2;
            }
            else
            {
                if (ta==2)
                {
                    p=p-p3;
                }
            }
        }
    }
    g=p*k;
    datos<<"Ganancias:"<<g<<" "<<endl;
    datos.close();
    return g;
}
