//Bài tập Ứng dụng kỹ thuật lập trình hướng đối tượng để:
//Thiết lập lớp PhanSo để biểu diễn khái niệm phân số với hai thành phần dữ liệu tử số, mẫu số và các hàm thành phần cộng, trừ, nhân, chia hai phân số,
//các hàm thành phần xuất, nhập, định giá trị cho phân số. Viết chương trình cho phép nhập vào hai phân số, in ra kết quả các phép toán cộng, trừ, nhân, 
//chia hai phân số kể trên
/*#include "iostream"

using namespace std;
#include "math.h"

class PhanSo
{
private:
    int tuso;
    int mauso;
public:
    void Input(){
        cout << "\nNhap Vao Tu So:";
        cin >> tuso;
        cout << "\nNhap Vao Mau So:";
        cin >> mauso;
    }
    void RutGon(){
        int ucln;
        int a= abs(tuso);
        int b= abs(mauso);
        while (a != b)
        {
            if(a > b){
                a= a-b;
            }else if(b > a){
                b= b - a;
            }
        }
        ucln=b;
        tuso= tuso/ucln;
        mauso=mauso/ucln;
    }
    PhanSo Cong(PhanSo a, PhanSo b){
        PhanSo cong;
        cong.tuso=a.tuso*b.mauso+a.mauso*b.tuso;
        cong.mauso=a.mauso*b.mauso;
        cong.RutGon();
        return cong;
    }
    PhanSo Tru(PhanSo a, PhanSo b){
        PhanSo tru;
        tru.tuso=a.tuso*b.mauso-a.mauso*b.tuso;
        tru.mauso=a.mauso*b.mauso;
        tru.RutGon();
        return tru;
    }
    PhanSo Nhan(PhanSo a, PhanSo b){
        PhanSo nhan;
        nhan.tuso=a.tuso*b.tuso;
        nhan.mauso=a.mauso*b.mauso;
        nhan.RutGon();
        return nhan;
    }
    PhanSo Chia(PhanSo a, PhanSo b){
        PhanSo chia;
        chia.tuso=a.tuso*b.mauso;
        chia.mauso=a.mauso*b.tuso;
        chia.RutGon();
        return chia;
    }
    void Output(){
        cout << tuso << "/"<<mauso;
    }
};
int main(){
    PhanSo a;
    a.Input();
    PhanSo b;
    b.Input();
    cout << "\nTong:";
    PhanSo c=c.Cong(a,b);
    c.Output();
    cout << "\nHieu:";
    c=c.Tru(a,b);
    c.Output();
    cout << "\nTich:";
    c=c.Nhan(a,b);
    c.Output();
    cout << "\nThuong:";
    c=c.Chia(a,b);
    c.Output();
    return 0;
}*/
#include "iostream"
using namespace std;
#include "string.h"

class DocGia{
protected:
    string hoten;
    string ngaylapthe;
    int thangcohieuluc;
public:
    void NhapThongTin(){
        fflush(stdin);
        cout << "\nNhap Ho Ten:";
        getline(cin, hoten);
        fflush(stdin);
        cout<< "\nNhap Ngay Lap The:";
        getline(cin, ngaylapthe);
        fflush(stdin);
        cout<< "\nNhap So Thang Co Hieu Luc:";
        cin >> thangcohieuluc;
        fflush(stdin);
    }
    void XuatThongTin(){
        cout << "\nHo Ten:"<<hoten;
        cout << "\nNgay Lap The:"<< ngaylapthe;
        cout << "\nSo Thang Co Hieu Luc:"<<thangcohieuluc;
    }
};
class TreEm:public DocGia{
private:
    string hotennguoidaidien;
public:
    void NhapTreEm(){
        DocGia::NhapThongTin();
        cout << "\nNhap Ho Ten Nguoi Dai Dien:";
        getline(cin,hotennguoidaidien);
        fflush(stdin);
    }
    float tienlamthe(){
        return thangcohieuluc*5000;
    }
    void XuatTreEm(){
        DocGia::XuatThongTin();
        cout<< "\nHo Ten Nguoi Dai Dien:"<<hotennguoidaidien;
        cout<< "\nTien Lam The:"<<tienlamthe();
    }
};
class NguoiLon:public DocGia{
private:
    string soCMND;
public:
    void NhapNguoiLon(){
        DocGia::NhapThongTin();
        cout<< "\nNhap So CMND:";
        getline(cin,soCMND);
        fflush(stdin);
    }
    float tienlamthe(){
        return thangcohieuluc*10000;
    }
    void XuatNguoiLon(){
        DocGia::XuatThongTin();
        cout<< "\nSo CMND:"<<soCMND;
        cout << "\nTien Lam The:"<<tienlamthe();
    }
};
void Menu(TreEm *ds_treEm[],NguoiLon *ds_nguoiLon[], int n, int m){
    int luachon;
    while(true){
        system("cls");
        cout<< "\n===================MENU==================";
        cout << "\n1.NHAP THONG TIN DOC GIA TRE EM";
        cout << "\n2.NHAP THONG TIN DOC GIA NGUOI LON";
        cout << "\n3.HIEN THI THONG TIN DOC GIA TRE EM";
        cout << "\n4.HIEN THI THONG TIN DOC GIA NGUOI LON";
        cout << "\n5.TONG TIEN LAM THE";
        cout << "\n0.KET THUC";
        cout << "\nNHAP LUA CHON:";
        cin>> luachon;
        system("cls");
        if(luachon<0||luachon>5){
            cout<< "\nNHAP SAI. VUI LONG NHAP LAI";
        }
        else if(luachon==0){
            for(int i=0;i<n;i++){
                delete ds_treEm[i];
            }
            for(int i=0;i<m;i++){
                delete ds_nguoiLon[i];
            }
            break;
        }
        else if(luachon==1){
            TreEm *a=new TreEm();
            cout<< "\nNHAP THONG TIN";
            a->NhapTreEm();
            ds_treEm[n]=a;
            n++;
            }
        else if(luachon==2){
            NguoiLon *a=new NguoiLon();
            a->NhapNguoiLon();
            ds_nguoiLon[m]=a;
            m++;
        }
        else if(luachon==3){
            for(int i=0;i<n;i++){
                cout<< "\nNGUOI THUE THU "<<i+1;
                ds_treEm[i]->XuatTreEm();
            }
            system("pause");
        }
        else if(luachon==4){
            for(int i=0;i<m;i++){
                cout<< "\nNGUOI THUE THU "<<i+1;
                ds_nguoiLon[i]->XuatNguoiLon();
            }
            system("pause");
        }
        else if(luachon==5){
            float a=0,b=0;
            for(int i=0;i<n;i++){
                a=a+ds_treEm[i]->tienlamthe();
            }
            for(int i=0;i<n;i++){
                b=b+ds_nguoiLon[i]->tienlamthe();
            }
            cout << "\nTONG TIEN LAM THE:"<< size_t(a+b);
            system("pause");
        }
    }
}

int main(){
    TreEm *ds_treEm[100];
    NguoiLon *ds_nguoiLon[100];
    int n=0,m=0;
    Menu(ds_treEm,ds_nguoiLon,n,m);
}
















