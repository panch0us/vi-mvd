using namespace std;

#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Light_Button.H>
#include "person.h"
#include "gui.cpp"

string surname;

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

static void callback_input_surname(Fl_Widget *w, void *user) {
    printf("%s\n", ((Fl_Input*)user)->value());

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

static void input_callback(Fl_Widget *w, void *){
    Fl_Window *window = new Fl_Window(500, 500, "Ввод лица");
    Fl_Input *input_surname = new Fl_Input(100, 10, 200, 25, "Фамилия:");
    Fl_Input *input_name = new Fl_Input(100, 40, 200, 25, "Имя:");
    Fl_Button *input_enter = new Fl_Button(105, 70, 120, 25, "Ввод");
    Fl_Button *input_cancel = new Fl_Button(230, 70, 60, 25, "Отмена");

    // если написал текст и нажал Ввод
    input_surname->callback(callback_input_surname, (void*)input_surname);
    input_name->callback();
    window->show();
}


int main(int argc, char **argv)
{

    Fl_Window *window = new Fl_Window(500, 500);
    Fl_Box *box = new Fl_Box(100, 20, 300, 70,"Опознание");
    box->box(FL_UP_BOX);
    box->labelfont(FL_BOLD+FL_ITALIC);
    box->labelsize(36);
    box->labeltype(FL_SHADOW_LABEL);

    Fl_Button *button_input = new Fl_Button(20, 120, 200, 40, "Ввод лица");
    button_input->callback(input_callback, (void*)PersonMissing& pm);

    window->end();
    window->show(argc, argv);
    
    return Fl::run();
}

