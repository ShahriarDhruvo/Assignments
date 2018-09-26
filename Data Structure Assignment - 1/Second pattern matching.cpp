#include <iostream>
#include <cstring>

using namespace std;

void preKMP(string patr, int f[])
{
    int m = patr.length(), chk;
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        chk = f[i - 1];
        while (chk >= 0)
        {
            if (patr[chk] == patr[i - 1])
                break;
            else
                chk = f[chk];
        }
        f[i] = chk + 1;
    }
}
bool KMP(string patr, string targ)
{
    int m = patr.length();
    int n = targ.length();
    int f[m];
    preKMP(patr, f);
    int i = 0;
    int chk = 0;
    while (i < n)
    {
        if (chk == -1)
        {
            i++;
            chk = 0;
        }
        else if (targ[i] == patr[chk])
        {
            i++;
            chk++;
            if (chk == m)
                return 1;
        }
        else
            chk = f[chk];
    }
    return 0;
}

int main()
{
    string tar,pat;
    cout << "Enter the string: ";
    cin >> tar;
    cout << "Enter the substring you want to find: " ;
    cin >> pat;
    if (KMP(pat, tar))
        cout<<"'"<<pat<<"' found in string '"<<tar<<"'"<<endl;
    else
        cout<<"'"<<pat<<"' not found in string '"<<tar<<"'"<<endl;
}
