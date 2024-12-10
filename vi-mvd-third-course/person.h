class PersonMissing {
    string surname;
    string name;
    string middle_name;
    string sex;
    unsigned short int birth_day;
    unsigned short int birth_month;
    unsigned short int birth_year;
    string birth_place;          //место рождения
    string residence_place_last; //последнее место жительства
    string appearance;           //описание внешности
    string teeth;                //состояние зубного аппарата
    string voice;                //характерные приметы голоса
    string blood_group;          //группа крови
    string clothes;              //описание одежды
    string headdress_size;       //размер головного убора
    string shoes_size;           //размеры обуви
    
public:
    void setSurname(string &sn);
    void setName(string &n);
    void setMiddleName(string &mn);
    void setSex(string &s);
    void setBirthDay(unsigned short int bd);
    void setBirthMonth(unsigned short int bm);
    void setBirthYear(unsigned short int y);
    void setBirthPlace(string &bp);
    void setResidentPlaceLast(string &rpl);
    void setAppearance(string &a);
    void setTeeth(string &t);
    void setVoice(string &v);
    void setBloodGroup(string &bg);
    void setClothes(string &c);
    void setHeaddressSize(string &hs);
    void setShoesSize(string &ss);
    
    string &getSurname();
    string &getName();
    string &getMiddleName();
    string &getSex();
    unsigned short int getBirthDay();
    unsigned short int getBirthMonth();
    unsigned short int getBirthYear();
    string &getBirthPlace();
    string &getResidentPlaceLast();
    string &getAppearance();
    string &getTeeth();
    string &getVoice();
    string &getBloodGroup();
    string &getClothes();
    string &getHeaddressSize();
    string &getShoesSize();
};


inline void PersonMissing::setSurname(string &sn){
    surname = sn;
}

inline void PersonMissing::setName(string &n){
    name = n;
}

inline void PersonMissing::setMiddleName(string &mn){
    middle_name = mn;
}

inline void PersonMissing::setSex(string &s){
    sex = s;
}

inline void PersonMissing::setBirthDay(unsigned short int bd){
    birth_day = bd;
}

inline void PersonMissing::setBirthMonth(unsigned short int bm){
    birth_month = bm;
}

inline void PersonMissing::setBirthYear(unsigned short int by){
    birth_year = by;
}

inline void PersonMissing::setBirthPlace(string &bp){
    birth_place = bp;
}

inline void PersonMissing::setResidentPlaceLast(string &rpl){
    residence_place_last = rpl;
}

inline void PersonMissing::setAppearance(string &a){
    appearance = a;
}

inline void PersonMissing::setTeeth(string &t){
    teeth = t;
}

inline void PersonMissing::setVoice(string &v){
    voice = v;
}

inline void PersonMissing::setBloodGroup(string &bg){
    blood_group = bg;
}

inline void PersonMissing::setClothes(string &c){
    clothes = c;
}

inline void PersonMissing::setHeaddressSize(string &hs){
    headdress_size = hs;
}

inline void PersonMissing::setShoesSize(string &ss){
    shoes_size = ss;
}

inline string &PersonMissing::getSurname(){
    return surname; 
}

inline string &PersonMissing::getName(){
    return name;
}

inline string &PersonMissing::getMiddleName(){
    return middle_name;
}

inline string &PersonMissing::getSex(){
    return sex;
}

inline unsigned short int PersonMissing::getBirthDay(){
    return birth_day; 
}

inline unsigned short int PersonMissing::getBirthMonth(){
    return birth_month; 
}

inline unsigned short int PersonMissing::getBirthYear(){
    return birth_year; 
}

inline string &PersonMissing::getBirthPlace(){
    return birth_place;
}

inline string &PersonMissing::getResidentPlaceLast(){
    return residence_place_last;
}

inline string &PersonMissing::getAppearance(){
    return appearance;
}

inline string &PersonMissing::getTeeth(){
    return teeth;
}

inline string &PersonMissing::getVoice(){
    return voice;
}

inline string &PersonMissing::getBloodGroup(){
    return blood_group;
}

inline string &PersonMissing::getClothes(){
    return clothes;
}

inline string &PersonMissing::getHeaddressSize(){
    return headdress_size;
}

inline string &PersonMissing::getShoesSize(){
    return shoes_size;
}

