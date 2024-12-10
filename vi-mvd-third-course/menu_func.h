void input_person(PersonMissing &pm){
    string buf;
    unsigned short int buf_i = 0;

    cout << "¬видите фамилию: ";
    getline(cin, buf);
    pm.setSurname(buf);

    cout << "¬видите им€: ";
    getline(cin, buf);
    pm.setName(buf);

    cout << "¬видите отчество: ";
    getline(cin, buf);
    pm.setMiddleName(buf);

    cout << "¬видите пол (м или ж): ";
    cin >> buf;
    pm.setSex(buf);

    cout << "¬видите день рождени€: ";
    cin >> buf_i;
    pm.setBirthDay(buf_i);

    cout << "¬видите мес€ц рождени€: ";
    cin >> buf_i;
    pm.setBirthMonth(buf_i);

    cout << "¬видите год рождени€: ";
    cin >> buf_i;
    pm.setBirthYear(buf_i);

    cout << "¬видите место рождени€: ";
    getline(cin, buf);
    pm.setBirthPlace(buf);

    cout << "¬видите последнее место жительства: ";
    getline(cin, buf);
    pm.setResidentPlaceLast(buf);

    cout << "¬видите описание внешности: ";
    getline(cin, buf);
    pm.setAppearance(buf);

    cout << "¬видите состо€ние зубного аппарата: ";
    getline(cin, buf);
    pm.setTeeth(buf);

    cout << "¬видите характерные приметы голоса: ";
    getline(cin, buf);
    pm.setVoice(buf);

    cout << "¬видите группу крови: ";
    getline(cin, buf);
    pm.setBloodGroup(buf);

    cout << "¬видите описание одежды: ";
    getline(cin, buf);
    pm.setClothes(buf);

    cout << "¬видите размер головного убора: ";
    getline(cin, buf);
    pm.setHeaddressSize(buf);

    cout << "¬видите размеры обуви: ";
    getline(cin, buf);
    pm.setShoesSize(buf);

    cout << "¬видите район пропажи: ";
    getline(cin, buf);
    pm.setAreaLoss(buf);

    cout << "¬видите день начала пропажи: ";
    cin >> buf_i;
    pm.setDayLossStart(buf_i);

    cout << "¬видите мес€ц начала пропажи: ";
    cin >> buf_i;
    pm.setMonthLossStart(buf_i);

    cout << "¬видите год начала пропажи: ";
    cin >> buf_i;
    pm.setYearLossStart(buf_i);

    cout << "¬видите день конца пропажи: ";
    cin >> buf_i;
    pm.setDayLossEnd(buf_i);

    cout << "¬видите мес€ц конца пропажи: ";
    cin >> buf_i;
    pm.setMonthLossEnd(buf_i);

    cout << "¬видите год конца пропажи: ";
    cin >> buf_i;
    pm.setYearLossEnd(buf_i);

    fflush(stdin); // очищаем стандартный поток ввода от символа \n, оставшегос€ после cin
}