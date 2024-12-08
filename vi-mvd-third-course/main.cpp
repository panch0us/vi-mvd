using namespace std;

#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include "person.h"

// константы
enum {
    spacing     = 5,       // промежутки
    button_w    = 300,     // ширина кнопки
    button_h    = 40,      // высота кнопки
    font_size   = 20       // размер шрифта
};

// названия заголовков и кнопок
static const char *msg[] = {
    "Добро пожаловать в АИПС \"Опознание\".",
    "Ввод лица",
    "Редактирование лица",
    "Поиск лица",
    "Выход"
};

static void exit_callback(Fl_Widget *w, void *);


int main(int argc, char **argv)
{
    string surname = "Савкин";
    string name = "Павел";
    string middle_name = "Владимирович";
    string sex = "М";

    PersonMissing pm;
    pm.setSurname(surname);
    pm.setName(name);
    pm.setMiddleName(middle_name);
    pm.setSex(sex);
    pm.setBirthYear(1990);

    cout << pm.getSurname() << std::endl;
    cout << pm.getName() << std::endl;


    int win_w = 1024;
    int win_h = 768;
    Fl_Window *win = new Fl_Window(win_w, win_h, "АИПС Опознание"); // создаем главное окно

    Fl_Button *b[4]; // создаем объекты кнопок
    int i;
    int y = spacing;
    for(i = 0; i < 4; i++){
        b[i] = new Fl_Button(spacing, y, button_w, button_h, msg[i+1]);
        b[i]->labelsize(font_size);
        y += button_h + spacing;
    }
    win->end();
    
    // установим реакцию на нажатие кнопок
    b[3]->callback(exit_callback, 0);

    win->show();
    return Fl::run();
}

static void exit_callback(Fl_Widget *w, void *)
{
    Fl_Widget *p;
    do {
        p = w->parent();
        if(p)
            w = p;
    } while(p);
    w->hide();
}