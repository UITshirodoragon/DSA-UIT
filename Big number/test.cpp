#include <iostream>
#include <cmath>

using namespace std;

struct PHANSO
{
    int tu, mau;
};

// bổ trợ
int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (a*b != 0) {
        if(a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;

}

int lcm(int a, int b)
{
    a = abs(a);
    b = abs(b);
    return (a * b) / gcd(a, b);

}

void RutGonPS(PHANSO &a)
{
    if(a.mau < 0)
    {
        a.tu *= -1;
        a.mau *= -1;
    }
    int temp = gcd(a.tu, a.mau);
    a.tu /= temp;
    a.mau /= temp;
}

void nhapPS(PHANSO &a)
{
    cin >> a.tu >> a.mau;
}

void xuatPS(PHANSO a)
{
    if(a.tu == 0)
    {
        cout << 0 << endl;
    }
    else if(a.tu % a.mau == 0)
    {
        cout << a.tu / a.mau << endl;
    }
    else
    {   
        cout << a.tu << "/" << a.mau << endl; 
    }
}

PHANSO SoSanhPS(PHANSO a, PHANSO b)
{
    double GiaTri_a = (double) a.tu/ a.mau;
    double GiaTri_b = (double) b.tu/ b.mau;
    if(GiaTri_a >= GiaTri_b)
        return a;
    else
        return b;
}

PHANSO TinhHieuPS(PHANSO a, PHANSO b)
{
    PHANSO hieu;
    hieu.tu = a.tu * b.mau - a.mau * b.tu;
    hieu.mau = a.mau * b.mau;
    RutGonPS(hieu);
    return hieu;
}

PHANSO TinhTongPS(PHANSO a, PHANSO b)
{
    PHANSO tong;
    tong.tu = a.tu * b.mau + a.mau * b.tu;
    tong.mau = a.mau * b.mau;
    RutGonPS(tong);
    return tong;
}

PHANSO TinhTichPS(PHANSO a, PHANSO b)
{
    PHANSO tich;
    tich.tu = a.tu * b.tu;
    tich.mau = a.mau * b.mau;
    RutGonPS(tich);
    return tich;
}

PHANSO TinhThuongPS(PHANSO a, PHANSO b)
{
    PHANSO thuong;
    
    thuong.tu = a.tu * b.mau;
    thuong.mau = a.mau * b.tu;
    RutGonPS(thuong);
    return thuong;
}

int main()
{
    PHANSO a, b;

    nhapPS(a);
    nhapPS(b);

    RutGonPS(a);
    RutGonPS(b);

    xuatPS(SoSanhPS(a,b));
    xuatPS(TinhTongPS(a,b));
    xuatPS(TinhHieuPS(a,b));
    xuatPS(TinhTichPS(a,b));
    xuatPS(TinhThuongPS(a,b));
    system("pause");
    return 0;
}