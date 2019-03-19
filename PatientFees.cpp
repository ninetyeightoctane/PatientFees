#include <iostream>

using namespace std;

char getMedicationTypeFromUser();
char getSurgeryTypeFromUser();

class PatientAccount{

    double daily_rate;

protected:

    double charges;
    int numberOfDays;

public:

    PatientAccount(int n){
        daily_rate=500;
        numberOfDays=n;
        charges=0;
    }

    void displayCharges(){
        double total= numberOfDays*daily_rate + charges;
        cout<<"Total charges: "<<total<<endl;
    }

    friend class Surgery;
    friend class Pharmacy;

};



class Surgery{
    double HEART,APPENDIX,EYE,LIVER,BONE;

public:
    Surgery(){
        HEART=5000;
        APPENDIX=1000;
        EYE=1200;
        LIVER=2000;
        BONE=1800;
    }

    void setSurgeryCharges(PatientAccount &p,char type){
        if(type=='A' || type=='a'){
            p.charges+=HEART;
        }
        else if(type=='B' || type=='b'){
            p.charges+=APPENDIX;
        }
        else if(type=='C' || type=='c'){
            p.charges+=EYE;
        }
        else if(type=='D' || type=='d'){
            p.charges+=LIVER;
        }
        else if(type=='E' || type=='e'){
            p.charges+=BONE;
        }
        else {
            cout<<"Invalid Surgery type "<<endl;
        }
    }

};



class Pharmacy{
    double ANTIBIOTICS,ANTISEPTICS,ANALGESICS,ANTIVIRAL,ANTIFUNGALS;

public:
    Pharmacy(){
        ANTIBIOTICS=100;
        ANTISEPTICS=75;
        ANALGESICS=150;
        ANTIVIRAL=50;
        ANTIFUNGALS=25;
    }



    void setMedicationCharges(PatientAccount &p,char type){
        if(type=='A' || type=='a'){
            p.charges+=ANTIBIOTICS;
        }
        else if(type=='B' || type=='b'){
            p.charges+=ANTISEPTICS;
        }
        else if(type=='C' || type=='c'){
            p.charges+=ANALGESICS;
        }
        else if(type=='D' || type=='d'){
            p.charges+=ANTIVIRAL;
        }
        else if(type=='E' || type=='e'){
            p.charges+=ANTIFUNGALS;
        }
        else {
            cout<<"Invalid medication type "<<endl;
        }
    }

};

int main() {

    Surgery surgery;
    Pharmacy pharmacy;

    while(true){
        int days;
        char surgeryType;
        char medicationType;

        cout<<"Enter number of days spent: "<<endl;
        cin>>days;

        PatientAccount patient(days);

        surgeryType=getSurgeryTypeFromUser();

        medicationType=getMedicationTypeFromUser();

        surgery.setSurgeryCharges(patient,surgeryType);

        pharmacy.setMedicationCharges(patient,medicationType);

        patient.displayCharges();

        cout<<"Do you want to continue? (y/n)"<<endl;
        char choice;
        cin>>choice;

        if(choice!='y'){
            cout<<"Goodbye"<<endl;
            break;
        }
    }
}

char getSurgeryTypeFromUser(){
    char surgeryType;
    cout<<"Enter a surgery type: (a)HEART (b)APPENDIX (c)EYE (d)LIVER (e)BONE"<<endl;
    cin>>surgeryType;
    if(surgeryType!='a' && surgeryType != 'b' && surgeryType!='c'&& surgeryType!='d' && surgeryType!='e'){
        cout<<"Invalid choice, try again..."<<endl;
        return getSurgeryTypeFromUser();
    }
    else{
        return surgeryType;
    }
}

char getMedicationTypeFromUser(){
    char medicationType;
    cout<<"Enter a medication type: (a)ANTIBIOTICS (b)ANTISEPTICS (c)ANALGESICS (d)ANTIVIRAL (e)ANTIFUNGALS"<<endl;
    cin>>medicationType;
    if(medicationType!='a' && medicationType != 'b' && medicationType!='c' && medicationType!='d' && medicationType!='e'){
        cout<<"Invalid choice, try again..."<<endl;
        return getMedicationTypeFromUser();
    }
    else{
        return medicationType;
    }
}