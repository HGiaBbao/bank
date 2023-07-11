/*
Mô tả: Chương trình C ++ trên HỆ THỐNG NGÂN HÀNG có lớp tài khoản với các dữ liệu thành viên như số tài khoản,
 tên, số tiền gửi, số tiền rút và loại tài khoản. Dữ liệu khách hàng được lưu trữ trong một tệp đuôi ".txt"  . Khách 
 hàng có thể nạp và rút số tiền trong tài khoản của mình. Người dùng có thể tạo, sửa đổi và xóa tài khoản.*/
 #include<iostream>
 #include<string>
 #include<cstdlib>
 #include<ctime>
 #include<cstring>
 #include<fstream>
 #include<unistd.h>
 using namespace std;
 class taiKhoan{
    private:
    
    string ten;
    int soTienGui;
    int soTienRut;
    int loaiTaiKhoan;
    int soTaiKhoanSau;
    int matkhau;
    int tienNap;
    
    public:
    void TaoTaiKhoan(){
        cout <<"Ten nguoi dung: ";
        cin >> ten;
        cout << "Nhap so tien muon nap : ";
        cin >>soTienGui;
        cout <<"Nhap mat khau (6 so) : ";
        cin >> matkhau;
        if(matkhau > 1000000 || matkhau <= 100000){
            cout <<"Mat khau khong duoc nho hon va lon hon 6 so!" <<endl;
            cout<<"Moi nhap lai mat khau :";
            cin >>matkhau;
        }
        cout << "Chon loai tai khoan : " << endl;
        cout << "1: Tai khoan thanh toan [tktt] " << endl;
        cout << "2:Tai khoan tiet kiem [tktk] " << endl;
        cout << "3:Tai khoan the tin dung [tkttd] " << endl;
        cout << "4:Tai khoan vay von [tkvv ]" << endl;
        cout << "Luu y: Viec chon loai tai khoan anh huong den quyen loi sau nay! " <<endl;
        cout << "Moi chon loai tai khoan :";
        cin >> loaiTaiKhoan;
        if (loaiTaiKhoan >=5)
        {
            cout<<"Phuong thuc nhap khong hop le!" << endl;
            cout <<"Bam y de thoat ra hoac p de thuc hien lai :";
            char chon2;
            cin >> chon2;
            switch (chon2)
            {
            case 'y':
            chucNang();
                break;
            case 'p':
            TaoTaiKhoan();
            break;

            default:
            cout<<"Chuong trinh bi loi!";
                break;
            }

        }
      
        
        cout <<"Tai khoan da duoc tao thanh cong!" <<endl;
        cout <<"Bam y de thoat ra hoac bam p de xem thong tin tai khoan!" << endl;
        char chon;
        cin >> chon;
        switch (chon)
        {
        case 'y':
        luu();
        chucNang();

            break;
        case 'p':
        xemtk();

        default:
            break;
        }



    }
    void xemtk(){
        cout <<"$--------------------------------$" <<endl;
        cout <<"Loai the:", dkt() ;
        cout <<"Nguoi dung : " << ten << endl;
        cout<<"So tien hien co : "<< soTienGui << endl;
        cout<<"Mat khau :" << matkhau << endl;
       

        
        cout <<"Bam y de thoat ra Hoac bam p de chinh sua :" << endl;
        char chon1;
        cin >> chon1;
        switch (chon1)
        {
        case 'y':
        luu();
        chucNang();
            break;
            case 'p':
            TaoTaiKhoan();
            break;
        
        default:
        cout <<"loi phep tinh!";
            break;
        }
    }
    void dkt(){
        if(loaiTaiKhoan == 1){
            cout<<"TAI KHOAN THANH TOAN" << endl;
        }
        else if(loaiTaiKhoan == 2){
            cout <<"TAI KHOAN TIET KIEM" << endl;
        }
        else if(loaiTaiKhoan == 3){
            cout <<"TAI KHOAN THE TIN DUNG" << endl;
        }
        else if(loaiTaiKhoan == 4){
            cout<<"TAI KHOAN VAY VON" << endl;
        }
        else{
            cout <<"dieu kien khong khop!" << endl;
        }

    }
    void chucNang(){
        cout<<"#--------------BankSystem-------------#"<<endl;
        cout<<"#1: Nap tien                          #"<<endl;
        cout<<"#2: Rut tien                          #"<<endl;
        cout<<"#3: Tao tai khoan                     #"<<endl;
        cout<<"#4: Sua doi                           #"<<endl;
        cout<<"#5: Xoa tai khoan                     #"<<endl;
        cout<<"#6:Xem thong tin tai khoan            #"<<endl;
        cout<<"#-------------@huynhgia.bao-----------#"<<endl;

    }
    void NapTien(){
       
        
    
    }
   /* void taoSTK(){
       srand(time(NULL)); 
	int  = rand() % (50 - 3 + 1) + 3;
     1 = *100000-564+899*2000; //số tài khoản khi tạo
    cout << "So tai khoan cua ban la: "<< 1 << endl; 
  
    }*/
    void luu(){
        ofstream file;
        file.open("taikhoan.txt");
        file << ten << endl;
        file << soTienGui << endl;
        file << loaiTaiKhoan << endl;
        file << matkhau << endl;
        
        file.close();
    }
    void mo(){
        ifstream infile;
        infile.open("taikhoan.txt");
        infile >> ten;
        infile >> soTienGui;
        infile >> loaiTaiKhoan;
        
        infile >> matkhau;
     
        cout <<"$--------------------------------$" <<endl;
        cout <<"Loai the:";
        if(loaiTaiKhoan == 1){
            cout<<"TAI KHOAN THANH TOAN" << endl;
        }
        else if(loaiTaiKhoan == 2){
            cout <<"TAI KHOAN TIET KIEM" << endl;
        }
        else if(loaiTaiKhoan == 3){
            cout <<"TAI KHOAN THE TIN DUNG" << endl;
        }
        else if(loaiTaiKhoan == 4){
            cout<<"TAI KHOAN VAY VON" << endl;
        }
        else{
            cout <<"dieu kien khong khop!" << endl;
        }
        cout <<"Nguoi dung : " << ten << endl;
        cout<<"So tien hien co : "<< soTienGui <<" VND " << endl;
        cout<<"Mat khau :" << matkhau << endl;
      
        
        infile.close();

    }
    void chon(){
        cout << "Moi ban chon :";
        int check;
        cin >> check;
        switch (check)
        {
        case 6:
        mo();
            break;
        case 3:
        TaoTaiKhoan();
        case 1:
        napTien();
        break;
        default:
            break;
        }

    } void napTien(){
        
        ifstream infile;
        infile.open("taikhoan.txt");
        infile >> ten;
        infile >> matkhau;
        string name;
        cout <<"$---------BankSystem-----------------$" << endl;
        cout <<" nhap ten tai khoan: ";
        cin >>name;
        if(name != ten){
            cout <<"Ten tai khoan khong dung:" << endl;;
            cout <<"Moi nhap lai: ";
            cin >> name;
             if(name != ten){
                cout <<"Ban da nhap sai 2 lan, Bam enter de thoat ra!";
                char enter;
                cin >> enter;
                if(enter == '\n'){
                    chucNang();
                    chon();
                }
             }
        }
        cout <<"Moi nhap mat khau: ";
        int mk;
        cin >> mk;
         if(mk != matkhau){
            cout <<"Mat khau khong dung:" << endl;;
            cout <<"Moi nhap lai: ";
            cin >> mk;
             if( mk != matkhau){
                cout <<"Ban da nhap sai 2 lan, Bam enter de thoat ra!";
                char enter;
                cin >> enter;
                if(enter == '\n'){
                    chucNang();
                    chon();
                }
                    else{
                        cout<<":) thieu nang tri tue a . fuck you" << endl;
                    }
                
             }
        }
        /*
        
     
        cout <<"$--------------------------------$" <<endl;
        cout <<"Loai the:";
        if(loaiTaiKhoan == 1){
            cout<<"TAI KHOAN THANH TOAN" << endl;
        }
        else if(loaiTaiKhoan == 2){
            cout <<"TAI KHOAN TIET KIEM" << endl;
        }
        else if(loaiTaiKhoan == 3){
            cout <<"TAI KHOAN THE TIN DUNG" << endl;
        }
        else if(loaiTaiKhoan == 4){
            cout<<"TAI KHOAN VAY VON" << endl;
        }
        else{
            cout <<"dieu kien khong khop!" << endl;
        }
        cout <<"Nguoi dung : " << ten << endl;
        cout<<"So tien hien co : "<< soTienGui <<" VND " << endl;
        
        */
       mo();
       
         ofstream nap;
         nap.open("taikhoan.txt");
        
        
        cout <<"So tien muon nap: ";
        
        cin >> tienNap;
        tienNap = tienNap + soTienGui;
        nap << tienNap << endl;
        nap.close();



    }


 };
 using namespace std;
 int main(){
   taiKhoan b;
    b.chucNang();
    b.chon();
    


 }

// dd/mm/yy           7 => 8.7.2023 |
