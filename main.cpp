#include <iostream>
using namespace std;

class Developer{
protected:
    string ID , name , role , status , WFH;
    int child=0;

    double totalGaji , gajiPokok , totalTunjangan=0;

public:
    void setID(string id){
        ID = id;
    }
    void setName(string n){
        name = n;
    }
    void setStatus(string s){
        status = s;
    }
    void setChild(int c){
        child = c;
    }
    void setWFH(string w){
        WFH = w;
    }

    void setTotalGaji(){
        totalGaji = gajiPokok + totalTunjangan;
    }

    void setData(){
        string id , n , s , w;
        int c;

        cout<<"\n======================Masukan Data======================\n";
        cout<<"Role\t\t: "<<role<<endl<<endl;
        cout<<"ID\t\t: ";
        cin>>id;
        setID(id);

        cout<<"Nama\t\t: ";
        cin.get();
        getline(cin,n);
        setName(n);

        cout<<"Status Menikah (iya/tidak)\t: ";
        cin>>s;
        setStatus(s);

        if(s=="iya"){
            cout<<"Jumlah anak\t: ";
            cin>>c;
            setChild(c);
        }

        cout<<"Bekerja dari rumah (iya/tidak)\t: ";
        cin>>w;
        setWFH(w);
    }
    void printData(){
        setTotalGaji();
        cout<<"\n=================Print Data=================\n\n";
        cout<<"ID\t\t: "<<ID<<endl
            <<"Nama\t\t: "<<name<<endl
            <<"Role\t\t: "<<role<<endl
            <<"Status Menikah\t: "<<status<<endl
            <<"Anak\t\t: "<<child<<endl
            <<"Work from home\t: "<<WFH<<endl;
        cout.precision(1);
        cout<<"Total Gaji\t: Rp"<<fixed<<totalGaji<<endl<<endl;
        system("pause");
        system("cls");
    }
};

class JuniorDev : public Developer{
private:
    void setGajiPokok(){
        gajiPokok = 10000000;
    }
    void setTunjangan(){
        if(status=="iya") totalTunjangan = gajiPokok * 0.1;

        if(child > 0) totalTunjangan += (child * 0.05) * gajiPokok;

        if(WFH=="tidak") totalTunjangan += gajiPokok * 0.25;
    }
public:
    JuniorDev(){
        role = "Junior Developer";
    }
    void main(){
        setData();
        setGajiPokok();
        setTunjangan();
        printData();
    }
};

class MiddleDev : public Developer{
private:
    void setGajiPokok(){
        gajiPokok = 20000000;
    }
    void setTunjangan(){
        if(status=="iya") totalTunjangan = gajiPokok * 0.125;

        if(child > 0) totalTunjangan += (child * 0.05) * gajiPokok;

        if(WFH=="tidak") totalTunjangan += gajiPokok * 0.30;
    }
public:
    MiddleDev(){
        role = "Middle Developer";
    }
    void main(){
        setData();
        setGajiPokok();
        setTunjangan();
        printData();
    }
};

class SeniorDev : public Developer{
private:
    void setGajiPokok(){
        gajiPokok = 30000000;
    }
    void setTunjangan(){
        if(status=="iya") totalTunjangan = gajiPokok * 0.15;

        if(child > 0) totalTunjangan += (child * 0.05) * gajiPokok;

        if(WFH=="tidak") totalTunjangan += gajiPokok * 0.30;
    }
public:
    SeniorDev(){
        role = "Senior Developer";
    }
    void main(){
        setData();
        setGajiPokok();
        setTunjangan();
        printData();
    }
};

int main() {
     JuniorDev jd1;
     MiddleDev md1;
     MiddleDev md2;
     SeniorDev sd1;
     SeniorDev sd2;
     SeniorDev sd3;

    jd1.main();

    md1.main();
    md2.main();

    sd1.main();
    sd2.main();
    sd3.main();


    return 0;
}
