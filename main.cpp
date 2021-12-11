#include <iostream>
#include<string>
#include <fstream>
#include<vector>
using namespace std;

class Table{
public:
    vector <vector <string> > tab;
    int col,str=0;
    int zag1[100];
    string zag[100];
    virtual void newst()=0;
    void delst();
    void show();
    void out();

};
void Table::delst()
{
    int n,k;
    cout << endl << "Enter num" << endl;
    cin >> n;
    n--;
    while (n <= str-1)
    {
        for (int j = 0; j < col; j++)
            tab[n][j] = tab[n + 1][j];
        n++;
    }
    str--;
}
void Table::show()
{
    string h="";
    int k=0;
    for (int i = 0; i <= col; i++)
    {
        for (k = zag[i].size(); k <= zag1[i]; k++)
        {
            cout << " ";
            h = h + "-";
        }
        for (int j = 0; j < zag[i].size(); j++)
            h = h + "-";
        cout << zag[i] << " | ";
        h = h + "---";
    }
    cout<<endl<<h<<endl;
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            for (k = tab[i][j].size(); k <= zag1[j]; k++)
            {
                cout << " ";
            }

            cout << tab[i][j]<<" | ";
        }
        cout << endl << h << endl;
    }
}
class Students: public Table
{
   public:
    void newst();
    Students();
};
Students::Students()
{
    zag[0]="ID";zag1[0]=4;
    zag[1]="Name";zag1[1]=20;
    zag[2]="Surname";zag1[2]=20;
    zag[3]="Otchestvo";zag1[3]=20;
    zag[4]="Age";zag1[4]=3;
    zag[5]="Class";zag1[5]=3;
    ifstream fin;
    col=6;
    int i = 0;
    string a;
    fin.open("students.txt");
    while (!fin.eof())
    {
        vector <string> vec;
        for(int j=0;j<6;j++)
        {
            fin>>a;
            //cout<<a<<" "<<a.size()<<endl;
            vec.push_back(a);

        }
        tab.push_back(vec);
        i++;
    }
    fin.close();
    col = 5;
    str = i;
}
void Students::newst()
{
    vector <string> vec;
    string a;
    cout<<"name"<<endl;
    for(int j=0;j<5;j++)
    {
        cin>>a;
        vec.push_back(a);
    }
    tab.push_back(vec);
    str++;
}
class Subjects: public Table
{
   public:
    void newst();
    Subjects();
};
Subjects::Subjects()
{
    zag[0]="ID";zag1[0]=7;
    zag[1]="Subject";zag1[1]=20;
    ifstream fin;
    col=2;
    int i = 0;
    string a;
    fin.open("subjects.txt");
    while (!fin.eof())
    {
        vector <string> vec;
        for(int j=0;j<2;j++)
        {
            fin>>a;
            vec.push_back(a);

        }
        tab.push_back(vec);
        i++;
    }
    fin.close();
    col = 1;
    str = i;
}
void Subjects::newst()
{
    vector <string> vec;
    string a;
    //cout<<"sub"<<endl;
    for(int j=0;j<2;j++)
    {
        cin>>a;
        vec.push_back(a);
    }
    tab.push_back(vec);
    str++;
}

class Marks: public Table
{
   public:
    void newst();
    Marks();
};
Marks::Marks()
{
    zag[0]="ID";zag1[0]=7;
    zag[1]="Subject";zag1[1]=7;
    zag[2]="Student";zag1[2]=7;
    zag[3]="Mark";zag1[3]=7;
    ifstream fin;
    col=5;
    int i = 0;
    string a;
    fin.open("marks.txt");
    while (!fin.eof())
    {
        vector <string> vec;
        for(int j=0;j<4;j++)
        {
            fin>>a;
            vec.push_back(a);

        }
        tab.push_back(vec);
        i++;
    }
    fin.close();
    col = 3;
    str = i;
}
void Marks::newst()
{
    vector <string> vec;
    string a;
    for(int j=0;j<4;j++)
    {
        vec.push_back(a);
    }
    tab.push_back(vec);
    str++;
}
void Table::out()
{
    ofstream file;
    file.open("output.txt");
    string h="";
    int k=0;
    for (int i = 0; i <= col; i++)
    {
        for (k = zag[i].size(); k <= zag1[i]; k++)
        {
            file << " ";
            h = h + "-";
        }
        for (int j = 0; j < zag[i].size(); j++)
            h = h + "-";
        file << zag[i] << " | ";
        h = h + "---";
    }
    file<<endl<<h<<endl;
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            for (k = tab[i][j].size(); k <= zag1[j]; k++)
            {
                file << " ";
            }

            file << tab[i][j]<<" | ";
        }
        file << endl << h << endl;
    }

}

int main()
{
    Students n;
    Subjects w;
    Marks a;
    n.show();
    w.show();
    a.show();
    n.out();
}

/*
class TSt {
public:
    string pupils[100][10];
    string zag[10];
    //vector<vector<string>> pupils;
    int zag1[10];
    int col, str;
    void newst();
    void delst();
    void show();
    void showall();
    void newcol();
    void delcol();
    TSt();
};
TSt::TSt()
{
    ifstream Fin;
    int i = 1;
    Fin.open("students.txt");
    string a, b = "";
    zag[0] = "FIO";
    zag[1] = "AGE";
    zag[2] = "Class";
    zag1[0] = 35;
    zag1[1] = 5;
    zag1[2] = 5;
    while (!Fin.eof())
    {
        b = "";
        //cout<<i;
        Fin >> a;
        b = b + " " + a;
        Fin >> a;
        b = b + " " + a;
        Fin >> a;
        b = b + " " + a;
        //cout<<b;
        pupils[i][0] = b;
        Fin >> pupils[i][1];
        Fin >> pupils[i][2];
        i++;
    }
    Fin.close();
    col = 3;
    str = i-1;
}
protected
void TSt::newst()
{
    string st,b,a;
    cout << endl << "Enter FIO" << endl; ;
    cin >> a;
    b = b + " " + a;
    cin >> a;
    b = b + " " + a;
    cin >> a;
    b = b + " " + a;
    pupils[str][0] = b;
    for (int k = 1; k < col; k++)
    {
        cout << endl << "Enter " << zag[k] << endl;
        cin >> st;
        pupils[str][k] = st;
    }
    str++;
}
void TSt::delst()
{
    int n,k;
    cout << endl << "Enter num" << endl;
    cin >> n;
    while (n <= str)
    {
        for (int j = 0; j < col; j++)
            pupils[n][j] = pupils[n + 1][j];
        n++;
        str--;
    }
}
void TSt::show()
{
    int n;
    cin >> n;
    for (int i = 0; i < col; i++)
    {
        for (int k = zag[i].size(); k <= zag1[i]; k++)
        {
            cout << " ";
        }
        cout << zag[i] << " | ";
    }
    cout << endl;
    for (int i = 0; i <col; i++)
    {
        for (int k = pupils[n][i].size(); k <= zag1[i]; k++)
                cout << " ";
            cout << pupils[n][i] << " | ";

    }
    cout << endl;

}
void TSt::newcol()
{
    cout << "enter name of columns" << endl;
    string nc,b;
    int i,t,a;
    cin >> nc;
    zag[col] = nc;

    cout << "enter kletocki" << endl;
    cin >> i;
    cout << "if if" << endl;
    cin >> t;
    zag1[col] = i;

    if (t == 1)
    {
        for (int j = 1; j <= str; j++)
        {
            cout << "For " << pupils[j][0] << endl;
            cin >> a;
            pupils[j][col] = a;
        }
    }
    if (t == 2)
    {
        for (int j = 1; j <= str; j++)
        {
            cout << "For " << pupils[j][0] << endl;
            cin >> b;
            pupils[j][col] = b;
        }

    }
    col++;
}
void TSt::delcol()
{
    int n, k;
    cout << endl << "Enter num" << endl;
    cin >> n;
    n--;
    while (n < col-1)
    {
        zag[n] = zag[n + 1];
        zag1[n] = zag1[n + 1];
        for (int j = 1; j <= str; j++)
            pupils[j][n] = pupils[j][n+1];
        n++;

    }
    col--;
}

int main()
{
    int a = 5;
    TSt M;
    M.showall();
    //M.newst();
    M.delcol();
    //M.delst();
    M.showall();
}*/
