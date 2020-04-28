#include <iostream>
using namespace std;

class Developer{
protected:
    string ID , name , role , status , WFH;
    int child;

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

        cout<<"Masukan data"<<endl;
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

        cout<<"Jumlah anak\t\t: ";
        cin>>c;
        setChild(c);

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
        cout<<"Total Gaji\t: Rp"<<fixed<<totalGaji;
    }
};

class JuniorDev : public Developer{
public:
    JuniorDev(){
        role = "Junior Developer";
    }
    void setGajiPokok(){
        gajiPokok = 10000000;
    }
    void setTunjangan(){
        if(status=="iya") totalTunjangan = gajiPokok * 0.1;

        if(child > 0) totalTunjangan += (child * 0.05) * gajiPokok;

        if(WFH=="tidak") totalTunjangan += gajiPokok * 0.25;
    }
};

class MiddleDev : public Developer{
public:
    MiddleDev(){
        role = "Middle Developer";
    }
    void setGajiPokok(){
        gajiPokok = 20000000;
    }
    void setTunjangan(){
        if(status=="iya") totalTunjangan = gajiPokok * 0.125;

        if(child > 0) totalTunjangan += (child * 0.05) * gajiPokok;

        if(WFH=="tidak") totalTunjangan += gajiPokok * 0.30;
    }
};

class SeniorDev : public Developer{
public:
    SeniorDev(){
        role = "Senior Developer";
    }
    void setGajiPokok(){
        gajiPokok = 30000000;
    }
    void setTunjangan(){
        if(status=="iya") totalTunjangan = gajiPokok * 0.15;

        if(child > 0) totalTunjangan += (child * 0.05) * gajiPokok;

        if(WFH=="tidak") totalTunjangan += gajiPokok * 0.30;
    }
};

int main() {
     JuniorDev jd1;
     MiddleDev md1;
     MiddleDev md2;
     SeniorDev sd1;
     SeniorDev sd2;
     SeniorDev sd3;

    jd1.setData();
    jd1.setGajiPokok();
    jd1.setTunjangan();
    jd1.printData();


    return 0;
}