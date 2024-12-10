class PersonMissing {
    string surname;
    string name;
    string middle_name;
    string sex;
    unsigned short int birth_day;
    unsigned short int birth_month;
    unsigned short int birth_year;
    string birth_place;                     // место рождения
    string residence_place_last;            // последнее место жительства
    string appearance;                      // описание внешности
    string teeth;                           // состояние зубного аппарата
    string voice;                           // характерные приметы голоса
    string blood_group;                     // группа крови
    string clothes;                         // описание одежды
    string headdress_size;                  // размер головного убора
    string shoes_size;                      // размеры обуви
    string area_loss;                       // район пропажи
    unsigned short int day_loss_start;      // день пропажи начало
    unsigned short int month_loss_start;    // месяц пропажи начало
    unsigned short int year_loss_start;     // год пропажи начало
    unsigned short int day_loss_end;        // день пропажи конец
    unsigned short int month_loss_end;      // месяц пропажи конец
    unsigned short int year_loss_end;       // год пропажи конец

public:
    void setSurname(string &sn);
    void setName(string &n);
    void setMiddleName(string &mn);
    void setSex(string &s);
    void setBirthDay(unsigned short int bd);
    void setBirthMonth(unsigned short int bm);
    void setBirthYear(unsigned short int by);
    void setBirthPlace(string &bp);
    void setResidentPlaceLast(string &rpl);
    void setAppearance(string &a);
    void setTeeth(string &t);
    void setVoice(string &v);
    void setBloodGroup(string &bg);
    void setClothes(string &c);
    void setHeaddressSize(string &hs);
    void setShoesSize(string &ss);
    void setAreaLoss(string &al);
    void setDayLossStart(unsigned short int dls);
    void setMonthLossStart(unsigned short int mls);
    void setYearLossStart(unsigned short int yls);
    void setDayLossEnd(unsigned short int dle);
    void setMonthLossEnd(unsigned short int mle);
    void setYearLossEnd(unsigned short int yle);
    
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
    string &setAreaLoss();
    unsigned short int getDayLossStart();
    unsigned short int getMonthLossStart();
    unsigned short int getYearLossStart();
    unsigned short int getDayLossEnd();
    unsigned short int getMonthLossEnd();
    unsigned short int getYearLossEnd();
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

inline void PersonMissing::setAreaLoss(string &al){
    area_loss = al;
}

inline void PersonMissing::setDayLossStart(unsigned short int dls){
    day_loss_start = dls;
}

inline void PersonMissing::setMonthLossStart(unsigned short int mls){
    month_loss_start = mls;
}

inline void PersonMissing::setYearLossStart(unsigned short int yls){
    year_loss_start = yls;
}

inline void PersonMissing::setDayLossEnd(unsigned short int dle){
    day_loss_end = dle;
}

inline void PersonMissing::setMonthLossEnd(unsigned short int mle){
    month_loss_end = mle;
}

inline void PersonMissing::setYearLossEnd(unsigned short int yle){
    year_loss_end = yle;
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

inline unsigned short int PersonMissing::getDayLossStart(){
    return day_loss_start; 
}

inline unsigned short int PersonMissing::getMonthLossStart(){
    return month_loss_start; 
}

inline unsigned short int PersonMissing::getYearLossStart(){
    return year_loss_start; 
}

inline unsigned short int PersonMissing::getDayLossEnd(){
    return day_loss_end; 
}

inline unsigned short int PersonMissing::getMonthLossEnd(){
    return month_loss_end; 
}

inline unsigned short int PersonMissing::getYearLossEnd(){
    return year_loss_end; 
}