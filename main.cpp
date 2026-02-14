#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int apartine(vector<int> v, int marime, int n)
{
    for(int i =  0; i < marime; i++)
    {
        if(n == v[i])
            return 1;
    }
    return 0;
}

int main()
{
    int C, D, n;
    bool prime;
    ifstream in("dans.in");
    ofstream out("dans.out");
    in >> C >> n >> D;
    vector<int> V(n);

    for(int &i : V)
        in >> i;
    if(C == 1)
    {
        int a, p = 0;
        for(int i : V)
        {
            prime = true;
            a = i + D;
            for(int j = 2; j < a; j++)
            {
                if(a % j == 0)
                    prime = false;
            }
            if(prime)
                p++;
        }
        //cout << p;
        out << p;
    }
    if(C == 2)
    {
        int itemp, Dtemp = D, uc, k = 0, r = 0;
        while(Dtemp > 0)
        {
            k++;
            Dtemp = Dtemp / 10;
        }
        Dtemp = D;
        vector<int> CifD(k);
        for(int i = 0; i < k; i++)
        {
            CifD[i] = Dtemp % 10;
            Dtemp = Dtemp / 10;
        }
        for(int i : V)
        {
            itemp = i;
            while(itemp > 0)
            {
                uc = itemp % 10;
                if(apartine(CifD, k, uc) == 1)
                    r++;


                itemp = itemp / 10;
            }
        }

        //cout << r;
        out << r;
    }
    return 0;
}
