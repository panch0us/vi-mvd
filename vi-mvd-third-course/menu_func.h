void input_person(PersonMissing &pm){
    string buf;
    unsigned short int buf_i = 0;

    cout << "¬ведите фамилию: ";
    getline(cin, buf);
    pm.setSurname(buf);

    cout << "¬ведите им€: ";
    getline(cin, buf);
    pm.setName(buf);

    cout << "¬ведите отчество: ";
    getline(cin, buf);
    pm.setMiddleName(buf);

    cout << "¬ведите пол (м или ж): ";
    cin >> buf;
    pm.setSex(buf);

    cout << "¬ведите день рождени€: ";
    cin >> buf_i;
    pm.setBirthDay(buf_i);

    cout << "¬ведите мес€ц рождени€: ";
    cin >> buf_i;
    pm.setBirthMonth(buf_i);

    cout << "¬ведите год рождени€: ";
    cin >> buf_i;
    pm.setBirthYear(buf_i);

    fflush(stdin); // очищаем стандартный поток ввода от символа \n, оставшегос€ после cin
    
    cout << "¬ведите место рождени€: ";
    getline(cin, buf);
    pm.setBirthPlace(buf);

    cout << "¬ведите последнее место жительства: ";
    getline(cin, buf);
    pm.setResidentPlaceLast(buf);

    cout << "¬ведите описание внешности: ";
    getline(cin, buf);
    pm.setAppearance(buf);

    cout << "¬ведите состо€ние зубного аппарата: ";
    getline(cin, buf);
    pm.setTeeth(buf);

    cout << "¬ведите характерные приметы голоса: ";
    getline(cin, buf);
    pm.setVoice(buf);

    cout << "¬ведите группу крови: ";
    getline(cin, buf);
    pm.setBloodGroup(buf);

    cout << "¬ведите описание одежды: ";
    getline(cin, buf);
    pm.setClothes(buf);

    cout << "¬ведите размер головного убора: ";
    getline(cin, buf);
    pm.setHeaddressSize(buf);

    cout << "¬ведите размеры обуви: ";
    getline(cin, buf);
    pm.setShoesSize(buf);

    cout << "¬ведите район пропажи: ";
    getline(cin, buf);
    pm.setAreaLoss(buf);

    cout << "¬ведите день начала пропажи: ";
    cin >> buf_i;
    pm.setDayLossStart(buf_i);

    cout << "¬ведите мес€ц начала пропажи: ";
    cin >> buf_i;
    pm.setMonthLossStart(buf_i);

    cout << "¬ведите год начала пропажи: ";
    cin >> buf_i;
    pm.setYearLossStart(buf_i);

    cout << "¬ведите день конца пропажи: ";
    cin >> buf_i;
    pm.setDayLossEnd(buf_i);

    cout << "¬ведите мес€ц конца пропажи: ";
    cin >> buf_i;
    pm.setMonthLossEnd(buf_i);

    cout << "¬ведите год конца пропажи: ";
    cin >> buf_i;
    pm.setYearLossEnd(buf_i);

    fflush(stdin); // очищаем стандартный поток ввода от символа \n, оставшегос€ после cin
}