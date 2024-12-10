void input_person(PersonMissing &pm){
    string buf;
    unsigned short int buf_i = 0;

    cout << "¬видите фамилию: ";
    cin >> buf;
    pm.setSurname(buf);

    cout << "¬видите им€: ";
    cin >> buf;
    pm.setName(buf);

    cout << "¬видите отчество: ";
    cin >> buf;
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
    cin >> buf;
    pm.setBirthPlace(buf);

    cout << "¬видите последнее место жительства: ";
    cin >> buf;
    pm.setResidentPlaceLast(buf);

    cout << "¬видите описание внешности: ";
    cin >> buf;
    pm.setAppearance(buf);

    cout << "¬видите состо€ние зубного аппарата: ";
    cin >> buf;
    pm.setTeeth(buf);

    cout << "¬видите характерные приметы голоса: ";
    cin >> buf;
    pm.setVoice(buf);

    cout << "¬видите группу крови: ";
    cin >> buf;
    pm.setBloodGroup(buf);

    cout << "¬видите описание одежды: ";
    cin >> buf;
    pm.setClothes(buf);

    cout << "¬видите размер головного убора: ";
    cin >> buf;
    pm.setHeaddressSize(buf);

    cout << "¬видите размеры обуви: ";
    cin >> buf;
    pm.setShoesSize(buf);
}